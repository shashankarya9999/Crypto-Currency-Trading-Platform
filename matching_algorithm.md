### Matching Algorithm

asks = orderbook.asks
bids = orderbook.bids

sales = []
sort asks lowest first
sort bids highest first

for ask in asks:
    for bid in bids:
        if bid.price >= ask.price   # we have a match
            sale = new order()
            sale.price = ask.price

            # now work out how much was sold and 
            # create new bids and asks covering
            # anything that was not sold
            if bid.amount == ask.amount:    # bid completely clears ask
                sale.amount = ask.amount
                sales.append(sale)
                bid.amount = 0  # make sure the bid is not processed again
                # can do no more with this ask
                # go onto the next ask
                break
            
            if bid.amount > ask.amount: # ask is completely gone, slice the ask
                sale.amount = bid.amount
                sales.append(sale)
                # we adjust the bid in place
                # so it can be used to process the next ask
                bid.amount = bid.amount - ask.amount                
                # ask is completely gone, so go on to next ask
                break

            if bid.amount < ask.amount  # bid is completely gone, splice the ask
                sale.amount = bid.amount
                sales.append(sale)
                # update the ask
                # and allow further bids to process the remaining amount
                ask.amount = ask.amount - bid.amount
                bid.amount = 0  # make sure the bid is not processed again
                # some ask remains so go to the next bid
                continue