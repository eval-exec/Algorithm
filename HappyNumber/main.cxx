class Solution {
public:
    bool isHappy(int n) {
        
        if (ss.count(n) == 1) return false;
        int h = hap(n);
        if (h == 1) return true;
        ss.insert(n);
        return isHappy(h);
    }
    
private:
    set<int> ss;
    

    int hap(int n){
        int sum = 0;
        int on = n;
        while(n > 0){
            sum += (n%10) * (n%10);
            n /= 10;
        }
        return sum;
    }
    

};
