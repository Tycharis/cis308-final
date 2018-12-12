/* core.c
 * Braedon Smith
 * Created 13 November 2018
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "lexer.h"
#include "parser.h"
#include "types.h"

double evaluate(SyntaxTree * tree)
{
    if (tree == NULL)
    {
        return -1.0;
    }

    switch(tree->value->type)
    {
        case ADD:
            return evaluate(tree->left) + evaluate(tree->right);
        case SUBTRACT:
            return evaluate(tree->left) - evaluate(tree->right);
        case MULTIPLY:
            return evaluate(tree->left) * evaluate(tree->right);
        case DIVIDE:
            return evaluate(tree->left) / evaluate(tree->right);
        case LN:
            return log(tree->left->value->value);
        case LOG:
            return log10(tree->left->value->value);
        case DOUBLE:
            return tree->left->value->value;
        default:
            break;
    }

    return -1.0;
}

void print_usage()
{
    printf("Load GUI:        ./main");
    printf("Evaluate string: ./main <input>");
    printf("Load from file:  ./main < <file>");
}

int main(int argc, char * argv[]) {
    if (argc == 1)
    {
        //TODO GUI
    }
    else if (argv[1] == "<")
    {
        FILE * input = fopen(argv[2], "r");
        char * str;
        double answer;

        while (fgets(str, -1, input) != NULL)
        {
            double answer = evaluate(parse_list(lex(str)));
            answer != -1.0 ? printf("%f\n", answer) : printf("Syntax error");
        }
    }
    else if (argv[1] != NULL)
    {
        double answer = evaluate(parse_list(lex(argv[1])));
        answer != -1.0 ? printf("%f", answer) : printf("Syntax error");
    }
    else
    {
        print_usage();
    }

    return 0;
}
