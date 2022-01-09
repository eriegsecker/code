# makefile for day 3 of aoc 2021

CC = gcc
FLAGS = -std=gnu99 -g
INCLUDES = ../../utils/file_utils/file_utils.o \
	   ../../utils/string_utils/string_utils.o
LINK = -Wall -lm

day3.exe: day3.c
	$(CC) $(FLAGS) $(INCLUDES) day3.c -o day3.exe $(LINK)

clean:
	rm -Rf *.exe
