#include <iostream>
#include <vector>
using namespace std;

/**
*  FUNCTION SIGNATURE:
 * int getMaxProfit(vector<int> &prices)
 * PURPOSE:
 * recommends the maximum profit for an investor by placing as many buy and sell orders in the time span
 * PARAMETER:
 *  vector<int> &prices
 * RETURN VALUE:
 *  returns the profit after buying and selling
*/
int getMaxProfit(vector<int> &prices)
{
    // cycle through vector to determine if current price is less than future price(s)
    // repeat until loop finds a price to buy
    // if none, return 0
    int timeInstance = 0;
    int maxProfit = 0;
    while(timeInstance < prices.size())
    {
        int buy = 0;
        int sell = 0;
        for(int i = timeInstance; i <= prices.size(); i++)
        {
            for(int j = timeInstance; j <= prices.size(); j++)
            {
                if (buy == 0)
                {
                    if(prices[i] < prices[j])
                    {
                        buy = prices[i];
                        // advances time along x-axis to prevent infinite loops
                        timeInstance = i;
                        i = prices.size();
                        j = prices.size();
                    }
                    else if(prices[i] > prices[j])
                    {
                        buy = prices[j];
                        // advances time along x-axis to prevent infinite loops                        timeInstance++;
                        i = prices.size();
                        j = prices.size();
                    }
                }
            }
        }
        // repeat the loop to find a sell price
        for(int i = timeInstance; i <= prices.size(); i++)
        {
            for(int j = timeInstance; j <= prices.size(); j++)
            {
                if (sell == 0)
                {
                    if(prices[i] > buy)
                    {
                        sell = prices[i];
                        // advances time along x-axis to prevent infinite loops
                        timeInstance = i;
                        i = prices.size();
                        j = prices.size();
                    }
                }
            }
        }
        if(sell - buy > 0)
            maxProfit += sell - buy;
    }
    return maxProfit;
}
int main()
    {
    // EXAMPLE USE CASE
    vector<int> arr{1, 2, 4};
    cout << getMaxProfit(arr) << endl; // 3
    vector<int> arr1{4,2,1};
    cout << getMaxProfit(arr1) << endl;
    vector<int> arr2{1};
    cout << getMaxProfit(arr2) << endl;
    vector<int> arr3{1,2,5,1,6};
    cout << getMaxProfit(arr3) << endl;
    vector<int> arr4{3,1,5,2,4};
    cout << getMaxProfit(arr4) << endl;
    return 0;
}
