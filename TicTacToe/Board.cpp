#include "Board.h"
#include <stdio.h>

Board::Board() {
	board = new Piece*[BOARD_SIZE];
	for (int i = 0; i < BOARD_SIZE; i++) {
		board[i] = new Piece[BOARD_SIZE];
		for (int j = 0; j < BOARD_SIZE; j++) {
			board[i][j] = Piece::NONE;
		}
	}
}

Board::~Board() {
	for (int i = 0; i < BOARD_SIZE; i++) {
		delete[] board[i];
	}
	delete[] board;
}

bool Board::move(Piece p, int x, int y) {
	if (board[x][y] != Piece::NONE) {
		return false;
	} else {
		board[x][y] = p;
		return true;
	}
}

Piece Board::getPiece(int x, int y) {
	return board[x][y];
}

// Returns NONE if no one has won yet, otherwise returns the piece that won
Piece Board::checkWin() {
	// Check horizontal
	for (int i = 0; i < BOARD_SIZE; i++) {
		if (board[i][0] != Piece::NONE && board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
			return board[i][0];
		}
	}

	// Check vertical
	for (int i = 0; i < BOARD_SIZE; i++) {
		if (board[0][i] != Piece::NONE && board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
			return board[0][i];
		}
	}

	// Check diagonals
	if (board[0][0] != Piece::NONE && board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
		return board[0][0];
	}
	if (board[0][2] != Piece::NONE && board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
		return board[0][2];
	}

	return Piece::NONE;
}

void Board::reset() {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			board[i][j] = Piece::NONE;
		}
	}
}

bool Board::isFull() {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (board[i][j] == Piece::NONE) {
				return false;
			}
		}
	}
	return true;
}
