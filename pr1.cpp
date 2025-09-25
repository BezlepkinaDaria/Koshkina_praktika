#include <iostream>
using namespace std;

int main() {
    float num1, num2, num3, srznach;
    cout << "Введите 3 значения: " << endl;
    cin >> num1 >> num2 >> num3;
    float *ptr1 = &num1, *ptr2 = &num2, *ptr3 = &num3;
    srznach = (*ptr1 + *ptr2 + *ptr3)/ 3;
    cout << "Среднее арифметическое: " << srznach << endl;
    
    
    float numb1, numb2;
    cout << "Введите 2 числа: ";
    cin >> numb1 >> numb2;
    float *ptr = &numb1;
    float &ref = numb1;
    *ptr *= 1.3;
    ref *= 0.7;
    cout << "Значение numb1 через указатель: " << *ptr << endl;
    cout << "Значение numb2 через ссылку: " << numb2 << endl;
    
    
    int num4, num5;
    cout << "Введите 2 целых числа: ";
    cin >> num4 >> num5;
    num4 = num4 ^ num5;
    num5 = num4 ^ num5;
    num4 = num4 ^ num5;
    cout << "После обмена: num4 = " << num4 << ", num5 = " << num5 << endl;
    
    
    int num, n;
    cout << "Введите число: ";
    cin >> num;
    cout << "Введите степень n: ";
    cin >> n;
    int result = num << n;
    cout << "Результат умножения на 2^" << n << ": " << result << endl;
    
    
    int a, step;
    cout << "Введите число: ";
    cin >> a;
    cout << "Введите степень n: ";
    cin >> step;
    int resultat = a >> step;
    cout << "Результат деления на 2^" << step << ": " << resultat << endl;
    
    
    char char1, char2;
    cout << "Введите 2 значения: ";
    cin >> char1 >> char2;
    char &ref1 = char1;
    ref1 = char2;
    cout << "Значение char1 после изменения: " << char1 << endl;
    
    
    char char3, char4;
    cout << "Введите 2 значения: ";
    cin >> char3 >> char4;
    char *ptr5= &char3;
    *ptr5 = char4;
    cout << "Значение char3 после изменения: " << *ptr5 << endl;
    
    
    int chislo;
    cout << "Введите число: ";
    cin >> chislo;
    bool power = (chislo > 0) && ((chislo & (chislo - 1)) == 0);
    cout << "Является ли число степенью двойки: " << boolalpha << power << endl;
    
    
    int chislo1;
    cout << "Введите число: ";
    cin >> chislo1;
    bool chetn = (chislo1 & 1) == 0;
    cout << "Является ли число четным: " << boolalpha << chetn << endl;
    
    
    
    
    int l, m;

    cout << "Введите два числа: ";
    cin >> l >> m;

    cout << "Сумма: " << l + m << endl;
    cout << "Разность: " << l - m << endl;
    cout << "Умножение: " << l * m << endl;

    if (m != 0) {
        cout << "Деление: " << static_cast<double>(l) / m << endl;
        cout << "Остаток: " << l % m << endl;
    } else {
        cout << "Деление на ноль недопустимо." << endl;
    }

    cout << "Битовое И: " << (l & m) << endl;
    cout << "Битовое ИЛИ: " << (l | m) << endl;
    cout << "Битовый XOR: " << (l ^ m) << endl;

    int *ptr7 = &l;
    int *ptr8 = &m;

    cout << "Адрес l: " << static_cast<void*>(ptr7) << endl;
    cout << "Адрес m: " << static_cast<void*>(ptr8) << endl;

    cout << "Инкремент l: " << ++l << " (l теперь = " << l << ")" << endl;
    cout << "Декремент m: " << --m << " (m теперь = " << m << ")" << endl;
    return 0;
    
}
