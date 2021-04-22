#include <iostream>

using namespace std;

string cifrado(string t1, int k)
{
    string cif = "";

    for (int i = 0; i < t1.length(); i++)
    {
        if (isupper(t1[i]))
        {
            cif += char(int(t1[i] + k - 65) % 26 + 65);
        }
        else
        {
        cif += char(int(t1[i] + k - 97) % 26 + 97);
        }
    }
    return cif;
}

string dCifrado(string t1, int k)
{
    string dcif = "";

    for (int i = 0; i < t1.length(); i++)
    {
        if (isupper(t1[i]))
        {
            dcif += char(int(t1[i] - k - 65) % 26 + 65);
        }

        else
        {
            dcif += char(int(t1[i] - k - 97) % 26 + 97);
        }
    }
    return dcif;
}

int main()
{
    cout << "Texto a cifrar" << endl;
    string t;
    cin >> t;
    cout << "Clave de cifrado" << endl;
    cout << "Texto : \t"      << t << endl;
    string textoC = cifrado(t, 13);
    cout << "Cifrado : \t"    << textoC << endl;
    cout << "Ingresar clave (13 para ROT13)" << endl;
    int c;
    cin >> c;
    cout << "Descifrado : \t" << dCifrado(textoC, c) << endl;

    return 0;
}

/*18.11 Escriba un programa que introduzca por separado un primer nombre y un apellido, y que concatene los dos en un
nuevo objeto string.*/


#include <iostream>
#include <string>
using namespace std;
int main()
{
    string nombre;
    string apellido;
    cout << "Ingrese nombre: ";
    cin >> nombre;
    cout << "Ingrese apellido: ";
    cin >> apellido;
    cout << "Todo completo: ";
    string nombre_completo(nombre + ' ' + apellido);
    cout << nombre_completo;
}

/*18.12 Escriba un programa para jugar al ahorcado.El programa debe elegir una palabra(que se codifica directamente en el
    programa, o se lee de un archivo de texto) y mostrar lo siguiente :
Adivine la palabra : XXXXXX
Cada X representa una letra.El usuario trata de adivinar las letras en la palabra.Deber� mostrarse la respuesta apropiada(si
o no) despu�s de cada intento de adivinar.Despu�s de cada intento incorrecto, muestre el diagrama con otra parte del cuerpo
incluida.Despu�s de siete intentos incorrectos, el usuario deber� colgarse.La pantalla debe tener la siguiente apariencia :
Despu�s de cada intento de adivinar, muestre todos los intentos que hizo el usuario.Si el usuario adivina la palabra correctamente, el programa debe mostrar lo siguiente :
Felicidades!!!Adivino mi palabra.Desea jugar otra vez ? si / no*/


#include <iostream>
#include <string>
using namespace std;
string palabra_original;
string palabra_mostrar;
int vidas;
int intentos;
void mostrar_persona();
void mostrar();
void ingresar(char x);
void iniciar();
int main()
{
    iniciar();
    mostrar();
    while (vidas > 0 && palabra_mostrar != palabra_original)
    {
        char x;
        cout << "Inserte una letra:";
        cin >> x;
        ingresar(x);
        mostrar();
    }
    if (vidas > 0)
    {
        cout << endl << "-------GANASTE-------" << endl << endl;
        cout << "Numero de intentos: " << intentos << endl << endl;
    }
    else
    {
        cout << "PERDISTE, la palabra secreta era: " << palabra_original << endl << endl;
    }
}
void mostrar_persona()
{
    if (vidas <= 6)
    {
        cout << " O " << endl;
        if (vidas <= 5)
        {
            cout << "/";
            if (vidas <= 4)
            {
                cout << "|";
                if (vidas <= 3)
                {
                    cout << "\\" << endl;
                    if (vidas <= 2)
                    {
                        cout << " | " << endl;
                        if (vidas <= 1)
                        {
                            cout << "/ ";
                            if (vidas <= 0)
                            {
                                cout << "\\" << endl;
                            }
                        }
                    }
                }
            }
        }
    }
}
void mostrar()
{
    mostrar_persona();
    cout << endl << "Tus vidas disponibles son: " << vidas << endl;
    cout << "Intente descubrir la palabra: "<< palabra_mostrar << endl;
}
void iniciar()
{
    vidas = 7;
    intentos = -1;
    palabra_original = "abstracta";
    for (int i = 0; i < palabra_original.length(); i++)
    {
        if (palabra_original[i] >= 'A' && palabra_original[i] <= 'Z')
        {
            palabra_original[i] += 32;
        }
    }
    for (int i = 0; i < palabra_original.length(); i++)
    {
        if (palabra_original[i] >= 'a' && palabra_original[i] <= 'z')
        {
            palabra_mostrar += 'X';
        }
        else
        {
            palabra_mostrar += palabra_original[i];
        }
    }
}
void ingresar(char x)
{
    bool perderVidas = true;
    for (int i = 0; i < palabra_original.length(); i++)
    {
        if (x == palabra_original[i])
        {
            perderVidas = false;
            palabra_mostrar[i] = x;
            intentos++;
        }
    }
    if (perderVidas)
    {
        vidas--;
        intentos++;
    }
}

