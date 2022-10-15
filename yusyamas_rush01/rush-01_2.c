/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 11:16:00 by yusyamas          #+#    #+#             */
/*   Updated: 2022/10/15 20:57:30 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	count_height_check_horiz(int grid[4][4], int *check_flag);

void	count_height_check_vert(int grid[4][4], int *check_flag);

void	check_building_pazzle(int grid[4][4], int *rule, int *check_flag);

int		my_next_permutation(int *array, int num);

void	array_init(int *grid, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		grid[i] = i + 1;
		i += 1;
	}
}

//条件を満たすなら*is_find = 1, そうでないなら*is_find = 0
void	check_state(int grid[4][4], int *rule, int *is_find)
{
	int	check_flag;

	check_flag = 1;
	count_height_check_horiz(grid, &check_flag);
	count_height_check_vert(grid, &check_flag);
	if (check_flag == 0)
	{
		return ;
	}
	check_building_pazzle(grid, rule, &check_flag);
	if (check_flag == 1)
	{
		*is_find = 1;
	}
}

void	grid_decision_dfs(int grid[4][4], int depth, int *rule, int *is_find)
{
	if (depth == 4)
	{
		check_state(grid, rule, is_find);
		return ;
	}
	array_init(grid[depth], 4);
	while (1)
	{
		grid_decision_dfs(grid, depth + 1, rule, is_find);
		if (*is_find)
		{
			return ;
		}
		if (my_next_permutation(grid[depth], 4) == 0)
		{
			return ;
		}
	}
}
