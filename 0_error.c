#include "main.h"

/**
* cdErrConcat - function that concatenates the message for cd error
*
* @datash: data relevant (directory)
* @msg: message to print
* @error: output message
* @ver_str: counter lines
* Return: error message
*/
char *cdErrConcat(data_shell *mydata, char *msg, char *error, char *ver_str)
{
char *bad_flag;

stringCopy(error, mydata->av[0]);
stringConcat(error, ": ");
stringConcat(error, ver_str);
stringConcat(error, ": ");
stringConcat(error,mydata->args[0]);
stringConcat(error, msg);
if (mydata->args[1][0] == '-')
{
bad_flag = malloc(3);
bad_flag[0] = '-';
bad_flag[1] = mydata->args[1][1];
bad_flag[2] = '\0';
stringConcat(error, bad_flag);
free(bad_flag);
}
else
{
stringConcat(error, mydata->args[1]);
}

stringConcat(error, "\n");
stringConcat(error, "\0");
return (error);
}
/**
* cdErrGet - that allow error message
* for cd command in get_cd
* @datash: data relevant (directory)
* Return: Error message
*/
char *cdErrGet(data_shell *mydata)
{
int length, len_id;
char *error, *ver_str, *msg;

ver_str = aux_itoa(mydata->counter);
if (mydata->args[1][0] == '-')
{
msg = ": Wrong option ";
len_id = 2;
}
else
{
msg = ": can't change directory to ";
len_id = stringLen(mydata->args[1]);
}

length = stringLen(mydata->av[0]) + stringLen(mydata->args[0]);
length += stringLen(ver_str) + stringLen(msg) + len_id + 5;
error = malloc(sizeof(char) * (length + 1));

if (error == 0)
{
free(ver_str);
return (NULL);
}

error = cdErrConcat(mydata, msg, error, ver_str);

free(ver_str);

return (error);
}
/**
* error_missed - error message when the
* command get no error
* @datash: data relevant (counter, arguments)
* Return: Error message
*/
char *error_missed(data_shell *mydata)
{
int length;
char *error;
char *ver_str;

ver_str = aux_itoa(mydata->counter);
length = stringLen(mydata->av[0]) + stringLen(ver_str);
length += stringLen(mydata->args[0]) + 16;
error = malloc(sizeof(char) * (length + 1));
if (error == 0)
{
free(error);
free(ver_str);
return (NULL);
}
stringCopy(error, mydata->av[0]);
stringConcat(error, ": ");
stringConcat(error, ver_str);
stringConcat(error, ": ");
stringConcat(error, mydata->args[0]);
stringConcat(error, ": not found\n");
stringConcat(error, "\0");
free(ver_str);
return (error);
}

/**
* error_shellExit - generic an error message for exit in get_exit
* @mydata: data relevant (counter, arguments)
*
* Return: Error message
*/
char *error_shellExit(data_shell *mydata)
{
int length;
char *error;
char *ver_str;

ver_str = aux_itoa(mydata->counter);
length = stringLen(mydata->av[0]) + stringLen(ver_str);
length += stringLen(mydata->args[0]) + stringLen(mydata->args[1]) + 23;
error = malloc(sizeof(char) * (length + 1));
if (error == 0)
{
free(ver_str);
return (NULL);
}
stringCopy(error, mydata->av[0]);
stringConcat(error, ": ");
stringConcat(error, ver_str);
stringConcat(error, ": ");
stringConcat(error, mydata->args[0]);
stringConcat(error, ": Wrong number: ");
stringConcat(error, mydata->args[1]);
stringConcat(error, "\n\0");
free(ver_str);

return (error);
}
