#include <iostream>
#include <cstdlib>
#include <windows.h>

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

        switch (menuInp) {
            case 1:
                system("cls");

                system("pause");
                break;
            case 2:
                system("cls");

                system("pause");
                break;
            case 3:
                system("cls");

                system("pause");
                break;
            case 4:
                system("cls");
                int arr[] = {10, 5, 7, 1, 3, 100};
                int n = sizeof(arr)/sizeof(int);
                cout << n << endl;
                for (int i = 0; i < n / 2 + 1; i++) {
                    for (int j = 0; j < n - i - 1; j++) {
                        if (arr[j] > arr[j + 1]) {
                            int temp = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j + 1] = temp;
                        }
                    }
                }

                for (int i = 0; i < n; i++) {
                    cout << arr[i] << " ";
                }
                system("pause");
                break;
            case 5:
                system("cls");

                system("pause");
                break;
        }
    } while (menuInp != 6);

    return 0;
}
