#pragma once
#include <SDL_rect.h>
#include <vector>

class Card {
public:
	Card(char suit, int value);

	int getValue();

	static bool splittable(std::vector<Card> pair);

	SDL_Rect getClip();
private:
	// H for hearts, D for diamonds, S for spades, C for clubs
	char m_suit;

	// Note: C14 is red back and S14 is blue back
	// 11 for jack, 12 for queen, 13 for king, 1 for ace
	int m_value;

};

