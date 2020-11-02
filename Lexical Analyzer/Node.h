#pragma once
#include <string>
#include <iostream>
using namespace std;

class Node
{
	string identifier, type;
	Node* next;

public:
	Node();
	Node::Node(string, string);

	~Node();

	void print() const;

	friend class SymbolTable;
};

