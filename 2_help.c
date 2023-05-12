#include "main.h"

/**
* helpme - function that retrieves help messages according builtin
* @datash: data structure (args and input)
* Return: Return 0
*/
int helpme(data_shell *mydata)
{

if (mydata->args[1] == 0)
genHelper();
else if(stringComp(mydata->args[1], "setenv") == 0)
setenvHelper();
else if (stringComp(mydata->args[1], "env") == 0)
enviroHelper();
else if (stringComp(mydata->args[1], "unsetenv") == 0)
unsetenvHelper();
else if (stringComp(mydata->args[1], "help") == 0)
builtinHelper();
else if (stringComp(mydata->args[1], "exit") == 0)
exitHelper();
else if (stringComp(mydata->args[1], "cd") == 0)
cdHelper();
else if (stringComp(mydata->args[1], "alias") == 0)
aliasHelper();
else
write(STDERR_FILENO, mydata->args[0],
stringLen(mydata->args[0]));

mydata->status = 0;
return (1);
}
