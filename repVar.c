#include "main.h"

/**
* checkEnv - That function  checks if the
* typed variable is an env variable
* @linh: head of linked list
* @str: input string
* @data: data structure
* Return: no return
*/
void checkEnv(newVar **linh, char *str, data_shell *data)
{
int row, chr, p, lval;
char **envr;

envr = data->_environ;
for (row = 0; envr[row]; row++)
{
for (p = 1, chr = 0; envr[row][chr]; chr++)
{
if (envr[row][chr] == '=')
{
lval =  stringLen(envr[row] + chr + 1);
add_rvar_node(linh, p, envr[row] + chr + 1, lval);
return;
}

if (str[p] == envr[row][chr])p++;
else
break;
}
}

for (p = 0; str[p]; p++)
{
if (str[p] == ' ' || str[p] == '\t' || str[p] == ';' || str[p] == '\n')
break;
}

add_rvar_node(linh, p, NULL, 0);
}

/**
* checkVars -That  function checks
* if the typed variable is $$ or $?
* @linh: head of the linked list
* @str: input string
* @st: last status of the Shell
* @data: data structure
* Return: no return
*/
int checkVars(newVar **linh, char *str, char *st, data_shell *data)
{
int a, b, c;

b =  stringLen(st);
c= stringLen(data->pid);

for (a = 0; str[a]; a++)
{
if (str[a] == '$')
{
if (str[a + 1] == '?')
add_rvar_node(linh, 2, st, b), a++;
else if (str[a + 1] == '$')
add_rvar_node(linh, 2, data->pid, c), a++;
else if (str[a + 1] == '\n')
add_rvar_node(linh, 0, NULL, 0);
else if (str[a + 1] == '\0')
add_rvar_node(linh, 0, NULL, 0);
else if (str[a + 1] == ' ')
add_rvar_node(linh, 0, NULL, 0);
else if (str[a + 1] == '\t')
add_rvar_node(linh, 0, NULL, 0);
else if (str[a + 1] == ';')
add_rvar_node(linh, 0, NULL, 0);
else
checkEnv(linh, str + a, data);
}
}

return (a);
}

/**
* repInput - That function  replaces string into variables
*
* @head: head of the linked list
* in: input string
* @ni: new input string (replaced)
* @nl: new length
* Return: replaced string
*/
char *repInput(newVar **head, char *in, char *ni, int nl)
{
newVar *index;
int a, b, c;

index = *head;
for (b = a = 0; a< nl; a++)
{
if (in[b] == '$')
{
if (!(index->len_var) && !(index->len_val))
{
ni[a] = in[b];
b++;
}
else if (index->len_var && !(index->len_val))
{
for (c = 0; c < index->len_var; c++)
b++;
a--;
}
else
{
for (c = 0; c < index->len_val; c++)
{
ni[a] = index->val[c];
a++;
}
b += (index->len_var);
a--;
}
index = index->next;
}
else
{
ni[a] = in[b];
b++;
}
}

return (ni);
}

/**
* repVar - calls functions to replace string into vars
*
* @in: input string
* @mydata: data structure
* Return: replaced string
*/
char *repVar(char *in, data_shell *mydata)
{
newVar *head, *index;
char *status, *ni;
int olen, nl;

status = aux_itoa(mydata->status);
head = NULL;

olen = checkVars(&head, in, status, mydata);

if (head == NULL)
{
free(status);
return (in);
}

index = head;
nl = 0;

while (index != NULL)
{
nl += (index->len_val - index->len_var);
index = index->next;
}

nl += olen;

ni = malloc(sizeof(char) * (nl + 1));
ni[nl] = '\0';

ni = repInput(&head, in, ni, nl);

free(in);
free(status);
free_rvar_list(&head);

return (ni);
}
