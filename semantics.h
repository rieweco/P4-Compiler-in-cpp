//semantics.h
#ifndef SEMANTICS_H
#define SEMANTICS_H

#include <string>
#include <vector>
	
using namespace std;

class Semantics {
private:
	int stackCount;
	int globalFlag;
	vector<string> *varsNotNeeded = new vector<string>();
	vector<string> *varsNeeded = new vector<string>();
public:
	Semantics(int stackCount);
	~Semantics();
	
	//getters and setters
	int getStackCount();
	int getFlag();
	void setFlag(int flag);
	vector<string> *getVars();
	vector<string> *getNeededVars();
	void setVarsNotNeeded(vector<string> *varsNotNeeded);
	void setVarsNeeded(vector<string> *varsNeeded);
	
	//toString
	string toString();

};


#endif
