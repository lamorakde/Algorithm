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

// 针对模板向量类 vector 的算法函数
template <typename T>
void bubbleSort(vector<T> &inputVector)
{	// 针对模板向量类 vector 使用冒泡法排序
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

// 其他的算法函数

// void convert(Stack<char> & S, _int64 n, int base)	// 十进制数 n 到 base 进制的转换（递归版本）
// {
// 	//0 < n, 1 < base <= 16，新进制下的数位符号，可规定base取值范围适当扩充
// 	static char digit[]{ '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
// 	if (n > 0)	//在尚有余数之前，不断递归
// 	{
// 		convert(S, n / base, base);//通过递归得到所有更高位
// 		S.push(digit[n/base]);//输出低位
// 	}
// 	//新进制下由高到低的各数位，自顶而下保存于栈 S 中
// }

void convert(Stack<char> & S, _int64 n, int base)	// 十进制数 n 到 base 进制的转换（迭代版本）
{
	//0 < n, 1 < base <= 16，新进制下的数位符号，可规定base取值范围适当扩充
	static char digit[]{ '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	while (n > 0)	//由低到高，逐一计算出新进制下癿各数位
	{
		int remainder = (int)(n % base);
		S.push(digit[remainder]);//余数（当前位）入栈
		n /= base; //n更新为其对base的除商
	}
	//新进制下由高到低的各数位，自顶而下保存于栈 S 中
}

bool paren(const char exp[], int lo, int hi)
{
	//表达式括号匹配检查，可兼容三种括号
	Stack<char> S;//使用栈基类已发现但尚未匹配癿左括号
	for (int i = 0; exp[i]; i++)/* 逐一检查当前字符 */
	{	 //左括号直接进栈；右括号若与栈顶失配，则表达式必然不匹配
		switch (exp[i])
		{
		case '(':S.push(exp[i]); break;;
		case '[': S.push(exp[i]); break;
		case '{': S.push(exp[i]); break;
		case ')': if ((S.empty()) || ('(' != S.pop())) return false; break;
		case ']': if ((S.empty()) || ('[' != S.pop())) return false; break;
		case '}': if ((S.empty()) || ('{' != S.pop())) return false; break;
		default: break; //非括号字符一律忽略
		}
	}
	//整个表达式扫描过后，栈中若仍残留（左）括号，则不匹配；否则（栈空）匹配
	return S.empty();
}