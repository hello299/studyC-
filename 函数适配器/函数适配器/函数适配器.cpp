#include<iostream>
#include<algorithm>
#include <functional>
#include<vector>
using namespace std;
/*ͨ��ν�������N�ĸ���*/
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
/*ͨ��Ԥ����ĺ������������N�ĸ���*/
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
	/*�����6�ĸ���*/
	int num_count_1 = count(vec_int.begin(), vec_int.end(), 6);
	cout << "num_count_1�ĸ���Ϊ:" << num_count_1 << endl;/*����*/
	/*ͨ��ν�������2�ĸ���*/
	/*ͨ���º�����������4�ĸ���*/
	int num_2 = count_if(vec_int.begin(), vec_int.end(), Greator(4)/*��ʱ�Զ�����ν�ʵ�operator()���غ���*/);
	cout << "����4����Ϊ��" << num_2 << endl;
	
	/*���Զ��庯���е���greater<int>()Ԥ���庯�� ʵ�������2�ĸ���*/
	int num = 3;
	int count3 = Great(vec_int.begin(), vec_int.end(), num);

	/*�������ĸ���*/
	int count4 = count_if(vec_int.begin(), vec_int.end(), bind2nd(modulus<int>(), 2));
	cout << "�����ĸ���Ϊ:" << count4 << endl;

	/*��ż���ĸ������ڶ��������ĸ���ȡ��*/
	int count5 = count_if(vec_int.begin(), vec_int.end(), not1(bind2nd(modulus<int>(), 2)));
	cout<< "ż���ĸ���Ϊ:" << count5 << endl;
}

int main(void)
{
	MainFunc();
	return 0;
}