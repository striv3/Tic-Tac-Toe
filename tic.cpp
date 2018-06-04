#include"tic_tac.hpp"
#include<iostream>
#include<string>
#include<random>
#include<ctime>
#include<iomanip>
using namespace std;
extern string board[3];
int player_Move()
{
    unsigned n;
    cin>>n;
    --n;
    unsigned i=n/3,j=n%3;
    if(board[i][j]=='\0')
        board[i][j]='X';
    else
        {cout<<"\nInvalid Move.Try Again";
        player_Move();}
    return (n+1);
}
void Move(unsigned i,unsigned j)
{
    if(board[i][j]=='\0')
        board[i][j]='O';
    else
        cout<<"\nInvalid Move.Try Again";
    current_board();
}
int defend()
{
  if(win()==0)
  {for(auto i=0;i!=3;++i)
    {//cout<<"ok";
        if(board[i][0]!='\0' && board[i][0]==board[i][1] && board[i][2]=='\0')
            {Move(i,2);return 1;}
        if(board[i][1]!='\0' && board[i][1]==board[i][2] && board[i][0]=='\0')
            {Move(i,0);return 1;}
        if(board[i][0]!='\0' && board[i][0]==board[i][2] && board[i][1]=='\0')
            {Move(i,1);return 1;}

    }
    for(auto j=0;j!=3;++j)
    {
        if(board[0][j]!='\0' && board[0][j]==board[1][j] && board[2][j]=='\0')
            {Move(2,j);return 1;}
        if(board[1][j]!='\0' && board[1][j]==board[2][j] && board[0][j]=='\0')
            {Move(0,j);return 1;}
        if(board[0][j]!='\0' && board[0][j]==board[2][j] && board[1][j]=='\0')
            {Move(1,j);return 1;}
    }
    //For Primary Diagonal
    if(board[0][0]!='\0' && board[0][0]==board[1][1] && board[2][2]=='\0')
        {Move(2,2);return 1;}
    if(board[1][1]!='\0' && board[1][1]==board[2][2] && board[0][0]=='\0')
        {Move(0,0);return 1;}
    if(board[0][0]!='\0' && board[0][0]==board[2][2] && board[1][1]=='\0')
        {Move(1,1);return 1;}
    //---------------------------------For Secondary Diagonal
    if(board[0][2]!='\0' && board[0][2]==board[1][1] && board[2][0]=='\0')
        {Move(2,0);return 1;}
    if(board[1][1]!='\0' && board[1][1]==board[2][0] && board[0][2]=='\0')
        {Move(0,2);return 1;}
    if(board[0][2]!='\0' && board[0][2]==board[2][0] && board[1][1]=='\0')
        {Move(1,1);return 1;}
    return 0;
  }
  return 1;
}
int win()
{
    for(auto i=0;i!=3;++i)
    {
        if(board[i][0]=='O' && board[i][1]=='O' && board[i][2]=='\0')
            {Move(i,2);return 1;}
        if(board[i][1]=='O' && board[i][2]=='O' && board[i][0]=='\0')
            {Move(i,0);return 1;}
        if(board[i][0]=='O' && board[i][2]=='O' && board[i][1]=='\0')
            {Move(i,1);return 1;}

    }
        for(auto j=0;j!=3;++j)
    {
        if(board[0][j]=='O' && board[1][j]=='O' && board[2][j]=='\0')
            {Move(2,j);return 1;}
        if(board[1][j]=='O' && board[2][j]=='O' && board[0][j]=='\0')
            {Move(0,j);return 1;}
        if(board[0][j]=='O' && board[2][j]=='O' && board[1][j]=='\0')
            {Move(1,j);return 1;}
    }
    //For Primary Diagonal
    if(board[0][0]=='O' && board[1][1]=='O' && board[2][2]=='\0')
        {Move(2,2);return 1;}
    if(board[1][1]=='O' && board[2][2]=='O' && board[0][0]=='\0')
        {Move(0,0);return 1;}
    if(board[0][0]=='O' && board[2][2]=='O' && board[1][1]=='\0')
        {Move(1,1);return 1;}
    //---------------------------------For Secondary Diagonal
    if(board[0][2]=='O' && board[1][1]=='O' && board[2][0]=='\0')
        {Move(2,0);return 1;}
    if(board[1][1]=='O' && board[2][0]=='O' && board[0][2]=='\0')
        {Move(0,2);return 1;}
    if(board[0][2]=='O' && board[2][0]=='O' && board[1][1]=='\0')
        {Move(1,1);return 1;}
    return 0;
}

