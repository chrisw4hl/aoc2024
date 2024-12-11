#include<string>
#include<sstream>
#include<iostream>
using namespace std;

int main(){

	freopen("./day3.txt","r",stdin);
	string input="";
	string token="";
	bool enable=true;
	long long res = 0;
	size_t pos = 0;
	while(getline(cin,input)){
		//std::cout<<input<<std::endl;
		if(enable == false){
			size_t do_pos_init = input.find("do()");
			input.erase(0,do_pos_init+3);
			enable=true;

		}
		while((pos = input.find("mul(")) != std::string::npos){
			size_t dont = input.find("don't()");
			if(pos > dont){
				size_t do_pos = input.find("do()");
				if(do_pos == std::string::npos){
					enable = false;
					break;
				}else{
					input.erase(0,do_pos+3);
					continue;
				}
			}
			//	std::cout<<input<<std::endl;
			token=input.substr(pos+4,8);
			//	std::cout<<token<<std::endl;
			size_t mid = token.find(",");
			size_t end = token.find(")");
			int num1=0;
			int num2=0;

			if((end<mid)||(end==std::string::npos)){
				input.erase(0,pos+3);
				continue;
			}	
			try{
				num1=stoi(token.substr(0,mid));
			}catch(std::invalid_argument const& ex){
				input.erase(0, pos+3);
			}
			try{
				num2=stoi(token.substr(mid+1,end-mid-1));
			}catch(std::invalid_argument const& ex){
				input.erase(0, pos+3);
			}
			//	std::cout<<num1<<" "<<num2<<std::endl;
			input.erase(0, pos+3);	
			//	std::cout<<input<<std::endl;

			res += (long)num1 * num2;
		}
		std::cout<<res<<std::endl;
	}
	std::cout<<res<<std::endl;
	return 0;
}
