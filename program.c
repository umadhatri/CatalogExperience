#include <stdio.h>

double lagrangeInterpolation(double x[], double y[], int n, double f) {
    double result = 0.0;
    for (int i = 0; i < n; i++) {
        double term = y[i];
        for (int j = 0; j < n; j++) {
            if (j != i) {
                term *= (f - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }
    return result;
}

int main() {
    // Example input points
    double x[] = {1.0, 2.0, 3.0, 4.0};
    double y[] = {2.0, 4.0, 6.0, 8.0};
    int n = sizeof(x) / sizeof(x[0]);

    double f = 0.0;
    double result = lagrangeInterpolation(x, y, n, f);

    printf("Lagrange's interpolation at f=0: %lf\n", result);

    return 0;
}