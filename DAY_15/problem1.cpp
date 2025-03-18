// K-th element of two Arrays
// https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=k-th-element-of-two-sorted-array

// Using Binary Search TC O(log(min(n,m))) SC O(1)
// Approach , similar to finding median of two sorted arrays we will have k elements in one part and rest in other then try to apply symmetry if the array gets sorted ans is max of left1 and left2
class Solution {
public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int n1 = a.size(), n2 = b.size();
        if (n2 < n1){ return kthElement(b, a, k); }
        int low = max(0, k - n2), high = min(k, n1), mid1, mid2;
        while (high >= low){
            mid1 = low + (high - low) / 2;
            mid2 = k - mid1;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            if (mid1 < n1){ r1 = a[mid1]; }
            if (mid2 < n2){ r2 = b[mid2]; }
            if (mid1 > 0){ l1 = a[mid1 - 1]; }
            if (mid2 > 0){ l2 = b[mid2 - 1]; }

            if (r1 >= l2 && r2 >= l1){
                return max(l1, l2);
            }
            else if (r1 < l2){
                low = mid1 + 1;
            }
            else{
                high = mid1 - 1;
            }
        }
        return -1;
    }
};

// Using 2 Pointer Approach O(n1+n2) SC O(1)
class Solution {
public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int n1 = a.size(), n2 = b.size();
        int i = 0, j = 0, n = n1 + n2;
        int count = 1;
        while (i < a.size() && j < b.size()){
            if (a[i] < b[j]){
                if (count == k){ return a[i]; }
                count++;
                i++;
            }
            else{
                if (count == k){ return b[j]; }
                count++;
                j++;
            }
        }
        while (i < n1){
            if (count == k){ return a[i]; }
            count++;
            i++;
        }
        while (j < n2){
            if (count == k){ return b[j]; }
            count++;
            j++;
        }
        return -1;
    }
};
