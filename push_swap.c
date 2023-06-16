/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 09:21:34 by ncasteln          #+#    #+#             */
/*   Updated: 2023/06/16 19:01:33 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static int	build_stack(t_clist **stack, int argc, char **argv)
{
	int		i;
	int		j;
	char	**argv_splitted;

	argv_splitted = NULL;
	if(!(is_valid_argc(argc)))
		return (0);
	i = 1;
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' '))
		{
			argv_splitted = ft_split(argv[i], ' ');
			j = 0;
			while (argv_splitted[j])
			{
				if (is_valid_argv(argv_splitted[j], *stack))
					clst_append(stack, clst_newnode((int)ft_atol(argv_splitted[j])));
				else
					return (0); // free() argv_splitted, clst
				j++;
			}
		}
		else
		{
			if (is_valid_argv(argv[i], *stack))
				clst_append(stack, clst_newnode((int)ft_atol(argv[i])));
			else
				return (0); // free() argv_splitted, clst
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	// 1) modify the build_stack so that returns the stack
	// 2) use a bigger structure to inglobate them, but is it useful?
	t_clist *a;
	t_clist *b;

	a = NULL;
	b = NULL;

	if (!(build_stack(&a, argc, argv)))
		return (error());

	clst_print(a);

	return (0);
}
