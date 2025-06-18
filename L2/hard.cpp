#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

void updateMatrix(int matrix[][MAX_SIZE], int rows, int columns, bool rowFlags[], bool columnFlags[])
{
    cout << "Output:\n";
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            if (rowFlags[i] || columnFlags[j])
            {
                matrix[i][j] = 1;
            }
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int rows, columns;

    cout << "Input: ";
    cin >> rows >> columns;

    int matrix[MAX_SIZE][MAX_SIZE];
    bool rowFlags[MAX_SIZE] = {false};
    bool columnFlags[MAX_SIZE] = {false};

    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            cin >> matrix[i][j];
            if (matrix[i][j] == 1)
            {
                rowFlags[i] = true;
                columnFlags[j] = true;
            }
        }
    }

    updateMatrix(matrix, rows, columns, rowFlags, columnFlags);

    return 0;
}
