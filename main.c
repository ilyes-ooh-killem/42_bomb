/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/15 01:40:58 by ihermell          #+#    #+#             */
/*   Updated: 2014/07/16 02:40:54 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int		is_first_operator(char c);
int		is_number(char c);

int ft_intlen(int x) {
	if (x < 0)
		x *= -1;
	if(x>=100000) {
		if(x>=10000000) {
			if(x>=1000000000) return 10;
			if(x>=100000000) return 9;
			return 8;
		}
		if(x>=1000000) return 7;
		return 6;
	}
	else {
		if(x>=1000) {
			if(x>=10000) return 5;
			return 4;
		} else {
			if(x>=100) return 3;
			if(x>=10) return 2;
			return 1;
		}
	}
}

char	*ft_itoa(int nb)
{
	char	*str;
	int		int_len;
	int		negative;

	printf("ITOA B4 : %d\n", nb);
	negative = 0;
	int_len = 0;
	if (nb < 0)
	{
		negative = 1;
		nb *= -1;
		int_len = 1;
	}
	int_len += ft_intlen(nb);
	str = (char*)malloc(sizeof(char) * (int_len + 1));
	str[int_len] = '\0';
	while (int_len-- > negative)
	{
		str[int_len] = (nb % 10) + 48;
		nb /= 10;
	}
	if (negative)
		str[0] = '-';
	printf("ITOA After: %s\n", str);
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
	return (is_negative * nbr);
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
	if ((c == '+' || c == '-' || is_first_operator(c)) )
		return (1);
	return (0);
}

int		is_valid_operator(char c, char c2)
{
	if (is_operator(c) && !is_number(c2))
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

int	calculate_product_expr(char *expr, char first_operand, char *second_operand, int result)
{
	char *nb;
	char *nb_start;
	int cursor;
	int i;

	cursor = 0;
	nb = (char*)malloc(sizeof(char) * 11);
	while (!is_number(expr[cursor]) && !(expr[cursor] == '-' && is_number(expr[cursor + 1])))
		cursor++;
	nb_start = expr + cursor;
	//printf("WHILE : %s\n", nb_start);
	i = 0;
	while (is_number(expr[cursor++]) || (i == 0 && nb_start[i] == '-'))
	{
		nb[i] = expr[cursor - 1];
		i++;
	}
	//printf("NB : %s\n", nb);
	printf("RESULT LOL : %d\n", result);
	//printf("1st %c\n", first_operand);
	//printf("2nd %c\n", second_operand[0]);
	//printf("atoi %d\n", ft_atoi(nb));
	if (second_operand[0] == '\0' || second_operand[0] == ')')
	{
		if (first_operand == '*')
			return (result * ft_atoi(nb));
		if (first_operand == '/')
			return (result / ft_atoi(nb));
		if (first_operand == '%')
		   return (result % ft_atoi(nb));	
	}
	if (is_first_operator(second_operand[0]))
	{
		if (first_operand == '*')
			return (evaluate_product_expr(second_operand, result * ft_atoi(nb)));
		if (first_operand == '/')
			return (evaluate_product_expr(second_operand, result / ft_atoi(nb)));
		if (first_operand == '%')
			return (evaluate_product_expr(second_operand, result % ft_atoi(nb)));
	}
		if (first_operand == '*')
			return (result * ft_atoi(nb) + evaluate_base_expr(second_operand, 0));
		if (first_operand == '/')
			return (result / ft_atoi(nb) + evaluate_base_expr(second_operand, 0));
		if (first_operand == '%')
			return (result % ft_atoi(nb) + evaluate_base_expr(second_operand, 0));

}


int	evaluate_product_expr(char *expr, int result)
{
	char first_operand;
	char *second_operand;
	int cursor;
	char *nb_start;
	int nb;

	printf("Evaluate product : '%s'\n", expr);
	first_operand = expr[0];
	cursor = 1;
	while (expr[cursor] != '\0'&& expr[cursor] != ')' && !(is_valid_operator(expr[cursor], expr[cursor + 1])))
		cursor++;	
	second_operand = expr + cursor;
	return calculate_product_expr(expr, first_operand, second_operand, result);
}

int	calculate_base_result(char *expr, char first_operand, char *second_operand, int result)
{
	char *nb;
	char *nb_start;
	int cursor;
	int i;

	cursor = 0;
	nb = (char*)malloc(sizeof(char) * 11);
	while (!is_number(expr[cursor]))
		cursor++;
	nb_start = expr + cursor;
	//printf("WHILE : %s\n", nb_start);
	i = 0;
	while (is_number(expr[cursor++]) || (i == 0 && nb_start[i] == '-'))
	{
		nb[i] = expr[cursor - 1];
		i++;
	}
	//printf("NB : %s\n", nb);
	//printf("%d\n", result);
	printf("1st %c\n", first_operand);
	printf("2nd %c\n", second_operand[0]);
	//printf("atoi %d\n", ft_atoi(nb));
	//printf("RESSULLLT : %d\n", result - ft_atoi(nb));
	
	if (second_operand[0] == '\0' || second_operand[0] == ')')
	{
		if (first_operand == '+')
			return (result + ft_atoi(nb));
		if (first_operand == '-')
			return (result - ft_atoi(nb));
	}
	if (is_first_operator(second_operand[0]))
	{
		if (first_operand == '+')
			return (result + evaluate_product_expr(second_operand, ft_atoi(nb)));
		if (first_operand == '-')
			return (result - evaluate_product_expr(second_operand, ft_atoi(nb)));
	}
	if (first_operand == '+')
		return (result + ft_atoi(nb) + evaluate_base_expr(second_operand, result));
	else if (first_operand == '-')
		return (result - ft_atoi(nb) + evaluate_base_expr(second_operand, result));
}

int	evaluate_base_expr(char *expr, int result)
{
	char first_operand;
	char *second_operand;
	int nb_l;
	int cursor;

	printf("'Evaluate product : %s\n", expr);
	//printf("\n'%s'\n", expr);
	cursor = 0;
	while (expr[cursor] == ' ')
		cursor++;
	if (!is_operator(expr[cursor]))
		first_operand = '+';
	else
		first_operand = expr[cursor];
	cursor++;
	while (expr[cursor] != '\0' && expr[cursor] != ')' && !(is_valid_operator(expr[cursor], expr[cursor + 1])))
		cursor++;	
	second_operand = expr + cursor;
	return calculate_base_result(expr, first_operand, second_operand, result);
}

/*char *calculate_expr(char *expr)
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
*/

