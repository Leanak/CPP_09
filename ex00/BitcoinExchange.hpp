/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leanakache <leanakache@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 00:55:20 by leanakache        #+#    #+#             */
/*   Updated: 2026/02/19 21:59:23 by leanakache       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdbool>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <cstdio>
#include <map>


#define RED     "\033[0;91m"
#define GREEN   "\033[0;92m"
#define MAGENTA "\033[0;95m"

#define BOLD       "\033[1m"
#define UNDERLINE  "\033[4m"
#define ITALIC     "\033[3m"

#define END "\033[0m"

class BitcoinExchange ;

//parsing
void errorMsg(std::string message);
bool    parseFile(char *file, BitcoinExchange & database);
bool checkDate(std::string & line);
std::string trim(std::string line, const std::string toTrim);

class BitcoinExchange
{
    private :
        std::map<std::string, double> database;
    public :
        //Fonction pour chercher la ligne d'input dans la database
        double getRate(const std::string & date) const;
        //Charger database
        bool loadDatabase(const std::string &filename);
        void printDatabase(void);
        // constructeur copie
        //Operateur = 
        BitcoinExchange(void);
        ~BitcoinExchange(void);
};
