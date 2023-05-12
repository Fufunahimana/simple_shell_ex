#include "main.h"

/**
* stringDupl - function that duplicates a 
* str in the heap memory.
* @t: Type char pointer str
* Return: duplicated str
*/
char *stringDupl(const char *t)
{
char *new;
size_t len;

len = stringLen(t);
new = malloc(sizeof(char) * (len + 1));
if (new == NULL)
return (NULL);
_memcpy(new, t, len + 1);
return (new);
}

/**
* stringLen -function that  Returns the lenght of a string.
* @t: Type char pointer
* Return: Always 0.
*/
int stringLen(const char *t)
{
int len;

for (len = 0; t[len] != 0; len++)
{
}
return (len);
}

/**
* compChars - function that  compare chars of strings
* @i: input string.
* @d: delimiter.
*
* Return: 1 if are equals, 0 if not.
*/
int compChars(char i[], const char *d)
{
unsigned int k, l, m;
for (k = 0, m = 0; i[k]; k++)
{
for (l = 0; d[l]; l++)
{
if (i[k] == d[l])
{
m++;
break;
}
}
}
if (k == m)
return (1);
return (0);
}

/**
* spString - function that splits a string by some delimiter.
* @i: input string.
* @d: delimiter.
*
* Return: string splited.
*/
char *spString(char i[], const char *d)
{
static char *splitted, *str_end;
char *str_start;
unsigned int k, bool;

if (i != NULL)
{
if (compChars(i, d))
return (NULL);
splitted = i; /*Store first address*/
k = stringLen(i);
str_end = &i[k]; /*Store last address*/
}
str_start = splitted;
if (str_start == str_end) /*Reaching the end*/
return (NULL);

for (bool = 0; *splitted; splitted++)
{
/*Breaking loop finding the next token*/
if (splitted != str_start)
if (*splitted && *(splitted - 1) == '\0')
break;
/*Replacing delimiter for null char*/
for (k = 0; d[k]; k++)
{
if (*splitted == d[k])
{
*splitted = '\0';
if (splitted == str_start)
str_start++;
break;
}
}
if (bool == 0 && *splitted) /*Str != Delim*/
bool = 1;
}
if (bool == 0) /*Str == Delim*/
return (NULL);
return (str_start);
}

/**
* defString - function that defines if string passed is a number
*
* @is: input string
* Return: 1 if string is a number. 0 in other case.
*/
int defString(const char *is)
{
unsigned int k;

for (k = 0; is[k]; k++)
{
if (is[k] < 48 || is[k] > 57)
return (0);
}
return (1);
}
