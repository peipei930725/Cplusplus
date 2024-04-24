#include <iostream>
#include <fstream> // 包含文件操作相關的頭文件

using namespace std;

enum directions {N, NE, E, SE, S, SW, W, NW, No};//方位

struct offsets {
int a;  // 表示列的位移量
int b;  // 表示行的位移量
directions drections;
};

template <class T>
class Stack { //template 的 stack
private:
    T* elements; // 使用指標來表示堆疊的元素
    size_t capacity; // 堆疊的容量
    size_t current_size; // 堆疊中當前的元素數量
public:
    // 構造函數，初始化堆疊
    Stack() : capacity(10), current_size(0) {
        elements = new T[capacity];
    }

    // 摧毀函數，釋放堆疊佔用的內存
    ~Stack() {
        delete[] elements;
    }

    // 將元素壓入堆疊
    void push(const T& element) {
        // 如果堆疊已滿，擴展容量
        if (current_size == capacity) {
            capacity *= 2;
            T* new_elements = new T[capacity];
            for (size_t i = 0; i < current_size; ++i) {
                new_elements[i] = elements[i];
            }
            delete[] elements;
            elements = new_elements;
        }
        elements[current_size++] = element;
    }

    // 將元素彈出堆疊
    void pop() {
        if (current_size > 0) {
            --current_size;
        }
    }

    // 返回堆疊頂部的元素
    T& top() {
        return elements[current_size - 1];
    }

    // 返回堆疊中元素的數量
    size_t size() const {
        return current_size;
    }
    // T* Stack<T>::getElements() const {
    //     return elements;
    // }
};


class maze{
private:
    char **themap; // 使用二維字符數組代替 vector<vector<char>>
    int height;    // 地圖高度
    int width;     // 地圖寬度
    bool result();           //判斷終點
    void output();           //輸出
    int current_row=1;
    int current_col=1;
    int count=0;
    pair<int, int> start_pos; // 起點位置
    pair<int, int> end_pos;   // 終點位置
    Stack<offsets> thepath;   // 紀錄走過的路
public:
    maze();
    void findpath();    //找路
    void input();       //輸入
    void outputToFile();//文件輸出
};