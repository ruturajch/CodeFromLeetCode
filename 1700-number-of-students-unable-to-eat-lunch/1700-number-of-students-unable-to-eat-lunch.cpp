class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> studentStack;
        queue<int> sandwichStack;
        
        int n = students.size();
        for(int i = 0; i < n; i++){
            studentStack.push(students[i]);
            sandwichStack.push(sandwiches[i]);
        }
        int i = 0;
        while(i < n){
            if(studentStack.empty()){
                //cout << "hello" << endl;
                return 0;
            }else if(studentStack.front() == sandwichStack.front()){
                studentStack.pop();
                sandwichStack.pop();
                i = 0;
                n = studentStack.size();
            }else{
                i++;
                int temp = studentStack.front();
                studentStack.pop();
                studentStack.push(temp);
            }
        }
        return studentStack.size();
    }
};