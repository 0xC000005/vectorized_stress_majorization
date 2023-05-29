
#include "HeapSort.h"
using namespace std;

void HeapAdjust(std::vector<float> &a, std::vector<int> &ids, int i, int size)  //������ 
{
	int lchild = 2 * i;       //i�����ӽڵ���� 
	int rchild = 2 * i + 1;     //i���Һ��ӽڵ���� 
	int max = i;            //��ʱ���� 
	//std::cout << "heap adjust " << a.size() << "," << max << "," << lchild << "," << rchild << std::endl;
	if (i <= size / 2)          //���i��Ҷ�ڵ�Ͳ��ý��е��� 
	{
		if (lchild <= size&&a[lchild - 1]>a[max - 1])
		{
			max = lchild;
		}
		if (rchild <= size&&a[rchild - 1]>a[max - 1])
		{
			max = rchild;
		}
		if (max != i)
		{
			swap(a[i - 1], a[max - 1]);
			swap(ids[i - 1], ids[max - 1]);
			HeapAdjust(a, ids, max, size);    //�������֮����maxΪ���ڵ���������Ƕ� 
		}
	}
}

void BuildHeap(std::vector<float> &a, std::vector<int> &ids, int size)    //������ 
{
	int i;
	for (i = size / 2; i >= 1; i--)    //��Ҷ�ڵ�������ֵΪsize/2 
	{
		HeapAdjust(a, ids, i, size);
	}
}


void HeapSort(std::vector<float> &a, int size, std::vector<int> &child_list)    //������ 
{
	int i;
	BuildHeap(a, child_list, size);
	for (i = size; i >= 1; i--)
	{
		swap(a[0], a[i - 1]);           //�����Ѷ������һ��Ԫ�أ���ÿ�ν�ʣ��Ԫ���е�����߷ŵ������ 
		swap(child_list[0], child_list[i - 1]);
		//BuildHeap(a,i-1);        //������Ԫ�����½���Ϊ�󶥶� 
		HeapAdjust(a, child_list, 1, i - 1);      //���µ����Ѷ��ڵ��Ϊ�󶥶� 
	}
}
