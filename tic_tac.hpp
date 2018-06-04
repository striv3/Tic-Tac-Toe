#ifndef TIC_TAC
#define TIC_TAC
#include<string>
extern std::string board[3];
int defend();
int win();
void Move(unsigned,unsigned);
int player_Move();
int check_win();
void Random_Corner();
void Random_Sideways(unsigned i,unsigned j);
void Random_Sideways_Corner(unsigned i,unsigned j);
void current_board();
void board_number();
void move_adjacent_side(int n);
void adjacent_corner_side(unsigned n);
void adjacent_centre_side(unsigned n);

#endif // tic_tac
