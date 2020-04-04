# # A simple Makefile for CPSC 350
# # Assumes the following directory hierarchy:
# # Assignment X
# # 	src
# #       include

# #this Makefile goes in the src directory

# #change this to the correct assignment #
# EXECUTABLE := assignment3

# # the source files to be built
# SOURCES := *.cpp

# #stuff you don't need to worry about
# INCLUDES := -I ../include
# EXT := exe
# CC := g++

# all:
# 	$(CC) $(INCLUDES) $(SOURCES) -o $(EXECUTABLE).$(EXT)

# # this line required by make - don't delete

all: main.cpp #make all is default - if any of files listed change, do this thing
	g++ $< -o SyntaxChecker.exe

realclean:
	find . -type f -name "*.o" -exec rm '{}' \;
	find . -type f -name "*.exe" -exec rm '{}' \;
	find . -type f -name "*.txt" -exec rm '{}' \;