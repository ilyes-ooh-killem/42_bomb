/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/15 01:40:58 by ihermell          #+#    #+#             */
/*   Updated: 2014/07/15 17:14:55 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int		ft_intlen(int nb)
{
	if (nb < 1)
		return (0);
	return (1 + ft_intlen(nb / 10));
}

char	*ft_itoa(int nb)
{
	char	*str;
	int		int_len;

	int_len = ft_intlen(nb);
	str = (char*)malloc(sizeof(char) * (int_len + 1));
	str[int_len] = '\0';
	while (int_len-- > 0)
	{
		str[int_len] = (nb % 10) + 48;
		nb /= 10;
	}	
	return (str);
}

int		ft_atoi(char *str)
{
	int	nbr;
	int i;
	int is_negative;

	nbr = 0;
	i = 0;
	is_negative = 1;
	if (str[i] == '-')
	{
		is_negative = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr *= 10;
		nbr += str[i] - '0';
		i++;
	}
	return (nbr);
}

int		ft_natoi(char *str, int l)
{
	int i;
	char *cut;

	i = 0;
	cut = (char*)malloc(sizeof(char) * l + 1);
	while (i++ < l)
		cut[i - 1] == str[i - 1];
	return ft_atoi(cut);
}


char	*test()
{
	return "test";
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnstr(char *str, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		is_operator(char c)
{
	if (c == '+')
		return (1);
	return (0);
}

int		is_first_operator(char c)
{
	if (c == '*' || c == '/' || c == '%')
		return (1);
	return (0);
}

int		is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		calculate_first_operands_expr(char *expr, int l)
{
	int		i;

	i = 0;
	while (i < l && expr[i] != '\0')
	{




int	evaluate_product_expr(char *expr)
{
}
int	calculate_base_result(char *expr, char first_operand, char second_operand, int result)
{
	char *nb;
	char *nb_start;

	int i;

	nb = (char*)malloc(sizeof(char) * 11);
	if (!second_operand) // null
	while (!is_number(expr[cursor])i)
		cursor++;
	nb_start = expr[cursor];
	i = 0;
	while (is_number(expr[cursor++]))
	{
		nb[i] = expr[cursor - 1];
		i++;
	}
	if (is_first_operator(second_operand[0]))
		return (result + evaluate_product_expr(nb_start));
	if (first_operand == '+')
		return (result + ft_atoi(nb) + evaluate_base_expr(second_operand));
	else if (first_operand == '-')
		return (result - ft_atoi(nb) + evaluate_base_expr(second_operand));
}

int	evaluate_base_expr(char *expr, int result)
{
	char first_operand;
	char *second_operand;
	char *first_expr;
	int nb_l;
	int cursor;

	cursor = 0;
	first_expr_l = 0;
	if (!is_operator(expr[cursor]))
		first_operand = '+';
	else
		first_operand = expr[cursor];
	cursor++;
	while (!is_operator(expr[cursor]) && expr[cursor] != '\0')
		cursor++;
	second_operand = expr + cursor;
	result = calculate_result();
			}
char *calculate_expr(char *expr)
{
	int	result = 0;
	int		cursor = 0;
	int		i;
	char	**temp;

	temp = (char**)malloc(sizeof(char*) * 4);
	temp[0] = (char*)malloc(sizeof(char) * 2);
	temp[2] = (char*)malloc(sizeof(char) * 2);
	temp[0] = "+";
	temp[1] = "0";
	temp[2] = "0";
	temp[3] = "+";	
	while (expr[cursor] != '\0')
	{
		while (!is_number(expr[cursor]))
			cursor++;
		free(temp[1]);
		free(temp[2]);
		temp[1] = expr[cursor]; 
		temp[2] = (char*)malloc(sizeof(char) * 12);
		i = 0;
		while (expr[cursor] >= '0' && expr[cursor] <= '9')
		{
			temp[2][i] = expr[cursor];
			cursor++;
			i++;
		}
		temp[2][i] = '\0';
		
		while (!is_operator(expr[cursor]) && cursor)
				cursor++;
			if (temp[0])
				free(temp[0]);
			temp[0] = temp[3];
			temp[3] = (char*)malloc(sizeof(char) * 2);
			temp[3][0] = expr[cursor];
			temp[3][1] = '\0';	
		}
		
		if (temp[0] == '+')
			result += temp[2];
		else if (temp[0] == '-')
			result -= temp[
	}
	return (ft_itoa(result));
}

char *eval_expr(char *str)
{
	char	*copy = (char*)malloc(20);
	char	*start_expr;
	int		pos_start_expr;
	int		depth_expr;
	int		len_expr;
	int		sub_expr_cursor;
	int		cursor;
	char *test;

	cursor = 0;
	len_expr = 0;
	if (!str[cursor])
		return ("");
	printf("To eval : %s\n", str);
	while (str[cursor] != '\0')
	{
		if (str[cursor] == '(')
		{
			sub_expr_cursor = cursor;
			pos_start_expr = cursor;
			start_expr = str + cursor;
			sub_expr_cursor++;
			depth_expr = 1;
			while (str[sub_expr_cursor] != ')' || depth_expr > 1)
			{
				if (str[sub_expr_cursor] == '(')
					depth_expr++;
				if (str[sub_expr_cursor] == ')')
					depth_expr--;
				len_expr++;
				sub_expr_cursor++;
			}
			char *eval_m_expr = eval_expr(start_expr + 1);
			//char *eval_e_expr = eval_expr(start_expr + len_expr + 3); 
			test = (char*)malloc(pos_start_expr + strlen(eval_m_expr));// + strlen(eval_e_expr));
			int nawak = 0;
			while (copy[nawak] != '\0')
			{
				test[nawak] = copy[nawak];
				nawak++;
			}
			int i = 0;
			while (eval_m_expr[i] != 0)
			{
				test[nawak] = eval_m_expr[i];
				nawak++;
				i++;
			}
			cursor++;
			printf("Test : %s\n", calculate_expr(test));
			return (test);
			//printf("Start : %d", pos_start_expr);
			//printf("p :%d\n", pos_start_expr + len_expr + 1);
			//printf("s :%s\n", start_expr + len_expr + 1);
			//printf("Eval expr : %s\n", eval_expr(start_expr + 1));
			//printf("Eval after :%s\n", eval_expr(start_expr + len_expr + 2));
		}
		if (str[cursor] == ')')
		{	
			printf("S: %s\n", str);
			//printf("Curs: %d\n", cursor);
			//printf("Str : %s\n", str);

			return calculate_expr(str);
		}
		printf("%c\n", str[cursor]);
		copy[cursor] = str[cursor];
		copy[cursor + 1] = '\0';
		cursor++;
	}
	printf("FINAL VALUE : %s", test);
	return "e";
}

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		printf("End : %s", eval_expr(av[1]));
	}/*
	char *str;
	int nb;

	nb = 1500;
	printf("%s", ft_itoa(nb));*/
	return (0);
}
