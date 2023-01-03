#include "s21_cat.h"

int main(int argc, char* argv[]) {
    int error = 0;
    int count = 1;
    int* p_count = &count;
    struct Flags flag;
    flags_init(&flag);

    if (argc > 1) {
        int argc_count = 1;
        while (argv[argc_count] != NULL) {
            if (argv[argc_count][0] == '-') {
                error = flags_check(&flag, argv, argc_count);
                memset(argv[argc_count], '\0', strlen(argv[argc_count]));
            }
            if (error == 1) {
                fprintf(stderr, "OPTION ERROR\n");
                break;
            }
            argc_count++;
        }

        if (flag.b_flag == 1) {
            flag.n_flag = 0;
        }

        if (error == 0) {
            int arg_count = 1;
            while (argv[arg_count] != NULL) {
                if (argv[arg_count][0] != '\0') {
                    if (TUNING == 1) {*p_count = 1;}
                    FILE* f;
                    f = fopen(argv[arg_count], "r");
                    if (f != NULL) {
                        cat_print(f, &flag, p_count);
                        fclose(f);
                    } else {
                        fprintf(stderr, "mycat: Can`t open file \"%s\"\n", argv[arg_count]);
                    }
                }
                arg_count++;
            }
        }
    }
    return error;
}

void cat_print(FILE* f, struct Flags* flag, int* p_count) {
    char print_c = getc(f);
    char fut_c = '\0';
    if (print_c != EOF) {
        if (flag->super == 0 && (flag->n_flag == 1 || flag->b_flag == 1)) {
            printf("%6d\t", *p_count);
            flag->super = 1;
            (*p_count)++;
        }
        for (; fut_c != EOF;) {
            fut_c = getc(f);
            if (flag->s_flag == 1 && (print_c == '\n' && fut_c == '\n')) {
                fut_c = squeeze(print_c, fut_c, f, flag, p_count);
            }
            if (((print_c >= 0 && print_c < 32) || print_c == 127) && flag->v_flag == 1) {
                if (print_c == '\n') {
                    printf("\n");
                } else if (print_c == 127) {
                    printf("^%c", print_c - 64);
                } else if (print_c == '\t' && flag->t_flag == 0) {
                    printf("\t");
                } else {
                    printf("^%c", print_c + 64);
                }
            } else if (flag->t_flag == 1 && print_c == '\t') {
                printf("^I");
            } else {
                printf("%c", print_c);
                }
            if (flag->e_flag == 1) {end(fut_c);}
            if (!(print_c == '\n' && fut_c == EOF)) {
                if (flag->b_flag == 1 && flag->super == 1) {number_b(print_c, fut_c, p_count);}
                if ((flag->n_flag == 1) && flag->super == 1) {number(print_c, p_count);}
            } else {flag->super = 0;}
            print_c = fut_c;
        }
    }
}

void end(char ft_c) {
    if (ft_c == '\n') {
        printf("%c", '$');
    }
}

void number_b(char pr_c, char fut_c, int* p_count) {
    if (pr_c == '\n') {
        if (!(pr_c == '\n' && fut_c == '\n')) {
            printf("%6d\t", *p_count);
            (*p_count)++;
        }
    }
}

void number(char pr_c, int* p_count) {
    if (pr_c == '\n') {
        printf("%6d\t", *p_count);
        (*p_count)++;
    }
}

char squeeze(char pr_c, char ft_c, FILE* f, struct Flags* flag, int* p_count) {
    if (pr_c == '\n' && ft_c == '\n') {
        while (ft_c == '\n') {
            ft_c = getc(f);
        }
        printf("\n");
        if (flag->e_flag == 1) {
            printf("%c", '$');
        }
        if (flag->n_flag == 1) {
            printf("%6d\t", *p_count);
            (*p_count)++;
        }
    }
    return ft_c;
}
int flags_check(struct Flags* flag, char** argv, int count) {
    int error = 0;
    for (int i = 1; i < (int)strlen(argv[count]); i++) {
        if (argv[count][i] == 'b') {
            flag->b_flag = 1;
        } else if (argv[count][i] == 'e') {
            flag->e_flag = 1;
            flag->v_flag = 1;
        } else if (argv[count][i] == 'E') {
            flag->e_flag = 1;
        } else if (argv[count][i] == 'v') {
            flag->v_flag = 1;
        } else if (argv[count][i] == 'n') {
            flag->n_flag = 1;
        } else if (argv[count][i] == 's') {
            flag->s_flag = 1;
        } else if (argv[count][i] == 'T') {
            flag->t_flag = 1;
        } else if (argv[count][i] == 't') {
            flag->t_flag = 1;
            flag->v_flag = 1;
        } else {
            if (argv[count][1] == '-' && strcmp(argv[count], "--number-nonblank") == 0) {
                flag->b_flag = 1;
                break;
            } else if (argv[count][1] == '-' && strcmp(argv[count], "--number") == 0) {
                flag->n_flag = 1;
                break;
            } else if (argv[count][1] == '-' && strcmp(argv[count], "--squeeze-blank") == 0) {
                flag->s_flag = 1;
                break;
            } else {
                error = 1;
                break;
            }
        }
    }
    return error;
}

void flags_init(struct Flags* flag) {
    flag->b_flag = 0;
    flag->e_flag = 0;
    flag->n_flag = 0;
    flag->v_flag = 0;
    flag->s_flag = 0;
    flag->t_flag = 0;
    flag->super = 0;
}
