/* Best Optimization technique for this question is to think the minval 


    Logic :- insted of trying the every permutation just look for the minVal befor that day so that we will get the 
    maxProfit  right .

*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minval = INT_MAX ;
        int mxProfit = 0 ;

        for(int i=0 ; i<prices.size() ; i++){
            mxProfit = max(mxprofit , prices[i]-minval) ;
            minval = min(minval , prices[i]) ;
        }
        return mxprofit ;
    }
};


/*
   TC = 0(n) 
   SC = 0(1)
*/

