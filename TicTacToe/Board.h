#pragma once
enum class Piece {
	NONE, X, O
};

class Board {
public:
	Board();
	bool move(Piece p, int x, int y);
	Piece getPiece(int x, int y);
	Piece checkWin();
	void reset();
	bool isFull();
private:
	void printBoard();
	Piece boardStatus[3][3];
};

