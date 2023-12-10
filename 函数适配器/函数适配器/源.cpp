#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;

template<typename Fn>
class MyNote
{
public:
	MyNote(Fn & f) :fn(f) {}/*f����ָ���ǣ�bind2nd(greater��100)*/

	bool operator()(const typename Fn::argument_type& val)//һԪ��������argument_type
	{
		/*������return�����operator�����������ʱ�򣬴�ʱ��fn��bind2nd(greater��100)��val����������ĵ���ֵ*/
		return !fn(val);
	}
private:
	Fn fn;/*��һ����bind2nd(greater��������)�����ı���*/
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
		cout << "��һ�� �� ����100��Ԫ��:" << *it << endl;
	}

	return 0;
}

/*https://blog.csdn.net/TUJI67/article/details/89737292
����ϸ����ȡ������ʵ��   mynote����not1��ȡ����*/