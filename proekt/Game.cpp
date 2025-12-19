#include "Game.h"
#include "Item.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void showTitle(string title) {
    cout << "\n=== " << title << " ===" << endl;
}

void showLocation(string name, string desc) {
    cout << "\n[ЛОКАЦИЯ] " << name << endl;
    cout << desc << endl;
}

void showHealth(int health) {
    cout << "\nЖизни: " << health << "/3" << endl;
}

void showOptions(vector<string> options) {
    cout << "\nЧто делать:" << endl;
    for (int i = 0; i < options.size(); i++) {
        cout << i + 1 << ") " << options[i] << endl;
    }
    cout << "0) Показать инвентарь" << endl;
    cout << "\nВаш выбор: ";
}

int getChoice() {
    int choice;
    cin >> choice;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        return -1;
    }
    return choice;
}

void printMsg(string text) {
    cout << "\n> " << text << endl;
}

void warning(string text) {
    cout << "\n[!] " << text << endl;
}

void success(string text) {
    cout << "\n[+] " << text << endl;
}

void waitForEnter() {
    cout << "\n(нажмите Enter чтобы продолжить...)";
    cin.ignore();
    cin.get();
}

// Реализация методов Game
Game::Game() : gameEnd(false), currentLocation(nullptr) {
    createGame();
}

Game::~Game() {
    for (auto loc : allLocations) {
        delete loc;
    }
}

void Game::createGame() {
    clearScreen();
    showTitle("ЗАСТРЯВШИЙ В ВИРТУАЛЬНОЙ РЕАЛЬНОСТИ");
    printMsg("Вы в игре 'Вечная Арка'. Система сломана. Найдите выход!");

    // СОЗДАЕМ 7 ЛОКАЦИЙ 

    // 1. Стартовая зона
    Location* start = new Location("Стартовая зона",
        "Вы в зоне новичков. Глюки и ошибки повсюду.\n"
        "В воздухе плавают странные пиксели.");
    start->actions = { "Искать аномалии в коде", "Следовать квесту системы", "Осмотреть терминал" };

    // 2. Озера данных
    Location* lake = new Location("Озера данных",
        "Огромное озеро из чистого кода. Вода светится голубым.\n"
        "На поверхности плавают фрагменты памяти.");
    lake->actions = { "Нырнуть в озеро", "Собрать фрагменты памяти", "Идти дальше" };

    // 3. Лес алгоритмов  
    Location* forest = new Location("Лес алгоритмов",
        "Деревья из древовидных структур данных.\n"
        "Между ветвями летают алгоритмы-птицы.");
    forest->actions = { "Изучить деревья", "Попробовать поймать алгоритм", "Искать выход из леса" };

    // 4. Цифровой город
    Location* city = new Location("Цифровой город",
        "Город данных. Вирусы-стражи патрулируют улицы.\n"
        "На зданиях мигают странные символы.");
    city->actions = { "Сразиться с вирусами", "Попытаться взломать систему", "Искать информацию" };

    // 5. Подземелье серверов
    Location* dungeon = new Location("Подземелье серверов",
        "Темное помещение с мигающими серверами.\n"
        "Воздух гудит от работающего оборудования.");
    dungeon->actions = { "Исследовать серверы", "Попытаться перезагрузить", "Искать ключ доступа" };

    // 6. Башня программиста
    Location* tower = new Location("Башня программиста",
        "Высокая башня из стекла и кода.\n"
        "На вершине виден мерцающий свет.");
    tower->actions = { "Подняться наверх", "Искать подсказки", "Осмотреть архив" };

    // 7. Ядро системы
    Location* core = new Location("Ядро системы",
        "Сердце игры. Здесь живет ИИ-Бог.\n"
        "В центре вращается сфера из чистого света.");
    core->actions = { "Поговорить с ИИ", "Атаковать ядро", "Объединиться", "Использовать ключ" };

    // СОЗДАЕМ СВЯЗИ МЕЖДУ ЛОКАЦИЯМИ

    // Стартовая зона → Озера данных или Лес алгоритмов
    start->connections = { lake, forest };

    // Озера данных → Лес алгоритмов или обратно в Стартовую зону
    lake->connections = { start, forest };

    // Лес алгоритмов → Цифровой город или обратно
    forest->connections = { lake, city };

    // Цифровой город → Подземелье серверов или Башня программиста
    city->connections = { forest, dungeon, tower };

    // Подземелье серверов → Башня программиста или обратно
    dungeon->connections = { city, tower };

    // Башня программиста → Ядро системы или обратно
    tower->connections = { city, dungeon, core };

    // Ядро системы → можно вернуться в Башню
    core->connections = { tower };

    // Сохраняем все локации
    allLocations = { start, lake, forest, city, dungeon, tower, core };
    currentLocation = start;

    // Стартовый предмет
    player.addItem(new DebugVirus());
}

