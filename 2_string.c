#include "main.h"

/**
* revString -function that  reverses a string.
* @i: input string.
* Return: no return.
*/
void revString(char *i)
{
int count = 0, k, l;
char *str, temp;

while (count >= 0)
{
if (i[count] == '\0')
break;
count++;
}
str = i;

for (k = 0; k < (count - 1); k++)
{
for (l = k + 1; l > 0; l--)
{
temp = *(str + l);
*(str + l) = *(str + (l - 1));
*(str + (l - 1)) = temp;
}
}
}
