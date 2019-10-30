#include<iostream>
#include<vector>
#include<map>

using namespace std;

void showVectString(vector<string> result);
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        //输入9键键盘上的一些数字，输出对应可能的所有字母组合
        //有的数字对应3个字母，有的对应4个字母
        map<int,string> chMap = {
            {2,"abc"},
            {3,"def"},
            {4,"ghi"},
            {5,"jkl"},
            {6,"mno"},
            {7,"pqrs"},
            {8,"tuv"},
            {9,"wxyz"},
            {0,""},
            {1,""},
        };
        
        //提取第一个数字
        string str = (string)chMap[(int)digits[0]-'0'];
        cout << digits[0] << "," << chMap[(int)digits[0]-'0'] << "," << str[0] << endl;

        vector<string> l1,l2;
        for(int k = 0; k < (int)str.size(); k++){
            string tmp = "";
            tmp.append(1,str[k]);
            l1.push_back(tmp);
        }

        //遍历这个数字列表，
        for(int i = 1; i<(int)digits.size(); i++){
            //遍历原来的字符串
            for(int j = 0; j < (int)l1.size();j++){
                //遍历当前数字的字母
                for(int k = 0; k < (int)chMap[(int)digits[i]-'0'].size(); k++){
                    //分别粘上后加入新数组
                    l2.push_back(l1[j]+chMap[(int)digits[i]-'0'].substr(k,1));
                    cout << "k = " << k << ", " << chMap[(int)digits[i]-'0'].substr(k,1) << endl;
                }
            }
            cout << "----------------" << endl;
            showVectString(l1);
            showVectString(l2);
            cout << "----------------" << endl;

            l1 = l2;
            l2.clear();
        }
        return l1;
    }
};

int main(){
    Solution solution;
    vector<string> result = solution.letterCombinations((string)"23");
    showVectString(result);
    return 0;
}

void showVectString(vector<string> result){
    cout << "result : " << endl;
    for(int i = 0; i< (int)result.size();i++){
        cout << i << " : " << result[i] << endl;
    }
    cout << endl;
}