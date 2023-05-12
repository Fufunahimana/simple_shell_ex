#include "main.h"

/**
* get_builtin -function that allow  builtin
* that pais the command in the arg
* @cmd: command
* Return: function pointer of the builtin command
*/
int (*get_builtin(char *cmd))(data_shell *)
{
myBuiltin  builtin[] = {
{ "env", myenvi },
{ "exit", exit_shell },
{ "setenv", setEnviro },
{ "unsetenv", doUnsetenv },
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
