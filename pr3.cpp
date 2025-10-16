#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

void taskManager() {
    vector<int> tasks;
    int choice, taskId;
   
    do {
        cout << "\n=== Менеджер задач ===" << endl;
        cout << "1. Добавить задачу" << endl;
        cout << "2. Удалить задачу" << endl;
        cout << "3. Показать все задачи" << endl;
        cout << "4. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;
       
        switch(choice) {
            case 1:
                cout << "Введите ID новой задачи: ";
                cin >> taskId;
                tasks.push_back(taskId);
                cout << "Задача добавлена!" << endl;
                break;
               
            case 2:
                if(tasks.empty()) {
                    cout << "Список задач пуст!" << endl;
                } else {
                    cout << "Введите ID задачи для удаления: ";
                    cin >> taskId;
                    bool found = false;
                    for(int i = 0; i < tasks.size(); i++) {
                        if(tasks[i] == taskId) {
                            tasks.erase(tasks.begin() + i);
                            cout << "Задача удалена!" << endl;
                            found = true;
                            break;
                        }
                    }
                    if(!found) cout << "Задача не найдена!" << endl;
                }
                break;
               
            case 3:
                if(tasks.empty()) {
                    cout << "Список задач пуст!" << endl;
                } else {
                    cout << "Список задач: ";
                    for(int task : tasks) {
                        cout << task << " ";
                    }
                    cout << endl;
                }
                break;
        }
    } while(choice != 4);
}

void siteAnalysis() {
    int days;
    cout << "Введите количество дней: ";
    cin >> days;
   
    int* visits = new int[days];
    int total = 0;
   
    for(int i = 0; i < days; i++) {
        cout << "Посещений за день " << (i + 1) << ": ";
        cin >> visits[i];
        total += visits[i];
    }
   
    double average = (double)total / days;
    int maxVisits = visits[0], minVisits = visits[0];
    int maxDay = 1, minDay = 1;
    int lowDays = 0;
   
    for(int i = 0; i < days; i++) {
        if(visits[i] > maxVisits) {
            maxVisits = visits[i];
            maxDay = i + 1;
        }
        if(visits[i] < minVisits) {
            minVisits = visits[i];
            minDay = i + 1;
        }
        if(visits[i] < average) {
            lowDays++;
        }
    }
   
    double lowPercentage = (double)lowDays / days * 100;
   
    cout << "\n=== Результаты анализа ===" << endl;
    cout << "Общее количество посещений: " << total << endl;
    cout << "Среднее количество посещений в день: " << average << endl;
    cout << "Максимальное посещение: " << maxVisits << " (день " << maxDay << ")" << endl;
    cout << "Минимальное посещение: " << minVisits << " (день " << minDay << ")" << endl;
    cout << "Дней с низкой посещаемостью: " << lowPercentage << "%" << endl;
   
    delete[] visits;
}

string caesarCipher(string text, int shift) {
    string result = "";
   
    for(char c : text) {
        if(isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            c = (c - base + shift) % 26;
            if(c < 0) c += 26;
            result += (c + base);
        } else {
            result += c;
        }
    }
   
    return result;
}

void caesarCipherProgram() {
    string text;
    int shift;
   
    cout << "Введите текст для шифрования: ";
    cin.ignore();
    getline(cin, text);
   
    cout << "Введите сдвиг: ";
    cin >> shift;
   
    string encrypted = caesarCipher(text, shift);
    cout << "Зашифрованный текст: " << encrypted << endl;
}

