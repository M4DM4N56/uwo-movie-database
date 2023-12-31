cmake_minimum_required(VERSION 3.26)
project(Assignment5 C)

set(CMAKE_C_STANDARD 11)

add_executable(Assignment5
    movieTheaterDB.c
    # movieTheaterDB.h
    movieTheaterDB_actor.c
    movieTheaterDB_actor.h
    movieTheaterDB_movie.c
    movieTheaterDB_movie.h
    )

