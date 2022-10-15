/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:59:46 by yusyamas          #+#    #+#             */
/*   Updated: 2022/10/15 20:57:58 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	array_init(int *grid, int n);

/* dir = 0 : horiz(-) , dir = 1 : vert(|) */
void	check_array_all_1(int grid[4][4], int *check_flag, int dir, int place)
{
	int	i;

	i = 0;
	if (dir == 0)
	{
		while (i < 4)
		{
			if (grid[place][i] != 1)
				*check_flag = 0;
			i += 1;
		}
	}
	else
	{
		while (i < 4)
		{
			if (grid[i][place] != 1)
				*check_flag = 0;
			i += 1;
		}
	}
}

void	count_height_check_horiz(int grid[4][4], int *check_flag)
{
	int	i;
	int	j;
	int	count_height[4];

	i = 0;
	while (i < 4)
	{
		array_init(count_height, 4);
		j = 0;
		while (j < 4)
		{
			count_height[grid[i][j] - 1] += 1;
			j += 1;
		}
		check_array_all_1(grid, check_flag, 0, i);
		i += 1;
	}
}

void	count_height_check_vert(int grid[4][4], int *check_flag)
{
	int	i;
	int	j;
	int	count_height[4];

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
		check_array_all_1(grid, check_flag, 1, j);
		j += 1;
	}
}
