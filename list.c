#include "shell.h"

/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: pointer to pointer to the head node
 * @str: string to store in the node
 * @num: the number/id for the node
 * Return: pointer to the new node
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
	list_t *new_node, *node;

	if (!head)
		return (NULL);

	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);

	new_node->str = strdup(str);
	if (!new_node->str)
	{
		free(new_node);
		return (NULL);
	}
	new_node->num = num;
	new_node->next = NULL;

	if (*head == NULL)
		*head = new_node;
	else
	{
		node = *head;
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	return (new_node);
}

