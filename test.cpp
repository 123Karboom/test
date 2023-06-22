#include <iostream>

using namespace std;

int hashFunction(int k, int m)
{
    return k % m;
}

void insertElement(int *hashTable, int k, int m)
{
    int index = hashFunction(k, m);

    for (int i = 0; i < m; i++)
    {
        int newIndex = (index + i * i) % m;

        if (hashTable[newIndex] == 0 || hashTable[newIndex] == -1)
        {
            hashTable[newIndex] = k;
            return;
        }
    }

    cout << k << " FULL" << endl;
}

void printEmptySlots(const int *hashTable, int m)
{
    for (int i = 0; i < m; i++)
    {
        if (hashTable[i] == 0)
        {
            cout << i << endl;
        }
    }
}

int main()
{
    int m, n;
    cin >> m >> n;

    int *hashTable = new int[m];

    for (int i = 0; i < m; i++)
    {
        hashTable[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        insertElement(hashTable, k, m);
    }

    printEmptySlots(hashTable, m);

    delete[] hashTable;

    return 0;
}
