// Sort a stack
// https://www.geeksforgeeks.org/problems/sort-a-stack/1

/*The structure of the class is
class SortedStack{
public:
    stack<int> s;
    void sort();
};
*/

/* The below method sorts the stack s
you are required to complete the below method */
void SortedStack::sort()
{
    int topElement = s.top();
    s.pop();
    if (s.empty()){
        s.push(topElement);
        return;
    }
    sort();
    stack<int> stk;
    while (!s.empty() && s.top() > topElement){
        int temp = s.top();
        s.pop();
        stk.push(temp);
    }
    s.push(topElement);
    while (!stk.empty()){
        s.push(stk.top());
        stk.pop();
    }
}

// TC O(n square) SC O(n)
// Approach : recursively reach the the base case where we can compare elements of stack easily , think of using a temporary container to store the elements to insert the current element at the right position .