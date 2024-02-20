// Test2DDynMas.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

// Сделать случайный выбор спавнившийся фигуры

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>



int _WIDTH = 16;   // Количество столбцов
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
    void print(int x = 0, int y = 0) { // Вывод в консоль двумерного динамического массива размерностью width * height типа Int
        //std::cout << std::endl;
        for (int i = 0; i < _height; ++i) {
            for (int j = 0; j < _width; ++j) {
                gotoxy(j, i);
                if (_dynMas[i][j] == 0) {
                    std::cout << " ";
                }
                else if (_dynMas[i][j] == 2) {
                    std::cout << "*";
                }
                else {
                    std::cout << _dynMas[i][j];
                }
            }
            //std::cout << std::endl;
        }
    }
    void printDebug(int x = 0, int y = 0) { // Вывод в консоль двумерного динамического массива размерностью width * height типа Int
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
    int get(int posInHeight, int posInWidth) {
        return _dynMas[posInHeight][posInWidth];
    }
    int _x = 0;
    int _y = 0;
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
        _x = x;
        _y = y;
        Board->print(x, y);
    }
    void showDebug(int x = 0, int y = 0) { // Для отладки
        Board->printDebug(x, y);
    }
    void write(int value, int posInHeight, int posInWidth) {
        Board->write(value, posInHeight, posInWidth);
    }
    int get(int posInHeight, int posInWidth) {
        return Board->get(posInHeight, posInWidth);
    }
    void deleteLine(int line) {
        for (int i = 1; i < _WIDTH - 1; ++i) {
            this->write(0, line, i);
        }
    }
    const int getHeight() {
        return _height;
    }
    const int getWidth() {
        return _width;
    }
    int getx() {
        return _x;
    }
    int gety() {
        return _y;
    }
    
    intArray2D* Board = 0;
private:
    int _x = 0;
    int _y = 0;
    int _height = 0;
    int _width = 0;
};

struct Block {

    virtual void show() {}
    virtual void hide() {}
    virtual void moveLeft() {}
    virtual void moveRight() {}
    virtual void moveDown() {}
    virtual void spawn() {}
    virtual bool isDownConflict() { }

};

struct blockBox : Block {
    blockBox(GameBoard* board, int x = 5, int y = 0) {
        _board = board;
        _x = x;
        _y = y;
    }
    void show() {
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
        --_x;
    }
    void hide() {
        gotoxy(_x, _y);
        std::cout << " ";
        _board->write(0, _y, _x);
        gotoxy(_x, ++_y);
        std::cout << " ";
        _board->write(0, _y, _x);
        gotoxy(++_x, _y);
        std::cout << " ";
        _board->write(0, _y, _x);
        gotoxy(_x, --_y);
        std::cout << " ";
        _board->write(0, _y, _x);
        --_x;
    }

    void moveLeft() {
        if (!isLeftConflict()) {
            this->hide();
            --_x;
            this->show();
        }
    }
    void moveRight() {
        if (!isRightConflict()) {
            this->hide();
            ++_x;
            this->show();
        }
    }
    void moveDown() {
        if (!isDownConflict()) {
            this->hide();
            ++_y;
            this->show();
        }
    }

    bool isLeftConflict() {
        if (_x == _board->getx() + 1) {
            return true;
        }
        return false;
    }
    bool isRightConflict() {
        if (_x == _board->getx() + _WIDTH - 3) {
            return true;
        }
        return false;
    }
    bool isDownConflict() { // Проверка границ
        /*if (_y == _board->gety() + _HEIGHT - 3) {*/
        if(_board->get(this->gety() + 2, this->getx()) == 1 ||      // Надо оптимизировать // Проверка границ поля
            _board->get(this->gety() + 2, this->getx() + 1) == 2 || // Проверка столкновения с
            _board->get(this->gety() + 2, this->getx()) == 2) {     // другими фигурами
            this->spawn(); // Сброс новой фигуры
            return true;
        }
        return false;
    }
    int getx() {
        return _x;
    }
    int gety() {
        return _y;
    }
    void spawn() {
        this->checkLines();
        _x = 5;
        _y = 0;
        this->show();
    }

    void checkLines() {
        int d = 0;
        //std::cout << "C: " << _board->get(_HEIGHT - 2, _WIDTH - 2);
        for (int i = 1; i < _HEIGHT; ++i) {
            d = 0;
            for (int j = 1; j < _WIDTH; ++j) {
                if (_board->get(i, j) == 2) {
                    ++d;
                    if (d == 14) {
                        _board->deleteLine(i);
                    }
                    /*gotoxy(40, 5);
                    std::cout << "Counter: " << d;*/
                }

            }
        }
    }

private:
    int _x = 0;
    int _y = 0;
    GameBoard* _board = 0;

};

