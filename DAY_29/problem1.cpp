// Find length of Loop
// https://www.geeksforgeeks.org/problems/find-length-of-loop/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-length-of-loop

// Brute Force using map

/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node* head) {
        unordered_map<Node*, int> mpp;
        Node* temp = head;
        int indx = 0;
        while (temp != nullptr){
            if (mpp.find(temp) != mpp.end()){
                return indx - mpp[temp];
            }
            mpp[temp] = indx;
            temp = temp->next;
            indx++;
        }
        return 0;
    }
};

// TC O(n) SC O(n)
// Approach : store the index of the node and when it repeats compare it with its intial index.


// Optimal using tortoise and hare algo 

/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node* head) {
        Node* slow = head;
        Node* fast = head;
        while (fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow){
                slow = slow->next;
                int count = 1;
                while (slow != fast){
                    count++;
                    slow = slow->next;
                }
                return count;
            }
        }
        return 0;
    }
};

// TC O(n) SC O(1)
// Approach : refer to previous questions , as soon as we hit slow == fast we can stop one of the pointer and move the other till it reaches the other again keeping track of the count with a variable. 
