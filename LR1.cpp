#include <iostream> 
#include <math.h>
#define EPSILON 0.0001
#define MAX_ITERATIONS 10

using namespace std;

double F(double x)
{
    return  3 * pow(x, 4) - 8 * pow(x, 3) - 18 * pow(x, 2) + 2;
}

double deriF(double x)
{
    return 12 * pow(x, 3) - 24 * pow(x, 2) - 36 * x;
}

double G(double x)
{
    return 1 / sqrt(-1.5 * pow(x, 2) + 4 * x + 9);
}

double S(double x)
{
    return tan(0.55 * x + 0.1) - pow(x, 2);
}

double deriS(double x)
{
    return -2 * x + 0.55 / (pow(cos(0.1 + 0.55 * x), 2));
}

double T(double x)
{
    return tan(0.55 * x + 0.1) / x;
}

pair<double, double> P(double x, double y)
{
    return { sin(x + y) - 0.2, sqrt(1 - pow(x, 2))};
}

void newtonRaphsonF(double x)
{
    double h = F(x) / deriF(x);
    cout << "Root: " << x << endl;
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
    cout << "Root: " << x << endl;
    while (abs(h) >= EPSILON)
    {
        h = S(x) / deriS(x);
        x = x - h;
        cout << "Root: " << x << endl;
    }
    cout << endl;
}

void fixPointIterationF(double x)
{
    double h = x - G(x);
    cout << "Root: " << x << endl;
    while (abs(h) >= EPSILON)
    {
        h = x - G(x);
        x = G(x);
        cout << "Root: " << x << endl;
    }
    cout << endl;
}

void fixPointIterationS(double x)
{
    double h = x - T(x);
    cout << "Root: " << x << endl;
    while (abs(h) >= EPSILON)
    {
        h = x - T(x);
        x = T(x);
        cout << "Root: " << x << endl;
    }
    cout << endl;
}

void fixPointIterationP(double x, double y)
{
    double h = max(abs(x - P(x, y).first), abs(y - P(x, y).second)), temp;
    cout << "Root: " << x << ", " << y << endl;
    while (h >= EPSILON)
    {
        h = max(abs(x - P(x, y).first), abs(y - P(x, y).second));
        temp = x;
        x = P(x, y).first;
        y = P(temp, y).second;
        cout << "Root: " << x << ", " << y << endl;
    }
    cout << endl;
}

void mullerF(double a, double b, double c)
{
    int i;
    double res;

    for (i = 0;; ++i)
    {
        // Calculating various constants required
        // to calculate x3
        double f1 = F(a);
        double f2 = F(b);
        double f3 = F(c);
        double d1 = f1 - f3;
        double d2 = f2 - f3;
        double h1 = a - c;
        double h2 = b - c;
        double a0 = f3;
        double a1 = (((d2 * pow(h1, 2)) - (d1 * pow(h2, 2))) / ((h1 * h2) * (h1 - h2)));
        double a2 = (((d1 * h2) - (d2 * h1)) / ((h1 * h2) * (h1 - h2)));
        double x = ((-2 * a0) / (a1 + abs(sqrt(a1 * a1 - 4 * a0 * a2))));
        double y = ((-2 * a0) / (a1 - abs(sqrt(a1 * a1 - 4 * a0 * a2))));

        // Taking the root which is closer to x2
        if (x >= y)
            res = x + c;
        else
            res = y + c;

        // checking for resemblance of x3 with x2 till
        // two decimal places
        double m = res * 100;
        double n = c * 100;
        m = floor(m);
        n = floor(n);
        if (m == n)
            break;
        a = b;
        b = c;
        c = res;
        cout << "Root: " << res << endl;
        if (i > MAX_ITERATIONS)
            break;
    }

    if (i > MAX_ITERATIONS)
        cout << "Root cannot be found using Muller's method" << endl;
    else
        cout << "Root: " << res << endl;
    cout << endl;
}

void mullerS(double a, double b, double c)
{
    int i;
    double res;

    for (i = 0;; ++i)
    {
        // Calculating various constants required
        // to calculate x3
        double f1 = S(a);
        double f2 = S(b);
        double f3 = S(c);
        double d1 = f1 - f3;
        double d2 = f2 - f3;
        double h1 = a - c;
        double h2 = b - c;
        double a0 = f3;
        double a1 = (((d2 * pow(h1, 2)) - (d1 * pow(h2, 2))) / ((h1 * h2) * (h1 - h2)));
        double a2 = (((d1 * h2) - (d2 * h1)) / ((h1 * h2) * (h1 - h2)));
        double x = ((-2 * a0) / (a1 + abs(sqrt(a1 * a1 - 4 * a0 * a2))));
        double y = ((-2 * a0) / (a1 - abs(sqrt(a1 * a1 - 4 * a0 * a2))));

        // Taking the root which is closer to x2
        if (x >= y)
            res = x + c;
        else
            res = y + c;

        // checking for resemblance of x3 with x2 till
        // two decimal places
        double m = res * 100;
        double n = c * 100;
        m = floor(m);
        n = floor(n);
        if (m == n)
            break;
        a = b;
        b = c;
        c = res;
        cout << "Root: " << res << endl;
        if (i > MAX_ITERATIONS)
            break;
        
    }
    if (i > MAX_ITERATIONS)
        cout << "Root cannot be found using Muller's method" << endl;
    else
        cout << "Root: " << res << endl;
    cout << endl;
}

int main()
{
    cout << "**************** PART 1 ****************" << endl;
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

    cout << "**************** PART 2 ****************" << endl;
    cout << "Expected roots: -1.3, -0.3, 0.3 and 4.1" << endl;

    inroot = -1.3;
    fixPointIterationF(inroot);

    inroot = -0.3;
    fixPointIterationF(inroot);

    inroot = 0.3;
    fixPointIterationF(inroot);

    inroot = 4.1;
    fixPointIterationF(inroot);

    cout << endl;
    cout << "Expected roots: -3.2, -0.1, 0.7, 2.3" << endl;

    inroot = -3.2;
    fixPointIterationS(inroot);

    inroot = -0.1;
    fixPointIterationS(inroot);

    inroot = 0.7;
    fixPointIterationS(inroot);

    inroot = 2.3;
    fixPointIterationS(inroot);

    cout << "**************** PART 3 ****************" << endl;
    cout << "Expected roots: -1.3, -0.3, 0.3 and 4.1" << endl;

    mullerF(-3, -2, -1.3);
    mullerF(-2, -1.3, -0.3);
    mullerF(-1.3, -0.3, 0.3);
    mullerF(-0.3, 0.3, 4.1);

    cout << endl;
    cout << "Expected roots: -3.2, -0.1, 0.7, 2.3" << endl;
    mullerS(-5, -4, -3.2);
    mullerS(-4, -3.2, -0.1);
    mullerS(-3.2, -0.1, 0.7);
    mullerS(-0.1, 0.7, 2.3);

    cout << "**************** PART 4 ****************" << endl;
    cout << "Expected roots: {-0.99, 0.07} and {0.78, 0.61}" << endl;

    fixPointIterationP(-0.1, 0);

    fixPointIterationP(0.8, 0.6);

    return 0;
}