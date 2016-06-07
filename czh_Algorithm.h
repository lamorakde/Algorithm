#ifndef CZH_ALGORITHM_H_
#define CZH_ALGORITHM_H_
#include <vector>
using namespace std;

template <typename T> void showVector(vector<T> &inputVector);

// 针对模板向量类 vector 的算法函数
template <typename T> void bubbleSort(vector<T> &inputVector);


// 其他的算法函数
void convert(Stack<char> & S, _int64 n, int base);	// 十进制数 n 到 base 进制的转换（迭代版本）

#endif
