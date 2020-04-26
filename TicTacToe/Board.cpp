#include "Board.h"
#include <stdio.h>

Board::Board() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			boardStatus[i][j] = Piece::NONE;
		}
	}
}

bool Board::move(Piece p, int x, int y) {
	if (boardStatus[x][y] != Piece::NONE) {
		return false;
	} else {
		boardStatus[x][y] = p;
		printf("[%d][%d]\n", x, y);
		//printBoard();
		return true;
	}
}

Piece Board::getPiece(int x, int y) {
	return boardStatus[x][y];
}

// Returns NONE if no one has won yet, otherwise returns the piece that won
Piece Board::checkWin() {
	// Check horizontal
	for (int i = 0; i < 3; i++) {
		if (boardStatus[i][0] != Piece::NONE && boardStatus[i][0] == boardStatus[i][1] && boardStatus[i][0] == boardStatus[i][2]) {
			return boardStatus[i][0];
		}
	}

	// Check vertical
	for (int i = 0; i < 3; i++) {
		if (boardStatus[0][i] != Piece::NONE && boardStatus[0][i] == boardStatus[1][i] && boardStatus[0][i] == boardStatus[2][i]) {
			return boardStatus[0][i];
		}
	}

	// Check diagonals
	if (boardStatus[0][0] != Piece::NONE && boardStatus[0][0] == boardStatus[1][1] && boardStatus[0][0] == boardStatus[2][2]) {
		return boardStatus[0][0];
	}
	if (boardStatus[0][2] != Piece::NONE && boardStatus[0][2] == boardStatus[1][1] && boardStatus[0][2] == boardStatus[2][0]) {
		return boardStatus[0][2];
	}

	return Piece::NONE;
}

void Board::reset() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			boardStatus[i][j] = Piece::NONE;
		}
	}
}

bool Board::isFull() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (boardStatus[i][j] == Piece::NONE) {
				return false;
			}
		}
	}
	return true;
}

void Board::printBoard() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (boardStatus[i][j] == Piece::X) {
				printf(" X ");
			} else if (boardStatus[i][j] == Piece::O) {
				printf(" O ");
			} else {
				printf(" . ");
			}
		}
		printf("\n");
	}
}
