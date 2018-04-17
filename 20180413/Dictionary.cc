///
/// @file    Dictionary.cc
/// @author  ICIOfg
/// @date    2018-04-13 22:24:51
///
#include <string.h>
#include <fstream> 
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
using std::istringstream;
using std::ostringstream;
using std::stringstream;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
using std::vector;
using std::cin;
#if 1
typedef struct Dict
{
	string  w;
	int count;
	//	struct Dict * next;
}Dic, *pdic;

#endif

class Dictionary
{
	public:

		void read(const std::string& filename);
		void store(const std::string & filename);

	private:

		vector <Dic> word;
		//int count;
		//Dictionary * next;
};

void Dictionary::read(const std::string & filename)
{	

	ifstream ifs(filename.c_str());
	if(!ifs)
	{
		cout << "open file error" << endl;
		return ;

	}

	string line;
	string n;
	//	int i =0;
	int way=0;
	while(getline(ifs, line))
	{
		istringstream iss(line);
		Dic ve;
		//	vector <Dic> ::iterator it;
		while(iss >> n)
		{
			way =1;
			for(size_t idx=0; idx!= word.size(); ++idx)
			{
				if(word[idx].w == n)
				{
					++word[idx].count;
					way = 0;
					break;
				}
			}
			if(way)
			{
				ve.w = n;
				ve.count =1;
				word.push_back(ve);
			}
		//	ve.w = n;
//			cout << "ve.w= " << ve.w << endl;
		//	ve.count =1;


			//	for(auto & number : word)
			//	{
		//	word.push_back(ve);
		}
	}
		//	for(it = word.begin(); it!= word.end(); ++it)
		//	{

		//		cout << *it << endl;
		//	}
		//	for(auto & number : word)
		//
#if 0
		for(size_t idx=0; idx!= word.size(); ++idx)
		{
			cout << word[idx].w << "  " << word[idx].count
				<< endl;
		}
#endif
	ifs.close();		
}



	void Dictionary::store(const std::string & filename)
	{
		ofstream ofs(filename.c_str(),std::ios::out);
#if 0
		cout <<  "ofs.badbit:" << ofs.bad() << endl;
		cout <<  "ofs.failbit:" << ofs.fail() << endl;
		cout <<  "ofs.eofbit:" << ofs.eof() << endl;
		cout <<  "ofs.goodbit:" << ofs.good() << endl;
#endif
		if(!ofs)
		{
			cout << "ofstream open error" << endl;
			return;
		}


		for(size_t idx=0; idx!= word.size(); ++idx)
		{
			ofs << word[idx].w << "  " << word[idx].count	
				<< endl;
		}
		ofs.close();
	}










	int main(void)
	{
		Dictionary bib;
		string filename; //="The_Holy_Bible.txt";
		cin >> filename;
		bib.read(filename);

		filename = "diccionario.txt";

		bib.store(filename);

#if 0	
		ifstream ifs("The_Holy_Bible.txt");
		if(!ifs)
		{
			cout << "ifstream open error" << endl;
			return -1;
		}

		string line;
		string w;
		//	string n="how" ;
		vector <string> words;
		//	words.push_back(n);
		cout << words[0] <<endl;
		cout << words[0].length() << endl;

		getline(ifs, line,'\n');
		istringstream iss(line);
		while(iss >> w)

		{
			words.push_back(w);
			cout << w << endl;
		}
#endif

#if 0
		do{
			getline(ifs, line,'\n');

			cout << line << endl;
			iss >> w;
			words.push_back(w);
			cout << w << endl;
		}while(iss != NULL);
		ifs.close();
#endif
		return 0;
	}





