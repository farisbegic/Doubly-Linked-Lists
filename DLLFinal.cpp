#include <iostream>
using namespace std;
struct node{
    int data;
    node *previous;
    node *next;
};

class DoublyLinkedList{
    node *first;
    node *last;
    int length;
public:
    DoublyLinkedList(){
        first = last = NULL;
        length = 0;
    }
    bool isEmpty(){
        if (first == NULL)
            return true;
        else
            return false;
    }
    void Display(){
        if (isEmpty()){
            cout << "The list is empty." << endl;
            return;
        }
        node *temp = first;
        while (temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    int getLength() const{ return length; }
    void addFront(int data){
        node *nova = new node;
        nova->data = data;
        nova->next = first;
        nova->previous = NULL;
        if (isEmpty()){
            last = nova;
        } else{
            first->previous = nova;
        }
        first = nova;
        length++;
        cout << "Successfully added element " << data << " to the beginning" << endl;
    }
    void addBack(int data){
        node *nova = new node;
        nova->data = data;
        nova->previous = last;
        nova->next = NULL;
        if (isEmpty())
            first = nova;
        else
            last->next = nova;
        last = nova;
        length++;
        cout << "Successfully added element " << data << " to the end" << endl;
    }
    void addPosition(int position, int data){
        if (position > length || position < 0){
            cout << "Invalid position." << endl;
            return;
        }
        else if (position == 0)
            addFront(data);
        else if (position == length)
            addBack(data);
        else if (position > 0 && position < length){
            node *nova = new node;
            nova->data = data;
            node *temp = first;
            int i = 0;
            while (temp != NULL && i < position){
                temp = temp->next;
                i++;
            }
            nova->next = temp;
            nova->previous = temp->previous;
            temp->previous->next = nova;
            temp->previous = temp;
            length++;
        }
        cout << "Successfully added element " << data << " to the " << position << ". position." << endl;
    }
    void deleteFront(){
        if (isEmpty()){
            cout << "The list is empty." << endl;
            return;
        }
        if (length == 1){
            first = last = NULL;
        } else {
            node *temp = first;
            first = first->next;
            first->previous = NULL;
            delete(temp);
        }
        length--;
        cout << "Deleting the first element.." << endl;
    }
    void deleteBack(){
        if (isEmpty()){
            cout << "The list is empty." << endl;
            return;
        }
        if (length == 1){
            first = last = NULL;
        } else{
            node *temp = last;
            last = last->previous;
            last->next = NULL;
            delete(temp);
        }
        length--;
        cout << "Deleting the last element.." << endl;
    }
    void deletePosition(int position){
        if (isEmpty()){
            cout << "The list is empty." << endl;
            return;
        }
        if (position > length || position < 0){
            cout << "Invalid position." << endl;
            return;
        }
        else if (position == 0)
            deleteFront();
        else if (position == length)
            deleteBack();
        else if (position > 0 && position < length){
            node *temp = first;
            int i = 0;
            while (temp != NULL && i < position){
                temp = temp->next;
                i++;
            }
            temp->previous->next = temp->next;
            temp->next->previous = temp->previous;
            delete(temp);
            length--;
        }
        cout << "Deleting the element at the " << position << ". position." << endl;
    }
};

int main(){
    cout << "Welcome to the demonstration program of doubly linked lists made by Begic Faris" << endl;
    DoublyLinkedList lista;
    bool state = true;
    int input, value, position;
    while (state){
        cout << "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
        cout << "Please choose one of the following options: " << endl;
        cout << "1. Insert item at the beginning" << endl;
        cout << "2. Insert item at given position" << endl;
        cout << "3. Insert item at the end" << endl;
        cout << "4. Delete first item" << endl;
        cout << "5. Delete last item" << endl;
        cout << "6. Delete item by position" << endl;
        cout << "7. Display Doubly Linked List" << endl;
        cout << "8. Get size of the Doubly Linked List" << endl;
        cout << "9. Exit the program" << endl;
        cout << "Please choose an option: " << endl;
        cin >> input;
        switch (input){
    case 1:
        cout << "You have chosen to insert an item at the beginning so please enter in the value." << endl;
        cin >> value;
        lista.addFront(value);
        break;
    case 2:
        cout << "You have chosen to insert an item at the given position so please enter in the position and value, respectively." << endl;
        cin >> position >> value;
        lista.addPosition(position,value);
        break;
    case 3:
        cout << "You have chosen to insert an item at the end so please enter in the value." << endl;
        cin >> value;
        lista.addBack(value);
        break;
    case 4:
        lista.deleteFront();
        break;
    case 5:
        lista.deleteBack();
        break;
    case 6:
        cout << "You have chosen to delete an item based on position, so please enter the position" << endl;
        cin >> position;
        lista.deletePosition(position);
        break;
    case 7:
        cout << "Doubly Linked List: " << endl;
        lista.Display();
        break;
    case 8:
        cout << "The size of your doubly linked list is " << lista.getLength() << endl;
        break;
    case 9:
        cout << "Thank you for using my program" << endl;
        state = false;
        break;
        }
    }
    return 0;
}
