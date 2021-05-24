#include<iostream>
#include<string>

int main(int argc , char**argv){

    std::string myStr = "Hello";
    std::cout << myStr << std::endl;
    std::cout << "First Char: " << myStr.front() << std::endl;
    std::cout << "Last Char: " << myStr.back() << std::endl;
    std::cout << "Third index: " << myStr[3] << std::endl;

    //copy strings, from index
    std::string myStr2(myStr, 0);
    std::cout << "copy: " << myStr2 << std::endl;

    //concat strings;
    std::string myStr3(myStr + " world\n");
    std::cout <<"3: " << myStr3;
    std::cout << myStr + " Human\n";

    //append to string.
    myStr2.append(" eveyone\n");
    std::cout << "copy new: " << myStr2; 

    //delete char in strings
    // myStr3.erase(start_index,end_index)
    myStr3.erase(6);
    std::cout << "3: " << myStr3 << "\n";

    //string length
    std::cout << "3 length: " <<myStr3.length() << std::endl;

    //finding words in string. npos == end of strings.
    std::string newStr("Find me from my index");
    std::string searchStr("me");
    if(newStr.find(searchStr) != std::string::npos){
        std::cout << "Found at: "<< newStr.find(searchStr) << std::endl;

        //substring using substr(start_index,end_index);
        std::cout << "Found: " << newStr.substr(newStr.find(searchStr),searchStr.length()) << std::endl;
    }

    
    //check if letter,number or space isalpha function return nonzero value if true.
    std::cout << "is 'F' a letter ?: " << isalpha('f') << std::endl;
    std::cout << "is '1' a letter ?: " << isalpha('1') << std::endl;
    std::cout << "is 'F' a number ?: " << isdigit('f') << std::endl;
    std::cout << "is '1' a number ?: " << isdigit('1') << std::endl;
    std::cout << "is ' ' a space ?: " << isspace(' ') << std::endl;

    
    return 0;
}