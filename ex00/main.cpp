/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leanakache <leanakache@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 00:54:53 by leanakache        #+#    #+#             */
/*   Updated: 2026/02/19 22:01:13 by leanakache       ###   ########.fr       */
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
    database.loadDatabase("data.csv");
    //database.printDatabase();
    if (!parseFile(av[1], database))
        return 1;
    return 0;
}