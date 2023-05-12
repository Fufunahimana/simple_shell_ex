include "main.h"
#include <stddef.h>
#include <stdlib.h>

/**
* swapChar - That function  swaps | and & for non-printed chars
* @in: input string
* @bool: type of swap
* Return: swapped string
*/
char *swapChar(char *in, int bool)
{
int k;

if (bool == 0)
{
for (k = 0; in[k]; k++)
{
if (in[k] == '|')
{
if (in[k + 1] != '|')
in[k] = 16;
else
k++;
}

if (in[k] == '&')
{
if (in[k + 1] != '&')
in[k] = 12;
else
k++;
}
}
}
else
{
for (k = 0; in[k]; k++)
{
in[k] = (in[k] == 16 ? '|' : in[k]);
in[k] = (in[k] == 12 ? '&' : in[k]);
}
}
return (in);
}

/**
* addNodes - function that adds separators
* and command lines in the lists
* @hs: head of separator list
* @hl: head of command lines list
* @in: input string
* Return: no return
*/
void addNodes(linkList **hs, newList **hl, char *in)
{
int k;
char *line;

in = swapChar(in, 0);

for (k = 0; in[k]; k++)
{
if (in[k] == ';')
 add_newNode(hs, in[k]);

if (in[k] == '|' || in[k] == '&')
{
 add_newNode(hs, in[k]);
k++;
}
}

line = spString(in, ";|&");
do {
line = swapChar(line, 1);
add_line_node_end(hl, line);
line =spString(NULL, ";|&");
} while (line != NULL);

}

/**
* goNext - function for to go
* to the next command line stored
* @sl: separator list
* @cl: command line list
* @mydata: data structure
* Return: no return
*/
void goNext(linkList **sl,newList **cl, data_shell *mydata)
{
int loop_sep;
linkList *ls_s;
newList *ls_l;

loop_sep = 1;
ls_s = *sl;
ls_l = *cl;

while (ls_s != NULL && loop_sep)
{
if (mydata->status == 0)
{
if (ls_s->separator == '&' || ls_s->separator == ';')
loop_sep = 0;
if (ls_s->separator == '|')
ls_l = ls_l->next, ls_s = ls_s->next;
}
else
{
if (ls_s->separator == '|' || ls_s->separator == ';')
loop_sep = 0;
if (ls_s->separator == '&')
ls_l = ls_l->next, ls_s = ls_s->next;
}
if (ls_s != NULL && !loop_sep)
ls_s = ls_s->next;
}

*sl = ls_s;
*cl = ls_l;
}

/**
* splitCommands - splits command lines according to
* the separators ;, | and &, and executes them
* my@data: data structure
* @in: input string
* Return: 0 to exit, 1 to continue
*/
int splitCommands(data_shell *mydata, char *in)
{

linkList *hs, *sl;
line_list *hl, *cl;
int loop;

hs = NULL;
h = NULL;

addNodes(&hs, &hl, in);

sl = hs;
cl = hl;

while (cl != NULL)
{
mydata->in = cl->line;
mydata->args = splitLine(mydata->in);
loop = FindBuilt(mydata);
free(mydata->args);

if (loop == 0)
break;

goNext(&sl, &cl, mydata);

if (cl != NULL)
cl = cl->next;
}

free_sep_list(&hs);
free_line_list(&hl);

if (loop == 0)
return (0);
return (1);
}

/**
* splitLine - function that tokenizes the input string
*
* @in: input string.
* Return: string splitted.
*/
char **splitLine(char *in)
{
size_t bsize;
size_t k;
char **tokens;
char *token;

bsize = TOK_BUFSIZE;
tokens = malloc(sizeof(char *) * (bsize));
if (tokens == NULL)
{
write(STDERR_FILENO, ": allocation error\n", 18);
exit(EXIT_FAILURE);
}

token = spString(in, TOK_DELIM);
tokens[0] = token;

for (k = 1; token != NULL; k++)
{
if (k == bsize)
{
bsize += TOK_BUFSIZE;
tokens = realloc(tokens, k, sizeof(char *) * bsize);
if (tokens == NULL)
{
write(STDERR_FILENO, ": allocation error\n", 18);
exit(EXIT_FAILURE);
}
}
token = spString(NULL, TOK_DELIM);
tokens[k] = token;
}

return (tokens);
}
