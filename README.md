# simple_shell

### Introduction
This repository was created in December 2016 while the authors were students at [Holberton School](https://www.holbertonschool.com/). The school project consisted in writing a shell, in **C**, using a limited number of standard library functions, if we needed them, we had to rewrite them as the school focuses on learning by doing. It lasted 11 days.  
The goal in this project was to make us understand how a shell works. To single out some items: what is the *environment*, the difference between *functions* and *system calls*, how to create *processes* using `execve`...  
In order to run this program, after you download the code you can compile it with  
`gcc 4.8.4 -Wall -Werror -Wextra -pedantic *.c -o simple_shell`.  
You can then run it by invoking `./simple_shell` in that same directory.  

###How to use it
In order to use this shell, in a terminal, first run the program:    
`prompt$ ./simple_shell`  
It wil then display a simple prompt and wait for commands.  
`$ `   
A command will be of the type `$ commandname argument`  
This shell can handle two types of commands: builtins and normal program.

#####Built-ins and normal programs
Commands will be searched by their name in that order. Shell built-ins will be executed internally while normal programs will spawn a new (child) process.
If for example the `commandname` is `env`, the simple shell will first look through the (linked) list of built-ins, find it and then run the matching function. If the `commandname` is `ls`, the simple shell will not find that name among the built-ins. It will then proceed to look for an entry with that name in the paths listed `$PATH` variable. It will find it in `/bin` and so the simple shell will create a child process to run `/bin/ls`.

#####List of built-ins
Currently the list of built-ins we wrote is:  
* cd [directory]  
Switch to the specified directory (path).
* env  
Displays the environment variable
* exit [exitstatus]  
Exit from the program with exitstatus value. 0 by default.
* getenv NAME  
Return the value of the NAME variable if it is in the environment
* help [command]  
Displays the syntax for the command, or all commands.  
* history  
Displays the last 1000 commands.  
* setenv NAME VALUE  
Sets or replace the environment variable NAME with valur VALUE.  
* unsetenv NAME  
Unsets the environment variable NAME  

###Some particular files
The repository contains a large number of files, as many files contain only one function.  
Some have self-explanatory terms, others look like standard library function names. The Latter are our version of them.
We in particular had to rewrite `getline` from the standard library to use a buffer and limit the number of system calls. 

###List of functions and system calls we could use
List of allowed functions and system calls

    access (man 2 access)
    chdir (man 2 chdir)
    close (man 2 close)
    closedir (man 3 closedir)
    execve (man 2 execve)
    exit (man 3 exit)
    fork (man 2 fork)
    free (man 3 free)
    fstat (man 2 fstat)
    getcwd (man 3 getcwd)
    getline (man 3 getline)
    kill (man 2 kill)
    lstat (man 2 lstat)
    malloc (man 3 malloc)
    open (man 2 open)
    opendir (man 3 opendir)
    perror (man 3 perror)
    read (man 2 read)
    readdir (man 3 readdir)
    signal (man 2 signal)
    stat (man 2 stat)
    strtok (man 3 strtok)
    wait (man 2 wait)
    waitpid (man 2 waitpid)
    wait3 (man 2 wait3)
    wait4 (man 2 wait4)
    write (man 2 write)
    _exit (man 2 _exit)
