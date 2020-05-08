#include "Player.h"
#include <time.h>

Player::Player(Dealer* dealer) : m_dealer(dealer) {

}

void Player::startRound() {
	std::vector<Card> startingHand = m_dealer->drawCards(2);
	m_hand.insert(m_hand.end(), startingHand.begin(), startingHand.end());
}

void Player::hit() {
	if (!busted()) {
		m_hand.push_back(m_dealer->drawCard());
	}
}

void Player::split() {
	if (Card::splittable(m_hand)) {
		// implement splits
	}
}

bool Player::busted() {
	int sum = 0;
	for (int i = 0; i < m_hand.size(); i++) {
		sum += m_hand[i].getValue();
	}
	return (sum > 21);
}

std::vector<Card> Player::getHand() {
	return m_hand;
}
