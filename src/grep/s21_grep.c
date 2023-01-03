#include "s21_grep.h"


int main(int argc, char* argv[]) {
    int error = 0;
    struct Flags flag;
    flags_init(&flag);

    if (argc > 1) {
        int arrg_count = 1;
        while (argv[arrg_count] != NULL) {
            if (argv[arrg_count][0] == '-') {
                error = flags_check(&flag, argv, arrg_count);
                memset(argv[arrg_count], '\0', strlen(argv[arrg_count]));
            }
            if (error == 1) {
                fprintf(stderr, "OPTION ERROR\n");
                break;
            }
            arrg_count++;
        }

        char search_string[8192] = {0};
        if (error == 0) {
            if (flag.e == 1) {
                e_func(search_string, argv);
            } else if (flag.f == 1) {
                f_func(search_string, argv);
            } else {
                find_search_string(search_string, argv);
            }
            main_print(search_string, argv, &flag);
        }
    }
    return error;
}

void main_print(char* search_string, char** argv, struct Flags* flag) {
    int f_count = file_count(argv);
    int arg_count = find_arg_count(argv, 0);
    while (argv[arg_count] != NULL) {
        if (argv[arg_count][0] != '\0') {
            FILE* f;
            f = fopen(argv[arg_count], "r");
            if (f != NULL) {
                regex_t regex;
                int regflag = 0;
                char* tmp_line = NULL;
                long unsigned int len = 0;
                int success = 0;
                int red = 0;
                int compare = 0;
                int str_count = 1;
                int over = 0;
                int count_success = 0;
                if (flag->v == 1) {compare = REG_NOMATCH;}
                if (flag->i == 1) {regflag = REG_ICASE;}
                if (flag->e == 1) {regflag = REG_EXTENDED;}
                regcomp(&regex, search_string, regflag);
                while (red != EOF && over != 1) {
                    red = getline(&tmp_line, &len, f);
                    if (tmp_line && red != EOF) {
                        success = regexec(&regex, tmp_line, 0, NULL, 0);
                        if (success == 0) {count_success++;}
                        if (success == compare && flag->v == 1) {
                            if (f_count > 1 && flag->h == 0) {printf("%s:", argv[arg_count]);}
                            printf("%s", tmp_line);
                        } else if (success == 0 && flag->l == 1) {
                            printf("%s\n", argv[arg_count]);
                            over = 1;
                        } else if (success == 0 && compare == 0 && flag->c == 0) {
                            if (f_count > 1 && flag->h == 0) {printf("%s:", argv[arg_count]);}
                            if (flag->o == 1) {
                                o_print(tmp_line, search_string);
                            } else {
                                if (flag->n == 1) {
                                    printf("%d:", str_count);
                                }
                                printf("%s", tmp_line);
                            }
                        }
                    }
                    str_count++;
                }
                if (flag->c == 1) {
                    if (f_count > 1 && flag->h == 0) {printf("%s:", argv[arg_count]);}
                    printf("%d\n", count_success);
                }
                free(tmp_line);
                regfree(&regex);
                fclose(f);
            } else {
                if (flag->s == 0) {
                    fprintf(stderr, "mygrep: %s: No such file or directory\n", argv[arg_count]);
                }
            }
        }
        arg_count++;
    }
}

void find_search_string(char* search_string, char** argv) {
    int a = 1;
    while (a) {
        if (argv[a][0] != '\0') {
            strcpy(search_string, argv[a]);
            memset(argv[a], '\0', strlen(argv[a]));
            break;
        }
        a++;
    }
}

void f_func(char* search_string, char** argv) {
    int a = 0;
    char* tmp_line = NULL;
    long unsigned int len = 0;
    while (argv[a] != NULL) {
        if (argv[a][0] == '\0') {
            FILE* f;
            f = fopen(argv[a + 1], "r");
            if (f != NULL) {
                getline(&tmp_line, &len, f);
                if (tmp_line) {
                    strcat(search_string, tmp_line);
                    memset(argv[a + 1], '\0', strlen(argv[a + 1]));
                    fclose(f);
                    break;
                }
            }
            fclose(f);
        }
        a++;
    }
}

void e_func(char* search_string, char** argv) {
    int a = 0;
    int e_count = 0;
    while (argv[a] != NULL) {
        if (argv[a][0] == '\0') {
            e_count++;
            if (e_count > 1) {
                strcat(search_string, "|");
                strcat(search_string, argv[a + 1]);
                memset(argv[a + 1], '\0', strlen(argv[a + 1]));
            } else {
                strcat(search_string, argv[a + 1]);
                memset(argv[a + 1], '\0', strlen(argv[a + 1]));
            }
            a++;
        }
        a++;
    }
}

int file_count(char** argv) {
    int a = 1;
    int count = 0;
    while (argv[a] != NULL) {
        if (argv[a][0] != '\0') {
            count++;
        }
        a++;
    }
    return count;
}

int find_arg_count(char** argv, int count) {
    int b = 1;
    while (count == 0) {
        if (argv[b][0] != '\0') {
            count = b;
        }
        b++;
    }
    return count;
}

void o_print(char* tmp_line, char* search_string) {
    int count = 0;
    int n = strlen(search_string);
    while (tmp_line[count] != '\0') {
        if (memcmp(&tmp_line[count], search_string, n) == 0) {
            printf("%s\n", search_string);
        }
        count++;
    }
}

int flags_check(struct Flags* flag, char** argv, int count) {
    int error = 0;
    for (int i = 1; i < (int)strlen(argv[count]); i++) {
        if (argv[count][i] == 'e') {
            flag->e = 1;
        } else if (argv[count][i] == 'f') {
            flag->f = 1;
        } else if (argv[count][i] == 'v') {
            flag->v = 1;
        } else if (argv[count][i] == 'i') {
            flag->i = 1;
        } else if (argv[count][i] == 'h') {
            flag->h = 1;
        } else if (argv[count][i] == 'l') {
            flag->l = 1;
        } else if (argv[count][i] == 'c') {
            flag->c = 1;
        } else if (argv[count][i] == 'n') {
            flag->n = 1;
        } else if (argv[count][i] == 'o') {
            flag->o = 1;
        } else if (argv[count][i] == 's') {
            flag->s = 1;
        } else {
            error = 1;
            break;
        }
    }
    if (error == 0) {
        flag->yes = 1;
    }
    return error;
}

void flags_init(struct Flags* flag) {
    flag->e = 0;
    flag->f = 0;
    flag->v = 0;
    flag->i = 0;
    flag->h = 0;
    flag->l = 0;
    flag->c = 0;
    flag->n = 0;
    flag->o = 0;
    flag->s = 0;
    flag->yes = 0;
}
