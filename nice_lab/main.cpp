#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool fileExists(const string& filename) {   // �������� �� ������� ����� �� �����
    ifstream file(filename);
    return file.good();
}

int main() {
    srand(time(0)); // ������������� ���������� ��������� �����

    string files[] = {"file1.txt", "file2.txt", "file3.txt"};   // ������������� ������� � ���������� ������

    for (int i = 0; i < 3; i++) {
        if (!fileExists(files[i])) {    // ���� ���� �� ����������, ������� �����
            ofstream file(files[i]);
            if (file.is_open()) {
                for (int j = 0; j < 10; j++) {  // ��� �������� �������� ����� ���������� 10 ��������� �����
                    file << (rand() % 10 + 1) << " ";
                }
                file.close();
                cout << "���� " << files[i] << " ������� ������!" << endl;
            } else {
                cout << "������ ��� �������� ����� " << files[i] << endl;   // ���� ���� �� ������ ������ ������
            }
        } else {
            cout << "������ �������� - ���� " << files[i] << " ��� ����������" << endl; // ���� ���� ��� ����������, ����� ������ ������
        }
    }

    return 0;
}
