#include "SymbolTable.h"

int main()
{
	SymbolTable table;

	table.insert("while", "keyword");
	table.insert("if", "keyword");
	table.insert("else", "keyword");
	table.insert("for", "keyword");

	table.print();

	return 0;
}