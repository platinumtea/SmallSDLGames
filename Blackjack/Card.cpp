#include "Card.h"

Card::Card(char suit, int value) : m_suit(suit), m_value(value) {

}

int Card::getValue() {
	return m_value;
}

bool Card::splittable(std::vector<Card> pair) {
	if (pair.size() == 2) {
		if (pair[0].m_value == pair[1].m_value) {
			return true;
		}
	}
	return false;
}

SDL_Rect Card::getClip() {
	const int width = 71, height = 96;
	int x, y;
	switch (m_suit) {
	case 'C':
		y = 0;
		break;
	case 'S':
		y = 96;
		break;
	case 'H':
		y = 192;
		break;
	case 'D':
		y = 288;
		break;
	default:
		y = 0;
	}
	x = (m_value - 1) * 72;

	SDL_Rect rect = { x, y, width, height };
	return rect;
}
