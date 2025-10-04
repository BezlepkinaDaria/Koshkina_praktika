int main() {
    // Задание 1: Посетитель на фестивале
    int age, ticket_type;
        while (true) {
        cout << "Введите возраст: ";
        cin >> age;
        if (age == 0) break;
        cout << "Тип билета (1-обычный, 2-детский, 3-пенсионный, 4-VIP): ";
        cin >> ticket_type;
        if (age < 5) cout << "Вход запрещен: маленький возраст";
        else if (age >= 5 && age <= 12 && ticket_type == 2) cout << "Вход разрешен (детский билет)";
        else if (age >= 13 && age <= 49 && (ticket_type == 1 || ticket_type == 4)) cout << "Вход разрешен (обычный/VIP)";
        else if (age >= 50 && age <= 64 && ticket_type != 2) cout << "Вход разрешен (кроме детского)";
        else if (age >= 65 && (ticket_type == 3 || ticket_type == 4)) cout << "Вход разрешен (пенсионный/VIP)";
        else cout << "Вход запрещен: неверный тип билета";
     break;  
    }
    // Задание 2: Система учета результатов тестирования
    while (true) {
        int main_score, extra_tasks, bonus;
        cout << "Балл за тест (0-100, -1 для выхода): ";
        cin >> main_score;
        if (main_score == -1) break;
        cout << "Доп. задания: ";
        cin >> extra_tasks;
        cout << "Бонус (1-да, 0-нет): ";
        cin >> bonus;

        int total_score = main_score + (extra_tasks * 3);
        if (bonus == 1) total_score += 15;
        total_score = min(total_score, 100);

        string grade;
        if (total_score >= 90) grade = "Отлично";
        else if (total_score >= 75) grade = "Хорошо";
        else if (total_score >= 60) grade = "Удовлетворительно";
        else grade = "Неудовлетворительно";

        cout << "Итоговая оценка: " << grade << endl << endl;
    break;
    }
    // Задание 3: Напиток в кофейне
    while (true) {
        int choice;
        cout << "Выберите напиток (0 - выход):\n1. Эспрессо (100 руб)\n2. Капучино (150 руб)\n3. Латте (180 руб)\n4. Чай (80 руб)\n5. Шоколад (120 руб)\nВаш выбор: ";
        cin >> choice;
        if (choice == 0) break;

        double price = 0.0;
        string drink_name;
        switch (choice) {
            case 1: price = 100; drink_name = "Эспрессо"; break;
            case 2: price = 150; drink_name = "Капучино"; break;
            case 3: price = 180; drink_name = "Латте"; break;
            case 4: price = 80;  drink_name = "Чай"; break;
            case 5: price = 120; drink_name = "Шоколад"; break;
            default: cout << "Неверный выбор.\n"; continue;
        }

        cout << "Выберите размер (1-S, 2-M +30%, 3-L +50%): ";
        cin >> choice;
        double size_multiplier = 1.0;
        string size_name;
        switch (choice) {
            case 1: size_multiplier = 1.0;  size_name = "S"; break;
            case 2: size_multiplier = 1.3;  size_name = "M"; break;
            case 3: size_multiplier = 1.5;  size_name = "L"; break;
            default: cout << "Неверный выбор размера.\n"; continue;
        }

        cout << "Выберите добавку (1-нет, 2-молоко +10, 3-сироп +15, 4-сливки +20): ";
        cin >> choice;
        double add_price = 0.0;
        string add_name;
        switch (choice) {
            case 1: add_price = 0;    add_name = "Нет"; break;
            case 2: add_price = 10;   add_name = "Молоко"; break;
            case 3: add_price = 15;   add_name = "Сироп"; break;
            case 4: add_price = 20;   add_name = "Сливки"; break;
            default: cout << "Неверный выбор добавки.\n"; continue;
        }

        double total_price = price * size_multiplier + add_price;
        cout << "Заказ: " << drink_name << ", " << size_name << ", " << add_name << "\nИтого: " << fixed << setprecision(2) << total_price << " руб.\n" << endl;
    break;
    }
    // Задание 4: Покупка товаров в магазине
    cout << "=== Задание 4: Покупка товаров в магазине ===" << endl;
    int num_items;
    double price, total_price = 0.0;
    bool loyalty_card;
    cout << "Введите количество товаров: ";
    cin >> num_items;
    for (int i = 0; i < num_items; ++i) {
        cout << "Цена товара " << (i + 1) << ": ";
        cin >> price;
        total_price += price;
    }
    double original_price = total_price;
    if (total_price > 5000) total_price *= 0.90;
    cout << "Есть карта лояльности? (1-да, 0-нет): ";
    cin >> loyalty_card;
    if (loyalty_card) total_price *= 0.95;

    double amount_paid, change;
    cout << "Сумма к оплате: " << fixed << setprecision(2) << total_price << " руб.\nВнесено: ";
    cin >> amount_paid;
    change = amount_paid - total_price;

    cout << "\n=== Чек ===\nСумма без скидок: " << fixed << setprecision(2) << original_price << " руб.\nСумма к оплате: " << fixed << setprecision(2) << total_price << " руб.\nСдача: " << fixed << setprecision(2) << change << " руб.\n=========\n" << endl;
    // Задание 5: Игра "Угадай число"
    srand(time(0));
    int secret_number = rand() % 20 + 1;
    int guess, attempts = 0;
    cout << "Я загадал число от 1 до 20. Угадайте!" << endl;
    while (true) {
        cout << "Ваша попытка: ";
        cin >> guess;
        attempts++;
        if (guess < 1 || guess > 20) {
            cout << "Ошибка! Введите число от 1 до 20.\n";
            continue;
        }
        if (guess == secret_number) {
            cout << "Поздравляю, вы угадали!\nПопыток: " << attempts << endl;
            break;
        } else if (guess < secret_number) cout << "Слишком мало!\n";
        else cout << "Слишком много!\n";
        break;
    }
    return 0;
}
