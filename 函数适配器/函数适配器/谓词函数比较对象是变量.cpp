#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
using namespace std;

//��Ӧ���ö��� �������洫�볣�� 
bool Greaterthan6(int &num)
{
	return num > 6;
}
/*�����������ú������� ��װ�� ��Ϊ�º���������operator���� �ҳ�������������ڸ��������ĸ���*/
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
/*���ú�������ĺ����������봫�����n�� ��ɴ��������n�Ĳ����Ƚ�*/
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
	/*���õ�һ�ַ���*/
	int count1 = count_if(vec_int.begin(), vec_int.end(), Greaterthan6);/*Ѱ�Ҵ���6�ĺ���*/
	cout << "����6����ĿΪ��" << count1 << endl;
	/*���õڶ��ַ���*/
	int num = 3;
	int count2 = count_if(vec_int.begin(), vec_int.end(), GreaterT(num));
	cout << "����3����ĿΪ��" << count2 << endl;
	/*���ú��������� ����n��ʾ�Ƚϵ���*/
	int n = 1;
	int count3 = GreaterthanN(vec_int.begin(), vec_int.end(), n);
	cout << "����1����ĿΪ��" << count3 << endl;
	return 0;
}