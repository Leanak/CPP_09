/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputParsing.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 12:47:44 by leanakache        #+#    #+#             */
/*   Updated: 2026/03/21 19:47:29 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void errorMsg(std::string message)
{
    std::cerr << message << std::endl;
}

std::string trim(std::string line, const std::string toTrim)
{
    size_t start = line.find_first_not_of(toTrim);
    if (start == std::string::npos)
        return ("");
    size_t end = line.find_last_not_of(toTrim);
    return (line.substr(start, end  - start + 1));
}

bool checkValue(std::string & line)
{
    if (line.empty())
        return (errorMsg("Error: bad value => " + line), false);

    char *end;

    double number = std::strtod(line.c_str(), &end);

    if (*end != '\0')
        return (errorMsg("Error: bad value => " + line), false);
    if (number < 0)
        return (errorMsg("Error: not a positive number."), false);
    if (number > 1000)
        return (errorMsg("Error: too large a number."), false);
    
    return true ;
}

bool checkDate(std::string & line)
{
    int bisextile = 0; 
    int maxDay = 28;
    if (line.length() != 10)
        return (errorMsg("Error: bad date format => " + line), false);
        
    if (line[4] != '-' || line[7] != '-')
        return (errorMsg("Error: bad date format => " + line), false);
        
    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7)
            continue ; 
        if (!isdigit(static_cast<unsigned char>(line[i])))
            return (errorMsg("Error: bad date format => " + line), false);
    }
    int year = std::strtol(line.substr(0, 4).c_str(), NULL, 10);
    int month = std::strtol(line.substr(5, 2).c_str(), NULL, 10);
    int day = std::strtol(line.substr(8, 2).c_str(), NULL, 10);

    if (year < 0)
        return (errorMsg("Error: bad year => " + line), false);
    if (month < 1 || month > 12)
        return (errorMsg("Error: bad month => " + line), false);
    if (month == 2)
    {
        //gerer années bisextiles
        if (year % 4 == 0)
        {
            if (year % 400 == 0)
                bisextile = 1;
            else if (year % 100 == 0)
                bisextile = 0;
            else
                bisextile = 1;
        }
        if (bisextile)
            maxDay = 29;
        if (day < 1 || day > maxDay)
            return (errorMsg("Error: check bisextile year or not => " + line), false);   
    }
    else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        if (day < 1 || day > 31)
            return (errorMsg("Error: bad day => " + line), false);   
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day < 1 || day > 30)
            return (errorMsg("Error: bad day => " + line), false);
    }
    return (true);
}

bool checkFormat(std::string & line, BitcoinExchange & database)
{ 
    size_t pipePos = line.find('|');

    if (pipePos == std::string::npos)
        return (errorMsg("Error: bad input => " + line), false);
    std::string date = trim(line.substr(0, pipePos), " \t\n\r\f\v");
    std::string value = trim(line.substr(pipePos + 1), " \t\n\r\f\v");
    
    if (date.empty() || value.empty())
        return false ; 
    
    double trueValue = std::strtod(value.c_str(), NULL);
    
    if (!checkDate(date) || !checkValue(value))
        return false ;
    std::cout << date << " => " << value << " = " << database.getRate(date) * trueValue << std::endl;
    return true ;
}

bool    parseFile(char *file, BitcoinExchange & database)
{
    int emptyFile = 0;
    std::string line;
    std::ifstream input(file);
    int index = 0;
    
    if (!input.is_open())
            return (errorMsg("Error: could not open file"), false);
    while (getline(input, line))
    {
        ++index;
        if (index == 1 && line == "date | value")
        {
            emptyFile = 1;
            continue ;
        }
        if (!checkFormat(line, database))
        {
            continue ;
        }
    }
    if (index == 0 || (index == 1 && emptyFile == 1))
        return (errorMsg("Empty file"), false);
    return (true);
}