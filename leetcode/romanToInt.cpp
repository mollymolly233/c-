class Solution {
public:
    int romanToInt(string s) {
        map<string, int> m;
        m[string("I")] = 1;
        
        m[string("IV")] = 4;
        m[string("V")] = 5;
        m[string("IX")] = 9;
        m[string("X")] = 10;
        
        m[string("XL")] = 40;
        m[string("L")] = 50;
        m[string("XC")] = 90;
        m[string("C")] = 100;
        
        m[string("CD")] = 400;
        m[string("D")] = 500;
        m[string("CM")] = 900;
        m[string("M")] = 1000;
        
        int count = 4;
        int num = 0;
        for(int i = 0;i<s.length();i++){
            string sub = s.substr(i,2);
            if(m.find(sub)!=m.end()){
                num +=m[sub];
                i++;
            }
            else{
                num += m[s.substr(i,1)];
            }
        }
        return num;
    }
};