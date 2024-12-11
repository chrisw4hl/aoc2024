#include<iostream>
#include<string>
#include<sstream>



int main(){

	std::string line = "";
	std::string hold = "";
	int res = 0;
	int diff = 0;
	int cur_line = 0;
	bool increasing = false;

	std::freopen("day2.txt", "r", stdin);
        // the following line opens the input file
nest:	
	while(std::getline(std::cin, line)){
		std::stringstream ss_line(line);
		ss_line>>hold;
		cur_line = std::stoi(hold);
		ss_line>>hold;
		diff = cur_line - std::stoi(hold);
		cur_line = std::stoi(hold);
		if((diff > 3)||(diff < -3)){
			goto nest;
		}
		if(diff < 0){
			increasing = true;
		}else if(diff == 0){
			goto nest;
		}else{
			increasing = false;
		}


		while(ss_line >> hold){
			diff = cur_line - stoi(hold);
			cur_line = std::stoi(hold);

			if ((increasing == true) && (diff > 0)){
				goto nest;
			}else if((increasing == false) && (diff < 0)){
				goto nest;
			}else if((diff > 3) || (diff < -3) || (diff == 0)){
				goto nest;
			}
		}

		res++;




		}
				
	std::cout << res << std::endl;
	return 0;

}
