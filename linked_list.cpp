#include "iostream"
using namespace std;

struct node {
    int value;
    node* next;
};

int main(void)
{
    cout << "Program to create a linked list in c++. When you are done inputting values, just enter 0!\n";
    node* head = new node;
    cin >> head->value;
    node* n = head;
    while(head->value != 0){
        int i;
        cin >> i;
        if(i == 0) break;
        node* temp = new node;
        n->next = temp;
        temp->value = i;
        n = temp;
    }
    n->next = 0;
    cout << "Succesfully created a linked list: [ ";
    for(node* iter = head; iter != NULL; iter = iter->next) cout << iter->value << ' ';
    cout << "]\n";
}
