#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void setName(char *arr, char *arr2)
{
    for (int i = 0; arr2[i]; i++)
    {
        arr[i] = arr2[i];
    }
}
int main()
{
    srand(time(0));

    int mainCount;
    int select;
    int random[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
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
    char computer[10] = "computer";

    int toss;
    int size = (sizeof((random)) / sizeof((random[0])));

    printf("\033[0;31m");
    printf("LET'S PLAY TICTACTOE \n");
    printf("\033[0m");
    printf("Select Your Opponent\nPRESS the respective number  \n");

    printf("\033[0;34m");

    printf("1.Human \n2.Computer \n");
    printf("\033[0m");

    scanf("%d", &select);
    fflush(stdin);
    switch (select)
    {
    case 1:
        printf("\033[0;35m");
        printf("Player 1 Name: \n");
        gets(firstPlayer);
        printf("\033[0m");

        printf("\033[0;36m");
        printf("Player 2 Name: \n");
        gets(secondPlayer);
        printf("\n");
        printf("\033[0m");

        printf("Press Any Key  for the Toss \n");
        getchar();
        toss = rand() % 3;
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
                    if (chart[i][j] == 'O')
                    {
                        printf("\033[0;31m");
                    }
                    else if (chart[i][j] == 'X')
                    {
                        printf("\033[0;32m");
                    }

                    printf("%c  ", chart[i][j]);
                    printf("\033[0m");
                }
                printf("\n");
            }
            // printf("\033[0m");

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
                        printf("\033[0;34m");
                        printf("********** %s Won  ,Congratulations******* \n", winnerName);
                        printf("\033[0m");
                        printf("\033[0;35m");
                        printf("GOL GAPE KHILA DE HUN TA");
                        printf("\033[0m");

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
        break;
    case 2:

        /// Vs Computer
        printf("Player's Name: \n");
        gets(firstPlayer);
        setName(firstTurn, firstPlayer);
        setName(secondTurn, computer);

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
                        if (winnerName == secondTurn)
                        {
                            printf("TUMSE NA HO PAYEGA");
                        }
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

            if (mainCount % 2 == 0)
            {
                int idx;
                printf("Enter the position:\n");
                scanf("%d", &position);

                // get the index to delte the element
                for (int i = 0; i < 10; i++)
                {
                    if (random[i] == position)
                    {
                        idx = i;
                    }
                }
                // delete element
                for (int i = idx; i < size; i++)
                {
                    random[i] = random[i + 1];
                }
                size = size - 1;
            }
            else
            {
                int randomPositon = rand() % size;

                // assin position randomly
                for (int i = 0; i < size; i++)
                {
                    position = random[randomPositon];
                }
                // delete the element
                for (int i = randomPositon; i < size; i++)
                {
                    random[i] = random[i + 1];
                }
                size = size - 1;
            }

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

        break;

    default:
        printf("please press the correct key");
    }

    return 0;
}