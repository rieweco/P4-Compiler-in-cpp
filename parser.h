#ifndef PARSER_H
#define PARSER_H

#include "token.h"
#include "scanner.h"
#include "node.h"

using namespace std;

class Parser {
private:
    	string rawData;
    	Scanner *scanner;
public:
    	explicit Parser(string &rawData);

    	~Parser();
    
	string &getRawData();
    	Node *parse();
    	void setRawData(string &rawData);
	//<BNF> functions
    	Node *parse_program(int level);
   	Node *parse_block(int level);
    	Node *parse_vars(int level);
    	Node *parse_mvars(int level);
    	Node *parse_expr(int level);
    	Node *parse_M(int level);
    	Node *parse_R(int level);
    	Node *parse_stats(int level);
    	Node *parse_mStat(int level);
    	Node *parse_stat(int level);
    	Node *parse_in(int level);
    	Node *parse_out(int level);
    	Node *parse_if(int level);
    	Node *parse_loop(int level);
    	Node *parse_assign(int level);
    	Node *parse_RO(int level);
    
	//error and consume functions
	void reportError(TOKEN_IDENTIFIER expectedToken, ...);
	TOKEN_IDENTIFIER currentToken();
    	Node *consumeTerminal(Node *node);
    	Node *consumeNonTerminal(Node *originalNode, Node *nonTerminalNode);
};

#endif
