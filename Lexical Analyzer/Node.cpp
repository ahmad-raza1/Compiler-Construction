#include "Node.h"

Node::Node()
{
	this->next = nullptr;
}

Node::Node(string identifier, string type)
{
	this->identifier = identifier;
	this->type = type;
	this->next = nullptr;
}

Node::~Node()
{
	delete this->next;
	this->next = nullptr;
}

void Node::print() const
{
	cout << "Identifier's Name: " << this->identifier << endl
		<< "Type: " << this->type << endl;
}