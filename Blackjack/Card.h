#pragma once
class Card {
public:
	Card(char suit, int value);
private:
	// H for hearts, D for diamonds, S for spades, C for clubs
	char m_suit;
	// 11 for jack, 12 for queen, 13 for king, 1 for ace
	int m_value;
};

