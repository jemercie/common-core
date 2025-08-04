/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:55:27 by jemercie          #+#    #+#             */
/*   Updated: 2023/11/28 13:55:52 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <iostream>
# include <ctime>
# include <fstream>
# include <cstdlib>
# include <cstring>
# include <utility>
# include <regex.h>
# include <limits>
# include <iomanip>
# include <cmath>

void putError(int err, const char *str, int i);

class BitcoinExchange
{
    public:
        BitcoinExchange(const char *csvFile, const char *inputFile);
        ~BitcoinExchange();

		class ProblemOpeningFileException : public std::exception
		{
			const char* what() const throw();
		};


    private:
        void            _calculBtcValues();

        BitcoinExchange(const BitcoinExchange &src);
        BitcoinExchange &operator=(BitcoinExchange const & rhs);
        void    setTodayDate();
        void    parseCsvFile();
        bool    checkCsvLine(const char *date, float exchange_rate, int i);
        bool    regexCheckFormat(const char *testedStr, const char *regex, int err, int line);
        bool    checkInputLine(const char *date, float value);
        void    displayResultLine(std::string date, float value);

        std::map<std::string, float>    _btcData;
        std::fstream                    _csvFile;
        std::fstream                    _inputFile;
        char                            _todayDate[11];
        const char*                     _csvFilename;
        const char*                     _inputFilename;
        const char*                     _btcCreationDate;
        std::string                     _regex[4];


};

#endif
