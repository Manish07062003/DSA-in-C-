
#include <iostream>
using namespace std;
class Polynomial
{
public:
    int *degCoeff; // Name of your array (Don't change this)
    int capacity;
    // Complete the class
public:
    Polynomial()
    {
        capacity = 10;
        degCoeff = new int[10];
        for (int i = 0; i < 10; i++)
        {
            degCoeff[i] = 0;
        }
    }
    Polynomial(const Polynomial &p)
    {
        this->degCoeff = new int[p.capacity];
        for (int i = 0; i < p.capacity; i++)
        {
            this->degCoeff[i] = p.degCoeff[i];
        }
        this->capacity = p.capacity;
    }
    void operator=(const Polynomial &p)
    {
        delete[] this->degCoeff;
        this->degCoeff = new int[p.capacity];
        for (int i = 0; i < p.capacity; i++)
        {
            this->degCoeff[i] = p.degCoeff[i];
        }
        this->capacity = p.capacity;
    }
    void setCoefficient(int deg, int coeff)
    {
        if (deg >= capacity)
        {
            int size = capacity * 2;
            while (size <= deg)
            {
                size *= 2;
            }
            int *newDeg = new int[size], i;
            for (i = 0; i < size; i++)
            {
                newDeg[i] = 0;
            }
            for (i = 0; i < capacity; i++)
            {
                newDeg[i] = degCoeff[i];
            }
            delete[] degCoeff;
            this->capacity = size;
            degCoeff = newDeg;
        }
        degCoeff[deg] = coeff;
    }
    Polynomial operator+(const Polynomial &p)
    {
        Polynomial pnew;
        int i = 0, j = 0;
        while (i < this->capacity && j < p.capacity)
        {
            int result = this->degCoeff[i] + p.degCoeff[j];
            pnew.setCoefficient(i, result);
            i++;
            j++;
        }
        while (i < this->capacity)
        {
            pnew.setCoefficient(i, this->degCoeff[i]);
            i++;
        }
        while (j < p.capacity)
        {
            pnew.setCoefficient(j, p.degCoeff[j]);
            j++;
        }
        return pnew;
    }
    Polynomial operator-(const Polynomial &p)
    {
        Polynomial pnew;
        int i = 0, j = 0;
        while (i < this->capacity && j < p.capacity)
        {
            int result = this->degCoeff[i] - p.degCoeff[j];
            pnew.setCoefficient(i, result);
            i++;
            j++;
        }
        while (i < this->capacity)
        {
            pnew.setCoefficient(i, this->degCoeff[i]);
            i++;
        }
        while (j < p.capacity)
        {
            pnew.setCoefficient(j, -p.degCoeff[j]);
            j++;
        }
        return pnew;
    }
    Polynomial operator*(const Polynomial &p)
    {
        Polynomial pnew;
        int i = 0, j = 0;
        for (int i = 0; i < p.capacity; i++)
        {
            for (int j = 0; j < this->capacity; j++)
            {
                int deg = i + j;
                int coeff = this->degCoeff[j] * p.degCoeff[i];
                if (deg < pnew.capacity)
                {
                    coeff += pnew.degCoeff[deg];
                }
                pnew.setCoefficient(deg, coeff);
            }
        }
        return pnew;
    }
    bool operator==(const Polynomial &p2)
    {
        int maxcapacity = max(p2.capacity, this->capacity);
        for (int i = 0; i < maxcapacity; i++)
        {
            if (this->degCoeff[i] != p2.degCoeff[i])
            {
                return false;
            }
        }
        return true;
    }
    void print()
    {
        for (int i = 0; i < capacity; i++)
        {
            if (degCoeff[i] != 0)
            {
                cout << degCoeff[i] << "x" << i << " ";
            }
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
    int count1, count2, choice;
    cin >> count1;
    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];

    for (int i = 0; i < count1; i++)
    {
        cin >> degree1[i];
    }

    for (int i = 0; i < count1; i++)
    {
        cin >> coeff1[i];
    }

    Polynomial first;
    for (int i = 0; i < count1; i++)
    {
        first.setCoefficient(degree1[i], coeff1[i]);
    }

    cin >> count2;

    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];

    for (int i = 0; i < count2; i++)
    {
        cin >> degree2[i];
    }

    for (int i = 0; i < count2; i++)
    {
        cin >> coeff2[i];
    }

    Polynomial second;
    for (int i = 0; i < count2; i++)
    {
        second.setCoefficient(degree2[i], coeff2[i]);
    }

    cin >> choice;

    Polynomial result;
    switch (choice)
    {
        // Add
    case 1:
        result = first + second;
        result.print();
        break;
        // Subtract
    case 2:
        result = first - second;
        result.print();
        break;
        // Multiply
    case 3:
        result = first * second;
        result.print();
        break;

    case 4: // Copy constructor
    {
        Polynomial third(first);
        if (third.degCoeff == first.degCoeff)
        {
            cout << "false" << endl;
        }
        else
        {
            cout << "true" << endl;
        }
        break;
    }

    case 5: // Copy assignment operator
    {
        Polynomial fourth(first);
        if (fourth.degCoeff == first.degCoeff)
        {
            cout << "false" << endl;
        }
        else
        {
            cout << "true" << endl;
        }
        break;
    }
    }

    return 0;
}
