/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:13:34 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/02 00:47:21 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*=================================| LIBFT |==================================*/

#ifndef LIBFT_H
# define LIBFT_H

/*===============================| LIBRARIES |================================*/

# include <ctype.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <unistd.h>

/*===========================| MACRO DEFINITIONS |============================*/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
#  define FALSE 0
#  define TRUE 1
# endif

// Default color:
# define DEF "\033[0m"

// Regular colors (also works with "\033[3Xm" [X for color number]):
# define BLA "\033[0;30m"
# define RED "\033[0;31m"
# define GRE "\033[0;32m"
# define YEL "\033[0;33m"
# define BLU "\033[0;34m"
# define MAG "\033[0;35m"
# define CYA "\033[0;36m"
# define WHI "\033[0;37m"

// Light colors:
# define BLA_LIGH "\033[90m"
# define RED_LIGH "\033[91m"
# define GRE_LIGH "\033[92m"
# define YEL_LIGH "\033[93m"
# define BLU_LIGH "\033[94m"
# define MAG_LIGH "\033[95m"
# define CYA_LIGH "\033[96m"
# define WHI_LIGH "\033[97m"

// Bold colors:
# define BLA_BOLD "\033[30;1m"
# define RED_BOLD "\033[31;1m"
# define GRE_BOLD "\033[32;1m"
# define YEL_BOLD "\033[33;1m"
# define BLU_BOLD "\033[34;1m"
# define MAG_BOLD "\033[35;1m"
# define CYA_BOLD "\033[36;1m"
# define WHI_BOLD "\033[37;1m"

// Faint colors:
# define BLA_FAIN "\033[30;2m"
# define RED_FAIN "\033[31;2m"
# define GRE_FAIN "\033[32;2m"
# define YEL_FAIN "\033[33;2m"
# define BLU_FAIN "\033[34;2m"
# define MAG_FAIN "\033[35;2m"
# define CYA_FAIN "\033[36;2m"
# define WHI_FAIN "\033[37;2m"

// Italicized text:
# define BLA_ITAL "\033[30;3m"
# define RED_ITAL "\033[31;3m"
# define GRE_ITAL "\033[32;3m"
# define YEL_ITAL "\033[33;3m"
# define BLU_ITAL "\033[34;3m"
# define MAG_ITAL "\033[35;3m"
# define CYA_ITAL "\033[36;3m"
# define WHI_ITAL "\033[37;3m"

// Underlined text:
# define BLA_LINE "\033[30;4m"
# define RED_LINE "\033[31;4m"
# define GRE_LINE "\033[32;4m"
# define YEL_LINE "\033[33;4m"
# define BLU_LINE "\033[34;4m"
# define MAG_LINE "\033[35;4m"
# define CYA_LINE "\033[36;4m"
# define WHI_LINE "\033[37;4m"

// Slow blinking text:
# define BLA_SLOW "\033[30;5m"
# define RED_SLOW "\033[31;5m"
# define GRE_SLOW "\033[32;5m"
# define YEL_SLOW "\033[33;5m"
# define BLU_SLOW "\033[34;5m"
# define MAG_SLOW "\033[35;5m"
# define CYA_SLOW "\033[36;5m"
# define WHI_SLOW "\033[37;5m"

// Fast blinking text:
# define BLA_FAST "\033[30;6m"
# define RED_FAST "\033[31;6m"
# define GRE_FAST "\033[32;6m"
# define YEL_FAST "\033[33;6m"
# define BLU_FAST "\033[34;6m"
# define MAG_FAST "\033[35;6m"
# define CYA_FAST "\033[36;6m"
# define WHI_FAST "\033[37;6m"

// Negative text:
# define BLA_NEGA "\033[30;7m"
# define RED_NEGA "\033[31;7m"
# define GRE_NEGA "\033[32;7m"
# define YEL_NEGA "\033[33;7m"
# define BLU_NEGA "\033[34;7m"
# define MAG_NEGA "\033[35;7m"
# define CYA_NEGA "\033[36;7m"
# define WHI_NEGA "\033[37;7m"

/*============================| TYPE DEFINITIONS |============================*/

typedef struct s_list
{
	struct s_list	*next;
	void			*content;
}			t_list;

/*===============================| FUNCTIONS |================================*/

char	*ft_itoa(int n);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *nptr);
int		ft_fbool(int boolean);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strbcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_tolower(int c);
int		ft_toupper(int c);
long	ft_atol(const char *nptr);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_eof(int fd);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

/*=========================| LINKED LIST FUNCTIONS |==========================*/

int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);

/*===========================| PRINTF FUNCTIONS |=============================*/

int		ft_printf(const char *str, ...);
int		pf_int(int num);
int		pf_lohex(unsigned int num);
int		pf_memadd(void *mem);
int		pf_str(const char *str);
int		pf_ucheck(int total);
int		pf_uphex(unsigned int num);
int		pf_uint(unsigned int num);
int		pf_write(unsigned char letter);

/*========================| GET_NEXT_LINE FUNCTIONS |=========================*/

char	*get_next_line(int fd);
char	*gnl_get_string(int fd, char *s_ptr);
char	*gnl_trim_string(char *s_ptr, char *ptr);

/*===============================| LIBFT END |================================*/

#endif

/*==================================| EOF |===================================*/
