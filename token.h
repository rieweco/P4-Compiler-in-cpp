#ifndef TOKEN_H
#define TOKEN_H

#include <map>
#include <string>
#include "utility.h"

enum TOKEN_IDENTIFIER {
    	END_OF_FILE, 
    	IDENTIFIER,
    	INTEGER, 
    	KEYWORD_START, 
    	KEYWORD_STOP,
    	KEYWORD_IFF, 
    	KEYWORD_ITER, 
    	KEYWORD_VOID, 
    	KEYWORD_VAR, 
    	KEYWORD_RETURN, 
   	KEYWORD_READ, 
    	KEYWORD_PRINT, 
    	KEYWORD_PROGRAM, 
	KEYWORD_THEN,
	KEYWORD_LET,
    	OPERATOR_EQUALS, 
   	OPERATOR_LESS_THAN, 
   	OPERATOR_GREATER_THAN, 
    	OPERATOR_COLON, 
    	OPERATOR_PLUS, 
    	OPERATOR_MINUS, 
    	OPERATOR_ASTERISK, 
    	OPERATOR_FORWARD_SLASH, 
    	OPERATOR_AMPERSAND, 
    	OPERATOR_PERCENT, 
    	DELIMITER_PERIOD, 
    	DELIMITER_LEFT_PARENTHESIS, 
    	DELIMITER_RIGHT_PARENTHESIS, 
    	DELIMITER_LEFT_CURLY_BRACE, 
    	DELIMITER_RIGHT_CURLY_BRACE, 
    	DELIMITER_LEFT_SQUARE_BRACKET, 
    	DELIMITER_RIGHT_SQUARE_BRACKET, 
    	DELIMITER_COMMA, 
    	DELIMITER_SEMICOLON 
};

const std::string END_OF_FILE_TOKEN_NAME = "END_OF_FILE";
const std::string IDENTIFIER_TOKEN_NAME = "IDENTIFIER";
const std::string INTEGER_TOKEN_NAME = "INTEGER";
const std::string KEYWORD_START_TOKEN_NAME = "KEYWORD_START";
const std::string KEYWORD_STOP_TOKEN_NAME = "KEYWORD_STOP";
const std::string KEYWORD_IFF_TOKEN_NAME = "KEYWORD_IFF";
const std::string KEYWORD_ITER_TOKEN_NAME = "KEYWORD_ITER";
const std::string KEYWORD_VOID_TOKEN_NAME = "KEYWORD_VOID";
const std::string KEYWORD_VAR_TOKEN_NAME = "KEYWORD_VAR";
const std::string KEYWORD_RETURN_TOKEN_NAME = "KEYWORD_RETURN";
const std::string KEYWORD_READ_TOKEN_NAME = "KEYWORD_READ";
const std::string KEYWORD_PRINT_TOKEN_NAME = "KEYWORD_PRINT";
const std::string KEYWORD_PROGRAM_TOKEN_NAME = "KEYWORD_PROGRAM";
const std::string KEYWORD_LET_TOKEN_NAME = "KEYWORD_LET";
const std::string KEYWORD_THEN_TOKEN_NAME = "KEYWORD_THEN";
const std::string OPERATOR_EQUALS_TOKEN_NAME = "OPERATOR_EQUALS";
const std::string OPERATOR_LESS_THAN_TOKEN_NAME = "OPERATOR_LESS_THAN";
const std::string OPERATOR_GREATER_THAN_TOKEN_NAME = "OPERATOR_GREATER_THAN";
const std::string OPERATOR_COLON_TOKEN_NAME = "OPERATOR_COLON";
const std::string OPERATOR_PLUS_TOKEN_NAME = "OPERATOR_PLUS";
const std::string OPERATOR_MINUS_TOKEN_NAME = "OPERATOR_MINUS";
const std::string OPERATOR_ASTERISK_TOKEN_NAME = "OPERATOR_ASTERISK";
const std::string OPERATOR_FORWARD_SLASH_TOKEN_NAME = "OPERATOR_FORWARD_SLASH";
const std::string OPERATOR_AMPERSAND_TOKEN_NAME = "OPERATOR_AMPERSAND";
const std::string OPERATOR_PERCENT_TOKEN_NAME = "OPERATOR_PERCENT";
const std::string DELIMITER_PERIOD_TOKEN_NAME = "DELIMITER_PERIOD";
const std::string DELIMITER_LEFT_PARENTHESIS_TOKEN_NAME = "DELIMITER_LEFT_PARENTHESIS";
const std::string DELIMITER_RIGHT_PARENTHESIS_TOKEN_NAME = "DELIMITER_RIGHT_PARENTHESIS";
const std::string DELIMITER_LEFT_CURLY_BRACE_TOKEN_NAME = "DELIMITER_LEFT_CURLY_BRACE";
const std::string DELIMITER_RIGHT_CURLY_BRACE_TOKEN_NAME = "DELIMITER_RIGHT_CURLY_BRACE";
const std::string DELIMITER_LEFT_SQUARE_BRACKET_TOKEN_NAME = "DELIMITER_LEFT_SQUARE_BRACKET";
const std::string DELIMITER_RIGHT_SQUARE_BRACKET_TOKEN_NAME = "DELIMITER_RIGHT_SQUARE_BRACKET";
const std::string DELIMITER_COMMA_TOKEN_NAME = "DELIMITER_COMMA";
const std::string DELIMITER_SEMICOLON_TOKEN_NAME = "DELIMITER_SEMICOLON";

