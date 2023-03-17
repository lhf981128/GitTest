

//int Func(int x) {
//	int a = x & (x - 1);
//	return x - a;
//}
//
//int SumN(int n) {
//	int res=0;
//	for (int i = 1; i <= n; i++)
//	{
//		res += i / Func(i);
//	}
//	return res;
//}


//int main() {
//	//int t;
//	int nm = Func(1200);
//	cout << nm;
//	/*cin >> t;
//	vector<int> In(t);
//	vector<int> Out(t);
//
//	for (int i = 0; i < t; i++)
//	{
//		int num;
//		cin >> num;
//		In[i] = num;
//	}
//	for (int i = 0; i < t; i++) {
//		Out[i] = SumN(In[i]);
//	}
//	
//	for (auto &nu : Out) {
//		cout << nu << endl;
//	}*/
//	
//	return 0;
//
//}


//void Adoor(vector<int>& per) {
//	int size = per.size();
//	if (size == 1)
//		return;
//	rotate(per.begin(), per.begin() + 1, per.end());
//
//}
//void Bdoor(vector<int>& per) {
//	int size = per.size();
//	if (size == 1)
//		return;
//	reverse(per.begin(), per.end());
//}
//
//int main() {
//	int personNum;
//	cin >> personNum;
//	int doorNum;
//	cin >> doorNum;
//	vector<char> doorSerise(doorNum);
//	for (int i = 0; i < doorNum; i++)
//	{
//		cin >> doorSerise[i];
//	}
//	vector<int> qu(personNum);
//	for (int j = 0; j < personNum; j++)
//	{
//		qu[j] = j + 1;
//	}
//
//	for (int k = 0; k < doorNum; k++)
//	{
//		if (doorSerise[k] == 'A') {
//			Adoor(qu);
//		}
//		else {
//			Bdoor(qu);
//		}
//	}
//	for (auto & se : qu) {
//		cout << se << endl;
//	}
//
//	system("pause");
//	return 0;
//
//}

//bool IsHtml(string s) {
//	int len = s.length();
//
//}
//
//int main() {
//	string input;
//	getline(cin, input);
//
//	bool Flag=IsHtml(input);
//	if (Flag == true)
//		cout << "YES" << endl;
//	else
//		cout << "NO" << endl;
//
//	system("pause");
//	return 0;
//
//}


//int main() {
//	int n;
//	cin >> n;
//	int temp;
//	vector<int> A(n, 0);
//	for (int i = 0; i < n; i++) {
//		cin >> temp;
//		A[i] = temp;
//	}
//	int Q;
//	cin >> Q;
//	vector<int> X(Q, 0);
//	for (int i = 0; i < Q; i++) {
//		cin >> temp;
//		X[i] = temp;
//	}
//	int add = 0;
//	long long sum = 0;
//	for (int i = 0; i < Q; i++) {
//		for (int j = 0; j < n; j++) {
//			A[j] = A[j] + X[i];
//			sum += abs(A[j]);
//		}
//		cout << sum << endl;
//	}
//	return 0;
//}



////合并两个数组，第一个升序排列，第二个降序排列,可去重
//void mergeArray(vector<int> &a,vector<int> &b,int m,int n) {
//	int i = m - 1;
//	int j = 0;
//	int index = m + n - 1;
//	for (int q = 0; q < n; q++) {
//		a.push_back(0);
//	}
//	for (int k = 0; k < m + n; k++)
//	{
//		if (i < 0)
//		{
//			a[index--] = b[j++];
//		}
//		else if (j >n-1)
//		{
//			a[index--] = a[i--];
//		}
//		else if (a[i] > b[j] && i >= 0)
//		{
//			a[index--] = a[i--];
//		}
//		else if (a[i] < b[j] && j <n)
//		{
//			a[index--] = b[j++];
//		}
//	}
//
//
//}


//int main() {
//	int r;
//	int c;
//	cin >> r;
//	cin >> c;
//	vector<int> a(r,0);
//	vector<int> b(c,0);
//	for (int i = 0; i < r; i++) {
//		cin >> a[i];
//	}
//	for (int j = 0; j < c; j++) {
//		cin >> b[j];
//	}
//	mergeArray(a, b, r, c);
//	for (auto &nu : a) {
//		cout << nu << " ";
//	}
//}



