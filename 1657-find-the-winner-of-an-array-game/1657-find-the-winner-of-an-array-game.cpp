class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if(k > arr.size()){
            sort(arr.begin(), arr.end(), greater<int>());
            return arr[0];
        }
        int cur = arr[0];
        int i = 1;
        int count = 0;
        while(i != arr.size()){
            //cout << cur << " " << arr[i] << endl;
            if(cur > arr[i]){
                count ++;
                arr.push_back(arr[i]);
            }else{
                //cout << arr[i] << " " << 1 << endl;
                arr.push_back(cur);
                cur = arr[i];
                count = 1;
            }
            //cout << cur << " " << count << endl;
            if(count == k){
                return cur;
            }
            i++;
        }   
        return -1;  
    }
};