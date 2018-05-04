//checkSem.cpp file
#include <string>
#include "checkSem.h"

using namespace std;

CheckSem::CheckSem(Node *tree) : tree(tree) {
	//push_back() to function like a stack
	semantics->push_back(new Semantics(0));
}

//main function to check semantics of tree
string CheckSem::checkit() {
	string codeGen = runOnNode(tree);
	codeGen += "STOP\n";
	codeGen += nextBlockCode();
	codeGen += addTemps();
	
	cout << "checkSem complete. No Errors found!" << endl;
	
	//return code string for tree
	return codeGen;
}

string CheckSem::runOnNode(Node *node) {
	string codeGen;

	//check if node is nonterminal
	if(node->isNonTerminal()) {
		//add child nodes of non terminal to vector
		vector<Node *> &children = node->getChildren();
		if (node->getKeyword() == "program") {
			if (children.size() == 2) {
				//recursive call to add children to codeGen string
				codeGen += runOnNode(children.at(0));
				codeGen += runOnNode(children.at(1));
				cout << "program code: " << codeGen << endl;
			}
			
		}
		//check block node's children
		else if (node->getKeyword() == "block") {
			//set new semantics stack
			semantics->push_back(new Semantics(semantics->size()));
			//recursion on left node then right node
			codeGen += runOnNode(children.at(1));
			codeGen += runOnNode(children.at(2));
			//test cout to show whats in block node
			//cout << "block code: " << codeGen << endl;
			
			//pop semantics stack
			semantics->pop_back();
		}
		//check vars node children
		else if (node->getKeyword() == "vars") {
			if (children.empty()) {
				//empty node, do nothing
				//test cout to show whats in vars node
				//cout << "vars code: " << codeGen << endl;
			}
			else if (children.size() == 5) {
				if ( isVarUnique(children.at(1)->getValue())) {
					//add Identifier to stack
					vector<string> *vars = semantics->at(semantics->size() - 1)->getNeededVars();
					vars->push_back(children.at(1)->getValue());
					semantics->at(semantics->size() - 1)->setVarsNeeded(vars);
					//add Integer to stack
					vector<string> *temps = semantics->at(semantics->size() - 1)->getVars();
					temps->push_back(createTempNumber());
					semantics->at(semantics->size() - 1)->setVarsNotNeeded(temps);
					
				}
				else {
					cout << "checkSem Error: Var: " << children.at(1)->getValue() << " is already on the Stack!" << endl;
					exit(1);
				}
				
				if(findVar(children.at(1)->getValue())) {
					variables->push_back(children.at(1)->getValue());
				}
	
				//recursive call
				codeGen += runOnNode(children.at(4));
				//test cout to show whats in vars node
				//cout << "vars code: " << codeGen << endl;
			}
		}

		//check mvars
		else if (node->getKeyword() == "mvars") {
			if (children.size() == 1) {
				//do nothing
				//test cout to show whats in mvars node
				//cout << "mvars code: " << codeGen << endl;
			}
			else if(children.size() == 3) {
				if (isVarUnique(children.at(1)->getValue())) {
					//add Identifier to stack
					vector<string> *vars = semantics->at(semantics->size() - 1)->getNeededVars();
					vars->push_back(children.at(1)->getValue());
					semantics->at(semantics->size() - 1)->setVarsNeeded(vars);
					
					//add integer to stack
					vector<string> *temps = semantics->at(semantics->size() - 1)->getVars();
					temps->push_back(createTempNumber());
					semantics->at(semantics->size() - 1)->setVarsNotNeeded(temps);
					
				}
				else {
					cout << "checkSem Error: Var: " << children.at(1)->getValue() << " is already on the Stack!" << endl;
					exit(1);
				}
				if (findVar(children.at(1)->getValue())) {
					variables->push_back(children.at(1)->getValue());
				}
		
				//recursive call
				codeGen += runOnNode(children.at(2));
				//test cout to show whats in mvars node
				//cout << "mvars code: " << codeGen << endl;
			}
		}

		//expr
		else if (node->getKeyword() == "expr") {
			if (children.size() == 1) {
				//recursive call
				codeGen += runOnNode(children.at(0));
			}
			else if (children.size() == 3) {
				if (children.at(1)->getValue() == "+") {
					codeGen += runOnNode(children.at(0));
					string tempID = createTempNumber();
					codeGen += "STORE ";
					codeGen += tempID;
					codeGen += "\n";
					codeGen += runOnNode(children.at(2));
					codeGen += "ADD ";
					codeGen += tempID;
					codeGen += "\n";
					//test cout to show whats in expr node
					//cout << "expr code: " << codeGen << endl;
				}
				else if (children.at(1)->getValue() == "-") {
					codeGen += runOnNode(children.at(2));
                                        string tempID = createTempNumber();
                                        codeGen += "STORE ";
                                        codeGen += tempID;
                                        codeGen += "\n";
                                        codeGen += runOnNode(children.at(0));
                                        codeGen += "SUB ";
                                        codeGen += tempID;
                                        codeGen += "\n";
					//test cout to show whats in expr node
					//cout << "expr code: " << codeGen << endl;
				}
				else if (children.at(1)->getValue() == "/") {
					codeGen += runOnNode(children.at(2));
                                        string tempID = createTempNumber();
                                        codeGen += "STORE ";
                                        codeGen += tempID;
                                        codeGen += "\n";
                                        codeGen += runOnNode(children.at(0));
                                        codeGen += "DIV ";
                                        codeGen += tempID;
                                        codeGen += "\n";
					//test cout to show whats in expr node
					//cout << "expr code: " << codeGen << endl;

				}
				else if (children.at(1)->getValue() == "*") {
					codeGen += runOnNode(children.at(0));
                                        string tempID = createTempNumber();
                                        codeGen += "STORE ";
                                        codeGen += tempID;
                                        codeGen += "\n";
                                        codeGen += runOnNode(children.at(2));
                                        codeGen += "MULT ";
                                        codeGen += tempID;
                                        codeGen += "\n";
					//test cout to show whats in expr node
					//cout << "expr code: " << codeGen << endl;
				}
			}
		}
		
		//check M
		else if (node->getKeyword() == "M") {
			if (children.size() == 1) {
				codeGen += runOnNode(children.at(0));
				//test cout to show whats in M node
				//cout << "M code: " << codeGen << endl;
			}
			else if (children.size() == 2) {
				codeGen += runOnNode(children.at(1));
                                codeGen += "MULT ";
                                codeGen += "-1";
                        	codeGen += "\n";
				//test cout to show whats in M node
				//cout << "M code: " << codeGen << endl;
			}
		}
		
		//check R
		else if (node->getKeyword() == "R") {
			if (children.size() == 3) {
				codeGen += runOnNode(children.at(1));
			}
			else if (children.size() == 1) {
				if (isalpha(children.at(0)->getValue()[0])) {
					codeGen += "LOAD ";
					string varID = getTempVarName(children.at(0)->getValue());
					codeGen += varID;
					codeGen += "\n";
					//test cout to show whats in R node
					//cout << "R code: " << codeGen << endl;
				}
				else if (isdigit(children.at(0)->getValue()[0])) {
					string number = children.at(0)->getValue();
					codeGen += "LOAD ";
					codeGen += number;
					codeGen += "\n";
					//test cout to show whats in R node
					//cout << "R code: " << codeGen << endl;
				}
			}
			else {
				cout << "checkSem Error: Var: " << children.at(0) << " is already found in Stack!" << endl;
				exit(1);
			}
		}

		//check stats
		else if (node->getKeyword() == "stats") {
			//recursive call
			codeGen += runOnNode(children.at(0));
			codeGen += runOnNode(children.at(1));
			//test cout to show whats in stats node
			//cout << "stats code: " << codeGen << endl;
		}

		//check mStat
		else if (node->getKeyword() == "mStat") {
			if (children.size() == 0) {
				//do nothing
				//test cout to show whats in mStat node
				//cout << "mStat code: " << codeGen << endl;
			}
			else if (children.size() == 2) {
				//recursive call
				codeGen += runOnNode(children.at(0));
				codeGen += runOnNode(children.at(1));
				//test cout to show whats in mStat node
				//cout << "mStat code: " << codeGen << endl;
			}
		}
	
		//check stat
		else if (node->getKeyword() == "stat") {
			if (children.size() == 1 && children.at(0)->getValue() == "in") {
				codeGen += runOnNode(children.at(0));
				//test cout to show whats in stat node
				//cout << "stat code: " << codeGen << endl;
			}
			else if (children.size() == 1 && children.at(0)->getValue() == "out") {
				codeGen += runOnNode(children.at(0));
				//test cout to show whats in stat node
				//cout << "stat code: " << codeGen << endl;
			}
			else if (children.size() == 1 && children.at(0)->getValue() == "block") {
				codeGen += runOnNode(children.at(0));
				//test cout to show whats in stat node
				//cout << "stat code: " << codeGen << endl;
			}
			else if (children.size() == 1 && children.at(0)->getValue() == "if") {
				codeGen += runOnNode(children.at(0));
				//test cout to show whats in stat node
				//cout << "stat code: " << codeGen << endl;
			}
			else if (children.size() == 1 && children.at(0)->getValue() == "loop") {
				codeGen += runOnNode(children.at(0));
				//test cout to show whats in stat node
				//cout << "stat code: " << codeGen << endl;
			}
			else if (children.size() == 1 && children.at(0)->getValue() == "assign") {
				codeGen += runOnNode(children.at(0));
				//test cout to show whats in stat node
				//cout << "stat code: " << codeGen << endl;
			}
			else {
				cout << "checkSem Error: Var: " << children.at(0) << " is not allowed for <stat>!" << endl;
			}
		}
		
		//check in
		else if (node->getKeyword() == "in") {
			string varID = getTempVarName(children.at(1)->getValue());
			codeGen += "READ ";
			codeGen += varID;
			codeGen += "\n";
			//test cout to show whats in in node
			//cout << "in code: " << codeGen << endl;
		}
		
		//check out
		else if (node->getKeyword() == "out") {
			if (children.size() == 3) {
				codeGen += runOnNode(children.at(1));
				string tempID = createTempNumber();
				codeGen += "STORE ";
				codeGen += tempID;
				codeGen += "\n";
				codeGen += "WRITE ";
				codeGen += tempID;
				codeGen += "\n";
				//test cout to show whats in out node
				//cout << "out code: " << codeGen << endl;
			}
		}
		
		//check if
		else if (node->getKeyword() == "if") {
			if(children.size() == 7) {
				string tempLabel = createTempLabel();
				codeGen += "BR ";
				codeGen += tempLabel;
				codeGen += "\n";
				string nextTempLabel = createTempLabel();
				string tempID = createTempNumber();
				string childrenCodeGen = tempLabel + ": NOOP\n";
				childrenCodeGen += runOnNode(children.at(4));
				childrenCodeGen += "STORE ";
				childrenCodeGen += tempID;
				childrenCodeGen += "\n";
				childrenCodeGen += runOnNode(children.at(2));
				childrenCodeGen += "SUB ";
				childrenCodeGen += tempID;
				childrenCodeGen += "\n";
				childrenCodeGen += runOnNode(children.at(3));
				childrenCodeGen += " ";
				childrenCodeGen += nextTempLabel;
				childrenCodeGen += "\n";
				childrenCodeGen += runOnNode(children.at(6));
				childrenCodeGen += "BR ";
				childrenCodeGen += nextTempLabel;
				childrenCodeGen += "\n";
				
				//add childrenCodeGen to class string pointer 
				loopCodeGen->push_back(childrenCodeGen);
				codeGen += "STOP\n";
				codeGen += nextTempLabel;
				codeGen += ": NOOP\n";
				//test cout to show whats in if node
				//cout << "if code: " << codeGen << endl;
			}
		}
		
		//check loop
		else if (node->getKeyword() == "loop") {
			if(children.size() == 7) {
				string tempLabel = createTempLabel();
                                codeGen += "BR ";
                                codeGen += tempLabel;
                                codeGen += "\n";
                                string nextTempLabel = createTempLabel();
                                string tempID = createTempNumber();
                                string childrenCodeGen = tempLabel + ": NOOP\n";
                                childrenCodeGen += runOnNode(children.at(4));
                                childrenCodeGen += "STORE ";
                                childrenCodeGen += tempID;
                                childrenCodeGen += "\n";
                                childrenCodeGen += runOnNode(children.at(2));
                                childrenCodeGen += "SUB ";
                                childrenCodeGen += tempID;
                                childrenCodeGen += "\n";
                                childrenCodeGen += runOnNode(children.at(3));
                                childrenCodeGen += " ";
                                childrenCodeGen += nextTempLabel;
                                childrenCodeGen += "\n";
                                childrenCodeGen += runOnNode(children.at(6));
                                childrenCodeGen += "BR ";
                                childrenCodeGen += tempLabel;
                                childrenCodeGen += "\n";
				
				//add childrenCodeGen to class string pointer
				loopCodeGen->push_back(childrenCodeGen);
                                codeGen += "STOP\n";
                                codeGen += nextTempLabel;
                                codeGen += ": NOOP\n";
				//test cout to show whats in loop node
				//cout << "loop code: " << codeGen << endl;
			}
		}
		
		//check assign
		else if (node->getKeyword() == "assign") {
			if(children.size() == 5) {
				codeGen += runOnNode(children.at(3));
				codeGen += "STORE ";
				string varID = getTempVarName(children.at(1)->getValue());
				codeGen += varID;
				codeGen += "\n";
				//test cout to show whats in assign
				//cout << "assign code: " << codeGen << endl;
			}
		}

		//check RO
		else if (node->getKeyword() == "RO") {
			if (children.size() == 1) {
				if (children.at(0)->getValue() == "<") {
					codeGen += "BRZPOS";
				}
				else if (children.at(0)->getValue() == "<<") {
					codeGen += "BRPOS";
				}
				else if (children.at(0)->getValue() == ">") {
					codeGen += "BRZNEG";
				}
				else if (children.at(0)->getValue() == ">>") {
					codeGen += "BRNEG";
				}
				else if (children.at(0)->getValue() == "=") {
					codeGen += "BRZERO";
				}
				else if (children.at(0)->getValue() == "==") {
					string tempID = createTempNumber();
					codeGen += "STORE ";
					codeGen += tempID;
					codeGen += "\n";
					codeGen += "MULT ";
					codeGen += tempID;
					codeGen += "\n";
					codeGen += "BRPOS";
				}
			//test cout to show whats in R0
			//	cout << "R0 code: " << codeGen << endl;
			}
			else {
				cout << "semCheck error! <RO> had invalid value! \n";
			}
		}
	}
		
	return codeGen;
}
		
			
//function to check if var is in scope
bool CheckSem::isVarUnique(string &var) {
	int i;
	for (i = 0; i < semantics->at(semantics->size() - 1)->getNeededVars()->size(); i++) {
		if (var == semantics->at(semantics->size() - 1)->getNeededVars()->at(i)) {
			return false;
		}
	}
	return true;			
}