void speedAnalysis() {
    const int hours = 24;
    int speed[hours];
    int limit;
   
    cout << "Введите порог разрешенной скорости: ";
    cin >> limit;
   
    cout << "Введите скорость за каждый час:" << endl;
    for(int i = 0; i < hours; i++) {
        cout << "Час " << (i + 1) << ": ";
        cin >> speed[i];
    }
   
    int totalSpeed = 0;
    int maxNormalInterval = 0, maxOverInterval = 0;
    int currentNormal = 0, currentOver = 0;
    int drivingHours = 0;
   
    for(int i = 0; i < hours; i++) {
        totalSpeed += speed[i];
       
        if(speed[i] > 0) drivingHours++;
       
        if(speed[i] <= limit) {
            currentNormal++;
            currentOver = 0;
        } else {
            currentOver++;
            currentNormal = 0;
        }
       
        if(currentNormal > maxNormalInterval) maxNormalInterval = currentNormal;
        if(currentOver > maxOverInterval) maxOverInterval = currentOver;
    }
   
    double averageSpeed = (double)totalSpeed / hours;
   
    cout << "\n=== Результаты анализа ===" << endl;
    cout << "Средняя скорость за сутки: " << averageSpeed << " км/ч" << endl;
    cout << "Максимальный интервал без превышения: " << maxNormalInterval << " часов" << endl;
    cout << "Максимальный интервал с превышением: " << maxOverInterval << " часов" << endl;
    cout << "Общее время движения: " << drivingHours << " часов" << endl;
}

void salesAnalysis() {
    const int days = 22;
    int currentMonth[days], lastYear[days];
   
    cout << "Введите продажи за текущий месяц:" << endl;
    for(int i = 0; i < days; i++) {
        cout << "День " << (i + 1) << ": ";
        cin >> currentMonth[i];
    }
   
    cout << "\nВведите продажи за аналогичный месяц прошлого года:" << endl;
    for(int i = 0; i < days; i++) {
        cout << "День " << (i + 1) << ": ";
        cin >> lastYear[i];
    }
   
    int totalSales = 0;
    vector<int> maxDays, minDays;
    vector<int> decreasePeriods;
   
    for(int i = 0; i < days; i++) {
        totalSales += currentMonth[i];
    }
   
    for(int i = 0; i < days; i++) {
        if(currentMonth[i] > 100000) maxDays.push_back(i + 1);
        if(currentMonth[i] < 10000) minDays.push_back(i + 1);
    }
   
    int currentDecrease = 1;
    for(int i = 1; i < days; i++) {
        if(currentMonth[i] < currentMonth[i - 1]) {
            currentDecrease++;
        } else {
            if(currentDecrease > 3) {
                decreasePeriods.push_back(currentDecrease);
            }
            currentDecrease = 1;
        }
    }
    if(currentDecrease > 3) {
        decreasePeriods.push_back(currentDecrease);
    }
   
    double averageSales = (double)totalSales / days;
   
    int totalCurrent = 0, totalLast = 0;
    for(int i = 0; i < days; i++) {
        totalCurrent += currentMonth[i];
        totalLast += lastYear[i];
    }
   
    int plannedSales;
    if(totalCurrent >= totalLast) {
        plannedSales = round(totalCurrent * 1.1);
    } else {
        plannedSales = round((totalCurrent + totalLast) / 2.0);
    }
   
    cout << "\n=== Анализ продаж ===" << endl;
    cout << "Средняя сумма продаж: " << averageSales << endl;
    cout << "Дни с максимальными продажами (>100000): " << maxDays.size() << " дней: ";
    for(int day : maxDays) cout << day << " ";
    cout << endl;
   
    cout << "Дни с минимальными продажами (<10000): " << minDays.size() << " дней: ";
    for(int day : minDays) cout << day << " ";
    cout << endl;
   
    cout << "Периоды уменьшения продаж (>3 дней): " << decreasePeriods.size() << " периодов" << endl;
    for(int period : decreasePeriods) {
        cout << " - " << period << " дней" << endl;
    }
   
    cout << "Планируемый объем на следующий месяц: " << plannedSales << endl;
}

int main() {
    int choice;
   
    do {
        cout << "\n=== ПРАКТИЧЕСКАЯ РАБОТА №3 ===" << endl;
        cout << "1. Менеджер задач" << endl;
        cout << "2. Анализ посещения сайта" << endl;
        cout << "3. Шифр Цезаря" << endl;
        cout << "4. Анализ скорости водителя" << endl;
        cout << "5. Анализ продаж" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите задание: ";
        cin >> choice;
       
        switch(choice) {
            case 1: taskManager(); break;
            case 2: siteAnalysis(); break;
            case 3: caesarCipherProgram(); break;
            case 4: speedAnalysis(); break;
            case 5: salesAnalysis(); break;
            case 0: cout << "Выход..." << endl; break;
            default: cout << "Неверный выбор!" << endl;
        }
    } while(choice != 0);
   
    return 0;
}
