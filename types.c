#include <stdlib.h>

#include "types.h"

void free_tree(SyntaxTree * tree)
{
    if (tree == NULL)
    {
        return;
    }

    free_tree(tree->left);
    free_tree(tree->right);

    free(tree->value);
    free(tree);
}

LinkedList * append(LinkedList * list, Token * token)
{
    LinkedList * new_list = malloc(sizeof(LinkedList));
    new_list->token = token;

    list->next = new_list;

    return list;
}

LinkedList * advance(LinkedList * list, int increment)
{
    for (int i = 0; i < increment; i++)
    {
        list = list->next;
    }

    return list;
}

void free_list(LinkedList * list)
{
    if (list == NULL)
    {
        return;
    }

    free_list(list->next);

    free(list->token);
    free(list);
}
