#include <iostream>
#include <string>

using namespace std;

// c)
void div(string a, int b)
{
    for (int i = 0; i <= a.length(); i=i+b)
    {
        for (int j = i; j < i+b; j++)
        {
            cout << a[j];
        }
        cout << endl;
    }
}

// e)
void guardar(string a, int b)
{
    for (int r = 0; r <= a.length(); r = r + b)
    {
        for (int t = r; t < r + b; t++)
        {
            cout << a[t];
        }
        cout << '*';
    }
}

int main()
{
    // a) y b);
    int n;
    string t;
    cout << "Ingrese texto: \t";
    getline(cin, t);
    cout << "Ingrese numero de letras por bloque: \t";
    cin >> n;
    div(t, n);
    guardar(t, n);

}

