#include "semantics.h"

using namespace std;
	
//class semantics
Semantics::Semantics(int stackCount) : stackCount(stackCount) {
}

Semantics::~Semantics() = default;

//function to get stack size
int Semantics::getStackCount() {
	return stackCount;
}

//function to set flag value
void Semantics::setFlag(int flag) {
	if (flag == 0) {
		globalFlag = 0;
	}
	else if (flag == 1) {
		globalFlag = 1;	
	}
	else {
		exit(1);
	}
}

//function to get flag value
int Semantics::getFlag() {
	return globalFlag;
}
 

//getter function: vector for getting variables not needed for semantics
vector<string> *Semantics::getVars() {
	return varsNotNeeded;
}


//getter function: vector for getting variables needed for semantics
vector<string> *Semantics::getNeededVars() {
	return varsNeeded;
}

//setter function: add var to varsNotNeeded Vector
void Semantics::setVarsNotNeeded(vector<string> *varsNotNeeded) {
	Semantics::varsNotNeeded = varsNotNeeded;
}

//setter function: add var to varsNeeded vector
void Semantics::setVarsNeeded(vector<string> *varsNeeded) {
	Semantics::varsNeeded = varsNeeded;
}

//toString to print vectors
string Semantics::toString() {
	string myToString = to_string(stackCount);
	myToString = myToString + "\n";
	
	int i;
	for(i = 0; i < varsNeeded->size(); i++)	{
		myToString = myToString + "var: " + varsNeeded->at(i) + ": " + varsNotNeeded->at(i);
		myToString = myToString + "\n";
	}
	
	return myToString;
}
