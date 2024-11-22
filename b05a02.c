#include <stdio.h>

double formel(double xVal)
{
    return (xVal * xVal) - 9;
}

double regula(double x1, double x2, double (*f)(double))
{
    double xs;
    double posXs;

    if (f(x2) == f(x1))
    {
        printf("Fehler: Division durch Null in der Regula-Falsi-Methode.\n");
        return -1; 
    }

    xs = x1 - (f(x1) * ((x2 - x1) / (f(x2) - f(x1))));
    if (xs < 0)
    {
        posXs = -xs;
    }
    else
    {
        posXs = xs;
    }
    if (f(posXs) < 1e-6)
    {
        return posXs;
    }
    if ((f(xs) > 0 && f(x1) > 0) || (f(xs) < 0 && f(x1) < 0))
    {
        return regula(xs, x2, f);
    }
    else
    {
        return regula(x1, xs, f);
    }
}

int main(void)
{
    double (*f)(double) = formel;
    double result;
    result = regula(-100, 100, f);
    if (result != -1) {
        printf("Gefundene Nullstelle: %f\n", result);  
    }

    return 0;
}