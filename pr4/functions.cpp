#include "functions.h"

double add(double a, double b) { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }
double divide(double a, double b) { return b != 0 ? a / b : 0; }

int bitwiseAND(int a, int b) { return a & b; }
int bitwiseOR(int a, int b) { return a | b; }
int bitwiseXOR(int a, int b) { return a ^ b; }

long long factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

double power(double base, int exp) {
    return (exp == 0) ? 1 : base * power(base, exp - 1);
}

void calculatorMenu() {
    int choice;
    double a, b;
    int x, y;
   
    do {
        cout << "\nКалькулятор" << endl;
        cout << "1. Сложение" << endl;
        cout << "2. Вычитание" << endl;
        cout << "3. Умножение" << endl;
        cout << "4. Деление" << endl;
        cout << "5. Битовое AND" << endl;
        cout << "6. Битовое OR" << endl;
        cout << "7. Битовое XOR" << endl;
        cout << "8. Факториал" << endl;
        cout << "9. Степень" << endl;
        cout << "0. Назад" << endl;
        cout << "Выберите операцию: ";
        cin >> choice;
       
        switch(choice) {
            case 1:
                cout << "Введите два числа: ";
                cin >> a >> b;
                cout << "Результат: " << add(a, b) << endl;
                break;
            case 2:
                cout << "Введите два числа: ";
                cin >> a >> b;
                cout << "Результат: " << subtract(a, b) << endl;
                break;
            case 3:
                cout << "Введите два числа: ";
                cin >> a >> b;
                cout << "Результат: " << multiply(a, b) << endl;
                break;
            case 4:
                cout << "Введите два числа: ";
                cin >> a >> b;
                if(b == 0) cout << "Ошибка: деление на ноль!" << endl;
                else cout << "Результат: " << divide(a, b) << endl;
                break;
            case 5:
                cout << "Введите два целых числа: ";
                cin >> x >> y;
                cout << "Результат: " << bitwiseAND(x, y) << endl;
                break;
            case 6:
                cout << "Введите два целых числа: ";
                cin >> x >> y;
                cout << "Результат: " << bitwiseOR(x, y) << endl;
                break;
            case 7:
                cout << "Введите два целых числа: ";
                cin >> x >> y;
                cout << "Результат: " << bitwiseXOR(x, y) << endl;
                break;
            case 8:
                cout << "Введите число: ";
                cin >> x;
                if(x < 0) cout << "Ошибка: факториал отрицательного числа!" << endl;
                else cout << "Результат: " << factorial(x) << endl;
                break;
            case 9:
                cout << "Введите основание и показатель: ";
                cin >> a >> x;
                cout << "Результат: " << power(a, x) << endl;
                break;
            case 0:
                cout << "Возврат в меню..." << endl;
                break;
            default:
                cout << "Неверный выбор!" << endl;
        }
    } while(choice != 0);
}

void nutritionTracker() {
    const int PLAN_MEALS = 5;
    double planCalories[PLAN_MEALS], actualCalories[100];
    int actualMeals;
    char choice;
   
    do {
        cout << "\nОтслеживание питания" << endl;
       
        cout << "Введите калорийность 5 плановых блюд:" << endl;
        double totalPlan = 0;
        for(int i = 0; i < PLAN_MEALS; i++) {
            cout << "Блюдо " << i+1 << ": ";
            cin >> planCalories[i];
            totalPlan += planCalories[i];
        }
       
        cout << "Введите количество фактических приемов пищи: ";
        cin >> actualMeals;
       
        double totalActual = 0;
        cout << "Введите калорийность каждого блюда:" << endl;
        for(int i = 0; i < actualMeals; i++) {
            cout << "Блюдо " << i+1 << ": ";
            cin >> actualCalories[i];
            totalActual += actualCalories[i];
        }
       
        cout << "\nРезультаты:" << endl;
        cout << "Плановые калории: " << totalPlan << endl;
        cout << "Фактические калории: " << totalActual << endl;
       
        double difference = totalActual - totalPlan;
        if(difference != 0) {
            cout << "Разница: " << abs(difference) << " калорий ("
                 << (difference > 0 ? "перебор" : "недобор") << ")" << endl;
        } else {
            cout << "Вы попали в план!" << endl;
        }
       
        if(totalActual <= totalPlan / 2) {
            cout << "Предупреждение: Потребление в 2 раза меньше плана!" << endl;
        } else if(totalActual >= totalPlan * 2) {
            cout << "Предупреждение: Потребление в 2 раза больше плана!" << endl;
        }
       
        if(actualMeals <= 2) {
            cout << "Предупреждение: Слишком мало приемов пищи (" << actualMeals << ")!" << endl;
        }
       
        cout << "\nПродолжить? (y/n): ";
        cin >> choice;
    } while(choice == 'y' || choice == 'Y');
}

