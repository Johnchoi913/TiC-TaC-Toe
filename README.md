# Tic Tac Toe Project
I am making a tic tac toe program in C that will work off the terminal

## Why?
Because I wish to relearn C and make sure I still have a good grasp of C

## Some Notes
- I added the math linker, as of yet I don't use it but I do have plans for it
- The Makefile does not have a clean nor does use the compiler flag for checking memory leaks as I'm working on a Windows Device and once I expand my storage I will add WSL and change the make file
- As this is a windows device to pipe in the testfiles in powershell you can't use ./main < ../test/test1 and instead you must use Get-Content ..\test\test1 | .\main.exe