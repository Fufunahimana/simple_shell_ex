#include "main.h"

/**
* getBuiltin - builtin that pais the command in the arg
* @cmd: command
* Return: function pointer of the builtin command
*/
int (*getBuiltin(char *cmd))(data_shell *)
{
myBuiltin builtin[] = {
{ "env", myenvi },
{ "exit", exitShell },
{ "setenv", _setenv },
{ "unsetenv", _unsetenv },
{ "cd", cdShell },
{ "help", helpme },
{ NULL, NULL }
};
int k;

for (k = 0; builtin[k].name; k++)
{
if (stringComp(builtin[k].name, cmd) == 0)
break;
}

return (builtin[k].f);
}
