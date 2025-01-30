// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

// for every element in versions, 1-n,
// call API function to see if current version, i, is bad
// while i is not bad, continue
// else return i

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 1, end = n, mid;
        for(int i = 1; i <= n; i++){
            mid = start + (end - start)/2;
            if(!isBadVersion(mid)){
                start = mid++;
            }
            else if(isBadVersion(mid) && isBadVersion(mid-1)){
                end = mid--;
            }
            if(isBadVersion(mid) && !isBadVersion(mid-1)){
                return mid;
            }
        }
        return -1;
    }
};




// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int first = 1;
        int last = n;

        while (first < last) {
            int mid = first + (last - first) / 2;

            if (isBadVersion(mid)) {
                last = mid; // Mid could be the first bad version, so narrow the
                            // range to the left half.
            } else {
                first = mid + 1; // If mid is not bad, the first bad version
                                 // must be after mid.
            }
        }

        return first; // At the end, first will be the first bad version.
    }
};