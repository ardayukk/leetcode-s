class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> vec;
        for(int i = 0; i < position.size(); i++){
            vec.push_back(make_pair(position[i], speed[i]));
        }
        
        std::sort(vec.begin(), vec.end(),
          [](const std::pair<int,int>& a, const std::pair<int,int>& b) {
              return a.first > b.first;
          });

        stack<double> s;
        for(int i = 0; i < vec.size(); i++){
            double arrivaltime = (double)(target - vec[i].first) / vec[i].second;

            if(s.empty()){
                s.push(arrivaltime);
            }
            else{
                double top = s.top();
                if(top < arrivaltime){
                    s.push(arrivaltime);
                }
            }
        }
        return s.size();
        

    }

};