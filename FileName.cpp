#include <iostream>
#include <string>
#include <locale>

using namespace std;

// ������� ������������� ��������� � � ������.
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

// ���������, �������� �� ������ ������� ����� ���������.
bool IsKPeriodic(const string& str)
{
    int K = findRepeatedSubstringSize(str);

    // �������� ������� ������������� ���������.
    if (K == -1)
        return false;

    int len = str.size();

    // ��������, ������� �� ����� ������ �� ����� ��������� ��� �������.
    if (len % K != 0)
        return false;

    else return true;
}

// ���������� ������� �� �������.
int main()
{
    std::setlocale(LC_ALL, "Russian");

    string str1 = "abcabcabcabc";
    cout << "������: " << str1 << endl;
    cout << "���� ��������� ������������� ���������? " << (IsKPeriodic(str1) ? "��." : "���.") << '\n' << endl;

    string str2 = "abcabcabcabr";
    cout << "������: " << str2 << endl;
    cout << "���� ��������� ������������� ���������? " << (IsKPeriodic(str2) ? "��." : "���.") << '\n' << endl;

       return 0;
}
