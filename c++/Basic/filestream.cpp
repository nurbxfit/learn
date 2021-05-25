#include<iostream>
#include<cstdlib>
#include<sstream>
#include<fstream> //--file stream

int main(int argc, char** argv){
    //ofstream = output stream
    //ifstram = input stream
    std::ofstream toFileStream;
    std::ifstream fromFileStream;

    std::string myText = "Hello I will be written in a file";
    std::string fromFileText;

    //writing to file, if file not exist it get created, here we pipe, out and trunc,
    /// ios_base::out is for write, in for read to file, trunc is for delete content then write
    toFileStream.open("testoutstream.txt",std::ios_base::out | std::ios_base::trunc);
    if(toFileStream.is_open()){
        toFileStream << myText << " Plus an extra lines below"<< std::endl; //we write to that stream
        std::cout << "Write something: ";
        getline(std::cin,myText);
        toFileStream << myText;
        toFileStream.close();
    }

    fromFileStream.open("testoutstream.txt",std::ios_base::in);
    if(fromFileStream.is_open()){
        while (fromFileStream.good())
        {   //read a line into var, then read another line, overide the var
            getline(fromFileStream,fromFileText); 
            std::cout << fromFileText << std::endl;

        }
        fromFileStream.close();
        
    }

    

    return 0;
}