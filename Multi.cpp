// Multi.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <list>
#include <ctime>
#include <set>
using namespace std;
struct MassP
{
    long* Point;
    int Value;
};
bool Comparer(MassP a, MassP b)
{
    return (a.Point[0] < b.Point[0])? 1: (a.Point[0] == b.Point[0]) ? (a.Point[1] < b.Point[1]) : 0;
}
class Matr
{
    public: list<struct MassP> Type;
    public: Matr()
    {
        set<long int> Row;
        set<long int> Line;
        Type = list<struct MassP>();
        int HowMany = rand() % 1000;
        for (int i = 0; i < HowMany + 2000; i++)
        {
            long line = rand() % 100000 * (rand() % 100);
            long row = rand() % 100000 * (rand() % 100);
            while (Line.count(line)&&Row.count(row))
            {
                line = rand() % 100000 * (rand() % 100);
                row = rand() % 100000 * (rand() % 100);
            }
            Line.insert(line);
            Row.insert(row);
            struct MassP Input;
            Input.Point = new long[2] {line,row};
            Input.Value = 1;
            Type.push_back(Input);
        }
    }
    public: Matr(int)
    {
        Type = list<struct MassP>();
        return;
    }
    public:void Sort()
    {
        Type.sort(Comparer);
    }
    public:void Reverse()
    {
        list<struct MassP>::iterator it = Type.begin();
        for (int i = 0; i < Type.size(); i++)
        {
            long buff;
            buff = it->Point[0];
            it->Point[0] = it->Point[1];
            it->Point[1] = buff;
            it++;
        }
        Sort();
    }
    public:void Add(struct MassP a) 
    {
        Type.push_back(a);
    }
    public:void Show()
    {
        list<struct MassP>::iterator it = Type.begin();
        for(int i=0;i<Type.size();i++)
        {
            cout << it->Point[0] << "\t" << it->Point[1] << "\t" << it->Value << endl;
            it++;
        }
    }
    Matr operator*(Matr OtherMatr)
    {
        Matr Out = Matr(0);
        OtherMatr.Reverse(); 
        list<struct MassP>::iterator it = Type.begin();
        list<struct MassP>::iterator buff;
        list<struct MassP>::iterator Endp=Type.end();
        for (int i = 0; i < Type.size(); i++)
        {    
            int Summ = 0;
            buff = it;
            list<struct MassP>::iterator Other = OtherMatr.Type.begin();
            int prev = Other->Point[0];
            for (int j = 0; j < OtherMatr.Type.size(); j++, Other++)
            {
                if (prev!= Other->Point[0])
                {
                    if (Summ > 0)
                    {
                        long* Help = new long[2]{ it->Point[0], prev };
                        struct MassP A { Help, Summ };
                        Out.Add(A);
                        Summ = 0;
                    }
                }
                if (Other->Point[1] == it->Point[1]) Summ += Other->Value * it->Value;
                if (it != Endp)
                {
                    buff = it;
                    buff++;
                    if (buff != Endp)
                        while (it->Point[0] == buff->Point[0])
                        {
                            if (Other->Point[1] == buff->Point[1]) Summ += Other->Value * buff->Value;
                            if (buff == Endp)break;
                            buff++;
                        }
                }
                prev = Other->Point[0];
                if (i == Type.size()-1)
                {
                    if (Summ > 0)
                    {
                        long* Help = new long[2]{ it->Point[0], prev };
                        struct MassP A { Help, Summ };
                        Out.Add(A);
                        Summ = 0;
                    }
                }
            }
            buff = it;
            int Add = 0;
            if (it != Endp)
            while (it->Point[0] == buff->Point[0])
            {
                Add++;
                it++;
                if (it == Endp)
                {
                    break;
                }
            }
            i += Add - 1;
        }
        Out.Sort();
        return Out;
    }
};


int main()
{
    srand(time(NULL));
    Matr Newbie=Matr();
    //long* Help = new long[2]{ 0,4 };
    //MassP aim{ Help, 1 };
    //Newbie.Add(aim);
    Newbie.Sort();
    std::cout << "\n";
    Matr Newxt = Matr();
    //long* Help2 = new long[2]{ 4,0 };
    //long* Help3 = new long[2]{ 4,10 };
    //MassP aim2{ Help2, 1 };
    //MassP aim3{ Help3, 1 };
    //Newxt.Add(aim2);
    //Newxt.Add(aim3);
    Newbie = Newbie * Newxt;
    Newbie.Show();
    std::cout << "Hello World!\n";
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
