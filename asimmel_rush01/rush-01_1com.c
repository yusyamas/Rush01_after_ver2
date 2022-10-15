/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01_1com.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimmel <asimmel@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 09:10:42 by yusyamas          #+#    #+#             */
/*   Updated: 2022/10/16 00:11:25 by asimmel          ###   ########.fr       */
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

//ポインターtabが指す配列の中身を、外側から中央に向かって２つずつ交換する。
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

//ポインターarrayの先の配列を次の順列に変え、、？。最後の順列になれば0を返す
int	my_next_permutation(int *array, int num)
{
	int	i;
	int	j;

	//4321のような並びになっていたら 0 を返す。奥から手前に探して、i=array[i-1]<array[i]である位置で終わる。
	i = num - 1;
	while (array[i - 1] >= array[i])
	{
		if (--i == 0)
		{
			return (0);
		}
	}
	//j=array[j]>array[i-1]もしくはj=iの位置で終わる。
	j = num - 1;
	while (j > i && array[j] <= array[i - 1])
	{
		j -= 1;
	}
	ft_swap(array, i - 1, j);	//array[i-1]とarray[j]の値を入れ替える
	ft_rev_int_tab(array + i, num - i);	 //??
	return (1);
}
