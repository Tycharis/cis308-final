#ifndef TYPES_H
#define TYPES_H

typedef enum Operator {
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE,
    MODULUS,
    LN,
    LOG
} Operator;

typedef struct Token {
    int value;
    Operator operation;
} Token;

typedef struct SyntaxTree {
    Token value;
    struct SyntaxTree left;
    struct SyntaxTree right;
} SyntaxTree;

#endif
