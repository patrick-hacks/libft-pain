// Copyright 2022
// Author: pfuchs

#ifndef SRC_UNITTESTS_LIBFT_H_
#define SRC_UNITTESTS_LIBFT_H_

#include <stddef.h>

typedef struct s_list {
  void *content;
  struct s_list *next;
} t_list;

extern "C" {

int ft_isalnum(int c);
int ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isprint(int c);
int ft_isascii(int c);
int ft_tolower(int c);
int ft_toupper(int c);
int ft_atoi(const char *str);

int ft_atoi(const char *str);
void *ft_calloc(size_t nitems, size_t size);
void *ft_memcpy(void *dest, const void *src, size_t n);
void *ft_memmove(void *dest, const void *src, size_t n);
void *ft_memset(void *mem, int c, size_t n);
void *ft_memchr(const void *hay, int c, size_t n);
int ft_memcmp(const void *mem1, const void *mem2, size_t n);
size_t ft_strlen(const char *str);
int ft_strncmp(const char *s1, const char *s2, size_t n);
char *ft_strchr(const char *str, int c);
char *ft_strrchr(const char *s, int c);
char *ft_strnstr(const char *hay, const char *needle, size_t n);
void ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t ft_strlcat(char *dest, const char *src, size_t n);
size_t ft_strlcpy(char *dest, const char *src, size_t n);
char *ft_strdup(const char *str);
char *ft_substr(char const *str, unsigned int start, size_t len);
char *ft_strjoin(char const *str1, char const *str2);
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
char **ft_split(char const *s, char c);
char *ft_strtrim(const char *str, const char *set);
void ft_putchar_fd(char c, int fd);
void ft_putendl_fd(const char *s, int fd);
void ft_putnbr_fd(int n, int fd);
void ft_putstr_fd(const char *s, int fd);
char *ft_itoa(int n);
void ft_bzero(void *mem, size_t n);
t_list *ft_lstnew(const void *content);
void ft_lstadd_front(t_list **lst, t_list *new_node);
int ft_lstsize(t_list *lst);
t_list *ft_lstlast(t_list *lst);
void ft_lstadd_back(t_list **lst, t_list *new_node);
void ft_lstdelone(t_list *lst, void (*del)(void *));
void ft_lstclear(t_list **lst, void (*del)(void *));
void ft_lstiter(t_list *lst, void (*f)(void *));
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
}

#endif  // SRC_UNITTESTS_LIBFT_H_