const std::map<const TOKEN_IDENTIFIER, const std::string> TOKEN_IDENTIFIER_TO_TOKEN_NAME_MAP = {
        {END_OF_FILE,                       	END_OF_FILE_TOKEN_NAME},
        {IDENTIFIER,                        	IDENTIFIER_TOKEN_NAME},
        {INTEGER,                           	INTEGER_TOKEN_NAME},
        {KEYWORD_START,                     	KEYWORD_START_TOKEN_NAME},
        {KEYWORD_STOP,                      	KEYWORD_STOP_TOKEN_NAME},
        {KEYWORD_IFF,                       	KEYWORD_IFF_TOKEN_NAME},
        {KEYWORD_ITER,                      	KEYWORD_ITER_TOKEN_NAME},
        {KEYWORD_VOID,                      	KEYWORD_VOID_TOKEN_NAME},
        {KEYWORD_VAR,                       	KEYWORD_VAR_TOKEN_NAME},
        {KEYWORD_RETURN,                    	KEYWORD_RETURN_TOKEN_NAME},
        {KEYWORD_READ,                      	KEYWORD_READ_TOKEN_NAME},
        {KEYWORD_PRINT,                     	KEYWORD_PRINT_TOKEN_NAME},
        {KEYWORD_PROGRAM,                   	KEYWORD_PROGRAM_TOKEN_NAME},
	{KEYWORD_THEN,			    	KEYWORD_THEN_TOKEN_NAME},
	{KEYWORD_LET,			   	KEYWORD_LET_TOKEN_NAME},
        {OPERATOR_EQUALS,                   	OPERATOR_EQUALS_TOKEN_NAME},
        {OPERATOR_LESS_THAN,                	OPERATOR_LESS_THAN_TOKEN_NAME},
        {OPERATOR_GREATER_THAN,             	OPERATOR_GREATER_THAN_TOKEN_NAME},
        {OPERATOR_COLON,                    	OPERATOR_COLON_TOKEN_NAME},
        {OPERATOR_PLUS,                     	OPERATOR_PLUS_TOKEN_NAME},
        {OPERATOR_MINUS,                    	OPERATOR_MINUS_TOKEN_NAME},
        {OPERATOR_ASTERISK,                 	OPERATOR_ASTERISK_TOKEN_NAME},
        {OPERATOR_FORWARD_SLASH,            	OPERATOR_FORWARD_SLASH_TOKEN_NAME},
        {OPERATOR_AMPERSAND,                	OPERATOR_AMPERSAND_TOKEN_NAME},
        {OPERATOR_PERCENT,                  	OPERATOR_PERCENT_TOKEN_NAME},
        {DELIMITER_PERIOD,                  	DELIMITER_PERIOD_TOKEN_NAME},
        {DELIMITER_LEFT_PARENTHESIS,        	DELIMITER_LEFT_PARENTHESIS_TOKEN_NAME},
        {DELIMITER_RIGHT_PARENTHESIS,      	DELIMITER_RIGHT_PARENTHESIS_TOKEN_NAME},
        {DELIMITER_LEFT_CURLY_BRACE,        	DELIMITER_LEFT_CURLY_BRACE_TOKEN_NAME},
        {DELIMITER_RIGHT_CURLY_BRACE,       	DELIMITER_RIGHT_CURLY_BRACE_TOKEN_NAME},
        {DELIMITER_LEFT_SQUARE_BRACKET,     	DELIMITER_LEFT_SQUARE_BRACKET_TOKEN_NAME},
        {DELIMITER_RIGHT_SQUARE_BRACKET,    	DELIMITER_RIGHT_SQUARE_BRACKET_TOKEN_NAME},
        {DELIMITER_COMMA,                   	DELIMITER_COMMA_TOKEN_NAME},
        {DELIMITER_SEMICOLON,               	DELIMITER_SEMICOLON_TOKEN_NAME}
};

