#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<stack>

//买卖股票的最佳时机，可多次买入，但每次买入时必须卖掉之前的，不考虑手续费

int maxPrices(vector<int> &prices) {
	int n = prices.size();
	if (n == 0) return 0;
	int sum = 0;
	for (int i = 1; i < n; i++)
	{
		int gap = prices[i] - prices[i - 1];
		if (gap > 0)
		{
			sum += gap;
		}
	}
	return sum;
}






//int main()
//{
//	int n;
//	int res;
//	cin >> n;
//	vector<int> prices(n);
//	for (int i = 0; i < n; i++) {
//		int num;
//		cin >> num;
//		prices[i]=num;
//	}
//	res = maxPrices(prices);
//	if (res != 0) {
//		return res;
//	}
//
//	return 0;
//}