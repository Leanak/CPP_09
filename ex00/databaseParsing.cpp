/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   databaseParsing.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leanakache <leanakache@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 13:11:55 by leanakache        #+#    #+#             */
/*   Updated: 2026/02/19 20:59:16 by leanakache       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

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

bool parseLine(std::string & line)
{
    size_t comaPos = line.find(',');

    if (comaPos == std::string::npos)
        return false ;
        
    std::string date = trim(line.substr(0, comaPos), " \t\n\r\v\f");
    std::string rate = trim(line.substr(comaPos + 1), " \t\n\r\v\f");
    if (!checkDate(date) || !checkRate(rate))
        return false ;
    return true ;
}

bool parseDatabase(void)
{
    BitcoinExchange trueDatabase;
    
    std::ifstream database("data.csv");
    std::string line;
    int index = 0;

    if (!database.is_open())
        return (errorMsg("Error: could not open the database file"),false);
    while (getline(database, line))
    {
        ++index;
        if (index == 1 && line == "date,exchange_rate")
            continue ;
        if (!parseLine(line))
            return (errorMsg("Error: wrong format line in database => " + line), false);
    }
    if (index == 0)
        return (errorMsg("Error: Empty database"), false); 

    return true ;
}