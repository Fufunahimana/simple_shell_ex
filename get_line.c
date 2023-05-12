#include "main.h"

/**
* bringLine - That function  assigns the line var for get_line
* @lineptr: Buffer that store the input str
* @buffer: str that is been called to line
* @n: size of line
* @j: size of buffer
*/
void bringLine(char **lineptr, size_t *l, char *buffer, size_t b)
{

if (*lineptr == NULL)
{
if  (b > BUFSIZE)
*l = b;

else
*l = BUFSIZE;
*lineptr = buffer;
}
else if (*l < b )
{
if (b > BUFSIZE)
*l = b;
else
*l = BUFSIZE;
*lineptr = buffer;
}
else
{
stringCopy(*lineptr, buffer);
free(buffer);
}
}
/**
* getLine -That function Read input from stream
* @lineptr: buffer that stores the input
* @l: size of lineptr
* @stream: stream to read from
* Return: The number of bytes
*/
ssize_t getLine(char **lineptr, size_t *l, FILE *stream)
{
int k;
static ssize_t input;
ssize_t retval;
char *buffer;
char t = 'z';

if (input == 0)
fflush(stream);
else
return (-1);
input = 0;

buffer = malloc(sizeof(char) * BUFSIZE);
if (buffer == 0)
return (-1);
while (t != '\n')
{
k = read(STDIN_FILENO, &t, 1);
if (k == -1 || (k == 0 && input == 0))
{
free(buffer);
return (-1);
}
if (k == 0 && input != 0)
{
input++;
break;
}
if (input >= BUFSIZE)
buffer = _realloc(buffer, input, input + 1);
buffer[input] = t;
input++;
}
buffer[input] = '\0';
bringLine(lineptr, l, buffer, input);
retval = input;
if (k != 0)
input = 0;
return (retval);
}