/*18.19 Escriba un programa que inserte los caracteres "******" en la mitad exacta de un objeto string.
*/


#include <iostream>
#include <string>
using namespace std;
int main()
{
    string palabra;
    string x = "*********";
    cout << "Ingrese la palabra: ";
    cin >> palabra;
    palabra.insert(palabra.size() / 2, x);
    cout << "Palabra con asteriscos: ";
    cout << palabra << endl;
    return 0;
}


/*18.21 Escriba un programa que introduzca una l�nea de texto, reemplace todos los signos de puntuaci�n con espacios y utilice
la funci�n strtok de la biblioteca de cadenas estilo C para dividir el objeto string en palabras individuales(tokens).*/





/*18.22 Escriba un programa que introduzca una l�nea de texto y la imprima al rev�s.Use iteradores en su soluci�n.
*/


#include <iostream>
#include <string>
using namespace std;
int main()
{
    string cadena1;
    cout << "Ingrese texto: ";
    getline(cin, cadena1);
    string::reverse_iterator i1 = cadena1.rbegin();
    cout << "Texto invertido: ";

    while (i1 != cadena1.rend())
    {
        cout << *i1;
        ++i1;
    }
    cout << endl;
    return 0;
}


/*18.27 Escriba una versi�n de la rutina de ordenamiento por selecci�n(fi gura 8.28) que ordene objetos string.Use la funci�n
swap en su soluci�n.*/


#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
void selection(string[], const int, bool (*)(int, int));
bool ascendente(int, int);
bool descendente(int, int);
int main()
{
    const int tamArr = 10;
    int orden;
    int cont;
    string arr[tamArr] = { "hola\n","como\n","estas\n","amigo\n","de\n","ciencia\n","de\n","la\n","computacion\n","xd\n" };

    cout << "Escriba la OPCION 1 para el orden ascendente y escriba la OPCION 2 para el orden descendente: ";
    cin >> orden;
    cout << endl << "Elementos de datos en el orden original" << endl << endl;
    for (cont = 0; cont < tamArr; cont++)
    {
        cout << " " << arr[cont];
    }
    if (orden == 1)
    {
        selection(arr, tamArr, ascendente);
        cout << endl << "Elementos en orden ascendente" << endl<<endl;
    }
    else
    {
        selection(arr, tamArr, descendente);
        cout << endl << "Elementos en orden descendente" << endl<<endl;
    }
    for (cont = 0; cont < tamArr; cont++)
    {
        cout << setw(18) << arr[cont];
    }
    cout << endl;

    return 0;
}
void selection(string trabajo[], const int tamanio, bool (*compara)(int, int))
{
    int menorOmayor;
    for (int i = 0; i < tamanio - 1; i++)
    {
        menorOmayor = i;
        for (int index = i + 1; index < tamanio; index++)
        {
            if (!(*compara)(trabajo[menorOmayor].size(), trabajo[index].size()))
            {
                menorOmayor = index;
            }
        }
        trabajo[menorOmayor].swap(trabajo[i]);
    }
}
bool ascendente(int a, int b){
    return a < b; }
bool descendente(int a, int b){
    return a > b; }
