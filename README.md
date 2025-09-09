# Crypto-Currency-Trading-Platform

A console-based Cryptocurrency trading platform simulating the experience of buying and selling cryptocurrencies. The program works with a real data set representing order book of a real currency exchange platform. 

After compiling and running, it reads in the CSV data and identifies any bad rows(part of error handling). And then the program prints out a text-based interactive menu.
```
1: Print help
2: Print exchange stats
3: Make an offer
4: Make a bid
5: Print wallet
6: Continue
==============
Current time is: 2020/03/17 17:01:24.884492
Type in 1-6
```
Print help - prints a help message<br>
Print exchange stats: The platform analyzes all the available things in the order book for the current time frame, and it prints out what the minimum and maximum for each pair is. If you're looking to snag a good deal, you'd likely want to set your buying offer at that price. That's the lowest price you'll find for it. 
I've made up my mind to sell something, so the first step is to determine if I have anything to sell. By checking my wallet, I can see what I currently have available. To check contents of wallet, we press "5".
Make an offer: shows this line
```make an offer - enter the amount: product,price, amount, eg ETH/BTC,200,0.5 ```
We make the ask/offer, and program sees if wallet can fulfill order or not. Then if wallet can fulfill order, then to process that order, we press "6". 
Then the matching engine comes into play, it looks at all the orders in the order book and it tries to match them so that if someone's offering something really cheap, then it'll give them the best price above that is available. 
Similar demonstration can be done for making a bid.


   
Order book data
The CSV file contains data from actual transactions that occurred in 2020, with each line representing an order in the order book. This order book reflects the offers made by individuals to buy and sell items. The platform's primary function is to maintain a record of these offers, where sellers indicate their asking prices and buyers specify their bidding prices. The exchange's role is to match these bids and asks, facilitating trades between parties. 

- Ask is when someone's offering to sell something.
```
2020/03/17 17:01:24.884492,ETH/BTC,ask,0.02192039,0.4014997
```  
- Let's say in row 60 of [20200317.csv](20200317.csv), the person has got 0.401 Ethereum for sale and he/she will sell it at a cost of 0.021 Bitcoin.
- Bid is when someone's offering to buy something
```
2020/03/17 17:01:24.884492,ETH/BTC,bid,0.02187308,7.44564869
```
- Let's say in line 1 of [20200317.csv](20200317.csv), the person is offering to buy upto 7.44 Ethereum at a cost of 0.021 Bitcoin.

### Why C++?
Because it is efficient, fast and powerful.  

I used Python for prototyping but I did not make the entire project in python because of its speed. But later on, I may make this entire project in python and compare it with this one.
