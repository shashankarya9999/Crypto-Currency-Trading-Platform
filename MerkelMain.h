#pragma once
#include<vector>
#include "OrderBookEntry.h"
#include "OrderBook.h"
#include "Wallet.h"

class MerkelMain
{
    public:
        MerkelMain();
        /* Call this to start the sim */
        void init();
    
    private:
        void printMenu();
        void printHelp();
        void printMarketStats();
        void enterAsk();
        void enterBid();
        void printWallet();
        void gotoNextTimeFrame();
        int getUserOption();
        void processUserOption(int user_option);

        std::string currentTime;

        OrderBook orderBook{"20200317.csv"};
        std::vector<OrderBookEntry> orders;

        Wallet wallet;
};