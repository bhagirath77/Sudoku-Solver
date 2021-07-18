#Automatic Sudoku Solver

What this python code does is that it creates a GUI application in which you have to fill in the entries of the sudoku that are given initially and then it will automatically solve the rest of the sudoku.
The algorithm that it uses is the backtracking algorithm.It will iterate through the complete grid row by row and column by column and fill the empty boxes with values from 0 to 9, whichever are possible. If any of them gives a sodoku that isn't possible to be solved, then it will go back and fill in the next possible value.

To understand this in detail, please refer to [this](https://www.geeksforgeeks.org/sudoku-backtracking-7/) link.

### Pre-requisites:

You need to download only the pygame library. Run this command in your terminal.

```python
pip install pygame
```


### Controls:
You need to use the mouse to go to a specific box and you can use the arrow keys to go up/down/left/right in the grid.

You can overwrite the values that you have written. 

To avoid silly mistakes, the app won't allow you to enter any value other than numbers in the range 1 to 9.

### Working:
First of all , you need to enter the values in the grid.

Once you are done with that, you need to press the start button and the code will start solving the sudoku
and you can see it doing that in real time since the values will be changing on the front end.

