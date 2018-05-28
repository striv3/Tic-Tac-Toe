#include<iostream>
#include<string>
using std::cout;
using std::cin;
using std::string;
extern string board[3];
void v_line()
{
for(auto i=0;i!=10;++i)
    cout<<"|\n";
}
void player_Move(unsigned i,unsigned j)
{
    if(board[i][j]!='\0')
        board[i][j]='X';
    else
        cout<<"\nInvalid Move.Try Again";
}
void Move(unsigned i,unsigned j)
{
    if(board[i][j]!='\0')
        board[i][j]='O';
    else
        cout<<"\nInvalid Move.Try Again";
}
void defend()
{
    for(auto i=0;i!=2;++i)
    {
        if(board[i][0]==board[i][1])
            Move(i,2);
        if(board[i][1]==board[i][2])
            Move(i,0);
        if(board[i][0]==board[i][2])
            Move(i,1);

    }
    for(auto j=0;j!=2;++j)
    {
        if(board[0][j]==board[1][j])
            Move(2,j);
        if(board[1][j]==board[2][j])
            Move(0,j);
        if(board[0][j]==board[2][j])
            Move(1,j);
    }
    //For Primary Diagonal
    if(board[0][0]==board[1][1])
        Move(2,2);
    if(board[1][1]==board[2][2])
        Move(0,0);
    if(board[0][0]==board[2][2])
        Move(1,1);
    //---------------------------------For Secondary Diagonal
    if(board[0][2]==board[1][1])
        Move(2,0);
    if(board[1][1]==board[2][0])
        Move(0,2);
    if(board[0][2]==board[2][0])
        Move(1,1);



}
void win()
{
    for(auto i=0;i!=2;++i)
    {
        if(board[i][0]=='O' && board[i][1]=='O')
            Move(i,2);
        if(board[i][1]=='O' && board[i][2]=='O')
            Move(i,0);
        if(board[i][0]=='O' && board[i][2]=='O')
            Move(i,1);

    }
        for(auto j=0;j!=2;++j)
    {
        if(board[0][j]=='O' && board[1][j]=='O')
            Move(2,j);
        if(board[1][j]=='O' && board[2][j]=='O')
            Move(0,j);
        if(board[0][j]=='O' && board[2][j]=='O')
            Move(1,j);
    }
    //For Primary Diagonal
    if(board[0][0]=='O' && board[1][1]=='O')
        Move(2,2);
    if(board[1][1]=='O' && board[2][2]=='O')
        Move(0,0);
    if(board[0][0]=='O' && board[2][2]=='O')
        Move(1,1);
    //---------------------------------For Secondary Diagonal
    if(board[0][2]=='O' && board[1][1]=='O')
        Move(2,0);
    if(board[1][1]=='O' && board[2][0]=='O')
        Move(0,2);
    if(board[0][2]=='O' && board[2][0]=='O')
        Move(1,1);

}
void check_win()
{
    if(board[0][0]==board[1][1] && board[0][0]==board[2][2])
    {
        if(board[0][0]=='O')
            cout<<"\nI Win.\nIt was Pleasure playing with you.";
        else if(board[0][0]=='X')
            cout<<"\nCongratulations.You Win";
    }
    if(board[2][0]==board[1][1] && board[2][0]==board[0][2])
    {
        if(board[0][0]=='O')
            cout<<"\nI Win.\nIt was Pleasure playing with you.";
        else if(board[0][0]=='X')
            cout<<"\nCongratulations.You Win";
    }
for(auto i=0;i!=2;++i)
        {
        if(board[i][0]==board[i][1] && board[i][0]==board[i][2])
            {
        if(board[i][0]=='O')
            cout<<"\nI Win.\nIt was Pleasure playing with you.";
        else if(board[i][0]=='X')
            cout<<"\nCongratulations.You Win";
            }

    }
for(auto j=0;j!=2;++j)
    {
        if(board[0][j]==board[1][j] && board[0][j]==board[1][j])
            {
        if(board[0][j]=='O')
            cout<<"\nI Win.\nIt was Pleasure playing with you.";
        else if(board[0][j]=='X')
            cout<<"\nCongratulations.You Win";
            }

    }
}
