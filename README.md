# Minesweeper
A C++ minesweeper game.
It's functional with no errors up till now.
It has 3 levels (easy - intermediate - hard).
Mines are generated randomly and first click is guaranteed not to be a mine.
Flags and question marks are allowed.
A track of time, clicks and mines left are available.
The player loses when he open a mine.
The player wins when the number of unopened cells is equal the number of mines and he didn't lose before.
When an empty cell is opened. all the empty adjacent cells are opened too.
The score is calculated as follow: (rows^4 * columns^4)  /(seconds * clicks).
The number of mines is calculated as follows: 1 + (rows * columns) / 10.

An option to save a game and load it in a later time is added to the menu but not coded yet.
Also a file that saved the scores of players is created and scores are stored in, but can't retrieve it back or display it yet.
