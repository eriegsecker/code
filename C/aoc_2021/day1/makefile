# sample makefile

CC = gcc
FLAGS = -std=gnu99 -g
INCLUDES = ../../utils/file_utils/file_utils.o
LINK = -Wall -lm

day1.exe: day1.c
	$(CC) $(FLAGS) $(INCLUDES) day1.c -o day1.exe $(LINK)

clean:
	rm -Rf *.exe
