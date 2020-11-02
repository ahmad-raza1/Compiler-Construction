#include "SymbolTable.h"

SymbolTable::SymbolTable()
{
	this->count = 0;

	for (int i = 0; i < MAX; i++)
		this->head[i] = nullptr;
}

SymbolTable::~SymbolTable()
{
	for (int i = 0; i < this->count; i++)
	{
		delete this->head[i];
		this->head[i] = nullptr;
	}
}

int SymbolTable::hashFunction(string id)
{
	int len = id.length(), asciiSum = 0;

	for (int i = 0; i < len; i++)
		asciiSum += id[i];

	return (asciiSum % 100);
}

bool SymbolTable::insert(string id, string type)
{
	int index = hashFunction(id);
	Node* p = new Node(id, type);

	if (this->head[index] == nullptr)
	{
		this->head[index] = p;
		//cout << id << " inserted" << endl;
		count++;
		return true;
	}

	else
	{
		Node* start = this->head[index];

		while (start->next != nullptr)
			start = start->next;

		start->next = p;
		//cout << id << " inserted" << endl;
		count++;
		return true;
	}

	return false;
}

bool SymbolTable::modify(string id, string type)
{
	int index = hashFunction(id);
	Node* start = this->head[index];

	if (! start)
		return "-1";

	while (start != nullptr)
	{
		if (start->identifier == id)
		{
			start->type = type;
			return true;
		}

		start = start->next;
	}

	return false;
}

bool SymbolTable::deleteEntry(string id)
{
	int index = hashFunction(id);
	Node* node = this->head[index];
	Node* prev = this->head[index];

	// no identifier is present at that index
	if (node == nullptr)
		return false;

	/// only one identifier is present
	if (node->identifier == id && node->next == nullptr)
	{
		node->next = nullptr;
		delete node;
		count--;
		return true;
	}

	while (node->identifier != id && node->next != nullptr)
	{
		prev = node;
		node = node->next;
	}

	// delete in the middle
	if (node->identifier == id && node->next != nullptr)
	{
		prev->next = node->next;
		node->next = nullptr;
		delete node;
		count--;
		return true;
	}

	// delete at the end
	else
	{
		prev->next = nullptr;
		node->next = nullptr;
		delete node;
		count--;
		return true;
	}

	return false;
}

Node* SymbolTable::find(string id)
{
	int index = hashFunction(id);
	Node* start = this->head[index];

	if (start == nullptr)
		return nullptr;

	while (start != nullptr)
	{
		if (start->identifier == id)
		{
			start->print();
			return start;
		}

		start = start->next;
	}

	return nullptr;
}

void SymbolTable::print()
{
	cout << "Total Entries: "
		<< this->count << endl << endl;

	Node* start; int index;
	for (int i = 0; i < MAX; i++)
	{
		if (this->head[i])
		{
			index = hashFunction(this->head[i]->identifier);
			cout << "Index: " << index << endl;

			start = this->head[i];

			while (start != nullptr)
			{
				start->print();
				start = start->next;
			}
			cout << endl;
		}
	}
}