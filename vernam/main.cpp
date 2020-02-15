#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>

using namespace std;


int main()
{
    string inptex, key, inptexnopr;
    int kl, i, j;

    //inptex = "ALLSWELLTHATENDSWELL";
    //key = "EVTIQWXQVVOPMCXREPYZ";
    ifstream keyf("key.txt");   //ключ не содержит пробелов, поэтому можно считать только первое слово из файла
    keyf >> key;
    keyf.close();
    //
    ifstream fin("input.txt");
    string temp;
while (!fin.eof())
    {
    fin >> temp;
    inptex += temp;     //temp берет только по одному слову, поэтому их надо приписать к главной переменной в этом отделе
    if (!fin.eof())     //чтобы пробелы не потерялись, после каждого слова надо их вернуть на место, но только если не конец файла, тогда не надо
        inptex += " ";
    }
    fin.close(); // закрываем файл

    //пример с вики
    //Ключ:           EVTIQWXQVVOPMCXREPYZ
    //Открытый текст: ALLSWELLTHATENDSWELL (All's well that ends well)
    //Шифротекст:     EGEAMAIBOCOIQPAJATJK

    kl = key.length();

    //добавим проверку на пробелы, чтобы не наплодить лишних байтов
    for (i = 0; i < inptex.length(); i++)
    {
        if (inptex[i] != ' ')
            inptexnopr += inptex[i];
    }
    //cout << inptexnopr << " " << inptexnopr.length() << endl;
    int il_nopr = inptexnopr.length();

    // проверим сколько раз будем сдвигать key
    div_t checkingwords;
    checkingwords = div(il_nopr, kl);
    int cw = checkingwords.quot;
    if (il_nopr % kl > 0)
        cw++;
    //
    int method;
    while ((method < 1) || (method > 2))
    {
    cout << "Select the method of shifring: 1 - for shifor shifor, 2 - for unshifor unshifor" << endl;
    cin >> method;
    }
    //

    int obn;
    j = 0;
    int ka, ia;
    bool zag = false;
    //
    string newone[cw];
    for (i = 0; i < cw; i++)
    {
        obn = 0;    //для смещения ключа вдоль рабочей строки
        while (obn < kl)
        {
            if (inptex[j] == '\0')
                break;
            else if (inptex[j] != ' ')
            {//

                    if ((inptex[j] >= 65) && (inptex[j] <= 90))
                    {
                        ia = inptex[j] - 65;
                        zag = true; //флаг для обратного преобразования в ASCII
                    }
                    else
                        ia = inptex[j] - 97;

                    //

                    if ((key[obn] >= 65) && (key[obn] <= 90))
                    {
                        ka = key[obn] - 65;
                    }
                    else
                        ka = key[obn] - 97;

                    //

                    if (method == 1)
                        inptex[j] = (ia + ka) % 26; //формула шифрования
                    else
                        inptex[j] = (26 + (ia - ka)) % 26;  //формула дешифрования

                    //

                    if (zag)
                        ia = inptex[j] + 65;
                    else
                        ia = inptex[j] + 97;
                    inptex[j] = ia;
            }//
            else
            {
                j++;
                continue;
            }
        obn++;
        j++;

        }
    }
    //запись в файл
    ofstream fout("out.txt");
    fout << inptex;
    fout.close();
    //
    cout << inptex
    //<< " " << inptex.length() //для отладки (не добавились ли лишние пробелы)
    << endl; //вывод на экран
}
