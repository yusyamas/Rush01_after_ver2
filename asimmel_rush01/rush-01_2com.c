/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01_2 com.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimmel <asimmel@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 11:16:00 by yusyamas          #+#    #+#             */
/*   Updated: 2022/10/15 19:48:49 by asimmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		my_next_permutation(int *array, int num);

//条件を満たすなら*is_find = 1, そうでないなら*is_find = 0
void	check_state(int **grid, int *rule, int *is_find)
{
}

//grid[] を {1,2,3,4,..n} で初期化
void	grid_init(int *grid, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		grid[i] = i + 1;
		i += 1;
	}
}


void	grid_decision_dfs(int **grid, int depth, int *rule, int *is_find)
{
	if (depth == 4)
	{
		//ruleの条件を満たすか確認
		check_state(grid, rule, is_find);
		return ;
	}
	//gridの初期化
	grid_init(grid[depth], 4);
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
