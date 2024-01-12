#include<iostream>
#include<string>

using namespace std;

class student{
public:
    void setName(string name){
        Sname=name;
    }
    string getName(){
        return Sname;
    }
    void displayMessage()
    {
        cout << "Welcome to the grade book for\n" << getName() << "!"<< endl;
    }
private:
    string Sname;
};
int main(){
    string myname;
    student me;

    cout<<"my name is"<<me.getName()<<endl;
    cout << "\nPlease enter the course name:" << endl;
    getline( cin, myname ); 
    me.setName( myname ); 

    cout << endl; 
    me.displayMessage();

    return 0;
}