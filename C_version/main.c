// include required header files
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * board: board initialization
 * print_board: Printing board state after player selection
*/

char board[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

void print_board() 
{
    printf("-------------\n");
    printf("| %c | %c | %c |\n", board[0], board[1], board[2]);
    printf("-------------\n");
    printf("| %c | %c | %c |\n", board[3], board[4], board[5]);
    printf("-------------\n");
    printf("| %c | %c | %c |\n", board[6], board[7], board[8]);
    printf("-------------\n");
}

/**
 * check_win: winning validation function
 * @player: parameter player
 * return: true if the conditions for winning are met, else, false
*/

int check_win(char player) 
{
    if ((board[0] == player && board[1] == player && board[2] == player) ||
        (board[3] == player && board[4] == player && board[5] == player) ||
        (board[6] == player && board[7] == player && board[8] == player) ||
        (board[0] == player && board[3] == player && board[6] == player) ||
        (board[1] == player && board[4] == player && board[7] == player) ||
        (board[2] == player && board[5] == player && board[8] == player) ||
        (board[0] == player && board[4] == player && board[8] == player) ||
        (board[2] == player && board[4] == player && board[6] == player)) 
    {
        return 1;
    } 
    else 
    {
        return 0;
    }
}

// Define player indicators
char player1 = 'X';
char player2 = 'O';

// Define variable to indicate who is playing first
char current_player = 'X';

// Loop until there is a winner or the board is full
int main() 
{
    int move;
    // Initializing random number generator
    srand(time(NULL));

    while(1) 
    {
        // Get input from the user on where they want to place their marker
        if(current_player == player1) 
        {
            printf("Player X, please enter a number between 1 and 9 to make your move: ");
            scanf("%d", &move);
            move--;
        }
        //------------------AI player 2-----------------------------
        else 
        {
            int options[9], count=0, i;
            for(i=0; i<9; i++) 
            {
                if(board[i] == ' ') 
                {
                    options[count++] = i+1;
                }
            }
            move = options[rand()%count]-1;
        }

        // Check if position is already occupied
        if(board[move] != ' ') 
        {
            printf("That position is already occupied. Please choose another one.\n");
            continue; // go back to the beginning of the loop
        }

        // Place the current player's marker on the board
        board[move] = current_player;

        // Print out the updated board
        print_board();

        // Check if the current player has won
        if(check_win(current_player)) 
        {
            printf("Congratulations, Player %c wins!\n", current_player);
            break; // end the game
        }

        // Check if the board is full
        int i, flag=0;
        for(i=0; i<9; i++) 
        {
            if(board[i] == ' ') 
            {
                flag=1;
                break;
            }
        }
        if(!flag) 
        {
            printf("The game is a tie!\n");
            break; // end the game
        }

        // If no one has won and the board isn't full, switch to the other player
        if(current_player == player1)
            current_player = player2;
        else
            current_player = player1;
    }

    return 0;
}