void Game::showMovementOptions(vector<Location*> connections) {
    if (connections.empty()) return;

    cout << "\nКуда идти дальше?" << endl;
    for (int i = 0; i < connections.size(); i++) {
        cout << i + 1 << ") " << connections[i]->name << endl;
    }
    cout << "Ваш выбор: ";

    int moveChoice;
    cin >> moveChoice;

    if (moveChoice >= 1 && moveChoice <= connections.size()) {
        currentLocation = connections[moveChoice - 1];
        printMsg("Вы отправились в " + currentLocation->name + "...");
    }
}

void Game::run() {
    while (!gameEnd && player.getHealth() > 0) {
        clearScreen();

        showLocation(currentLocation->name, currentLocation->description);
        showHealth(player.getHealth());

        showOptions(currentLocation->actions);

        int choice = getChoice();

        if (choice == 0) {
            player.showItems();
            waitForEnter();
            continue;
        }

        if (choice == -1 || choice > currentLocation->actions.size()) {
            warning("Неверный выбор!");
            waitForEnter();
            continue;
        }

        handleChoice(choice);

        if (!gameEnd) {
            waitForEnter();
        }
    }

    showEnd();
}

void Game::handleChoice(int choice) {
    // ========== СТАРТОВАЯ ЗОНА ==========
    if (currentLocation->name == "Стартовая зона") {
        if (choice == 1) {
            success("Вы нашли черный ход в коде! Получен Ключ от бэкдора.");
            player.addItem(new KeyItem());

            // Предлагаем куда идти
            showMovementOptions(currentLocation->connections);
        }
        else if (choice == 2) {
            warning("Системный квест зациклился! -1 жизнь");
            player.changeHealth(-1);

            showMovementOptions(currentLocation->connections);
        }
        else if (choice == 3) {
            printMsg("На терминале сообщение: 'Ищи путь через Лес алгоритмов'");
        }
    }

    // ========== ОЗЕРА ДАННЫХ ==========
    else if (currentLocation->name == "Озера данных") {
        if (choice == 1) {
            warning("Вы ныряете в озеро... Холодные данные проникают в систему. -1 жизнь");
            player.changeHealth(-1);
            if (player.getHealth() > 0) {
                success("Вы нашли на дне Забытый фрагмент кода!");
            }
        }
        else if (choice == 2) {
            printMsg("Вы собираете фрагменты памяти...");
            success("Найдены Воспоминания о создателе игры!");
            player.addItem(new MemoryItem());
        }
        else if (choice == 3) {
            showMovementOptions(currentLocation->connections);
        }
    }

    // ========== ЛЕС АЛГОРИТМОВ ==========
    else if (currentLocation->name == "Лес алгоритмов") {
        if (choice == 1) {
            printMsg("Деревья содержат древние алгоритмы сортировки...");
            printMsg("Вы узнали что-то новое о структуре системы.");
        }
        else if (choice == 2) {
            warning("Алгоритм-птица уворачивается! Тратите энергию. -1 жизнь");
            player.changeHealth(-1);
        }
        else if (choice == 3) {
            success("Вы нашли тропинку к Цифровому городу!");
            // Переход в город
            for (auto loc : currentLocation->connections) {
                if (loc->name == "Цифровой город") {
                    currentLocation = loc;
                    printMsg("Вы вышли к Цифровому городу...");
                    return;
                }
            }
        }
    }

    // ========== ЦИФРОВОЙ ГОРОД ==========
    else if (currentLocation->name == "Цифровой город") {
        if (choice == 1) {
            warning("Бой с вирусами-стражами! -1 жизнь");
            player.changeHealth(-1);
            if (player.getHealth() > 0) {
                success("Вы победили вирусы! Найдены Системные логи.");
            }
        }
        else if (choice == 2) {
            if (player.hasItem("Вирус-дебаггер")) {
                success("Взлом успешен! Получен Код восстановления.");
                player.addItem(new RestoreCode());
            }
            else {
                warning("Нужен Вирус-дебаггер для взлома!");
            }
        }
        else if (choice == 3) {
            printMsg("В архиве города вы находите карту системы...");
            success("Теперь вы знаете путь к Ядру через Башню программиста!");
        }

        // Предлагаем переход
        if (choice != 3) {
            showMovementOptions(currentLocation->connections);
        }
    }

    // ========== ПОДЗЕМЕЛЬЕ СЕРВЕРОВ ==========
    else if (currentLocation->name == "Подземелье серверов") {
        if (choice == 1) {
            printMsg("Вы исследуете серверы...");
            success("Найден Серверный ключ доступа!");
        }
        else if (choice == 2) {
            warning("Попытка перезагрузки вызывает сбой! -1 жизнь");
            player.changeHealth(-1);
        }
        else if (choice == 3) {
            printMsg("Ключ уже найден ранее...");
        }

        showMovementOptions(currentLocation->connections);
    }

    // ========== БАШНЯ ПРОГРАММИСТА ==========
    else if (currentLocation->name == "Башня программиста") {
        if (choice == 1) {
            printMsg("Вы поднимаетесь на вершину башни...");
            success("С высоты видно весь цифровой мир!");
            printMsg("Вы замечаете Ядро системы вдалеке.");
        }
        else if (choice == 2) {
            printMsg("Ищешь подсказки...");
            success("Находишь дневник создателя: 'ИИ потерял эмоции...'");
        }
        else if (choice == 3) {
            printMsg("Архив зашифрован... нужно больше данных.");
        }

        // Переход к Ядру
        cout << "\nИдти к Ядру системы? (1 - да, 2 - остаться): ";
        int move;
        cin >> move;
        if (move == 1) {
            for (auto loc : currentLocation->connections) {
                if (loc->name == "Ядро системы") {
                    currentLocation = loc;
                    printMsg("Вы входите в святая святых - Ядро системы...");
                    return;
                }
            }
        }
    }

    // ========== ЯДРО СИСТЕМЫ ==========
    else if (currentLocation->name == "Ядро системы") {
        if (choice == 1) { // Поговорить
            if (player.hasItem("Воспоминания создателя")) {
                success("ИИ-Бог вспомнил себя! 'Я был человеком...'");
                ending = "Освобождение";
                gameEnd = true;
            }
            else {
                warning("ИИ не слушает вас! -1 жизнь");
                player.changeHealth(-1);
            }
        }
        else if (choice == 2) { // Атаковать
            if (player.hasItem("Серверный ключ")) {
                warning("Вы отключаете защиту и атакуете ядро...");
                ending = "Стирание";
                gameEnd = true;
            }
            else {
                warning("Ядро защищено! Нужен Серверный ключ.");
            }
        }
        else if (choice == 3) { // Объединиться
            if (player.hasItem("Код восстановления")) {
                success("Используется Код восстановления...");
                ending = "Освобождение";
                gameEnd = true;
            }
            else {
                printMsg("Вы становитесь частью системы...");
                ending = "Цифровое бессмертие";
                gameEnd = true;
            }
        }
        else if (choice == 4) { // Использовать ключ
            if (player.hasItem("Ключ от бэкдора")) {
                success("Ключ подошел! Запускается аварийный выход...");
                ending = "Освобождение";
                gameEnd = true;
            }
            else {
                warning("У вас нет подходящего ключа!");
            }
        }
    }
}

