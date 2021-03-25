#include <iostream>
#include <ctime>
#include <vector>
#include <map>

using namespace std;

void show_function(vector<int>& Myvector, map<int, int>& Mymap);
void random_function(vector<int>& Myvector, map<int, int>& Mymap, int n);
void delete_function(vector<int>& Myvector, map<int, int>& Mymap);
void synchronize_function(vector<int>& Myvector, map<int, int>& Mymap);

int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(0));

    int n;
    vector<int> Myvector;
    map<int, int> Mymap;

    cout << "Введите n (>=20) = ";//захардкодил числа
    cin >> n;

    if(n >= 20)
    {
        random_function(Myvector, Mymap, n);
        show_function(Myvector, Mymap);
        delete_function(Myvector, Mymap);
        show_function(Myvector, Mymap);
        synchronize_function(Myvector, Mymap);
    }
    else
    {
        cout << "Неверное число" << endl;
    }

    Myvector.clear();
    Mymap.clear();

    return 0;
}

void show_function(vector<int>& Myvector, map<int, int>& Mymap)
{
    cout << "vector" << endl;

    for (auto i : Myvector)
    {
        cout << i << " ";
    }

    cout << endl << "map" << endl;

    for (auto i : Mymap)
    {
        cout << i.first << "," << i.second << "  ";
    }
    cout << endl;
}

void random_function(vector<int>& Myvector, map<int, int>& Mymap, int n)
{
    for(int i = 0; i < n; i++)
    {
        Myvector.push_back(rand() % 9 + 1);
        Mymap.emplace(i, rand() % 9 + 1);//map хранит в себе только уникальные ключи (первый элемент) -> сделаем кол-во ключей = кол-во элементов n (вектора) + в любом случае они хранятся в упорядаченном состоянии, а значениями будут числа от 1 до 9
    }
}

void delete_function(vector<int>& Myvector, map<int, int>& Mymap)
{
    for (int i = 0; i < rand() % 15; i++)//удаление случайного кол-ва чисел
    {
        Myvector.erase(Myvector.begin() + rand() % Myvector.size());//для vector

        int j = 0;//для map
        int d = rand() % Mymap.size();

        for(auto& k : Mymap)
        {
            if (j == d)//если j совпадает с rand числом, то удаляем элемент
            {
                Mymap.erase(k.first);
                break;//выход сразу после удаления, поэтому проблем быть н должно
            }
            j++;
        }

    }
    cout << endl << "Контейнеры после удаления случайного количества элементов" << endl << endl;
}

void synchronize_function(vector<int>& Myvector, map<int, int>& Mymap)
{
    vector<int> fMyvector;
    map<int, int> fMymap;

    for (auto vit = Myvector.begin(); vit != Myvector.end(); vit++)//классический перебор двумя циклами
    {
        for (auto mit = Mymap.begin(); mit != Mymap.end(); mit++)
        {
            if (*vit == mit->second)
            {
                fMyvector.push_back(*vit);
                fMymap.insert(make_pair(mit->first, *vit));
                Mymap.erase(mit->first);
                break;
            }
        }
    }
    cout << endl << "Контейнеры после синхронизации" << endl << endl;
    show_function(fMyvector, fMymap);//в map смотреть на значение
}
