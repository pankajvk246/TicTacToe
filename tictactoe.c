#include <stdio.h>
#include <stdlib.h>
void setName(char *arr, char *arr2)
{
    for (int i = 0; arr2[i]; i++)
    {
        arr[i] = arr2[i];
    }
}
int main()
{
    int mainCount;
    char arr[3][3] = {{1, 2, 3},
                      {4, 5, 6},
                      {7, 8, 9}};
    char chart[3][3] = {"123",
                        "456",
                        "789"};
    char firstPlayer[10] = {};
    char secondPlayer[10] = {};
    char firstTurn[10] = {};
    char secondTurn[10] = {};
    int toss;
    printf("LET'S PLAY TICTACTOE \n");

    printf("Player 1 Name: \n");
    gets(firstPlayer);
    printf("Player 2 Name: \n");
    gets(secondPlayer);
    printf("\n");

    printf("Lets get ready for the Toss \n");
    toss = rand() % 2;
    // printf("%d",toss);
    if (toss == 1)
    {
        printf("%d toss 1", toss);

        // firstTurn = firstPlayer;
        setName(firstTurn, firstPlayer);
        // secondPlayer = secondPlayer;
        setName(secondTurn, secondPlayer);
    }
    else
    {
        printf("%d toss 2", toss);

        // firstTurn = secondPlayer;
        setName(firstTurn, secondPlayer);

        // secondPlayer = firstPlayer;
        setName(secondTurn, firstPlayer);
    }
    printf("%s gets the first turn\n", firstTurn);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%c  ", chart[i][j]);
        }
        printf("\n");
    }

    // main loop and traversing and

    for (mainCount = 0; mainCount < 10; mainCount++)
    {
        printf("\e[1;1H\e[2J");
        char charcter;
        char chr;
        int position;
        if (mainCount % 2 == 0)
        {
            charcter = 'O';
        }
        else
        {
            charcter = 'X';
        }

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                printf("%c  ", chart[i][j]);
            }
            printf("\n");
        }
        // winning logic + result

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 1; j++)
            {
                if ((chart[i][j] == chart[i][j + 1] && chart[i][j] == chart[i][j + 2]) || (chart[j][i] == chart[j + 1][i] && chart[j][i] == chart[j + 2][i]) || (chart[i][j] == chart[i + 1][j + 1] && chart[i][j] == chart[i + 2][j + 2]) || (chart[i][j + 2] == chart[i + 1][j + 1] && chart[i][j + 2] == chart[i + 2][j]))
                {
                    // winner name code
                    char winnerName[10] = {};
                    if ((charcter != 'O'))
                    {
                        // winnerName = secondPlayer;
                        setName(winnerName, firstTurn);
                    }
                    else if ((charcter == 'O'))
                    {
                        // winnerName = firstPlayer;
                        setName(winnerName, secondTurn);
                    }
                    printf("********** %s Won  ,Congratulations******* \n", winnerName);
                    printf("GOL GAPE KHILA DE HUN TA");
                    exit(0);
                }
            }
        }
        if (mainCount == 9)
        {
            printf("MATCH Drawn");
            break;
        }

        printf("%s's Turn \n", mainCount % 2 == 0 ? firstTurn : secondTurn);

        printf("Enter the position:\n");
        scanf("%d", &position);
        // int array loop to compare position
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (position == arr[i][j])
                {
                    // inserting charcter in char array
                    for (int l = 0; l < 3; l++)
                    {
                        for (int k = 0; k < 3; k++)
                        {
                            if ((i == l) && (j == k))
                            {
                                chart[i][j] = charcter;
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}