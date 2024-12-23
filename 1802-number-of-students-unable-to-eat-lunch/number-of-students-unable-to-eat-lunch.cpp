class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        bool isEnd = false;
        int initialStudentCount = students.size();
        int ctr = 0;
        int numbLeft = 0;
        while(!isEnd){
            if(students.front() == sandwiches.front()){
                students.erase(students.begin());
                sandwiches.erase(sandwiches.begin());
                numbLeft++;
                ctr = 0;
            }
            else{
                int temp = students.at(0);
                students.erase(students.begin());
                students.push_back(temp);
                ctr++;
            }
            if(ctr == students.size()){
                isEnd = true;
            }
        }
        return initialStudentCount -numbLeft;
    }
};