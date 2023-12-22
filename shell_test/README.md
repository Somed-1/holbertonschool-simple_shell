# SIMPLE SHELL

## How it works

### shell.c
- Main file that runs program
- syscall getline to read user input
- check spaces function, if the input of user contains only spaces, nothing will happen and free user input line
- user input will be splited by split line function
- if anything go wrong error appears and all memory will be freed
