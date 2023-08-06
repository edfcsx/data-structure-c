cmake_minimum_required(VERSION 3.25)
project(Estruturas_de_dados_em_c C)

set(CMAKE_C_STANDARD 11)

add_executable(Estruturas_de_dados_em_c main.c stack.h linked_list.h types.h stack.c linked_list.c queue.h queue.c)
