#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

const int M = 500, N = 500, X = 500;
const int BLOCK_SIZE = 32;

void inicio(vector<vector<double>>& matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

void multiplica_blocagem(const vector<vector<double>>& A, const vector<vector<double>>& B, vector<vector<double>>& C, int block_size) {
    for (int i = 0; i < M; i += block_size) {
        for (int j = 0; j < X; j += block_size) {
            for (int k = 0; k < N; k += block_size) {
                for (int ii = i; ii < min(i + block_size, M); ii++) {
                    for (int jj = j; jj < min(j + block_size, X); jj++) {
                        for (int kk = k; kk < min(k + block_size, N); kk++) {
                            C[ii][jj] += A[ii][kk] * B[kk][jj];
                        }
                    }
                }
            }
        }
    }
}

int main() {
    vector<vector<double>> A(M, vector<double>(N));
    vector<vector<double>> B(N, vector<double>(X));
    vector<vector<double>> C(M, vector<double>(X, 0));

    inicio(A, M, N);
    inicio(B, N, X);

    auto start = high_resolution_clock::now();
    multiplica_blocagem(A, B, C, BLOCK_SIZE);
    auto end = high_resolution_clock::now();
    cout << "Tempo (blocagem): " << duration<double>(end - start).count() << " segundos." << endl;

    return 0;
}
