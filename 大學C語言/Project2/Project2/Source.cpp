#include <iostream>

using namespace std;

void input_state(bool[], unsigned long int, int);//prompt user to enter initial state.
void output_state(bool[], unsigned long int, int);//output the state after r-rule once or s-rule once.
int output_step_state(bool[], unsigned long int, unsigned long int, int, int);//output the state after each steps and return how much steps to use.
void r_rule_once(bool[], unsigned long int);//implement r-rule once.
void s_rule_once(bool[], unsigned long int);//implement s-rule once.
void r_rule_and_output(bool[], unsigned long int);//output the state after r-rule once and which ring to implement.
void s_rule_and_output(bool[], unsigned long int, int);//output the state after s-rule once and which ring to implement.
bool check_all_0(bool[], unsigned long int);//check whether the state is consist of all 0, if yes, return 0.
void copy_original_to_test(bool[], bool[], unsigned long int, int);//copy the original array to array test for fx.
void fx(bool[], unsigned long int, int);//test which rule to implement first.

int main() {
    unsigned long int ring_num;//store how many rings does user want to solve.
    bool check;//store whether the state is all 0. 0 for all 0, 1 for not all 0.
    int counter1;//store how much steps to use for solving rings.

    cout << "Welcome to play X-Linked Ring!" << endl
        << "How many X-Linked Ring do you want to solve?" << endl;
    cin >> ring_num;
    cout << endl;//get how many rings does user want to solve.

    bool ring_state[ring_num + 1] = { 0 };//store the initial state of the rings from user.

    cout << "What the " << ring_num << "-Linked Ring look like?" << endl
        << "Please enter the rings state from inside to outside." << endl
        << "If the ring is on the sword, please input 1. Otherwise, please enter 0." << endl;
    input_state(ring_state, ring_num + 1, 1);
    cout << endl;//get the initial state of the rings from user.

    cout << "The rings state of " << ring_num << "-Linked Ring is: ";
    output_state(ring_state, ring_num + 1, 1);
    cout << endl;//output the initial state.

    cout << "If run R-rule once, the rings state of " << ring_num << "-Linked Ring is: ";
    r_rule_once(ring_state, ring_num);
    output_state(ring_state, ring_num + 1, 1);
    r_rule_once(ring_state, ring_num);
    cout << endl;//demonstration of r-rule.
    cout << "If run S-rule once, the rings state of " << ring_num << "-Linked Ring is: ";
    check = check_all_0(ring_state, ring_num);
    if (check == 1) {
        s_rule_once(ring_state, ring_num);
        output_state(ring_state, ring_num + 1, 1);
        s_rule_once(ring_state, ring_num);
    }
    else {
        output_state(ring_state, ring_num + 1, 1);
    }
    cout << endl << endl;//demonstration of s-rule.

    bool test[ring_num + 1] = { 0 };//store a copy of ring_state for fx to test.

    cout << "Let's start to solve the " << ring_num << "-Linked Ring.";
    copy_original_to_test(ring_state, test, ring_num + 1, 1);
    fx(test, ring_num + 1, 1);
    if (test[ring_num] == 0 && check == 1) {
        cout << endl << "Start with S-rule !!" << endl;
    }
    else if (test[ring_num] == 1 && check == 1) {
        cout << endl << "Start with R-rule !!" << endl;
    }
    else {
        cout << endl;
    }//output which rule to use first.

    counter1 = output_step_state(ring_state, ring_num, ring_num, 0, test[ring_num]);//output the thorough steps with its ordinal information and get how much steps to use.

    if (check != 0 && counter1 == 1) {
        cout << endl << "The " << ring_num << "-Linked Ring is solved in " << counter1 << " step." << endl
            << "Thanks for using!! Goodbye ~";
    }
    if (check != 0 && counter1 != 1) {
        cout << endl << "The " << ring_num << "-Linked Ring is solved in " << counter1 << " steps." << endl
            << "Thanks for using!! Goodbye ~";
    }
    if (check == 0) {
        cout << "The rings state of " << ring_num << "-Linked Ring is: ";
        output_state(ring_state, ring_num + 1, 1);
        cout << endl << endl << "The " << ring_num << "-Linked Ring is solved in 0 step." << endl
            << "Thanks for using!! Goodbye ~";
    }//output exit message

    return 0;
}//end main

