#pragma once

#include "OrderBookEntry.h"
#include<vector>
#include<string>

class CSVReader
{
    public:
        CSVReader();

        // if not static, we would need to make instances of CSVreader
        // static -> no need to create instances of CSVreader beforehand
        static std::vector<OrderBookEntry> readCSV(std::string csvFile);   
        static std::vector<std::string> tokenise(std::string csvLine, char seperator);
        static OrderBookEntry stringsToOBE( std::string price,
                                            std::string amount,
                                            std::string timestamp,
                                            std::string product,
                                            OrderBookType OrderBookType );

    private:
        static OrderBookEntry stringsToOBE(std::vector<std::string> strings);
};