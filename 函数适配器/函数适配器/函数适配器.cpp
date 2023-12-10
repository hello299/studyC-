#include<iostream>
#include<algorithm>
#include <functional>
#include<vector>
using namespace std;
/*通过谓词求大于N的个数*/
class Greator
{
public:
	Greator(int i) :m_i(i)
	{ 

	};
	bool operator()(int & num)
	{
		if (num>this->m_i)
		{
			cout << num << " ";
		}
		return num > this->m_i;
	}
private:
	int m_i;
};
/*通过预定义的函数对象求大于N的个数*/
int Great(vector<int>::iterator begin,vector<int>::iterator end, int& num2)
{
	return count_if(begin,end, bind2nd(greater<int>(), num2));
}
void MainFunc()
{
	vector<int> vec_int;
	for (int i = 0; i < 10; i++)
	{
		vec_int.push_back(i+1);
	}
	/*求等于6的个数*/
	int num_count_1 = count(vec_int.begin(), vec_int.end(), 6);
	cout << "num_count_1的个数为:" << num_count_1 << endl;/*两个*/
	/*通过谓词求大于2的个数*/
	/*通过仿函数求函数大于4的个数*/
	int num_2 = count_if(vec_int.begin(), vec_int.end(), Greator(4)/*此时自动调用谓词的operator()重载函数*/);
	cout << "等于4的数为：" << num_2 << endl;
	
	/*在自定义函数中调用greater<int>()预定义函数 实现求大于2的个数*/
	int num = 3;
	int count3 = Great(vec_int.begin(), vec_int.end(), num);

	/*求奇数的个数*/
	int count4 = count_if(vec_int.begin(), vec_int.end(), bind2nd(modulus<int>(), 2));
	cout << "奇数的个数为:" << count4 << endl;

	/*求偶数的个数等于对求奇数的个数取反*/
	int count5 = count_if(vec_int.begin(), vec_int.end(), not1(bind2nd(modulus<int>(), 2)));
	cout<< "偶数的个数为:" << count5 << endl;
}

int main(void)
{
	MainFunc();
	return 0;
}