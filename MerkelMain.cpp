#include "MerkelMain.h"
#include<iostream>
#include<vector>
#include "OrderBookEntry.h"
#include "CSVReader.h"
#include<limits>
// #include "Wallet.h"

MerkelMain::MerkelMain()
{

}

void MerkelMain::init()
{
    int input;
    currentTime = orderBook.getEarliestTime();
    
    wallet.insertCurrency("BTC", 10);
    
    while(true)
    {
        printMenu();
        input = getUserOption();
        processUserOption(input);
    }
}

void MerkelMain::printMenu()
{
    // 1 print help
    std::cout << "1: Print help" << std::endl;
    // 2 print exchange stats
    std::cout << "2: Print exchange stats" << std::endl;
    // 3 make an offer
    std::cout << "3: Make an offer" << std::endl;
    // 4 make a bid
    std::cout << "4: Make a bid" << std::endl;
    // 5 print wallet
    std::cout << "5: Print wallet" << std::endl;
    // 6 continue
    std::cout << "6: Continue" << std::endl;  
    std::cout << "=========================" << std::endl;

    std::cout << "Current time is: " << currentTime << std::endl;
}

void MerkelMain::printHelp()
{
    std::cout << "Help - your aim is to make money. Analyze the market and make bids and offers" << std::endl;

}

void MerkelMain::printMarketStats()
{
    for(std::string const p: orderBook.getKnownProducts())
    {
        std::cout << "Product: " << p << std::endl;
        std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask, p, currentTime);
        std::cout << "Asks seen: " << entries.size() << std::endl;
        std::cout << "Max ask: " << OrderBook::getHighPrice(entries) << std::endl;
        std::cout << "Min ask: " << OrderBook::getLowPrice(entries) << std::endl;
    }

    // std::cout << "OrderBook contains: " << orders.size() << " entries" << std::endl;
    // unsigned int bids = 0;
    // unsigned int asks = 0;
    // for(OrderBookEntry& e: orders)
    // {
    //     if(e.order_type == OrderBookType::ask)
    //     {
    //         asks++;
    //     }
    //     if(e.order_type == OrderBookType::bid)
    //     {
    //         bids++;
    //     }
    // }
    // std::cout << "OrderBook asks: " << asks << " bids: " << bids << std::endl;
}

void MerkelMain::enterAsk()
{
    std::cout << "Make an offer - enter the amount: product, price, amount, eg ETH/BTC,200,0.5" << std::endl;
    std::string input;
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::getline(std::cin, input);    

    std::vector<std::string> tokens = CSVReader::tokenise(input,',');
    if(tokens.size() != 3)
    {
        std::cout << "MerkelMain::enterAsk Bad input! " << input << std::endl;
    }
    else
    {
        try
        {
            OrderBookEntry obe = CSVReader::stringsToOBE(
                tokens[1],
                tokens[2],
                currentTime,
                tokens[0],
                OrderBookType::ask
            );

            obe.username = "simuser";
            if(wallet.canFulfillOrder(obe))
            {
                std::cout << "Wallet looks good." << std::endl;
                orderBook.insertOrder(obe);
            }
            else
            {
                std::cout << "Wallet has insufficient funds." << std::endl;
            }
            
        }

        catch(const std::exception& e)
        {
            std::cout << "MerkelMain::enterAsk Bad input " << std::endl;
        }
    }

    std::cout << "You typed: " << input << std::endl;
}

void MerkelMain::enterBid()
{
    std::cout << "Make a bid - enter the amount: product, price, amount, eg ETH/BTC,200,0.5" << std::endl;
    std::string input;
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::getline(std::cin, input);    

    std::vector<std::string> tokens = CSVReader::tokenise(input,',');
    if(tokens.size() != 3)
    {
        std::cout << "MerkelMain::enterBid Bad input! " << input << std::endl;
    }
    else
    {
        try
        {
            OrderBookEntry obe = CSVReader::stringsToOBE(
                tokens[1],
                tokens[2],
                currentTime,
                tokens[0],
                OrderBookType::bid
            );

            obe.username = "simuser";
            if(wallet.canFulfillOrder(obe))
            {
                std::cout << "Wallet looks good." << std::endl;
                orderBook.insertOrder(obe);
            }
            else
            {
                std::cout << "Wallet has insufficient funds." << std::endl;
            }
            
        }

        catch(const std::exception& e)
        {
            std::cout << "MerkelMain::enterBid Bad input " << std::endl;
        }
    }

    // std::cout << "Make a bid - enter the amount" << std::endl;
}

void MerkelMain::printWallet()
{
    std::cout << wallet.toString() << std::endl;
}

void MerkelMain::gotoNextTimeFrame()
{
    std::cout << "Going to next time frame" << std::endl;
    std::vector<OrderBookEntry> sales = orderBook.matchAsksToBids("ETH/BTC", currentTime);
    std::cout << "Sales: " << sales.size() << std::endl;
    for(OrderBookEntry& sale: sales)
    {
        std::cout << "Sale price: " << sale.price << " amount " << sale.amount << std::endl;
        if(sale.username == "simuser")
        {
            // update the wallet
            wallet.processSale(sale);
        }
    }
    currentTime = orderBook.getNextTime(currentTime);
}

int MerkelMain::getUserOption()
{
    int user_option = 0;
    std::string line;
    std::cout << "Type in 1-6" << std::endl;
    std::getline(std::cin, line);
    try
    {
        user_option = std::stoi(line);
    }
    catch(const std::exception& e)
    {
        // 
    }
    // std::cin >> user_option;
    std::cout << "You chose: " << user_option << std::endl;
    return user_option;
}

void MerkelMain::processUserOption(int user_option)
{
    if(user_option == 0)    // bad input
    {
        std::cout << "Invalid choice. Choose 1-6" << std::endl;
    }

    if(user_option == 1)    
    {
        printHelp();
    }

    if(user_option == 2)    
    {
        printMarketStats();
    }

    if(user_option == 3)    
    {
        enterAsk();
    }

    if(user_option == 4)    
    {
        enterBid();
    }

    if(user_option == 5)    
    {
        printWallet();
    }

    if(user_option == 6)    
    {
        gotoNextTimeFrame();
    }
}
