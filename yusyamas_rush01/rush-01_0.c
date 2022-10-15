/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01_0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 23:53:56 by yusyamas          #+#    #+#             */
/*   Updated: 2022/10/15 21:02:22 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	grid_decision_dfs(int grid[4][4], int depth, int *rule, int *is_find);

void	print_grid(int grid[4][4], int n);

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

int	input_rule(int *rule, char *str, int n)
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
				return (1);
		}
		else
		{
			if (str[i] != ' ')
				return (1);
		}
		i += 1;
	}
	return (0);
}

int	augument_check(int *rule, char *str)
{
	int	n;

	n = ft_strlen(str);
	printf("%d\n", n);
	if (n != 31)
	{
		return (1);
	}
	return (input_rule(rule, str, n));
}

int	main(int argc, char **argv)
{
	int	grid[4][4];
	int	rule[16];
	int	is_find;

	is_find = 0;
	char c = argc + '0';
	write(1, &c, 1);
	if (argc != 2)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (augument_check(rule, argv[1]))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	grid_decision_dfs(grid, 0, rule, &is_find);
	if (is_find == 1)
		print_grid(grid, 4);
	else
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}
