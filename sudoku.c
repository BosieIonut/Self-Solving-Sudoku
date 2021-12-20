#include <stdio.h>
#include <stdlib.h>

#define N 9
void print(int v[N][N])
{
     for (int i = 0; i < N; i++)
      {
         for (int j = 0; j < N; j++)
            printf("%d ",v[i][j]);
         printf("\n");
       }
       printf("\n");
}
 
int valid(int x[N][N], int row, int col, int num)
{
     
    for (int i = 0; i <= 8; i++)
        if (x[row][i] == num)
            return 0;

    for (int i = 0; i <= 8; i++)
        if (x[i][col] == num)
            return 0;

    int startRow = row - row % 3,
                 startCol = col - col % 3;
   
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (x[i + startRow][j +
                          startCol] == num)
                return 0;
 
    return 1;
}
 
int backtr(int x[N][N], int row, int col)
{
    if (row == N - 1 && col == N)
        return 1;

    if (col == N)
    {
        row++;
        col = 0;
    }
    

    if (x[row][col] > 0)
        return backtr(x, row, col + 1);
 
    for (int num = 1; num <= N; num++)
    {
         
        if (valid(x, row, col, num)==1)
        {
            x[row][col] = num;
           
            if (backtr(x, row, col + 1)==1)
                return 1;
        }

        x[row][col] = 0;
    }
    return 0;
}
 
int main()
{
    int A[9][9] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}};
    
 
    if (backtr(A, 0, 0)==1)
        print(A);
    return 0;
}