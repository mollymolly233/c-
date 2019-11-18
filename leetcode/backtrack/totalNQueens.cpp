#include<iostream>
#include<vector>
#include<utility>
using namespace std;
/*
N皇后问题说明：一个n*n的棋盘上，能摆放n个的皇后的不同方法。
皇后这一棋子按照国际象棋的规则，只能在横纵、斜线三个方向上攻击。
所以要使皇后之间两两不能相互攻击到，需要将下一个皇后设置在前一个皇后的“日”字斜对角的位置上
 * Q * Q *
 Q * * * Q
 * * A * *
 Q * * * Q
 * Q * Q *
 并且任意一行或一列都不能有两个皇后

 思路分析
1.按照回溯法对一个皇后A的周围8个位置Q进行探测，查看：
	1.该位置是否在棋盘内；
	2.该位置所在行列是否已经有皇后了
2.查到符合条件的位置则置为皇后
3.把当前位置挪到刚刚新设置的皇后上，调用回溯算法，返回1，对新皇后的八个位置进行探测
出口是：皇后的数量足够了（成功） 或 整个棋盘都已经访问过了（失败）
*/

/*=======================================
				函数声明
=======================================*/
class Solution {
public:
	int totalNQueens(int n);//n皇后问题所有解的个数
	vector<vector<string>> solveNQueens(int n);//n皇后问题所有的解
private:
	vector<vector<int>> seq = {
		{-2,1},{-1,2},
		{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}
	};
	vector<vector<vector<int>>> resultArr;//结果数组，三维，元素是一个可行的皇后位置组合
	int n;//N皇后的N
	vector<int> row,column;//标记每一行每一列是否有皇后

	bool ifInMatrix(int x, int y);
	bool ifNoQueenInline(int x, int y);
	bool ifNoQueenInDiagnal(int x, int y, vector<vector<int>> matrix);
	void backtracking(vector<vector<int>> oneWay,int x, int y,vector<vector<int>> oneMatrix);
	void setQueen(vector<vector<int>> &oneMatrix, int x, int y, int value);//设置（value = 1）/撤销（value = 0）一个位置为皇后
	vector<string> TransQueensSeqIntoStr(vector<vector<int>> oneWay);//把结果转换成string的vector
	
};

void showVec(vector<int> v);//打印数组
void showTwoDimVec(vector<vector<int>> v);//二维数组
void showThreeDimVec(vector<vector<vector<int>>> v);//打印三维数组
void showVecStr(vector<string> v);//打印元素为string的vector
void showMatrix(vector<vector<int>> matrix);//打印矩阵

/*=======================================
				主函数
=======================================*/

int main(){
	Solution solution;
	solution.solveNQueens(4);
	return 0;
}

/*=======================================
				函数定义
=======================================*/

//目标：求n皇后问题的解的个数
int Solution::totalNQueens(int n) {
	return 0;
}

//目标：求n皇后问题的所有解
vector<vector<string>> Solution::solveNQueens(int n) {
	vector<vector<string>> result = {{""}};
	this->n = n;
	// this->row.resize(n);
	// this->column.resize(n);
	for(int i = 0; i<n; i++){
		vector<vector<int>> oneWay;
		vector<int> v0(n);
		vector<vector<int>> oneMatrix(n,v0);

		vector<int> line(n);
		this->row = line;
		this->column = line;
		backtracking(oneWay,0,i,oneMatrix);
	}
	// showThreeDimVec(this->resultArr);
	return result;
}

