
#include <string.h>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <iostream>
#include <vector>
using namespace std;

class Figura
{
public:
    Figura(const char* type)
    {
        int len = strlen(type) + 1;
        strcpy_s(m_type, len, type);
    }

    virtual void Show() = 0;
    virtual void Save() = 0;;
    virtual void Load() = 0;
    virtual ~Figura() {};

protected:
    char m_type[32];

};

class Square : public Figura
{
    int p_x;
    int p_y;
    int l;

public:
    Square() : Figura("Square"), p_x(0), p_y(0), l(0) {};
    Square(int a_, int b_, int l_) :Figura("Square"), p_x(a_), p_y(b_), l(l_) {};

    virtual void Show() override
    {
        cout << "\n Фигура - " << m_type << endl;
        cout << " Координата левого верхнего угла: x = " << p_x << "  y = " << p_y << endl;
        cout << " Сторона " << l << endl;
    }

    virtual void Save() override
    {
        ofstream fout;
        fout.open("Massiv.txt", ios::app);
        if (!fout.is_open())
        {
            cout << "\n Ошибка открытия файла !!!" << endl;
            return;
        }

        else
        {
            // cout << "\n Файл открыт !!!" << endl;
            fout.write((char*)&*this, sizeof(Square));
        }

        fout.close();
    }
    virtual void Load() { cout << " Load "; }
};

class Rectangle_ : public Figura
{
    int p_x;
    int p_y;
    int l;
    int w;

public:
    Rectangle_() : Figura("Rectangle"), p_x(0), p_y(0), l(0), w(0) {};
    Rectangle_(int a_, int b_, int l_, int w_) :Figura("Rectangle"), p_x(a_), p_y(b_), l(l_), w(w_) {};


    void Show() override
    {
        cout << "\n Фигура - " << m_type << endl;
        cout << " Координата левого верхнего угла: x = " << p_x << "  y = " << p_y << endl;
        cout << " Стороны " << l << " и " << w << endl;
    }

    virtual void Save() override
    {
        ofstream fout;
        fout.open("Massiv.txt", ios::app);
        if (!fout.is_open())
        {
            cout << "\n Ошибка открытия файла !!!" << endl;
            return;
        }

        else
        {
            // cout << "\n Файл открыт !!!" << endl;
            fout.write((char*)&*this, sizeof(Rectangle_));
        }

        fout.close();
    }
    virtual void Load() { cout << " Load "; }
};

class Circle : public Figura
{
    int p_x;
    int p_y;
    int r;

public:
    Circle() : Figura("Circle"), p_x(0), p_y(0), r(0) {};
    Circle(int a_, int b_, int r_) : Figura("Circle"), p_x(a_), p_y(b_), r(r_) {};

    virtual void Show() override
    {
        cout << "\n Фигура - " << m_type << endl;
        cout << " Координата центра: x = " << p_x << "  y = " << p_y << endl;
        cout << " Сторона " << r << endl;
    }

    virtual void Save() override
    {
        ofstream fout;
        fout.open("Massiv.txt", ios::app);
        if (!fout.is_open())
        {
            cout << "\n Ошибка открытия файла !!!" << endl;
            return;
        }

        else
        {
            // cout << "\n Файл открыт !!!" << endl;
            fout.write((char*)&*this, sizeof(Circle));
        }

        fout.close();
    }
    virtual void Load() { cout << " Load "; }

};

class Ellipse_ : public Figura
{
    int p_x;
    int p_y;
    int l;
    int w;

public:
    Ellipse_() : Figura("Ellipse"), p_x(0), p_y(0), l(0), w(0) {};
    Ellipse_(int a_, int b_, int l_, int w_) :Figura("Ellipse"), p_x(a_), p_y(b_), l(l_), w(w_) {};

    virtual void Show() override
    {
        cout << "\n Фигура - " << m_type << endl;
        cout << " Координата левого верхнего угла: x = " << p_x << "  y = " << p_y << endl;
        cout << " Стороны " << l << " и " << w << endl;
    }

    virtual void Save() override
    {
        ofstream fout;
        fout.open("Massiv.txt", ios::app);
        if (!fout.is_open())
        {
            cout << "\n Ошибка открытия файла !!!" << endl;
            return;
        }

        else
        {
            // cout << "\n Файл открыт !!!" << endl;
            fout.write((char*)&*this, sizeof(Ellipse_));
        }

        fout.close();
    }
    virtual void Load() { cout << " Load "; }
};


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Figura* Mas[4];

    Mas[0] = new Rectangle_(10, 15, 5, 6);
    Mas[1] = new Circle(15, 15, 10);
    Mas[2] = new Square(25, 20, 15);
    Mas[3] = new Ellipse_(20, 25, 10, 30);


    cout << "\ Отображение и сохранение в файл элементов массива: " << endl;
    for (int i = 0; i < 4; i++)
    {
        Mas[i]->Show();
        Mas[i]->Save();
        cout << endl;
    }


    cout << "\ Считывание из файла элементов массива: " << endl;
    for (int i = 0; i < 4; i++)
    {
        Mas[i]->Load();
        cout << endl;
    }
}