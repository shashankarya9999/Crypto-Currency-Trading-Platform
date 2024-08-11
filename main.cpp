#include<iostream>
#include<string>
#include<vector>
#include "OrderBookEntry.h"
#include "MerkelMain.h"
#include "CSVReader.h"
#include "Wallet.h"

int main()
{
    MerkelMain app{};
    app.init();
    // // CSVReader reader;
    // CSVReader::readCSV("20200317.csv");   
    // Wallet wallet;
    // wallet.insertCurrency("BTC", 5);
    // wallet.insertCurrency("USDT", 10000);
    // // std::cout << "Wallet has BTC " << wallet.containsCurrency("USDT", 10) << std::endl;
    // std::cout << wallet.toString() << std::endl;
    // wallet.removeCurrency("USDT", 1000);
    // std::cout << wallet.toString() << std::endl;
}

// enum class OrderBookType{bid, ask};

// double price = 5319.450228;
// double amount = 0.00020075;
// std::string timestamp{"2020/03/17 17:01:24.884492"};
// std::string product{"BTC/USDT"};   
// OrderBookType order_type = OrderBookType::ask;

// std::vector<double> prices;
// std::vector<double> amounts;
// std::vector<std::string> timestamps;
// std::vector<std::string> products;
// std::vector<OrderBookType> order_types;

// prices.push_back(5000.01);
// amounts.push_back(0.001);
// timestamps.push_back("2020/03/17 17:01:24.884492");
// products.push_back("BTC/USDT");
// order_types.push_back(OrderBookType::bid);

// prices.push_back(10.01);
// amounts.push_back(0.001);
// timestamps.push_back("2020/03/17 17:01:24.884492");
// products.push_back("BTC/USDT");
// order_types.push_back(OrderBookType::bid);


// std::cout << "prices: " << prices[0] << std::endl;
// std::cout << "prices: " << prices[1] << std::endl;

// while(true)
// {
//     printMenu();
//     int user_option = getUserOption();
//     processUserOption(user_option);
// }

// std::vector<OrderBookEntry> orders;
// orders.push_back(   OrderBookEntry{
//                         1000,
//                         0.02,
//                         "2020/03/17 17:01:24.884492",
//                         "BTC/USDT",
//                         OrderBookType::bid
//                     }
//                 );

// orders.push_back(   OrderBookEntry{
//                     2000,
//                     0.02,
//                     "2020/03/17 17:01:24.884492",
//                     "BTC/USDT",
//                     OrderBookType::bid
//                 }
//             );


// OrderBookEntry order1{
//     1000, 
//     0.02, 
//     "2020/03/17 17:01:24.884492",
//     "BTC/USDT",
//     OrderBookType::bid
// };

// orders.push_back(order1);

// order1.price = 100000;
// order1.amount = 0.002;
// order1.timestamp = "2020/03/17 17:01:24.884492";
// order1.product = "BTC/USDT";
// order1.order_type = OrderBookType::bid;

// std::cout << "PRICE: " << orders[1].price << std::endl;

// for(OrderBookEntry& order : orders)
// {
//     std::cout << "The price is " << order.price << std::endl;
// }

// for(unsigned int i = 0; i < orders.size(); ++i)
// {
//     std::cout << "The price is " << orders[i].price << std::endl;
// }

// for(unsigned int i = 0; i < orders.size(); ++i)
// {
//     std::cout << "The price is " << orders.at(i).price << std::endl;
// }

// return 0;
