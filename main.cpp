#include <iostream>
#include <stack>
bool isvalid(std::string s) ;
int main (int argc, char *argv[]) {
	
	while (true)
	{
		std :: string x ; 
		std :: cin >> x ; 
		std :: cout << isvalid(x);
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
