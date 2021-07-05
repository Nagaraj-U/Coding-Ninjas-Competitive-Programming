/*
Write a class StockSpanner which collects daily price quotes for some stock, and returns the span of that stock's price for the current day.

The span of the stock's price today is defined as the maximum number of consecutive days (starting from today and going backwards) for which the price of the stock was 
less than or equal to today's price.

For example, if the price of a stock over the next 7 days were [100, 80, 60, 70, 60, 75, 85], then the stock spans would be [1, 1, 1, 2, 1, 4, 6].

 

Example 1:

Input: ["StockSpanner","next","next","next","next","next","next","next"], [[],[100],[80],[60],[70],[60],[75],[85]]
Output: [null,1,1,1,2,1,4,6]
Explanation: 
First, S = StockSpanner() is initialized.  Then:
S.next(100) is called and returns 1,
S.next(80) is called and returns 1,
S.next(60) is called and returns 1,
S.next(70) is called and returns 2,
S.next(60) is called and returns 1,
S.next(75) is called and returns 4,
S.next(85) is called and returns 6.

Note that (for example) S.next(75) returned 4, because the last 4 prices
(including today's price of 75) were less than or equal to today's price.
*/








//similar to finding next greater element to left

//we need to find index of next greater element to left, so we can determine count how many are lesser than        current

class StockSpanner {
public:
    int index;
    stack<pair<int,int>> s;
    
    StockSpanner() {
        index = -1;
    }
    
    int next(int price){
        index++;
        int ans;
        if(s.empty()){
            ans = -1;
            s.push({price,index});
            
        }else if(s.top().first <= price){
            
            while(!s.empty() && s.top().first <= price){
                s.pop();
            }
            if(s.empty()){
                ans = -1;
            }else{
                ans = s.top().second;
            }
            
            s.push({price,index});
            
        }else if(s.top().first > price){
            
            ans = s.top().second;
            s.push({price,index});
        }
        
        return (index - ans);  //if current index is 3 and next greater element is present at 1 index then , total of (3-1) =  2 elements are lesser than current price
    }
};
