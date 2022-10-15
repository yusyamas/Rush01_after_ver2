/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01_0com.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimmel <asimmel@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 23:53:56 by yusyamas          #+#    #+#             */
/*   Updated: 2022/10/15 22:40:28 by asimmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>	//＊＊禁止: 要削除＊＊
#include <stdlib.h>
#include <unistd.h>

void	grid_decision_dfs(int grid[4][4], int depth, int *rule, int *is_find); //rush-01_2.c

void	print_grid(int grid[4][4], int n);	//rush-01_5.c

//文字配列の文字数を出力する
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

//入力された数字に不正がある場合は1を返す。なければコマンドライン入力の数字をrule[]に格納する。
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
				rule[cnt] = str[i] - '0'; //コマンドライン入力の数字をrule[]に格納
				cnt += 1;
			}
			else   
				return (1);   //エラー出力用：strの文字が1-4以外
		}
		else
		{
			if (str[i] != ' ')
				return (1);   //エラー出力用：コマンドライン入力引数の数字の間がスペース以外
		}
		i += 1;
	}
	return (0);
}

//コマンドライン入力の長さを確認して、不正があればエラー出力する。input_ruleを呼び出す。
int	augument_check(int *rule, char *str)
{
	int	n;

	n = ft_strlen(str);
	printf("%d\n", n);		//＊＊禁止: 要削除＊＊
	if (n != 31)
	{
		return (1); 	//エラー出力用：コマンドライン入力の長さが違う
	}
	return (input_rule(rule, str, n));
}

int	main(int argc, char **argv)
{
	int	grid[4][4];		//処理、出力する4x4マップ
	int	rule[16];		//コマンドライン入力の値
	int	is_find;		//解が見つかった場合は1、初期値: 0。

	is_find = 0;
	char c = argc + '0';
	write(1, &c, 1);		//コマンドライン入力の引数の数(argc)を出力
	
	//コマンドライン入力の引数の数の確認
	if (argc != 2)
	{
		write(2, "Error\n", 6); //エラー出力；コマンドライン入力の引数が２ではない場合
		return (1);
	}

	//コマンドライン入力の長さを確認して、不正があればエラー出力する。input_ruleを呼び出す。
	if (augument_check(rule, argv[1]))
	{
		write(2, "Error\n", 6); //augment_checkとinput_ruleの不正出力
		return (1);
	}

	//解を探す再帰関数
	grid_decision_dfs(grid, 0, rule, &is_find);
	if (is_find == 1)
		print_grid(grid, 4);	//解が見つかった時にコマンドライン出力
	else
	{
		write(2, "Error\n", 6);		//エラー出力：解が見つからなかった
		return (1);		
	}
	return (0);		
}
