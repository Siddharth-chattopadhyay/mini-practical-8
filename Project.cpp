#include<iostream>
using namespace std;

class Node{        
    public:
        int data;
        Node *next;
};

class LinkedList{
    Node
        *HEAD,
        *newNode,
        *nextNode;
    public:
        LinkedList(){
            this -> HEAD =
            this -> newNode =
            this -> nextNode =
                NULL;
        }

        void insert_at_beginning(int data){
            if (this -> HEAD == NULL){
                this -> HEAD = new Node;
                this -> HEAD -> next = NULL;
            } else {
                this -> newNode = new Node;
                this -> newNode -> next = HEAD;
                HEAD = newNode;
                newNode = NULL;
            }
            this -> HEAD -> data = data;
            cout << "Inserted the values at the beginning of the list" << endl;
        }

        void insert_at_pos(int key, int data){
            if (key < 0){
                cout << "Invalid key" << endl;
            }
            else {
                int count = 0;
                Node* ptr = HEAD;
                while (ptr != NULL){
                    ptr = ptr -> next;
                    count++;
                }

                if (key >= count)
                    cout << "key overflow" << endl;

                else {
                    newNode = new Node;
                    newNode -> data = data;
                    ptr = HEAD;
                    for (int i = 0; i < key; i++){
                        nextNode = ptr;
                        ptr = ptr -> next;
                    }
                    newNode -> next = ptr;
                    
                    if (nextNode != NULL)
                        nextNode -> next = newNode;

                    if (key == 0){
                        HEAD = newNode;
                    }
                    cout << "Inserted an element at pos: " << key << endl;
                }
                nextNode = newNode = ptr = NULL;
            }
        }

        void search(int key){
            Node* ptr = HEAD;
            for (int i = 0; i < key; i++)
                if (ptr != NULL)
                    ptr = ptr -> next;

            if (ptr == NULL)
                cout << "Node key overflow" << endl;
            cout << "Searched data is " << ptr -> data << endl;
            
        }

        void delete_node(int key){
            if (key < 0)
                cout << "Invalid key number: " << key << endl;
            else {
                Node* ptr = HEAD;
                if (key == 0){
                    ptr = ptr -> next;
                    delete HEAD;
                    HEAD = ptr;
                }
                else {
                    ptr = HEAD;
                    for (int i = 0; i < key - 1; i++)
                        if (ptr != NULL)
                            ptr = ptr -> next;
                        else 
                            cout << "Node key overflow" << endl;
                
                    nextNode = ptr -> next -> next;
                    delete ptr -> next;
                    ptr -> next = nextNode;
                    nextNode = NULL;
                    ptr = NULL;
                    cout << "Deleted the node from key: " << key << endl;
                }
            }
        }

        void pop(){
            if (HEAD == NULL){
                cout << "No value is present" << endl;
            }
            else if (HEAD -> next == NULL){
                delete HEAD;
                HEAD = NULL;
                cout << "Popped (deleted from end) back node" << endl;
            }
            else {
                Node* ptr = HEAD, *prev;
                while (ptr -> next != NULL){
                    prev = ptr;
                    ptr = ptr -> next;
                }
                delete ptr;
                prev -> next = NULL;
                cout << "Popped (deleted from end) back node" << endl;
            }
        }

        void delete_node_by_value(int data){
            Node* ptr = HEAD;
            if (ptr -> data == data){
                ptr = ptr -> next;
                delete HEAD;
                HEAD = ptr;
            }
            else {
                Node* prev = NULL;
                Node* deleteNode = NULL;
                while (ptr != NULL && deleteNode == NULL){
                    if (ptr -> data == data)
                        deleteNode = ptr;
                    else {
                        prev = ptr;
                        ptr = ptr -> next;
                    }
                }
                if (deleteNode == NULL)
                    cout << "Couldn't find a node by value: " << data << endl;
                else {
                    prev -> next = ptr -> next;
                    delete ptr;
                    cout << "Successfully deleted a node by value: " << data << endl;
                }
                prev = deleteNode = NULL;
            }
            ptr = NULL;
        }

