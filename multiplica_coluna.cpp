
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

const int M = 500, N = 500, X = 500;

void inicializa(vector<vector<double>>& matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

void multiplica_coluna(const vector<vector<double>>& A, const vector<vector<double>>& B, vector<vector<double>>& C) {
    for (int j = 0; j < X; j++) {
        for (int i = 0; i < M; i++) {
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

    inicializa(A, M, N);
    inicializa(B, N, X);

    auto start = high_resolution_clock::now();
    multiplica_coluna(A, B, C);
    auto end = high_resolution_clock::now();
    cout << "Tempo (coluna): " << duration<double>(end - start).count() << " segundos." << endl;

    return 0;
}
