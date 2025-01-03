#include<string>
#include<sstream>
#include<iostream>
using namespace std;

bool on_board(int x, int y, size_t len_x, size_t len_y){
	return (((x>=0)&&(x<len_x))&&((y>=0)&&(y<len_y)));

}

void turn_right(int &x, int &y){
	int new_x = y;
	int new_y = -x;
	x = new_x;
	y = new_y;

}

int main(){

	freopen("./day6.txt","r",stdin);
	vector<vector<int>> board;
	string input = "";
	int start_x=0;
	int start_y=0;
	int row = 0;
	int res =0;
	while(getline(cin,input)){
		vector<int> line;
		for(int i = 0; i<input.size(); ++i){
			if(input[i] == '#'){
				line.push_back(2);
			}else if(input[i] =='^'){
				line.push_back(0);
				start_x=i;
				start_y=row;
			}else{
				line.push_back(0);
			}
		}
		board.push_back(line);

		row++;
	}

	size_t len_x=board[0].size();
	size_t len_y=board.size();
	int vel_x=0;
	int vel_y=1;

	while(on_board(start_x, start_y, len_x, len_y)){
		if(board[start_y][start_x]==0){
			board[start_y][start_x]=1;
		}	
		if((start_y-vel_y<len_y)&&(start_x+vel_x<len_x)&&board[start_y-vel_y][start_x+vel_x]==2){
			turn_right(vel_x, vel_y);
		}

		start_x+=vel_x;
		start_y-=vel_y;
			

			}


for(int j=0; j<len_y; ++j){
	for(int k = 0; k<len_x; ++k){
		if(board[j][k]==1){
			res++;
		}
	}

}
	std::cout<<res<<std::endl;
return 0;
}
