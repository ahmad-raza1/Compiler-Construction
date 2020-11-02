#pragma once
#include "Node.h"

#define	MAX	500

class SymbolTable
{
	Node* head[MAX]; int count;
	int hashFunction(string);

public:
	SymbolTable();
	~SymbolTable();
	
	bool insert(string, string);
	bool modify(string, string);
	bool deleteEntry(string);
	Node* find(string);
	void print();
};

