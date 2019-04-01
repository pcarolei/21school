/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 23:09:34 by hlesli            #+#    #+#             */
/*   Updated: 2019/02/20 23:09:39 by hlesli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

int		ft_atoi(char *str);
int		count_x(int fd);
int		get_tab_cols_amount(char **tab);
void	display_char_tab(char **tab, int rows);
int		min(int a, int b, int c);
int		*get_start(int max, int max_i, int max_j);
void	final(char **str, int *start, int *end, char **param);
void	bsq(char **tab, char **param, int cols);
void	to_file();
int		first_line_symbol_counter(char *buf);
int		parse_cond_helper(int i, int j, int counter);
char	**parse(int fd);
void	shift_str_array(char **str, int y);
int		count_number_symbols(char *nbr_str);
int		is_map_first_line_valid(char *file_name, char *nbr_str);
char	**str_creation (int x, int y, char *file_name);
void	str_transpiler(char **str, char smb1, char smb2, int rows);
int		is_right_symbol(char test, char smb1, char smb2);
int		is_str_valid(char **str, int rows, char smb1, char smb2);
void	from_st_input (void);
void	from_files (int argc, char **argv);

#endif
