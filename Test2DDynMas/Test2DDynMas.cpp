// Test2DDynMas.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>



int _WIDTH = 15;   // Количество столбцов
int _HEIGHT = 30;  // Количество строк

COORD _POSITION = { 0, 0 };
HANDLE _HCONSOLE = GetStdHandle(STD_OUTPUT_HANDLE);

void gotoxy(int _x, int _y) {
    _POSITION.X = _x;
    _POSITION.Y = _y;
    SetConsoleCursorPosition(_HCONSOLE, _POSITION);
}

struct Array2D {   
    virtual void deleteMas() {};
    virtual void init() {};
    virtual void print() {};
    virtual void write() {};
protected:
    int _width = 0;
    int _height = 0;
};

struct intArray2D : Array2D {
    intArray2D(int width = 10, int height = 10) { // Конструктор
        _width = width;
        _height = height;
        _dynMas = create();
        init(0);
    }
    ~intArray2D() { // Деструктор
        deleteMas();
    }
    int** create() { // Создание двумерного динамического массива размерностью width * height типа Int
        int** my2DDynMas = new int* [_height];
        for (int i = 0; i < _height; ++i) {
            my2DDynMas[i] = new int[_width];
        }
        return my2DDynMas;
    }
    void deleteMas() { // Освобождение памяти двумерного динамического массива размерностью width * height типа Int
        for (int i = 0; i < _height; ++i) {
            delete[] _dynMas[i];
        }
        delete[] _dynMas;
    }
    void init(int value) { // Инициализация двумерного динамического массива размерностью width * height типа Int значением 0
        for (int i = 0; i < _height; ++i) {
            for (int j = 0; j < _width; ++j) {
                _dynMas[i][j] = value;
            }
        }
    }
    void print() { // Вывод в консоль двумерного динамического массива размерностью width * height типа Int
        //std::cout << std::endl;
        for (int i = 0; i < _height; ++i) {
            for (int j = 0; j < _width; ++j) {
                gotoxy(j, i);
                std::cout << _dynMas[i][j];
            }
            //std::cout << std::endl;
        }
    }
    void print(int x, int y) { // Вывод в консоль двумерного динамического массива размерностью width * height типа Int
        //std::cout << std::endl;
        for (int i = 0; i < _height; ++i) {
            for (int j = 0; j < _width; ++j) {
                gotoxy(x + j, y + i);
                std::cout << _dynMas[i][j];
            }
            //std::cout << std::endl;
        }
    }
    void write(int value, int posInHeight, int posInWidth) {
        _dynMas[posInHeight][posInWidth] = value;
    }
private:
    int** _dynMas = 0;
};

