/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01_2com.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimmel <asimmel@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 11:16:00 by yusyamas          #+#    #+#             */
/*   Updated: 2022/10/16 01:11:30 by asimmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	count_height_check_horiz(int grid[4][4], int *check_flag);  //rush-01_3.c

void	count_height_check_vert(int grid[4][4], int *check_flag);  //rush-01_3.c

void	check_building_pazzle(int grid[4][4], int *rule, int *check_flag);  //rush-01_4.c

int		my_next_permutation(int *array, int num);  //rush-01_1.c

//ポインターgridが指す配列の値を{1,2,3,4...n}にする。
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

//解が見つかれば *is_find = 1、見つからなければ 0。
void	check_state(int grid[4][4], int *rule, int *is_find)
{
	int	check_flag;

	//grid[][]の値がすべて1ではない場合に関数の処理を終わらせる。
	check_flag = 1;		//check_flag初期化
	count_height_check_horiz(grid, &check_flag);	//rush-01_3.c
	count_height_check_vert(grid, &check_flag);		//rush-01_3.c
	if (check_flag == 0)
	{
		return ;
	}
	//grid[][]の値がruleに従っているか確認する
	check_building_pazzle(grid, rule, &check_flag);	//rush-01_4.c
	if (check_flag == 1)
	{
		*is_find = 1;	//flagが0に変わらず出てきたら解を発見。
	}
}

//main()から呼び出す。depth = 0, is_find = 0
void	grid_decision_dfs(int grid[4][4], int depth, int *rule, int *is_find)
{
	if (depth == 4)		//再起関数のベースケース
	{
		check_state(grid, rule, is_find);	//解が見つかってたらis_findを更新
		return ;
	}
	array_init(grid[depth], 4);		//grid[depth]={1,2,3,4}
	while (1)		
	{
		grid_decision_dfs(grid, depth + 1, rule, is_find);	//depth+1で自身を呼び出し
		if (*is_find)	
		{
			return ;	//解が見つかっていたら終了
		}
		if (my_next_permutation(grid[depth], 4) == 0)  //rush-01_1.c
		{
			return ;	//次の順列がなければ終了
		}
	}
}
