/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01_0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 23:53:56 by yusyamas          #+#    #+#             */
/*   Updated: 2022/10/15 17:31:00 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	grid_decision_dfs(int **grid, int depth, int *rule, int *is_find);

void	print_grid(int **grid);

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (*str != '\0')
	{
		length += 1;
		str += 1;
	}
	return (length);
}

void	input_rule(int *rule, int *is_error, char *str, int n)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (i < n)
	{
		if (i % 2 == 0)
		{
			if ('1' <= str[i] && str[i] <= '4')
			{
				rule[cnt] = str[i] - '0';
				cnt += 1;
			}
			else
				*is_error = 1;
		}
		else
		{
			if (str[i] != ' ')
				*is_error = 1;
		}
		i += 1;
	}
}

void	augument_check(int *rule, int *is_error, char *str)
{
	int	n;

	n = ft_strlen(str);
	if (n != 31)
	{
		*is_error = 1;
		return ;
	}
	input_rule(rule, is_error, str, n);
}

int	main(int argc, char **argv)
{
	int	grid[4][4];
	int	is_error;
	int	rule[16];
	int	is_find;

	is_find = 0;
	if (argc != 2)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	augument_check(rule, &is_error, argv[1]);
	if (is_error)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	grid_decision_dfs(grid, 0, rule, &is_find);
	print_grid(grid);
}
