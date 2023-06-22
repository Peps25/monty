#include "monty.h"
#include <string.h>


void free_tokens(void);
unsigned int token_arr_len(void);
int is_empty_line(char *line, char *delims);
void (*get_op_func(char *opcode))(stack_t**, unsigned int);
int run_monty(FILE *script_fd);


/**
 * free_tokens - will free the global op_toks array of strings.
 */
void free_tokens(void)
{
    size_t ui = 0;


    if (op_toks == NULL)
        return;


    for (ui = 0; op_toks[ui]; ui++)
        free(op_toks[ui]);


    free(op_toks);
}


/**
 * token_arr_len - will get the length of current op_toks
 *
 * Return: len of current op_toks (as int)
 */
unsigned int token_arr_len(void)
{
    unsigned int toks_len = 0;


    while (op_toks[toks_len])
        toks_len++;
    return (toks_len);
}


/**
 * is_empty_line - will check if a line read from getline only has delimiters
 * @line: Pointer to the line
 * @delims: str of delimiter chars
 *
 * Return: 1 if there are delimiters,
 *         0 otherwise
 */
int is_empty_line(char *line, char *delims)
{
    int ui, j;


    for (ui = 0; line[ui]; ui++)
    {
        for (j = 0; delims[j]; j++)
        {
            if (line[ui] == delims[j])
                break;
        }
        if (delims[j] == '\0')
            return (0);
    }


    return (1);
}


/**
 * get_op_func - will match an opcode with its corresponding func
 * @opcode: Opcode to be matched
 *
 * Return: Pointer to the corresponding func
 */
void (*get_op_func(char *opcode))(stack_t**, unsigned int)
{
    instruction_t op_funcs[] = {
        {"push", monty_push},
        {"pall", monty_pall},
        {"pint", monty_pint},
        {"pop", monty_pop},
        {"swap", monty_swap},
        {"add", monty_add},
        {"nop", monty_nop},
        {"sub", monty_sub},
        {"div", monty_div},
        {"mul", monty_mul},
        {"mod", monty_mod},
        {"pchar", monty_pchar},
        {"pstr", monty_pstr},
        {"rotl", monty_rotl},
        {"rotr", monty_rotr},
        {"stack", monty_stack},
        {"queue", monty_queue},
        {NULL, NULL}
    };
    int ui;


    for (ui = 0; op_funcs[ui].opcode; ui++)
    {
        if (strcmp(opcode, op_funcs[i].opcode) == 0)
            return (op_funcs[ui].f);
    }


    return (NULL);
}


/**
 * run_monty - will primary function to execute a Monty bytecodes script.
 * @script_fd: file descriptor for an open Monty bytecodes script.
 *
 * Return: EXIT_SUCCESS if successful, err code on failure.
 */
int run_monty(FILE *script_fd)
{
    stack_t *stack = NULL;
    char *line = NULL;
    size_t len = 0, exit_status = EXIT_SUCCESS;
    unsigned int line_number = 0, prev_tok_len = 0;
    void (*op_func)(stack_t**, unsigned int);


    if (init_stack(&stack) == EXIT_FAILURE)
        return (EXIT_FAILURE);


    while (getline(&line, &len, script_fd) != -1)
    {
        line_number++;
        op_toks = strtow(line, DELIMS);
        if (op_toks == NULL)
        {
            if (is_empty_line(line, DELIMS))
                continue;
            free_stack(&stack);
            return (malloc_error());
        }
        else if (op_toks[0][0] == '#') /* comment line */
        {
            free_tokens();
            continue;
        }
        op_func = get_op_func(op_toks[0]);
        if (op_func == NULL)
        {
            free_stack(&stack);
            exit_status = unknown_op_error(op_toks[0], line_number);
            free_tokens();
            break;
        }
        prev_tok_len = token_arr_len();
        op_func(&stack, line_number);
        if (token_arr_len() != prev_tok_len)
        {
            if (op_toks && op_toks[prev_tok_len])
                exit_status = atoi(op_toks[prev_tok_len]);
            else
                exit_status = EXIT_FAILURE;
            free_tokens();
            break;
        }
        free_tokens();
    }
    free_stack(&stack);


    if (line && *line == 0)
    {
        free(line);
        return (malloc_error());
    }


    free(line);
    return (exit_status);
}
