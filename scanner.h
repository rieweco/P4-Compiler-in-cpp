#ifndef SCANNER_H
#define SCANNER_H

#include <string>
#include <map>
#include "token.h"

extern const std::string SUPPORTED_ALPHABET;

const int QUANTITY_TOKENS = 27;

extern const int FSA_TABLE_ROW_INDEX_END_OF_FILE;
extern const int FSA_TABLE_ROW_INDEX_IDENTIFIER;
extern const int FSA_TABLE_ROW_INDEX_INTEGER;
extern const int FSA_TABLE_ROW_INDEX_OPERATOR_ASSIGN;
extern const int FSA_TABLE_ROW_INDEX_OPERATOR_LESS_THAN;
extern const int FSA_TABLE_ROW_INDEX_OPERATOR_GREATER_THAN;
extern const int FSA_TABLE_ROW_INDEX_OPERATOR_EQUAL_TO;
extern const int FSA_TABLE_ROW_INDEX_OPERATOR_COLON;
extern const int FSA_TABLE_ROW_INDEX_OPERATOR_ADDITION;
extern const int FSA_TABLE_ROW_INDEX_OPERATOR_SUBTRACTION;
extern const int FSA_TABLE_ROW_INDEX_OPERATOR_MULTIPLICATION;
extern const int FSA_TABLE_ROW_INDEX_OPERATOR_DIVISION;
extern const int FSA_TABLE_ROW_INDEX_OPERATOR_MODULO;
extern const int FSA_TABLE_ROW_INDEX_OPERATOR_CONCATENATION;
extern const int FSA_TABLE_ROW_INDEX_DELIMITER_LEFT_PARENTHESIS;
extern const int FSA_TABLE_ROW_INDEX_DELIMITER_RIGHT_PARENTHESIS;
extern const int FSA_TABLE_ROW_INDEX_DELIMITER_LEFT_CURLY_BRACE;
extern const int FSA_TABLE_ROW_INDEX_DELIMITER_RIGHT_CURLY_BRACE;
extern const int FSA_TABLE_ROW_INDEX_DELIMITER_LEFT_SQUARE_BRACKET;
extern const int FSA_TABLE_ROW_INDEX_DELIMITER_RIGHT_SQUARE_BRACKET;
extern const int FSA_TABLE_ROW_INDEX_DELIMITER_COMMA;
extern const int FSA_TABLE_ROW_INDEX_DELIMITER_SEMICOLON;

extern const std::map<const TOKEN_IDENTIFIER, const int> TOKEN_IDENTIFIER_TO_FSA_TABLE_ROW_INDEX_MAP;

const int QUANTITY_CHARACTER_CLASSES = 24;

extern const int FSA_TABLE_COLUMN_INDEX_END_OF_FILE;
extern const int FSA_TABLE_COLUMN_INDEX_WHITE_SPACE;
extern const int FSA_TABLE_COLUMN_INDEX_LETTER;
extern const int FSA_TABLE_COLUMN_INDEX_DECIMAL;
extern const int FSA_TABLE_COLUMN_INDEX_EQUAL;
extern const int FSA_TABLE_COLUMN_INDEX_LESS_THAN;
extern const int FSA_TABLE_COLUMN_INDEX_GREATER_THAN;
extern const int FSA_TABLE_COLUMN_INDEX_COLON;
extern const int FSA_TABLE_COLUMN_INDEX_PLUS;
extern const int FSA_TABLE_COLUMN_INDEX_MINUS;
extern const int FSA_TABLE_COLUMN_INDEX_ASTERISK;
extern const int FSA_TABLE_COLUMN_INDEX_FORWARD_SLASH;
extern const int FSA_TABLE_COLUMN_INDEX_PERCENT;
extern const int FSA_TABLE_COLUMN_INDEX_PERIOD;
extern const int FSA_TABLE_COLUMN_INDEX_LEFT_PARENTHESIS;
extern const int FSA_TABLE_COLUMN_INDEX_RIGHT_PARENTHESIS;
extern const int FSA_TABLE_COLUMN_INDEX_LEFT_CURLY_BRACE;
extern const int FSA_TABLE_COLUMN_INDEX_RIGHT_CURLY_BRACE;
extern const int FSA_TABLE_COLUMN_INDEX_LEFT_SQUARE_BRACKET;
extern const int FSA_TABLE_COLUMN_INDEX_RIGHT_SQUARE_BRACKET;
extern const int FSA_TABLE_COLUMN_INDEX_COMMA;
extern const int FSA_TABLE_COLUMN_INDEX_SEMICOLON;

