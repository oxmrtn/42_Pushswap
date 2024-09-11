/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:32:30 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/24 16:40:15 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

long	ft_atoi(const char *nptr);

void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t nmemb, size_t size);

int		ft_isalpha(int c);

int		ft_isdigit(int c);

int		ft_isalnum(int c);

int		ft_isascii(int c);

int		ft_isprint(int c);

int		ft_ultimate_len(char **str);

char	*ft_itoa(int n);

size_t	ft_strlen(const char *str);

void	*ft_memchr(const void *s, int c, size_t n);

int		ft_memcmp(const void *pointer1, const void *pointer2, size_t size);

void	*ft_memset(void *s, int c, size_t n);

void	*ft_memcpy(void *dest, const void *src, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n);

void	ft_putchar_fd(char c, int fd);

void	ft_putendl_fd(char *s, int fd);

void	ft_putnbr_fd(int nbr, int fd);

void	ft_putstr_fd(char *s, int fd);

char	**ft_split(char *str, char c);

char	*ft_strchr(const char *s, int c);

char	*ft_strdup(char *src);

void	ft_striteri(char *s, void (*f)(unsigned int, char *));

char	*ft_strjoin(char *s1, char *s2);

size_t	ft_strlcat(char *dest, char *src, size_t size);

size_t	ft_strlcpy(char *dst, const char *src, size_t size);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int		ft_strncmp(char *s1, char *s2, unsigned int n);

char	*ft_strnstr(const char *big, const char *little, size_t len);

char	*ft_strrchr(const char *s, int c);

char	*ft_strtrim(char const *s1, char const *set);

char	*ft_substr(char const *s, unsigned int i, size_t len);

int		ft_tolower(int c);

int		ft_toupper(int c);

void	ft_lstadd_front(t_list **lst, t_list *new);

void	ft_lstadd_back(t_list **lst, t_list *new);

t_list	*ft_lstlast(t_list *lst);

t_list	*ft_lstnew(void *content);

int		ft_lstsize(t_list *lst);

void	ft_lstdelone(t_list *lst, void (*del)(void *));

void	ft_lstclear(t_list **lst, void (*del)(void *));

void	ft_lstiter(t_list *lst, void (*f)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
