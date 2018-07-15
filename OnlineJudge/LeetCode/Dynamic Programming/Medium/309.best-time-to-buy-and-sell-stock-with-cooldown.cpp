/*
 * [309] Best Time to Buy and Sell Stock with Cooldown
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
 *
 * algorithms
 * Medium (42.38%)
 * Total Accepted:    65.6K
 * Total Submissions: 154.9K
 * Testcase Example:  '[1,2,3,0,2]'
 *
 * Say you have an array for which the ith element is the price of a given
 * stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete as many
 * transactions as you like (ie, buy one and sell one share of the stock
 * multiple times) with the following restrictions:
 * 
 * 
 * You may not engage in multiple transactions at the same time (ie, you must
 * sell the stock before you buy again).
 * After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1
 * day)
 * 
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3,0,2]
 * Output: 3 
 * Explanation: transactions = [buy, sell, cooldown, buy, sell]
 * 
 * 
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int pre_buy, buy(INT_MIN);  // #include <limits.h>
        int pre_sell(0), sell(0);
        for (int i = 0; i < prices.size(); i++) {
            pre_buy = buy;
            buy = max(pre_buy, pre_sell - prices[i]);
            pre_sell = sell;
            sell = max(pre_sell, pre_buy + prices[i]);
        } 
    }
};
