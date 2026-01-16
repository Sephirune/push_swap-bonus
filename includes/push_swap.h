/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarogarc <aarogarc@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:20:49 by aarogarc          #+#    #+#             */
/*   Updated: 2025/12/04 16:37:29 by aarogarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../printf/ft_printf.h"
# include "../libft/libft.h"
# include <limits.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	long			nb;
	int				index;
	struct s_list	*next;
	struct s_list	*previous;
}	t_list;

typedef struct s_data
{
	int		moves;
	t_list	*a;
	t_list	*b;
}	t_data;

int		ft_atoi(const char *str);
int		check_args(const char *str);
int		ft_print_ints(char *str, int *count);
void	ft_push_a(t_data *data, int check);
void	ft_push_b(t_data *data, int check);
void	ft_reverse_a(t_data *data, int check);
void	ft_reverse_b(t_data *data, int check);
void	ft_rotate_a(t_data *data, int check);
void	ft_rotate_b(t_data *data, int check);
void	ft_rr(t_data *data);
void	ft_rrr(t_data *data);
void	ft_swap_a(t_data *data, int check);
void	ft_swap_b(t_data *data, int check);
void	ft_swap_ab(t_data *data);
void	ft_index(t_data *data);
int		is_sorted(t_list *pack);
int		check_duplicate(t_data *data, int vatoi);
void	parse_args(t_data *data, int argc, char **argv);
void	free_split(char **split);
void	check_error(void);
int		find_min(t_list *pack);
void	push_min(t_data *data);
int		get_bits(t_data *data);
void	aux_split(t_data *data, char **split);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(long nb);
void	free_list(t_list **lst);
void	check_error_free(t_data *data);
void	aux_main(t_data *data, int size);
void	size_2(t_data *data);
void	size_3(t_data *data);
void	size_4(t_data *data);
void	size_5(t_data *data);
void	radix_sort(t_data *data);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);

#endif
