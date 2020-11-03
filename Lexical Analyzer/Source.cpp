#include "SymbolTable.h"

#define	TOTAL_ASCII	128

void removeSpaces(string&);
void initilaizeArray(int[], int, int);
void printArr(int[], int);
void readKeywordsinSymbolTable(string, SymbolTable&);
void readAsciiToIntIndexMappingArray(string, int[]);

// Driver code
int main()
{
	//SymbolTable table;

	//readKeywordsinSymbolTable("keywords.csv", table);
	//table.print();

	int mapArr[TOTAL_ASCII];
	initilaizeArray(mapArr, TOTAL_ASCII, -1);

	readAsciiToIntIndexMappingArray("mapping.txt", mapArr);
	printArr(mapArr, TOTAL_ASCII);



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

void initilaizeArray(int arr[], int size, int value)
{
	for (int i = 0; i < size; i++)
		arr[i] = value;
}

void printArr(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << "Index: " << i
		<< ",\tValue: " << arr[i] << endl;

	cout << endl;
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

	fin.close();
}

void readAsciiToIntIndexMappingArray(string filename, int mapArr[])
{
	char c; int index, size;

	ifstream fin(filename);
	fin >> size;

	for (int i = 0; i < size; i++)
	{
		fin >> c >> index;

		if (c == 'L')		// letter
		{
			for (int j = 65; j <= 90; j++)
				mapArr[j] = index;

			for (int k = 97; k <= 122; k++)
				mapArr[k] = index;
		}

		else if (c == 'D')	// digit
		{
			for (int l = 48; l <= 57; l++)
				mapArr[l] = index;
		}

		else
			mapArr[int(c)] = index;
	}

	fin.close();
}