#include <iostream>
using namespace std;

// Definición del tamaño del tablero
#define N 8

// Función para imprimir el tablero
void ImprimeTablero(int Tablero[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << Tablero[i][j] << " ";
        cout << endl;
    }
}

// Función para verificar si una reina puede ser colocada en una posición
bool EsSegura(int Tablero[N][N], int row, int col) {
    int i, j;

    // Verifica la fila hacia la izquierda
    for (i = 0; i < col; i++)
        if (Tablero[row][i])
            return false;

    // Verifica la diagonal superior hacia la izquierda
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (Tablero[i][j])
            return false;

    // Verifica la diagonal inferior hacia la izquierda
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (Tablero[i][j])
            return false;

    // Si la posición es segura, retorna true
    return true;
}

// Función para resolver el problema de las 8 reinas utilizando fuerza bruta
void ResuelveReina(int Tablero[N][N], int col, int &Soluciones) {
    // Si se han colocado todas las reinas, imprime el tablero y retorna
    if (col == N) {
        Soluciones++;
        cout << "Solucion #" << Soluciones << ":" << endl;
        ImprimeTablero(Tablero);
        return;
    }

    // Intenta colocar la reina en cada fila de la columna actual
    for (int i = 0; i < N; i++) {
        // Verifica si la posición es segura
        if (EsSegura(Tablero, i, col)) {
            // Coloca la reina en la posición
            Tablero[i][col] = 1;

            // Resuelve el problema para la siguiente columna
            ResuelveReina(Tablero, col+1, Soluciones);

            // Retira la reina de la posición
            Tablero[i][col] = 0;
        }
    }
}

int main() {
    int Tablero[N][N] = {0};
    int Soluciones = 0;

    // Resuelve el problema de las 8 reinas
    ResuelveReina(Tablero, 0, Soluciones);

    cout << "Se encontraron " << Soluciones << " soluciones." << endl;

    return 0;
}
