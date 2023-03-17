#include<iostream>
using namespace std;
#include<string>
#include<vector>

int func(unsigned int val)
{
	val = (val & 0x55555555) + ((val & 0xaaaaaaaa) >> 1);
	val = (val & 0x33333333) + ((val & 0xcccccccc) >> 2);
	val = (val & 0x0f0f0f0f) + ((val & 0xf0f0f0f0) >> 4);
	val = (val & 0x00ff00ff) + ((val & 0xff00ff00) >> 8);
	val = (val & 0x0000ffff) + ((val & 0xffff0000) >> 16);

	return val;
}

int func1(unsigned int i)
{
	unsigned int temp = i;
	temp = (temp & 0x55555555) + ((temp & 0xaaaaaaaa) >> 1);
	temp = (temp & 0x33333333) + ((temp & 0xccccccccc) >> 2);
	temp = (temp & 0x0f0f0f0f) + ((temp & 0xf0f0f0f0) >> 4);
	temp = (temp & 0xff00ff) + ((temp & 0xff00fff00) >> 8);
	temp = (temp & 0xffff) + ((temp & 0xffff0000) >> 16);
	return temp;
}

string RePlace(string a) {
	int n = a.size();
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == '{')
		{
			count++;
		}
	}

	while (count--)
	{
		int index1 = a.find("{");
		int index2 = a.find("}");
		a.replace(index1,index2,"*");
	}

	return a;
}

bool IsMatch(string s, string p)
{
	int m = s.size();
	int n = p.size();
	vector<vector<int>> dp(m + 1, vector<int>(n + 1));
	dp[0][0] = true;
	for (int i = 1; i <= n; ++i)
	{
		if (p[i - 1] == '*')
		{
			dp[0][i] = true;
		}
		else {
			break;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (p[j - 1] == '*')
			{
				dp[i][j] = dp[i][j - 1] | dp[i - 1][j];
			}
			else if (p[j - 1] == '*' || s[i - 1] == p[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1];
			}
		}
	}
	return dp[m][n];
}

vector<bool> Query(vector<string> &str, string &rule) {
	vector<bool> res;
	rule=RePlace(rule);
	for (int i = 0; i < str.size(); i++)
	{
		bool a = IsMatch(str[i], rule);
		res.push_back(a);
	}
	return res;

}



//int main() {
//	int N;
//	cin >> N;
//	string Rule;
//	cin.ignore();
//
//	vector<string> strs;
//
//	for (int i = 0; i <N+1; i++)
//	{
//		if (i == 0) {
//			getline(cin, Rule);
//		}
//		else {
//			string st;
//			getline(cin, st);
//			strs.push_back(st);
//		}
//	}
//	for (int i = 0; i < N; i++)
//	{
//		cout << strs[i] << endl;
//	}
//	
//	vector<bool> result = Query(strs, Rule);
//
//	for (int i=0;i<N;i++)
//	{
//		cout << strs[i] << endl;
//		cout << result[i] << endl;
//	}
//
//	string b = RePlace(Rule);
//	cout << b << endl;
//
//	return 0;
//
//}






