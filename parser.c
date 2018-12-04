#include "types.h"

SyntaxTree parse(LinkedList * tokens, SyntaxTree * tree)
{
    if (tokens == NULL || tree == NULL)
    {
        return NULL;
    }

    while (tokens != NULL)
    {
        //TODO

        tokens = tokens->next;
    }
}
