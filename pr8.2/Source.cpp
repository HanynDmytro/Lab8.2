#include <iostream>
#include <string>

using namespace std;

string removeParenthesesContent(const string& input) {
    string result;
    int openParenthesesCount = 0; // ˳������� �������� �����

    // �������� �� ������� �����
    int parenthesesBalance = 0;  // ������ ����� (������ - ������)
    for (int i = 0; i < input.size(); ++i) {
        if (input[i] == '(') parenthesesBalance++;   // �������� ��� ������� �����
        if (input[i] == ')') parenthesesBalance--;   // �������� ��� ������� �����
    }

    // ���� ������ ����� �� ��������, ����� �����������, ����� �� �������
    if (parenthesesBalance != 0) {
        return input;
    }

    // ������� ������� �����
    for (int i = 0; i < input.size(); ++i) {
        if (input[i] == '(') {
            // ���� ������� ������� �����, �������� ��������
            openParenthesesCount++;
        }
        else if (input[i] == ')') {
            // ���� ������� ������� �����, �������� ��������
            if (openParenthesesCount > 0) {
                openParenthesesCount--;
            }
        }
        else if (openParenthesesCount == 0) {
            // ������ ������ �� ����������, ���� �� �� �� �������
            result += input[i];
        }
    }

    return result;
}

int main() {
    string input;
    cout << "String: ";
    getline(cin, input);

    string output = removeParenthesesContent(input);
    cout << "Result: " << output << endl;

    return 0;
}
