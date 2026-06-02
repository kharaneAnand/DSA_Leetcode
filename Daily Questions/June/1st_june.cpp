// 2144. Minimum Cost of Buying Candies With Discount 
//Leetcode 2144 :- 


/*
A shop is selling candies at a discount. For every two candies sold, the shop gives a third candy for free.
The customer can choose any candy to take away for free as long as the cost of the chosen candy
 is less than or equal to the minimum cost of the two candies bought.
For example, if there are 4 candies with costs 1, 2, 3, and 4, and the customer buys candies with
 costs 2 and 3, they can take the candy with cost 1 for free, but not the candy with cost 4.
Given a 0-indexed integer array cost, where cost[i] denotes the cost of the ith candy, 
return the minimum cost of buying all the candies.

*/ 

/*
Input: cost = [6,5,7,9,2,2]
Output: 23
Explanation: The way in which we can get the minimum cost is described below:
- Buy candies with costs 9 and 7
- Take the candy with cost 6 for free
- We buy candies with costs 5 and 2
- Take the last remaining candy with cost 2 for free
Hence, the minimum cost to buy all candies is 9 + 7 + 5 + 2 = 23.
*/


class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int mincost = 0;

        sort(cost.begin(), cost.end() , greater<int>());

        for (int i = 0; i < cost.size(); i++) {
            if ((i + 1) % 3 != 0) {
                mincost += cost[i];
            }
        }

        return mincost;
    }
};