#include<iostream>
#include<vector>

using namespace std;

enum directions {N, NE, E, SE, S, SW, W, NW,No};
//allowable moves

struct offsets {
int a; // to be used in move[q].a
// (表示列的位移量)
int b; // to be used in move[q].b
// (表示行的位移量)
directions drections;
};

template <class T>
class Stack {
public:
    vector<T> elements;
    void push(const T& element) {
        elements.push_back(element);
    }

    void pop() {
        elements.pop_back();
    }

    T& top() {
        return elements.back();
    }

    size_t size() const {
        return elements.size();
    }
};

class maze{
private:
    vector<vector<char>> themap;
    offsets move[100]; //步數
    bool result();
    void output();

    int current_row=1;
    int current_col=1;
    int exit_row=0;
    int exit_col=0;
    int count=0;
    Stack<offsets> thepath;
public:
    maze();
    void findpath();
    void input(int row,int col,char value);
};