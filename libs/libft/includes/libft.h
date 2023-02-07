/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 02:19:27 by larcrist          #+#    #+#             */
/*   Updated: 2022/11/17 15:04:18 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h> // write
# include <stdlib.h> // malloc(), free() and size_t
# include <stdarg.h> // variadic functions

// buffer_size of gnl
# define BUFFER_SIZE	1024

// hexadecimal of ft_printf - putptr, puthexa
# define HEX_LOWCASE "0123456789abcdef"
# define HEX_UPCASE  "0123456789ABCDEF"

# define INT_MAX +2147483647
# define INT_MIN -2147483648

# ifdef __linux__
#  define NULLABLE "(nil)"
# else
#  define NULLABLE "0x0"
# endif

/* -------◊	FUNCTIONS TO MANIPULATE CHARACTERS	◊------- */
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
int			ft_tolower(int c);
int			ft_toupper(int c);
int			ft_putchar(char c);
int			ft_putnbr(int nb);
int			ft_putnbr_unsigned(unsigned int number);

/* -------◊	FUNCTIONS TO MANIPULATE STRINGS	◊------- */
size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_putstr(char *str);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *str, char c);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
int			ft_putptr(unsigned long int ptr);
int			ft_puthex(unsigned int number, int flag);

/* -------◊		FUNCTIONS TO CONVERSION/STRINGS FOR INTEGERS	◊------- */
int			ft_atoi(const char *nptr);
char		*ft_itoa(int n);

/* -------◊		FUNCTIONS TO MANIPULATE MEMORY	◊------- */
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memset(void *str, int c, size_t len);
void		*ft_memmove(void *dest, const void *src, size_t len);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_calloc(size_t nitems, size_t size);
char		*ft_strdup(const char *s1);

/* -------◊		FUNCTIONS FILE DESCRIPTOR     ◊------- */
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

/* -------◊	GNL	◊------- */
char		*get_next_line(int fd);

/* -------◊	PRINTF	◊------- */
int			ft_printf(const char *str, ...);

#endif
