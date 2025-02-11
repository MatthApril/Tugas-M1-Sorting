#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <cmath>
#include <fstream>
#include <vector>
#include <ctime>
#include <string>

using namespace std;

void loadFile(vector<int> &numbers) {
    numbers.clear();
    ifstream myFile;
    string line;
    myFile.open("random.txt", ios::in);
    if (myFile.is_open()) {
        while(getline(myFile, line)) {
            numbers.push_back(stoi(line));
        }
        myFile.close();
    }
}

void saveFile(vector<int> numbers) {
    ofstream myFile;
    myFile.open("random.txt", ios::out);
    if (myFile.is_open()) {
        for (int i = 0; i < numbers.size(); i++) {
            myFile << numbers[i] << endl;
        }
        myFile.close();
    }
}

void shuffle(vector<int> &numbers) {
    for (int i = 0; i < numbers.size(); i++) {
        int j = (rand() % numbers.size() - i - 1)+ i + 1;
        int temp =  numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }
    cout << endl;
}

void bubbleSort(vector<int> numbers) {
    time_t start_time;
    time(&start_time);
    for (int i = 0; i < numbers.size(); i++) {
        for (int j = 0; j < numbers.size() - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
    time_t end_time;
    time(&end_time);

    cout << endl;
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    double duration = difftime(end_time, start_time);
    cout << "Bubble Sort took " << end_time - start_time << " seconds" << endl;
    cout << endl;

}

void twoWayBubble(vector<int> numbers) {
    time_t start_time;
    time(&start_time);
    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i; j < numbers.size() - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
        for (int j = numbers.size() - i - 2; j > i; j--) {
            if (numbers[j] < numbers[j - 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j - 1];
                numbers[j - 1] = temp;
            }
        }
    }
    time_t end_time;
    time(&end_time);

    cout << endl;
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    double duration = difftime(end_time, start_time);
    cout << "Two Way Bubble Sort took " << end_time - start_time << " seconds" << endl;
}

int main() {
    srand(time(0));
    ifstream file;
    string line;
    vector<int> numbers;
    file.open("random.txt", ios::in);
    if (file.is_open()) {
        if (!getline(file, line)) {
            for (int i = 1; i <= 100000; i++) {
                numbers.push_back(i);
            }
            saveFile(numbers);
        }
    }
    int menuInp;
    loadFile(numbers);

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
                    cout << "[ ";
                    for (int i = 0; i < numbers.size(); i++) {
                        cout << numbers[i] << " ";
                    }
                    cout << " ]" << endl;
                    shuffle(numbers);
                    saveFile(numbers);
                system("pause");
            } else if (menuInp == 2) {
                system("cls");

                system("pause");
            } else if (menuInp == 3) {
                system("cls");

                system("pause");
            } else if (menuInp == 4) {
                system("cls");
                bubbleSort(numbers);
                system("pause");
            } else if (menuInp == 5) {
                system("cls");
                twoWayBubble(numbers);
                system("pause");
            }
    } while (menuInp != 6);

    return 0;
}
