#include <iostream>
using namespace std;

template <typename T>
class Pair
{
    T x; //variables x and y are declared of type T which
    T y; //could take place of any known data type
public:
    void setX(T x)
    {
        this->x = x;
    }
    T getX()
    {
        return x;
    }
    // Now suppose you want to create x of one type (like int) and y of another type (for
    // eg. double), then you can do it in the following way:
    //  To use these in the main() function, simply call the class like this:
    // and the pair of the required types will be created.
    // 2
    void setY(T y)
    {
        this->y = y;
    }
    T getY()
    {
        return y;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Pair<int> p;
    p.setX(10);
    p.setY(20);
    cout << p.getX() << " " << p.getY() << endl;
    Pair<double> q;
    q.setX(10.2);
    q.setY(20.23);
    cout << q.getX() << " " << q.getY() << endl;
}