struct blockStick : Block {
    blockStick(GameBoard* board, int x = 5, int y = 0) {
        _board = board;
        _x = x;
        _y = y;
    }
    void show() {
        //for (int i = 0; i < 4; ++i) {

        //    gotoxy(_x, _y + i);
        //    //std::cout << "*";
        //    _board->write(2, _y + 1, _x);

        //}
        gotoxy(_x, ++_y);
        _board->write(2, _y, _x);
        gotoxy(_x, ++_y);
        _board->write(2, _y, _x);
        gotoxy(_x, ++_y);
        _board->write(2, _y, _x);
        _y -= 3;
    }
    void hide() {
        //for (int i = 0; i < 4; ++i) {

        //    gotoxy(_x, _y = +i);
        //    //std::cout << " ";
        //    _board->write(0, _y, _x);

        //}
        gotoxy(_x, ++_y);
        _board->write(0, _y, _x);
        gotoxy(_x, ++_y);
        _board->write(0, _y, _x);
        gotoxy(_x, ++_y);
        _board->write(0, _y, _x);
        _y -= 3;
    }

    void moveLeft() {
        if (!isLeftConflict()) {
            this->hide();
            --_x;
            this->show();
        }
    }
    void moveRight() {
        if (!isRightConflict()) {
            this->hide();
            ++_x;
            this->show();
        }
    }
    void moveDown() {
        if (!isDownConflict()) {
            this->hide();
            ++_y;
            this->show();
        }
    }

    bool isLeftConflict() {
        if (_x == _board->getx() + 1) {
            return true;
        }
        return false;
    }
    bool isRightConflict() {
        if (_x == _board->getx() + _WIDTH - 2) {
            return true;
        }
        return false;
    }
    bool isDownConflict() { // Проверка границ
        int r = 0;
        /*if (_y == _board->gety() + _HEIGHT - 3) {*/
        if (_board->get(this->gety() + 4, this->getx()) == 1 ||      // Надо оптимизировать // Проверка границ поля
                                                                     // Проверка столкновения с
            _board->get(this->gety() + 4, this->getx()) == 2) { 
            // другими фигурами
            this->spawn(); // Сброс новой фигуры
            return true;
        }
        return false;
    }
    int getx() {
        return _x;
    }
    int gety() {
        return _y;
    }
    void spawn() {
        this->checkLines();
        _x = 5;
        _y = 0;
        this->show();
    }

    void checkLines() {
        int d = 0;
        //std::cout << "C: " << _board->get(_HEIGHT - 2, _WIDTH - 2);
        for (int i = 1; i < _HEIGHT; ++i) {
            d = 0;
            for (int j = 1; j < _WIDTH; ++j) {
                if (_board->get(i, j) == 2) {
                    ++d;
                    if (d == 14) {
                        _board->deleteLine(i);
                    }
                    /*gotoxy(40, 5);
                    std::cout << "Counter: " << d;*/
                }

            }
        }
    }

    

private:
    int _x = 0;
    int _y = 0;
    GameBoard* _board = 0;

};

Block* randomFigure(Block* box, Block* stick) {

    int start = 0;
    int end = 1;

    int r = rand() % (end - start + 1) + start;

    switch (r)
    {
    case 0:
        return box;
        break;
    case 1:
        return stick;
        break;
    default:
        break;
    }

}

int main()
{
    
    GameBoard* myBoard = new GameBoard(_HEIGHT, _WIDTH);

    myBoard->show();

    Block* Box = new blockBox(myBoard);

    Block* Stick = new blockStick(myBoard);

    //Box->show();

    //Stick->show();

    myBoard->showDebug(20, 0);

    Block* Fig = 0;

    //_getch();

    //Box->hide();

    //Stick->hide();

    myBoard->showDebug(20, 0);

    int key = 0;

    Fig = randomFigure(Box, Stick);

    while (true) {
        while (!_kbhit())
        {
            //Box->moveDown();
            //Stick->moveDown();
            Fig->moveDown();
            myBoard->show();
            myBoard->showDebug(20, 0);
            Sleep(100);
        }
        key = _getch();
        //gotoxy(35, 20);
        //std::cout << key;
        switch (key)
        {
        case 72:
            break;
        case 80:
            //Box->moveDown();
            //Stick->moveDown();
            if (Fig->isDownConflict()) {
                Fig = randomFigure(Box, Stick);
                Fig->spawn();
            }
            Fig->moveDown();
            myBoard->show();
            myBoard->showDebug(20, 0);
            break;
        case 75: 
            //Box->moveLeft();
            //Stick->moveLeft();
            Fig->moveLeft();
            myBoard->show();
            myBoard->showDebug(20, 0);
            break;
        case 77:
            //Box->moveRight();
            //Stick->moveRight();
            Fig->moveRight();
            myBoard->show();
            myBoard->showDebug(20, 0);
            break;
        default:
            break;
        }
    }

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
