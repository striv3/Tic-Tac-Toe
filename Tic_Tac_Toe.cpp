#include"tic_tac.hpp"
#include<iostream>
#include<string>
using namespace std;
string board[3]={{'\0','\0','\0'},
                {'\0','\0','\0'},
                {'\0','\0','\0'}};//Global Variable //Used by every function.
main()
{
    cout<<"Hello There.Welcome To Tic-Tac-Toe v1.0 by Yashish"<<"\n";
    board_number();
    cout<<"\nIt's Your Turn :)"<<"\nFor Marking a region,press the corresponding number\n";
    int first_move=player_Move()-1,first_i=first_move/3,first_j=first_move%3;
    switch(first_move+1)
    {
        case 1:
        case 3:
        case 7:
        case 9:
        {
            Move(1,1);
            int second_move=player_Move()-1,second_i=second_move/3,second_j=second_move%3;
            if(first_i==second_i && second_j-first_j!=0)
                defend();
            else if(first_j==second_j && second_i-first_i!=0)
                defend();
            else if( (second_j-first_j!=0) && (second_i-first_i!=0) )
                move_adjacent_side(second_move);



            break;}
        case 5:
        {   Random_Corner();//Computer Move
            int second_move=player_Move()-1,second_i=second_move/3,second_j=second_move%3;
            if(first_i==second_i && second_j-first_j!=0)
                defend();
            else if(first_j==second_j && second_i-first_i!=0)
                defend();
            else if(second_i-first_i!=0 && second_j-first_j!=0)
            {   if(defend())
                ;
                else
                   Random_Sideways_Corner(second_i,second_j);}

            break;}
        case 2:
        case 4:
        case 6:
        case 8:
        {Move(1,1);
        int second_move=player_Move()-1,second_i=second_move/3,second_j=second_move%3;
        if(first_i==second_i && (second_j-first_j==1 || second_j-first_j==-1) )
                defend();
        else if(first_j==second_j && (second_j-first_j==1 || second_j-first_j==-1))
                defend();
        else if(first_i==second_i && (second_j-first_j==1 || second_j-first_j==-1) )
                Random_Corner();
        else if(first_j==second_j && (second_j-first_j==1 || second_j-first_j==-1))
                Random_Corner();
        else if( (second_i-first_i==1 || second_i-first_i==-1) && (second_j-first_j==1 || second_j-first_j==-1) )
                Move( max(first_i,second_i)==2?2:0,max(first_j,second_j)==2?2:0);
        else if( (second_i-first_i==1 || second_i-first_i==-1) && (second_j-first_j==2 || second_j-first_j==-2) )
                Move(second_i==2?0:2,second_j==2?0:2);
        else if( (second_i-first_i==2 || second_i-first_i==-2) && (second_j-first_j==1 || second_j-first_j==-1) )
                Move(second_i==2?0:2,second_j==2?0:2);
        break;}
        default:
            cout<<"Illegal Move.Try Again.";

    }

while(check_win()==0){
player_Move();
if(defend())
    ;
else if
    ;
}
}
