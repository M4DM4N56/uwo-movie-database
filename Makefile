CC = gcc
CFLAGS = -Wall

all: movieTheaterDB

movieTheaterDB: movieTheaterDB.c movieTheaterDB_movie.c movieTheaterDB_actor.c
	$(CC) $(CFLAGS) -o movieTheaterDB movieTheaterDB.c movieTheaterDB_movie.c movieTheaterDB_actor.c

clean:
	rm -f movieTheaterDB
