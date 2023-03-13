import random

# board initialization
board = [" ", " ", " ", " ", " ", " ", " ", " ", " "]

# Printing board state after player selection
def print_board():
    print("-------------")
    print("|", board[0], "|", board[1], "|", board[2], "|")
    print("-------------")
    print("|", board[3], "|", board[4], "|", board[5], "|")
    print("-------------")
    print("|", board[6], "|", board[7], "|", board[8], "|")
    print("-------------")

# Winning conditions: check!
def check_win(player):
    if (board[0] == player and board[1] == player and board[2] == player or
        board[3] == player and board[4] == player and board[5] == player or
        board[6] == player and board[7] == player and board[8] == player or
        board[0] == player and board[3] == player and board[6] == player or
        board[1] == player and board[4] == player and board[7] == player or
        board[2] == player and board[5] == player and board[8] == player or
        board[0] == player and board[4] == player and board[8] == player or
        board[2] == player and board[4] == player and board[6] == player):
        return True
    else:
        return False

# Define player indicators
player1 = "X"
player2 = "O"

# Define variable to indicate who is playing first
current_player = player1

# Loop until there is a winner or the board is full
while True:
    # Get input from the user on where they want to place their marker
    if current_player == player1:
        move = int(input("Player " + current_player + ", please enter a number between 1 and 9 to make your move: ")) - 1
    
    # -------------AI player 2-------------------------------
    else:
        move = random.choice([i for i in range(9) if board[i] == " "])
        
    # Check if position is already occupied
    if board[move] != " ":
        print("That position is already occupied. Please choose another one.")
        continue # go back to the beginning of the loop
    
    # Place the current player's marker on the board
    board[move] = current_player
    
    # Print out the updated board
    print_board()
    
    # -----------Check if the current player has won--------------
    if check_win(current_player):
        print("Congratulations, Player " + current_player + " wins!")
        break # end the game
        
    # Check if the board is full
    if " " not in board:
        print("The game is a tie!")
        break # end the game
    
    # If no one has won and the board isn't full, switch to the other player
    if current_player == player1:
        current_player = player2
    else:
        current_player = player1
