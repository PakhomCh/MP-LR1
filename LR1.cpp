#include <iostream> 
#include <math.h>
#define EPSILON 0.0001
#define MAX_ITERATIONS 10

using namespace std;

double F(double x)
{
    return  3 * pow(x, 4) + 8 * pow(x, 3) + 6 * pow(x, 2) - 11;
}

double deriF(double x)
{
    return 12 * pow(x, 3) + 24 * pow(x, 2) + 12 * x;
}

double G(double x)
{
    return sqrt(11) / sqrt(3 * pow(x, 2) + 8 * x + 6);
}

double S(double x)
{
    return log10(x + 2) + 2 * x - 3;
}

double deriS(double x)
{
    return 2 + 1 / (x * log(10) + log(100));
}

double T(double x)
{
    return 1.5 - log10(sqrt(x + 2));
}

pair<double, double> P(double x, double y)
{
    return { -1 * log(y), sqrt(sqrt(5 - pow(x, 4)))};
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

void wegsteinF(double x)
{
    bool flag = true;
    int itr = 0, q = 0.25;
    double x1;
    while (flag && (itr < MAX_ITERATIONS))
    {
        itr ++;

        x1 = G(x); // calculating the fixed point new x
        x1 = q * x + (1 - q) * x1;  // Applying Wegstein's method

        if (abs(x1 - x) < EPSILON) // Terminates if the error is less than tolerance
            flag = false;

        x = x1;
        if (itr > MAX_ITERATIONS) // Termination if number of iterations exceeds the limit
            flag = false;

        cout << "Root: " << x << endl;
    }
    if (itr > MAX_ITERATIONS)
        cout << "Root cannot be found using Muller's method" << endl;
    else
        cout << "Root: " << x << endl;
    cout << endl;
}

void wegsteinS(double x)
{
    bool flag = true;
    int itr = 0, q = 0.25;
    double x1;
    while (flag && itr < MAX_ITERATIONS)
    {
        itr++;

        x1 = T(x); // calculating the fixed point new x
        x1 = q * x + (1 - q) * x1;  // Applying Wegstein's method

        if (abs(x1 - x) < EPSILON) // Terminates if the error is less than tolerance
            flag = false;

        x = x1;
        if (itr > MAX_ITERATIONS) // Termination if number of iterations exceeds the limit
            flag = false;

        cout << "Root: " << x << endl;
    }
    if (itr > MAX_ITERATIONS)
        cout << "Root cannot be found using Muller's method" << endl;
    else
        cout << "Root: " << x << endl;
    cout << endl;
}

int main()
{
    cout << "**************** PART 1 ****************" << endl;
    cout << "Expected roots: -2.1 and 0.85" << endl;

    double inroot = -2.1;
    newtonRaphsonF(inroot);

    inroot = 0.85;
    newtonRaphsonF(inroot);

    cout << endl;
    cout << "Expected roots: 1.24" << endl;

    inroot = 1.2;
    newtonRaphsonS(inroot);

    cout << "**************** PART 2 ****************" << endl;
    cout << "Expected roots: -2.1 and 0.85" << endl;

    inroot = -2.1;
    fixPointIterationF(inroot);

    inroot = -0.85;
    fixPointIterationF(inroot);

    cout << endl;
    cout << "Expected roots: 1.24" << endl;

    inroot = 1.24;
    fixPointIterationS(inroot);

    cout << "**************** PART 3 ****************" << endl;
    cout << "Expected roots: -2.1 and 0.85" << endl;

    wegsteinF(-2.1);
    wegsteinF(0.85);

    cout << endl;
    cout << "Expected roots: 1.24" << endl;
    wegsteinS(1.24);

    cout << "**************** PART 4 ****************" << endl;
    cout << "Expected roots: {-0.54, 1.72} and {1.73, 0.17}" << endl;

    fixPointIterationP(-1, 1);

    fixPointIterationP(1.7, 0.2);

    return 0;
}