// Copyright 2022
// Author: pfuchs

#include "src/fakeft/libft.h"

#include <stdlib.h>

extern "C" {

int ft_isalnum(int c) { abort(); }
int ft_isalpha(int c) { abort(); }
int ft_isdigit(int c) { abort(); }
int ft_isprint(int c) { abort(); }
int ft_isascii(int c) { abort(); }
int ft_tolower(int c) { abort(); }
int ft_toupper(int c) { abort(); }
int ft_atoi(const char *str) { abort(); }
void *ft_calloc(size_t nitems, size_t size) { abort(); }
void *ft_memcpy(void *dest, const void *src, size_t n) { abort(); }
void *ft_memmove(void *dest, const void *src, size_t n) { abort(); }
void *ft_memset(void *mem, int c, size_t n) { abort(); }
void *ft_memchr(const void *hay, int c, size_t n) { abort(); }
int ft_memcmp(const void *mem1, const void *mem2, size_t n) { abort(); }
size_t ft_strlen(const char *str) { abort(); }
int ft_strncmp(const char *s1, const char *s2, size_t n) { abort(); }
char *ft_strchr(const char *str, int c) { abort(); }
char *ft_strrchr(const char *s, int c) { abort(); }
char *ft_strnstr(const char *hay, const char *needle, size_t n) { abort(); }
void ft_striteri(char *s, void (*f)(unsigned int, char *)) { abort(); }
size_t ft_strlcat(char *dest, const char *src, size_t n) { abort(); }
size_t ft_strlcpy(char *dest, const char *src, size_t n) { abort(); }
char *ft_strdup(const char *str) { abort(); }
char *ft_substr(char const *str, unsigned int start, size_t len) { abort(); }
char *ft_strjoin(char const *str1, char const *str2) { abort(); }
char *ft_strmapi(char const *s, char (*f)(unsigned int, char)) { abort(); }
char **ft_split(char const *s, const char *set) { abort(); }
char *ft_strtrim(const char *str, const char *set) { abort(); }
void ft_putchar_fd(char c, int fd) { abort(); }
void ft_putendl_fd(const char *s, int fd) { abort(); }
void ft_putnbr_fd(int n, int fd) { abort(); }
void ft_putstr_fd(const char *s, int fd) { abort(); }
char *ft_itoa(int n) { abort(); }
void ft_bzero(void *mem, size_t n) { abort(); }
t_list *ft_lstnew(void *content) { abort(); }
void ft_lstadd_front(t_list **lst, t_list *new_node) { abort(); }
int ft_lstsize(t_list *lst) { abort(); }
t_list *ft_lstlast(t_list *lst) { abort(); }
void ft_lstadd_back(t_list **lst, t_list *new_node) { abort(); }
void ft_lstdelone(t_list *lst, void (*del)(void *)) { abort(); }
void ft_lstclear(t_list **lst, void (*del)(void *)) { abort(); }
void ft_lstiter(t_list *lst, void (*f)(void *)) { abort(); }
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *)) {
  abort();
}
}
