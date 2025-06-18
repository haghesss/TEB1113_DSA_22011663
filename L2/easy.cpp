#include <iostream>
using namespace std;

void calculateDiagonalSums(int matrix[][100], int size)
{
    int primarySum = 0;
    int secondarySum = 0;

    for (int i = 0; i < size; ++i)
    {
        primarySum += matrix[i][i];
        secondarySum += matrix[i][size - i - 1];
    }

    cout << "Output:\n";
    cout << "Primary Diagonal Sum: " << primarySum << endl;
    cout << "Secondary Diagonal Sum: " << secondarySum << endl;
}

int main()
{
    int size;
    cout << "Input: ";
    cin >> size;

    int matrix[100][100];  

    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            cin >> matrix[i][j];
        }
    }

    calculateDiagonalSums(matrix, size);

    return 0;
}
