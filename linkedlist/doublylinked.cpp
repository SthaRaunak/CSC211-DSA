#include <iostream>

using namespace std;

class ListNode {
public:
  int value;
  ListNode *next;
  ListNode *prev;

  ListNode(int value) {
    this->value = value;
    next = nullptr;
    prev = nullptr;
  }
};

// doubly linked list
class DLinkedList {
  ListNode *head;
  ListNode *tail;

public:
  DLinkedList() {
    head = nullptr;
    tail = nullptr;
  }

  void insertHead(int value) {
    ListNode *a = new ListNode(value);
    if (head == nullptr) {
      head = tail = a;
    } else {
      a->next = head;
      head->prev = a;
      head = a;
    }
  }

  void insertTail(int value) {
    ListNode *a = new ListNode(value);
    if (tail == nullptr) {
      head = tail = a;
    } else {
      tail->next = a;
      a->prev = tail;
      tail = a;
    }
  }

  void insertAfterNode(int node_data, int value) {
    ListNode *a = new ListNode(value);
    ListNode *temp = head;
    while (temp != nullptr && temp->value != node_data) {
      temp = temp->next;
    }

    if (temp != nullptr) {
      cout << "The node doesnt exist" << endl;
    } else if (temp == tail) {
      temp->next = a;
      a->prev = temp;
      tail = a;
    } else {
      temp->next->prev = a;
      a->next = temp->next;
      temp->next = a;
      a->prev = temp;
    }
  }


  void deleteHead() {
    ListNode *temp;
    if (head == nullptr) {
      cout << "The linked list is empty" << endl;
      return;
    } else if (head == tail) {
      temp = head;
      head = tail = nullptr;
      free(temp);
    } else {
      temp = head;
      head = head->next;
      head->prev = nullptr;
      free(temp);
    }
  }

  void deleteTail() {
    ListNode *temp;
    if (tail == nullptr) {
      cout << "The linked list is empty " << endl;
      return;
    } else if (head == tail) {
      temp = tail;
      head = tail = nullptr;
    } else {
      temp = tail;
      tail = tail->prev;
      tail->next = nullptr;
    }
    cout << "Deleted Value: " << temp->value << endl;
    free(temp);
  }

  void display() {
    ListNode *temp = head;

    cout << "Displaying Linked List" << endl;
    int i = 1;
    while (temp != nullptr) {
      cout << i << ") " << temp->value << (temp == head ? " <- Head" : "")
           << (temp == tail ? " <- Tail" : "") << endl;
      temp = temp->next;
      i++;
    }
  }

};

int main() {
  DLinkedList dl;
  int option, val, node_data;

  while (true) {
    cout << " 1) insert head \n 2) insert tail \n 3) delete head \n 4)delete "
            "tail \n 5) insert after node \n 6) display"
         << endl;
    cin >> option;
    if (option == 7)
      break;
    switch (option) {

    case 1:
      cout << "Enter a value" << endl;
      cin >> val;
      dl.insertHead(val);
      break;

    case 2:
      cout << "Enter a value" << endl;
      cin >> val;
      dl.insertTail(val);
      break;

    case 3:
      dl.deleteHead();
      break;

    case 4:
      dl.deleteTail();
      break;

    case 5:
      cout << "Enter a the value of node to insert after" << endl;
      cin >> node_data;
      cout << "Enter a value" << endl;
      cin >> val;
      dl.insertAfterNode(node_data, val);

    case 6:
      dl.display();
      break;
    default:
      cout << "Invalid option" << endl;
    }
  }
}
