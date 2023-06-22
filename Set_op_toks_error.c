#include "monty.h"


/**
 * set_op_tok_error - will set last element of op_toks to be an err code.
 * @error_code: int to store as a str in op_toks.
 */
void set_op_tok_error(int error_code)
{
    int toks_len = 0, ui = 0;
    char *exit_str = NULL;
    char **new_toks = NULL;


    toks_len = token_arr_len();
    new_toks = malloc(sizeof(char *) * (toks_len + 2));
    if (!op_toks)
    {
        malloc_error();
        return;
    }
    while (ui < toks_len)
    {
        new_toks[ui] = op_toks[ui];
        ui++;
    }
    exit_str = get_int(error_code);
    if (!exit_str)
    {
        free(new_toks);
        malloc_error();
        return;
    }
    new_toks[ui++] = exit_str;
    new_toks[ui] = NULL;
    free(op_toks);
    op_toks = new_toks;
}
