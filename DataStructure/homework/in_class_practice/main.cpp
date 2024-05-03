#include<iostream>

using namespace std;

template <class T>
class ChainNode{
public:
    T data;
    ChainNode<T> *link;
    ChainNode(const T& value, ChainNode<T>* next = nullptr) : data(value), link(next) {}
};

template<class T>
class ChainIterator{
public:
    ChainIterator(ChainNode<T>* node) : current(node) {}

    ChainIterator<T>& operator++() {
        current = current->link;
        return *this;
    }

    T& operator*() const {
        return current->data;
    }

    bool operator!=(const ChainIterator<T>& other) const {
        return current != other.current;
    }

    ChainNode<T>* current;
};

template<class T>
class Chain{
public:
    ChainNode<T>* first;
    ChainNode<T>* last;

    Chain() : first(nullptr), last(nullptr) {}

    typedef ChainIterator<T> iterator;          //宣告iterator為ChainIterator<T>的別名

    iterator begin() const {
        return iterator(first);
    }

    iterator end() const {
        return iterator(nullptr);
    }

    void PrintValues() const
    {
        for (iterator it = begin(); it != end(); ++it) {
            cout << *it << " ";
        }
        cout << "\n";
    }

    void InsertNodeAtFirst(const T& value)
    {
        ChainNode<T>* newNode = new ChainNode<T>(value, first);
        first = newNode;
        if (last == nullptr)
            last = newNode;
    }

    void AppendNode(const T& value)
    {
        ChainNode<T>* newNode = new ChainNode<T>(value);
        if (first == nullptr)
        {
            first = newNode;
            last = newNode;
        }
        else
        {
            last->link = newNode;
            last = newNode;
        }
    }

    void InsertNodeAtIndex(const T& value, iterator position) {
        if (position.current == nullptr) {
            AppendNode(value);
            return;
        }

        ChainNode<T>* newNode = new ChainNode<T>(value, position.current->link);
        position.current->link = newNode;
    }

    void DeleteNode(iterator position) {
        if (position.current == first) {
            first = first->link;
            delete position.current;
            return;
        }

        ChainNode<T>* current = first;
        while (current != nullptr && current->link != position.current) {
            current = current->link;
        }

        if (current != nullptr) {
            current->link = position.current->link;
            if (position.current == last)
                last = current;
            delete position.current;
        }
    }
};

int main(){
    Chain<char> chain;

    chain.AppendNode('a');
    chain.AppendNode('b');
    chain.AppendNode('c');
    chain.AppendNode('d');
    chain.AppendNode('e');
    chain.PrintValues();

    chain.InsertNodeAtFirst('f');
    chain.PrintValues();

    Chain<char>::iterator it = chain.begin();
    for (int i = 0; i < 3 && it != chain.end(); ++i) {
        ++it;
    }
    chain.InsertNodeAtIndex('f', it);
    chain.PrintValues();

    // Using iterator to delete the node at position 3
    it = chain.begin();
    for (int i = 0; i < 3 && it != chain.end(); ++i) {
        ++it;
    }
    chain.DeleteNode(it);
    chain.PrintValues();
    return 0;
}
