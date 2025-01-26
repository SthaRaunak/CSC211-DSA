
#include <iostream>

using namespace std;

class ListNode {
public:
  int value;
  ListNode *next;

  ListNode(int value) {
    this->value = value;
    next = nullptr;
  }
};

class LinkedList {
  ListNode *head;
  ListNode *tail;

public:
  LinkedList() {
    head = nullptr;
    tail = nullptr;
  }

  void insertHead(int value) {
    ListNode *a = new ListNode(value);
    if (head == nullptr) {
      head = a;
      tail = a;
    } else {
      a->next = head;
      head = a;
    }
  }

  void insertTail(int value) {
    ListNode *a = new ListNode(value);
    if (tail == nullptr) {
      head = a;
      tail = a;
    } else {
      tail->next = a;
      tail = a;
    };
  }

  void display() {
    ListNode *temp = head;
    cout << "The linked list with index " << endl;
    int i = 1;
    while (temp != nullptr) {

      cout << i << ") " << temp->value << (temp == head ? " <- Head" : "")
           << (temp == tail ? " <- Tail" : "") << endl;
      temp = temp->next;
      i++;
    }
  }
  void getValue(int index) {
    ListNode *temp = head;
    for (int i = 1; i < index; i++) {
      if (temp == nullptr) {
        cout << "Invalid index" << endl;
        break;
      }
      temp = temp->next;
    }
    if (temp == nullptr)
      return;
    cout << "the value is " << temp->value << endl;
  };
};

