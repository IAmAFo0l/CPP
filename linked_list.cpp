#include "iostream"
using namespace std;

struct node{
    int val;
    node* next;
};

node *tail (NULL), *head (NULL), *temp, *iter;

void print()
{
    iter = head;
    if(head == NULL) cout << endl;
    else{
        while(iter->next != 0){
            cout << iter->val << ' ';
            iter = iter->next;
        }
        cout << iter->val;
        cout << endl;
    }
}

void append()
{
    cout << "Element to be appended: ";
    temp = new node;
    if(head == NULL){
        head = temp;
        tail = temp;
        cin >> head->val;
    }
    else{
        tail->next = temp;
        temp->next = NULL;
        tail = temp;
        cin >> tail->val;
    }
}

void pop()
{
    if(head == NULL) cout << "No element in linked list to pop";
    else if(head == tail) head = tail = NULL;
    else{
        iter = head;
        while(iter->next != tail) iter = iter->next;
        tail = iter;
        tail->next = 0;
    }
}

void insert()
{
    int pos;
    cout << "Position you wanna insert: ";
    cin >> pos;
    temp = new node;
    cout << "Element to be inserted: ";
    if(pos == 0){
        temp->next = head;
        head = temp;
        cin >> head->val;
    }
    else{
        iter = head;
        for(int i = 0; i < pos-1 && iter != tail; ++i) iter = iter->next;
        temp->next = iter->next;
        iter->next = temp;
        if(temp->next == 0) tail = temp;
        cin >> temp->val;
    }
}

void del()
{
    int pos;
    cout << "Enter the position of the element you wanna delete: ";
    cin >> pos;
    if(pos == 0 && head == NULL) cout << "Position out of range. Try appending or inserting";
    else if(pos == 0) head = head->next;
    else{
        iter = head;
        for(int i = 0; i < pos-1 && iter->next != tail; ++i) iter = iter->next;
        temp = iter->next;
        iter->next = temp->next;
        if(iter->next == 0) tail = iter;
    }
}

int main()
{
    cout << "An empty list has been intitalized\n";
    cout << "Available operations - append, insert, pop, delete, exit\n";
    string key;
    while(true){
        cout << "Operation to be performed: ";
        cin >> key;
        if(key == "append") append();
        else if(key == "pop") pop();
        else if(key == "insert") insert();
        else if(key == "delete") del();
        else if(key == "exit") return 0;
        else cout << "Please check the keyword entered\n";
        print();
    }
}
