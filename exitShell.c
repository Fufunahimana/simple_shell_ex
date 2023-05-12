#include "main.h"

/**
* exitShell - Function that exits the shell
*
* @mydata: data relevant (status and args)
* Return: 0 on success.
*/
int exitShell(data_shell *mydata)
{
unsigned int ustatus;
int isDigit;
int str_len;
int bigNumber;

if (mydata->args[1] != NULL)
{
ustatus = _atoi(mydata->args[1]);
isDigit = defString(mydata->args[1]);
str_len =  stringLen(mydata->args[1]);
bigNumber = ustatus > (unsigned int)INT_MAX;
if (!isDigit || str_len > 10 || bigNumber)
{
get_error(mydata, 2);
mydata->status = 2;
return (1);
}
mydata->status = (ustatus % 256);
}
return (0);
}
