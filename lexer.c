#include <stdlib.h>
#include <string.h>

#include "types.h"

bool is_digit(char c)
{
    return (c <= '9' && c >= '0');
}

bool is_whitespace(char c)
{
    return (c == ' ' || c == '\n' || c == '\t');
}

Token * copy_token(Token * token)
{
    if (token == NULL)
    {
        return NULL;
    }

    Token * t = malloc(sizeof(Token));
    memcpy(t, token, sizeof(Token));

    return t;
}

Token * make_add_token()
{
    Token * t = malloc(sizeof(Token));
    t->type = ADD;

    return t;
}

Token * make_subtract_token()
{
    Token * t = malloc(sizeof(Token));
    t->type = SUBTRACT;

    return t;
}

Token * make_multiply_token()
{
    Token * t = malloc(sizeof(Token));
    t->type = MULTIPLY;

    return t;
}

Token * make_divide_token()
{
    Token * t = malloc(sizeof(Token));
    t->type = DIVIDE;

    return t;
}

Token * make_mod_token()
{
    Token * t = malloc(sizeof(Token));
    t->type = MODULUS;

    return t;
}

Token * make_int_token(int value)
{
    Token * t = malloc(sizeof(Token));
    t->type = INTEGER;
    t->value = value;

    return t;
}

Token * make_ln_token()
{
    Token * t = malloc(sizeof(Token));
    t->type = LN;

    return t;
}

Token * make_log_token()
{
    Token * t = malloc(sizeof(Token));
    t->type = LOG;

    return t;
}

Token * tokenize(char * str, int * characters_read)
{
    if (characters_read == NULL)
    {
        return NULL;
    }

    *characters_read = 0;

    if (str == NULL)
    {
        return NULL;
    }

    while (is_whitespace(*str))
    {
        (*characters_read)++;
        str++;
    }

    switch (str[0])
    {
        case '+':
            (*characters_read)++;
            return make_add_token();
        case '-':
            (*characters_read)++;
            return make_subtract_token();
        case '*':
            (*characters_read)++;
            return make_multiply_token();
        case '/':
            (*characters_read)++;
            return make_divide_token();
        case '%':
            (*characters_read)++;
            return make_mod_token();
        case 'l':
        case 'L':
            (*characters_read)++;

            if (str[1] == 'n' || str[1] == 'N')
            {
                (*characters_read)++;
                return make_ln_token();
            }
            else if ((str[1] == 'o' || str[1] == 'O') && (str[2] == 'g' || str[2] == 'G'))
            {
                (*characters_read)++;
                return make_log_token();
            }
        default:
            return NULL;
    }

    if (is_digit(str[0]))
    {
        int digits = 0;
        int count = 0;

        while (is_digit(str[count])) {
            digits++;
            count++;
        }

        *characters_read += digits;

        return make_int_token(atoi(str));
    }

    *characters_read = 0;

    return NULL;
}

LinkedList * lex(char * input)
{
    LinkedList * head = NULL;

    int read = 0;
    Token * token = tokenize(input, &read);

    while (token != NULL)
    {
        input += read;

        head = append(head, token);
        read = 0;
        token = tokenize(input, &read);
    }

    return head;
}