extern const std::map<const char, const int> CHARACTER_TO_FSA_TABLE_COLUMN_INDEX_MAP;

extern const int FINAL_STATE_END_OF_FILE;
extern const int FINAL_STATE_IDENTIFIER;
extern const int FINAL_STATE_INTEGER;
extern const int FINAL_STATE_OPERATOR_EQUALS;
extern const int FINAL_STATE_OPERATOR_LESS_THAN;
extern const int FINAL_STATE_OPERATOR_GREATER_THAN;
extern const int FINAL_STATE_OPERATOR_COLON;
extern const int FINAL_STATE_OPERATOR_PLUS;
extern const int FINAL_STATE_OPERATOR_MINUS;
extern const int FINAL_STATE_OPERATOR_ASTERISK;
extern const int FINAL_STATE_OPERATOR_FORWARD_SLASH;
extern const int FINAL_STATE_OPERATOR_PERCENT;
extern const int FINAL_STATE_OPERATOR_PERIOD;
extern const int FINAL_STATE_DELIMITER_LEFT_PARENTHESIS;
extern const int FINAL_STATE_DELIMITER_RIGHT_PARENTHESIS;
extern const int FINAL_STATE_DELIMITER_LEFT_CURLY_BRACE;
extern const int FINAL_STATE_DELIMITER_RIGHT_CURLY_BRACE;
extern const int FINAL_STATE_DELIMITER_LEFT_SQUARE_BRACKET;
extern const int FINAL_STATE_DELIMITER_RIGHT_SQUARE_BRACKET;
extern const int FINAL_STATE_DELIMITER_COMMA;
extern const int FINAL_STATE_DELIMITER_SEMICOLON;

extern const int INITIAL_STATE;
extern const int INTERMEDIATE_STATE_IDENTIFIER;
extern const int INTERMEDIATE_STATE_INTEGER;
extern const int INTERMEDIATE_STATE_OPERATOR_EQUALS;
extern const int INTERMEDIATE_STATE_OPERATOR_LESS_THAN;
extern const int INTERMEDIATE_STATE_OPERATOR_GREATER_THAN;
extern const int INTERMEDIATE_STATE_OPERATOR_COLON;
extern const int INTERMEDIATE_STATE_OPERATOR_PLUS;
extern const int INTERMEDIATE_STATE_OPERATOR_MINUS;
extern const int INTERMEDIATE_STATE_OPERATOR_ASTERISK;
extern const int INTERMEDIATE_STATE_OPERATOR_FORWARD_SLASH;
extern const int INTERMEDIATE_STATE_OPERATOR_PERCENT;
extern const int INTERMEDIATE_STATE_OPERATOR_PERIOD;
extern const int INTERMEDIATE_STATE_DELIMITER_LEFT_PARENTHESIS;
extern const int INTERMEDIATE_STATE_DELIMITER_RIGHT_PARENTHESIS;
extern const int INTERMEDIATE_STATE_DELIMITER_LEFT_CURLY_BRACE;
extern const int INTERMEDIATE_STATE_DELIMITER_RIGHT_CURLY_BRACE;
extern const int INTERMEDIATE_STATE_DELIMITER_LEFT_SQUARE_BRACKET;
extern const int INTERMEDIATE_STATE_DELIMITER_RIGHT_SQUARE_BRACKET;
extern const int INTERMEDIATE_STATE_DELIMITER_COMMA;
extern const int INTERMEDIATE_STATE_DELIMITER_SEMICOLON;

extern const int FSA_TABLE[QUANTITY_TOKENS][QUANTITY_CHARACTER_CLASSES];

extern const std::map<const int, const TOKEN_IDENTIFIER> STATE_TO_TOKEN_IDENTIFIER_MAP;

class Scanner {
private:
    std::string rawData;
    int currentIndex;
    int currentLineNumber;
    bool commentMode = false;
public:
    Scanner(const std::string rawData);

    ~Scanner();

    const std::string &getRawData() const;

    int getCurrentIndex() const;

    void setCurrentIndex(int currentIndex);

    int getCurrentLineNumber() const;

    void setCurrentLineNumber(int currentLineNumber);

    bool isCommentMode() const;

    void setCommentMode(bool commentMode);

    Token *getNextToken();

    const int newLinesBeforeNextToken();

    const bool nextCharacterIsNotTokenCharacter(const char nextChar) const;
};

#endif
