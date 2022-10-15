/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimmel <asimmel@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 23:48:29 by asimmel           #+#    #+#             */
/*   Updated: 2022/10/15 17:03:38 by asimmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

//char	input[] = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2";

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_printresult(char **p)
{
	int pi;
	int pj;

	pi = 0;
	pj = 0;
	while (pj <= 15)
	{
		while (pi <= 5)
		{
			ft_putchar(p[pi][pj]);
			ft_putchar(' ');
			pi++;
		}
		ft_putchar('\n');
		pi = 0;
		pj++;
	}
}

char	**init_data(int x, int y)
{
	char **d;
	int i;
	
	d = (char**)malloc(x * sizeof(char*));
	i = 0;
	while (i < x)
	{
		d[i] = (char*)malloc(y * sizeof(char));
		i++;
	}

	return d;
}

char	**ft_firstfill(char **f)
{
	int fi;
	int fj;
	int v;

	fj = 0;
	v = 1;
	while (fj <= 15)
	{
		if (f[0][fj] == '4')
		{
			fi = 2;
			while (fi <= 5)
			{
				f[fi][fj] = v + '0';
				fi++;
				v++;
			}
			v = 1;
		}
		if (f[0][fj] == '3' && f[1][fj] == '2')
		{
			f[4][fj] = '4';
		}
		if (f[0][fj] == '3' && f[1][fj] == '1')
		{
			f[5][fj] = '4';
		}
		if (f[0][fj] == '1' && f[1][fj] == '2')
		{
			f[2][fj] = '4';
			f[5][fj] = '3';
		}
		fj++;
	}

	return f;
}

int main(void)
{
	char	col1[] = {'4', '3', '2', '1', '4', '3', '2', '1', '1', '2', '2', '2', '1', '2', '2', '2'};
	char	col2[] = {'1', '2', '2', '2', '1', '2', '2', '2', '4', '3', '2', '1', '4', '3', '2', '1'};

	char **data = init_data(6, 16);
	
	//initialize data contents
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
	
	data = ft_firstfill(data);
	ft_printresult(data);

	//fill known values
	
	
	
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
