#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


char **op_toks = NULL;


/**
 * main - entry point for Monty Interpreter
 *
 * @argc: number of arguments passed to the program
 * @argv: Pointer to an array of character pointers to args
 *
 * Return: (EXIT_SUCCESS) if successful, (EXIT_FAILURE) otherwise
 */
int main(int argc, char **argv)
{
    FILE *script_fd = NULL;
    int exit_code = EXIT_SUCCESS;


    if (argc != 2)
        return (usage_error());
    script_fd = fopen(argv[1], "r");
    if (script_fd == NULL)
        return (f_open_error(argv[1]));
    exit_code = run_monty(script_fd);
    fclose(script_fd);
    return (exit_code);
}
