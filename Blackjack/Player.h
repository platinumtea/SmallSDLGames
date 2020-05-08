#pragma once
#include "Card.h"
#include "Dealer.h"
#include <vector>

class Player {
public:
	Player(Dealer* dealer);
	void startRound();

	void hit();
	void split();

	bool busted();

	std::vector<Card> getHand();
private:
	Dealer* m_dealer;
	std::vector<Card> m_hand;
};

