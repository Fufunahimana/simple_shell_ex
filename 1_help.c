#include "main.h"

/**
* builtinHelper - that function Help information for the builtin help.
* Return: no return
*/
void builtinHelper(void)
{
char *help = "help: help [-dms] [pattern ...]\n";

write(STDOUT_FILENO, help, stringLen(help));
help = "\tDisplay information about builtin commands.\n ";
write(STDOUT_FILENO, help, stringLen(help));
help = "Displays brief summaries of builtin commands.\n";
write(STDOUT_FILENO, help, stringLen(help));
}
/**
* aliasHelper - that function Help information for the builtin alias.
* Return: no return
*/
void aliasHelper(void)
{
char *help = "alias: alias [-p] [name[=value]...]\n";

write(STDOUT_FILENO, help, stringLen(help));
help = "\tDefine or display aliases.\n ";
write(STDOUT_FILENO, help, stringLen(help));
}
/**
* cdHelper -that function  Help information for the builtin alias.
* Return: no return
*/
void cdHelper(void)
{
char *help = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

write(STDOUT_FILENO, help, stringLen(help));
help = "\tChange the shell working directory.\n ";
write(STDOUT_FILENO, help, stringLen(help));
}
