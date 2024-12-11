#include<iostream>
#include<string>
#include<sstream>

bool remove_one(std::string line){

	return false;
}

bool check_level(std::vector<int> line){
	int diff = 0;
	bool increasing = false;
	diff = line[0] - line[1];
	if((diff > 3)||(diff < -3)){
		return false;
	}
	if(diff < 0){
		increasing = true;

	}else if(diff == 0){
		return false;
	}else{
		increasing = false;
	}


	for(int i=2; i<line.size(); ++i){
		diff = line[i-1]-line[i];

		if ((increasing == true) && (diff > 0)){
			return false;
		}else if((increasing == false) && (diff < 0)){
			return false;
		}else if((diff > 3) || (diff < -3) || (diff == 0)){
			return false;
		}
	}


	return true;

}
int main(){

	int res = 0;
	std::string line = "";
	std::freopen("day2.txt", "r", stdin);
        // the following line opens the input file
	
nest:	
	while(std::getline(std::cin, line)){
		std::vector<int> line_vec;
		std::stringstream ss(line);
		int num;
		while(ss >> num){
			line_vec.push_back(num);
		}
		if(check_level(line_vec)){
			res++;
		}else{
			std::vector<int> subvec = {line_vec.begin() + 1, line_vec.end()};
			if(check_level(subvec)){
				res++;
				goto nest;
			}
			for(int i = 1; i<line_vec.size()-1; ++i){
subvec = {line_vec.begin(), line_vec.begin() + i};
subvec.insert(subvec.end(), line_vec.begin()+i+1, line_vec.end());
			
if(check_level(subvec)){
	res++;
	goto nest;
}
			}
subvec = {line_vec.begin(), line_vec.end()-1};
			
if(check_level(subvec)){
	res++;
	goto nest;
}
		}



		}
				
	std::cout << res << std::endl;
	return 0;

}
