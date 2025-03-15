// Ceil The Floor
// https://www.naukri.com/code360/problems/ceiling-in-a-sorted-array_1825401

pair<int, int> getFloorAndCeil(vector<int>& a, int n, int x) {
    int ceilIndex = lower_bound(a.begin(), a.end(), x) - a.begin();
    int ceil;
    if (ceilIndex == a.size()){
        ceil = -1;
    }
    else{
        ceil = a[ceilIndex];
    }
    int floor = -1;
    int low = 0, high = a.size() - 1, mid;
    while (high >= low){
        mid = low + (high - low) / 2;
        if (a[mid] <= x){
            floor = a[mid];
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return { floor,ceil };
}

// TC O(logn) SC O(1)