#include <iostream>
#include <string>
using namespace std;

template <typename V>
class MapNode
{
public:
    string key;
    V value;
    MapNode *next;

    MapNode(string key, V value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }
    ~MapNode()
    {
        delete next;
    }
};

template <typename V>
class ourmap
{
    MapNode<V> **bucketArray;
    int count;
    int numBucket;

public:
    ourmap()
    {
        count = 0;
        numBucket = 5;
        bucketArray = new MapNode<V> *[numBucket];
        for (int i = 0; i < numBucket; i++)
        {
            bucketArray[i] = NULL;
        }
    }
    ~ourmap()
    {
        for (int i = 0; i < numBucket; i++)
        {
            delete bucketArray[i];
        }
        delete bucketArray;
    }

    int getSize()
    {
        return count;
    }
    V getValue(string key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = bucketArray[bucketIndex];
        while (head != NULL)
        {
            if (head->key == key)
            {
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }

private:
    int getBucketIndex(string key)
    {
        int hashcode = 0;
        int currentCoeff = 1;
        for (int i = key.length() - 1; i >= 0; i--)
        {
            hashcode += key[i] * currentCoeff;
            hashcode %= numBucket;
            currentCoeff *= 37;
            currentCoeff %= numBucket;
        }
        return hashcode % numBucket;
    }
    void rehash()
    {
        MapNode<V> **temp = bucketArray;
        bucketArray = new MapNode<V> *[2 * numBucket];
        for (int i = 0; i < 2 * numBucket; i++)
        {
            bucketArray[i] = NULL;
        }
        int oldNumBucket = numBucket;
        count = 0;
        numBucket *= 2;
        for (int i = 0; i < oldNumBucket; i++)
        {
            MapNode<V> *head = temp[i];
            while (head != NULL)
            {
                string key = head->key;
                V value = head->value;
                insert(key, value);
                head = head->next;
            }
        }
        for (int i = 0; i < oldNumBucket; i++)
        {
            MapNode<V> *head = temp[i];
            delete head;
        }
        delete[] temp;
    }

public:
    double getLoadFactor()
    {
        return (1.0 * count) / numBucket;
    }

    void insert(string key, V value)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = bucketArray[bucketIndex];
        while (head != NULL)
        {
            if (head->key == key)
            {
                head->value = value;
                return;
            }
            head = head->next;
        }
        head = bucketArray[bucketIndex];
        MapNode<V> *newNode = new MapNode<V>(key, value);
        newNode->next = head;
        bucketArray[bucketIndex] = newNode;
        count++;
        double loadFactor = (1.0 * count) / numBucket;
        if (loadFactor > 0.7)
        {
            rehash();
        }
    }
    V remove(string key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = bucketArray[bucketIndex];
        MapNode<V> *prev = NULL;
        while (head != NULL)
        {
            if (head->key == key)
            {
                if (prev == NULL)
                {
                    bucketArray[bucketIndex] = head->next;
                }
                else
                {
                    prev->next = head->next;
                }
                V ans = head->value;
                head->next = NULL;
                delete head;
                count--;
                return ans;
            }
            prev = head;
            head = head->next;
        }
        return 0;
    }
};
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ourmap<int> map;
    for (int i = 0; i < 10; i++)
    {
        char c = '0' + i;
        string key = "abc";
        key += c;
        int value = i + 1;
        map.insert(key, value);
        cout << map.getLoadFactor() << endl;
    }
    cout << endl;
    map.remove("abc2");
    map.remove("abc7");
    for (int i = 0; i < 10; i++)
    {
        char c = '0' + i;
        string key = "abc";
        key += c;
        cout << key << ": " << map.getValue(key) << endl;
    }

    cout << endl;
    cout << map.getSize() << endl;
}