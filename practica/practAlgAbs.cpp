#include <iostream>
#include <string>

using namespace std;

int main()
{
    string x;
    getline(cin, x);
    int res = stoi(x);
    cout << res+1 << " es el resultado +1 para comprobar que es un entero";
    return 0;
}
