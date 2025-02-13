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

void selectSort(vector<int> numbers) {
    time_t start_time;
    time(&start_time);
    int minIndex;
    for (int i = 0; i < numbers.size(); i++){
        int mini = 1000001;
        for (int j = i + 1; j < numbers.size(); j++){
            if (mini > numbers[j]){
                mini = numbers[j];
                minIndex = j;
            }
        }
        if (mini < numbers[i]) {
            int temp = numbers[minIndex];
            numbers[minIndex] = numbers[i];
            numbers[i] = temp;
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
    cout << "Selection Sort took " << end_time - start_time << " seconds" << endl;
    cout << endl;
}

void StraightSelect(vector<int> numbers){
    time_t start_time;
    time(&start_time);

    for (int i = 0; i < numbers.size(); i++){
        for (int j = i + 1; j < numbers.size(); j++){
            if (numbers[i] > numbers[j]) {
                int temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
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
    cout << "Straight Selection Sort took " << end_time - start_time << " seconds" << endl;
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

void draw(int score, int arena[15][5]) {
    cout << "Score: " << score << endl;
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 5; j++) {
            if (arena[i][j] == 1) {
                cout << char(201);
            } else if (arena[i][j] == 2) {
                cout << char(187);
            } else if (arena[i][j] == 3) {
                cout << char(200);
            } else if (arena[i][j] == 4) {
                cout << char(188);
            } else if (arena[i][j] == 10) {
                cout << char(205) << char(205) << char(205);
            } else if (arena[i][j] == 11) {
                cout << char(186);
            } else if (arena[i][j] == 5) {
                cout << " " << char(219) << " ";
            } else {
                cout << "   ";
            }
        }
        cout << endl;
    }
}

void fill(int arena[15][5], int x) {
    arena[1][x] = 5;
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 0 && j == 0) {
                arena[i][j] = 1;
            } else if (i == 0 && j == 4) {
                arena[i][j] = 2;
            } else if (i == 14 && j == 0) {
                arena[i][j] = 3;
            } else if (i == 14 && j == 4) {
                arena[i][j] = 4;
            } else if (i == 0 || i == 14) {
                arena[i][j] = 10;
            } else if (j == 0 || j == 4) {
                arena[i][j] = 11;
            } else if (arena[i][j] != 5) {
                arena[i][j] = 0;
            }
        }
    }
}

void pianoTiles() {
    int score = 0;
    int arena[15][5];
    while (true) {
        int spawnX = rand() % 3 + 1;
        fill(arena, spawnX);
        draw(score, arena);
        for (int i = 13; i >= 1; i--) {
            for (int j = 1; j < 4; j++) {
                if (arena[i][j] == 5) {
                    arena[i][j] = 0;
                    if (i + 1 < 13) {
                        arena[i + 1][j] = 5;
                    }   
                }
            }
        }
        Sleep(1000);
        system("cls");
    }
}

int main() {
    srand(time(0));
    ifstream file;
    string line;
    vector<int> numbers;
    file.open("random.txt", ios::in);
    if (file.is_open()) {
        if (!getline(file, line)) {
            for (int i = 1; i <= 1000000; i++) {
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
             << "6. Play Games\n"
             << "7. Exit" << endl;
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
                selectSort(numbers);
                system("pause");
            } else if (menuInp == 3) {
                system("cls");
                StraightSelect(numbers);
                system("pause");
            } else if (menuInp == 4) {
                system("cls");
                bubbleSort(numbers);
                system("pause");
            } else if (menuInp == 5) {
                system("cls");
                twoWayBubble(numbers);
                system("pause");
            } else if (menuInp == 6) {
                system("cls");
                pianoTiles();
                system("pause");
            }
    } while (menuInp != 7);

    return 0;
}
