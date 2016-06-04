#include <iostream>
#include <vector>
#include "Algorithm_Stack.h"

using namespace std;

template <typename T>
void showVector(vector<T> &inputVector)
{
	cout << "Vector information begins:\n";
	for (int i = 0; i < inputVector.size(); i++)
	{
		cout << "#" << i + 1 << "\t: " << inputVector[i] << endl;
	}
	cout << "-----------------------------\n\n";
}

// ���ģ�������� vector ���㷨����
template <typename T>
void bubbleSort(vector<T> &inputVector)
{	// ���ģ�������� vector ʹ��ð�ݷ�����
	int size = inputVector.size();
	for (int i = 0; i < size; i++)
	{
		for (int j = 1; j < size - i; j++)
		{
			if (inputVector[j] < inputVector[j - 1])
				swap(inputVector[j], inputVector[j - 1]);
		}
	}
}

// �������㷨����

// void convert(Stack<char> & S, _int64 n, int base)	// ʮ������ n �� base ���Ƶ�ת�����ݹ�汾��
// {
// 	//0 < n, 1 < base <= 16���½����µ���λ���ţ��ɹ涨baseȡֵ��Χ�ʵ�����
// 	static char digit[]{ '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
// 	if (n > 0)	//����������֮ǰ�����ϵݹ�
// 	{
// 		convert(S, n / base, base);//ͨ���ݹ�õ����и���λ
// 		S.push(digit[n/base]);//�����λ
// 	}
// 	//�½������ɸߵ��͵ĸ���λ���Զ����±�����ջ S ��
// }

void convert(Stack<char> & S, _int64 n, int base)	// ʮ������ n �� base ���Ƶ�ת���������汾��
{
	//0 < n, 1 < base <= 16���½����µ���λ���ţ��ɹ涨baseȡֵ��Χ�ʵ�����
	static char digit[]{ '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	while (n > 0)	//�ɵ͵��ߣ���һ������½����°m����λ
	{
		int remainder = (int)(n % base);
		S.push(digit[remainder]);//��������ǰλ����ջ
		n /= base; //n����Ϊ���base�ĳ���
	}
	//�½������ɸߵ��͵ĸ���λ���Զ����±�����ջ S ��
}

bool paren(const char exp[], int lo, int hi)
{
	//���ʽ����ƥ���飬�ɼ�����������
	Stack<char> S;//ʹ��ջ�����ѷ��ֵ���δƥ��m������
	for (int i = 0; exp[i]; i++)/* ��һ��鵱ǰ�ַ� */
	{	 //������ֱ�ӽ�ջ������������ջ��ʧ�䣬����ʽ��Ȼ��ƥ��
		switch (exp[i])
		{
		case '(':S.push(exp[i]); break;;
		case '[': S.push(exp[i]); break;
		case '{': S.push(exp[i]); break;
		case ')': if ((S.empty()) || ('(' != S.pop())) return false; break;
		case ']': if ((S.empty()) || ('[' != S.pop())) return false; break;
		case '}': if ((S.empty()) || ('{' != S.pop())) return false; break;
		default: break; //�������ַ�һ�ɺ���
		}
	}
	//�������ʽɨ�����ջ�����Բ����������ţ���ƥ�䣻����ջ�գ�ƥ��
	return S.empty();
}