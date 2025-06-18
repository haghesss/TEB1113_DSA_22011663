#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Input: ";
    cin >> n;

    int matrix[100][100]; 

    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> matrix[i][j];
        }
    }

    cout << "Output:\n";
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = n - 1; j >= 0; --j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
