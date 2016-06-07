#ifndef CZH_ALGORITHM_H_
#define CZH_ALGORITHM_H_
#include <vector>
using namespace std;

template <typename T> void showVector(vector<T> &inputVector);

// ���ģ�������� vector ���㷨����
template <typename T> void bubbleSort(vector<T> &inputVector);


// �������㷨����
void convert(Stack<char> & S, _int64 n, int base);	// ʮ������ n �� base ���Ƶ�ת���������汾��

#endif
