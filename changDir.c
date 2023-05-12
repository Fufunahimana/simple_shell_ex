#include "main.h"

/**
* cdParentDir - function that changes to the parent directory
*
* @mydata: data relevant (environ)
*
* Return: no return
*/
void cdParentDir(data_shell *mydata)
{
char pwd[PATH_MAX];
char *dir, *cp_pwd, *cp_strtok_pwd;

getcwd(pwd, sizeof(pwd));
cp_pwd = stringDupl(pwd);
doSetEnv("OLDPWD", cp_pwd, mydata);
dir = mydata->args[1];
if (stringComp(".", dir) == 0)
{
doSetEnv("PWD", cp_pwd, mydata);
free(cp_pwd);
return;
}
if (stringComp("/", cp_pwd) == 0)
{
free(cp_pwd);
return;
}
cp_strtok_pwd = cp_pwd;
revString(cp_strtok_pwd);
cp_strtok_pwd = spString(cp_strtok_pwd, "/");
if (cp_strtok_pwd != NULL)
{
cp_strtok_pwd = spString(NULL, "\0");

if (cp_strtok_pwd != NULL)
revString(cp_strtok_pwd);
}
if (cp_strtok_pwd != NULL)
{
chdir(cp_strtok_pwd);
doSetEnv("PWD", cp_strtok_pwd, mydata);
}
else
{
chdir("/");
doSetEnv("PWD", "/", mydata);
}
mydata->status = 0;
free(cp_pwd);
}

/**
* cdGivenDir - changes to a directory given
* by the user
*
* @mydata: data relevant (directories)
* Return: no return
*/
void cdGivenDir(data_shell *mydata)
{
char pwd[PATH_MAX];
char *dir, *cp_pwd, *cp_dir;

getcwd(pwd, sizeof(pwd));

dir = mydata->args[1];
if (chdir(dir) == -1)
{
get_error(mydata, 2);
return;
}

cp_pwd = stringDupl(pwd);
doSetEnv("OLDPWD", cp_pwd, mydata);

cp_dir = stringDupl(dir);
doSetEnv("PWD", cp_dir, mydata);

free(cp_pwd);
free(cp_dir);

mydata->status = 0;

chdir(dir);
}
/**
* cdPrevDir - changes to the previous directory
*
* @mydata: data relevant (environ)
* Return: no return
*/
void cdPrevDir(data_shell *mydata)
{
char pwd[PATH_MAX];
char *p_pwd, *p_oldpwd, *cp_pwd, *cp_oldpwd;

getcwd(pwd, sizeof(pwd));
cp_pwd = stringDupl(pwd);

p_oldpwd = findEnvVar("OLDPWD", mydata->_environ);

if (p_oldpwd == NULL)
cp_oldpwd = cp_pwd;
else
cp_oldpwd = stringDupl(p_oldpwd);

doSetEnv("OLDPWD", cp_pwd, mydata);

if (chdir(cp_oldpwd) == -1)
doSetEnv("PWD", cp_pwd, mydata);
else
doSetEnv("PWD", cp_oldpwd, mydata);

p_pwd = findEnvVar("PWD", mydata->_environ);

write(STDOUT_FILENO, p_pwd, stringLen(p_pwd));
write(STDOUT_FILENO, "\n", 1);

free(cp_pwd);
if (p_oldpwd)
free(cp_oldpwd);

mydata->status = 0;

chdir(p_pwd);
}

/**
* cdHome - function that changes to home directory
*
* @mydata: data relevant (environ)
* Return: no return
*/
void cdHome(data_shell *mydata)
{
char *p_pwd, *home;
char pwd[PATH_MAX];

getcwd(pwd, sizeof(pwd));
p_pwd = stringDupl(pwd);

home = findEnvVar("HOME", mydata->_environ);

if (home == NULL)
{
doSetEnv("OLDPWD", p_pwd, mydata);
free(p_pwd);
return;
}

if (chdir(home) == -1)
{
get_error(mydata, 2);
free(p_pwd);
return;
}

doSetEnv("OLDPWD", p_pwd, mydata);
doSetEnv("PWD", home, mydata);
free(p_pwd);
mydata->status = 0;
}
