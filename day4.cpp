#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
	int res = 0;
	string line = "";
	vector<string> board;



	freopen("./day4.txt","r",stdin);


	while(getline(cin,line)){
		board.push_back(line);

	}

	int horiz_size = board[0].size();
	int vert_size = board.size();

	for(int i = 0; i<board.size(); ++i){
		for(int j = 0; j<board[i].size(); ++j){
			if(board[i][j]== 'X'){

				if(j<(horiz_size-3)){
					if(board[i].substr(j,4)=="XMAS"){
						res++;
					}
					if(i>=3){
						if((board[i-1][j+1]=='M')&&(board[i-2][j+2]=='A')&&(board[i-3][j+3]=='S')){
							res++;
						}

					}
				}
				if(j>=3){
					if(board[i].substr(j-3,4)=="SAMX"){
						res++;
					}

					if(i>=3){
						if((board[i-1][j-1]=='M')&&(board[i-2][j-2]=='A')&&(board[i-3][j-3]=='S')){
							res++;
						}
										
					}
				}
				if(i<(vert_size-3)){
					if((board[i+1][j]=='M')&&(board[i+2][j] == 'A') && (board[i+3][j]=='S')){
						res++;
					}

					if(j<(horiz_size-3)){
						if((board[i+1][j+1]=='M')&&(board[i+2][j+2]=='A')&&(board[i+3][j+3]=='S')){
							res++;
						}
					}

					if(j>=3){
						if((board[i+1][j-1]=='M')&&(board[i+2][j-2]=='A')&&(board[i+3][j-3]=='S')){
							res++;
						}

					}


				}
				if(i>=3){
					if((board[i-1][j]=='M')&&(board[i-2][j] == 'A') && (board[i-3][j]=='S')){
						res++;
					}
				}

			}


		}

	}


	std::cout<<res<<std::endl;

	return 0;
}
