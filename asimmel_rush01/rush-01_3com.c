/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01_3com.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimmel <asimmel@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:59:46 by yusyamas          #+#    #+#             */
/*   Updated: 2022/10/16 01:19:59 by asimmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	array_init(int *grid, int n);	//rush-01_2.c

//cnt_ht_chk_horz/vertによって呼び出される。gridのplace列(dir=0)または行(dir=1)に1があればflagを1→0にする。
/* dir = 0 : horiz(-) , dir = 1 : vert(|) */
void	check_array_all_1(int grid[4][4], int *check_flag, int dir, int place)
{
	int	i;

	i = 0;
	if (dir == 0)	//cnt_ht_chk_horz用
	{
		while (i < 4)
		{
			if (grid[place][i] != 1) //cnt_ht_chk..のgrid[i][1~4]!=1の場合
				*check_flag = 0; //check_flag 1→0
			i += 1;
		}
	}
	else	//dir == 1、cnt_ht_chk_vert用
	{
		while (i < 4)
		{
			if (grid[i][place] != 1) //cnt_ht_chk..のgrid[1~4][i]!=1の場合
				*check_flag = 0; //check_flag 1→0
			i += 1;
		}
	}
}

//grid[i][j]に応じてcount_height[4]の値を変化させる。check_array_all_1を呼び出す。
void	count_height_check_horiz(int grid[4][4], int *check_flag)
{
	int	i;
	int	j;
	int	count_height[4];	//何に使う配列ですか？

	i = 0;
	while (i < 4)
	{
		array_init(count_height, 4); //count_height = {1,2,3,4} (why?)
		j = 0;
		while (j < 4)
		{
			count_height[grid[i][j] - 1] += 1;	//grid[i][j]の高さを表すcount_height[]の位置を+1。
			j += 1;
		}
		check_array_all_1(grid, check_flag, 0, i); //grid[i][1~4]に1があればflag1→0。
		i += 1;
	}
}

//grid[i][j]に応じてcount_height[4]の値を変化させる。check_array_all_1を呼び出す。
void	count_height_check_vert(int grid[4][4], int *check_flag)
{
	int	i;
	int	j;
	int	count_height[4];	//何に使う配列ですか？

	j = 0;
	while (j < 4)
	{
		array_init(count_height, 4);
		i = 0;
		while (i < 4)
		{
			count_height[grid[i][j] - 1] += 1;
			i += 1;
		}
		check_array_all_1(grid, check_flag, 1, j); //grid[1~4][j]に1があればflag1→0
		j += 1;
	}
}