void Solution::backtracking(vector<vector<int>> oneWay,int x, int y,vector<vector<int>> oneMatrix){
	// cout << "------------------" << endl << 
	// "current(" << x << "," << y << "), queen num = " << oneWay.size() << endl;
	// cout << "row: "; showVec(this->row);
	// cout << "column: " ; showVec(this->column);
	// showMatrix(oneMatrix);//测试

	//失败的出口，位置验证不成功
	if(!ifInMatrix(x,y) || !ifNoQueenInline(x,y) || oneMatrix[x][y] != 0){
		// cout << "wrong place, itself" << endl;
		return;
	}

	//失败的出口，斜对角4个任意一个有值
	if(!ifNoQueenInDiagnal(x, y, oneMatrix))
		return;
	// if(ifInMatrix(x-1,y-1)) cout << "1:" << oneMatrix[x-1][y-1] << endl;
	// if(ifInMatrix(x+1,y-1)) cout << "2:" << oneMatrix[x+1][y-1] << endl;
	// if(ifInMatrix(x-1,y+1)) cout << "3:" << oneMatrix[x-1][y+1] << endl;
	// if(ifInMatrix(x+1,y+1)) cout << "4:" << oneMatrix[x+1][y+1] << endl;

	//失败的出口，已经访问到最后一层，但是皇后数量任然不够
	// if(x == this->n){
	// 	cout << "" << endl;
	// 	return;
	// }
	
	// cout << "new right Queen" << endl;
	vector<int> pos = {x,y};//进入可能的结果数组，候选皇后
	oneWay.push_back(pos);
	this->setQueen(oneMatrix,x,y,1);//设置为皇后
	// cout << "row: "; showVec(this->row);
	// cout << "column: " ; showVec(this->column);
	// showMatrix(oneMatrix);//测试

	//成功的出口，皇后的数量达到n
	if((int)oneWay.size() == this->n){
		this->resultArr.push_back(oneWay);
		showMatrix(oneMatrix);//测试
		return;
	}

	// showMatrix(oneMatrix);//测试
	for(int i = 0; i< (int)this->seq.size(); i++){
		int nextX = x+seq[i][0],nextY = y+seq[i][1];
		backtracking(oneWay,nextX,nextY,oneMatrix);//成功则会使oneway进入result
	}
	oneWay.pop_back();//退回前若没有进入结果数组，则说明是失败的
	this->setQueen(oneMatrix,x,y,0);//撤销皇后
	// cout << "row: "; showVec(this->row);
	// cout << "column: " ; showVec(this->column);
}
void Solution::setQueen(vector<vector<int>> &oneMatrix, int x, int y, int value){
	oneMatrix[x][y] = value;
	this->row[x] = value;
	this->column[y] = value;
}

//判断一个点是否被占用，是否超出界限
bool Solution::ifInMatrix(int x, int y){
	if(x>=0 && x<this->n //x在范围内
		&& y>=0 && y<this->n //y在范围内
		)
		return true;
	return false;
}
//前提是xy已经在矩阵中
bool Solution::ifNoQueenInline(int x, int y){
	if(this->row[x] == 0 //这一行没有其它皇后
		&& this->column[y] == 0 //这一列没有其它皇后
		)
		return true;
	return false;
}
//判断(x,y)的4个斜对角是不是有queen，有则说明(x,y)不合法
bool Solution::ifNoQueenInDiagnal(int x, int y, vector<vector<int>> matrix){
	if(ifInMatrix(x-1,y-1) && matrix[x-1][y-1] == 1)
		return false;
	if(ifInMatrix(x+1,y-1) && matrix[x+1][y-1] == 1)
		return false;
	if(ifInMatrix(x-1,y+1) && matrix[x-1][y+1] == 1)
		return false;
	if(ifInMatrix(x+1,y+1) && matrix[x+1][y+1] == 1)
		return false;
	return true;
}

vector<string> Solution::TransQueensSeqIntoStr(vector<vector<int>> oneWay){
	vector<string> result;
	for(int i = 0; i< (int)oneWay.size(); i++){
		string line;
		for(int j = 0; j < (int)oneWay[i].size(); j++){
			if(oneWay[i][j] == 0){
				line += ".";
			}
			else{
				line += "Q";
			}
		}
		result.push_back(line);
	}
	return result;
}


/*=======================================
				辅助函数
=======================================*/

void showVecStr(vector<string> v){
	cout << "one way:" << endl;
	for(int i = 0; i<(int)v.size(); i++){
		cout << v[i] << "," << endl;
	}
	cout << endl;
}
void showVec(vector<int> v){
	for(int i = 0; i<(int)v.size(); i++){
		cout << v[i] << ",";
	}
	cout << endl;
}

void showTwoDimVec(vector<vector<int>> v){
	// cout << "2 dim vec:" << endl;
	for(int i = 0; i< (int)v.size(); i++){
		showVec(v[i]);
	}
	cout << endl;
}

void showThreeDimVec(vector<vector<vector<int>>> v){
	cout << "3 dim vec:" << endl;
	for(int i = 0; i< (int)v.size(); i++){
		showTwoDimVec(v[i]);
	}
	cout << endl;
}

void showMatrix(vector<vector<int>> matrix){
	cout << "matrix:" << endl;
	for(int i = 0; i< (int)matrix.size(); i++){
		for(int j = 0; j < (int)matrix[i].size(); j++){
			cout << " " << matrix[i][j];
		}
		cout << endl;
	}
	cout << endl;
}