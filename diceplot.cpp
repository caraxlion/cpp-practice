// ============================================================================
// diceplot.cpp
// Caroline Richards
//
// ============================================================================
#include <iostream>
#include <cstdlib>
#include <string.h>
#include <iomanip>
using namespace std;
// Prototype/define functions anywhere below
int roll()
{
  // decalre rolls sum
  int sum =0;
  // simulate 4 rolls
  for (int i = 1; i <=4; i++)
  {
    int die = rand()%6 +1;
    sum += die;
  }
  return sum;
}
// histogram for numbers
void printHistogram(int counts[])
{ 
  for(int i=4; i < 25; i++) // i is the sum of 4 rolls
  {
    cout << i << ":";
    cout << setfill('X') << setw(counts[i-4]) << endl;
  }
}

int main()
{
  int seed, n;
  cin >> seed >> n;
  // Seed the pseudo-random number generator for repeatable results
  srand(seed);
  // practice for generating rolls
  //int r = rand()%6 +1;
  //int r2 = rand()%6 +1;
  //cout << r << " " << r2 << endl;
  // Your code here
  int dice[21] = {0};
  // populate the array with rolls
  for (int i = 0; i < n; i++)
  {
    int temp = roll();
    for (int j = 0; j < 21; j++)
    {
      if (j == temp - 4) // minus 4 since sum can't be 4
      {
        dice[j]++;
        break;
      }
    }
  }
  // call printHistogram
  printHistogram(dice);
  return 0;
}