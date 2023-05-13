#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

/* Points to an array of pointers to strings called the "environment" */
extern char **environ;


/**
 * struct data - struct that contains all relevant data on runtime
 * @av: argument vector
 * @input: command line written by the user
 * @args: tokens of the command line
 * @status: last status of the shell
 * @counter: lines counter
 * @_environ: environment variable
 * @pid: process ID of the shell
 */
typedef struct data
{
        char **av;
        char *input;
        char **args;
        int status;
        int counter;
        char **_environ;
        char *pid;
} data_shell;
/**
 * struct linkList_s - single linked list
 * @separator: ; | &
 * @next: next node
 * Description: single linked list to store separators
 */
typedef struct linkList_s
{
        char separator;
        struct linkList_s *next;
} linkList;

/**
 * struct newList - single linked list
 * @line: command line
 * @next: next node
 * Description: single linked list to store command lines
 */
typedef struct newList_s
{
        char *line;
        struct newList_s *next;
} newList;

/**
 * struct newVar_list - single linked list
 * @len_var: length of the variable
 * @val: value of the variable
 * @len_val: length of the value
 * @next: next node
 * Description: single linked list to store variables
 */
typedef struct newVar_list
{
        int len_var;
        char *val;
        int len_val;
        struct newVar_list *next;
} newVar;

/**
 * struct builtin_s - Builtin struct for command args.
 * @name: The name of the command builtin i.e cd, exit, env
 * @f: data type pointer function.
 */
typedef struct mybuiltin_s
{
        char *name;
        int (*f)(data_shell *mydata);
} myBuiltin;

/* 0_mylist.c */
linkList *add_sep_newNode(linkList **head, char sep);
void free_linkList(linkList **head);
newList *add_lineNewNode(newList **head, char *line);
void free_newList(newList **head);

/* 1_mylist.c */

newVar *add_rvar_node(newVar **head, int lvar, char *val, int lval);
void free_rvar_list(newVar **head);

/*0_string.c*/

char * stringConcat(char *dest, const char *src);
char *stringCopy(char *dest, char *src);
int stringComp(char *s1, char *s2);
char *stringChar(char *str, char chr );
int sLenpSub(char *is, char *accept);

/* aux_mem.c */
void _memcpy(void *newptr, const void *ptr, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);
/*1_string.c*/

char *stringDupl(const char *t);
int stringLen(const char *t);
int compChars(char i[], const char *d);
char *spString(char i[], const char *d);
int defString(const char *is);

/*2_string.c*/
void revString(char *i);


/*checkerror.c*/

int repChar(char *is, int in);
int errorFinder(char *is, int in, char lcr);
int firstChar(char *is, int *in);
void syntaxError(data_shell *mydata, char *is, int in, int bool);
int checkSyntaxError(data_shell *mydata, char *is);


/* shell_loop.c */
char *without_comment(char *in);
void shell_loop(data_shell *mydata);

/* read_line.c */
char *read_line(int *i_eof);


/* split.c */

char *swapChar(char *in, int bool);
void addNodes(linkList **hs, newList **hl, char *in);
void goNext(linkList **sl,newList **cl, data_shell *mydata);
int splitCommands(data_shell *mydata, char *in);
char **splitLine(char *in);


/*excLine.c*/
int FindBuilt(data_shell *mydata);
/*executor.c*/

int CurDirChecker(char *cp, int *ip);
char *locComand(char *cmd, char **_environ);
int excutDet(data_shell *mydata);
int comandCheckError(char *dd, data_shell *mydata);
int executComand(data_shell *mydata);


/*0_myenv.c*/
int envCompName(const char *nenv, const char *name);
char *findEnvVar(const char *name, char **_environ);
int myenvi(data_shell *mydata);
/*1_myenv.c*/

char *copyInfo(char *name, char *value);
void doSetEnv(char *name, char *value, data_shell *mydata);
int setEnviro(data_shell *mydata);
int doUnsetenv(data_shell *mydata);

/*changDir.c*/
void cdParentDir(data_shell *mydata);
void cdGivenDir(data_shell *mydata);
void cdPrevDir(data_shell *mydata);
void cdHome(data_shell *mydata);

/*chngDirShell.c*/

int cdShell(data_shell *mydata);

/* get_builtin */
int (*get_builtin(char *cmd))(data_shell *mydata);

/* _exit.c */
int exit_shell(data_shell *mydata);

/* aux_stdlib.c */
int get_len(int n);
char *aux_itoa(int n);
int _atoi(char *s);
/* 0_error.c */

char *cdErrConcat(data_shell *mydata, char *msg, char *error, char *ver_str);
char *cdErrGet(data_shell *mydata);
char *error_missed(data_shell *mydata);
char *error_shellExit(data_shell *mydata);

/* 1_error.c */
char *error_env(data_shell *mydata);
char *error_pathFind(data_shell *mydata);

/* aux_error2.c */
char *error_get_alias(char **args);
char *error_env(data_shell *mydata);
char *error_syntax(char **args);
char *error_permission(char **args);
char *error_path_126(data_shell *mydata);


/* 3_error.c */
int Finderror(data_shell *mydata, int eval);
int get_error(data_shell *mydata, int eval);

/* get_sigint.c */
void get_sigint(int sig);

/*0_help.c*/
void enviroHelper(void);
void setenvHelper(void);
void unsetenvHelper(void);
void genHelper(void);
void exitHelper(void);

/*1_help.c*/
void builtinHelper(void);
void aliasHelper(void);
void cdHelper(void);

/*2_help.c*/
int helpme(data_shell *mydata);

#endif
