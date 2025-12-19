#pragma once
#include <string>
#include <iostream>
using namespace std;

class Item {
protected:
    string name;
    string desc;
public:
    Item(string n, string d);
    string getName();
    string getDesc();
    virtual void use() = 0;
    virtual ~Item() {}
};

class KeyItem : public Item {
public:
    KeyItem();
    void use() override;
};

class DebugVirus : public Item {
public:
    DebugVirus();
    void use() override;
};

class MemoryItem : public Item {
public:
    MemoryItem();
    void use() override;
};

class RestoreCode : public Item {
public:
    RestoreCode();
    void use() override;
};

class CodeFragment : public Item {
public:
    CodeFragment();
    void use() override;
};

class ServerKey : public Item {
public:
    ServerKey();
    void use() override;
};

class SystemLogs : public Item {
public:
    SystemLogs();
    void use() override;
};