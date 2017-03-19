#include <iostream>
#include <fstream>
#include <ctime>

void Read(),Write();
std::string line;

int main()
{
	std::string choise;
	std::cout << "Would you like to write or read the Journal?" << std::endl;
	std::cin >> choise;
	std::cin.ignore();
	switch (tolower(choise[0])){
		case ('w'):{
			Write();
			break;
		}
		case ('r'):{
			Read();
			break;
		}
		default :{
			std::cout << "Something went wrong" << std::endl;
		}
	}


	return 0;
}

void Read()
{
	std::ifstream myfile("./test.txt");
	std::cout << "\x1B[2J\x1B[H"; //clear the screen
	if (!myfile.is_open()){
		std::cout << "I can't find the file to read from." << std::endl;
		return;
	}
	while ( getline (myfile,line))
	{
		std::cout << line << std::endl;
	}

}

void Write()
{
	std::string lines;
	std::string total;
	std::cout << "\x1B[2J\x1B[H"; //clear the screen
	std::cout << "Write your thoughts or/and what you did today :D" << std::endl;
	std::ofstream myfile("./test.txt",std::ios_base::app); 
	while (true) {
		getline(std::cin, lines);
		if (lines.empty()){
			break;
		} else {
			total = total + lines + "\n";
		}
	}
	time_t t; // Current time
	time (&t);
	myfile << std::endl << ctime (&t) << "-\"" << total << "\"" << std::endl;
}

