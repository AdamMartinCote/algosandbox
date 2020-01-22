cmake_minimum_required(VERSION 3.15)
project(hello_c C)

set(CMAKE_C_STANDARD 99)

add_executable(hello_c src/main.c src/datastructures/linkedlist.h src/nchoosek/nchoosek.h src/nchoosek/nchoosek.c utils/utils.c src/sparechange/spacechange.h src/sparechange/sparechange.c src/datastructures/graph/graph.h src/datastructures/graph/graph.c src/substring/substring.c src/substring/substring.h src/datastructures/linkedlist/linkedlist.c src/datastructures/linkedlist/linkedlist.h test/main.c)
