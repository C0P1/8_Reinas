#include <iostream>
using namespace std;

// Definici�n del tama�o del tablero
#define N 8

// Funci�n para imprimir el tablero
void ImprimeTablero(int Tablero[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << Tablero[i][j] << " ";
        cout << endl;
    }
}

// Funci�n para verificar si una reina puede ser colocada en una posici�n
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

    // Si la posici�n es segura, retorna true
    return true;
}

// Funci�n para resolver el problema de las 8 reinas utilizando fuerza bruta
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
        // Verifica si la posici�n es segura
        if (EsSegura(Tablero, i, col)) {
            // Coloca la reina en la posici�n
            Tablero[i][col] = 1;

            // Resuelve el problema para la siguiente columna
            ResuelveReina(Tablero, col+1, Soluciones);

            // Retira la reina de la posici�n
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
