/*
** EPITECH PROJECT, 2019
** my
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <unistd.h>
#include <stdlib.h>

int my_putchar(char c);
int my_putstr(char *str);
int my_putnbr(int nb);
int my_printf(char *form, ...);

char *my_revstr(char *str);
char *my_strcat(char *str1, char *str2);
char *my_strncat(char *str1, char *str2, int nb);
char *my_strnncat(int start, int end, char *str, char *add_str);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
char *concat_params(int ac, char **av);
char *my_itoa(int nb);
char *my_strdup(char *src);
char *my_strcpy(char *src);
char *my_strncpy(char *dest, char const *src, int n);
int my_mstrcpy(char **dest, char *src);
int my_mstrncpy(char **dest, char *src, int n);
void my_memset(char **str, char c, int len);
int my_realloc(char **str, int size);
char *my_replacestr(char *str, char *fromstr, char *tostr);
char *clean_str(char *str, char *list_char, char to_char);

int my_strlen(char *str);
int my_charisalpha(char const str);
int my_charisnum(char const str);
int my_str_isalpha(char const *str);
int my_str_isnum_with_add_and_sub(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);

char *get_next_line(int fd);

int my_isneg(int nb);
int my_getnbr(char const *str);
int my_power(int nb, int p);
int my_sqrt(int nb);

#endif /* !MY_H_ */
