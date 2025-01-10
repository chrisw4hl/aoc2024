#include<string>
#include<sstream>
#include<iostream>
#include<set>
using namespace std;

vector<vector<int>> board;
size_t len_x = 0;
size_t len_y = 0;
int res2 = 0;

bool on_board(int x, int y){
	return (((x>=0)&&(x<len_x))&&((y>=0)&&(y<len_y)));

}

void turn_right(int &x, int &y){
	int new_x = y;
	int new_y = -x;
	x = new_x;
	y = new_y;

}

int loop(int x,int y,int vel_x,int vel_y){
  int count = 0;
  set<pair<int,int>>turns;
  while(on_board(x,y)){
    if(board[y][x]==0){
      board[y][x]=1;
    }
    if(on_board(x+vel_x,y-vel_y)&&(board[y-vel_y][x+vel_x]==2)){
      turn_right(vel_x,vel_y);
      if(count > 25000){
        return 1;
      }else{
        count++;
      }

    }else{
      x+=vel_x;
      y-=vel_y;
      count++;
    }

  }
  return 0;
}

void check_for_cycle(int x, int y, int vel_x, int vel_y){
  for(int i = 0; i<len_y; i++){
    for(int j = 0; j<len_x; j++){
      hold = board[i][j];
      board[i][j]=2;
      if(loop(x,y,vel_x,vel_y)==1){
        res2++;
      }
      board[i][j]=hold;
    }
  }
}

int main(){

	freopen("./day6.txt","r",stdin);
		string input = "";
	int start_x=0;
	int start_y=0;
	int row = 0;
	int res = 0;

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

  for(auto line : board){
    for(auto i : line){
      std::cout<<i;
    }
    std::cout<<"\n";
  }

	len_x=board[0].size();
	len_y=board.size();
	int vel_x=0;
	int vel_y=1;
	int res_loop = 0; 
  check_for_cycle(start_x, start_y, vel_x, vel_y);

  

for(auto line : board){
    for(auto i : line){
      std::cout<<i;
    }
    std::cout<<"\n";
  }

  for(int j=0; j<len_y; ++j){
    for(int k = 0; k<len_x; ++k){
      if(board[j][k]==1){
        res++;
      }
    }

  }

	std::cout<<"Part 1 result: "<<res<<std::endl;
  std::cout<<"Part 2 result: "<<res2<<std::endl;
return 0;
}
