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

  // More initialization code as needed
    char play = '.';
    char guess;

    // initialize the guess word array
    int tarlen = strlen(targetWord);

    for (int i = 0; i < tarlen; i++)
    {
        word[i] = '*';
    }
    word[tarlen] = '\0';
  // The game should continue until a word
  //  is guessed correctly, a '!' is entered,
  //  or 10 turns have elapsed without the word being guessed
    int attempts = 10;
    while (attempts > 0)
    {
        cout << attempts << " remain: " << word << endl; // how many guesses do you have and what have you already guessed
        cout << "Enter a letter: "; // give me something to work with here
        cin >> guess;

        if ( guess == '!')
        {
            play = 'n';
            break; // lame-o quitters right here
        } // end quitters
        else // compare the guess
        {
            // gimme a word pointers
            char* guessing = &word[0];
            const char* target = &targetWord[0];

            // call me the comparison function!!!
            int trying = processGuess(guessing, target, guess);
            // what's the verdict? do they stay, do they lose a guess? are they confused with life?
            if (trying == 0)
            {
                // hangman time, they lose a guess
                attempts--;
            }

        } // end guess comparing

    } // end playing loop

  // Print out end of game status
    bool end = strcmp(targetWord, word); // check the results

    if (end == true)
    {
        cout << "Win! " << attempts << " guesses to spare." << endl; // win and extra guesses
    }
    else if (play == 'n')
    {
        cout << "Quit!" << endl; // they want to quit cause they're lame
    }
    else
    {
        cout << "Lose" << word << endl; // lose and final word
    }

    // end game satus print out

    
  return 0;
}

// Given the current version of the word, target/selected word, and
// the character that the user just guessed, change the word to 
// "turn on" any occurrences the guess character and return a count
// of how many occurrences of 'guess' were found
int processGuess(char* word, const char* targetWord, char guess)
{
  int worlen = strlen(targetWord); // get the target word length
  int guslen = strlen(word); // get the guess word length
  int lettercount = 0;
  char truther = 'y'; // if they've gussed it already they're a liar not a truther

  // make a pointer for the guessed letter
  const char* g = &guess;

  // check that the letter isn't already guessed
  for (int j=0; j < guslen; j++)
  {
    int guessed = strcmp(word, g);
    if (guessed != 0)
    {
        truther = 'n'; // *gasp* liar! they've already guessed this letter, for shame
        break;
    }
  }

  if (truther = 'y') // they have not guessed this yet :)
  {
    for (int i=0; i < worlen; i++)
    {
        const char* tarval = targetWord; // letter assignment for target word index
        int check = strcmp(tarval, g); // compare the letters

        if (check == 0)
        {
            lettercount++; // increment the letter counter
            word[i] = guess; // change the * to the guess letter
        }
    }
  }

    
    return lettercount;
    
}
}
