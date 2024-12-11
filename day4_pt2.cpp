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

	for(int i = 1; i<board.size()-1; ++i){
		for(int j = 1; j<board[i].size()-1; ++j){
			if(board[i][j]== 'A'){

				if(j<=(horiz_size-1)){
					if(i>=1){
						if((board[i-1][j+1]=='S')&&(board[i+1][j-1]=='M')){
							if((board[i+1][j+1]=='S')&&(board[i-1][j-1]=='M')){

								res++;
							}
							if((board[i+1][j+1]=='M')&&(board[i-1][j-1]=='S')){

								res++;
							}

						}
						if((board[i-1][j+1]=='M')&&(board[i+1][j-1]=='S')){
							if((board[i+1][j+1]=='S')&&(board[i-1][j-1]=='M')){

								res++;
							}

							if((board[i+1][j+1]=='M')&&(board[i-1][j-1]=='S')){

								res++;
							}
							}


					}
				}
			}
						


		}

	}


	std::cout<<res<<std::endl;

	return 0;
}
