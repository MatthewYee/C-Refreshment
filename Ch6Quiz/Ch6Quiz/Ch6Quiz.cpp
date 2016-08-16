// Ch6Quiz.cpp : Defines the entry point for the console application.
//

/*
Pretend you’re writing a game where the player can hold 3 
types of items: health potions, torches, and arrows. 
Create an enum to identify the different types of items, 
and a fixed array to store the number of each item the 
player is carrying (use built-in fixed arrays, 
not std::array). 
The player should start with 2 health potions, 
5 torches, and 10 arrows. 
Write a function called countTotalItems() 
that returns how many items the player has in total. 
Have your main() function print the output of 
countTotalItems().
*/

#include "stdafx.h"
#include<iostream>
#include <array>
#include <string>
#include <utility>
#include <cstring>
#include <cstdlib> 
#include <ctime>

using namespace std;

// Structure student   QUIZ 2
struct Student {
	string name;
	int grade; 
};

// sorting program // remember a array deteriorate 
void sortNames( Student *students, int size)
{
	// Step through each element of the array
	for (int startIndex = 0; startIndex < size; ++startIndex)
	{
		// largestIndex is the index of the smallest element we've encountered so far.
		int largestIndex = startIndex;

		// Look for largest element remaining in the array (starting at startIndex+1)
		for (int currentIndex = startIndex + 1; currentIndex < size; ++currentIndex)
		{
			// If the current element is larger than our previously found smallest
			if (students[currentIndex].grade > students[largestIndex].grade)
				// This is the new smallest number for this iteration
				largestIndex = currentIndex;
		}

		// Swap our start element with our smallest element
		swap(students[startIndex], students[largestIndex]);
	}

}

// QUIZ 3 Refernce variable write your own function to swap the value of two integer variables.
void swapnumber(int &one, int &two)
{
	int temp = one; 
	one = two;
	two = temp;

}

// Quiz 4 question 
void printCString(const char *str)			// array deteriorated to pointers address when passed to the function 
{
	// While we haven't encountered a null terminator
	while (*str != '\0')
	{
		// print the current character
		std::cout << *str;

		// and point str at the next character
		++str;
	}
}

enum items {
	HEALTH_POTION = 2,
	TORCHES = 5,
	ARROWS = 10,
	MAX_ITEMS
};

int countTotalItems(int *item)
{
	// initialize an variable to calculate total of it
	int total = 0;

	for (int increment = 0; increment < MAX_ITEMS; ++increment)
	{
		// set total to add all of the values inside
		total += item[increment];
	}
	return total;
}

// QUIZ number 6 
enum CardRank {
	RANK_TWO,
	RANK_THREE,
	RANK_FOUR,
	RANK_FIVE,
	RANK_SIX,
	RANK_SEVEN,
	RANK_EIGHT,
	RANK_NINE,
	RANK_TEN,
	JACK,
	QUEEN,
	KING,
	ACE,
	MAX_RANK
};

enum CardSuit {
	CLUBS,
	DIAMONDS,
	HEARTS,
	SPADES,
	MAX_SUITS
};

struct Card {
	CardRank rank;
	CardSuit suit;
};

void printCard(const Card &card) { // right idea, though remember the struct takes in one. 
	using namespace std; 
	switch (card.rank) // Yeah for repetitive cases such as this a switch statement would've been better than if statement
	{
		case RANK_TWO:	   cout << "2"; break;
		case RANK_THREE:   cout << "3"; break;
		case RANK_FOUR:    cout << "4"; break;
		case RANK_FIVE:    cout << "5"; break;
		case RANK_SIX:     cout << "6"; break;
		case RANK_SEVEN:   cout << "7"; break;
		case RANK_EIGHT:   cout << "8"; break;
		case RANK_NINE:    cout << "9"; break;
		case RANK_TEN:     cout <<"10"; break;
		case JACK:		   cout << "J"; break;
		case QUEEN:        cout << "Q"; break;
		case KING:         cout << "K"; break;
		case ACE:          cout << "A"; break;
	}
	switch (card.suit)
	{
		case CLUBS:		cout << "C"; break;
		case DIAMONDS:	cout << "D"; break;
		case HEARTS:	cout << "H"; break;
		case SPADES:	cout << "S"; break;
	}
}

void printDeck(const array<Card, 52> &deck)
{
	// for each card in the deck print out its value 
	for (const auto &card : deck)
	{
		printCard(card);
		cout << " ";
	}
	cout << "\n";
}

void swapCard(Card &card1, Card &card2)
{
	Card temp = card1;		// initialize the  
	// swap the two card value
	card1 = card2;			// swap the card by reference
	card2 = temp;
}