void salaryAnalysis() {
    const int FIXED_EMPLOYEES = 15;
    double fixedRates[FIXED_EMPLOYEES], hourlyRates[100];
    int hourlyEmployees;
    char choice;
   
    do {
        cout << "\nАнализ зарплаты" << endl;
       
        cout << "Введите ставки " << FIXED_EMPLOYEES << " фиксированных сотрудников:" << endl;
        double totalFixed = 0, minFixed = 1e9;
        for(int i = 0; i < FIXED_EMPLOYEES; i++) {
            cout << "Сотрудник " << i+1 << ": ";
            cin >> fixedRates[i];
            totalFixed += fixedRates[i];
            if(fixedRates[i] < minFixed) minFixed = fixedRates[i];
        }
       
        cout << "Введите количество почасовых сотрудников: ";
        cin >> hourlyEmployees;
       
        double totalHourly = 0;
        cout << "Введите ставки почасовых сотрудников:" << endl;
        for(int i = 0; i < hourlyEmployees; i++) {
            cout << "Сотрудник " << i+1 << ": ";
            cin >> hourlyRates[i];
            totalHourly += hourlyRates[i] * 160;
        }
       
        double totalSalary = totalFixed + totalHourly;
        double avgSalary = totalSalary / (FIXED_EMPLOYEES + hourlyEmployees);
       
        cout << "\nРезультаты:" << endl;
        cout << "Общий фонд зарплат: " << totalSalary << endl;
        cout << "Фонд фиксированных: " << totalFixed << endl;
        cout << "Фонд почасовых: " << totalHourly << endl;
       
        if(totalFixed > totalHourly) {
            cout << "Фиксированная оплата требует больше бюджета" << endl;
        } else {
            cout << "Почасовая оплата требует больше бюджета" << endl;
        }
       
        int aboveAvg = 0;
        for(int i = 0; i < FIXED_EMPLOYEES; i++) {
            if(fixedRates[i] > avgSalary) aboveAvg++;
        }
        for(int i = 0; i < hourlyEmployees; i++) {
            if(hourlyRates[i] * 160 > avgSalary) aboveAvg++;
        }
        cout << "Сотрудников с зарплатой выше среднего: " << aboveAvg << endl;
       
        int belowMinFixed = 0;
        for(int i = 0; i < hourlyEmployees; i++) {
            if(hourlyRates[i] * 160 < minFixed) belowMinFixed++;
        }
        cout << "Почасовых сотрудников ниже минимальной фиксированной ставки: "
             << belowMinFixed << endl;
       
        cout << "\nПродолжить? (y/n): ";
        cin >> choice;
    } while(choice == 'y' || choice == 'Y');
}

