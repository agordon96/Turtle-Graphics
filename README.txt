This program emulates the Berkeley Logo turtle graphics game, where a turtle is used to move around and draw shapes using simplistic
commands. Ncurses was the primary tool in creating the graphics for this game in C.

//*********HOW IT WORKS*********\\
Simply enter one of the commands below with the correct syntax and the program will do the work for you outlined for each command.
If the spelling is done wrong for a command, the program will offer a friendly reminder that the program "does not know" the command
and will ask for another input right after.

//***********COMMANDS***********\\
lt x - Turns the turtle to the left by the number given by x, in degrees.
rt x - Turns the turtle to the right by the number given by x, in degrees.
fd x - Moves the turtle forward based on its current angle by a set amount of paces given by x.
bk x - Moves the turtle backward based on its current angle by a set amount of paces given by x.
pd   - Puts the pen down, allowing lines to be drawn along the turtle's path.
pu   - Picks the pen up, disallowing lines to be drawn along the turtle's path.
home - Resets the board and the turtle's values to their default settings.

setpencolor x : Sets the foreground (the trail, text and turtle) to a set color given by x;
1    - Red
2    - Blue
3    - Green
4    - White
5    - Yellow

quit - Simply typing quit will exit you from the program entirely.

//**********LIMITATIONS**********\\
- Pen down and pen up register as true/false but they don't physically do anything to the program.
- Setting rt or lt equal to a very large number will cause problems with angle registration and not turn the turtle properly.
- Going fd or bk too far will not stop the turtle from going off of the board, nor will the trail stop along with it.
- The buffer messages for the queue does not work properly and will give false histories for past commands.
- No reading of any sort is done on the board on program completion.