#include <iostream>
#include <fstream> // for file reading
#include <filesystem>// to check if it is there ;
#include <stack>
#include <string>
#include <system_error>
//funcs 
bool isvalid(std::string s) ;


// vars 
std :: string file_name ; 
std::fstream file ;
std::string contains ; 

int main (int argc, char *argv[]) {

	if (argc  < 2 )
	{
		std::cerr << "Invalid !! there is no file neame !\n";
		return -1 ; 
	}
	else 
		file_name = argv[1];
	
	//file  checking 
	if (std ::filesystem::exists(file_name)) //checks if the file is there
	{
		if (std::string extintion (file_name.end ()- 3 , file_name.end()); extintion != ".bf")  // file extintion checking
		{
			std::cerr << "wrong file no brainfuck file found!\n";
			return -1;
		}
		else 
		{

			file = std::fstream(file_name ,std::ios::out); 
			std :: cout << contains;
		}
	}
	else 
	{
		std:: cerr << "file does not exist\n";
		return -1;
	}
	

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
