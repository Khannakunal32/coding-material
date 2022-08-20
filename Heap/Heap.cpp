/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

class Heap
{
public:
    int *arr;

    int size = 0;

    Heap(int n)
    {
        arr = new int[n];
        arr[0] = -1;
        size = 0;
    }

    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            if (val > arr[index / 2])
            {
                swap(arr[index], arr[index / 2]);
                index /= 2;
            }
            else
                return;
        }
    }

    void deleteFirst()
    {
        if (size == 0)
        {
            cout << "nothing to delete";
            return;
        }

        arr[1] = arr[size];
        size--;
        // arr.pop_back();
        // delete the last element from the array

        int index = 1;

        while (index < size)
        {

            int leftIndex = 2 * index;
            int rightIndex = 2 * index + 1;

            if (leftIndex < size && arr[index] < arr[leftIndex])
            {
                swap(arr[index], arr[leftIndex]);
                index = 2 * index;
            }
            else if (rightIndex < size && arr[index] < arr[rightIndex])
            {
                swap(arr[index], arr[rightIndex]);
                index = 2 * index + 1;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    int n = 4;
    Heap myheap(n + 1);
    myheap.insert(50);
    myheap.insert(55);
    myheap.insert(53);
    myheap.insert(52);
    myheap.insert(54);
    // myheap.print();

    myheap.deleteFirst();
    myheap.print();

    return 0;
}
