#include <iostream>

#define MAX 3

using namespace std;

template <typename T> class CircularQueue {
private:
  int front, rear;
  T *items;

public:
  CircularQueue() {
    front = rear = -1;
    items = new T[MAX];
  }

  void enqueue(T data_item) {
    if (front == ((rear + 1) % MAX)) {
      cout << "Queue is full" << endl;
    } else if (front == -1) {
      rear = front = 0;
      items[rear] = data_item;
    } else if (rear == (MAX - 1)) {
      rear = 0;
      items[rear] = data_item;
    } else {
      items[++rear] = data_item;
    }
  }

  T dequeue() {
    T data_item;
    if (front == -1) {
      cout << "The queue is empty" << endl;
      return 0;
    } else if (front == rear) {
      data_item = items[front];
      front = rear = -1;
    } else if (front == (MAX - 1)) {
      data_item = items[front];
      front = 0;
    } else {
      data_item = items[front++];
    }
    cout << "deuque item: " << data_item << endl;
    return data_item;
  }

  void display() {
    if (front == -1) {
      cout << "display err: The queue is empty" << endl;
      return;
    }
    cout << "Queue elements are : " << endl;

    if (front <= rear) {
      for (int i = front; i <= rear; i++) {
        cout << items[i] << ",";
      }
      cout << endl;
    } else {
      for (int i = front; i < MAX; i++) {
        cout << items[i] << ",";
      }

      for (int i = 0; i <= rear; i++) {
        cout << items[i] << ",";
      }
      cout << endl;
    }
  }
};


