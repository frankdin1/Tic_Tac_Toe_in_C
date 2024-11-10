#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void displayBoard(char a[]);
char playerTurn(bool trueOrfalse);
bool showWinner(char arr[]);

int main()
{
    char posArr[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    displayBoard(posArr);
    bool playerOneTurn = true;
    char ch;
    //int arrLength = sizeof(posArr) / sizeof(posArr[0]);

    while(true)
    {
        int choice;
        bool weHaveAWinner;

        ch = playerTurn(playerOneTurn);
        scanf("%d", &choice);
        if (posArr[choice-1] != 'X' && posArr[choice-1] != 'O')
            posArr[choice-1] = ch;
        else
        {
            printf("Pick a different number.\n");
            while (posArr[choice-1] == 'X' || posArr[choice-1] == 'O')
                scanf("%d", &choice);
            posArr[choice-1] = ch;
        }
        system("clear");
        displayBoard(posArr);
        playerOneTurn = !playerOneTurn;

        weHaveAWinner = showWinner(posArr);
        if (weHaveAWinner)
            break;
        /*if(
            posArr[0] == posArr[1] && posArr[0] == posArr[2] ||
            posArr[3] == posArr[4] && posArr[3] == posArr[5] ||
            posArr[6] == posArr[7] && posArr[6] == posArr[8] ||
            posArr[0] == posArr[3] && posArr[0] == posArr[6] ||
            posArr[1] == posArr[4] && posArr[1] == posArr[7] ||
            posArr[2] == posArr[5] && posArr[2] == posArr[8] ||
            posArr[0] == posArr[4] && posArr[0] == posArr[8] ||
            posArr[2] == posArr[4] && posArr[2] == posArr[6]
            )
        {
            printf("Winner");
            break;
        }*/

    }

    return 0;
}

//Code to display board
void displayBoard(char arr[])
{
    printf("\t\tTIC TAC TOE\n");
    printf("\tPlayer One(X)\tPlayer Two(O)\n");
    printf("\n");

    int col = 0;
    for (int i = 0; i < 9; i++)
    {
        printf("\t%c   |", arr[i]);
        col++;
        if (col % 3 ==0)
        {
            printf("\n");
            printf("\t_____________________\n");
            printf("\n");
            col = 0;
        }
    }
}

//Function to switch player turns
char playerTurn(bool firstPlayerTurn)
{
    char c;
    if (firstPlayerTurn)
    {
        printf("Player 1, pick a number: ");
        c = 'X';
    }
    else
    {
        printf("Player 2, pick a number: ");
        c = 'O';
    }
    return c;
}

//Function to display winner
bool showWinner(char arr[])
{
    bool winnerDeclared = false;
    if (
        (arr[0] == arr[1] && arr[0] == arr[2]) ||
        (arr[0] == arr[3] && arr[0] == arr[6]) ||
        (arr[0] == arr[4] && arr[0] == arr[8])
        )
    {
        if (arr[0] == 'X')
        {
            printf("Player 1 wins\n");
            winnerDeclared = true;
        }
        else if (arr[0] == 'O')
        {
            printf("Player 2 wins");
            winnerDeclared = true;
        }
    }
    return winnerDeclared;
}
