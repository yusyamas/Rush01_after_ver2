/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimmel <asimmel@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 23:48:29 by asimmel           #+#    #+#             */
/*   Updated: 2022/10/15 13:13:18 by asimmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
#include <unistd.h>

//char	input[] = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2";

char	col1[] = {'4', '3', '2', '1', '1', '2', '2', '2', '4', '3', '2', '1', '1', '2', '2', '2'};
char	col2[] = {'1', '2', '2', '2', '1', '2', '2', '2', '4', '3', '2', '1', '4', '3', '2', '1'};
char	data[6][16];


void ft_firstfill();



void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_printresult(void)
{
	int pi;
	int pj;

	pi = 0;
	pj = 0;
	while (pj <= 15)
	{
		while (pi <= 5)
		{
			ft_putchar(data[pi][pj]);
			ft_putchar(' ');
			pi++;
		}
		ft_putchar('\n');
		pi = 0;
		pj++;
	}
}

void	ft_firstfill(void)
{
	int fj;
	int fi;
	int v;

	fj = 0;
	fi = 2;
	v = 1;
	while (fj <= 11)
	{
		if (data[0][fj] == 4)
		{
			while (fi < 5)
			{
				data[0][fi] = v;
				v++;
			}
			v = 1;
		}
		if (data[0][fj] == '3' && data[1][fj] == '2')
		{
			data[4][fj] = '4';
		}
		if (data[0][fj] == '3' && data[1][fj] == '1')
		{
			data[5][fj] = '4';
		}
		if (data[0][fj] == '1' && data[1][fj] == '2')
		{
			data[2][fj] = '4';
			data[5][fj] = '3';
		}
		fj++;
	}
}


int main(void)
{
	int i;

	i = 0;
	while (i <= 15)
	{
		data[0][i] = col1[i];
		data[1][i] = col2[i];
		data[2][i] = '0';
		data[3][i] = '0';
		data[4][i] = '0';
		data[5][i] = '0';
		i++;
	}
	
	ft_firstfill();
	ft_printresult();
	
	
	
	
	/*
	if (argc > 2)
	{
		return (1);
	}

	int i;
	
	i = 0;
	while (*(argv[1] + i) != '\0')
	{
		ft_putchar(*(argv[1] + i));
		i++;
	}		
	*/
	
	

	return (0);
}
