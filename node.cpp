#include "node.h"

using namespace std;

Node::Node(string value, bool nonTerminal, int level, string keyword) : 
	value(value),
        nonTerminal(nonTerminal),
        level(level),
	keyword(keyword) {
}

Node::~Node() = default;

int Node::getLevel() {
    return level;
}

string &Node::getValue() {
    return value;
}

bool Node::isNonTerminal() {
    return nonTerminal;
}

vector<Node *> &Node::getChildren() {
    return children;
}

void Node::setChildren(vector<Node *> &children) {
    Node::children = children;
}

string Node::getKeyword() {
	return keyword;
}

string Node::toString() {
    string output;

    output = output + toStringMe();
    output = output + toStringChildren();

    return output;
}

string Node::toStringMe() {
    string spaces = "   ";
    string output;

    for (int i = 0; i < getLevel(); i++) {
        output += spaces + spaces;
    }

    if (nonTerminal) {
        output += "<" + value + ">\n";
    } else {
        output += value + "\n";
    }

    return output;
}

string Node::toStringChildren() {
    string output = "";

    for (Node *node : getChildren()) {
        output += node->toString();
    }

    return output;
}
