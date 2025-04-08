#include <stdio.h>
#include <ctype.h>

#define INT_LIT 10
#define IDENT 11
#define ASSIGN_OP 20
#define ADD_OP 21
#define SUB_OP 22
#define MULT_OP 23
#define DIV_OP 24
#define LEFT_PAREN 25
#define RIGHT_PAREN 26

char nextChar;
char lexeme[100];
int lexLen;
int nextToken;

// Function to get the next character
void getChar() {
    nextChar = getchar();
    if (nextChar == EOF) {
        nextToken = EOF;
    }
}

// Function to add a character to lexeme
void addChar() {
    if (lexLen < 98) {
        lexeme[lexLen++] = nextChar;
        lexeme[lexLen] = '\0';
    }
    else {
        printf("Error: Lexeme too long\n");
    }
}

// Function to classify the next token
int lookup(char ch) {
    switch (ch) {
    case '+': return ADD_OP;
    case '-': return SUB_OP;
    case '*': return MULT_OP;
    case '/': return DIV_OP;
    case '(': return LEFT_PAREN;
    case ')': return RIGHT_PAREN;
    case '=': return ASSIGN_OP;
    default: return -1;
    }
}

// Lexical analyzer function
int lex() {
    lexLen = 0;

    // Skip whitespace
    while (isspace(nextChar))
        getChar();

    if (isalpha(nextChar)) {
        addChar();
        getChar();
        nextToken = IDENT;
    }
    else if (isdigit(nextChar)) {
        addChar();
        getChar();
        nextToken = INT_LIT;
    }
    else {
        nextToken = lookup(nextChar);
        if (nextToken != -1) {
            addChar();
            getChar();
        }
        else {
            nextToken = EOF;
        }
    }

    printf("Next token is: %d, Next lexeme is %s\n", nextToken, lexeme);
    return nextToken;
}

// Main function
int main() {
    printf("Enter your expression: ");
    getChar();
    nextToken = 0;  // Initialize nextToken

    while (nextToken != EOF) {
        lex();
    }

    return 0;
}
