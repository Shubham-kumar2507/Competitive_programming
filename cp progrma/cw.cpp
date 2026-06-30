#include <iostream>
#include <algorithm> 
using namespace std;

int makeGoal(int big, int small, int goal) {
        int maxBig = min(goal / 5, big);
        int remain = goal - (maxBig * 5);

        return small >= remain ? remain : -1;
}

int main() {
    int big, small, goal;
    cout <<"goal: ";
    cin >> goal;
    cout <<"big: ";
    cin >> big;
    cout <<"small: ";
    cin >> small;
    cout << "Result: " << makeGoal(big, small, goal) << endl;   
    return 0;
}
