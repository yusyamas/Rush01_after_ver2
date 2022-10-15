/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01_0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 23:53:56 by yusyamas          #+#    #+#             */
/*   Updated: 2022/10/15 13:51:39 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	grid[4][4];
	int	is_error;
	int	rule[16];

	if (argc != 2)
	{
		write(2, "Error\n", 6);
		return (1);
	}
}
