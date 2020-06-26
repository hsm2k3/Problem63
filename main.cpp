#include <iostream>

using namespace std;

bool verticalFinder(int, int, int);
bool horizontalFinder(int, int, int);

string target1 = "FOAM", target2 = "MASS";
char twoD[4][4] = {{'F','A','C','I'},
                   {'O','B','Q','P'},
                   {'A','N','O','B'},
                   {'M','A','S','S'}};

int main() {
    char holder;
    bool found1, found2;
    /*sizeof(twoD)/sizeof(twoD[0]) returns size of rows*/
    int size = sizeof(twoD)/sizeof(twoD[0]);

    for(int i = 0; i < size;i++)
    {
        for(int j = 0; j < size;j++)
        {
            if(twoD[i][j] == 'F')
            {
                holder = twoD[i][j];
                found1 = verticalFinder(i, j, size);
            }
            if(twoD[i][j] == 'M')
            {
                holder = twoD[i][j];
                found2 = horizontalFinder(i, j, size);
            }
        }
    }

    if(found1 == true)
        cout << "FOAM is found\n";
    if(found2 == true)
        cout << "MASS is found\n";
    return 0;
}

bool verticalFinder(int x, int y, int size)
{
    string found;
    bool foundIt = false;
    for (int i = x; i < size; ++i) {
        if(target1[i] == twoD[i][y])
        {
            found += target1[i];
        }
    }
    if(found == target1 || found == target2)
        foundIt = true;

    return foundIt;
}

bool horizontalFinder(int x, int y, int size)
{
    string found;
    bool foundIt = false;
    for (int i = 0; i < size; ++i) {
        if(target2[i] == twoD[x][i])
        {
            found += target2[i];
        }
    }
    if(found == target1 || found == target2)
        foundIt = true;

    return foundIt;
}