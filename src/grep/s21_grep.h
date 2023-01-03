#ifndef SRC_GREP_S21_GREP_H_
#define SRC_GREP_S21_GREP_H_

#if defined(__APPLE__) && defined(__MACH__)
    #define TUNING "|"
#elif defined(__linux__)
    #define TUNING "\\|"
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>

struct Flags {
    int e;
    int f;
    int v;
    int i;
    int h;
    int l;
    int c;
    int n;
    int o;
    int s;
    int yes;
};

void main_print(char* search_string, char** argv, struct Flags* flag);
void find_search_string(char* search_string, char** argv);
void f_func(char* search_string, char** argv);
void e_func(char* search_string, char** argv);
int file_count(char** argv);
int find_arg_count(char** argv, int count);
void flags_init(struct Flags* flag);
int flags_check(struct Flags* flag, char** argv, int count);
void o_print(char* tmp_line, char* search_string);


#endif  // SRC_GREP_S21_GREP_H_
