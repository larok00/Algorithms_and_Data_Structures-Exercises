#include <fstream>
#include <cstdlib>

void copyfile(){
	
	ifstream infile;
	ofstream outfile;
	
	infile.open("");
	
	if( !infile.is_open() ){
		cout << "could not open input file" << endl;
		exit(EXIT_FAILURE);
	}
	
	outfile.open("");
	
	if ( !outfile.is_open() ){
		cout << "could not open output file" << endl;
		exit(EXIT_FAILURE);
	}
	
	int info;
	
	while (infile >> info){
		outfile << info
	}
	
	infile.close();
	outfile.close();
}
