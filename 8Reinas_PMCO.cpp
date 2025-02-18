#include <iostream>
using namespace std;
#define N 8

// Función para imprimir el tablero
void ImprimirTablero(int tablero[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << tablero[i][j] << " ";
        cout << endl;
    }
}

// Función para verificar si una reina puede ser colocada en una posición segura
bool EsSeguro(int tablero[N][N], int row, int col) {
    int i, j;

    // Verifica la fila hacia la izquierda
    for (i = 0; i < col; i++)
        if (tablero[row][i])
            return false;

    // Verifica la diagonal superior hacia la izquierda
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (tablero[i][j])
            return false;

    // Verifica la diagonal inferior hacia la izquierda
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (tablero[i][j])
            return false;

    // Verifica la fila hacia la derecha
    for (i = col + 1; i < N; i++)
        if (tablero[row][i])
            return false;

    // Verifica la diagonal superior hacia la derecha
    for (i = row, j = col; i >= 0 && j < N; i--, j++)
        if (tablero[i][j])
            return false;

    // Verifica la diagonal inferior hacia la derecha
    for (i = row, j = col; j < N && i < N; i++, j++)
        if (tablero[i][j])
            return false;

    return true;
}

// Función para verificar si la solución ingresada es válida
bool VerificaSol(int tablero[N][N]) {
    int filaCount[N] = {0}, columnaCount[N] = {0};

    // Verifica que haya exactamente una reina por fila y columna
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (tablero[i][j] == 1) {
                filaCount[i]++;
                columnaCount[j]++;
                if (filaCount[i] > 1 || columnaCount[j] > 1)
                    return false;
                // Verifica si la reina está en una posición segura
                tablero[i][j] = 0;  // Temporalmente la quitamos para validar
                if (!EsSeguro(tablero, i, j))
                    return false;
                tablero[i][j] = 1;  // Restauramos la reina
            }
        }
    }
    return true;
}

int main() {
    int tablero[N][N] = {0};

    // Pedir al usuario las posiciones de las reinas
    for (int i = 0; i < N; i++) {
        int row, col;
        cout << "Ingrese la posición de la reina " << i + 1 << ": ";
        cin >> row >> col;

        // Validar que la entrada sea correcta
        if (row < 0 || row >= N || col < 0 || col >= N || tablero[row][col] == 1) {
            cout << "Entrada inválida. Intente de nuevo.\n";
            i--; // Reintentar la entrada para la misma reina
            continue;
        }
        tablero[row][col] = 1;
    }

    // Verificar si la solución ingresada es válida
    if (VerificaSol(tablero))
        cout << "La solución es válida." << endl;
    else
        cout << "La solución es inválida." << endl;

    return 0;
}
