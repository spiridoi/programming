//
//  main.cpp
//  tick tack toel
//
//  Created by daylin on 06/10/2015.
//  Copyright (c) 2015 daylin. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;


int size=9;

void printBoard (string board[],int size);

void makeMove ( string board[], int size,  string playern);

bool check (string board[],int size);



int main()
{
    string board[9]={"1","2","3","4","5","6","7","8","9"};
    string player1;
    string player2;
    string playern;
    string winner;
    bool win=false;
    
    
    cout<<"Let's play tick-tack-toe!"<<endl;
    
    printBoard (board,size);
    
    cout<< "Player one, please chose X or O."<<endl;
    cin>>player1;
    
    //cout<< player1;
    
    while (!((player1 == "X")||(player1=="O")))
        {
            cout<< "Player one, please chose X or O."<<endl;
            cin >>player1;
            
        }
    if(player1=="X")
           player2="O";
    else player2="X";
    
    
    //cout<<player1<<player2<<endl;
    
    
    playern=player1;
    int draw=1;
    
    
    while(!((win)||(draw>9)))
    {
        
        makeMove (board, size, playern);
        printBoard (board,size);
        win=check (board,size);
        winner=playern;
        if (playern==player1)
            playern=player2;
        else playern=player1;
        draw++;
    
    }
    
    if (win==true)
        cout<< "Player "<< winner <<" Wins!!!"<<endl;
    else
        cout<< "This game is a draw!!"<<endl;
    return 0;
}


void printBoard (string board [], int size)
{
    int j=1;
    
    for(int i=0;i<9;i++)
    {
        cout<<board[i];
        if(j%3==0)
            cout << endl;
        j++;
    }
}

void makeMove ( string board[], int size,  string playern)
{
    
    int n=0;
    
    cout<< "Player "<<playern<<", what is your move."<<endl;
    cin >> n;
    
    while (((n >9) || (n<1) || (board[n-1]=="X") || (board[n-1]=="O")))
        {
            cout << "Invalid move!"<<endl;
            cout<< "Player "<<playern<<", what s your move."<<endl;
            cin>> n;
        }
    if (playern=="X")
        board[n-1]="X";
    else
        board[n-1]="O";
    
}

bool check (string board[],int size)
{
    if  (board[0]==board[1]&&board[1]==board[2])
        return true;
    else if (board[3]==board[4]&&board[4]==board[5])
        return true;
    else if (board[6]==board[7]&&board[7]==board[8])
        return true;
    else if (board[0]==board[3]&&board[3]==board[6])
        return true;
    else if (board[1]==board[4]&&board[4]==board[7])
        return true;
    else if (board[2]==board[5]&&board[5]==board[8])
        return true;
    else if (board[0]==board[4]&&board[4]==board[8])
        return true;
    else if (board[2]==board[4]&&board[4]==board[6])
        return true;
    else
        return false;
    
}










