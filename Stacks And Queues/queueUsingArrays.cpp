#include <iostream>
#include <cstdlib>
using namespace std;
template <typename T> // Generalised using templates
class Queue
{
    T *data;        // to store data
    int nextIndex;  // to store next index
    int firstIndex; // to store the first index
    int size;       // to store the size
    int capacity;   // to store the capacity it can hold
public:
    Queue()
    { // Constructor to initialize values
        data = new T[3];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
        capacity = 3;
    }
    int getSize()
    { // Returns number of elements present
        return size;
    }
    bool isEmpty()
    { // To check if queue is empty or not
        return size == 0;
    }
    void enqueue(T element)
    { // Function for insertion
        if (size == capacity)
        {
            T *newData = new T[capacity * 2];
            int j = 0;
            for (int i = firstIndex; i < capacity; i++)
            {
                newData[j++] = data[i];
            }
            for (int i = 0; i < firstIndex; i++)
            {
                newData[j++] = data[i];
            }
            delete[] data;
            data = newData;
            firstIndex = 0;
            nextIndex = capacity;
            capacity *= 2;
        }
        data[nextIndex] = element;              // Otherwise added a new element
        nextIndex = (nextIndex + 1) % capacity; // in cyclic way
        if (firstIndex == -1)
        { // Suppose if queue was empty
            firstIndex = 0;
        }
        size++; // Finally, incremented the size
    }
    T front()
    { // To return the element at front position
        if (isEmpty())
        { // To check if the queue was initially empty
            cout << "Queue is empty ! " << endl;
            return 0;
        }
        return data[firstIndex]; // otherwise returned the element
    }
    T dequeue()
    { // Function for deletion
        if (isEmpty())
        { // To check if the queue was empty
            cout << "Queue is empty ! " << endl;
            return 0;
        }
        T ans = data[firstIndex];
        firstIndex = (firstIndex + 1) % capacity;
        size--; // Decrementing the size by 1
        if (size == 0)
        {                    // If queue becomes empty after deletion, then
            firstIndex = -1; // resetting the original parameters
            nextIndex = 0;
        }
        return ans;
    }
};
int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    Queue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    // q.enqueue(50);
    // q.enqueue(60);
    // cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    q.enqueue(60);
    q.enqueue(70);
    cout << q.front() << endl;
    // q.enqueue(90);
    cout << q.dequeue() << endl;
    // cout << q.dequeue() << endl;
    // cout << q.front() << endl;
    // cout << q.getSize() << endl;

    return 0;
}
