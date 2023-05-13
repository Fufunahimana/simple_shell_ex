#include "main.h"

/**
* find_error - calls the error according the builtin, syntax or permission
* @datash: data structure that contains arguments
* @eval: error value
* Return: error
*/
int Finderror(data_shell *mydata, int eval)
{
char *error;

switch (eval)
{
case -1:
error = error_env(mydata);
break;
case 126:
error = error_pathFind(mydata);
break;
case 127:
error = error_missed(mydata);
break;
case 2:
if (stringComp("exit", mydata->args[0]) == 0)
error = error_shellExit(mydata);
else if (stringComp("cd", mydata->args[0]) == 0)
error = error_missed(mydata);
break;
}

if (error)
{
write(STDERR_FILENO, error, stringLen(error));
free(error);
}

mydata->status = eval;
return (eval);
}