void input_state(bool o1[], unsigned long int n1, int counter2) {
    if (counter2 != n1) {
        if (counter2 == 1) {
            cout << "What the state of 1st rings?" << endl;
            cin >> o1[counter2];
            counter2++;
            input_state(o1, n1, counter2);
        }
        else if (counter2 == 2) {
            cout << "What the state of 2nd rings?" << endl;
            cin >> o1[counter2];
            counter2++;
            input_state(o1, n1, counter2);
        }
        else if (counter2 == 3) {
            cout << "What the state of 3rd rings?" << endl;
            cin >> o1[counter2];
            counter2++;
            input_state(o1, n1, counter2);
        }
        else if ((counter2 % 10 == 1) && (counter2 / 10 != 0) && (counter2 / 10 != 1)) {
            cout << "What the state of " << counter2 / 10 << "1st rings?" << endl;
            cin >> o1[counter2];
            counter2++;
            input_state(o1, n1, counter2);
        }
        else if ((counter2 % 10 == 2) && (counter2 / 10 != 0) && (counter2 / 10 != 1)) {
            cout << "What the state of " << counter2 / 10 << "2nd rings?" << endl;
            cin >> o1[counter2];
            counter2++;
            input_state(o1, n1, counter2);
        }
        else if ((counter2 % 10 == 3) && (counter2 / 10 != 0) && (counter2 / 10 != 1)) {
            cout << "What the state of " << counter2 / 10 << "3rd rings?" << endl;
            cin >> o1[counter2];
            counter2++;
            input_state(o1, n1, counter2);
        }
        else {
            cout << "What the state of " << counter2 << "th rings?" << endl;
            cin >> o1[counter2];
            counter2++;
            input_state(o1, n1, counter2);
        }
    }//prompt user to enter corresponding state with its ordinal information
}//end input_state

void output_state(bool o2[], unsigned long int n2, int counter3) {
    if (counter3 != n2) {
        cout << o2[counter3];
        counter3++;
        output_state(o2, n2, counter3);
    }//output the entries in the array which is the argument of output_state
}//end output_state

void r_rule_once(bool o3[], unsigned long int n3) {
    if (o3[n3] == 0) {
        o3[n3] = !o3[n3];
    }
    else {
        o3[n3] = !o3[n3];
    }
}//end r_rule_once

void s_rule_once(bool o4[], unsigned long int n4) {
    if (o4[n4] == 1) {
        o4[n4 - 1] = !o4[n4 - 1];
    }
    else {
        s_rule_once(o4, n4 - 1);
    }
}//end s_rule_once

bool check_all_0(bool o5[], unsigned long int counter4) {
    if (o5[counter4] == 1) {
        return 1;
    }
    else if (o5[counter4] == 0 && counter4 > 0) {
        counter4--;
        check_all_0(o5, counter4);
    }
    else {
        return 0;
    }
}//end check_all_0

void copy_original_to_test(bool o6[], bool t1[], unsigned long int n5, int counter5) {
    if (counter5 != n5) {
        t1[counter5] = o6[counter5];
        counter5++;
        copy_original_to_test(o6, t1, n5, counter5);
    }
}//end copy_original_to_test

void fx(bool t2[], unsigned long int n6, int counter6) {
    if (counter6 != n6) {
        if (t2[counter6] == 1) {
            t2[counter6 + 1] = !t2[counter6 + 1];
            counter6++;
            fx(t2, n6, counter6);
        }
        else {
            t2[counter6 + 1] = t2[counter6 + 1];
            counter6++;
            fx(t2, n6, counter6);
        }
    }//use the method in reference to get the value of fx which have an array as input
}//end fx

