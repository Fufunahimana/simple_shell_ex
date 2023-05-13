#include "main.h"

/**
* add_newNode - function that  adds a separator found at the end
* of a sep_list.
* @head: head of the linked list.
* @sep: separator found (; | &).
* Return: address of the head.
*/
linkList *add_newNode(linkList **head, char sep)
{
linkList *new, *temp;

new = malloc(sizeof(linkList));
if (new == NULL)
return (NULL);

new->separator = sep;
new->next = NULL;
temp = *head;

if (temp == NULL)
{
*head = new;
}
else
{
while (temp->next != NULL)
temp = temp->next;
temp->next = new;
}

return (*head);
}

/**
* free_linkList - function that frees a sep_list
* @head: head of the linked list.
* Return: no return.
*/
void free_linkList(linkList **head)
{
linkList *temp;
linkList *curr;

if (head != NULL)
{
curr = *head;
while ((temp = curr) != NULL)
{
curr = curr->next;
free(temp);
}
*head = NULL;
}
}

/**
* add_line_lineNewNode - function that  adds a command line at the end
* of a line_list.
* @head: head of the linked list.
* @line: command line.
* Return: address of the head.
*/
newList *add_lineNewNode(newList **head, char *line)
{
newList *new, *temp;

new = malloc(sizeof(newList));
if (new == NULL)
return (NULL);

new->line = line;
new->next = NULL;
temp = *head;

if (temp == NULL)
{
*head = new;
}
else
{
while (temp->next != NULL)
temp = temp->next;
temp->next = new;
}
return (*head);
}

/**
* free_newList -function that  frees a line_list
* @head: head of the linked list.
* Return: no return.
*/
void free_newList(newList **head)
{
newList *temp;
newList *curr;

if (head != NULL)
{
curr = *head;
while ((temp = curr) != NULL)
{
curr = curr->next;
free(temp);
}
*head = NULL;
}
}
