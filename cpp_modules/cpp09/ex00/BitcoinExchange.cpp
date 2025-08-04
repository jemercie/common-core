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

static bool checkDate(std::string date);

void    BitcoinExchange::_calculBtcValues()
{
    this->parseCsvFile();
    std::cout << " * * * * * * * * * * * * * * " << std::endl;
    if (this->_btcData.empty())
    {
        putError(6, NULL, 0);
        return;
    }
    std::cout << "        Btc values:" << std::endl;
    std::string inputLine;
    std::getline(this->_inputFile, inputLine, '\n');
    if (!regexCheckFormat(inputLine.c_str(), this->_regex[2].c_str(), 5, 0))
        return;
    for (; std::getline(this->_inputFile, inputLine);)
    {
        if (!inputLine.empty())
        {
            if (regexCheckFormat(inputLine.c_str(), this->_regex[3].c_str(), 7, 0))
            {
                std::string date = inputLine.substr(0, 10);
                std::string value = inputLine.substr(13, inputLine.length());
                if (checkInputLine(date.c_str(), std::strtof(value.c_str(), NULL)) && checkDate(date))
                    displayResultLine(date, std::strtof(value.c_str(), NULL));
            }
        }
    }
}

bool    BitcoinExchange::checkInputLine(const char* date, float value)
{
    if (std::strcmp(date, this->_todayDate) >= 0)
    {
        std::cerr << "Error: you can't see the future, do you?" << std::endl;
        return (0);
    }
    else if (std::strcmp(date, this->_btcCreationDate) < 0)
    {
        std::cerr << "Error: bitcoins didn't exist yet the "<< date << ", they were created on January 3, 2009." << std::endl;
        return (0);
    }
    if (value < 0)
    {
        std::cerr << "Error: the value (" << value << ") to convert can't be negative." << std::endl;
        return (0);
    }
    else if (value > 1000)
    {
        std::cerr << "Error: the value (" << value << ") to convert can't exceed 1000." << std::endl;
        return (0);
    }
    return (1);
}

static bool checkDate(std::string date)
{
    std::string year = date.substr(0, 4);
    std::string month = date.substr(5, 2);
    std::string day = date.substr(8, 9);
    if (!month.compare("02"))
    {
        long int yearl= std::strtol(year.c_str(), NULL, 10);
        if (yearl % 4 == 0 && std::strtol(day.c_str(), NULL, 10) <= 29)
            return (1);
        else if (yearl % 4 != 0 && std::strtol(day.c_str(), NULL, 10) <= 28)
            return (1);
    }
    else if (!month.compare("01") || month.compare("03") == 0 || !month.compare("05") || !month.compare("07") || !month.compare("08") || !month.compare("10") || !month.compare("12"))
    {
        long int dayl= std::strtol(day.c_str(), NULL, 10);
        if (dayl <= 31 && day1 != 0)
            return (1);
    }
    else if (!month.compare("04") || !month.compare("06") || !month.compare("09") || !month.compare("11"))
    {
        long int dayl= std::strtol(day.c_str(), NULL, 10);
        if (dayl <= 30 && day1 != 0)
            return (1);
    }
    std::cerr << "Error : invalid month (" << month << ") or day (" << day << ")." << std::endl;
    return (0);
}


void    BitcoinExchange::displayResultLine(std::string date, float value)
{
    std::map<std::string, float>::iterator element;
    element = this->_btcData.find(date);
    if (element == this->_btcData.end())
    {
        element = this->_btcData.upper_bound(date);
        element--;
        if (element == this->_btcData.end())
            element = this->_btcData.lower_bound(date);
    }
    float result = value * element->second;
    if (result > std::numeric_limits<float>::infinity())
        std::cerr << date << " - "  << value << " : ** UNSUPPORTED FORMAT ** the result is way too big." << std::endl;
    else
        std::cout << date << " - "  << value << " => " << result << std::endl;
}

BitcoinExchange::BitcoinExchange(const char *csvFilename, const char *inputFilename) : _csvFilename(csvFilename), _inputFilename(inputFilename), _btcCreationDate("2009-01-03")
{
    if (csvFilename == NULL || inputFilename == NULL)
        throw ProblemOpeningFileException();
    this->_csvFile.open(this->_csvFilename, std::fstream::in);
    if (!this->_csvFile)
        throw ProblemOpeningFileException();
    this->_inputFile.open(this->_inputFilename, std::fstream::in);
    if (!this->_inputFile)
    {
        _csvFile.close();
        throw ProblemOpeningFileException();
    }
    _regex[0] = "^date,exchange_rate$";
    _regex[1] = "^[0-9]{4}[-][0-9]{2}[-][0-9]{2}[,][+-]?[0-9]*([.]?[0-9]*)?$";
    _regex[2] = "^date[ ][|][ ]value$";
    _regex[3] = "^[0-9]{4}[-][0-9]{2}[-][0-9]{2}[ ][|][ ][+-]?[0-9]*([.]?[0-9]*)?$";
    setTodayDate();
    this->_calculBtcValues();
}

void    BitcoinExchange::setTodayDate()
{
    time_t rawtime;
    struct tm * timeinfo;
    time (&rawtime);
    timeinfo = localtime (&rawtime);

    strftime(this->_todayDate, 11, "%F" ,timeinfo);
}

BitcoinExchange::~BitcoinExchange()
{
    this->_csvFile.close();
}

const char *BitcoinExchange::ProblemOpeningFileException ::what() const  throw()
{
	return ("A problem occured opening the file.\n");
}
