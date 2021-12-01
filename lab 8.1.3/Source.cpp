#define _CRT_SECURE_NO_WARNINGS 
#include <iostream> 
using namespace std;

bool Search(char* s)
{
    int  pos = 0;
    char* t;
    while (t = strchr(s + pos, 'Q'))
    {
        pos = t - s + 1;
        if ((s[pos - 2] == 'S') || (s[pos] == 'S'))
            return 1;
    }
    return 0;
}

char* Replace(char* s)
{
    char* t = new char[strlen(s)];
    char* p;
    int pos1 = 0,
        pos2 = 0;
    *t = 0;
    while (p = strchr(s + pos1, 'Q'))
    {
        if (s[p - s - 1] == 'S' && s[p - s] == 'Q')
        {
            pos2 = p - s + 2;
            strncat(t, s + pos1, pos2 - pos1 - 3);
            strcat(t, "***");
            pos1 = pos2 - 1;
        }
        else if (s[p - s] == 'Q' && s[p - s + 1] == 'S')
        {
            pos2 = p - s + 2;
            strncat(t, s + pos1 - 1, pos2 - pos1 - 1);
            strcat(t, "***");
            pos1 = pos2;
        }
    }
    strcat(t, s + pos1);
    strcpy(s, t);

    return t;
}
int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    if (Search(str))
        cout << "True" << endl;
    else
        cout << "False" << endl;
    char* dest = new char[151];
    dest = Replace(str);

    cout << "Modified string (result): " << dest << endl;
    return 0;
}