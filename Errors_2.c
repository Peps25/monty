#include "monty.h"


int short_stack_error(unsigned int line_number, char *op);
int div_error(unsigned int line_number);
int pop_error(unsigned int line_number);
int div_error(unsigned int line_number);
int pchar_error(unsigned int line_number, char *message);


/**
 * pop_error - will print pop err messages for empty stacks
 * @line_number: line no. in script where err occured
 *
 * Return: (EXIT_FAILURE) always
 */
int pop_error(unsigned int line_number)
{
    fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
    return (EXIT_FAILURE);
}


/**
 * pint_error - will print pint err messages for empty stacks
 * @line_number: line no. in Monty bytecodes file where err occurred
 *
 * Return: (EXIT_FAILURE) always
 */
int pint_error(unsigned int line_number)
{
    fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
    return (EXIT_FAILURE);
}


/**
 * short_stack_error - will print monty math function err messages
 *                     for stacks or queues smaller than 2 nodes
 * @line_number: line no. in Monty bytecodes file where err occurred.
 * @op: op where the err occurred
 *
 * Return: (EXIT_FAILURE) always
 */
int short_stack_error(unsigned int line_number, char *op)
{
    fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
    return (EXIT_FAILURE);
}


/**
 * div_error - will print division err messages for division by 0
 * @line_number: line number in Monty bytecodes file where err occurred
 *
 * Return: (EXIT_FAILURE) always
 */
int div_error(unsigned int line_number)
{
    fprintf(stderr, "L%u: division by zero\n", line_number);
    return (EXIT_FAILURE);
}


/**
 * pchar_error - will print pchar err messages for empty stacks
 *               empty stacks and non-char values.
 * @line_number: line number in Monty bytecodes file where error occurred.
 * @message: corresponding err message to print.
 *
 * Return: (EXIT_FAILURE) always
 */
int pchar_error(unsigned int line_number, char *message)
{
    fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
    return (EXIT_FAILURE);
}
