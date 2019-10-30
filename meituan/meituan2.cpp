#include<iostream>
#include<vector>
#include<string>

using namespace std;

class PrizePool{
public:
    void send(string input) {
        cout << input;
    }
};
class ReviewEncourage {
public:
    ReviewEncourage(int n);      // 构造函数,n为中奖用户数
    void bonus(PrizePool prizePool);  // 仅能打印A，表示发放积分
    void coupon(PrizePool prizePool);  // 仅能打印B，表示发放优惠券
    void contribution(PrizePool prizePool);  // 仅能打印C，表示发放贡献值
    void printSeq();

private:
    int total;
    vector<char> reward;
};

int main(){
    int n = 0;
    cin >> n;
    ReviewEncourage *reviewEncourage = new ReviewEncourage(n);
    reviewEncourage->printSeq();
    return 0;
}


ReviewEncourage::ReviewEncourage(int n){
    ReviewEncourage::total = n;
}

// 仅能打印A，表示发放积分
void ReviewEncourage::bonus(PrizePool prizePool){
    prizePool.send("A");
}
// 仅能打印B，表示发放优惠券
void ReviewEncourage::coupon(PrizePool prizePool){
    prizePool.send("B");
}
// 仅能打印C，表示发放贡献值
void ReviewEncourage::contribution(PrizePool prizePool){
    prizePool.send("C");
}


void ReviewEncourage::printSeq(){
    PrizePool prizePool;
    int BCcount = 1;
    for(int i = 0; i< total; i++){
        if(i%2 == 0){
            bonus(prizePool);
        }
        else if(BCcount++%2 == 1){
            coupon(prizePool);
        }
        else{
            contribution(prizePool);
        }
    }
}