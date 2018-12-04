/* core.c
 * Braedon Smith, Brandon Taylor
 * Created 13 November 2018
 */

#include <math.h>
#include <stdio.h>

int main(int argc, const char * argv[]) {
    if (argc == 1)
    {
        //TODO GUI
    }
    else if (argv[1] == "<")
    {
        //TODO scan file in argv[2]
    }
    else if (argv[1] != NULL)
    {
        //TODO scan string in argv[1]
    }
    else
    {
        print_usage();
        return 0;
    }
}

int evaluate(SyntaxTree * tree)
{
    if (tree == NULL)
    {
        return NULL;
    }

    switch(tree->token)
    {
        case ADD:
            return evaluate(tree->left) + evaluate(tree->right);
        case SUBTRACT:
            return evaluate(tree->left) - evaluate(tree->right);
        case MULTIPLY:
            return evaluate(tree->left) * evaluate(tree->right);
        case DIVIDE:
            return evaluate(tree->left) / evaluate(tree->right);
        case MODULUS:
            return evaluate(tree->left) % evaluate(tree->right);
        case LN:
            return log(tree->left);
        case LOG:
            return log10(tree->left);
        case INTEGER:
            return tree->left->value;
        default:
            break;
    }

    return NULL;
}

void print_usage()
{
    printf("Load GUI:        ./main");
    printf("Evaluate string: ./main <input>");
    printf("Load from file:  ./main < <file>")
}
