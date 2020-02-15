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
    ifstream keyf("key.txt");   //���� �� �������� ��������, ������� ����� ������� ������ ������ ����� �� �����
    keyf >> key;
    keyf.close();
    //
    ifstream fin("input.txt");
    string temp;
while (!fin.eof())
    {
    fin >> temp;
    inptex += temp;     //temp ����� ������ �� ������ �����, ������� �� ���� ��������� � ������� ���������� � ���� ������
    if (!fin.eof())     //����� ������� �� ����������, ����� ������� ����� ���� �� ������� �� �����, �� ������ ���� �� ����� �����, ����� �� ����
        inptex += " ";
    }
    fin.close(); // ��������� ����

    //������ � ����
    //����:           EVTIQWXQVVOPMCXREPYZ
    //�������� �����: ALLSWELLTHATENDSWELL (All's well that ends well)
    //����������:     EGEAMAIBOCOIQPAJATJK

    kl = key.length();

    //������� �������� �� �������, ����� �� ��������� ������ ������
    for (i = 0; i < inptex.length(); i++)
    {
        if (inptex[i] != ' ')
            inptexnopr += inptex[i];
    }
    //cout << inptexnopr << " " << inptexnopr.length() << endl;
    int il_nopr = inptexnopr.length();

    // �������� ������� ��� ����� �������� key
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
        obn = 0;    //��� �������� ����� ����� ������� ������
        while (obn < kl)
        {
            if (inptex[j] == '\0')
                break;
            else if (inptex[j] != ' ')
            {//

                    if ((inptex[j] >= 65) && (inptex[j] <= 90))
                    {
                        ia = inptex[j] - 65;
                        zag = true; //���� ��� ��������� �������������� � ASCII
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
                        inptex[j] = (ia + ka) % 26; //������� ����������
                    else
                        inptex[j] = (26 + (ia - ka)) % 26;  //������� ������������

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
    //������ � ����
    ofstream fout("out.txt");
    fout << inptex;
    fout.close();
    //
    cout << inptex
    //<< " " << inptex.length() //��� ������� (�� ���������� �� ������ �������)
    << endl; //����� �� �����
}
