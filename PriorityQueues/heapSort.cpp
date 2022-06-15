#include <iostream>
using namespace std;

void makeHeap(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int childIndex = i;

        // up-heapify
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (arr[childIndex] < arr[parentIndex])
            {
                int temp = arr[childIndex];
                arr[childIndex] = arr[parentIndex];
                arr[parentIndex] = temp;
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }
}
void removeMin(int arr[], int n)
{
    int temp = arr[0];
    arr[0] = arr[n - 1];
    arr[n - 1] = temp;
    n--;

    int parentIndex = 0;
    int leftChild = 2 * parentIndex + 1;
    int rightChild = 2 * parentIndex + 2;

    // down-heapify
    while (leftChild < n)
    {
        int minIndex = parentIndex;
        if (arr[minIndex] > arr[leftChild])
        {
            minIndex = leftChild;
        }
        if (rightChild < n && arr[minIndex] > arr[rightChild])
        {
            minIndex = rightChild;
        }
        if (minIndex == parentIndex)
        {
            break;
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[parentIndex];
        arr[parentIndex] = temp;

        parentIndex = minIndex;
        leftChild = 2 * parentIndex + 1;
        rightChild = 2 * parentIndex + 2;
    }
}
void heapSort(int arr[], int n)
{
    makeHeap(arr, n);
    for (int i = 0; i < n; i++)
    {
        removeMin(arr, n - i);
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    heapSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}