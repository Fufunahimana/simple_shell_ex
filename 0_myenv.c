#include "main.h"

/**
* envCompName - function that  compares env variables names
* with the name passed.
* @nenv: name of the environment variable
* @name: name passed
*
* Return: 0 if are not equal. Another value if they are.
*/
int envCompName(const char *nenv, const char *name)
{
int k;

for (k = 0; nenv[k] != '='; k++)
{
if (nenv[k] != name[k])
{
return (0);
}
}

return (k + 1);
}

/**
* findEnvVar -function that help to  get
* an environment variable
* @name: name of the environment variable
* @_environ: environment variable
*
* Return: value of the environment variable if is found.
* In other case, returns NULL.
*/
char *findEnvVar(const char *name, char **_environ)
{
char *ptr_env;
int k, mov;

/* Initialize ptr_env value */
ptr_env = NULL;
mov = 0;
/* Compare all environment variables */
/* environ is declared in the header file */
for (k = 0; _environ[k]; k++)
{
/* If name and env are equal */
mov = envCompName(_environ[k], name);
if (mov)
{
ptr_env = _environ[k];
break;
}
}

return (ptr_env + mov);
}

/**
* myenvi -function that  prints the evironment variables
*
* @mydata: data relevant.
* Return: 1 on success.
*/
int myenvi(data_shell *mydata)
{
int k, l;

for (k = 0; mydata->_environ[k]; k++)
{

for (l = 0; mydata->_environ[k][l]; l++)
;

write(STDOUT_FILENO, mydata->_environ[k], l);
write(STDOUT_FILENO, "\n", 1);
}
mydata->status = 0;

return (1);
}
