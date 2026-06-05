# This is a guide on how to use this starter raylib template

Normally put all your code into main.cpp
Start your code with **F5**

# Modifications

## /src 

If you want to put your code into a src folder, navigate to .vscode and to tasks
Change every:

`"OBJS=${fileBasenameNoExtension}.cpp"` 

to 

`"OBJS=src/${fileBasenameNoExtension}.cpp"`

## C++ --> C

Open the Makefile file, and find `CC = g++` 

Change it to: `CC = gcc

*and maybe more but I am not sure right now.*`