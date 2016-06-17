/***********************************a2.h****************************************************
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

typedef struct
{
    char * command;
    char * color;
    int dir;
    int value;
    int isPen;
    int xPos;
    int yPos;
} Turtle;

typedef struct
{
    char * lastCom;
    char * secondCom;
    char * thirdCom;
} Buffer;

void drawBoard();
void moveForward(int distance, int angle, int forbac, Turtle * turtle);
void printCommands(Buffer * buffer);
void doCommand(Turtle * turtle);
