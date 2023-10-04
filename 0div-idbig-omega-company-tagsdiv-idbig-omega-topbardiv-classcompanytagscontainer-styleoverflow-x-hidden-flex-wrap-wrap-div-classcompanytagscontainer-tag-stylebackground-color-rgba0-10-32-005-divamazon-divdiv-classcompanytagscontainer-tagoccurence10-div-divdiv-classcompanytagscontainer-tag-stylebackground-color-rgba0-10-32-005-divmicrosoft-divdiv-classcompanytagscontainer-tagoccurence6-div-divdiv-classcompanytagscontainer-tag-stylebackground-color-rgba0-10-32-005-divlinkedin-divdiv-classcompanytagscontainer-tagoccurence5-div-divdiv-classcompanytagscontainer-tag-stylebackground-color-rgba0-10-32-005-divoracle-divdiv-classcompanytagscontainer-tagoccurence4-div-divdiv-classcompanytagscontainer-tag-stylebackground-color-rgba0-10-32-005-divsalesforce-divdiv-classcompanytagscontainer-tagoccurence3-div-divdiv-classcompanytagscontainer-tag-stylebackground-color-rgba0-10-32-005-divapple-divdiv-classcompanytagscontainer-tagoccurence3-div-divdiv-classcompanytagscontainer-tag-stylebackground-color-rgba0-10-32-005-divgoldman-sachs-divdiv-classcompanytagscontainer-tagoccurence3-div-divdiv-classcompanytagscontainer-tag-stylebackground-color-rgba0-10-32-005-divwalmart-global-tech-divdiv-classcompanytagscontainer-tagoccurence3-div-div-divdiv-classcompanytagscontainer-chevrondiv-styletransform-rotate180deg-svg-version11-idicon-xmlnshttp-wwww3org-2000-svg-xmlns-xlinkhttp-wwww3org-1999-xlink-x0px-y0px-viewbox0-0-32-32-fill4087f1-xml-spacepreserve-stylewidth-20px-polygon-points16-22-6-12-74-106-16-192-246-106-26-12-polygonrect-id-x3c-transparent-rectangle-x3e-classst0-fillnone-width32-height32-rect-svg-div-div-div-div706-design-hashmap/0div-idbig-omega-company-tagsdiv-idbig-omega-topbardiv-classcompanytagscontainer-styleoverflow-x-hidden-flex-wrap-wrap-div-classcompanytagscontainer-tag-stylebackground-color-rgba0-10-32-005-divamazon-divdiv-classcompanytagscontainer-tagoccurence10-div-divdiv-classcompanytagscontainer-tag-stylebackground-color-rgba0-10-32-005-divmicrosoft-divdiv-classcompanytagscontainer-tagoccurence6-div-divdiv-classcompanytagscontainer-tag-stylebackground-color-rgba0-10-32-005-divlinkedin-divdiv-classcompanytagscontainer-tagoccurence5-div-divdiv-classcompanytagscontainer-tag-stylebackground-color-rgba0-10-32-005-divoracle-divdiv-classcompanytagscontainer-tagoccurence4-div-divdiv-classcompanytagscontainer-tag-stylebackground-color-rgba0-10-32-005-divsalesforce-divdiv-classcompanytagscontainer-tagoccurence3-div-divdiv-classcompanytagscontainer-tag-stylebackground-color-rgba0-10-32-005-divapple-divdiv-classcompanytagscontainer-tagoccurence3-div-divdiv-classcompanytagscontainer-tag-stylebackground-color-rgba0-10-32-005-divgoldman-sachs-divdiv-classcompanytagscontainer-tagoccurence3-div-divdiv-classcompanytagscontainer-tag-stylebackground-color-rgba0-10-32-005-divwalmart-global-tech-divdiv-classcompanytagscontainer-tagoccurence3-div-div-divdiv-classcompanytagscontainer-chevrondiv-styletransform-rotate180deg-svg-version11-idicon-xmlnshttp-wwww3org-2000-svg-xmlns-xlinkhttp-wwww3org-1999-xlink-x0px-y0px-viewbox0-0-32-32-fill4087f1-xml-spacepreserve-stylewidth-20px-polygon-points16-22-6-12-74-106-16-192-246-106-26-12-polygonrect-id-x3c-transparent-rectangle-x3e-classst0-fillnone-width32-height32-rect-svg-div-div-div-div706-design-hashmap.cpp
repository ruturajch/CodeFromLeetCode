class MyHashMap {
public:
    vector<pair<int, int>> map ;

    MyHashMap() {
        map = vector<pair<int, int>>();
    }
    
    void put(int key, int value) {
        bool flag = false;
        int n = map.size();
        cout << "put"<< endl;
        for(int i = 0; i < n; i++){
            if(map[i].first == key){
                map[i].second = value;
                flag = true;
            }
        }
        if(!flag){
            map.push_back({key, value});   
        }
    }
    
    int get(int key) {
        int n = map.size();
        cout << "get"<< endl;
        for(int i = 0; i < n; i++){
            if(map[i].first == key){
                return map[i].second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int n = map.size();
        std::cout << "remove" << std::endl;

        // Use std::remove_if along with erase to remove elements
        map.erase(std::remove_if(map.begin(), map.end(),
                                 [key](const std::pair<int, int>& curPair) {
                                     return curPair.first == key;
                                 }),
                  map.end());
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */