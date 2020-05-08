#pragma once
#include <vector>
#include "Card.h"

class Dealer {
public:
	Dealer();

	Card drawCard();

	std::vector<Card> drawCards(int num);

private:
	const unsigned short NUMBER_OF_DECKS = 1;
	std::vector<Card> deck;
};