//function to see if var is already active
bool CheckSem::findVar(string &name) {
	int i;
	for (i = 0; i < variables->size(); i++) {
		if(name == variables->at(i)) {
			return false;
		}
	}
	return true;		
}

//function to get the var name from semantics vector
string CheckSem::getTempVarName(string &name) {
	string tempName;
	bool exists = false;
	int index = semantics->size() - 1;
	
	//check semantics vector for current scope
	int i;
	while (index >= 0 && !exists) {
		for (i = 0; i < semantics->at(index)->getNeededVars()->size(); i++) {
			//test cout to show the temp vars being added
			//cout << "new getTempVarName[" << i << "]: " << semantics->at(index)->getNeededVars()->at(i) << endl;
			if(semantics->at(index)->getNeededVars()->at(i) == name) {
				exists = true;
				tempName = semantics->at(index)->getVars()->at(i);
			}
		}
		index--;	
	}
	if (exists) {
		return tempName;
	}	
	else {
		cout << "ERROR: " << name << " found in program but does NOT exists as a defined var!" << endl;
		exit(1);	
	}
}


//function to add all the temp vars to the end of the codeGen string
string CheckSem::addTemps() {
	string tempCode;
	int i;
	for (i = 0; i < numIDs; i++) {
		tempCode += "T";
		string num = to_string(i);
		tempCode += num;
		tempCode += " 0";
		tempCode += "\n";
	}
	
	return tempCode;
}


//funciton to add all code from <block>
string CheckSem::nextBlockCode() {
	string blockCode;
	//loop through loopCodeGen pointer 
	for (string &loopCode : *loopCodeGen) {
		blockCode += loopCode;
		blockCode += "STOP\n";
	}
	
	return blockCode;
}


//function to assign and increment numLabels
string CheckSem::createTempLabel() {
	string num = to_string(numLabels++);
	string label = "L";
	label += num;
	
	return label;
}

//function to assign and increment tempIDs
string CheckSem::createTempNumber() {
	string num = to_string(numIDs++);
	string id = "T";
	id += num;

	return id;
}














