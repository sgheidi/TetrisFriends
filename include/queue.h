#ifndef QUEUE_H
#define QUEUE_H

class _queue_ {
private:
	void ClearNextColors();
public:
	void Init();
	void ServeNext();
	void SetTestRand();
	void UpdateNextColors();
	void PrintQueue();
};

extern _queue_ Queue;

#endif // QUEUE_H
