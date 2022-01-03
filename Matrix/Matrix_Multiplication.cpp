#include <iostream>
using namespace std;

#define R1 4
#define C1 4
#define R2 4
#define C2 4

void Matrix_Mul(int A[][C1], int B[][C2]) {
    int C[R1][C2];
    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < R2; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }
}


int main() {
    int A[R1][C1] = {
            {1, 1, 1, 1},
            {2, 2, 2, 2},
            {3, 3, 3, 3},
            {4, 4, 4, 4}
    };

    int B[R2][C2] = {
            {1, 1, 1, 1},
            {2, 2, 2, 2},
            {3, 3, 3, 3},
            {4, 4, 4, 4}
    };

    if (C1 != R2) {
        cout << "The number of columns in Matrix-1  must be equal to the number of rows in "
                "Matrix-2" << endl;
        cout << "Please update MACROs according to your array dimension in #define section"
                << endl;

        return 0;
    }


    Matrix_Mul(A, B);
    return 0;
}