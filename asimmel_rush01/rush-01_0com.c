/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01_0com.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimmel <asimmel@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 23:53:56 by yusyamas          #+#    #+#             */
/*   Updated: 2022/10/15 18:02:31 by asimmel          ###   ########.fr       */
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

//入力された数字に不正がある場合は 1 を返す。なければ入力で rule[] を初期化する。
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

//入力の長さを確認して、不正があれば *is_error を1にする。input_ruleを実行する。
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
	//コマンドライン入力の数を確認して、不正があれば 1 を返す。
	if (argc != 2)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	//入力確認、エラー出力、入力→rule[]。
	augument_check(rule, &is_error, argv[1]);
	if (is_error)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	//rush-01_2.c
	grid_decision_dfs(grid, 0, rule, &is_find);
	//未完成
	print_grid(grid);
}
