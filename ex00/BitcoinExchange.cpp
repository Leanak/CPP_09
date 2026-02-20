/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leanakache <leanakache@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 15:11:27 by leanakache        #+#    #+#             */
/*   Updated: 2026/02/19 22:00:52 by leanakache       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

double BitcoinExchange::getRate(const std::string & date) const
{
    std::map<std::string, double>::const_iterator it = database.lower_bound(date);

    if (it == database.end() || it->first != date)
        --it;
    return (it->second);
}


void BitcoinExchange::printDatabase(void)
{
    for (std::map<std::string, double>::const_iterator it = database.begin(); it != database.end(); it++)
       std::cout << it->first << " -> " << it->second << std::endl;
}

bool checkRate(std::string rate)
{
    int dotCount = 0;
    
    if (rate.empty())
        return (errorMsg("Error: bad value => " + rate), false);
    
    for (size_t i = 0; i < rate.length(); i++)
    {
        if (rate[i] == '.')
        {
            dotCount++;
            if (dotCount > 1)
                return (errorMsg("Error: bad value => " + rate), false);
        }
        else if (!isdigit(static_cast<unsigned char>(rate[i])))
            return (errorMsg("Error: bad value => " + rate), false);
    }
    double number = std::strtod(rate.c_str(), NULL);
    if (number > std::numeric_limits<float>::max())
        return (errorMsg("Error: value too large for float in database.csv"), false);
    if (number < 0)
        return (errorMsg("Error: not a positive number."), false);
    return true ;
}

bool BitcoinExchange::loadDatabase(const std::string &filename)
{
    std::ifstream file(filename);
    std::string line;
    int index = 0;

    if (!file.is_open())
        return (errorMsg("Error: could not open the database file"),false);
     while (getline(file, line))
    {
        ++index;
        if (index == 1 && line == "date,exchange_rate")
            continue ;
        size_t comaPos = line.find(',');

        if (comaPos == std::string::npos)
            return false ;
        
        std::string date = trim(line.substr(0, comaPos), " \t\n\r\v\f");
        std::string rateStr = trim(line.substr(comaPos + 1), " \t\n\r\v\f");
        if (!checkDate(date) || !checkRate(rateStr))
            return (errorMsg("Error: wrond data in database => " + line), false);
        
        double rate = std::strtod(rateStr.c_str(), NULL);
        database[date] = rate;
    }
    if (index == 0)
        return (errorMsg("Error: Empty database"), false); 
    
    return true ;
}

BitcoinExchange::~BitcoinExchange(void)
{
    //std::cout << "Destructor called" << std::endl;
    //Map est automatiquement créée et vide
}

BitcoinExchange::BitcoinExchange(void)
{
    //std::cout << "Constructor by default called" << std::endl;
    //Map est automatiquement créée et vide
}