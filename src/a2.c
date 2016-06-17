/***********************************a2.c****************************************************
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

#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "a2.h"

int main(void)
{
    int i = 0;
    char input[256];
    char * token;

    /*Initialize and allocate memory to the two structs and their char members*/
    Turtle * turtle;
    Buffer * buffer;
    turtle = malloc(sizeof(Turtle));
    buffer = malloc(sizeof(Buffer));
    turtle->command = malloc(sizeof(char)*50);
    turtle->color = malloc(sizeof(char)*50);
    buffer->lastCom = malloc(sizeof(char)*50);

    /*Where the turtle will begin and have him facee upward*/
    turtle->xPos = 50;
    turtle->yPos = 25;
    turtle->dir = 0;

    initscr();
    start_color();
    drawBoard();
    refresh();

    /*If quit becomes the command entered, the program will end immediately*/
    while(strcmp(input, "quit") != 0)
    {
        /*Reset cursor to the input area and getstr for the next iteration of the program*/
        move(44, 0);
        getstr(input);
        buffer->lastCom = input;
        token = strtok(input, " ");
        turtle->command = token;

        /*Split the input token into the command, shown as turtle->command, and value, shown as turtle->value*/
        while(token != NULL)
        {
            turtle->value = atoi(token);
            token = strtok(NULL, " ");
        }

        /*Go into functions.c and use the appropriate command to the input as well as updating the queue with the latest command*/
        printCommands(buffer);
        doCommand(turtle);
        refresh();
        i = 0;

        /*Draw the @ symbol where the turtle is supposed to be after the commands were carried out*/
        mvaddch(turtle->yPos, turtle->xPos, '@');
    }

    cbreak();
    noecho();
    refresh();
    endwin();

    return 0;
}
