using ll = long long;
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        ll sum = 0;
        ll altans = 0;
        int m = min(need1, need2);
        altans = static_cast<ll>(need1 + need2 - m) * static_cast<ll>(costBoth);
        if(cost1 + cost2 > costBoth){
            sum += (static_cast<ll>(m) * static_cast<ll>(costBoth));
            need1 -= m;
            need2 -= m;
        }
        if(cost1 > cost2){
            swap(cost1, cost2);
            swap(need1, need2);
        }
        if(need1 > 0){
            if(cost1 > costBoth){
                sum += (static_cast<ll>(need1) * static_cast<ll>(costBoth));
                need2 -= need1;
            }
            else{
                sum += (static_cast<ll> (need1) * static_cast<ll>(cost1));
            }
            need1 = 0;
        }
        if(need2 > 0){
            if(cost1 > costBoth){
                sum += (static_cast<ll>(need2) * static_cast<ll>(costBoth));
                need1 -= need2;
            }
            else{
                sum += (static_cast<ll> (need2) * static_cast<ll>(cost2));
            }
            need2 = 0;
        }

        return min(altans,sum);
        
    }
};