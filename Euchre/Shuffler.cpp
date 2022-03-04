#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Shuffler.h"

#include "Card.h";

using namespace Euchre;

// Referenced and modified from: https://kalkicode.com/shuffle-an-array-in-cpp

void Shuffler::swapElement(Card deck[], int i, int j)
{
    // Get i location element
    int tempValue = deck[i].Value;
    int tempSuit = deck[i].Suit;

    // Set new values
    deck[i].Value = deck[j].Value;
    deck[i].Suit = deck[j].Suit;

    deck[j].Value = tempValue;
    deck[j].Suit = tempSuit;
}
// Returns the random location of array elements
int Shuffler::randomLocation(int min, int max)
{
    // Calculate random number between given range
    return rand() % (max - min) + min;
}

// Function which is shuffle given array elements
void Shuffler::shuffleElement(Card arr[], int size)
{
    // (i,j) indicate locations
    int j = 0;
    int i = 0;
    // Variable which is controlling the 
    // execution process of loop
    int counter = 0;
    // Loop which is shuffling random elements in array
    while (counter < size)
    {
        // Get random location of array index
        i = randomLocation(0, size);
        j = randomLocation(0, size);
        if (i != j)
        {
            // Swap array elements
            swapElement(arr, i, j);
            counter++;
        }
    }
}