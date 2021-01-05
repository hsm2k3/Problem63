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
    int size = sizeof(twoD)/sizeof(twoD[0]);

    for(int i = 0; i < size;i++)
    {
        for(int j = 0; j < size;j++)
        {
            if(twoD[i][j] == 'F')
            {
                if(verticalFinder(i, j, size))
                {
                    cout << target1 << " is found vertically\n";
                }
                if(horizontalFinder(i, j, size))
                {
                    cout << target1 << " is found horizontally\n";
                }

            }
            if(twoD[i][j] == 'M')
            {
                if(verticalFinder(i, j, size))
                {
                    cout << target2 << " is found vertically\n";
                }
                if(horizontalFinder(i, j, size))
                {
                    cout << target2 << " is found horizontally\n";
                }
            }
        }
    }
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