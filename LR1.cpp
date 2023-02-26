#include <iostream>
#include <math.h>
#define EPSILON 0.0001


using namespace std;

double F(double x)
{
    return  3 * pow(x, 4) + 8 * pow(x, 3) + 6 * pow(x, 2) - 11;
}

double deriF(double x)
{
    return 12 * pow(x, 3) + 24 * pow(x, 2) + 12 * x;
}

double S(double x)
{
    return log10(2 + x) + 2 * x - 3;
}

double deriS(double x)
{
    return 1 / log(10) / (2 + x) + 2;
}

void newtonRaphsonF(double x)
{
    double h = F(x) / deriF(x);
    while (abs(h) >= EPSILON)
    {
        h = F(x) / deriF(x);
        x = x - h;
        cout << "Root: " << x << endl;
    }
    
}

void newtonRaphsonS(double x)
{
    double h = S(x) / deriS(x);
    while (abs(h) >= EPSILON)
    {
        h = S(x) / deriS(x);
        x = x - h;
        cout << "Root: " << x << endl;
    }
}

int main()
{
    cout << "Expected roots: -2.1 and 0.85" << endl;

    double inroot = -2.1;
    newtonRaphsonF(inroot);

    inroot = 0.85;
    newtonRaphsonF(inroot);

    cout << endl;
    cout << "Expected roots: 1.24" << endl;

    inroot = 0.85;
    newtonRaphsonS(inroot);

    return 0;
}
