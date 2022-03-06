class Stack
// {
//     T *data;
//     int nextIndex;
//     int capacity;

// public:
//     Stack()
//     {
//         data = new T[5];
//         nextIndex = 0;
//         capacity = 5;
//     }
//     // return the no. of elements in the stack
//     int size()
//     {
//         return nextIndex;
//     }

//     bool isEmpty()
//     {
//         return (nextIndex == 0);
//     }

//     // insert Element
//     void push(T element)
//     {
//         if (nextIndex == capacity)
//         {
//             T *newData = new T[capacity * 2];
//             for (int i = 0; i < capacity; i++)
//             {
//                 newData[i] = data[i];
//             }
//             delete[] data;
//             data = newData;
//             capacity *= 2;
//         }
//         data[nextIndex] = element;
//         nextIndex++;
//     }
//     // delete Element
//     T pop()
//     {
//         if (isEmpty())
//         {
//             cout << "Stack is Underflow" << endl;
//             return 0;
//         }
//         nextIndex--;
//         return data[nextIndex];
//     }
//     // top most element
//     T top()
//     {
//         if (isEmpty() || nextIndex == capacity)
//         {
//             return 0;
//         }
//         return data[nextIndex - 1];
//     }
// };