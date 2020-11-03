#pragma once
#include "Node.h"

class TransitionTable
{
	int** table, row, col;

public:
	TransitionTable();
	TransitionTable(int, int);

	~TransitionTable();

	void readTableFromFile(string);
};

