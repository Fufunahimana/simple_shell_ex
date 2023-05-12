
#include "main.h"

/**
* cdShell - function that allow to
* change a current directory
* @mydata: data relevant
* Return: 1 on success
*/
int cdShell(data_shell *mydata)
{
char *dir;
int home1, home2, welcome;

dir = mydata->args[1];

if (dir != NULL)
{
home1 = stringComp("$HOME", dir);
home2 = stringComp("~", dir);
welcome = stringComp("--", dir);
}

if (dir == NULL || !home1 || !home2 || !welcome)
{
cdHome(mydata);
return (1);
}

if (stringComp("-", dir) == 0)
{
cdPrevDir(mydata);
return (1);
}

if (stringComp(".", dir) == 0 || stringComp("..", dir) == 0)
{
cdParentDir(mydata);
return (1);
}

cdGivenDir(mydata);

return (1);
