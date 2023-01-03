#ifndef SRC_CAT_S21_CAT_H_
#define SRC_CAT_S21_CAT_H_

#if defined(__APPLE__) && defined(__MACH__)
    #define TUNING 1
#elif defined(__linux__)
    #define TUNING 0
#endif

#include <stdio.h>
#include <string.h>

struct Flags {
    int b_flag;
    int v_flag;
    int e_flag;
    int n_flag;
    int s_flag;
    int t_flag;
    int super;
};

void end(char ft_c);
void number_b(char pr_c, char fut_c, int* p_count);
void number(char pr_c, int* p_count);
char squeeze(char pr_c, char ft_c, FILE* f, struct Flags* flag, int* p_count);
void cat_print(FILE* f, struct Flags* flag, int* p_count);
void flags_init(struct Flags* flag);
int flags_check(struct Flags* flag, char** argv, int count);

#endif  // SRC_CAT_S21_CAT_H_
