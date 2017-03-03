#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstdio>

using namespace std;

int check(const char &ch, const string &w)
{
	for(int i=0;i<w.length(); i++)
	{
		if(ch == w[i])
		{
			cout << "\nYou already entered that letter. Try another letter!";
			return 1;
		}
	}
}
/*int dash(const string &temp, const int &l)
{
	int flag = -1;
	for(int i=0;i<l;i++)
	{
		if(temp[i] == '_')
			flag = 1;
	}
	if(flag == -1)
		return 0;
	return 1;
}*/
int printstr(const string &temp, const int &l)
{
	for(int i=0;i<l;i++)
	{
		cout << temp[i] << " ";
	}
}
int game(int &trial, const int &l, const char &ch, const string &org, string &temp, int &NOD, string &w)
{
	int flag = -1;
	for(int i=0; i<l; i++)
	{
		tolower(org[i]);
			if(ch == org[i])
			{
				//cout << "\nCORRECT!";
				if(check(ch, w))
				{
					continue;	
				}
				flag = 1;
				NOD--;
				temp[i] = ch;
			}
	}
	if(flag == -1)
	{
			trial--;
			
				cout << "\nWRONG GUESS!";
			
	}
	cout << "\nNumber of trials left : " << trial;
	cout << "\nString at hand : ";
	printstr(temp, l);
}
int main()
{
	string org, temp;
	char a;
	cout << "H A N G M A N \n\nRule of the game : Enter / instead of space while entering movie name\n\nEnter the name of the movie : ";
	//cin.getline(org);
	cin >> org;
	int l, trial=10, NOD;
	l=org.length();
	//clrscr();
	system("CLS");
	char ch;
	cout << "\nThe number of trials is 10";
	for(int i=0;i<l;i++)
	{
		if(org[i] == '/' )
		{
			temp+='/';
			NOD--;
		}
		else
			temp+='_';

	}

	// THis is a test commit line fuck you bastards. 
	//temp.assign(l, '_');
	NOD = l;
	string w = " "; //= '\0';
	cout << "\nAll set. Let's start!";
	do
	{
		cout << "\nGuess a letter : "; 
		cin >> ch;
		w+=ch;
		game(trial, l, ch, org, temp, NOD, w);
		cout << "\n\n";
	}while(trial > 0 && NOD > 0);
	if(trial == 0)
	{
		cout << "\nYou let the man die. Better luck next time! O.O\nTHE END.";
	}
	else
		cout << "\nCongratulations! You made it alive!";
	return 0;
}