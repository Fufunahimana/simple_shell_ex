#include "main.h"

/**
* repChar - counts the repetitions of a char
*
* @is: input string
* @in: index
* Return: repetitions
*/
int repChar(char *is, int in)
{
if (*(is - 1) == *is)
return (repChar(is - 1, in + 1));

return (in);
}

/**
* errorFinder -function that  finds syntax errors
* @is: input string
* @in: index
* @lcr: last char read
* Return: index of error. 0 when there are no
* errors
*/
int errorFinder(char *is, int in, char lcr)
{
int count;

count = 0;
if (*is == '\0')
return (0);

if (*is == ' ' || *is == '\t')
return (errorFinder(is + 1, in + 1, lcr));

if (*is == ';')
if (lcr == '|' || lcr == '&' || lcr == ';')
return (in);

if (*is == '|')
{
if (lcr == ';' || lcr == '&')
return (in);

if (lcr == '|')
{
count = repChar(is, 0);
if (count == 0 || count > 1)
return (in);
}
}

if (*is == '&')
{
if (lcr == ';' || lcr == '|')
return (in);

if (lcr == '&')
{
count = repChar(is, 0);
if (count == 0 || count > 1)
return (in);
}
}

return (errorFinder(is + 1, in + 1, *is));
}

/**
* firstChar - function that finds
* index of the first char
*
* @is: input string
* @in: index
* Return: 1 if there is an error. 0 in other case.
*/
int firstChar(char *is, int *in)
{

for (*in = 0; is[*in]; *in += 1)
{
if (is[*in] == ' ' || is[*in] == '\t')
continue;

if (is[*in] == ';' || is[*in] == '|' || is[*in] == '&')
return (-1);

break;
}

return (0);
}

/**
* syntaxError - function that  prints 
* a syntax error when it is found
* @mydata: data structure
* @is: input string
* @in: index of the error
* @bool: to control msg error
* Return: no return
*/
void syntaxError(data_shell *mydata, char *is, int in, int bool)
{
char *msg, *msg2, *msg3, *error, *counter;
int length;

if (is[in] == ';')
{
if (bool == 0)
msg = (is[in + 1] == ';' ? ";;" : ";");
else
msg = (is[in - 1] == ';' ? ";;" : ";");
}

if (is[in] == '|')
msg = (is[in + 1] == '|' ? "||" : "|");

if (is[in] == '&')
msg = (is[in + 1] == '&' ? "&&" : "&");

msg2 = ": Syntax error: \"";
msg3 = "\" unexpected\n";
counter = aux_itoa(mydata->counter);
length = stringLen(mydata->av[0]) + stringLen(counter);
length += stringLen(msg) + stringLen(msg2) + stringLen(msg3) + 2;

error = malloc(sizeof(char) * (length + 1));
if (error == 0)
{
free(counter);
return;
}
stringCopy(error, mydata->av[0]);
stringConcat(error, ": ");
stringConcat(error, counter);
stringConcat(error, msg2);
stringConcat(error, msg);
stringConcat(error, msg3);
stringConcat(error, "\0");

write(STDERR_FILENO, error, length);
free(error);
free(counter);
}

/**
* checkSyntaxError - an intermediate function to
* find and print a syntax error
*
* @mydata: data structure
* @is: input string
* Return: 1 if there is an error. 0 in other case
*/
int checkSyntaxError(data_shell *mydata, char *is)
{
int begin = 0;
int f_char = 0;
int in = 0;

f_char = firstChar(is, &begin);
if (f_char == -1)
{
syntaxError(mydata, is, begin, 0);
return (1);
}

in = errorFinder(is + begin, 0, *(is + begin));
if (in != 0)
{
syntaxError(mydata, is, begin + in, 1);
return (1);
}

return (0);
}
