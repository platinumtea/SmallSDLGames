#include "Dealer.h"
#include <time.h>

Dealer::Dealer() {
	srand(time(NULL));
	for (int i = 0; i < NUMBER_OF_DECKS; i++) {
		for (int j = 1; j <= 13; j++) {
			deck.push_back(Card('C', j));
			deck.push_back(Card('S', j));
			deck.push_back(Card('H', j));
			deck.push_back(Card('D', j));
		}
	}
}

Card Dealer::drawCard() {
	int card = rand() % (deck.size() - 1);
	Card temp = deck[card];

	deck.erase(deck.begin() + card);
	return temp;
}

std::vector<Card> Dealer::drawCards(int num) {
	std::vector<Card> cards;
	while (num--) {
		cards.push_back(drawCard());
	}
	return cards;
}

