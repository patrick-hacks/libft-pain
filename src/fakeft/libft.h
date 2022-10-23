// Copyright 2022
// Author: pfuchs

#ifndef SRC_FAKEFT_LIBFT_H_
#define SRC_FAKEFT_LIBFT_H_

#include <assert.h>
#include <stddef.h>

extern "C" {

typedef struct s_list {
  void *content;
  struct s_list *next;
} t_list;

int ft_isalnum(int c) __attribute__((weak));
int ft_isalpha(int c) __attribute__((weak));
int ft_isdigit(int c) __attribute__((weak));
int ft_isprint(int c) __attribute__((weak));
int ft_isascii(int c) __attribute__((weak));
int ft_tolower(int c) __attribute__((weak));
int ft_toupper(int c) __attribute__((weak));
int ft_atoi(const char *str) __attribute__((weak));

int ft_atoi(const char *str) __attribute__((weak));
void *ft_calloc(size_t nitems, size_t size) __attribute__((weak));
void *ft_memcpy(void *dest, const void *src, size_t n) __attribute__((weak));
void *ft_memmove(void *dest, const void *src, size_t n) __attribute__((weak));
void *ft_memset(void *mem, int c, size_t n) __attribute__((weak));
void *ft_memchr(const void *hay, int c, size_t n) __attribute__((weak));
int ft_memcmp(const void *mem1, const void *mem2, size_t n)
    __attribute__((weak));
size_t ft_strlen(const char *str) __attribute__((weak));
int ft_strncmp(const char *s1, const char *s2, size_t n) __attribute__((weak));
char *ft_strchr(const char *str, int c) __attribute__((weak));
char *ft_strrchr(const char *s, int c) __attribute__((weak));
char *ft_strnstr(const char *hay, const char *needle, size_t n)
    __attribute__((weak));
void ft_striteri(char *s, void (*f)(unsigned int, char *))
    __attribute__((weak));
size_t ft_strlcat(char *dest, const char *src, size_t n) __attribute__((weak));
size_t ft_strlcpy(char *dest, const char *src, size_t n) __attribute__((weak));
char *ft_strdup(const char *str) __attribute__((weak));
char *ft_substr(char const *str, unsigned int start, size_t len)
    __attribute__((weak));
char *ft_strjoin(char const *str1, char const *str2) __attribute__((weak));
char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
    __attribute__((weak));
char **ft_strsplit(char const *s, const char *set) __attribute__((weak));
char *ft_strtrim(const char *str, const char *set) __attribute__((weak));
void ft_putchar_fd(char c, int fd) __attribute__((weak));
void ft_putendl_fd(const char *s, int fd) __attribute__((weak));
void ft_putnbr_fd(int n, int fd) __attribute__((weak));
void ft_putstr_fd(const char *s, int fd) __attribute__((weak));
char *ft_itoa(int n) __attribute__((weak));
void ft_bzero(void *mem, size_t n) __attribute__((weak));
t_list *ft_lstnew(void *content) __attribute__((weak));
void ft_lstadd_front(t_list **lst, t_list *new_node) __attribute__((weak));
int ft_lstsize(t_list *lst) __attribute__((weak));
t_list *ft_lstlast(t_list *lst) __attribute__((weak));
void ft_lstadd_back(t_list **lst, t_list *new_node) __attribute__((weak));
void ft_lstdelone(t_list *lst, void (*del)(void *)) __attribute__((weak));
void ft_lstclear(t_list **lst, void (*del)(void *)) __attribute__((weak));
void ft_lstiter(t_list *lst, void (*f)(void *)) __attribute__((weak));
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
    __attribute__((weak));
}

#endif  // SRC_FAKEFT_LIBFT_H_
