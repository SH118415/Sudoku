#include <stdio.h>
#include <stdlib.h>

// Sudoku is a 9x9 grid in which each row,each column and each 3x3 grid has a number from 1 to 9 only once
int sudokuArray[9][9]; //9x9 sudoku grid
int checkRowColGrid(int,int,int); // prototype declaration of the function to check Row,Column,Grid
void completeSudoku(int row,int column);

int main()
{
    int row,column;
    printf("Enter the unsolved Sudoku puzzle\n");
    for (row=0;row<9;row++)
        for (column=0;column<9;column++)
        scanf("%d",&sudokuArray[row][column]); // Entering the unsolved sudoku array values
     completeSudoku(0,0);
}

int checkRowColGrid(int row,int column,int num)//this function checks whether a number can be put in the row,column,grid of sudoku or not
{
    int startRow=(row/3)*3;
    int startColumn=(column/3)*3;
    int i;
    for(i=0;i<9;i++)
         {
        if (sudokuArray[row][i]==num) return 0;// checks the row and returns 0 if number is found
        if (sudokuArray[i][column]==num) return 0;//checks the column and returns 0 if number is found
        if (sudokuArray[startRow+ (i%3)][startColumn + (i/3)] == num) return 0;//checks the 3x3 grid and return 0 if number is found
         }
    return 1; //returns 1 if number is not found anywhere
}

void completeSudoku(int row,int column)
{
    if (sudokuArray[row][column]!=0)
        {
           (column<8) ? completeSudoku(row,column+1) : completeSudoku(row+1,0);// if the sudoku array value is not zero then it has a number from 1 to 9 so move further
        }
        else
        {
            int num;
            for(num=1;num<=9;num++) // if the sudoku array is zero check which number will fill the cell
            {
               if (checkRowColGrid(row,column,num))
               {
                   sudokuArray[row][column]=num;
                   (column<8) ? completeSudoku(row,column+1) : completeSudoku(row+1,0); // after the number is filled move to the next cell

               }
            }
            sudokuArray[row][column]=0; //No valid number was found
        }
        if(row>8) // the sudoku puzzle is completed and result is displayed on the screen
        {
            int ro,col;
            printf("The completed puzzle\n");
            for( ro=0;ro<9;ro++)
            {
                for(col=0;col<9;col++)
                    printf("%d ",sudokuArray[ro][col]);
                printf("\n");

            }
        }
}



