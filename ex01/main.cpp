/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 12:51:36 by lenakach          #+#    #+#             */
/*   Updated: 2026/03/21 19:49:35 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void	printStack(std::stack<int> copy)
{
	while (!copy.empty())
	{
		std::cout << copy.top() << " ";
		copy.pop();
	}
	std::cout << std::endl;
}

bool	isoperateur(int c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (true);
	return (false);
}

bool	readToken(std::string arg, rpnStack &calcul)
{
	size_t	i;

	i = 0;
	while (isspace(arg[i]) && i < arg.length())
		i++;
	while (i < arg.length())
	{
		std::string res;
		while (i < arg.length() && isspace(arg[i]))
			i++;
		while (i < arg.length() && !isspace(arg[i]))
		{
			res += arg[i];
			i++;
		}
		if (res.length() == 1 && isdigit(res[0]))
			calcul.pushToStack(res);
		else if (res.length() == 1 && isoperateur(res[0]))
		{
			calcul.doOperation(res[0]);
		}
		else
			return false ;
	}
	if (calcul.getSize() != 1)
		return false;
	return (true);
}

int	main(int ac, char **av)
{
	rpnStack calcul;
	if (ac != 2)
	{
		std::cerr << "Wrong number of arguments" << std::endl;
		return (1);
	}
	try
	{
		if (!readToken(av[1], calcul))
		{
			std::cerr << "Error" << std::endl;
			return (1);
		}
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
		return 1; 
	}
	calcul.printprint();
	return (0);
}