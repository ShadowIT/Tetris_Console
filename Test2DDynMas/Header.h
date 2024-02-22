// Ћишний код из cpp файла, не подключать к нему

#pragma once
#include <iostream>
#include <windows.h>

COORD _POSITION = { 0, 0 };
HANDLE _HCONSOLE = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_CURSOR_INFO structCursorInfo;

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

struct charArray2D : Array2D {
    charArray2D(int width = 10, int height = 10) { //  онструктор 
        _width = width;
        _height = height;
        _dynMas = create();
        init(0);
    }
    char** create() { // —оздание двумерного динамического массива размерностью width * height типа Int
        char** my2DDynMas = new char* [_height];
        for (int i = 0; i < _height; ++i) {
            my2DDynMas[i] = new char[_width];
        }
        return my2DDynMas;
    }
    void deleteMas() { // ќсвобождение пам€ти двумерного динамического массива размерностью width * height типа Int
        for (int i = 0; i < _height; ++i) {
            delete[] _dynMas[i];
        }
        delete[] _dynMas;
    }
    void init(char value) { // »нициализаци€ двумерного динамического массива размерностью width * height типа Int значением 0
        for (int i = 0; i < _height; ++i) {
            for (int j = 0; j < _width; ++j) {
                _dynMas[i][j] = value;
            }
        }
    }
    void print() { // ¬ывод в консоль двумерного динамического массива размерностью width * height типа Int
        std::cout << std::endl;
        for (int i = 0; i < _height; ++i) {
            for (int j = 0; j < _width; ++j) {
                std::cout << _dynMas[i][j];
            }
            std::cout << std::endl;
        }
    }
    void write(char value, int posInHeight, int posInWidth) {
        _dynMas[posInHeight][posInWidth] = value;
    }
private:
    char** _dynMas = 0;
};
struct stringArray2D : Array2D {
    stringArray2D(int width = 10, int height = 10) { //  онструктор 
        _width = width;
        _height = height;
        _dynMas = create();
        init(0);
    }
    std::string** create() { // —оздание двумерного динамического массива размерностью width * height типа Int
        std::string** my2DDynMas = new std::string * [_height];
        for (int i = 0; i < _height; ++i) {
            my2DDynMas[i] = new std::string[_width];
        }
        return my2DDynMas;
    }
    void deleteMas() { // ќсвобождение пам€ти двумерного динамического массива размерностью width * height типа Int
        for (int i = 0; i < _height; ++i) {
            delete[] _dynMas[i];
        }
        delete[] _dynMas;
    }
    void init(std::string value) { // »нициализаци€ двумерного динамического массива размерностью width * height типа Int значением 0
        for (int i = 0; i < _height; ++i) {
            for (int j = 0; j < _width; ++j) {
                _dynMas[i][j] = value;
            }
        }
    }
    void print() { // ¬ывод в консоль двумерного динамического массива размерностью width * height типа Int
        //std::cout << std::endl;
        for (int i = 0; i < _height; ++i) {
            for (int j = 0; j < _width; ++j) {
                gotoxy(i, j);
                std::cout << _dynMas[i][j];
            }
            //std::cout << std::endl;
        }
    }
    void write(std::string value, int posInHeight, int posInWidth) {
        _dynMas[posInHeight][posInWidth] = value;
    }
private:
    std::string** _dynMas = 0;
};
