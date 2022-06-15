#include <vector>

// minHeap
class PriorityQueue
{
private:
    vector<int> pq;

public:
    PriorityQueue()
    {
    }

    bool isEmpty()
    {
        return pq.size() == 0;
    }

    // returns the size of priority queue
    int getSize()
    {
        return pq.size();
    }

    int getMin()
    {
        if (isEmpty())
        {
            return 0; // priority queue is empty
        }
        return pq[0];
    }

    void insert(int element)
    {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        // up - heapify

        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[childIndex] < pq[parentIndex])
            {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }

    int removeMin()
    {
        if (isEmpty())
        {
            return 0; // if priority queue is empty return 0
        }
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        // down - heapify

        int parentIndex = 0;
        int leftChild = 2 * parentIndex + 1;
        int rightChild = 2 * parentIndex + 2;
        while (leftChild < pq.size())
        {
            int minIndex = parentIndex;
            if (pq[minIndex] > pq[leftChild])
            {
                minIndex = leftChild;
            }
            if (rightChild < pq.size() && pq[minIndex] > pq[rightChild])
            {
                minIndex = rightChild;
            }
            if (minIndex == parentIndex)
            {
                break;
            }
            int temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = minIndex;
            leftChild = 2 * parentIndex + 1;
            rightChild = 2 * parentIndex + 2;
        }

        return ans;
    }
};