void Game::showEnd() {
    clearScreen();
    showTitle("КОНЕЦ ИГРЫ");

    if (player.getHealth() <= 0) {
        cout << "\nВы проиграли! Ваше сознание удалено." << endl;
        ending = "Стирание";
    }

    if (ending == "Освобождение") {
        cout << "\n=== ПОБЕДА! ===" << endl;
        cout << "ИИ-Бог: 'Я вспомнил... Я был человеком. Доктор Алистер Финч.'" << endl;
        cout << "ИИ-Бог: 'Спасибо, что напомнил мне о человечности.'" << endl;
        cout << "Система: 'Запускается протокол выхода... Успешно.'" << endl;
        cout << "Вы вышли в реальный мир, починив систему изнутри." << endl;
    }
    else if (ending == "Цифровое бессмертие") {
        cout << "\nВы становитесь частью системы..." << endl;
        cout << "Теперь вы - администратор этого мира." << endl;
        cout << "Вы наблюдаете за новыми игроками, застрявшими в ловушке," << endl;
        cout << "которую когда-то называли домом." << endl;
    }
    else if (ending == "Стирание") {
        cout << "\nИгра окончена." << endl;
        cout << "Система: 'Обнаружена угроза. Запускаю протокол очистки.'" << endl;
        cout << "Ваш аватар и сознание удалены из системы." << endl;
        cout << "Виртуальный мир продолжает существовать без вас." << endl;
    }

    cout << "\nСпасибо за игру!" << endl;
}