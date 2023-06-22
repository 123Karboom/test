#include <bits/stdc++.h>
using namespace std;

// Định nghĩa một nút trong cây nhị phân tìm kiếm
struct Node
{
    int value;
    Node *left;
    Node *right;

    Node(int val)
    {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

// Hàm chèn một giá trị vào cây nhị phân tìm kiếm
void insertNode(Node *&root, int value)
{
    if (root == nullptr)
    {
        root = new Node(value);
        return;
    }

    if (value < root->value)
    {
        insertNode(root->left, value);
    }
    else
    {
        insertNode(root->right, value);
    }
}

// Hàm tạo cây nhị phân tìm kiếm từ một vector giá trị
Node *createBST(vector<int> values)
{
    Node *root = nullptr;
    for (int value : values)
    {
        insertNode(root, value);
    }
    return root;
}

// Hàm in ra các node theo thứ tự tăng dần
void printInOrder(Node *root, ofstream &outFile)
{
    if (root != nullptr)
    {
        printInOrder(root->left, outFile);
        outFile << root->value << " ";
        cout << root->value << " ";
        printInOrder(root->right, outFile);
    }
}

// Hàm in ra các node theo thứ tự giảm dần
void printReverseOrder(Node *root, ofstream &outFile)
{
    if (root != nullptr)
    {
        printReverseOrder(root->right, outFile);
        outFile << root->value << " ";
        cout << root->value << " ";
        printReverseOrder(root->left, outFile);
    }
}

// Hàm in ra các node lá có giá trị là số lẻ tăng dần
void printOddLeaves(Node *root, ofstream &outFile)
{
    if (root != nullptr)
    {
        printOddLeaves(root->left, outFile);
        if (root->left == nullptr && root->right == nullptr && root->value % 2 != 0)
        {
            outFile << root->value << " ";
            cout << root->value << " ";
        }
        printOddLeaves(root->right, outFile);
    }
}

// Hàm tính tầng của mỗi node trong cây theo thứ tự tăng dần của node
void calculateNodeLevels(Node *root, vector<int> &levels, int level)
{
    if (root != nullptr)
    {
        calculateNodeLevels(root->left, levels, level + 1);
        levels.push_back(level);
        calculateNodeLevels(root->right, levels, level + 1);
    }
}

// Hàm ghi mảng giá trị vào tập tin
void writeValuesToFile(vector<int> values, ofstream &outFile)
{
    for (int value : values)
    {
        outFile << value << " ";
        cout << value << " ";
    }
}

// Hàm tính số lượng node trong cây
int countNodes(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void findBalancedNodes(Node *node, vector<int> &result)
{
    if (node == nullptr)
    {
        return;
    }

    int leftCount = countNodes(node->left);
    int rightCount = countNodes(node->right);

    if (leftCount == rightCount)
    {
        result.push_back(node->value);
    }

    findBalancedNodes(node->left, result);
    findBalancedNodes(node->right, result);
}

int main()
{
    ifstream inFile("input.txt");
    ofstream outFile("output.txt");

    if (!inFile)
    {
        cout << "Khong the mo tep tin input.txt" << endl;
        return 1;
    }

    int n;
    inFile >> n;
    vector<int> values(n);
    for (int i = 0; i < n; i++)
    {
        inFile >> values[i];
    }
    inFile.close();

    Node *root = createBST(values);

    // Yêu cầu 1: Các node trong cây theo thứ tự tăng dần
    vector<int> inOrderValues;
    printInOrder(root, outFile);
    outFile << endl;
    cout << endl;

    // Yêu cầu 2: Các node trong cây theo thứ tự giảm dần
    vector<int> reverseOrderValues;
    printReverseOrder(root, outFile);
    outFile << endl;
    cout << endl;

    // Yêu cầu 3: Các node lá có giá trị là số lẻ tăng dần
    vector<int> oddLeaves;
    printOddLeaves(root, outFile);
    outFile << endl;
    cout << endl;

    // Yêu cầu 4: Các node trên cây có tổng số node cây con bên trái bằng tổng số node cây con bên phải

    vector<int> balancedNodes;
    findBalancedNodes(root, balancedNodes);
    for (int value : balancedNodes)
    {
        outFile << value << " ";
        cout << value << " ";
    }
    cout << endl;
    outFile << endl;

    // Yêu cầu 5: Số tầng của các node trong cây theo thứ tự tăng dần của node
    vector<int> nodeLevels;
    calculateNodeLevels(root, nodeLevels, 0);
    writeValuesToFile(nodeLevels, outFile);
    outFile << endl;
    cout << endl;

    outFile.close();

    return 0;
}
