#include <iostream>
#include <math.h>
#define EPSILON 0.0001


using namespace std;

double F(double x)
{
    return  3 * pow(x, 4) - 8 * pow(x, 3) - 18 * pow(x, 2) + 2;
}

double deriF(double x)
{
    return 12 * pow(x, 3) - 24 * pow(x, 2) - 36 * x;
}

double S(double x)
{
    return tan(0.55 * x + 0.1) - pow(x, 2);
}

double deriS(double x)
{
    return -2 * x + 0.55 / (pow(cos(0.1 + 0.55 * x), 2));
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
    cout << endl;
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
    cout << endl;
}

int main()
{
    cout << "Expected roots: -1.3, -0.3, 0.3 and 4.1" << endl;

    double inroot = -1.3;
    newtonRaphsonF(inroot);

    inroot = -0.3;
    newtonRaphsonF(inroot);

    inroot = 0.3;
    newtonRaphsonF(inroot);

    inroot = 4.1;
    newtonRaphsonF(inroot);

    cout << endl;
    cout << "Expected roots: -3.2, -0.1, 0.7, 2.3" << endl;

    inroot = -3.2;
    newtonRaphsonS(inroot);

    inroot = -0.1;
    newtonRaphsonS(inroot);

    inroot = 0.7;
    newtonRaphsonS(inroot);

    inroot = 2.3;
    newtonRaphsonS(inroot);

    return 0;
}
