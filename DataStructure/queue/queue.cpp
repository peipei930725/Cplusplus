#include <iostream>

using namespace std;

class queue {
public:
    queue(int MaxQueueSize);
    ~queue();
    bool IsFull();
    bool IsEmpty();
    void enqueue(int item);
    void dequeue();
    int frontItem();

private:
    int front;
    int rear;
    int *queuing;
    int Maxsize;
};

queue::queue(int MaxQueueSize) : Maxsize(MaxQueueSize), front(0), rear(-1) {
    queuing = new int[Maxsize];
}

queue::~queue() {
    delete[] queuing;
}

bool queue::IsFull() {
    return (rear == Maxsize - 1);
}

bool queue::IsEmpty() {
    return (front > rear);
}

void queue::enqueue(int item) {
    if (!IsFull()) {
        rear++;
        rear=rear%6;
        queuing[rear] = item;
        cout << "Enqueued: " << item << endl;
    } else {
        cout << "Queue is full! Cannot enqueue." << endl;
    }
}

void queue::dequeue() {
    if (!IsEmpty()) {
        cout << "Dequeued: " << queuing[front] << endl;
        front++;
        front=front%6;
    } else {
        cout << "Queue is empty! Cannot dequeue." << endl;
    }
}

int queue::frontItem() {
    if (!IsEmpty()) {
        return queuing[front];
    } else {
        cout << "Queue is empty!" << endl;
        return -1; // Assuming -1 is not a valid value in the queue
    }
}

int main() {
    queue myQueue(5); // Create a queue with a maximum size of 5

    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);
    myQueue.enqueue(4);
    myQueue.enqueue(5);

    // Trying to enqueue one more element when the queue is full
    myQueue.enqueue(6);

    cout << "Front item: " << myQueue.frontItem() << endl;

    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();

    // Trying to dequeue one more element when the queue is empty
    myQueue.dequeue();

    return 0;
}
