# makefile for day 2 aoc 2021 
CC = gcc
FLAGS = -std=gnu99 -g
INCLUDES = ../../utils/file_utils/file_utils.o ../../utils/string_utils/string_utils.o
LINK = -Wall -lm

day2.exe: day2.c
	$(CC) $(FLAGS) $(INCLUDES) day2.c -o day2.exe $(LINK)

clean:
	rm -Rf *.exe
