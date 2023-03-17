#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

vector<vector<int>> ZhuanZhi(vector<vector<int>> &a) {
	vector< vector<int>> res(a.size(), vector<int>(a.size(), 0));
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < a.size(); j++)
		{
			res[j][i] = a[i][j];
		}
	}
	return res;
}

int Mins(vector<vector<int>> &a, vector<vector<int>> &b) {
	int res = 0;
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < a.size(); j++)
		{
			res+=abs(a[i][j]-b[i][j]);
		}
	}
	return res;
}



//int main() {
//	/*
//	6 5
//	5 6 7 8 9 10
//	*/
//	int n;
//	cin >> n;
//	int count = n;
//	vector<vector<int>> Matrix;
//	vector<vector<int>> res;
//	while (count)
//	{
//		vector<int> temp;
//		for (int i = 0; i < n; i++)
//		{
//			int num;
//			cin >> num;
//			temp.push_back(num);
//		}
//		Matrix.push_back(temp);
//		count--;
//	}
//	res = ZhuanZhi(Matrix);
//	
//	/*for (int p = 0; p < n; p++) {
//		for (int k = 0; k < n; k++)
//		{
//			cout << res[p][k] << " ";
//		}
//	}*/
//	//cout << endl;
//	int resN = Mins(Matrix, res);
//	cout << resN;
//
//	return 0;
//}