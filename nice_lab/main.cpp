#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool fileExists(const string& filename) {   // Проверка на наличие файла по имени
    ifstream file(filename);
    return file.good();
}

int main() {
    srand(time(0)); // Инициализация генератора случайных чисел

    string files[] = {"file1.txt", "file2.txt", "file3.txt"};   // Инициализация массива с названиями файлов

    for (int i = 0; i < 3; i++) {
        if (!fileExists(files[i])) {    // Если файл не существует, создаем новый
            ofstream file(files[i]);
            if (file.is_open()) {
                for (int j = 0; j < 10; j++) {  // При успешном открытии файла записываем 10 случайных чисел
                    file << (rand() % 10 + 1) << " ";
                }
                file.close();
                cout << "Файл " << files[i] << " успешно создан!" << endl;
            } else {
                cout << "Ошибка при создании файла " << files[i] << endl;   // Если файл не открыт выдаем ошибку
            }
        } else {
            cout << "Ошибка создания - файл " << files[i] << " уже существует" << endl; // Если файл уже существует, также выдаем ошибку
        }
    }

    return 0;
}
