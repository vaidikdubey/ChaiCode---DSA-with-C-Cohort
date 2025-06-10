#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> monotonicIncreasing(vector<int> nums)
{
    int n = nums.size();
    stack<int> st;
    vector<int> result;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top() > nums[i])
        {
            st.pop();
        }
        st.push(nums[i]);
    }

    while (!st.empty())
    {
        result.insert(result.begin(), st.top());
        st.pop();
    }

    return result;
}

int main()
{

    vector<int> num1 = {3, 4, 5, 6, 1, 2, 4, 5, 7, 8};

    vector<int> num2 = {1, 2, 3, 4, 5, 5, 6, 7, 8, 8, 9, 10};

    vector<int> result = monotonicIncreasing(num1);

    cout << "Monotonic Increasing Stack Num1" << endl;
    for(int ele: result) {
        cout << ele << " ";
    }
    cout << endl;

    result = monotonicIncreasing(num2);
    
    cout << "Monotonic Increasing Stack Num2" << endl;
    for(int ele: result) {
        cout << ele << " ";
    }
    cout << endl;

    return 0;
}