#include <iostream>
#include <cstdlib>
using namespace std;
class DynamicArray
{
    int *data;
    int nextIndex;
    int capacity; // total size
public:
    DynamicArray()
    {
        data = new int[5]; // Starting with capacity = 5
        nextIndex = 0;
        capacity = 5;
    }
    DynamicArray(DynamicArray const &d)
    {
        //this -> data = d.data; // Shallow copy
        // Deep copy
        this->data = new int[d.capacity];
        for (int i = 0; i < d.nextIndex; i++)
        {
            this->data[i] = d.data[i];
        }
        this->nextIndex = d.nextIndex;
        this->capacity = d.capacity;
    }
    // operator overloading: We are simply equating two arrays
    void operator=(DynamicArray const &d)
    {
        this->data = new int[d.capacity];
        for (int i = 0; i < d.nextIndex; i++)
        {
            this->data[i] = d.data[i];
        }
        this->nextIndex = d.nextIndex;
        this->capacity = d.capacity;
    }
    // inserting a new element to the array
    void add(int element)
    {
        if (nextIndex == capacity)
        {                                         // If the capacity is not enough
            int *newData = new int[2 * capacity]; // We doubled the
            // capacity of the array
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i]; // Elements copied to the array
            }
            delete[] data;
            data = newData;
            capacity *= 2;
        }
        data[nextIndex] = element;
        nextIndex++;
    }
    int get(int i) const
    { // For returning the element at particular index
        if (i < nextIndex)
        {
            return data[i];
        }
        else
        {
            return -1;
        }
    }
    void add(int i, int element)
    {
        if (i < nextIndex)
        {
            data[i] = element;
        }
        else if (i == nextIndex)
        {
            add(element);
        }
        else
        {
            return;
        }
    }
    void print() const
    { // For printing the complete array
        for (int i = 0; i < nextIndex; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    DynamicArray d1;
    d1.add(10);
    d1.add(20);
    d1.add(30);
    d1.add(40);
    d1.add(50);
    d1.add(60);
    d1.add(70);

    DynamicArray d2(d1);
    d1.add(2, 100);

    d1.print();
    d2.print();
    cout<<d2.get(3)<<endl;
}