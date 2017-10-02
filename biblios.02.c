/* Biblios in C */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 87			// default number of cards in deck
#define NUMPLAYERS	2	// default number of players

struct Card
{
	int value;		// card colour value
	int gold;		// gold value
	int numDice;	// number of dice the card manipulates
	int mod;		// increase/decrease dice value
	char *colour;	// card colour associated with dice
};

void setUpDeck(struct Card deck[], int NumPlayers, int *deckPos);
void addGoldCards(struct Card deck[], int *deckPos, int numPlayers);
void addColourCards(struct Card deck[], int *deckPos);
void addDiceCards(struct Card deck[], int *deckPos);
void addCard(struct Card deck[], int *deckPos, char *colour, int value, int numDice, int mod, int numCards);
void shuffleDeck(struct Card deck[], int *deckPos);

int main(void)
{
	struct Card deck[SIZE] = { 0 };		// array of struct Cards to store the three types.

	int deckPos = 0;					// track deck position

	setUpDeck(deck, NUMPLAYERS, &deckPos);

	return 0;
}

// creates deck by adding gold, colour, and dice cards. Deck is shuffled and end of deck is assigned.
void setUpDeck(struct Card deck[], int numPlayers, int *deckPos)
{
	addGoldCards(deck, deckPos, numPlayers);
	addColourCards(deck, deckPos);
	addDiceCards(deck, deckPos);
	shuffleDeck(deck, deckPos);
}

// add gold cards to deck. Eleven cards of values 1, 2 and 3.
void addGoldCards(struct Card deck[], int *deckPos, int numPlayers)
{
	int i, j, numGold = 11;

	// set quantity of gold cards based on number of players.
	switch (numPlayers)
	{
	case 2:
		numGold = 9;
		break;

	case 3:
		numGold = 10;
		break;

	case 4:
		numGold = 11;
		break;
	}

	// put gold cards in deck, and update deck position.
	for (i = 1; i <= 3; i++)
	{
		for (j = 0; j < numGold; j++)
		{
			deck[*deckPos].gold = i;
			(*deckPos)++;
		}
	}
}

// add the five color/category cards to the deck, nine of each color
void addColourCards(struct Card deck[], int *deckPos)
{

	// add red cards, two 2s and seven 1s
	addCard(deck, deckPos, "red", 2, 0, 0, 2);
	addCard(deck, deckPos, "red", 1, 0, 0, 7);

	// add green cards, two 2s and seven 1s
	addCard(deck, deckPos, "green", 2, 0, 0, 2);
	addCard(deck, deckPos, "green", 1, 0, 0, 7);

	// add orange cards, two 2s and seven 1s
	addCard(deck, deckPos, "orange", 2, 0, 0, 2);
	addCard(deck, deckPos, "orange", 1, 0, 0, 7);

	// add blue cards, two 4s, three 3s, and four 2s
	addCard(deck, deckPos, "blue", 4, 0, 0, 2);
	addCard(deck, deckPos, "blue", 3, 0, 0, 3);
	addCard(deck, deckPos, "blue", 2, 0, 0, 4);

	// add brown cards, two 4s, three 3s, and four 2s
	addCard(deck, deckPos, "brown", 4, 0, 0, 2);
	addCard(deck, deckPos, "brown", 3, 0, 0, 3);
	addCard(deck, deckPos, "brown", 2, 0, 0, 4);
}

// add dice modifier cards
void addDiceCards(struct Card deck[], int *deckPos)
{
	addCard(deck, deckPos, "none", 0, 1, 1, 2);
	addCard(deck, deckPos, "none", 0, 1, -1, 2);
	addCard(deck, deckPos, "none", 0, 2, 1, 2);
	addCard(deck, deckPos, "none", 0, 2, -1, 2);
	addCard(deck, deckPos, "none", 0, 1, 3, 1);
}

// add card(s) to deck based on a specific colour, value, and dice attributes
void addCard(struct Card deck[], int *deckPos, char *colour, int value, int numDice, int mod, int numCards)
{
	int i;

	for (i = 0; i < numCards; i++)
	{
		deck[*deckPos].colour = colour;
		deck[*deckPos].value = value;
		deck[*deckPos].numDice = numDice;
		deck[*deckPos].mod = mod;
		(*deckPos)++;
	}
}

// shuffle deck
void shuffleDeck(struct Card deck[], int *deckPos)
{
	int i, randNum;
	struct Card temp;		// temporary variable used for swapping

	for (i = 0; i <= *deckPos; i++)
	{
		randNum = rand() % (*deckPos);

		temp = deck[i];

		deck[i] = deck[randNum];

		deck[randNum] = temp;
	}

}
