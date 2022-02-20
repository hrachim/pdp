#include <iostream>
#include <stdlib.h>
using namespace std;

void print(int **arr, int r, int c, string text) {
    cout << text << endl;
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }
}

int main()
{
    cout << "Matrix Algorithm implementation!"<< endl;
    int r1, c1, r2, c2;
    cout << "Enter row 1 and column 1 : ";
    cin >> r1 >> c1;
    cout << "Enter row 2 and column 2 : ";
    cin >> r2 >> c2;
    while (c1 != r2)
    {
        cout << "Enter row 1 and column 1 : ";
        cin >> r1 >> c1;
        cout << "Enter row 2 and column 2 : ";
        cin >> r2 >> c2;
    }

    int** arr1 = new int*[r1];
    int** arr2 = new int*[r2];
    int** result = new int*[r1];
    for(int i = 0; i < r1; ++i)
    {
        arr1[i] = new int[c1];
    }

    for(int i = 0; i < r2; ++i)
    {
        arr2[i] = new int[c2];
    }

    for(int i = 0; i < r1; ++i)
    {
        result[i] = new int[c2];
    }

    for(int i = 0; i < r1; ++i)
    {
        for(int j = 0; j < c1; ++j)
        {
            arr1[i][j] = j;
        }
    }

    for(int i = 0; i < r2; ++i)
    {
        for(int j = 0; j < c2; ++j)
        {
            arr2[i][j] = j;
        }
    }

    for(int i = 0; i < r1; ++i)
    {
        for(int j = 0; j < c2; ++j)
        {
            result[i][j]=0;
        }
    }

    print(arr1, r1, c1, "Matrix 1 is");
    print(arr2, r2, c2, "Matrix 2 is");

    for (int i = 0; i < r1; ++i)
    {
        for (int j = 0; j < c2; ++j)
        {
            for (int k = 0; k < c1; ++k)
            {
                result[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

    print(result, r1, c2, "Result matrix is");

    return 0;
}
