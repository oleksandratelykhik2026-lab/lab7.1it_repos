#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int ROWS = 9;
const int COLS = 6;

// Формування матриці
void Create(int a[ROWS][COLS], int Low, int High)
{
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
			a[i][j] = Low + rand() % (High - Low + 1); // ініціалізація елементів матриці випадковими числами з діапазону [Low, High]
}

// Виведення матриці
void Print(int a[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
            cout << setw(4) << a[i][j];

        cout << endl;
    }

    cout << endl;
}

// Обмін двох стовпців
void Change(int a[ROWS][COLS], int col1, int col2)
{
    for (int i = 0; i < ROWS; i++)
    {
        int temp = a[i][col1];
        a[i][col1] = a[i][col2];
        a[i][col2] = temp;
    }
}

// Сортування стовпців за трьома ключами
void Sort(int a[ROWS][COLS])
{
    for (int pass = 0; pass < COLS - 1; pass++)
    {
        for (int j = 0; j < COLS - pass - 1; j++)
        {
			bool needSwap = false; // Прапорець для визначення необхідності обміну стовпців

			if (a[0][j] > a[0][j + 1]) // Порівняння перших ключів
                needSwap = true;

            else if (a[0][j] == a[0][j + 1] &&
				a[1][j] < a[1][j + 1]) // Порівняння других ключів
                needSwap = true;

            else if (a[0][j] == a[0][j + 1] &&
                a[1][j] == a[1][j + 1] &&
				a[2][j] < a[2][j + 1]) // Порівняння третіх ключів
                needSwap = true;

            if (needSwap)
				Change(a, j, j + 1); // Обмін стовпців, якщо потрібно
        }
    }
}

// Обчислення кількості та суми,
// заміна потрібних елементів нулями
void Calc(int a[ROWS][COLS], int& S, int& k)
{
    S = 0;
    k = 0;

    for (int i = 0; i < ROWS; i++)
    {
		for (int j = 0; j < COLS; j++) // Перебір елементів матриці
        {
			if (a[i][j] % 2 == 0 && a[i][j] % 7 != 0) // Перевірка на парність та неподільність на 7
            {
				S += a[i][j]; // Додаємо елемент до суми
                k++;
				a[i][j] = 0; // Замінюємо елемент на нуль
            }
        }
    }
}

int main()
{
    srand(static_cast<unsigned>(time(0)));

    int Z[ROWS][COLS];

	Create(Z, 18, 74); // Формування матриці випадковими числами з діапазону [18, 74]

    cout << "Initial matrix:" << endl;
    Print(Z);

    Sort(Z);

    cout << "Sorted matrix:" << endl;
    Print(Z);

    int S = 0;
    int k = 0;

    Calc(Z, S, k);

    cout << "Sum = " << S << endl;
    cout << "Count = " << k << endl;

    cout << "Modified matrix:" << endl;
    Print(Z);

    return 0;
}