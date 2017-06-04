#include <stdio.h>

//http://bubkoo.com/2014/01/14/sort-algorithm/heap-sort/
void swap(int & a, int & b)
{
        int temp = a;
        a = b;
        b = temp;
}

const int N = 20;

int PARENT(int i)
{
        return (i-1)/2;
}

int LEFT(int i)
{
        return 2* i + 1;
}

int RIGHT(int i)
{
        return 2 * i + 2;
}

void maxheap_down(int a[], int index, int heapSize);
//构建一个最大堆
void buildHeap(int a[], int n)
{
        for (int i = n/2 - 1; i >= 0; i--)
          maxheap_down(a, i, n-1);
}
void maxheap_down(int a[], int index, int heapSize)
{
        int left = LEFT(index);
        int right = RIGHT(index);

        while (true)
        {
                int iMax = index;
                if (left < heapSize && a[left] > a[index])
                {
                        iMax = left;
                }

                if (right < heapSize && a[right] > a[iMax])
                {
                        iMax = right;
                }

                if (iMax != index)
                {
                        swap(a[iMax], a[index]);
                        index = iMax;
                }
                else
                        break;
        }
}

void maxheap_down2(int a[], int index, int heapSize)
{
        int left = LEFT(index);
        int right = RIGHT(index);

        int iMax = index;
        if (left < heapSize &&a[left] > a[index])
        {
         iMax = left;
        }
        if (right < heapSize && a[right] > a[iMax])
        {
          iMax = right;
        }
        if (iMax != index)
        {
                swap(a[iMax], a[index]);
                index = iMax;
                maxheap_down(a,index, heapSize);
        }
}
