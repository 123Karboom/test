#include <iostream>
using namespace std;



struct Point
{
    int x, y;
    Point *next;
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
        next = nullptr;
    }
};

void addNode(Point *&head, Point *newNode)
{
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Point *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

double khoangCach(int x, int y)
{
    return x*x + y*y;
}

void swapPoint(Point *a, Point *b)
{
    int tempX = a->x;
    int tempY = a->y;
    a->x = b->x;
    a->y = b->y;
    b->x = tempX;
    b->y = tempY;
}

bool comparePoint(Point *a, Point *b)
{
    double kc1 = khoangCach(a->x, a->y);
    double kc2 = khoangCach(b->x, b->y);

    if (kc1 == kc2)
    {
        return a->x < b->x;
    }

    return kc1 < kc2;
}

void sortPoint(Point *head)
{
    Point *cur = head;
    while (cur != nullptr)
    {
        Point *kcmin = cur;
        Point *temp = cur->next;
        while (temp != nullptr)
        {
            if (comparePoint(temp, kcmin))
            {
                kcmin = temp;
            }
            temp = temp->next;
        }
        swapPoint(cur, kcmin);
        cur = cur->next;
    }
}

void printPoints(Point *head)
{
    Point *cur = head;
    while (cur != nullptr)
    {
        cout << cur->x << " " << cur->y << endl;
        cur = cur->next;
    }
}

int main()
{
    int n;
    cin >> n;

    Point *head = nullptr;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        Point *newNode = new Point(x, y);
        addNode(head, newNode);
    }

    sortPoint(head);
    printPoints(head);

    return 0;
}
