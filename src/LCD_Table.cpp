#include "LCD_Table.h"
#include <stdlib.h>
#include <iostream>
#include <ctype.h>
using namespace std;


LCD_Table::LCD_Table()
{
	fTableSize=37;
}

LCD_Table::~LCD_Table()
{
}

void LCD_Table::Run()
{
	cout<<"\t\t\tLCD TABLE\n";
	ofstream out("Table Binary.txt",ios::out);
	pt0:
	cout<<"\nChoose from the options given below\n\n";
	cout<<"1.\tRun Event\n";
	cout<<"2.\tHelp(?)\n";
	cout<<"3.\tAbout\n";
	cout<<"4.\tExit\n\n";
	char ch0;
	cin.clear();
	cout<<"LCD:>";
	cin>>ch0;
	switch(ch0)
	{
		case '1':this->Engine(out);
		goto pt0;
		break;
		case '2':this->Help();
		goto pt0;
		break;
		case '3':this->About();
		goto pt0;
		break;
		case '4':goto pt1;
		break;
	}
	pt1:
	cout<<"\nExit? Y/N\n\n";
	char ch;
	cin.clear();
	cout<<"LCD:>";
	cin>>ch;
	ch=tolower(ch);
	if(ch=='y')
	{
		cout<<"\nContact us:\n";
		cout<<"08139278033\n";
		cout<<"kosmaz2009@yahoo.com\n\n";
		system("pause");
		return;
	}
	else
	goto pt0;
}

void LCD_Table::Engine(ofstream& out) const
{
    Table LCD_Table[]={
    {'a',"1-------","10001000"},{'b',"1-------","1-------"},{'c',"10100111","11000110"},
    {'d',"1-------","1-------"},{'e',"1-------","10000110"},{'f',"1-------","10001110"},
    {'g',"1-------","1-------"},{'h',"10001011","10001001"},{'i',"11111011","11111001"},
    {'j',"11110011","11110001"},{'k',"1-------","1-------"},{'l',"11100111","11000111"},
    {'m',"1-------","1-------"},{'n',"10101011","1-------"},{'o',"10100011","11000000"},
    {'p',"1-------","10001100"},{'q',"1-------","1-------"},{'r',"10101111","1-------"},
    {'s',"1-------","10010010"},{'t',"10000111","1-------"},{'u',"11100011","11000001"},
    {'v',"1-------","1-------"},{'w',"1-------","1-------"},{'x',"1-------","1-------"},
    {'y',"1-------","10010001"},{'z',"1-------","1-------"},{'0',"11000000","11000000"},
    {'1',"11111001","11111001"},{'2',"10100100","10100100"},{'3',"10110000","10110000"},
    {'4',"10011001","10011001"},{'5',"10010010","10010010"},{'6',"10000010","10000010"},
    {'7',"11111000","11111000"},{'8',"10000000","10000000"},{'9',"10011000","10011000"}
    };
  pt0:
  Table* Anode_Cathode;
  cout<<"\nChoose from the options given below\n\n";
  cout<<"1.\tCommon Anode\n";
  cout<<"2.\tCommon Cathode\n\n";
  pt1:   
  cout<<"LCD:>";
  cin.clear();
  char input;
  cin>>input;
  if(input=='1')
  Anode_Cathode=LCD_Table;
  else
  if(input=='2')
  Anode_Cathode=this->CommonCathode(LCD_Table);
  else
  if(input=='3')
  exit(1);
  else{
  	cout<<"Please choose from the options given above\n";
	  goto pt1;  	
  }  

cout<<"LCD:>";
  char in;
  cin.clear();
  do{
  	    cin>>in;
        this->Compare(in,Anode_Cathode,out);
    }
  while(in!='.');
  
  cout<<"\nContinue? Y/N\n"<<endl;
  cout<<"LCD:>";
  char ch;
  cin.clear();
  cin>>ch;
  ch=tolower(ch);
  if(ch=='y')
  goto pt0;
  else{
  	if(input==2)
  delete Anode_Cathode;
  return;
  }
}

void LCD_Table::Compare(char& character,const Table LCD_Table[],ofstream& out) const
{
    char temp=tolower(character);
    for(int i=0;i<fTableSize;i++)
	{
        if(temp==LCD_Table[i].character){
            if(!isupper(character)){
             cout<<LCD_Table[i].character<<"\t"<<LCD_Table[i].LCDSmall<<endl;
             cout<<"****************\n";
             out<<LCD_Table[i].character<<"\t"<<LCD_Table[i].LCDSmall<<endl;
             out<<"*****************\n";
            }
	      else{
           cout<<(char)toupper(LCD_Table[i].character)<<"\t"<<LCD_Table[i].LCDBig<<endl;
           cout<<"****************\n";
           out<<(char)toupper(LCD_Table[i].character)<<"\t"<<LCD_Table[i].LCDBig<<endl;
           out<<"*****************\n";
	      }
	    }
	}
	return;
}


Table* LCD_Table::CommonCathode(const Table OriginalTable[]) const
{
	Table* newtable=new Table[fTableSize];
	for(int i=0;i<fTableSize;i++)
	{
        newtable[i].character=OriginalTable[i].character;
        for(int k=0;k<ArrayLimit;k++){
        	if(OriginalTable[i].LCDSmall[k]=='0')
        	newtable[i].LCDSmall[k]='1';
        	else 
            if(OriginalTable[i].LCDSmall[k]=='1')      //nested if statement for LCDSmall array element
        	newtable[i].LCDSmall[k]='0';
        	else
        	if(OriginalTable[i].LCDSmall[k]=='-')
        	newtable[i].LCDSmall[k]='-';
		}
    }
    
    for(int i=0;i<fTableSize;i++)
		for(int k=0;k<ArrayLimit;k++){
			if(OriginalTable[i].LCDBig[k]=='0')
        	newtable[i].LCDBig[k]='1';
        	else
        	if(OriginalTable[i].LCDBig[k]=='1')        //nested if statement for LCDBig array element
        	newtable[i].LCDBig[k]='0';
        	else
        	if(OriginalTable[i].LCDBig[k]=='-')
        	newtable[i].LCDBig[k]='-';
		}        
	return newtable;             
}


void LCD_Table::About()
{
	cout<<"This program involves the use of an already genenrated table of binary\n";
	cout<<"values of an LCD component in electronic devices for supported characters\n";
	cout<<"ranging from a-z(uppercase and lowercase) and numbers ranging from 0-9.\n";
	cout<<"Not all alphabets both upper and lower case are supported. It comprises of\n";
	cout<<"both the common anode table and the common cathode table which have been\n";
	cout<<"genrated already for you for easy usage when writing exams using your personal\n";
	cout<<"laptop and while in the exam hall then it is at USERS OWN RISK if caught using\n";
	cout<<"the program as an aid in the exam hall\n";
	cout<<"\t\tENJOY\n\n";
	system("pause");
	return;
}

void LCD_Table::Help()
{
	cout<<"A string of characters and numbers is allowed\n";
	cout<<"Use a fullstop(.) to show the end of every input to avoid errors\n\n";
	cout<<"Please be mindful of the input buffer cause if not carefully handled in\n";
	cout<<"terms of keyboard input will lead to program malfunction. Obey whatever\n";
	cout<<"instruction you will encounter while using the program strictly to avoid\n";
	cout<<"program malfunction or misbehaviour.     -k0$m@3-\n\n";
	system("pause");
	return;
}
