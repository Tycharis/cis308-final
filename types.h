#ifndef TYPES_H
#define TYPES_H

typedef enum
{
    FALSE,
    TRUE
} bool;

typedef struct Token
{
    int value;

    enum
    {
        ADD,
        SUBTRACT,
        MULTIPLY,
        DIVIDE,
        MODULUS,
        LN,
        LOG,
        INTEGER
    } type;
} Token;

typedef struct SyntaxTree
{
    Token value;
    struct SyntaxTree * left;
    struct SyntaxTree * right;
} SyntaxTree;

void free_tree(SyntaxTree *);

typedef struct LinkedList
{
    Token * value;
    struct LinkedList * next;
} LinkedList;

LinkedList * append(LinkedList *, Token *);
LinkedList * advance(LinkedList *, int);
void free_list(LinkedList * list);

#endif
