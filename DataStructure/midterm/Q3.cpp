#include <iostream>

using namespace std;

class queue {
public:
    queue(int size);
    void enqueue(int item);
    void dequeue();
    int frontItem();

private:
    int front;
    int back;
    int *queuing;
    int Maxsize;
};

queue::queue(int size) : Maxsize(size), front(0), back(-1) {
    queuing = new int[Maxsize];
}

void queue::enqueue(int item) {
    back++; 
    back=back%6;
    queuing[back] = item;
    cout << "Enqueued: " << item << endl;
}

void queue::dequeue() {
    cout << "Dequeued: " << queuing[front] << endl;
    front++;
    front=front%6;
}

int queue::frontItem() {
    return queuing[front];
}

int main() {
    int t=0;
    int count=1;
    while(cin>>t){
        cout<<"Scenario #"<<t<<endl;
        int team;
        cin>>team;
        while(team--){
            queue theteam(20000);
        }
    }
}
