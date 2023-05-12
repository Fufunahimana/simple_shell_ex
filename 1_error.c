#include "main.h"

/**
* error_env - error message for env in get_env.
* @datash: data relevant (counter, arguments)
* Return: error message.
*/
char *error_env(data_shell *mydata)
{
int length;
char *error;
char *ver_str;
char *msg;

ver_str = aux_itoa(mydata->counter);
msg = ": Unable to add/remove from environment\n";
length =stringLen(mydata->av[0]) + stringLen(ver_str);
length += stringLen(mydata->args[0]) + stringLen(msg) + 4;
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
stringConcat(error, msg);
stringConcat(error, "\0");
free(ver_str);

return (error);
}
/**
* error_pathFind -an  error message for path and failure denied permission.
* @mydata: data relevant (counter, arguments).
*
* Return: The error string.
*/
char *error_pathFind(data_shell *mydata)
{
int length;
char *ver_str;
char *error;

ver_str = aux_itoa(mydata->counter);
length = stringLen(mydata->av[0]) + stringLen(ver_str);
length += stringLen(mydata->args[0]) + 24;
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
stringConcat(error, ": Permission denied\n");
stringConcat(error, "\0");
free(ver_str);
return (error);
}