const std::string KEYWORD_LITERAL_START = "start";
const std::string KEYWORD_LITERAL_STOP = "stop";
const std::string KEYWORD_LITERAL_IFF = "iff";
const std::string KEYWORD_LITERAL_ITER = "iter";
const std::string KEYWORD_LITERAL_VOID = "void";
const std::string KEYWORD_LITERAL_VAR = "var";
const std::string KEYWORD_LITERAL_RETURN = "return";
const std::string KEYWORD_LITERAL_READ = "read";
const std::string KEYWORD_LITERAL_PRINT = "print";
const std::string KEYWORD_LITERAL_PROGRAM = "program";
const std::string KEYWORD_LITERAL_THEN = "then";
const std::string KEYWORD_LITERAL_LET = "let";

const std::map<const std::string, const TOKEN_IDENTIFIER> KEYWORD_LITERAL_TO_KEYWORD_TOKEN_IDENTIFIER_MAP = {
        {KEYWORD_LITERAL_START,   	KEYWORD_START},
        {KEYWORD_LITERAL_STOP,     	KEYWORD_STOP},
        {KEYWORD_LITERAL_IFF,   	KEYWORD_IFF},
        {KEYWORD_LITERAL_ITER,    	KEYWORD_ITER},
        {KEYWORD_LITERAL_VOID,    	KEYWORD_VOID},
        {KEYWORD_LITERAL_VAR,     	KEYWORD_VAR},
        {KEYWORD_LITERAL_RETURN,  	KEYWORD_RETURN},
        {KEYWORD_LITERAL_READ,   	KEYWORD_READ},
        {KEYWORD_LITERAL_PRINT,  	KEYWORD_PRINT},
        {KEYWORD_LITERAL_PROGRAM,	KEYWORD_PROGRAM},
	{KEYWORD_LITERAL_THEN,		KEYWORD_THEN},
	{KEYWORD_LITERAL_LET,		KEYWORD_LET},
};

class Token {
private:
    const TOKEN_IDENTIFIER tokenIdentifier;
    const std::string value;
    const std::string lineNumber;
public:
    Token(const TOKEN_IDENTIFIER tokenIdentifier, const std::string value, const std::string lineNumber) : tokenIdentifier(tokenIdentifier),
                                                                                                           value(value),
                                                                                                           lineNumber(lineNumber) {
    };

    ~Token() = default;

    const TOKEN_IDENTIFIER getTokenIdentifier() const{
        return tokenIdentifier;
    }

    const std::string &getValue() const{
        return value;
    }

    const std::string &getLineNumber() const{
        return lineNumber;
    }

    const std::string toString() const{
        return "Line Number: \"" + getLineNumber() + "\", Token Identifier: \"" + TOKEN_IDENTIFIER_TO_TOKEN_NAME_MAP.at(getTokenIdentifier()) + "\", Token Value: \"" + trim(getValue()) + "\"";
    }
};


#endif
