// Search in Linked List
// https://www.geeksforgeeks.org/problems/search-in-linked-list-1664434326/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=search-in-linked-list-1664434326

/* Link list node */
/*
struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
}; */

class Solution {
public:
    // Function to count nodes of a linked list.
    bool searchKey(int n, Node* head, int key) {
        Node* temp = head;
        while (temp != nullptr){
            if (temp->data == key){
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
};

// TC O(n) SC O(1)
