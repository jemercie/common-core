/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:55:02 by jemercie          #+#    #+#             */
/*   Updated: 2023/11/28 13:55:17 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool BitcoinExchange::regexCheckFormat(const char *testedStr, const char *regex, int err, int line)
{
    regex_t reg;

    if (regcomp(&reg, regex, REG_EXTENDED) != 0)
    {
        std::cout << "problem occured compiling regex eee\n";
        return (0);
    }
    int res = regexec(&reg, testedStr, (size_t) 0, NULL, 0);
    regfree(&reg);
    if (res == 0)
        return (1);
    putError(err, testedStr, line);
    return (0);
}

void BitcoinExchange::parseCsvFile()
{
    int i = 1;
    std::string csvLine;
    std::pair<std::map<std::string, float>::iterator, bool> checkInsert;

    std::getline(this->_csvFile, csvLine, '\n');
    if (!regexCheckFormat(csvLine.c_str(), this->_regex[0].c_str(), 0, i))
        return;
    for (; std::getline(this->_csvFile, csvLine); ++i)
    {
        if (!csvLine.empty())
        {
            if (regexCheckFormat(csvLine.c_str(), this->_regex[1].c_str(), 1, i))
            {
                std::string date = csvLine.substr(0, 10);
                std::string exchange_rate = csvLine.substr(11, csvLine.length());
                if (checkCsvLine(date.c_str(), std::strtof(exchange_rate.c_str(), NULL), i))
                {
                    checkInsert = this->_btcData.insert(std::make_pair(date.c_str(), std::strtof(exchange_rate.c_str(), NULL)));
                    if (!(checkInsert.second))
                    putError(2, NULL, i);
                }
            }
        }
    }
}

bool BitcoinExchange::checkCsvLine(const char *date, float exchange_rate, int i)
{
    if (std::strcmp(date, this->_todayDate) >= 0)
    {
        putError(3, date, i);
        return (0);
    }
    else if (std::strcmp(date, this->_btcCreationDate) < 0)
    {
        putError(4, date, i);
        return (0);
    }
    if (exchange_rate < 0)
    {
        std::cerr << "csv file error: line " << i << ": wrong exchange rate : " << exchange_rate << ". It cannot be negative." << std::endl;
        return (0);
    }
    return (1);
}

void putError(int err, const char *str, int i)
{
    if (err == 0)
        std::cerr << "csv file error: line " << i << ": wrong header format : " << str << ". Must be \"date,exchange_rate\"." << std::endl;
    else if (err == 1)
        std::cerr << "csv file error: line " << i << ": wrong format, date must formatted like : YYYY-MM-DD and exchange rate must be a number." << std::endl;
    else if (err == 2)
        std::cerr << "csv file error: line " << i << ": there is already an exchange rate value at this date." << std::endl;
    else if (err == 3)
        std::cerr << "csv file error: line " << i << ": wrong date : " << str <<  ". You can't see the future, do you?" << std::endl;
    else if (err == 4)
        std::cerr << "csv file error: line " << i << ": wrong date : " << str <<  ". Bitcoins didn't exist yet, they were created on January 3, 2009." << std::endl;
    else if (err == 5)
        std::cerr << "Error: wrong input file header format : " << str << ". Must be \"date | value\". Program stop here." << std::endl;
    else if (err == 6)
        std::cerr << "No data concerning bitcoin exchange rate available, cannot calcul bitcoin values sorry." << std::endl;
    else if (err == 7)
        std::cerr << "Error: line must be formatted like : date YYYY-MM-DD | value." << std::endl;
}