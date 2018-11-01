#include "node.h"

Node::Node() {
	data = 0;
	next = 0;
}

Node::Node(int x) {
	data = x;
	next = 0;
}

Node::Node(int x, Node* node) {
	data = x;
	next = node;
}

Node::~Node() {
}

int Node::getData() {
	return data;
}

Node* Node::getNext() {
	return next;
}

void Node::setNext(Node* node) {
	next = node;
}