// QUIZ 6g
// Generate a random number between min and max (inclusive)
// Assumes srand() has already been called
int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
																				 // evenly distribute the random number across our range
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void shuffleDeck(const array<Card, 52> &deck)
{
	// Step through each card in the deck
	for (int index = 0; index < 52; ++index)
	{
		// Pick a random card, any card
		int swapIndex = getRandomNumber(0, 51);
		// Swap it with the current card
		swapCard(deck[index], deck[swapIndex]);
	}
}

int getCardValue(Card &card)
{
	switch (card.rank)
	{
		case RANK_TWO:		return 2;
		case RANK_THREE:	return 3;
		case RANK_FOUR:		return 4;
		case RANK_FIVE:		return 5;
		case RANK_SIX:		return 6;
		case RANK_SEVEN:	return 7;
		case RANK_EIGHT:	return 8;
		case RANK_NINE:		return 9;
		case RANK_TEN:		return 10;
		case JACK:			return 10;
		case QUEEN:			return 10;
		case KING:			return 10;
		case ACE:			return 11;
	}
	return 0;
}

char getPlayerChoice()
{
	cout << "(h) to hit or (s) to stand: ";
	char choice;
	do 
	{
		cin >> choice;
	} while (choice != 'h' && choice != 's');
	return choice;
}

bool playBlackJack(array<Card,52> &deck)
{
	// setup initial game state
	const Card *cardPtr = &deck[0];

	// initialize player and dealer total amount
	int playerTotal = 0;
	int dealerTotal = 0;

	// Deal the player one card
	dealerTotal += getCardValue(*cardPtr++);
	cout << "The dealer is showing: " << dealerTotal << '\n';

	// Deal the player two cards
	playerTotal += getCardValue(*cardPtr);
	playerTotal += getCardValue(*cardPtr);

	//player goes first
	while (1)
	{
		cout << "You have: " << playerTotal << '\n';

		// See if the player has busted
		if (playerTotal > 21)
			return false;
		char choice = getPlayerChoice();
		if (choice == 'h')
			return false;
		else if (choice == 's')
			break;
	}
	playerTotal += getCardValue(*cardPtr++);

	// If player hasn't busted, dealer goes until he has 17 points 
	while (dealerTotal < 17)
	{
		dealerTotal += getCardValue(*cardPtr++);
		cout << "Dealer now has: " << dealerTotal << '\n';
	}

	// If dealer busted, player wins 
	if (dealerTotal > 21)
		// Player win 
		return true; 
	return(playerTotal > dealerTotal);

}

int main()
{
	int item[MAX_ITEMS] { HEALTH_POTION, TORCHES, ARROWS};
	// const int numofitems = sizeof(item) / sizeof(item[0]);
	int tot = countTotalItems(item);
	cout << tot << endl;

	// Quiz 3 
	int x = 4; 
	int y = 5;
	swapnumber(x, y);
	cout << "x is " << x << "\n";
	cout << "y is " << y << "\n";


	// Quiz number 2
	cout << "How many students: ";
	int size;
	cin >> size;

	Student *arrays = new Student[size];
	for (auto i = 0; i < size; ++i)
	{
		Student student; // initialize a student structs each iteration of the array size 
		cout << "Enter name of Student: ";
		cin >> arrays[i].name;
		cout << "Enter grade: ";
		cin >> arrays[i].grade;
	}
	sortNames(arrays, size);

	for (int index = 0; index < size; ++index)
	{
		cout << arrays[index].name << " got a grade of " << arrays[index].grade << "\n";
	}

	delete[] arrays;

	// c-style string
	const char *strings = "Hello World!";			// created 
	char t[] = "Hello World!";						// working on the 
	int spacefound = 0;
	for (int i = 0; i < strlen(t); i++)
	{
		// if the current character is a space count it
		if (t[i] == ' ')
		{
			spacefound++;
		}
		cout << t[i];
	}

	printCString("Hello World!");

	// Quiz 6d a deck of cards has 52 cards 
	array<Card, 52> deck;

	// How to initialize a deck of cards with one card each using static cast
	int card = 0; 
	for(int suit = 0; suit < MAX_SUITS; ++suit)
	for (int rank = 0; rank < MAX_RANK; ++rank)
	{
		deck[card].suit = static_cast<CardSuit>(suit);
		deck[card].rank = static_cast<CardRank>(rank);
		++card;
	}

	srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
	rand(); // If using Visual Studio, discard first random value

	array<Card, 52> deck;

	// We could initialize each card individually, but that would be a pain.  Let's use a loop.
	int card = 0;
	for (int suit = 0; suit < MAX_SUITS; ++suit)
		for (int rank = 0; rank < MAX_RANK; ++rank)
		{
			deck[card].suit = static_cast<CardSuit>(suit);
			deck[card].rank = static_cast<CardRank>(rank);
			++card;
		}

	printDeck(deck);

	shuffleDeck(deck);

	printDeck(deck);

	if (playBlackJack(deck))
		cout << "You win! \n";
	else
		cout << "You lose! \n";

    return 0;
}

