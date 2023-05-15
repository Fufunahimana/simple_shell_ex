#include "main.h"

/**
* FindBuilt - function that 
* finds builtins and commands
* @mydata: data relevant (args)
* Return: 1 on success.
*/
int FindBuilt(data_shell *mydata)
{
int (*builtin)(data_shell *mydata);

if (mydata->args[0] == NULL)
return (1);

builtin = getBuiltin(mydata->args[0]);

if (builtin != NULL)
return (builtin(mydata));

return (executComand(mydata));
}
