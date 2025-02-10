#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <cmath>

using namespace std;

int main()
{
    int menuInp;
    do {
        system("cls");
        cout << "Tugas Minggu 1 Alpro" << endl;
        cout << "1. Generate Angka\n"
             << "2. Selection\n"
             << "3. Straight Selection\n"
             << "4. Bubble\n"
             << "5. Two Way Bubble\n"
             << "6. Exit" << endl;
        cout << ">> ";
        cin >> menuInp;

            if (menuInp == 1) {
                system("cls");

                system("pause");
            } else if (menuInp == 2) {
                system("cls");

                system("pause");
            } else if (menuInp == 3) {
                system("cls");

                system("pause");
            } else if (menuInp == 4) {
                system("cls");
                int arr[] = {10, 5, 7, 1, 3, 100};
                int n = sizeof(arr)/sizeof(int);
                cout << n << endl;
                for (int i = 0; i < n; i++) {
                    cout << arr[i] << " ";
                }

                for (int i = 0; i < n / 2 + 1; i++) {
                    for (int j = 0; j < n - i - 1; j++) {
                        if (arr[j] > arr[j + 1]) {
                            int temp = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j + 1] = temp;
                        }
                    }
                }

                cout << endl;
                for (int i = 0; i < n; i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;
                system("pause");
            } else if (menuInp == 5) {
                system("cls");
                int arr[] = {10, 5, 7, 1, 3, 4, 50};
                int n = sizeof(arr)/sizeof(int);
                for (int i = 0; i < n; i++) {
                    cout << arr[i] << " ";
                }

                for (int i = 0; i < sqrt(n); i++) {
                    for (int j = i; j < n - i - 1; j++) {
                        if (arr[j] > arr[j + 1]) {
                            int temp = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j + 1] = temp;
                        }
                    }
                    for (int j = n - i - 1; j > i; j--) {
                        if (arr[j] < arr[j - 1]) {
                            int temp = arr[j];
                            arr[j] = arr[j - 1];
                            arr[j - 1] = temp;
                        }
                    }
                }

                cout << endl;
                for (int i = 0; i < n; i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;

                system("pause");
            }
    } while (menuInp != 6);

    return 0;
}
