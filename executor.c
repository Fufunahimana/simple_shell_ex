#include "main.h"

/**
* curDirChecker - function that checks ":"
* if is in the current directory.
* @cp: type char pointer char.
* @ip: type int pointer of index.
* Return: 1 if the path is searchable in the cd, 0 otherwise.
*/
int curDirChecker(char *cp, int *ip)
{
if (cp[*ip] == ':')
return (1);

while (cp[*ip] != ':' && cp[*ip])
{
*ip += 1;
}

if (cp[*ip])
*ip += 1;

return (0);
}

/**
* locComand -function that  locates a command
* @cmd: command name
* @_environ: environment variable
* Return: location of the command.
*/
char *locComand(char *cmd, char **_environ)
{
char *path, *ptr_path, *token_path, *dir;
int len_dir, len_cmd, k;
struct stat st;

path = findEnvVar("PATH", _environ);
if (path)
{
ptr_path = stringDupl(path);
len_cmd = stringLen(cmd);
token_path = spString(ptr_path, ":");
k = 0;
while (token_path != NULL)
{
if (curDirChecker(path, &k))
if (stat(cmd, &st) == 0)
return (cmd);
len_dir = stringLen(token_path);
dir = malloc(len_dir + len_cmd + 2);
stringCopy(dir, token_path);
stringConcat(dir, "/");
stringConcat(dir, cmd);
stringConcat(dir, "\0");
if (stat(dir, &st) == 0)
{
free(ptr_path);
return (dir);
}
free(dir);
token_path = spString(NULL, ":");
}
free(ptr_path);
if (stat(cmd, &st) == 0)
return (cmd);
return (NULL);
}
if (cmd[0] == '/')
if (stat(cmd, &st) == 0)
return (cmd);
return (NULL);
}

/**
* excutDet - function that  determines
* if is an executable
* @mydata: data structure
* Return: 0 if is not an executable, other number if it does
*/
int excutDet(data_shell *mydata)
{
struct stat st;
int k;
char *input;

input = mydata->args[0];
for (k = 0; input[k]; k++)
{
if (input[k] == '.')
{
if (input[k + 1] == '.')
return (0);
if (input[k + 1] == '/')
continue;
else
break;
}
else if (input[k] == '/' && k != 0)
{
if (input[k + 1] == '.')
continue;
k++;
break;
}
else
break;
}
if (k == 0)
return (0);

if (stat(input + k, &st) == 0)
{
return (k);
}
get_error(mydata, 127);
return (-1);
}

/**
* comandCheckError - function that verifies
* if user has permissions to access
* @dd: destination directory
* @mydata: data structure
* Return: 1 if there is an error, 0 if not
*/
int comandCheckError(char *dd, data_shell *mydata)
{
if (dd == NULL)
{
get_error(mydata, 127);
return (1);
}

if (stringComp(mydata->args[0], dd) != 0)
{
if (access(dd, X_OK) == -1)
{
get_error(mydata, 126);
free(dd);
return (1);
}
free(dd);
}
else
{
if (access(mydata->args[0], X_OK) == -1)
{
get_error(mydata, 126);
return (1);
}
}

return (0);
}

/**
* executComand - function that 
* executes command lines
* @mydata: data relevant (args and input)
* Return: 1 on success.
*/
int executComand(data_shell *mydata)
{
pid_t pd;
pid_t wpd;
int state;
int exec;
char *dir;
(void) wpd;

exec = executComand(mydata);
if (exec == -1)
return (1);
if (exec == 0)
{
dir = locComand(mydata->args[0], mydata->_environ);
if (comandCheckError(dir, mydata) == 1)
return (1);
}

pd = fork();
if (pd == 0)
{
if (exec == 0)
dir = locComand(mydata->args[0], mydata->_environ);
else
dir = mydata->args[0];
execve(dir + exec, mydata->args, mydata->_environ);
}
else if (pd < 0)
{
perror(mydata->av[0]);
return (1);
}
else
{
do {
wpd = waitpid(pd, &state, WUNTRACED);
} while (!WIFEXITED(state) && !WIFSIGNALED(state));
}

mydata->status = state / 256;
return (1);
}
