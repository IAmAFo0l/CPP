#include "iostream"
using namespace std;

struct node{
    int val;
    node* next;
};

// Initializing global variables
node *tail (NULL), *head (NULL), *temp, *iter;

// Print elements of the list
void print()
{
    // iterator starting from head
    iter = head;
    // In case of an empty list
    if(head == NULL) cout << endl;
    else{
        // Iterating over each element
        while(iter->next != 0){
            cout << iter->val << ' ';
            iter = iter->next;
        }
        cout << iter->val;
        cout << endl;
    }
}

// To append an element
void append()
{
    cout << "Element to be appended: ";
    // Creating a new node
    temp = new node;
    // In case of an empty list
    if(head == NULL){
        head = temp;
        tail = temp;
        cin >> head->val;
    }
    // In case of a non-empty list
    else{
        tail->next = temp;
        temp->next = NULL;
        tail = temp;
        cin >> tail->val;
    }
}

// To pop the last element
void pop()
{
    // In case of and empty list
    if(head == NULL) cout << "No element in linked list to pop";
    // In case of a single element list
    else if(head == tail){
        delete head;
        delete tail;
    }
    // For a non-empty list
    else{
        iter = head;
        // Iterating over each element
        while(iter->next != tail) iter = iter->next;
        iter->next = 0;
        delete tail;
        tail = iter;
    }
}

// Insert an element in the list
void insert()
{
    int pos;
    cout << "Position you wanna insert: ";
    // Taking position-to-be-inserted from user
    cin >> pos;
    // Creating a new node
    temp = new node;
    cout << "Element to be inserted: ";
    // In case of inserting an element at the first position
    if(pos == 0){
        temp->next = head;
        head = temp;
        cin >> head->val;
    }
    // Inserting at another position
    else{
        iter = head;
        // Iterating over each element
        // Inserting an element at a position out of range becomes tail element
        for(int i = 0; i < pos-1 && iter != tail; ++i) iter = iter->next;
        temp->next = iter->next;
        iter->next = temp;
        if(temp->next == 0) tail = temp;
        cin >> temp->val;
    }
}

// Deleting an element given its position
void del()
{
    int pos;
    cout << "Enter the position of the element you wanna delete: ";
    // Taking position-to-be-deleted from user
    cin >> pos;
    // In case of an empty list
    if(pos == 0 && head == NULL) cout << "Position out of range. Try appending or inserting";
    // Deleting the first element
    else if(pos == 0){
        temp = head->next;
        delete head;
        head = temp;
    }
    // Deleting other elements
    else{
        iter = head;
        // Iterating over each element
        // If the position is out of range the last element gets popped
        for(int i = 0; i < pos-1 && iter->next != tail; ++i) iter = iter->next;
        temp = iter->next;
        iter->next = temp->next;
        delete temp;
        // If the last element been deleted, tail is repositioned
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
        // Function calls
        if(key == "append") append();
        else if(key == "pop") pop();
        else if(key == "insert") insert();
        else if(key == "delete") del();
        else if(key == "exit") return 0;
        else cout << "Please check the keyword entered\n";
        print();
    }
}
