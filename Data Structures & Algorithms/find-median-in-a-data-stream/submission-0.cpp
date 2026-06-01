class MedianFinder {
public:
    vector<int> arr;
    int n = 0;
    MedianFinder() {
    }
    
    void addNum(int num) {
        int i=0;
        for(; i<n; i++) {
            if (arr[i] > num) {
                break;
            }
        }
        arr.insert(arr.begin()+i, num);
        n++;
        // for (int a: arr) {
        //     cout << a << " ";
        // }
        // cout << endl;
    }
    
    double findMedian() {
        if (n%2 == 1) {
            return (double)(arr[n/2]);
        }
        else {
            return (arr[n/2 - 1]+arr[n/2])/(2.0);
        }
    }
};