void r_rule_and_output(bool o7[], unsigned long int n7) {
    if (o7[n7] == 0) {
        o7[n7] = !o7[n7];
        if (n7 == 1) {
            cout << "!! Turn the 1st ring on !!" << endl;
            cout << "The rings state of " << n7 << "-Linked Ring is: ";
            output_state(o7, n7 + 1, 1);
            cout << endl;
        }
        else if (n7 == 2) {
            cout << "!! Turn the 2nd ring on !!" << endl;
            cout << "The rings state of " << n7 << "-Linked Ring is: ";
            output_state(o7, n7 + 1, 1);
            cout << endl;
        }
        else if (n7 == 3) {
            cout << "!! Turn the 3rd ring on !!" << endl;
            cout << "The rings state of " << n7 << "-Linked Ring is: ";
            output_state(o7, n7 + 1, 1);
            cout << endl;
        }
        else if ((n7 % 10 == 1) && (n7 / 10 != 0) && (n7 / 10 != 1)) {
            cout << "!! Turn the " << n7 / 10 << "1st ring on !!" << endl;
            cout << "The rings state of " << n7 << "-Linked Ring is: ";
            output_state(o7, n7 + 1, 1);
            cout << endl;
        }
        else if ((n7 % 10 == 2) && (n7 / 10 != 0) && (n7 / 10 != 1)) {
            cout << "!! Turn the " << n7 / 10 << "2nd ring on !!" << endl;
            cout << "The rings state of " << n7 << "-Linked Ring is: ";
            output_state(o7, n7 + 1, 1);
            cout << endl;
        }
        else if ((n7 % 10 == 3) && (n7 / 10 != 0) && (n7 / 10 != 1)) {
            cout << "!! Turn the " << n7 / 10 << "3rd ring on !!" << endl;
            cout << "The rings state of " << n7 << "-Linked Ring is: ";
            output_state(o7, n7 + 1, 1);
            cout << endl;
        }
        else {
            cout << "!! Turn the " << n7 << "th ring on !!" << endl;
            cout << "The rings state of " << n7 << "-Linked Ring is: ";
            output_state(o7, n7 + 1, 1);
            cout << endl;
        }
    }
    else {
        o7[n7] = !o7[n7];
        if (n7 == 1) {
            cout << "!! Turn the 1st ring down !!" << endl;
            cout << "The rings state of " << n7 << "-Linked Ring is: ";
            output_state(o7, n7 + 1, 1);
            cout << endl;
        }
        else if (n7 == 2) {
            cout << "!! Turn the 2nd ring down !!" << endl;
            cout << "The rings state of " << n7 << "-Linked Ring is: ";
            output_state(o7, n7 + 1, 1);
            cout << endl;
        }
        else if (n7 == 3) {
            cout << "!! Turn the 3rd ring down !!" << endl;
            cout << "The rings state of " << n7 << "-Linked Ring is: ";
            output_state(o7, n7 + 1, 1);
            cout << endl;
        }
        else if ((n7 % 10 == 1) && (n7 / 10 != 0) && (n7 / 10 != 1)) {
            cout << "!! Turn the " << n7 / 10 << "1st ring down !!" << endl;
            cout << "The rings state of " << n7 << "-Linked Ring is: ";
            output_state(o7, n7 + 1, 1);
            cout << endl;
        }
        else if ((n7 % 10 == 2) && (n7 / 10 != 0) && (n7 / 10 != 1)) {
            cout << "!! Turn the " << n7 / 10 << "2nd ring down !!" << endl;
            cout << "The rings state of " << n7 << "-Linked Ring is: ";
            output_state(o7, n7 + 1, 1);
            cout << endl;
        }
        else if ((n7 % 10 == 3) && (n7 / 10 != 0) && (n7 / 10 != 1)) {
            cout << "!! Turn the " << n7 / 10 << "3rd ring down !!" << endl;
            cout << "The rings state of " << n7 << "-Linked Ring is: ";
            output_state(o7, n7 + 1, 1);
            cout << endl;
        }
        else {
            cout << "!! Turn the " << n7 << "th ring down !!" << endl;
            cout << "The rings state of " << n7 << "-Linked Ring is: ";
            output_state(o7, n7 + 1, 1);
            cout << endl;
        }
    }//implement r-rule once and print the state after execution with its ordinal information
}//end r_rule_and_output

