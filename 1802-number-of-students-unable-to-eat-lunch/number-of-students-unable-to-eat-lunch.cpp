class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count0 = 0;
        int count1 = 0;
        int numEat = 0;
        int n = students.size();
        for(int i = 0; i < n; i++){
            if(students[i] == 1){
                count1++;
            }
            else{
                count0++;
            }
        }
        queue<int> studq;
        queue<int> sandq;
        
        for(int i = 0; i < n; i++){
            studq.push(students[i]);
            sandq.push(sandwiches[i]);
        }
        int iter = 0;
        while(!studq.empty()){
            if(studq.front() == sandq.front()){
                numEat++;
                iter = 0;
                if(studq.front() == 0){
                    count0 -= 1;
                }
                else{
                    count1 -= 1;
                }
                studq.pop();
                sandq.pop();
            }
            else{
                iter++;
                int front = studq.front();
                studq.pop();
                studq.push(front);

            }

            if ((sandq.front() == 0 && count0 == 0) ||
                (sandq.front() == 1 && count1 == 0)) {
                break;
            }
            if (iter == studq.size()) break;
        }
        return n - numEat;
    }
};