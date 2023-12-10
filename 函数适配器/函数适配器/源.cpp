#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;

template<typename Fn>
class MyNote
{
public:
	MyNote(Fn & f) :fn(f) {}/*f具体指的是：bind2nd(greater，100)*/

	bool operator()(const typename Fn::argument_type& val)//一元函数对象argument_type
	{
		/*进行完return后调用operator重载运算符的时候，此时的fn是bind2nd(greater，100)，val代表迭代器的迭代值*/
		return !fn(val);
	}
private:
	Fn fn;/*第一次是bind2nd(greater，？？？)函数的变量*/
};

template<typename Fn>
MyNote<Fn> mynote(Fn f)
{
	return MyNote<Fn>(f);/*greater<int>(*iter(val),2)*/
}

int main()
{
	int arr[] = { 12,34,42,52,64,62,90,102,46,256,78 };
	int len = sizeof(arr) / sizeof(arr[0]);
	vector<int> vec(arr, arr + len);

	vector<int>::iterator it = find_if(vec.begin(), vec.end(), mynote(bind2nd(greater<int>(), 100)));

	if (it != vec.end())
	{
		cout << "第一个 不 大于100的元素:" << *it << endl;
	}

	return 0;
}

/*https://blog.csdn.net/TUJI67/article/details/89737292
的详细解释取反器的实现   mynote就是not1的取反器*/