void s_rule_and_output(bool o8[], unsigned long int n8, int counter7) {
    if (o8[counter7] == 1 && o8[counter7 - 1] == 0) {
        o8[counter7 - 1] = !o8[counter7 - 1];
        if ((counter7 - 1) == 1) {
            cout << "!! Turn the 1st ring on !!" << endl;
            cout << "The rings state of " << n8 << "-Linked Ring is: ";
            output_state(o8, n8 + 1, 1);
            cout << endl;
        }
        else if ((counter7 - 1) == 2) {
            cout << "!! Turn the 2nd ring on !!" << endl;
            cout << "The rings state of " << n8 << "-Linked Ring is: ";
            output_state(o8, n8 + 1, 1);
            cout << endl;
        }
        else if ((counter7 - 1) == 3) {
            cout << "!! Turn the 3rd ring on !!" << endl;
            cout << "The rings state of " << n8 << "-Linked Ring is: ";
            output_state(o8, n8 + 1, 1);
            cout << endl;
        }
        else if (((counter7 - 1) % 10 == 1) && ((counter7 - 1) / 10 != 0) && ((counter7 - 1) / 10 != 1)) {
            cout << "!! Turn the " << (counter7 - 1) / 10 << "1st ring on !!" << endl;
            cout << "The rings state of " << n8 << "-Linked Ring is: ";
            output_state(o8, n8 + 1, 1);
            cout << endl;
        }
        else if (((counter7 - 1) % 10 == 2) && ((counter7 - 1) / 10 != 0) && ((counter7 - 1) / 10 != 1)) {
            cout << "!! Turn the " << (counter7 - 1) / 10 << "2nd ring on !!" << endl;
            cout << "The rings state of " << n8 << "-Linked Ring is: ";
            output_state(o8, n8 + 1, 1);
            cout << endl;
        }
        else if (((counter7 - 1) % 10 == 3) && ((counter7 - 1) / 10 != 0) && ((counter7 - 1) / 10 != 1)) {
            cout << "!! Turn the " << (counter7 - 1) / 10 << "3rd ring on !!" << endl;
            cout << "The rings state of " << n8 << "-Linked Ring is: ";
            output_state(o8, n8 + 1, 1);
            cout << endl;
        }
        else {
            cout << "!! Turn the " << (counter7 - 1) << "th ring on !!" << endl;
            cout << "The rings state of " << n8 << "-Linked Ring is: ";
            output_state(o8, n8 + 1, 1);
            cout << endl;
        }
    }
    else if (o8[counter7] == 1 && o8[counter7 - 1] == 1) {
        o8[counter7 - 1] = !o8[counter7 - 1];
        if ((counter7 - 1) == 1) {
            cout << "!! Turn the 1st ring down !!" << endl;
            cout << "The rings state of " << n8 << "-Linked Ring is: ";
            output_state(o8, n8 + 1, 1);
            cout << endl;
        }
        else if ((counter7 - 1) == 2) {
            cout << "!! Turn the 2nd ring down !!" << endl;
            cout << "The rings state of " << n8 << "-Linked Ring is: ";
            output_state(o8, n8 + 1, 1);
            cout << endl;
        }
        else if ((counter7 - 1) == 3) {
            cout << "!! Turn the 3rd ring down !!" << endl;
            cout << "The rings state of " << n8 << "-Linked Ring is: ";
            output_state(o8, n8 + 1, 1);
            cout << endl;
        }
        else if (((counter7 - 1) % 10 == 1) && ((counter7 - 1) / 10 != 0) && ((counter7 - 1) / 10 != 1)) {
            cout << "!! Turn the " << (counter7 - 1) / 10 << "1st ring down !!" << endl;
            cout << "The rings state of " << n8 << "-Linked Ring is: ";
            output_state(o8, n8 + 1, 1);
            cout << endl;
        }
        else if (((counter7 - 1) % 10 == 2) && ((counter7 - 1) / 10 != 0) && ((counter7 - 1) / 10 != 1)) {
            cout << "!! Turn the " << (counter7 - 1) / 10 << "2nd ring down !!" << endl;
            cout << "The rings state of " << n8 << "-Linked Ring is: ";
            output_state(o8, n8 + 1, 1);
            cout << endl;
        }
        else if (((counter7 - 1) % 10 == 3) && ((counter7 - 1) / 10 != 0) && ((counter7 - 1) / 10 != 1)) {
            cout << "!! Turn the " << (counter7 - 1) / 10 << "3rd ring down !!" << endl;
            cout << "The rings state of " << n8 << "-Linked Ring is: ";
            output_state(o8, n8 + 1, 1);
            cout << endl;
        }
        else {
            cout << "!! Turn the " << (counter7 - 1) << "th ring down !!" << endl;
            cout << "The rings state of " << n8 << "-Linked Ring is: ";
            output_state(o8, n8 + 1, 1);
            cout << endl;
        }
    }
    else {
        s_rule_and_output(o8, n8, counter7 - 1);
    }//implement s-rule once and print the state after execution with its ordinal information
}//end s_rule_and_output

int output_step_state(bool o9[], unsigned long int n9, unsigned long int counter8, int counter9, int start) {
    bool check;
    counter8 = n9;
    check = check_all_0(o9, n9);
    if ((start == 0) && (check != 0) && (counter9 % 2 == 0)) {
        s_rule_and_output(o9, n9, counter8);
        counter9 += 1;
        output_step_state(o9, n9, counter8, counter9, start);
    }
    else if ((start == 0) && (check != 0) && (counter9 % 2 == 1)) {
        r_rule_and_output(o9, n9);
        counter9 += 1;
        output_step_state(o9, n9, counter8, counter9, start);
    }
    else if ((start == 1) && (check != 0) && (counter9 % 2 == 0)) {
        r_rule_and_output(o9, n9);
        counter9 += 1;
        output_step_state(o9, n9, counter8, counter9, start);
    }
    else if ((start == 1) && (check != 0) && (counter9 % 2 == 1)) {
        s_rule_and_output(o9, n9, counter8);
        counter9 += 1;
        output_step_state(o9, n9, counter8, counter9, start);
    }
    else {
        return counter9;
    }