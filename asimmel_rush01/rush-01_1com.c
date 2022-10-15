/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01_1com.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimmel <asimmel@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 09:10:42 by yusyamas          #+#    #+#             */
/*   Updated: 2022/10/15 19:48:46 by asimmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
*/

//引数の配列 の i 位置と j 位置の値を交換。
void	ft_swap(int *x, int i, int j)
{
	int	tmp;

	tmp = x[i];
	x[i] = x[j];
	x[j] = tmp;
}

//引数の配列の中身を外側から中央に向かって交換する。
void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	j = size - 1;
	while (i < size / 2)
	{
		ft_swap(tab, i, j);
		i += 1;
		j -= 1;
	}
}

//引数の配列の
int	my_next_permutation(int *array, int num)
{
	int	i;
	int	j;

	//4321のような並びになっていたら 0 を返す。なってなければ [i - 1] < [i] i をで止める?
	i = num - 1;
	while (array[i - 1] >= array[i])
	{
		if (--i == 0)
		{
			return (0);
		}
	}
	//
	j = num - 1;
	while (j > i && array[j] <= array[i - 1])
	{
		j -= 1;
	}
	ft_swap(array, i - 1, j);
	ft_rev_int_tab(array + i, num - i);
	return (1);
}

//---------------------------------------------------
//以下は使わない
void	show_data(int *x, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		printf("%d%c", x[i], (i != 3) ? ' ' : '\n');
		i += 1;
	}
}

int	main(void)
{
	int	x[4] = {1, 2, 3, 4};

	do
	{
		show_data(x, 4);
	} while (my_next_permutation(x, 4));
}
