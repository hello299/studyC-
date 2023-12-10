#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;

/*取反器的具体实现*/
template<typename T>
class TemplateFunc
{
public:
	TemplateFunc(T& num):m_num(num)
	{
	};
	/*此时调用greator()函数*/
	bool operator()(T &val)
	{
		return !TemplateFunc(val);
	}
private:
	T m_num;
};
template<typename T>
TemplateFunc<T> templatefunc(T t)
{
	return templatefunc<T>(t);
}

int main(void)
{
	vector<int> vec_int;
	for (int i = 0; i < 10; i++)
	{
		vec_int.push_back(i + 1);
	}
	int num = 3;
	/*寻找小于等于3的个数*/
	int count3 = count_if(vec_int.begin(), vec_int.end(), not1(bind2nd(greater<int>(), 2)));
	return 0;
}