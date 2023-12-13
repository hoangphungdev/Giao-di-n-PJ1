// Phung Manh Hoang 20215385
// Problem: Simulation Stack

#include <iostream>

using namespace std;

// Tao cau truc Node
struct Node
{
    int data_85;
    Node *next_85;
};

// Tao cau truc Stack
struct Stack
{
    int top_85;
    Node *head_85;
};

// Khoi tao Stack
Stack initStack()
{
    Stack S_85;
    S_85.top_85 = 0;
    S_85.head_85 = NULL;
    return S_85;
}

// Khoi tao Node
Node *initNode(int data_85)
{
    Node *temp_85_85 = new Node();
    temp_85_85->data_85 = data_85;
    temp_85_85->next_85 = NULL;
    return temp_85_85;
}

// Them Node vao Stack
void Push(Stack &S_85, int data_85)
{
    Node *temp_85 = initNode(data_85);
    temp_85->next_85 = S_85.head_85;
    S_85.head_85 = temp_85;
    S_85.top_85++;
}

// Xoa Node khoi Stack
void Pop(Stack &S_85)
{
    if (S_85.top_85 > 0)
    {
        S_85.top_85--;
        cout << S_85.head_85->data_85 << endl;
        Node *temp_85 = S_85.head_85->next_85;
        delete (S_85.head_85);
        S_85.head_85 = temp_85;
        return;
    }
    cout << "NULL" << endl;
}

// Xoa Stack
void deleteStack(Stack &S_85)
{
    while (S_85.top_85 > 0)
    {
        Node *temp_85 = S_85.head_85->next_85;
        delete (S_85.head_85);
        S_85.head_85 = temp_85;
        S_85.top_85--;
    }
}

int main()
{
    Stack S_85 = initStack();
    string str_85;
    int x_85;

    do
    {
        cin >> str_85;
        // Them Node vao Stack
        if (str_85 == "PUSH")
        {
            cin >> x_85;
            Push(S_85, x_85);
        }
        // Xoa Node khoi Stack
        else if (str_85 == "POP")
            Pop(S_85);

    } while (str_85 != "#");

    deleteStack(S_85);
}