//template<typename>
//class A {
//
//};
//
//int main() {
//	A<int> a;
//	vector<vector<double>> points;
//	double res=0.0;
//	int x, y;
//	char ch;
//	while (cin >> x >> y) {
//		char ch;
//
//		vector<double> temp;
//		temp.push_back(x);
//		temp.push_back(y);
//		points.push_back(temp);
//		cin.get(ch);
//		if (ch == '\n') {
//			break;
//		}
//	}
//	
//	int n = points.size();
//	for (int p = 0; p < n; p++)
//	{
//		cout << points[p][0] << " " << points[p][1] << endl;
//	}
//	sort(points.begin(), points.end(), [](vector<double> &a, vector<double> &b) {
//		if (a[0] == b[0])
//			return a[1] < b[1];
//		return a[0] < b[0];
//	});
//	if (n < 3)
//		cout << 0.00000 << endl;
//	for (int i = 0; i < n; i++)
//
//	{
//
//		res = res + (points[i][0] * points[(i + 1) % n] [1] - points[(i + 1) % n][0] * points[i][1]) / 2.0;
//
//	}
//
//	cout << abs(res) << endl;
//}


//bool IsArithmeticProgression(vector<int> arr) {
//	int n = arr.size();
//	if (n == 1 || n == 2)
//		return true;
//	sort(arr.begin(), arr.end());
//	for (int i = 0; i < arr.size() - 2; i++)
//	{
//		if (arr[i + 1] * 2 != arr[i] + arr[i + 2])
//		{
//			return false;
//		}
//	}
//	return true;
//
//}
//
//int MaxLength(vector<int> &sa) {
//	int res = 0;
//	int n = sa.size();
//	for (int i = 0; i < n-1; i++)
//	{
//		for (int j = i+1; j < n; j++)
//		{
//			vector<int> temp(sa.begin() + i, sa.begin() + j);
//			if (IsArithmeticProgression(temp)) {
//				res =max(res, j - i);
//			}
//		}
//	}
//	return res;
//
//}
//
//int main() {
//	int N;
//	cin >> N;
//	vector<int> Save(N);
//	for (int i = 0; i < N; i++)
//	{
//		cin >> Save[i];
//	}
//	cout << MaxLength(Save);
//	system("pause");
//	return 0;
//}
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<numeric>
#include<functional>
#include<math.h>
using namespace std;

map<int, int>::iterator findMax(map<int, int> &sa, int tk)
{
	for (map<int, int>::iterator i = sa.begin(); i!= sa.end(); i++) {
		if (i->second >= tk) {
			return i;
		}
	}
	return sa.end();
}

int MaxGuan(vector<int> &a, vector<int> &b, int t) {
	int m = a.size();
	int n = b.size();
	vector<int> res;
	map<int, int> aSum;
	map<int, int> bSum;
	for (int i = 0; i < m; i++) {
		int numA = accumulate(a.begin(), a.begin() + i+1, 0);
		aSum[i] = numA;
	}
	for (int j = 0; j < n; j++) {
		int numB = accumulate(b.begin(), b.begin() + j+1, 0);
		bSum[j] = numB;
	}
	int indexA = 0, indexB = 0;
	map<int, int>::iterator save;
	for (map<int, int>::iterator it = aSum.begin(); it != aSum.end(); it++) {
		if (it->second >= t) {
			indexA = it->first + 1;
			save = it;
			break;
		}
	}
	for (map<int, int>::iterator it = bSum.begin(); it != bSum.end(); it++) {
		if (it->second >= t) {
			indexB = it->first + 1;
			break;
		}
	}
	res.push_back(indexA);
	res.push_back(indexB);

	for (map<int, int>::iterator it = aSum.begin(); it != save; it++) {
		map<int, int>::iterator iter = findMax(bSum, t-it->second);
		if (iter!=bSum.end()) {
			int temp = it->first + 1 + iter->first + 1;
			res.push_back(temp);
		}
		else {
			int temp = it->first + n + 1;
			res.push_back(temp);
		}
	}
	int result = *max_element(res.begin(), res.end());
	return result;
}


//int main() {
//	int n, m, t;
//	cin >> n >> m >> t;
//	vector<int> N(n, 0);
//	for (int i = 0; i < n; i++)
//		cin >> N[i];
//	vector<int> M(m, 0);
//	for (int i = 0; i < m; i++)
//		cin >> M[i];
//
//	cout << MaxGuan(N, M, t) << endl;
//}