//int main() {
//		/*数组指针在一维数组里不常用，更常用于多维数组*/
//
//	unsigned int ab = func(0x11530829);
//	cout << ab << endl;
//
//	int arr2[3][3] = { {1, 2, 3},
//					  {4, 5, 6},
//					  {7, 8, 9} };
//
//	int* p3 = &arr2[1][0];//多维数组的数组名是一个指向多维数组首元素地址的指针，多维数组的首元素还是一个数组，所以多维数组的数组名是一个数组指针，无法用它去初始化一个普通指针
//	//arr2[2][0]是二维数组第二行的首元素，p3指向这个首元素,所以p3+1，就是在第二行的维度上进行移动
//	std::cout << *(p3 + 1) << std::endl;//输出第二行第二个元素5
//
//	int(*p4)[3] = arr2;//p4是一个数组指针，指向包含3个int的一维数组，当前指向arr2的第一个一维数组({1,2,3})
//	//p4+1会走一整个一维数组的大小，即p4+1指向了arr2的第二个一维数组({4,5,6})，对p4+1解引用会得到第二个一维数组首元素的地址，即*(p4+1)=&arr2[1][0]
//	//那么，在*(p4+1)的基础上再+2，得到的就是第二个一维数组中最后一个元素的地址，即6的存储地址。*(p4+1)+2=&arr2[1][2]
//	//在这个基础上进行解引用得到的就是元素6，即*(*(p4+1)+2)=arr2[1][2]=6
//	std::cout << *(p4 + 1) << std::endl;//0000001F65BAFC84
//	std::cout << &arr2[1][0] << std::endl;//0000001F65BAFC84
//	std::cout << *(p4 + 1) + 2 << std::endl;//0000002A1CBAF9BC
//	std::cout << &arr2[1][2] << std::endl;//0000002A1CBAF9BC
//	std::cout << *(*(p4 + 1) + 2) << std::endl;//6
//	std::cout << arr2[1][2] << std::endl;//6
//	std::cout << *(arr2[1] + 2) << std::endl;//6
//	std::cout << *arr2[1] << std::endl;//4
//	std::cout << 2[1[arr2]] << std::endl;//相当于arr2[1][2]
//
//	return 0;
//}

//int main()
//{
//	int arr[] = { 1,2,4,5,6 };
//	int* p1 = arr;//普通指针，p1仅仅指向了arr的首元素，p1+1只走一个int字节（4字节），指向了arr下一个元素
//
//	int(*p2)[5] = &arr;//数组指针，p2却指向了整个数组的地址，p2+1却会走整个arr大小的字节（4*5=20字节），
//	std::cout << p1 << std::endl;
//	std::cout << p1[2] << std::endl;//指向数组的指针可以使用索引
//	std::cout << (*p2) << std::endl;//p2指向了整个数组的地址，对p2解引用得到的是数组首元素的地址，再解引用一次就是数组首元素
//	std::cout << p1 << std::endl;
//	std::cout << p2 << std::endl;
//
//	int p0 = *((int*)(*p2)+1);
//	std::cout << p0 << std::endl;
//
//
//	/*数组指针在一维数组里不常用，更常用于多维数组*/
//	int arr2[3][3] = { {1, 2, 3},
//					  {4, 5, 6},
//					  {7, 8, 9} };
//
//	int* p3 = &arr2[1][0];//多维数组的数组名是一个指向多维数组首元素地址的指针，多维数组的首元素还是一个数组，所以多维数组的数组名是一个数组指针，无法用它去初始化一个普通指针
//	//arr2[2][0]是二维数组第二行的首元素，p3指向这个首元素,所以p3+1，就是在第二行的维度上进行移动
//	std::cout << *(p3 + 1) << std::endl;//输出第二行第二个元素5
//
//	int(*p4)[3] = arr2;//p4是一个数组指针，指向包含3个int的一维数组，当前指向arr2的第一个一维数组({1,2,3})
//	//p4+1会走一整个一维数组的大小，即p4+1指向了arr2的第二个一维数组({4,5,6})，对p4+1解引用会得到第二个一维数组首元素的地址，即*(p4+1)=&arr2[1][0]
//	//那么，在*(p4+1)的基础上再+2，得到的就是第二个一维数组中最后一个元素的地址，即6的存储地址。*(p4+1)+2=&arr2[1][2]
//	//在这个基础上进行解引用得到的就是元素6，即*(*(p4+1)+2)=arr2[1][2]=6
//	std::cout << *(p4 + 1) << std::endl;//0000001F65BAFC84
//	std::cout << &arr2[1][0] << std::endl;//0000001F65BAFC84
//	std::cout << *(p4 + 1) + 2 << std::endl;//0000002A1CBAF9BC
//	std::cout << &arr2[1][2] << std::endl;//0000002A1CBAF9BC
//	std::cout << *(*(p4 + 1) + 2) << std::endl;//6
//	std::cout << arr2[1][2] << std::endl;//6
//
//	/*
//	由此得到一个结论，*(*(p4+i)+j)=arr2[i][j]，p4+i指向arr2第i个一维数组的地址，*(p4+i)指向第i个一维数组首元素的地址
//	*/
//
//
//
//
//	return 0;
//}

