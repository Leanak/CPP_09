/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 00:54:53 by leanakache        #+#    #+#             */
/*   Updated: 2026/03/21 19:47:18 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    BitcoinExchange database;
    
    if (ac != 2 || !av[1])
    {
        std::cout << "Wrong number of arguments" << std::endl;
        return 1;
    }
    try
    {
        database.loadDatabase("data.csv");
        if (!parseFile(av[1], database))
            return 1;
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
        return 1; 
    }
    return 0;
}