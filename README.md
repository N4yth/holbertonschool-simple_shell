# **C - SIMPLE_SHELL Holbertonschool Toulouse**  


## **Summary**
* [Authors](#authors)
* [Installation](#installation)
* [Flowchart](#flowchart)
* [Resources](#resources)
* [Requirements](#requirements)
* [Files](#files)
* [Compilation](#compilation)
* [Allowed_functions_and_system_calls](#allowed_functions_and_system_calls)
* [Prototypes](#prototypes)
* [Functions](#functions)
* [Output](#output)
* [Testing](#testing)
* [Checks](#checks)
* [Example](#example)
* [Tools to help](#tools-to-help)

---------------------------


# **Background Context**
Write a simple UNIX command interpreter.  
**The challenge:**  
This is a group project, with a important collaboration.  
The project lasts 2 weeks.  


# **Authors**  
This project is done in team:  
@Nathan Dupuis  
@Ingrid Mornac


# **Installation**  
Create one project repository for our team, with the main branch and a branch per member on our Github.  


# **Flowchart**  


# **Resources**
## **Read or watch:**
- [Unix_shell](https://en.wikipedia.org/wiki/Unix_shell)  
- [Thompson_shell](https://en.wikipedia.org/wiki/Thompson_shell)  
- [Ken_Thompson](https://en.wikipedia.org/wiki/Ken_Thompson)  
- [Everything_you_need_to_know_to_start_coding_your_own_shell_concept_page](https://github.com/N4yth/holbertonschool-simple_shell/blob/ingrid/Images/Everything%20you%20need%20to%20know.pdf)


## **Man:**


# **Requirements**  
- Allowed editors: vi, vim, emacs
- All your files should end with a new line
- Your code should use the Betty style. 
- It will be checked using betty-style.pl and betty-doc.pl
- Your shell should not have any memory leaks
- No more than 5 functions per file
- All your header files should be include guarded
- Use system calls only when you need to  


# **Files**  
- README.md
- AUTHORS
- man_1_simple_shell  
- simpleShell.h  
contains declaration for all the functions in this repo, and the libraries
- main.c
- getEnv.c  
creation of our GetEnv function
- strtoken.c
- findExec.c
- execution.c  


# **Compilation**
All your files will be compiled on Ubuntu 20.04 LTS.
The code will be compiled this way:
```
gcc, using the options -Wall -Werror -    Wextra -pedantic -std=gnu89
```  

# **Allowed functions and system calls**
|Allowed functions and system calls|Allowed functions and system calls|
|-----------------------------|--------------------------------|
|- all functions from string.h|- access (man 2 access)|
|- chdir (man 2 chdir)|- close (man 2 close)|
|- closedir (man 3 closedir)|- execve (man 2 execve)|
|- exit (man 3 exit)|- _exit (man 2 _exit)|
|- fflush (man 3 fflush)|- fork (man 2 fork)|
|- free (man 3 free)|- getcwd (man 3 getcwd)|
|- getline (man 3 getline)|- getpid (man 2 getpid)|
|- isatty (man 3 isatty)|- kill (man 2 kill)|
|- malloc (man 3 malloc)|- open (man 2 open)|
|- opendir (man 3 opendir)|- perror (man 3 perror)|
|- printf (man 3 printf)|- fprintf (man 3 fprintf)|
|- vfprintf (man 3 vfprintf)|- sprintf (man 3 sprintf)|
|- putchar (man 3 putchar)|- read (man 2 read)|
|- readdir (man 3 readdir)|- signal (man 2 signal)|
|- stat (__xstat) (man 2 stat)|- lstat (__lxstat) (man 2 lstat)|
|- fstat (__fxstat) (man 2 fstat)|- strtok (man 3 strtok)|
|- wait (man 2 wait)|- waitpid (man 2 waitpid)|
|- wait3 (man 2 wait3)|- wait4 (man 2 wait4)|
|- write (man 2 write)|  


# **Prototypes**
The prototypes of all the functions are included in the header file called simpleShell.h.


# **Functions**
|Function | Description |
|---------|-------------|
|char **strtoken(char **command, char *line, char *separator)|strok the line given into an array of all element|
|char *myGetEnv(const char *name)|retrieve the value of an environment variable|
|int findExec(char **command)|handle the paths|
|int execution(char **command)|execute the command|  


# **Output**
- Unless specified otherwise, your program must have the exact same output:
as sh (/bin/sh) as well as the exact same error output.
- The only difference is when you print an error:
 the name of the program must be equivalent to your argv[0]


# **Testing**
- Your shell should work like this in interactive mode:
```
julien@ubuntu:/# ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
julien@ubuntu:/#
```
- But also in non-interactive mode:
```
julien@ubuntu:/# echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
julien@ubuntu:/# cat test_ls_2
/bin/ls
/bin/ls
julien@ubuntu:/# cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
julien@ubuntu:/#
```


# **Checks**
The Checker will be released at the end of the project (1-2 days before the deadline).  
We strongly encourage the entire class to work together to create a suite of checks 
covering both regular tests and edge cases for each task.  
After the deadline, you will need to fork the repository if it’s not on your Github account 
to be able to be corrected by the checker.


# **Example**
**Fork, wait and execve code** 
```
int main(void) 
{
    pid_t pid;
    int i;

    for (i = 0; i < 5; i++)
    {
        pid = fork();

        if (pid == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0)
        {
             printf("Child %d: Execute the command 'ls -l /tmp'\n", i + 1);
            
            char *args[] = {"/bin/ls", "-l", "/tmp", NULL};
            
            if (execve(args[0], args, NULL) == -1)
            {
                perror("execve");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            wait(NULL);
        }
    }
    return 0;
}
```
**Fork, wait and execve output**
```
Child 1: Execute the command 'ls -l /tmp'
total 52
drwxr-xr-x 2 compiler compiler 4096 Apr 21 13:12 4L24cucsCz
drwxr-xr-x 2 compiler compiler 4096 Apr 21 13:13 722nx9yuCT
drwxr-xr-x 2 compiler compiler 4096 Apr 21 13:13 LriY70ay9m
drwxr-xr-x 2 compiler compiler 4096 Apr 21 13:13 MCkt5fbhjW
drwxr-xr-x 2 compiler compiler 4096 Apr 21 13:13 Rp7xfycKiF
drwxr-xr-x 2 compiler compiler 4096 Apr 21 13:13 VGL2RNn2j7
drwxr-xr-x 2 compiler compiler 4096 Apr 21 13:13 WTufTgioBX
drwxr-xr-x 2 compiler compiler 4096 Apr 21 13:12 X11DdGEb7L
drwxr-xr-x 2 compiler compiler 4096 Apr 21 13:12 ZQPoGUoy2D
-rw------- 1 compiler compiler    0 Apr 21 13:13 ccZKMuGd.s
-rw------- 1 compiler compiler    0 Apr 21 13:13 ccl9Vsz1.s
prw-r--r-- 1 compiler compiler    0 Apr 21 09:59 fifo
drwxr-xr-x 2 compiler compiler 4096 Apr 21 13:13 kk7txJ7Pji
drwxr-xr-x 3 compiler compiler 4096 Apr 21 08:57 pkg
drwxr-xr-x 2 compiler compiler 4096 Apr 21 13:12 sKX1aqUYNd
drwxr-xr-x 2 compiler compiler 4096 Apr 21 13:10 uKfjY3GTdO
Child 2: Execute the command 'ls -l /tmp'
total 52
drwxr-xr-x 2 compiler compiler 4096 Apr 21 13:12 4L24cucsCz
drwxr-xr-x 2 compiler compiler 4096 Apr 21 13:13 722nx9yuCT
drwxr-xr-x 2 compiler compiler 4096 Apr 21 13:13 LriY70ay9m
drwxr-xr-x 2 compiler compiler 4096 Apr 21 13:13 MCkt5fbhjW
drwxr-xr-x 2 compiler compiler 4096 Apr 21 13:13 Rp7xfycKiF
drwxr-xr-x 2 compiler compiler 4096 Apr 21 13:13 VGL2RNn2j7
drwxr-xr-x 2 compiler compiler 4096 Apr 21 13:13 WTufTgioBX
drwxr-xr-x 2 compiler compiler 4096 Apr 21 13:12 X11DdGEb7L
drwxr-xr-x 2 compiler compiler 4096 Apr 21 13:12 ZQPoGUoy2D
-rw------- 1 compiler compiler    0 Apr 21 13:13 ccZKMuGd.s
-rw------- 1 compiler compiler    0 Apr 21 13:13 ccl9Vsz1.s
prw-r--r-- 1 compiler compiler    0 Apr 21 09:59 fifo
drwxr-xr-x 2 compiler compiler 4096 Apr 21 13:13 kk7txJ7Pji
drwxr-xr-x 3 compiler compiler 4096 Apr 21 08:57 pkg
drwxr-xr-x 2 compiler compiler 4096 Apr 21 13:12 sKX1aqUYNd
drwxr-xr-x 2 compiler compiler 4096 Apr 21 13:10 uKfjY3GTdO
Child 3: Execute the command 'ls -l /tmp'
total 52
drwxr-xr-x 2 compiler compiler 4096 Apr 21 13:12 4L24cucsCz
drwxr-xr-x 2 compiler compiler 4096 Apr 21 13:13 722nx9yuCT
drwxr-xr-x 2 compiler compiler 4096 Apr 21 13:13 LriY70ay9m
drwxr-xr-x 2 compiler compiler 4096 Apr 21 13:13 MCkt5fbhjW
drwxr-xr-x 2 compiler compiler 4096 Apr 21 13:13 Rp7xfycKiF
drwxr-xr-x 2 compiler compiler 4096 Apr 21 13:13 VGL2RNn2j7
drwxr-xr-x 2 compiler compiler 4096 Apr 21 13:13 WTufTgioBX
drwxr-xr-x 2 compiler compiler 4096 Apr 21 13:12 X11DdGEb7L
drwxr-xr-x 2 compiler compiler 4096 Apr 21 13:12 ZQPoGUoy2D
-rw------- 1 compiler compiler    0 Apr 21 13:13 ccZKMuGd.s
-rw------- 1 compiler compiler    0 Apr 21 13:13 ccl9Vsz1.s
prw-r--r-- 1 compiler compiler    0 Apr 21 09:59 fifo
drwxr-xr-x 2 compiler compiler 4096 Apr 21 13:13 kk7txJ7Pji
drwxr-xr-x 3 compiler compiler 4096 Apr 21 08:57 pkg
drwxr-xr-x 2 compiler compiler 4096 Apr 21 13:12 sKX1aqUYNd
drwxr-xr-x 2 compiler compiler 4096 Apr 21 13:10 uKfjY3GTdO
Child 4: Execute the command 'ls -l /tmp'
total 56
drwxr-xr-x 2 compiler compiler 4096 Apr 21 13:12 4L24cucsCz
drwxr-xr-x 2 compiler compiler 4096 Apr 21 13:13 722nx9yuCT
drwxr-xr-x 2 compiler compiler 4096 Apr 21 13:13 LriY70ay9m
drwxr-xr-x 2 compiler compiler 4096 Apr 21 13:13 MCkt5fbhjW
drwxr-xr-x 2 compiler compiler 4096 Apr 21 13:13 Rp7xfycKiF
drwxr-xr-x 2 compiler compiler 4096 Apr 21 13:13 VGL2RNn2j7
drwxr-xr-x 2 compiler compiler 4096 Apr 21 13:13 WTufTgioBX
drwxr-xr-x 2 compiler compiler 4096 Apr 21 13:12 X11DdGEb7L
drwxr-xr-x 2 compiler compiler 4096 Apr 21 13:12 ZQPoGUoy2D
-rw------- 1 compiler compiler    0 Apr 21 13:13 ccFPicZe.o
-rw------- 1 compiler compiler  908 Apr 21 13:13 ccZKMuGd.s
-rw------- 1 compiler compiler    0 Apr 21 13:13 ccl9Vsz1.s
prw-r--r-- 1 compiler compiler    0 Apr 21 09:59 fifo
drwxr-xr-x 2 compiler compiler 4096 Apr 21 13:13 kk7txJ7Pji
drwxr-xr-x 3 compiler compiler 4096 Apr 21 08:57 pkg
drwxr-xr-x 2 compiler compiler 4096 Apr 21 13:12 sKX1aqUYNd
drwxr-xr-x 2 compiler compiler
```


# **Tools to help**
Approaching a Project [Holberton Pages](https://github.com/N4yth/holbertonschool-simple_shell/blob/ingrid/Images/Approaching%20a%20Project.png)
