#ifndef BOARD_H
#define BOARD_H

class Board {
private:
	void Horizontal(int startX, int endX, int startY, int endY);
	void Vertical(int startX, int endX, int startY, int endY);
public:
	int InQueue = 0;
	int SwitchCount = 0;
	void Test();
	void DrawGrid();
	void RenderBlocks_Board();
	void RenderBlocks_Hold();
	void RenderBlocks_Next();
	void Init();
	void ResetUnits();
	void SwitchTetronimo();
};

extern Board GameBoard;

#endif // BOARD_H
