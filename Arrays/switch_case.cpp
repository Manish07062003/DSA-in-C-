#include <iostream>
using namespace std;
int main()
{
    char button;
    cout << "input a character: ";
    cin >> button;
    switch (button)
    {
    case 'a':
        cout << "Hello" << endl;
        break;
    case 'b':
        cout << "Namaste" << endl;
        break;
    case 'c':
        cout << "Salute" << endl;
        break;
    case 'd':
        cout << "Hola" << endl;
        break;

    default:
        cout <<  "I am still learning more!" << endl;
        break;
    }
}