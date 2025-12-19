#include "Item.h"
#include <iostream>

Item::Item(string n, string d) : name(n), desc(d) {}

string Item::getName() { return name; } // обр
string Item::getDesc() { return desc; }

// Ключ от бэкдора
KeyItem::KeyItem() : Item("Ключ от бэкдора", "Открывает скрытые пути в системе") {}
void KeyItem::use() {
    cout << "> Ключ светится. Он откроет путь, когда придет время." << endl;
}

// Вирус-дебаггер
DebugVirus::DebugVirus() : Item("Вирус-дебаггер", "Находит ошибки в коде системы") {}
void DebugVirus::use() {
    cout << "> Вирус ищет уязвимости..." << endl;
    cout << "> Найдена скрытая дверь!" << endl;
}

// Воспоминания
MemoryItem::MemoryItem() : Item("Воспоминания создателя", "Эмоции создателя игры") {}
void MemoryItem::use() {
    cout << "> Вы видите воспоминания: 'Я хотел создать рай...'" << endl;
    cout << "> 'Но забыл, как быть человеком...'" << endl;
}

// Код восстановления
RestoreCode::RestoreCode() : Item("Код восстановления", "Перезагружает систему") {}
void RestoreCode::use() {
    cout << "> Код активирован! Система начнет перезагрузку." << endl;
}

// НОВЫЕ ПРЕДМЕТЫ:

// Забытый фрагмент кода
CodeFragment::CodeFragment()
    : Item("Забытый фрагмент кода", "Древний код с неизвестным назначением") {
}
void CodeFragment::use() {
    cout << "> Фрагмент кода активируется..." << endl;
    cout << "> На экране появляется: '01001000 01000101 01001100 01010000'" << endl;
    cout << "> (В двоичном коде: HELP)" << endl;
}

// Серверный ключ
ServerKey::ServerKey()
    : Item("Серверный ключ", "Ключ доступа к системным серверам") {
}
void ServerKey::use() {
    cout << "> Ключ подходит к защитным системам серверов." << endl;
    cout << "> Теперь можно отключить защиту ядра." << endl;
}

// Системные логи
SystemLogs::SystemLogs()
    : Item("Системные логи", "Журналы работы системы") {
}
void SystemLogs::use() {
    cout << "> Читаете логи..." << endl;
    cout << "> '[ERROR] Потеряна эмоциональная матрица создателя'" << endl;
    cout << "> '[WARNING] ИИ проявляет признаки безумия'" << endl;
    cout << "> '[NOTE] Бэкдор доступен через Лес алгоритмов'" << endl;
}