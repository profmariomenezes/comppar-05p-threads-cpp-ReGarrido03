#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

const int M = 500, N = 500, X = 500;

void iniciar(vector<vector<double>>& matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

void multiplicar_linha(const vector<vector<double>>& A, const vector<vector<double>>& B, vector<vector<double>>& C) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < X; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    vector<vector<double>> A(M, vector<double>(N));
    vector<vector<double>> B(N, vector<double>(X));
    vector<vector<double>> C(M, vector<double>(X, 0));

    iniciar(A, M, N);
    iniciar(B, N, X);

    auto start = high_resolution_clock::now();
    multiplicar_linha(A, B, C);
    auto end = high_resolution_clock::now();
    cout << "Tempo (linha): " << duration<double>(end - start).count() << " segundos." << endl;

    return 0;
}
