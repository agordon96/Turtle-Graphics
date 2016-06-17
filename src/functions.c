/***********************************functions.c****************************************************
Student Name: Aaron Gordon        Student Number: 0884023
Date: February 9th, 2015          Course Name: CIS*2500 Intermediate Programming
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
        1) I have read and understood the University policy on academic integrity;
        2) I have completed the Computing with Integrity Tutorial on Moodle; and
        3) I have achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and all material
(data, images, ideas or words) that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for this course.
********************************************************************************************/

#include "a2.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ncurses.h>

/*Draws the initial board on program startup*/
void drawBoard()
{
    int i;

    /*Draw the outlines for the board; first the bottom two lines with mvaddstr and then an array spanning down for the right wall*/
    mvaddstr(43, 0, "=====================================================================================================");
    mvaddstr(50, 0, "----------------------------------------------------------------------------------------------------");
    for(i = 0; i <= 50; i++)
    {
        mvaddch(i, 100, '|');
    }

    /*Reset @ and cursor to the default start position on the board*/
    mvaddch(25, 50, '@');
    move(44, 0);
}

/*Move the turtle (@) a certain distance and leave a trail behind him corresponding to the color currently active*/
void moveForward(int distance, int angle, int forbac, Turtle * turtle)
{
    int i;

    /*Erase where the @ is initially so he can be moved and not leave his ghost behind*/
    mvaddch(turtle->yPos, turtle->xPos, ' ');
    /*Every one of these eight directions corresponds to a certain angle range that can be manipulated via rt and lt
    Each one draws the trail behind @ if the pen is down and gives a new yPos/xPos for however long @ is supposed to move*/
    if(angle >= 340 || angle < 20)
    {
        for(i = 0; i <= distance; i++)
        {
            mvaddch(turtle->yPos, turtle->xPos, '|');
            turtle->yPos -= forbac;
        }
    }
    else if(angle >= 20 && angle < 70)
    {
        for(i = 0; i <= distance; i++)
        {
            mvaddch(turtle->yPos, turtle->xPos, '/');
            turtle->yPos -= forbac;
            turtle->xPos += forbac;
        }
    }
    else if(angle >= 70 && angle < 110)
    {
        for(i = 0; i <= distance; i++)
        {
            mvaddch(turtle->yPos, turtle->xPos, '-');
            turtle->xPos += forbac;
        }
    }
    else if(angle >= 110 && angle < 160)
    {
        for(i = 0; i <= distance; i++)
        {
            mvaddch(turtle->yPos, turtle->xPos, '\\');
            turtle->yPos += forbac;
            turtle->xPos += forbac;
        }
    }
    else if(angle >= 160 && angle < 200)
    {
        for(i = 0; i <= distance; i++)
        {
            mvaddch(turtle->yPos, turtle->xPos, '|');
            turtle->yPos += forbac;
        }
    }
    else if(angle >= 200 && angle < 250)
    {
        for(i = 0; i <= distance; i++)
        {
            mvaddch(turtle->yPos, turtle->xPos, '/');
            turtle->yPos += forbac;
            turtle->xPos -= forbac;
        }
    }
    else if(angle >= 250 && angle < 290)
    {
        for(i = 0; i <= distance; i++)
        {
            mvaddch(turtle->yPos, turtle->xPos, '-');
            turtle->xPos -= forbac;
        }
    }
    else if(angle >= 290 && angle < 340)
    {
        for(i = 0; i <= distance; i++)
        {
            mvaddch(turtle->yPos, turtle->xPos, '\\');
            turtle->yPos -= forbac;
            turtle->xPos -= forbac;
        }
    }
}

/*The function for every command that is possible, see README.txt for a review of what each command does*/
void doCommand(Turtle * turtle)
{
    int i, j;

    /*Initialize five pairs of color options for foreground and background*/
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_WHITE, COLOR_BLACK);
    init_pair(5, COLOR_YELLOW, COLOR_BLACK);
    mvaddstr(48, 0, "                                                     ");

    if(strcmp(turtle->command, "lt") == 0)
    {
        if(turtle->value > turtle->dir)
        {
            turtle->dir = (turtle->dir + 360 - turtle->value);
        }
        else
        {
            turtle->dir = turtle->dir - turtle->value;
        }
    }
    else if(strcmp(turtle->command, "rt") == 0)
    {
        if((turtle->value + turtle->dir) >= 360)
        {
            turtle->dir = (turtle->dir + turtle->value - 360);
        }
        else
        {
            turtle->dir = turtle->dir + turtle->value;
        }
    }
    else if(strcmp(turtle->command, "fd") == 0)
    {
        moveForward(turtle->value, turtle->dir, 1, turtle);
    }
    else if(strcmp(turtle->command, "bk") == 0)
    {
        moveForward(turtle->value, turtle->dir, -1, turtle);
    }
    else if(strcmp(turtle->command, "home") == 0)
    {
        for(i = 0; i <= 42; i++)
        {
            for(j = 0; j <= 89; j++)
            {
                mvaddch(i, j, ' ');
            }
        }
        turtle->xPos = 50;
        turtle->yPos = 25;
        turtle->dir = 0;
        mvaddstr(48, 0, "Home entered; resetting board to default.");
    }
    else if(strcmp(turtle->command, "pu") == 0)
    {
        mvaddstr(47, 75, "             ");
        mvaddstr(47, 75, "Pen is up.");
        turtle->isPen = 0;
    }
    else if(strcmp(turtle->command, "pd") == 0)
    {
        mvaddstr(47, 75, "             ");
        mvaddstr(47, 75, "Pen is down.");
        turtle->isPen = 1;
    }
    else if(strcmp(turtle->command, "setpencolor") == 0)
    {
        attron(COLOR_PAIR(turtle->value));
    }
    else
    {
        mvaddstr(48, 0, "Don't know ");
        mvaddstr(48, 11, turtle->command);
    }

    /*Since you can't rotate the turtle, a direction number is displayed at the bottom right of the message section for reference*/
    mvprintw(48, 75, "                 ");
    mvprintw(48, 75, "Direction: %d", turtle->dir);
}

/*Designed to have a buffer that cycles through the last few commands done and displays them on the screen*/
void printCommands(Buffer * buffer)
{
    mvaddstr(44, 0, "                                               ");
    mvaddstr(45, 0, "                                               ");
    mvaddstr(45, 0, buffer->lastCom);
    mvaddstr(46, 0, "                                               ");
    mvaddstr(46, 0, buffer->secondCom);
    mvaddstr(47, 0, "                                               ");
    mvaddstr(47, 0, buffer->thirdCom); 
    mvaddstr(48, 0, "                                               ");
}
