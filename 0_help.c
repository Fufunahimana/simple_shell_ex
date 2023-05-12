#include "main.h"

/**
* enviroHelper - that function Help information for the builtin env
* Return: no return
*/
void enviroHelper(void)
{
char *help = "env: env [option] [name=value] [command [args]]\n\t";

write(STDOUT_FILENO, help, stringLen(help));
help = "Print the enviroment of the shell.\n";
write(STDOUT_FILENO, help, stringLen(help));

}
/**
* setenvHelper - that function  Help information for the builtin setenv
* Return: no return
*/
void setenvHelper(void)
{

char *help = "setenv: setenv (const char *name, const char *value,";

write(STDOUT_FILENO, help,stringLen(help));
help = "int replace)\n\t";
write(STDOUT_FILENO, help, stringLen(help));
help = "Add a new definition to the environment\n";
write(STDOUT_FILENO, help,stringLen(help));
}
/**
* unsetenvHelper - function that  Help information for the builtin unsetenv
* Return: no return
*/
void unsetenvHelper(void)
{
char *help = "unsetenv: unsetenv (const char *name)\n\t";

write(STDOUT_FILENO, help, stringLen(help));
help = "Remove an entry completely from the environment\n";
write(STDOUT_FILENO, help, stringLen(help));
}
/**
* genHelper - The Entry point for help information for the help builtin
* Return: no return
*/
void genHelper(void)
{
char *help = "^-^ bash, version 1.0(1)-release\n";

write(STDOUT_FILENO, help, stringLen(help));
help = "These commands are defined internally.Type 'help' to see the list";
write(STDOUT_FILENO, help, stringLen(help));
help = "Type 'help name' to find out more about the function 'name'.\n\n ";
write(STDOUT_FILENO, help, stringLen(help));
help = " alias: alias [name=['string']]\n cd: cd [-L|[-P [-e]] [-@]] ";
write(STDOUT_FILENO, help, stringLen(help));
help = "[dir]\nexit: exit [n]\n  env: env [option] [name=value] [command ";
write(STDOUT_FILENO, help, stringLen(help));
help = "[args]]\n  setenv: setenv [variable] [value]\n  unsetenv: ";
write(STDOUT_FILENO, help, stringLen(help));
help = "unsetenv [variable]\n";
write(STDOUT_FILENO, help, stringLen(help));
}
/**
* exitHelper - function that  Help an information for the builint exit
* Return: no return
*/
void exitHelper(void)
{
char *help = "exit: exit [n]\n Exit shell.\n";

write(STDOUT_FILENO, help, stringLen(help));
help = "Exits the shell with a status of N. If N is ommited, the exit";
write(STDOUT_FILENO, help, stringLen(help));
help = "statusis that of the last command executed\n";
write(STDOUT_FILENO, help,stringLen(help));
}
