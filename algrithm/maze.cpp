#include<iostream>
#include<vector>
#include<math.h>
#include<utility>//pair
#include<stack>


using namespace std;
class Maze{
public:
	void initMaze(int len, int width);
	void fixMaze();
	void showMaze();
	void showPath();
	void setStartAndEnd();
	bool ifLegal(int i, int j);
	void backtracking(int i, int j);
private:
	int x,y,foundFlag = 0;
	pair<int,int> start,end;
	vector<vector<int>> mazeMatrix;
};


int main(){
	Maze maze;
	cout << "init maze" << endl;
	maze.initMaze(5,7);

	cout << "show maze" << endl;
	maze.showMaze();
	maze.setStartAndEnd();
	maze.fixMaze();
	return 0;
}

void Maze::initMaze(int x, int y){
	this->x = x;
	this->y = y;
	//随机在len*width的矩阵中标记0/1，标为1的地方为迷宫有墙的地方，0的地方为可以走动的地方
	for(int i = 0; i<x; i++){
		vector<int> line;
		for(int j = 0; j<y; j++){
			int tmp = rand()%100;
			cout << tmp << endl;
			line.push_back((tmp<50) ? 0 : 1);
		}
		mazeMatrix.push_back(line);
	}
}

void Maze::showMaze(){
	cout << endl << "maze" << endl;
	for(int i = 0; i<x; i++){
		for(int j = 0; j<y; j++){
			if(mazeMatrix[i][j] == 0) cout << " ";
			else cout << mazeMatrix[i][j];
			cout << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void Maze::setStartAndEnd(){
	cout << "input start position seperated with blanket:";
	cin >> start.first >> start.second;
	while(start.first >= x || start.second >= y){
		cout << "illegal input, try again seperated with blanket:";
		cin >> start.first >> start.second;
	}

	cout << endl << "input end position seperated with blanket:";
	cin >> end.first >> end.second;
	while(end.first >= x || end.second >= y){
		cout << endl << "illegal input, try again seperated with blanket:";
		cin >> end.first >> end.second;
	}

	cout << endl << "start(" << start.first << "," << start.second << ")" << endl;
	cout << endl << "end(" << end.first << "," << end.second << ")" << endl;
}

void Maze::fixMaze(){
	//从start位置开始，一次探测上下所有4个方向，如果可以走通则存到solution里，不可以则退回
	backtracking(start.first,start.second);
	showMaze();
}

void Maze::backtracking(int i, int j){
	cout << i << "," << j << endl;
	//递归出口：当前访问的结点是终点
	if(i == end.first && j == end.second){
		//把这个过程走过的路打出来
		mazeMatrix[i][j] = 2;
		foundFlag = 1;
		return;
	}
	if(!ifLegal(i,j)){//不符合条件，退回剪枝
		// mazeMatrix[m][n] = 0;//退回
		cout << "(" << i << "," << j  << ") illegal" << endl;
		return;
	}
	else{//当前结点是合法的下一步
		mazeMatrix[i][j] = 2;//标记为访问，尝试它可能的所有下一个位置
		showMaze();
		//往四个方向尝试，如果可以则继续，如果不可以则退回
		backtracking(i+1,j);
		backtracking(i-1,j);
		backtracking(i,j+1);
		backtracking(i,j-1);
		//四个方向都尝试了，发现都不行，则标回0
		if(foundFlag != 1)
			mazeMatrix[i][j] = 0;//退回
	}
}

bool Maze::ifLegal(int i, int j){
	if(i>=0 && i<x && j>=0 && j<y && mazeMatrix[i][j] == 0)
		return true;
	return false;
}