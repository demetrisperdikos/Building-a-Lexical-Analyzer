#include <fstream>
#include <string>
#include "lex.h"
#include <iostream>
#include <map>
#include <list>


using namespace std; 

int main(int argc, char* argv[]){

LexItem toke /*lex item */;


int number_ofLine, startToken = 0 /*variable decleration*/; 
number_ofLine = 1 /*num of lines is set to 1*/;

int looper=1; bool idnt; bool iConst;
bool rConst; /*declare rconst*/
bool sConst; /*declare sconst*/
bool boVal /*declare boval*/;
bool tr;


tr =true; 
iConst = false /*set to false*/;
boVal= false /*set to false*/;
rConst = false /*set to false*/;
sConst = false /*set to false*/;
idnt = false/*set to false*/;


list<string> consti;
list<string> play;
list<string> iden;
list<string> connstantl;
list<int>constanti; 
list<string> dentifi;
list<double>constantr;


if (argc <= 1)
{
    cout << "NO SPECIFIED INPUT FILE NAME."; 
    cout << endl;
    exit(1);
}

ifstream infile(argv[1]);

while(looper<argc){
    
string marker(argv[looper]);
                      
    if(tr){
    if(marker =="-v"/*flag is set to iconst*/){
        boVal = !boVal;
    }
    else if(marker =="-sconst"/*flag is set to sconst*/){
        sConst = !sConst;
    }
    
    else if(marker =="-iconst"/*flag is set to iconst*/){
        iConst = !iConst;
    }
    
    else if(marker =="-ident" /*flag is set ident*/){
        idnt = !idnt;
    }

    else if(marker =="-rconst"/*flag is set to rconst*/){
        rConst = !rConst;
    } 
    
    
    
    
                            
    else if (marker/*flag aray -*/[0] == '-' ){
        cerr << "UNRECOGNIZED FLAG " << marker;
        cout << /*space for format*/endl;
        exit(1);
    }
    
    
    else if (looper==/*File check, if we know what flag is*/argc-1){infile.open(marker);
        if(infile.is_open() == false)
        {
        cerr << "CANNOT OPEN the File "/*cannot open*/ << argv[1];
        cout << endl;
        exit(1/*exit*/);
        }
        
        ifstream infile; infile.peek(/*ifstream and infile*/);
        if (infile.eof()){
            cout << "Lines: 0" <<endl;
            exit(1);
        }  
                                                                    
    }
    
    else if(argv[2]/*is not equal to -*/[0] != '-') {
        cout << /*print that only one file name is allowed*/ "ONLY ONE FILE NAME ALLOWED.\n";
        exit(1);
    }
        looper = looper + 1;
    }
    
}

if (infile.is_open()/*is open infile*/ &&/*and*/ infile.good(/*infile is .good*/)) {
    
    while((toke = getNextToken(infile, number_ofLine)) != DONE && toke != ERR){               
        
    startToken = startToken + 1;

        
        if(boVal){
            cout<<toke;
            cout<<endl;
        }
        if(toke.GetToken()/*Ident==*/ == IDENT){
            dentifi.push_back/*dentifi token*/(toke.GetLexeme());
        }
        if(toke.GetToken()/*RCONST ==*/ == RCONST){
            constantr.push_back(stod/*const token*/(toke.GetLexeme()));
        }
        if(toke.GetToken()/*SCONST ==*/ == SCONST){
            connstantl.push_back(/*constl lex*/toke.GetLexeme());
        }  
        if(toke.GetToken()/*ICONST*/ == ICONST){
            constanti.push_back(stoi/* const push back again with token*/(toke.GetLexeme()));
        }
        
    }
}


if(/*if that checks*/toke.GetToken()== ERR /*get token*/){
    cout<< "Error in line " << number_ofLine << " (" <<toke.GetLexeme()<< ")";
    cout <<endl; 
    exit(1);
}

cout << "Lines: "/*cout lines*/ << number_ofLine;
cout << endl;
if (startToken != 0){cout << "Tokens: " << startToken << endl;}
    
if (sConst/*sconst true?*/){
    if (!connstantl.empty())
    connstantl.sort(); 
    cout << "STRINGS:" <<endl;
    
        for (string j : connstantl)
            cout << '\'' << j /*display \ then the string of j*/ << '\'' << endl; 
}
if (iConst/*iconst true?*/){
    if (!constanti.empty()) 
        constanti./*sort unique*/sort();
    constanti.unique();
    cout << "INTEGERS:"/*display integers*/ <<endl;
    for (int j : constanti)
        cout << j << endl;
}

if (rConst/*rconst true?*/){
    if (!constantr.empty())
    cout << "REALS:" <<endl;
    constantr.sort(/*constant is sorted*/);
        for (double /*for loop again*/ j : constantr) cout << j << endl;
}

if (idnt/*idnt true?*/){
    if (!dentifi.empty());
    cout << "IDENTIFIERS:"/*display identifier word*/<<endl;
    
    string /*empty string*/sto = "";
    dentifi./*dentifi sort*/sort();
    dentifi./*dentifi unque*/unique();
    
    for (/*for string j is then*/string j : dentifi)
    {
    cout << sto /*cout for the sto*/ << j;
    sto = ", ";
        
    }
    
    cout << endl /*cout end the line*/;
    
}

exit(1);
}