#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
using namespace std;

//对应内置对象 函数里面传入常数 
bool Greaterthan6(int &num)
{
	return num > 6;
}
/*方法二，利用函数对象 封装类 称为仿函数，重载operator（） 找出荣天气里面大于给定的数的个数*/
class GreaterT
{
public:
	GreaterT(int &i) :m_i(i)
	{
	};
	bool operator()(const int& num)
	{
		return num > this->m_i;
	}

private:
	int m_i;
};
/*利用函数对象的函数适配器与传入参数n绑定 完成传入变量的n的参数比较*/
int GreaterthanN(vector<int>::iterator begin_iter,vector<int>::iterator end_iter,int& N)
{
	return count_if(begin_iter, end_iter, bind2nd(greater<int>(), N));
}


int main(void)
{
	vector<int> vec_int;
	for (int i = 0; i < 10; i++)
	{
		vec_int.push_back(i + 1);
	}
	/*运用第一种方法*/
	int count1 = count_if(vec_int.begin(), vec_int.end(), Greaterthan6);/*寻找大于6的函数*/
	cout << "大于6的数目为：" << count1 << endl;
	/*运用第二种方法*/
	int num = 3;
	int count2 = count_if(vec_int.begin(), vec_int.end(), GreaterT(num));
	cout << "大于3的数目为：" << count2 << endl;
	/*利用函数适配器 参数n表示比较的数*/
	int n = 1;
	int count3 = GreaterthanN(vec_int.begin(), vec_int.end(), n);
	cout << "大于1的数目为：" << count3 << endl;
	return 0;
}