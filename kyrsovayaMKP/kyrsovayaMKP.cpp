#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node* p;
};

class Stack {
private:
    Node* top; // указатель на верхний элемент стека

public:
    // Конструктор по умолчанию
    Stack() {
        top = nullptr;
    }

    // Деструктор
    ~Stack() {
        // Освобождаем память, занятую элементами стека
        while (top != nullptr) {
            Node* temp = top;
            top = top->p;
            delete temp;
        }
    }

    // Функция, которая проверяет, пуст ли стек
    bool isEmpty() {
        return top == nullptr;
    }

    // Функция, которая проверяет, полон ли стек
    bool isFull() {
        // В данном примере стек не будет заполняться, поэтому всегда возвращает false
        return false;
    }

    // Функция, которая добавляет элемент в стек
    void push(int value) {
        Node* newNode = new Node; // создание нового узла
        newNode->key = value;
        newNode->p = top; // новый элемент будет ссылаться на предыдущий верхний элемент
        top = newNode; // новый элемент становится верхним
    }

    // Функция, которая удаляет элемент из стека и выводит его на экран
    void pop() {
        if (isEmpty()) {
            cout << "stack is empty" << endl;
        }
        else {
            Node* temp = top;
            top = top->p; // переназначаем верхний элемент
            cout << "Popped element: " << temp->key << endl;
            delete temp; // освобождаем память, занятую удаленным элементом
        }
    }

    // Функция, которая удаляет все элементы стека
    void remove() {
        while (!isEmpty()) {
            pop();
        }
    }

    // Функция, которая выводит информацию о длине стека
    void length() {
        int count = 0;
        Node* temp = top;
        while (temp != nullptr) {
            count++;
            temp = temp->p;
        }
        cout << "Stack length: " << count << endl;
    }

    // Функция, которая выводит стек в терминал
    void print() {
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->key << " ";
            temp = temp->p;
        }
        cout << endl;
    }
};

int main() {
    Stack myStack;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    myStack.print(); // Вывод: 3 2 1

    myStack.pop(); // Вывод: Popped element: 3

    myStack.length(); // Вывод: Stack length: 2

    myStack.remove(); // Вывод: Popped element: 2  Popped element: 1


}