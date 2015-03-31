#include <boost/filesystem.hpp>
#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#include <sstream>
#include <md5.h>

using namespace std;
using namespace boost::filesystem;
int main(int argc, char* argv[1])
{
	setlocale(LC_ALL, "russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Enter the directory path:\n" << std::endl;
	path dir_path;
	cin >> dir_path;
 ofstream f("AbFiles.tsv");
 f << "Name\t\t\tPath\t\t\t\t\tSize\t\t\t\t\t\t\tHash" << endl;

 if (is_directory(dir_path) && exists(dir_path))
 {

	 recursive_directory_iterator end;
	 for (recursive_directory_iterator it(dir_path); it != end; ++it)
		 if (is_regular_file(it->path()))
		 {

			 stringstream result;
			 string a;

			 ifstream myfile;
			 myfile.open(it->path().string(), ios::binary);
			 result << myfile.rdbuf();
			 a = result.str();
			 f << it->path().filename() << "\t\t" << it->path() << "\t\t" << file_size(it->path()) << "\t\t"  <<"\t\t" <<get_md5(a)<< endl;
		 } 
 }
 else 
 {
	 cout << dir_path << " does not exist\n";
 }
 

	f.close();
	
	
	
	system("pause");

}