int check_win()
{
    if(board[0][0]==board[1][1] && board[0][0]==board[2][2])
    {
        if(board[0][0]=='O')
            {cout<<"\nI Win.\nIt was Pleasure playing with you.";return 1;}
        else if(board[0][0]=='X')
            {cout<<"\nCongratulations.You Win";return 1;}
    }
    if(board[2][0]==board[1][1] && board[2][0]==board[0][2])
    {
        if(board[0][0]=='O')
            {cout<<"\nI Win.\nIt was Pleasure playing with you.";return 1;}
        else if(board[0][0]=='X')
            {cout<<"\nCongratulations.You Win";return 1;}
    }
for(auto i=0;i!=3;++i)
        {
        if( (board[i][0]==board[i][1]) && (board[i][0]==board[i][2]) )
            {
        if(board[i][0]=='O')
            {cout<<"\nI Wiin.\nIt was Pleasure playing with you.";return 1;}
        else if(board[i][0]=='X')
            {cout<<"\nCongratulations.You Win";return 1;}
            }

    }
for(auto j=0;j!=3;++j)
    {
        if(board[0][j]==board[1][j] && board[0][j]==board[2][j])
            {
        if(board[0][j]=='O')
            {cout<<"\nI Win.\nIt was Pleasure playing with you.";return 1;}
        else if(board[0][j]=='X')
            {cout<<"\nCongratulations.You Win";return 1;}
            }

    }
return 0;
}
void Random_Sideways_Corner(unsigned i,unsigned j)
{
static std::default_random_engine e(time(0));
static std::uniform_int_distribution<unsigned> u(0,1);
u(e);
bool k=u(e);
unsigned complement_i,complement_j;
i==2?complement_i=0:complement_i=2;
j==2?complement_j=0:complement_j=2;
if(k)
board[complement_i][j]=='\0'?Move(complement_i,j):Move(i,complement_j);
else
board[i][complement_j]=='\0'?Move(i,complement_j):Move(complement_i,j);

}
void Random_Corner()
{
std::default_random_engine e(time(0));
std::uniform_int_distribution<unsigned> u(0,1);
u(e);
bool y=u(e),x=u(e);
if(y==1 && x==1)
    board[2][2]=='\0'?Move(2,2):Random_Corner();
else if(y==1 && x==0)
    board[2][0]=='\0'?Move(2,0):Random_Corner();
else if(y==0 && x==0)
    board[0][2]=='\0'?Move(0,2):Random_Corner();
else
    board[0][0]=='\0'?Move(0,0):Random_Corner();
}
void Random_Sideways(unsigned i,unsigned j)
{
    if(i!=1 && j!=1)
        Random_Sideways_Corner(i,j);

}
void board_number(){
cout<<setw(5)<<"|"<<setw(5)<<"|"<<"\n";
cout<<setw(2)<<1<<setw(3)<<"|"<<setw(2)<<2<<setw(3)<<"|"<<setw(2)<<3<<"\n";
    for(auto i=0;i!=4;++i)
        cout<<"-";
    cout<<"|";
    for(auto i=0;i!=4;++i)
        cout<<"-";
         cout<<"|";
    for(auto i=0;i!=4;++i)
        cout<<"-";
    cout<<"\n";
    cout<<setw(2)<<4<<setw(3)<<"|"<<setw(2)<<5<<setw(3)<<"|"<<setw(2)<<6<<"\n";
    for(auto i=0;i!=4;++i)
        cout<<"-";
    cout<<"|";
    for(auto i=0;i!=4;++i)
        cout<<"-";
         cout<<"|";
    for(auto i=0;i!=4;++i)
        cout<<"-";
    cout<<"\n";
   cout<<setw(2)<<7<<setw(3)<<"|"<<setw(2)<<8<<setw(3)<<"|"<<setw(2)<<9<<"\n";
}
void current_board()
{
    cout<<setw(5)<<"|"<<setw(5)<<"|"<<"\n";
cout<<setw(2)<<board[0][0]<<setw(3)<<"|"<<setw(2)<<board[0][1]<<setw(3)<<"|"<<setw(2)<<board[0][2]<<"\n";
    for(auto i=0;i!=4;++i)
        cout<<"-";
    cout<<"|";
    for(auto i=0;i!=4;++i)
        cout<<"-";
         cout<<"|";
    for(auto i=0;i!=4;++i)
        cout<<"-";
    cout<<"\n";
    cout<<setw(2)<<board[1][0]<<setw(3)<<"|"<<setw(2)<<board[1][1]<<setw(3)<<"|"<<setw(2)<<board[1][2]<<"\n";
    for(auto i=0;i!=4;++i)
        cout<<"-";
    cout<<"|";
    for(auto i=0;i!=4;++i)
        cout<<"-";
         cout<<"|";
    for(auto i=0;i!=4;++i)
        cout<<"-";
    cout<<"\n";
   cout<<setw(2)<<board[2][0]<<setw(3)<<"|"<<setw(2)<<board[2][1]<<setw(3)<<"|"<<setw(2)<<board[2][2]<<"\n";
}
void move_adjacent_side(int n)
{
    if(n==0 || n==2 || n==6 || n==8)
        adjacent_corner_side(n);
    else if(n==4)
        adjacent_centre_side(n);
}
void adjacent_corner_side(unsigned n)
{
std::default_random_engine e(time(0));
std::uniform_int_distribution<unsigned> u(0,1);
u(e);
unsigned i=n/3,j=n%3;
if(u(e))
    i==0?(j==0?Move(0,1):Move(0,1)):(j==0?Move(1,0):Move(1,2));
else
    i==0?(j==0?Move(1,0):Move(1,2)):(j==0?Move(2,1):Move(2,1));
}

void adjacent_centre_side(unsigned n)
{
std::default_random_engine e(time(0));
std::uniform_int_distribution<unsigned> u(0,3);
u(e);
unsigned k=u(e);
if(k==1 && board[1][0]=='\0')
    Move(1,0);
else if(k==2&& board[0][1]=='\0')
    Move(0,1);
else if(k==3&& board[1][2]=='\0')
    Move(1,2);
else if(k==0&& board[2][1]=='\0')
    Move(2,1);
else
    adjacent_centre_side(n);
}
