// game.cpp
// Word guessing game illustrates C-strings, some C-string library functions,
//  functions and array passing.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

// Prototype. we'll define this below.
int processGuess(char word[], const char targetWord[], char guess);

// Define an array of strings (since a string is just a char array)
//  and since string literals (e.g. "hi") evaluate to the starting address
//  of those characters, we really want an array of char *'s
const char* wordBank[] = {"computer", "president", "trojan", "program",
                          "coffee", "library", "football", "popcorn", 
                          "science", "engineer"};

const int numWords = 10;

int main(int argc, char* argv[])
{
  //------------- Do not modify this code --------------
  if(argc < 2){
    srand(time(0)); // use the time to get randomly chosen words each run
  }
  else {
    srand(atoi(argv[1])); // use the command line argument as the seed
  }

  // Pick a random word from the wordBank
  const char* targetWord = wordBank[rand() % numWords];

  int numTurns = 10; // variable to track how many turns remain

  char word[80];  // a blank array to use to build up the answer
                  // It should be initialized with *'s and then
                  //  change them to the actual letters when the 
                  //  user guesses the letter

  // More initialization code as needed ****************************************************
  //get target word length
  int tarlen = strlen(targetWord);

  //create pointer for word to initialize
  char *wordpt = word;
  //initialize the array
  for(int a=0; a < tarlen; a++)
  {
    *wordpt = '*';
    wordpt++;
  }//end initialize array
  
  // don't forget the null character
  word[tarlen] = '\0';

  // initialize values for continuous play
  char play = '.'; // quit value
  int attempts = 10; // turns

  // begin continuous play **********************************************************************
  while (attempts > 0)
  {
    // initialize guess letter in loop so it is reset each time
    char guess;

    cout << attempts << " guesses remain: " << word << endl;
    cout << "Enter a letter: " << endl;
    cin >> guess;

    if (guess == '!')
    {
        play = '!';
        attempts = 0;
        break;
    }

    // now check the hangman letters
    // will return an integer value of the number of letters correct
    int numLetters = processGuess(word, targetWord, guess);

    if (numLetters == 0) // letter was already guessed or not in the target word
    {
        attempts--;

    } // end bad guess

    // do they match? if so then break
    const char *guessing = word;
    int checkwords = strcmp(targetWord, guessing);
    if (checkwords == 0)
    {
        break;
    }


  } // end continuous play **********************************************************************
    
    // evaluate the end results ***********************************************************
    if (play == '!') // player wants to quit
    {
        cout << "Quit!" << endl;
    } // end player quit
    else // print win or loss
    {
        // make a pointer to the guessed word to evaluate
        const char *finalguess = word;
        //compare the guessed word and the target word ********* use of strcmp ***********************
        int score = strcmp(targetWord, finalguess);

        //get the results of the comparison and print the player's final score
        if (score == 0) // winning statement
        {
            cout << "Win! " << attempts << " guesses to spare." << endl;
        } // end winning statement
        else // losing statement
        {
            cout << "Lose! " << word << endl;
        } // end losing statement
        
    } // end win or loss *************************************************************************

    // the end goodbye!

  return 0;
}

// Given the current version of the word, target/selected word, and
// the character that the user just guessed, change the word to 
// "turn on" any occurrences the guess character and return a count
// of how many occurrences of 'guess' were found
int processGuess(char word[], const char targetWord[], char guess)
{
    // receives pointer to word[0] and targetWord[0], and just the character entered
    // targetWord is the array of characters in the target word
    // word is the hangman letters (*)

    //count of occurences of guessed letter
    int lettercount = 0;

    const char* occurs = strchr(targetWord, guess);
    if (occurs != NULL) // the letter IS in the targetWord
    {
        //has this letter already been guessed?
        char* liar = strchr(word, guess);

        // NULL if it has not, so execute '*' to letter changes
        if(liar == NULL)
        {
            // they are a truther cause they haven't guessed that letter yet
            // get the word length for the for loop replacement process
            int tarlength = strlen(targetWord);
            // replace the stars with letters
            for(int l=0; l < tarlength; l++)
            {
                if (targetWord[l]== guess) // check against the target word location
                {
                    word[l] = guess; // replace the * at the corresponding guess word location
                    lettercount++;
                } 
            } // end letter replacement


        } // end if the letter has not already been guessed

    } // end if the letter IS in the targetWord
    
    //return the letter count
    return lettercount;
    
}