void temperatureAnalysis() {
    double lastYear[31] = {10, 12, 8, 15, 11, 9, 7, 13, 14, 10,
                          6, 5, 8, 12, 11, 9, 7, 4, 3, 2,
                          1, 0, -1, 2, 4, 6, 8, 10, 12, 9, 7};
    double thisYear[31];
    int days;
    char choice;
   
    do {
        cout << "\nАнализ температуры" << endl;
       
        cout << "Введите количество дней для анализа (макс 31): ";
        cin >> days;
       
        cout << "Введите температуры за " << days << " дней текущего года:" << endl;
        double totalThis = 0, totalLast = 0;
        double maxThis = -100, minThis = 100, maxLast = -100, minLast = 100;
        int belowZeroThis = 0, belowZeroLast = 0;
       
        for(int i = 0; i < days; i++) {
            cout << "День " << i+1 << ": ";
            cin >> thisYear[i];
            totalThis += thisYear[i];
            totalLast += lastYear[i];
           
            if(thisYear[i] > maxThis) maxThis = thisYear[i];
            if(thisYear[i] < minThis) minThis = thisYear[i];
            if(lastYear[i] > maxLast) maxLast = lastYear[i];
            if(lastYear[i] < minLast) minLast = lastYear[i];
           
            if(thisYear[i] < 0) belowZeroThis++;
            if(lastYear[i] < 0) belowZeroLast++;
        }
       
        double avgThis = totalThis / days;
        double avgLast = totalLast / days;
       
        cout << "\nРезультаты:" << endl;
        cout << "Средняя температура этого года: " << avgThis << "C" << endl;
        cout << "Средняя температура прошлого года: " << avgLast << "C" << endl;
       
        if(avgThis > avgLast) {
            cout << "Этот год был теплее" << endl;
        } else if(avgThis < avgLast) {
            cout << "Прошлый год был теплее" << endl;
        } else {
            cout << "Годы были одинаково теплыми" << endl;
        }
       
        if(abs(avgThis - avgLast) > 5) {
            cout << "Высокий перепад: Разница более 5C!" << endl;
        }
       
        cout << "Максимум/минимум этого года: " << maxThis << "C / " << minThis << "C" << endl;
        cout << "Максимум/минимум прошлого года: " << maxLast << "C / " << minLast << "C" << endl;
       
        cout << "Дней ниже 0 этого года: " << belowZeroThis << endl;
        cout << "Дней ниже 0 прошлого года: " << belowZeroLast << endl;
       
        cout << "\nПродолжить? (y/n): ";
        cin >> choice;
    } while(choice == 'y' || choice == 'Y');
}

void financeAnalysis() {
    double income;
    char choice;
   
    do {
        cout << "\nАнализ финансовых расходов" << endl;
       
        cout << "Введите месячный доход семьи: ";
        cin >> income;
       
        double mandatory[7] = {5800, 6200, 4700, 10500, 5000, 3600, 23700};
        double totalMandatory = 0;
        for(double expense : mandatory) totalMandatory += expense;
       
        vector<double> unplanned;
        double expense;
        char addMore;
       
        cout << "Добавить незапланированные расходы? (y/n): ";
        cin >> addMore;
       
        while(addMore == 'y' || addMore == 'Y') {
            cout << "Введите сумму расхода: ";
            cin >> expense;
            unplanned.push_back(expense);
            cout << "Добавить еще? (y/n): ";
            cin >> addMore;
        }
       
        double totalUnplanned = 0;
        for(double exp : unplanned) totalUnplanned += exp;
       
        double avgUnplanned = unplanned.empty() ? 0 : totalUnplanned / unplanned.size();
        double balance = income - totalMandatory - totalUnplanned;
        double targetBalance = income * 0.1;
        double requiredUnplanned = income - totalMandatory - targetBalance;
       
        cout << "\nРезультаты:" << endl;
        cout << "Обязательные расходы: " << totalMandatory << endl;
        cout << "Незапланированные расходы: " << totalUnplanned << endl;
       
        if(totalUnplanned > totalMandatory) {
            double percent = ((avgUnplanned - totalMandatory) / totalMandatory) * 100;
            cout << "Незапланированные расходы превысили обязательные на "
                 << percent << "%" << endl;
        }
       
        cout << "Остаток на счету: " << balance << endl;
       
        if(balance < targetBalance) {
            cout << "Для сохранения 10% дохода нужно сократить незапланированные расходы" << endl;
        } else {
            cout << "На счету осталось более 10% дохода" << endl;
        }
       
        cout << "\nПродолжить с новыми данными? (y/n): ";
        cin >> choice;
    } while(choice == 'y' || choice == 'Y');
}

void mainMenu() {
    int choice;
   
    do {
        cout << "\nГлавное меню:" << endl;
        cout << "1. Калькулятор" << endl;
        cout << "2. Отслеживание питания" << endl;
        cout << "3. Анализ зарплаты" << endl;
        cout << "4. Анализ температуры" << endl;
        cout << "5. Анализ финансов" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите задание: ";
        cin >> choice;
       
        switch(choice) {
            case 1: calculatorMenu(); break;
            case 2: nutritionTracker(); break;
            case 3: salaryAnalysis(); break;
            case 4: temperatureAnalysis(); break;
            case 5: financeAnalysis(); break;
            case 0: break;
            default: cout << "Неверный выбор!" << endl;
        }
    } while(choice != 0);
}