//struct charArray2D : Array2D {
//    charArray2D(int width = 10, int height = 10) { // Конструктор 
//        _width = width;
//        _height = height;
//        _dynMas = create();
//        init(0);
//    }     
//    char** create() { // Создание двумерного динамического массива размерностью width * height типа Int
//        char** my2DDynMas = new char* [_height];
//        for (int i = 0; i < _height; ++i) {
//            my2DDynMas[i] = new char[_width];
//        }
//        return my2DDynMas;
//    }
//    void deleteMas() { // Освобождение памяти двумерного динамического массива размерностью width * height типа Int
//        for (int i = 0; i < _height; ++i) {
//            delete[] _dynMas[i];
//        }
//        delete[] _dynMas;
//    }
//    void init(char value) { // Инициализация двумерного динамического массива размерностью width * height типа Int значением 0
//        for (int i = 0; i < _height; ++i) {
//            for (int j = 0; j < _width; ++j) {
//                _dynMas[i][j] = value;
//            }
//        }
//    }
//    void print() { // Вывод в консоль двумерного динамического массива размерностью width * height типа Int
//        std::cout << std::endl;
//        for (int i = 0; i < _height; ++i) {
//            for (int j = 0; j < _width; ++j) {
//                std::cout << _dynMas[i][j];
//            }
//            std::cout << std::endl;
//        }
//    }
//    void write(char value, int posInHeight, int posInWidth) {
//        _dynMas[posInHeight][posInWidth] = value;
//    }
//private:
//    char** _dynMas = 0;
//};
//struct stringArray2D : Array2D {
//    stringArray2D(int width = 10, int height = 10) { // Конструктор 
//        _width = width;
//        _height = height;
//        _dynMas = create();
//        init(0);
//    }
//    std::string** create() { // Создание двумерного динамического массива размерностью width * height типа Int
//        std::string** my2DDynMas = new std::string* [_height];
//        for (int i = 0; i < _height; ++i) {
//            my2DDynMas[i] = new std::string[_width];
//        }
//        return my2DDynMas;
//    }
//    void deleteMas() { // Освобождение памяти двумерного динамического массива размерностью width * height типа Int
//        for (int i = 0; i < _height; ++i) {
//            delete[] _dynMas[i];
//        }
//        delete[] _dynMas;
//    }
//    void init(std::string value) { // Инициализация двумерного динамического массива размерностью width * height типа Int значением 0
//        for (int i = 0; i < _height; ++i) {
//            for (int j = 0; j < _width; ++j) {
//                _dynMas[i][j] = value;
//            }
//        }
//    }
//    void print() { // Вывод в консоль двумерного динамического массива размерностью width * height типа Int
//        //std::cout << std::endl;
//        for (int i = 0; i < _height; ++i) {
//            for (int j = 0; j < _width; ++j) {
//                gotoxy(i, j);
//                std::cout << _dynMas[i][j];
//            }
//            //std::cout << std::endl;
//        }
//    }
//    void write(std::string value, int posInHeight, int posInWidth) {
//        _dynMas[posInHeight][posInWidth] = value;
//    }
//private:
//    std::string** _dynMas = 0;
//};

struct GameBoard {

    GameBoard(int height = 10, int width = 10) {
        _height = height;
        _width = width;
        Board = this->create();
    }

    intArray2D* create() {
        intArray2D* GameBoardArray = new intArray2D(_width, _height);

        for (int i = 0; i < _height; ++i) {
            for (int j = 0; j < _width; ++j) {
                if (j == 0 || j == _width - 1) {
                    GameBoardArray->write(1, i, j);
                }
                if (i == _height - 1) {
                    GameBoardArray->write(1, i, j);
                }
            }
        }
        return GameBoardArray;
    }
    void show(int x = 0, int y = 0) {
        Board->print(x, y);
    }
    void write(int value, int posInHeight, int posInWidth) {
        Board->write(value, posInHeight, posInWidth);
    }
    intArray2D* Board = 0;
private:
    int _height = 0;
    int _width = 0;
};

struct blockBox {

    blockBox(GameBoard* board, int x = 0, int y = 0) {
        _board = board;
        _x = x;
        _y = y;
    }

    void show(int _x, int _y) {
        gotoxy(_x, _y);
        std::cout << "*";
        _board->write(2, _y, _x);
        gotoxy(_x, ++_y);
        std::cout << "*";
        _board->write(2, _y, _x);
        gotoxy(++_x, _y);
        std::cout << "*";
        _board->write(2, _y, _x);
        gotoxy(_x, --_y);
        std::cout << "*";
        _board->write(2, _y, _x);
    }

private:
    int _x = 0;
    int _y = 0;
    GameBoard* _board = 0;

};

int main()
{
    
    GameBoard* myBoard = new GameBoard(_HEIGHT, _WIDTH);

    myBoard->show();

    blockBox* Box = new blockBox(myBoard);

    Box->show(5, 5);

    myBoard->show(20, 0);

    _getch();
    /*intArray2D* _myArray = new intArray2D(_WIDTH, _HEIGHT);
    
    _myArray->print();
    
    

    delete _myArray;*/

    return 0;

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
