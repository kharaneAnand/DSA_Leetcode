
/*
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future 
to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/

/*
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
*/


/*Brute Force for this is to check for the every possible combination whose profit is the maximum 
and return the maximum one okey 

        TC = 0(n^2) 
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int res  = 0 ; 
        for(int i=0 ; i<prices.size() ;i++){
            int mx = 0 ;
            for(int j=i+1 ; j<prices.size() ; j++){
                mx = max(prices[j]-prices[i] , mx) ;
            }
            res = max(res , mx) ;
        }
        return res ;
    }
};