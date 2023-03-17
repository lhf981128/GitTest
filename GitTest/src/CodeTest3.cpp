#include<iostream>
using namespace std;
#include<vector>

///笔试题：1表示对矩阵顺时针旋转180度   2表示行镜像

vector<vector<int>> DoMatrix(vector<vector<int>> &mat, vector<int> &te) {
	int len = mat.size();
	for (int i = 0; i < te.size(); i++)
	{
		if (te[i] == 1)
		{
			for (int j = 0; j < len; j++)
				for (int k = j + 1; k < len; k++)
					swap(mat[j][k], mat[k][j]);//转置
			for (int j = 0; j < len; j++) {
				for (int k = 0; k < len / 2; k++) {
					swap(mat[j][k], mat[j][len - k - 1]);
				}
			}
			for (int j = 0; j < len; j++)
				for (int k = j + 1; k < len; k++)
					swap(mat[j][k], mat[k][j]);//转置
			for (int j = 0; j < len; j++) {
				for (int k = 0; k < len / 2; k++) {
					swap(mat[j][k], mat[j][len - k - 1]);
				}
			}
		}
		if (te[i] == 2)
		{
			for (int j = 0; j <  len/ 2; j++) {
				for (int k = 0; k < len; k++) {
					swap(mat[j][k], mat[len - j - 1][k]);
				}
			}
		}
	}
	return mat;

}



//int main()
//{
//	int n;
//	cin >> n;
//	int count = n;
//	int q;
//	vector<int> A;//存储操作的数
//	vector<vector<int>> matrix;
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
//		matrix.push_back(temp);
//		count--;
//	}
//
//	for (int i = 0; i < q; i++)
//	{
//		int num;
//		cin >> num;
//		A.push_back(num);
//	}
//
//	res = DoMatrix(matrix, A);
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			cout << res[i][j] << endl;
//		}
//	}
//
//	return 0;
//
//}