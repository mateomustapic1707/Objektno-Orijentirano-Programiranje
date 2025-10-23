#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

double** alocirajMatricu(int m, int n) {
    double** mat = new double* [m];
    for (int i = 0; i < m; i++)
        mat[i] = new double[n];
    return mat;
}

void dealocirajMatricu(double** mat, int m) {
    for (int i = 0; i < m; i++)
        delete[] mat[i];
    delete[] mat;
}

void unesiMatricu(double** mat, int m, int n) {
    cout << "Unesite elemente matrice " << m << "x" << n << ":\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
}

void generirajMatricu(double** mat, int m, int n, double a, double b) {
    srand(time(0));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            mat[i][j] = a + static_cast<double>(rand()) / RAND_MAX * (b - a);
}

void ispisiMatricu(double** mat, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << setw(10) << fixed << setprecision(4) << mat[i][j];
        cout << endl;
    }
}

double** zbrojiMatrice(double** A, double** B, int m, int n) {
    double** C = alocirajMatricu(m, n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

double** oduzmiMatrice(double** A, double** B, int m, int n) {
    double** C = alocirajMatricu(m, n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

double** pomnoziMatrice(double** A, double** B, int m, int n, int p) {
    double** C = alocirajMatricu(m, p);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    return C;
}

double** transponirajMatricu(double** A, int m, int n) {
    double** T = alocirajMatricu(n, m);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            T[j][i] = A[i][j];
    return T;
}

int main() {
    int m = 2, n = 3;
    double** A = alocirajMatricu(m, n);
    double** B = alocirajMatricu(m, n);

    generirajMatricu(A, m, n, 0, 10);
    generirajMatricu(B, m, n, 0, 10);

    cout << "Matrica A:\n"; ispisiMatricu(A, m, n);
    cout << "\nMatrica B:\n"; ispisiMatricu(B, m, n);

    double** C = zbrojiMatrice(A, B, m, n);
    cout << "\nZbroj (A + B):\n"; ispisiMatricu(C, m, n);

    double** T = transponirajMatricu(A, m, n);
    cout << "\nTransponirana matrica A:\n"; ispisiMatricu(T, n, m);

    dealocirajMatricu(A, m);
    dealocirajMatricu(B, m);
    dealocirajMatricu(C, m);
    dealocirajMatricu(T, n);

    return 0;
}
