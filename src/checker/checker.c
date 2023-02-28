/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:03:19 by jlimones          #+#    #+#             */
/*   Updated: 2023/02/28 19:43:30 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/jlimones/Desktop/push_swap_git/src/push_swap.h"

int	std_in_term(char *param, t_node **stack_a, t_node **stack_b, int len)
{
	if (ft_strncmp(param, "pa\n", len) == 0)
		ft_push_a(stack_a, stack_b);
	else if (ft_strncmp(param, "pb\n", len) == 0)
		ft_push_b(stack_b, stack_a);
	else if (ft_strncmp(param, "sa\n", len) == 0)
		ft_move_swap_a(stack_a, 1);
	else if (ft_strncmp(param, "sb\n", len) == 0)
		ft_move_swap_b(stack_a, 1);
	else if (ft_strncmp(param, "ss\n", len) == 0)
		ft_move_swap_ab(stack_a, stack_b);
	else if (ft_strncmp(param, "ra\n", len) == 0)
		rotate_a(stack_a, 1);
	else if (ft_strncmp(param, "rb\n", len) == 0)
		rotate_b(stack_b, 1);
	else if (ft_strncmp(param, "rr\n", len) == 0)
		rotate_ab(stack_a, stack_b);
	else if (ft_strncmp(param, "rra\n", len) == 0)
		reverse_rotate_a(stack_a, 1);
	else if (ft_strncmp(param, "rrb\n", len) == 0)
		reverse_rotate_b(stack_b, 1);
	else if (ft_strncmp(param, "rrr\n", len) == 0)
		reverse_rotate_ab(stack_a, stack_b);
	else
		return (1);
	return (0);
}

int	exec_instructions(t_node **stack_a, t_node **stack_b)
{
	char	*param;
	int		status;

	if (stack_a == NULL)
		return (0);
	param = ft_gnl(STDIN_FILENO);
	status = 0;
	while (param != NULL)
	{
		if (status == 0)
			status = std_in_term(param, stack_a,
					stack_b, ft_strlen(param));
		else
			std_in_term(param, stack_a, stack_b, ft_strlen(param));
		free(param);
		param = ft_gnl(STDIN_FILENO);
	}
	return (status);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		status_code;

	stack_b = NULL;
	if (argc < 2)
		return (0);
	//parse_params(argc, argv, &push_swap);  checkear los numeros
	//check_duplicates(push_swap.int_array, push_swap.arr_len);
	//init_stacks(&push_swap);
	status_code = exec_instructions(stack_a, stack_b);
	if (status_code == 1)
		ft_putstr_fd("Error\n", STDERR_FILENO);
	else
	{
		if (is_sorted(push_swap.a) && push_swap.b == NULL)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	free(push_swap.int_array);
	ft_lstclear(&push_swap.a, ft_do_nothing);
	ft_lstclear(&push_swap.b, ft_do_nothing);
	return (0);
}