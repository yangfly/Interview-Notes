/*
 * [123] Best Time to Buy and Sell Stock III
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
 *
 * algorithms
 * Hard (30.85%)
 * Total Accepted:    113.1K
 * Total Submissions: 366.6K
 * Testcase Example:  '[3,3,5,0,0,3,1,4]'
 *
 * Say you have an array for which the ith element is the price of a given
 * stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete at most two
 * transactions.
 * 
 * Note: You may not engage in multiple transactions at the same time (i.e.,
 * you must sell the stock before you buy again).
 * 
 * Example 1:
 * 
 * 
 * Input: [3,3,5,0,0,3,1,4]
 * Output: 6
 * Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit
 * = 3-0 = 3.
 * Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 =
 * 3.
 * 
 * Example 2:
 * 
 * 
 * Input: [1,2,3,4,5]
 * Output: 4
 * Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit
 * = 5-1 = 4.
 * Note that you cannot buy on day 1, buy on day 2 and sell them later, as you
 * are
 * engaging multiple transactions at the same time. You must sell before buying
 * again.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 * 
 */
static const auto ________ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int headProfit(int n, const vector<int>& deals, int start) {
        // for all increasing positive accumulated profit
        int pre = 0; // accumlated head profit
        int sum = 0; // head sum
        int mam = 0; // maximum profit
        for (int i = start; i < deals.size(); i++) {
            sum += deals[i];
            if (sum > pre) {
                mam = max(mam, sum + getProfit(n-1, deals, i+1));
                pre = sum;
            }
        }
        return mam;
    }

    int getProfit(int n, const vector<int>& deals, int start) {
        if (n == 0) return 0;

        // find first positive deal
        int i = start;
        for (; i < deals.size(); i++)
            if (deals[i] > 0) break;

        // no positive deal
        if (i == deals.size()) return 0;

        return max(headProfit(n, deals, i), getProfit(n, deals, i+1));
    }

    int maxProfit(vector<int>& prices) {
        vector<int> deals;
        bool buy = true;
        if (prices.size() > 1) {
            int buyin = prices[0];
            for (int i = 1; i < prices.size(); i++) {
                if (buy && prices[i - 1] < prices[i])
                    buy = false;
                else if (!buy && prices[i - 1] > prices[i])
                    buy = true;
                deals.push_back(prices[i - 1] - buyin);
                buyin = prices[i - 1];
            }
            if (!buy)
                deals.push_back(prices[prices.size() - 1] - buyin);
        }

        return getProfit(2, deals, 0);
    }
};
