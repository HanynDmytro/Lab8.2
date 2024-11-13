#include <iostream>
#include <string>

using namespace std;

string removeParenthesesContent(const string& input) {
    string result;
    int openParenthesesCount = 0; // Лічильник відкритих дужок

    // Перевірка на парність дужок
    int parenthesesBalance = 0;  // Баланс дужок (відкриті - закриті)
    for (int i = 0; i < input.size(); ++i) {
        if (input[i] == '(') parenthesesBalance++;   // Збільшуємо для відкритої дужки
        if (input[i] == ')') parenthesesBalance--;   // Зменшуємо для закритої дужки
    }

    // Якщо баланс дужок не нульовий, рядок некоректний, нічого не змінюємо
    if (parenthesesBalance != 0) {
        return input;
    }

    // Основна обробка рядка
    for (int i = 0; i < input.size(); ++i) {
        if (input[i] == '(') {
            // Якщо зустріли відкриту дужку, збільшуємо лічильник
            openParenthesesCount++;
        }
        else if (input[i] == ')') {
            // Якщо зустріли закриту дужку, зменшуємо лічильник
            if (openParenthesesCount > 0) {
                openParenthesesCount--;
            }
        }
        else if (openParenthesesCount == 0) {
            // Додаємо символ до результату, якщо він не між дужками
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