        void reverse(){
            Node* ptr = HEAD;
            Node* end = HEAD;
            int count = 1;
            while (HEAD != NULL && end -> next != NULL){
                end = end -> next;
                count++;
            }

            for (int i = 0; i < count / 2; i++){
                int data = ptr -> data;
                ptr -> data = end -> data;
                end -> data = data;
                ptr = ptr -> next;
                end = HEAD;
                for (int j = i + 2; j < count; j++)
                    end = end -> next;
            }

            ptr = NULL;
            end = NULL;
            cout << "Reversed a linked list" << endl;
        }

        void overrite(int key, int newValue){
            if (key < 0)
                cout << "Invalid key number: " << key << endl;

            else {
                int count = 1;
                Node* ptr = HEAD;
                while (HEAD != NULL && ptr -> next != NULL){
                    ptr = ptr -> next;
                    count++;
                }
                
                if (key >= count){
                    cout << "Key value overflow" << endl;
                }
                
                else {
                    ptr = HEAD;
                    for (int i = 0; i < key; i++){
                        ptr = ptr -> next;
                    }
                    cout << "Overritten data from " << ptr -> data << " to " << newValue << " at key " << key << endl;
                    ptr -> data = newValue;
                }
            }
        }

        void display(){
            if (HEAD == NULL){
                cout << "Nothing is present" << endl;
            }
            else {
                Node* ptr = HEAD;
                cout << "Values are: ";
                while (ptr != NULL){
                    cout << ptr -> data << " ";
                    ptr = ptr -> next;
                }
                cout << endl;
            }
        }

        void append(int data){
            newNode = new Node();
            if (newNode == NULL)
                cout << "Unable to append an integer value" << endl;
            else {
                newNode->data = data;
                newNode->next = NULL;
                Node* ptr = HEAD;
                if (HEAD == NULL){
                    HEAD = newNode;
                }
                else{
                    while (ptr -> next != NULL){
                        ptr = ptr -> next;
                    }
                    ptr -> next = newNode;
                }

    
                newNode = NULL;
                ptr = NULL;
                cout << "Appended a data to linked list" << endl;
            }
        }

        int getCount(){
            int count = 0;
            Node* ptr = HEAD;
            while (ptr != NULL){
                ++count;
                ptr = ptr -> next;
            }
            return count;
        }

        // void append(LinkedList& data){
        //     Node* ptr = HEAD;
        //     if (HEAD == NULL)
        //         HEAD = data.HEAD;
        //     else {
        //         while (ptr -> next != NULL)
        //             ptr = ptr -> next;
    
        //         ptr -> next = data.HEAD;
        //     }
        //     ptr = NULL;
        // }
};

int main() {
    LinkedList linkedList;
    int choice, ele, pos;
    do{
        cout << "1. Insert values at the beginning of the list" << endl;
        cout << "2. Insert values at the position of the list" << endl;
        cout << "3. Insert values at the end of the list" << endl;

        cout << "4. Delete values from the behinning of the list" << endl;
        cout << "5. Delete values from the position of the list" << endl;
        cout << "6. Delete values from the end of the list" << endl;

        cout << "7. Update values at the position of the list" << endl;
        cout << "8. Check the list count" << endl;
        cout << "9. List all values" << endl;

        cout << "0. Exit" << endl;

        cout << "Your Choice: ";
        cin >> choice;

        switch (choice){
            case 0:
                cout << "Exiting operations... Thank you for using Linked List" << endl;
                break;

            case 1:
                cout << "Enter element value: ";
                cin >> ele;
                linkedList.insert_at_beginning(ele);
                break;

            case 2:
                cout << "Enter position: ";
                cin >> pos;
                cout << "Enter element value: ";
                cin >> ele;

                linkedList.insert_at_pos(pos, ele);
                break;
            
            case 3:
                cout << "Enter element value: ";
                cin >> ele;
                linkedList.append(ele);
                break;

            case 4:
                linkedList.delete_node(0);
                break;

            case 5:
                cout << "Enter position: ";
                cin >> pos;
                linkedList.delete_node(pos);
                break;

            case 6:
                linkedList.pop();
                break;

            case 7:
                cout << "Enter position: ";
                cin >> pos;
                cout << "Enter new value: ";
                cin >> ele;
                linkedList.overrite(pos, ele);
                break;

            case 8:
                cout << "amount of data is " << linkedList.getCount() << endl;
                break;

            case 9:
                linkedList.display();
                break;

            default:
                cout << "Invalid choice ... try again" << endl;

        }
    } while(choice != 0);
    return 0;
}