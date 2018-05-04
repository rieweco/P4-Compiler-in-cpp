#ifndef CHECKSEM_H
#define CHECKSEM_H

#include "node.h"
#include "semantics.h"

using namespace std;

class CheckSem {
private:
	Node *tree;
	vector<string> *variables = new vector<string>();
	vector<Semantics *> *semantics = new vector<Semantics *>();
	int numIDs = 0;
	int numLabels = 0;
	vector<string> *loopCodeGen = new vector<string>();
public:
	CheckSem(Node *tree);
	~CheckSem();
	string createTempNumber();
	string createTempLabel();	
	string runOnNode(Node *node);
	string nextBlockCode();
	string addTemps();
	string getTempVarName(string &name);
	bool findVar(string &name);	
	string checkit();	
	bool isVarUnique(string &var);
};




#endif
