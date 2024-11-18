class Solution {
public:
    int maxProfit(vector<int>& prices) {
    /*  add first elemt to hash map as index/value
        use first elememt as bestDayToBuy to start off with
        potentionProfit = 0 to start
        for every element after the first, compare w. buyDay to see if its lower
        if lower, buyDay = current element && sellDay = current element ( avoid a previous index as sell date)
        potentialProfit = max(potentialProfit, current element - buyDay);
        return potenrialProfit. */

        int buyDay, potentialProfit = 0;
        if(prices.empty() || prices.size() == 1)
            return 0;

        buyDay = prices[0];

        for(int i = 1 ; i < prices.size(); i++){
            if(prices[i] < buyDay)
                buyDay = prices[i];
            potentialProfit = std::max(potentialProfit, prices[i]-buyDay);     
        }
        return potentialProfit;
    }
};