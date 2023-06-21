#include "monty.h"
/**
 * addnode - will add node to head stack
 * @head: head of the stack
 * @i: the new_value
 * Return: no return
*/
void addnode(stack_t **head, int i)
{

	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (aux)
		aux->prev = new_node;
	new_node->i = i;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}
