#include <iostream>
#include <vector>
using namespace std;
void bublesort(int a[], int n)
{
       for (int i = 0; i < n; i++)
       {
              for (int j = 0; j < n - i - 1; j++)
              {
                     if (a[j] > a[j + 1])
                            swap(a[j], a[j + 1]);
              }
       }
}

void insertionsort(int n, int a[])
{
       for (int i = 1; i < n; i++)
       {
              int x = a[i];
              int pos = i - 1;
              while (pos >= 0 && x < a[pos])
              {
                     a[pos + 1] = a[pos];
                     pos--;
              }
              a[pos + 1] = x;
       }
}

void merge(int a[], int l, int m, int r)
{
       //TODO
       vector<int> x(a + l, a + m + 1);
       vector<int> y(a + m + 1, a + r + 1);
       int i = 0, j = 0;
       while (i < x.size() && j < y.size())
       {
              if (x[i] <= y[j])
              {
                     a[l] = x[i];
                     l++;
                     i++;
              }
              else
              {
                     a[l] = y[j];
                     ++l;
                     ++j;
              }
       }
       while (i < x.size())
       {
              a[l] = x[i];
              l++;
              i++;
       }
       while (j < y.size())
       {
              a[l] = y[j];
              l++;
              j++;
       }
}

void mergesort(int a[], int l, int r)
{
       if (l >= r)
              return;
       int m = (l + r) / 2;
       mergesort(a, l, m);
       mergesort(a, m + 1, r);
       merge(a, l, m, r);
}

void binarysearch(int a[], int n, int x)
{
    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (a[mid] == x)
        {
            cout << "Da tim thay o vi tri: " << mid << endl;
            return; // exit the function once x is found
        }
        else if (a[mid] < x)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << "Khong thay !!!" << endl; // output if x is not found
}


int main()
{
       int a[1000];
       int n;
       cin >> n;
       for (int i = 0; i < n; i++)
              cin >> a[i];
       // binarySearch check
       int x = 10;
       binarysearch(a, n, x);
}
