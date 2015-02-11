#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std ;

bool Compare(string a, string b);

int main(){

	extern char **environ; // needed to access your execution environment
	int k = 0; 
	while (environ[k] != NULL) 
		{
			cout << environ[k] << endl;
			k++; 
								
		}

	char a[600];
	string temp = " ";
	bool notFound = false;
	bool isWord = false; 
	int total = 0;
	vector <string> vec1(0);
	vector <int> vec2(0);
	for (int i= 0; i<k; i++)
	{
		

		strcpy_s(a, (strlen(environ[i])+1), environ[i]);
		int count=0;
		for(int j= 0; j<strlen(environ[i])+1; j++)
		{

			if(environ[i][j]!=' ' && environ[i][j]!=':' && environ[i][j]!='\\' && environ[i][j]!='\n' && environ[i][j]!='='&& environ[i][j]!= ';'&& environ[i][j]!= '~' && environ[i][j]!= '.' && environ[i][j]!= '<' && environ[i][j]!= '>')
			{
				if(isalnum(environ[i][j]) && (isalpha(environ[i][j])))
				{
					temp +=environ[i][j];
				
				}

			}
			else 
			{
				total++;
				notFound=true;
				for (int i=0; i<vec1.size(); i++)
				{
					if(vec1[i] == temp )
					{
						vec2[i]++;
						
						notFound = false;
					}
					
				}

				if(notFound)
					{
						if(temp.size() >=2)
						{
							isWord = false;
							for(int i=0; i < temp.size(); i++)
							{
								if(isalpha)
								{
									isWord =true;
									
								}
							}
							if(isWord == true)
								{
									vec1.push_back(temp);
									vec2.push_back(1);
									temp = "";
								}

						
						}
					}
			}
		
		}
	}
	cout<<endl;
	for(int i= 0 ; i<vec2.size(); i++){
	cout << vec1[i] << " is used " << vec2[i] << " times" << endl;
	cout << endl;
	}
	cout<<endl;
	cout<<"There are total of "<< total <<" words" << endl;

	//New Task;
	char searchInput[40];


	cout<<endl;
	cout << "Please input the word you want to search" << endl;
	cin.getline (searchInput, 40);
	int amount = 0;

	while (!Compare(searchInput , "END"))
	{
		char *temp = new char[(strlen(searchInput) +1)];
		for (int c = 0; c < k; c++)
		{
			if (strlen(environ[c]) >= strlen(searchInput))
			{
				for (int i= 0; i < (strlen(environ[c])- strlen(searchInput)); i++)
				{
					for (int j = 0; j < strlen(searchInput); j++)
						{
					
						temp [j] = environ[c][i+j];
					
						}

					temp[strlen(searchInput)]= '\0';
			
					if (Compare(searchInput, temp) == true) amount++;

				}
			}
		}
		delete [] temp;
		cout<< searchInput << " occurs " << amount << " times " << endl;
		amount = 0;
		cout << "Would you like to search another word" << endl;
		cin.getline(searchInput , 40); 

	}
			
	cin.get();
	return 0;
}

bool Compare(string input, string exsist) 
{

	for (int i =0; i<input.size(); i++)
	{
		input[i] = tolower(input[i]);
	}

	for (int i =0; i<exsist.size(); i++)
	{
		exsist[i] = tolower(exsist[i]);
	}
	if (exsist == input)return true;
	else return false;
}