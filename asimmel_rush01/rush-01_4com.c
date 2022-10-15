/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01_4com.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimmel <asimmel@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 19:28:26 by yusyamas          #+#    #+#             */
/*   Updated: 2022/10/16 01:13:53 by asimmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//入力のcol_upに従っているか確認
void	check_b_p_col_up(int grid[4][4], int *rule, int *check_flag)
{
	int	i;
	int	j;
	int	old;
	int	cnt;

	j = 0;
	while (j < 4)
	{
		i = 0;
		old = 0;
		cnt = 0;
		while (i < 4)
		{
			if (old < grid[i][j])
			{
				old = grid[i][j];
				cnt += 1;
			}
			if (rule[j] != cnt) //＊＊while(j>=0)の外でcntを確認？＊＊
				*check_flag = 0;
			i += 1;
		}
		j += 1;
	}
}

//入力のcol_downに従っているか確認
void	check_b_p_col_down(int grid[4][4], int *rule, int *check_flag)
{
	int	i;
	int	j;
	int	old;
	int	cnt;

	j = 0;
	while (j < 4)
	{
		i = 4 - 1;
		old = 0;
		cnt = 0;
		while (i >= 0)
		{
			if (old < grid[i][j])
			{
				old = grid[i][j];
				cnt += 1;
			}
			if (rule[j + 4] != cnt) //＊＊while(j>=0)の外でcntを確認？＊＊
				*check_flag = 0;
			i -= 1;
		}
		j += 1;
	}
}

//入力のrow_leftに従っているか確認
void	check_b_p_row_left(int grid[4][4], int *rule, int *check_flag)
{
	int	i;
	int	j;
	int	old;
	int	cnt;

	i = 0;
	while (i < 4)
	{
		j = 0;
		old = 0;
		cnt = 0;
		while (j < 4)
		{
			if (old < grid[i][j])
			{
				old = grid[i][j];
				cnt += 1;
			}
			if (rule[i + 4 * 2] != cnt) //＊＊while(j>=0)の外でcntを確認？＊＊
				*check_flag = 0;
			j += 1;
		}
		i += 1;
	}
}

//入力のrow_rightに従っているか確認
void	check_b_p_row_right(int grid[4][4], int *rule, int *check_flag)
{
	int	i;
	int	j;
	int	old;
	int	cnt;

	i = 0;
	while (i < 4)
	{
		j = 4 - 1;
		old = 0;
		cnt = 0;
		while (j >= 0)
		{
			//右から左に見て、次の高さが前より下がった回数を数え
			if (old < grid[i][j])
			{
				old = grid[i][j];
				cnt += 1;
			}
			if (rule[i + 4 * 3] != cnt) //＊＊while(j>=0)の外でcntを確認？＊＊
				*check_flag = 0;
			j -= 1;
		}
		i += 1;
	}
}

//grid[][]の値がruleに従っているか確認する
void	check_building_pazzle(int grid[4][4], int *rule, int *check_flag)
{
	check_b_p_col_up(grid, rule, check_flag);
	check_b_p_col_down(grid, rule, check_flag);
	check_b_p_row_left(grid, rule, check_flag);
	check_b_p_row_right(grid, rule, check_flag);
}
