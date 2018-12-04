/* core.c
 * Braedon Smith, Brandon Taylor
 * Created 13 November 2018
 */

#include <math.h>

int main(int argc, const char * argv[]) {
    return 0;
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
