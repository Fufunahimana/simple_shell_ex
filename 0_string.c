#include "main.h"

/**
* stringConcat - function that  concatenate two strings
* @dest: char pointer the dest of the copied str
* @src: const char pointer the source of str
* Return: the dest
*/
char * stringConcat(char *dest, const char *src)
{
int k;
int l;

for (k = 0; dest[k] != '\0'; k++)
;

for (l = 0; src[l] != '\0'; l++)
{
dest[k] = src[l];
k++;
}

dest[k] = '\0';
return (dest);
}
/**
* * stringCopy -function that Copies the string pointed to by src.
* @dest: Type char pointer the dest of the copied str
* @src: Type char pointer the source of str
* Return: the dest.
*/
char *stringCopy(char *dest, char *src)
{

size_t p;

for (p = 0; src[p] != '\0'; p++)
{
dest[p] = src[p];
}
dest[p] = '\0';
return (dest);
}
/**
* stringComp - that function compares two strings.
* @s1: type str compared
* @s2: type str compared
* Return: Always 0.
*/
int stringComp(char *s1, char *s2)
{
int k;

for (k = 0; s1[k] == s2[k] && s1[k]; k++)
;

if (s1[k] > s2[k])
return (1);
if (s1[k] < s2[k])
return (-1);
return (0);
}
/**
* stringChar - function that locates a character in a string,
* @str: string.
* @chr: character.
* Return: the pointer to the first occurrence of the character c.
*/
char *stringChar(char *str, char chr)
{
unsigned int k = 0;

for (; *(str + k) != '\0'; k++)
if (*(str + k)== chr)
return (str + k);
if (*(str + k) == chr)
return (str + k);
return ('\0');
}
/**
* sLenpSub - function that gets the length of a prefix substring.
* @is: initial segment.
* @accept: accepted bytes.
* * Return: the number of accepted bytes.
*/
int sLenpSub(char *is, char *accept)
{
int k, l, bool;

for (k = 0; *(is + k) != '\0'; k++)
{
bool = 1;
for (l = 0; *(accept + l) != '\0'; l++)
{
if (*(is + k) == *(accept + l))
{
bool = 0;
break;
}
}
if (bool == 1)
break;
}
return (k);
}