char *link_expr(char *expr)
{
	char *copy;
	int i;
	int size;

	printf("ORIGGG '%s'", expr);
	if (expr[0] == ')' || expr[0] == '\0')
		return ("");
	i = 0;
	size = 0;
	while (!is_number(expr[size]) && expr[size] != '(')
	{
 		printf("CHAR : %c\n", expr[i]);
		size++;
	}
	printf("SIZZEEE : %d\n", size);
	copy = (char*)malloc(sizeof(char) * (size + 1));
	i = 0;
	while (i++ < size)	
		copy[i - 1] = expr[i - 1];
	copy[i] = '\0';
	printf("LIIIINKKK : '%s'", copy);
	return (copy);
}

int	ft_strlen(char *str)
{
	int size;

	size = 0;
	while (*(str++) != '\0')
		size++;
	return (size);
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
	int		result;
	char *test;

	result = 0;
	cursor = 0;
	len_expr = 0;

	if (!str[cursor] || str[cursor] == ')')
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
				{	
					depth_expr++;
				}
				if (str[sub_expr_cursor] == ')')
					depth_expr--;
				len_expr++;
				sub_expr_cursor++;
			}
			char *eval_m_expr = eval_expr(start_expr + 1);
			char *eval_e_expr = eval_expr(start_expr + len_expr + 2);
			char *link = link_expr(start_expr + len_expr + 2);
			test = (char*)malloc(pos_start_expr + strlen(eval_m_expr) + strlen(link) + strlen(eval_e_expr) + 1);
			int nawak = 0;
			while (copy[nawak] != '\0')
			{
				test[nawak] = copy[nawak];
				nawak++;
			}
			int i = 0;
			while (eval_m_expr[i] != '\0')
			{
				test[nawak] = eval_m_expr[i];
				nawak++;
				i++;
			}
			i = 0;
			while (link[i] != '\0')
			{
				test[nawak] = link[i];
				nawak++;
				i++;
			}
			i = 0;
			while (eval_e_expr[i] != '\0')
			{
				test[nawak] = eval_e_expr[i];
				nawak++;
				i++;
			}
			test[nawak] = '\0';
			cursor++;
			return ft_itoa(evaluate_base_expr(test, 0));
			//printf("Start : %d", pos_start_expr);
			//printf("p :%d\n", pos_start_expr + len_expr + 1);
			//printf("s :%s\n", start_expr + len_expr + 1);
			//printf("Eval expr : %s\n", eval_expr(start_expr + 1));
			//printf("Eval after :%s\n", eval_expr(start_expr + len_expr + 2));
		}
		if (str[cursor] == ')')
		{	
			printf("String evaluated : %s\n", str);
			//printf("Curs: %d\n", cursor);
			//printf("Str : %s\n", str);

			return ft_itoa(evaluate_base_expr(str, 0));
		}
		copy[cursor] = str[cursor];
		copy[cursor + 1] = '\0';
		cursor++;
	}
	return ft_itoa(evaluate_base_expr(str, 0));
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
