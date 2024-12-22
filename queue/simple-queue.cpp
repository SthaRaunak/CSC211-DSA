#include <iostream>

#define QUEUE_SIZE 5

using namespace std;

template <typename T> class Queue {
private:
  int front, rear; // index
  T *items;

public:
  Queue() {
    front = rear = -1;
    items = new T[QUEUE_SIZE];
  }

  void enqueue(T item) {
    if (rear == (QUEUE_SIZE - 1)) {
      cout << "queue is full! " << endl;
    } else if (rear == -1) {
      front++;
      items[++rear] = item;
    } else {
      items[++rear] = item;
    }
  }

  T dequeue() {
    if (rear == -1) {
      cout << "queue is empty!" << endl;
      return 0;
    } else if (front == rear) {
      T item = items[rear];
      front = rear = -1;
      return item;
    } else {
      return items[front++];
    }
  }

  void display() {
    for (int i = front; i <= rear; i++) {
      cout << items[i] << ",";
    }
    cout << endl;
  }
};
