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
        }

        void search(int key){
            Node* ptr = HEAD;
            for (int i = 0; i < key; i++)
                if (ptr != NULL)
                    ptr = ptr -> next;
                else 
                    cout << "Node key overflow" << endl;
            cout << "Searched data is " << ptr -> data << endl;
            
        }

        void delete_node(int key){
            if (key <= 0)
                cout << "Invalid key number: " << key << endl;
            else {
                Node* ptr = HEAD;
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

        void delete_node_by_value(int data){
            Node* ptr = HEAD;
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

            prev = ptr = deleteNode = NULL;

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
        }

        void display(){
            Node* ptr = HEAD;
            cout << "Values are: ";
            while (ptr != NULL){
                cout << ptr -> data << " ";
                ptr = ptr -> next;
            }
            cout << endl;
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
            }
        }

        void append(LinkedList& data){
            Node* ptr = HEAD;
            if (HEAD == NULL)
                HEAD = data.HEAD;
            else {
                while (ptr -> next != NULL)
                    ptr = ptr -> next;
    
                ptr -> next = data.HEAD;
            }
            ptr = NULL;
        }
};

int main() {

    // int choice, ele, pos;
    // do{
    //     cout << "1. Insert values at the beginning of the list" << endl;
    //     cout << "2. Insert values at the position of the list" << endl;
    //     cout << "3. Insert values at the end of the list" << endl;

    //     cout << "4. Delete values from the behinning of the list" << endl;
    //     cout << "5. Delete values from the position of the list" << endl;
    //     cout << "6. Delete values from the end of the list" << endl;

    //     cout << "7. Update values at the position of the list" << endl;
    //     cout << "8. Check the list count" << endl;
    //     cout << "9. List all values" << endl;

    //     cout << "0. Exit" << endl;

    //     cout << "Your Choice: ";
    //     cin >> choice;

    //     switch (choice){
    //         case 0:
    //             cout << "Exiting operations... Thank you for using Linked List" << endl;
    //             break;

    //         case 1:

    //     }
    // } while(choice != 0);

    int s = 0;

    LinkedList l1;



    l1.append(s += 10);
    l1.append(s += 10);
    l1.append(s += 10);
    l1.append(s += 10);
    l1.append(s += 10);

    l1.insert_at_beginning(s += 10);
    l1.insert_at_beginning(s += 10);
    l1.insert_at_beginning(s += 10);
    l1.insert_at_beginning(s += 10);
    l1.insert_at_beginning(s += 10);

    l1.display();
    l1.reverse();
    l1.display();
    
    l1.delete_node(1);
    l1.display();
    
    l1.delete_node_by_value(100);
    l1.display();

    LinkedList create;
    create.insert_at_beginning(1290);
    create.insert_at_beginning(1291);
    create.insert_at_beginning(1292);

    create.append(170);
    create.append(171);
    create.append(172);

    l1.append(create);

    create.display();
    l1.display();

    l1.search(2);
    return 0;
}