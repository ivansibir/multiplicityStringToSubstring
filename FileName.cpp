#include <iostream>
#include <string>
#include <locale>

using namespace std;

// Находим повторяющуюся подстроку и её размер.
int findRepeatedSubstringSize(const string& str)
{
    int len = str.size();
    for (int i = 1; i <= len / 2; i++)
    {
        if (len % i == 0)
        {
            bool isRepeated = true;
            for (int j = i; j < len; j++)
            {
                if (str[j] != str[j % i])
                {
                    isRepeated = false;
                    break;
                }
            }
            if (isRepeated)
            {
                return i;
            }
        }
    }
    return -1;
}

// Проверяем, является ли строка кратной числу подстроке.
bool IsKPeriodic(const string& str)
{
    int K = findRepeatedSubstringSize(str);

    // Проверка наличия повторяющейся подстроки.
    if (K == -1)
        return false;

    int len = str.size();

    // Проверка, делится ли длина строки на длину подстроки без остатка.
    if (len % K != 0)
        return false;

    else return true;
}

// Реализация функций на примере.
int main()
{
    std::setlocale(LC_ALL, "Russian");

    string str1 = "abcabcabcabc";
    cout << "Строка: " << str1 << endl;
    cout << "Есть кратность повторяющейся подстроке? " << (IsKPeriodic(str1) ? "Да." : "Нет.") << '\n' << endl;

    string str2 = "abcabcabcabr";
    cout << "Строка: " << str2 << endl;
    cout << "Есть кратность повторяющейся подстроке? " << (IsKPeriodic(str2) ? "Да." : "Нет.") << '\n' << endl;

       return 0;
}
