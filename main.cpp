#include <iostream>
#include <fstream> // for file reading
#include <filesystem>// to check if it is there ;
#include <stack>
#include <string>
#include <system_error>
//funcs 
bool isvalid(std::string s) ;
void operate(std :: string s);

// vars 
std :: string file_name ; 
std::ifstream file ;
std::string contains ; 

int main (int argc, char *argv[]) {

	// while (true) {
	// 	std :: string x ; 
	// 	std:: cin >> x; 
	// 	std :: cout << isvalid(x);
	// }
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
			file = std::ifstream(file_name); 
			if (file.is_open())
			{
				while (file)
				{
					std :: string temp ; 
					std::getline(file , temp);
					contains += temp ; 
				}
			}
			operate(contains); // file is ready to be operated on ; 
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

void operate(std :: string s){
	if (!(isvalid(s)))
	{
		std ::cout << "synatx error unmatched parenthese";
		return;
	}
}
