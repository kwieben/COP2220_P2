/*
 * Program Name: COP 2220 Project 2
 *
 * Author: N01451619
 *
 * Date: 9/24/2019
 *
 * Description: A game of Rock, Paper, Scissors
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

// function declerations
void initialize_random(void),       // init random library
     flush_scanf(void);             // clear buffer
bool did_player_win(int, int);      // check if player has won
int generate_computer_choice(int),  // generate computer move
    user_choice(void);              // check user move
char get_user_input(void);          // capture user move

/*
 * Function Name: main 
 *
 * Input Parameters: void
 * 
 * Description: main called on excute. Contain main game logic. 
 *
 * Return Value: 1 or 0 based on program state. 
 */
int main(void) {
  enum NUMBERS {ZERO, ONE, TWO, THREE}; // Constants
  enum OUTCOMES {WINS, LOSSES, TIES, QUIT};
  int arry[5] = {1,2,3,4,5};
  // computer, user, score variables
  int userPiece, 
      computerPiece, 
      scoreBoard[THREE] = {ZERO, ZERO, ZERO};

  // game messages
  char 
    *gamePieces[THREE][TWO] = 
      {
        {"Rock","Rock breaks Scissors"},
        {"Paper","Paper covers Rock"},
        {"Scissors","Scissors cut Paper"}
      }, // game moves and messages
    *tieGameString[TWO] = 
      {
        "We picked the same thing",
        "it is a tie."
      },
    *userWonString = "you win!", 
    *computerWonString = "the computer wins!";
  
  initialize_random(); // init rand 

  // print welcome message
  printf("Let’s play a game of %s/%s/%s \n\n",
    gamePieces[ZERO][ZERO], 
    gamePieces[ONE][ZERO], 
    gamePieces[TWO][ZERO]);

  // play the game while user choice isn't less than array index[ZERO]
  while((userPiece = user_choice()) != QUIT){
    computerPiece 
      = generate_computer_choice(THREE); // generate computer choice

    bool playerWin 
          = did_player_win(userPiece, computerPiece), // user game?
         tieGame 
          = computerPiece == userPiece; // tie game?
    
    // update score board
    if(playerWin)
    {
      scoreBoard[WINS]++;
    }
    else if(tieGame)
    { 
      scoreBoard[TIES]++;
    }
    else
    {
      scoreBoard[LOSSES]++;
    } 

    // display results
    printf("You picked %s, the computer picked %s.\n",
      gamePieces[userPiece][ZERO], 
      gamePieces[computerPiece][ZERO]);

    printf("%s, %s \n\n",
      tieGame ? 
        tieGameString[ZERO] :
          playerWin ? 
            gamePieces[userPiece][ONE] : 
              gamePieces[computerPiece][ONE],
      tieGame ? 
        tieGameString[ONE] : 
          playerWin ? 
            userWonString :
              computerWonString);
  }

  // display score board 
  printf("\nYou won %d times, the computer won %d times and it was a tie %d times. Thank you for playing!\n",
    scoreBoard[WINS],
    scoreBoard[LOSSES],
    scoreBoard[TIES]);
  return ZERO;
}

/*
 * Function Name: initialize_random
 *
 * Input Parameters: void 
 * 
 * Description: seed random 
 *
 * Return Value: void
 */
void initialize_random(void)
{
  srand(time(NULL));
  return;
}

/*
 * Function Name: did_player_win
 *
 * Input Parameters: _user and _computer move 
 * 
 * Description: Check if the user has won
 *
 * Return Value: bool 
 */
bool did_player_win(int _userMove, int _computerMove)
{
  enum MOVES{ROCK, PAPER, SCISSORS, QUIT};
  return (
    (_userMove == SCISSORS && _computerMove == PAPER) || 
    (_userMove == PAPER    && _computerMove == ROCK)  || 
    (_userMove == ROCK     && _computerMove == SCISSORS));
}
  
/*
 * Function Name: user_choice
 *
 * Input Parameters: void
 * 
 * Description: check and return user game choice
 *
 * Return Value: int 
 */
int user_choice()
{
  enum MOVES{ROCK, PAPER, SCISSORS, QUIT}; // local constants
  do // only exit if vaild choice
  {
    switch(toupper(get_user_input())) // vaildate user input
    {
      case 'R':
        return ROCK;
      case 'P':
        return PAPER;
      case 'S':
        return SCISSORS;
      case 'Q':
        return QUIT;
      default:
        printf("Error: Invalid choice, try again. \n");
    }
  }while(true);
}

/*
 * Function Name: get_user_input
 *
 * Input Parameters: void
 * 
 * Description: get user choice
 *
 * Return Value: char 
 */
char get_user_input(){
    char userChoice;
    printf("Enter the R, P, S, or Q (for quit): ");
    scanf("%c", &userChoice);
    flush_scanf();
    return userChoice;
}
/*
 * Function Name: generate_computer_choice
 *
 * Input Parameters: void
 * 
 * Description: Randomly pick a game piece for the computer
 *
 * Return Value: void 
 */
int generate_computer_choice(int _range)
{
    return rand() % _range;
}

/*
 * Function Name: flush_scanf
 *
 * Input Parameters: void
 * 
 * Description: Flush scanf  
 *
 * Return Value: void 
 */
void flush_scanf(void)
{
    char c;
    while((c = getchar()) != '\n' && c != EOF)
    return;
}
