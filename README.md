# simple_shell

### Introduction
This repository was created in December 2016 while the authors were students at [Holberton School](https://www.holbertonschool.com/). The school project consisted in writing a shell, in **C**, using a limited number of standard library functions. It lasted 11 days.  
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
If for example the `commandname` is `env`, the simple shell will first look through the (linked) list of built-ins, find it and then run the matching function. If the `commandname` is `ls`, the simple shell will not find that name among the built-ins. It will the proceed to look for an entry with that name in the paths listed `$PATH` variable. It will find it in `/bin` and so the simple shell will create a child process to run `/bin/ls`.
#####List of built-ins
Currently the list of built-ins is:  
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

