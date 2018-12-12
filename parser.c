#include <stdlib.h>

#include "lexer.h"
#include "types.h"

int parse(SyntaxTree * tree, LinkedList * tokens)
{
    if (tokens == NULL || tree == NULL)
    {
        return -1;
    }

    int count = 0;
    int temp;

    switch(tokens->token->type)
    {
        case ADD:
        case SUBTRACT:
        case MULTIPLY:
        case DIVIDE:
            tree->value = copy_token(tokens->token);
            count++;

            tree->left = malloc(sizeof(SyntaxTree *));
            temp = parse(tree->left, advance(tokens, count));

            if (temp != -1)
            {
                count += temp;
            }

            tree->right = malloc(sizeof(SyntaxTree *));
            temp = parse(tree->right, advance(tokens, count));

            if (temp != -1)
            {
                count += temp;
            }

            break;
        case LN:
        case LOG:
            tree->value = copy_token(tokens->token);
            count++;

            tree->left = malloc(sizeof(SyntaxTree *));
            temp += parse(tree->left, advance(tokens, count));

            if (temp != -1)
            {
                count += temp;
            }

            tree->right = NULL;

            break;
        case DOUBLE:
            tree->value = copy_token(tokens->token);
            tree->left = NULL;
            tree->right = NULL;

            count++;

            break;
    }

    return count;
}

SyntaxTree * parse_list(LinkedList * list)
{
    SyntaxTree * tree = malloc(sizeof(SyntaxTree *));
    parse(tree, list);

    return tree;
}
