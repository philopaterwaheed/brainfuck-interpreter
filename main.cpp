#include <iostream>
#include <vector>
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

std::string brainLuck(const std::string &code) {
  std :: string output = ""; 
  char input ;
  int remain =0 ; //for [] jumping
  std:: vector <int> arr (1,0); 
  int codeptr = 0; 
  for (int i =0 ; i < code.size() ; i++)
    {
       switch(code[i]){
         case '>':
          codeptr++;
	  if (codeptr >= arr.size()) 
		  arr.push_back(0);

          break;
         case '<':
           codeptr--;
	   if (codeptr < 0 )
	   {
		   std:: cerr << "run time error trying to aceess invalid pointer";
		   return  "";
	   }
          break;
         case '+':
          (arr[codeptr])++;
          if (arr[codeptr] > 255)
            {
            arr[codeptr] = 0  ;  
            }
         break;
         case '-':
          (arr[codeptr]) -= 1;
          if (arr[codeptr] < 0){
            arr[codeptr] = 255  ;
            }
          break;
         case '.':
          output+=(static_cast<char> (arr[codeptr]) );
          break;
         case ',':
	   if (std::cin >> input && input >= 0 && input <= 255)
	   {
		arr[codeptr] = input;
	   }
          break;
         case '[':
           if (arr[codeptr] == 0  )
            {
             while (code[i] != ']' && remain != 0 )
		{
		       i++ ; 
			if (code[i] == '[')
				remain ++ ; 
			if (code[i] == ']' && remain > 0)
				remain -- ; 
		}
	    }
          break;
         case ']':
           if (arr[codeptr] > 0  )
             {
               while (code[i] != '[')
		{
			i -- ;  
			if (code[i] == ']')
				remain ++ ; 
			if (code[i] == '[' && remain > 0)
				remain -- ; 
             	}
	     }
           
          break;
           }
    //std :: cout << output << " " ; 
    }
  return output;
}
