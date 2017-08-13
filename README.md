# Minesweeper
A C++ minesweeper game .. it's functional with no errors up till now.
it has 3 levels (easy - intermediate - hard).
mines are generated randomly and first click is guaranteed not to be a mine.
flags and question marks are allowed.
a track of time, clicks and mines left are available.
the player loses when he open a mine.
the player wins when the number of unopened cells is equal the number of mines and he didn't lose before.
when an empty cell is opened .. all the empty adjacent cells are opened too.
the score is calculated as follow: (rows^4*columns^4)/(seconds*clicks).
the number of mines is calculated as follows: 1+(rows*columns)/10.

an option to save a game and load it in a later time is added to the menu but not coded yet.
also a file that saved the scores of players is created and scores are stored in, but can't retrieve it back or display it yet.
