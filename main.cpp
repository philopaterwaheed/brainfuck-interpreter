#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <system_error>
//funcs 
bool isvalid(std::string s) ;


// vars 
std :: string file_name ; 

int main (int argc, char *argv[]) {

	if (argc  < 2 )
	{
		std::cerr << "Invalid !! there is no file neame !\n";
		return -1 ; 
	}
	else 
		file_name = argv[1];
	
	//file name checking 

	if (std::string extintion (file_name.end ()- 3 , file_name.end()); extintion != ".bf")
		std:: cout << extintion;
	else 
		std:: cout << extintion << "e" ; 

	return 0;
}
bool isvalid(std::string s) {
	std ::stack<char> stack ;  
        for (char c : s) { 
		if (c == '[')
			stack.push(c);
		else if ( c == ']')
		{
			if (stack.empty())
				return false;
			else 
				stack.pop();
		}
        }
        return stack.empty();
    }
