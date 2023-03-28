#include <iostream>

using namespace std;

struct Node 
{
    int data;
    Node* next;
};

void addNode(Node** head, int data) 
    {
    Node* newNode = new Node{ data, nullptr 
    };
    if (*head == nullptr) 
    {
        *head = newNode;
        return;
    }
    Node* curr = *head;
    while (curr->next != nullptr) 
    {
        curr = curr->next;
    }
    curr->next = newNode;
}

void checkDuplicates(Node* head) 
{
    Node* curr = head;
    while (curr != nullptr) 
    {
        Node* next = curr->next;
        while (next != nullptr)
        {
            if (curr->data == next->data) 
            {
                cout << "\n The list includes two equal numbers. " << curr->data << endl;
                return;
            }
            next = next->next;
        }
        curr = curr->next;
    }
    cout << "\n The list doesn`t include two equal numbers: " << endl;
}

int main() 
    { 
    int amount;
    cout << "\n Enter the number of the list elements: "; cin >> amount;
    Node* head = nullptr;
    int num;
    for (int i = 0; i < amount; i++) 
    {
        cout << "Enter the number to include to list: ";
        cin >> num;
        addNode(&head, num);
    }

    checkDuplicates(head);

    return 0;
}