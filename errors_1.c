#include "monty.h"

int f_open_error(char *filename);
int unknown_op_error(char *opcode, unsigned int line_number);
int no_int_error(unsigned int line_number);
int usage_error(void);
int malloc_error(void);


/**
 * usage_error - will print usage err messages
 *
 * Return: (EXIT_FAILURE) on success
 */
int usage_error(void)
{
    fprintf(stderr, "USAGE: monty file\n");
    return (EXIT_FAILURE);
}


/**
 * malloc_error - will print malloc err messages
 *
 * Return: (EXIT_FAILURE) on success
 */
int malloc_error(void)
{
    fprintf(stderr, "Error: malloc failed\n");
    return (EXIT_FAILURE);
}


/**
 * f_open_error - will print file opening err messages with file name
 * @filename: the name of the file that failed to open
 *
 * Return: (EXIT_FAILURE) on success
 */
int f_open_error(char *filename)
{
    fprintf(stderr, "Error: Can't open file %s\n", filename);
    return (EXIT_FAILURE);
}


/**
 * unknown_op_error - will print unknown instruction err messages
 * @opcode: opcode where the error occurred
 * @line_number: line number in Monty bytecodes file where the error occured
 *
 * Return: (EXIT_FAILURE) on success
 */
int unknown_op_error(char *opcode, unsigned int line_number)
{
    fprintf(stderr, "L%u: unknown instruction %s\n",
        line_number, opcode);
    return (EXIT_FAILURE);
}


/**
 * no_int_error - will print invalid monty_push arg err messages.
 * @line_number: line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) on success
 */
int no_int_error(unsigned int line_number)
{
    fprintf(stderr, "L%u: usage: push integer\n", line_number);
    return (EXIT_FAILURE);
}

