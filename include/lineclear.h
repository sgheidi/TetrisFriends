#ifndef LINECLEAR_H
#define LINECLEAR_H

class _LineClear_ {

	public:
		void ClearLine(int row);
		bool IsRowFull(int row);
		void BringLinesDown(int y, int NumLines);
		void LineClear();
};

extern _LineClear_ LineClearer;

#endif // LINECLEAR_H
