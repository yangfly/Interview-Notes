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
 * Input: v
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
    int getOne(vector<int>& profits, int start, int end) {
        int profit = 0;
        for (int i = start; i < end; i++) {
            profit = max(profit, profits[i]);
        }
        return profit;
    }

    int getTwo(vector<int>& profits, int start, int end) {
        int i = 0;
        for (i = start; i < end; i++) {
            if (profits[i] > 0)
                break;
        }
        if (i == end)
            return 0;
        else {
            int profit = profits[i];
            for (i = i + 1; i < end; i++) {
                if (profits[i] > 0)
                    break;
            }
            if (i == end)
                return profit;
            else
                return max(profit + getOne(profits, i, end), getTwo(profits, i, end));
        }
    }

    int maxProfit(vector<int>& prices) {
        vector<int> profits;
        bool buy = true;
        if (prices.size() > 1) {
            int buyin = prices[0];
            for (int i = 1; i < prices.size(); i++) {
                if (buy && prices[i - 1] < prices[i])
                    buy = false;
                else if (!buy && prices[i - 1] > prices[i])
                    buy = true;
                profits.push_back(prices[i - 1] - buyin);
                buyin = prices[i - 1];
            }
            if (!buy)
                profits.push_back(prices[prices.size() - 1] - buyin);
        }

        return getTwo(profits, 0, profits.size());
    }
};


// getTwo = max(getAttach, getTwo(1:))
// getAttach = for all attach_positive:
//                 attach_positive + getOnlyOne(1:)


// [
//     {
//         "key": "alt+i",
//         "command": "leetcode.signin",
//         "when": "editorFocus"
//     },
//     {
//         "key": "alt+s",
//         "command": "leetcode.searchProblem",
//         "when": "editorFocus"
//     },
//     {
//         "key": "alt+t",
//         "command": "leetcode.testSolution",
//         "when": "editorFocus"
//     }
// ]
