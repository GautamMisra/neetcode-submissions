class MedianFinder {
public:
vector<int>arr;
double median;
    MedianFinder() {

    }
    
    void addNum(int num) {
        arr.push_back(num);
        sort(arr.begin(),arr.end());
    }
    
    double findMedian() {
        int n=arr.size();
        if(n%2==0){
            median=(arr[(n - 1) / 2] + arr[n / 2]) / 2.0;
        }
        else{
            median=arr[n/2];
        }
        return median;
    }
};
