#include "SymbolTable.h"
#include <fstream>

void removeSpaces(string&);
void readKeywordsinSymbolTable(string, SymbolTable&);

// Driver code
int main()
{
	SymbolTable table;

	readKeywordsinSymbolTable("keywords.csv", table);
	table.print();


	return 0;
}

void removeSpaces(string &str)
{
	int i = 0, j = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			str[j++] = str[i];
		i++;
	}
	str[j] = '\0';
}

void readKeywordsinSymbolTable(string filename, SymbolTable &table)
{
	ifstream fin(filename);
	string keyword;

	while (! fin.eof())
	{
		getline(fin, keyword, ',');
		removeSpaces(keyword);
		table.insert(keyword, "keyword");
	}
}