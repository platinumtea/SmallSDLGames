#pragma once

enum class Piece {
	NONE, X, O
};

class Board {
public:
	Board();
	~Board();
	bool move(Piece p, int x, int y);
	Piece getPiece(int x, int y);
	Piece checkWin();
	void reset();
	bool isFull();
private:
	const int BOARD_SIZE = 3;
	Piece** board;
};
