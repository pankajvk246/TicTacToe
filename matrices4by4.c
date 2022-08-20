#include <stdio.h>
#include <stdlib.h>
int main()
{
    char arrow;
    int row = 3, column = 3;
    int arr[4][4] = {{01, 10, 9, 12},
                     {14,04, 02, 11},
                     {3, 8, 7, 13},
                     {6, 5, 15,0}};

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {

            printf("%d  ", arr[i][j]);
        }
        printf("\n");
    }

    for (int k = 0; k < 10; k++)
    {
        printf("press arrow keys to make a move \n");
        arrow = _getch();
        // printf("%c \n", arrow);

        // scanf("%c", &arrow);

        if (arrow == 72)
        {
            // sorting
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if ((i == row) && (j == column))
                    {
                        int temp;
                        temp = arr[i - 1][j];
                        arr[i - 1][j] = arr[i][j];
                        arr[i][j] = temp;
                        row = i - 1;
                    }
                }
            }
        }
        else if (arrow == 75)
        {
            printf("LEFT");
            // sorting
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if ((i == row) && (j == column))
                    {
                        int temp;
                        temp = arr[i][j + 1];
                        arr[i][j + 1] = arr[i][j];
                        arr[i][j] = temp;
                        column = j + 1;
                    }
                }
            }
        }

        else if (arrow == 77)
        {
            // sorting
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if ((i == row) && (j == column))
                    {
                        int temp;
                        temp = arr[i][j - 1];
                        arr[i][j - 1] = arr[i][j];
                        arr[i][j] = temp;
                        column = j - 1;
                    }
                }
            }
        }

        else if (arrow == 80)
        {
            // sorting
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if ((i == row) && (j == column))
                    {
                        int temp;
                        temp = arr[i + 1][j];
                        arr[i + 1][j] = arr[i][j];
                        arr[i][j] = temp;
                        row = i + 1;
                    }
                }
            }
        }

        // traversing
        printf("\e[1;1H\e[2J");
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                printf("%d  ", arr[i][j]);
            }
            printf("\n");
        }
    }

    // // traversing
    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         printf("%d ", arr[i][j]);
    //     }
    //     printf("\n");
    // }

    return 0;
}