#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void displayBoard(char a[]);
char playerTurn(bool trueOrfalse);
char revealWinner(char arr[]);
void alreadyTaken(char arr[], char c, int n);

int main()
{
    char posArr[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    displayBoard(posArr);
    bool playerOneTurn = true;
    char ch;

    while(true)
    {
        int choice;
        char winner;

        ch = playerTurn(playerOneTurn);
        scanf("%d", &choice);
        alreadyTaken(posArr, ch, choice);
        system("clear");
        displayBoard(posArr);
        playerOneTurn = !playerOneTurn;

        winner = revealWinner(posArr);
        if (winner == 'X')
        {
            printf("Player 1 wins\n");
            break;
        }
        else if (winner == 'O')
        {
            printf("Player 2 wins\n");
            break;
        }
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

//Function to determine winner
char revealWinner(char arr[])
{
    char winningChar;

    //each conditional statement checks for a different winning scenario

    //either column 0, row 0, or the diagonal from top left to bottom right have a winner
    if (
        (arr[0] == arr[1] && arr[0] == arr[2]) ||
        (arr[0] == arr[3] && arr[0] == arr[6]) ||
        (arr[0] == arr[4] && arr[0] == arr[8])
        )
    {
        winningChar = arr[0];
    }
    //the middle column has a winner
    else if (arr[1] == arr[4] && arr[1] == arr[7])
    {
        winningChar = arr[1];
    }
    //either column 2, row 0, and the diagonal from top right to bottom left have a winner
    else if (
        (arr[2] == arr[1] && arr[2] == arr[0]) ||
        (arr[2] == arr[4] && arr[2] == arr[6]) ||
        (arr[2] == arr[5] && arr[2] == arr[8])
        )
    {
        winningChar = arr[2];
    }
    //the middle row has a winner
    else if (arr[3] == arr[4] && arr[3] == arr[5])
    {
        winningChar = arr[3];
    }
    //the bottom row has a winner
    else if (arr[6] == arr[7] && arr[6] == arr[8])
    {
        winningChar = arr[6];
    }
    return winningChar;
}

//Function to stop players from marking a spot that was already marked
void alreadyTaken(char arr[], char ch, int choice)
{
    if (arr[choice-1] != 'X' && arr[choice-1] != 'O')
            arr[choice-1] = ch;
        else
        {
            printf("Pick a different number.\n");
            while (arr[choice-1] == 'X' || arr[choice-1] == 'O')
                scanf("%d", &choice);
            arr[choice-1] = ch;
        }
}
