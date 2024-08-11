#include "Wallet.h"
#include<iostream>
#include "CSVReader.h"
#include<string>

Wallet::Wallet()
{

}

// insert currency to the wallet
void Wallet::insertCurrency(std::string type, double amount)
{
    double balance;
    if(amount < 0)
    {
        throw std::exception{};
    }
    if(currencies.count(type) == 0) // not there yet
    {
        balance = 0;
    }
    else    // is there
    {
        balance = currencies[type];
    }
    
    balance += amount;
    currencies[type] = balance;
}

// remove currency from the wallet
bool Wallet::removeCurrency(std::string type, double amount)
{
    double balance;
    if(amount < 0)
    {
        return false;
    }
    if(currencies.count(type) == 0) // not there yet
    {
        std::cout << "No currency for " << type << std::endl;
        return false;
    }
    else    // is there - do we have enough
    {
        if(containsCurrency(type, amount))  // we have enough
        {
            std::cout << "Removing " << type << ": " << amount << std::endl;
            currencies[type] -= amount;
            return true;
        }
        else    return false;
    }
    
    // balance += amount;
    // currencies[type] = balance;    
}

// check if the wallet contains this much currency or more
bool Wallet::containsCurrency(std::string type, double amount)
{
    if(currencies.count(type) == 0) // not there yet
        return false;

    else    return currencies[type] >= amount;
}
        
std::string Wallet::toString()
{
    std::string s;
    for(std::pair<std::string, double> pair: currencies)
    {
        std::string currency = pair.first;
        double amount = pair.second;
        s += currency + " : " + std::to_string(amount) + "\n";
    }
    return s;
}

bool Wallet::canFulfillOrder(OrderBookEntry order)
{
    std::vector<std::string> currs = CSVReader::tokenise(order.product, '/');
    // ask
    if(order.order_type == OrderBookType::ask)
    {
        double amount = order.amount;
        std::string currency = currs[0]; 
        std::cout << "Wallet::canFulfillOrder " << currency << " : " << amount << std::endl;
        return containsCurrency(currency, amount);
    }
    // bid
    if(order.order_type == OrderBookType::bid)
    {
        double amount = order.amount * order.price;
        std::string currency = currs[1];
        std::cout << "Wallet::canFulfillOrder " << currency << " : " << amount << std::endl;        
        return containsCurrency(currency, amount);
    }

    return false;
}

void Wallet::processSale(OrderBookEntry& sale)
{
    std::vector<std::string> currs = CSVReader::tokenise(sale.product, '/');
    // ask
    if(sale.order_type == OrderBookType::asksale)
    {
        double outgoingAmount = sale.amount;
        std::string outgoingCurrency = currs[0]; 
        double incomingAmount = sale.amount * sale.price;
        std::string incomingCurrency = currs[1];

        currencies[incomingCurrency] += incomingAmount;
        currencies[outgoingCurrency] -= outgoingAmount;
    }
    // bid
    if(sale.order_type == OrderBookType::bidsale)
    {
        double incomingAmount = sale.amount;
        std::string incomingCurrency = currs[0]; 
        double outgoingAmount = sale.amount * sale.price;
        std::string outgoingCurrency = currs[1];

        currencies[incomingCurrency] += incomingAmount;
        currencies[outgoingCurrency] -= outgoingAmount;        
    }  
}