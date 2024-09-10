//1. Write a C++ program to create a new text file and write your name,and marks
//obtained into it.

#include<iostream>
#include<fstream>
using namespace std;

main()
{
	ofstream file("pratibha.txt");
	
	if(file.is_open()){
		file<<"name:pratibha_chopade"<<endl;
		file<<"marks obtain is 80:"<<endl;
		
			file.close();
	cout << "Data successfully written to file 'pratibha.txt'." << endl;
	}
 else {
       //It stands for "character error
        cerr << "Error: Could not open the file." << endl;
        return 1;
    }
	}

