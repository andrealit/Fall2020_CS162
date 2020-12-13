/*********************************************************************
 ** Program Filename: Game.h
 ** Author: Andrea Tongsak
 ** Date: 11/19/2020
 ** Description: The header file for game
 ** Input: -
 ** Output: -
 *********************************************************************/

#ifndef Game_h
#define Game_h

#include <stdio.h>
#include <vector>

#include "Room.h"

using namespace std;

class Game {
    protected:
        vector<vector<Room>> cave; // 2d array of vectors
        int cave_size;
        bool wumpus_dead;
        bool game_done;
    
        int player_x_start;
        int player_y_start;
    
        int playX, playY;
    
        int wumpX, wumpY;
        
        int player_action;
        char move;
        int num_gold;
        int gold_collected;

        int arrows;
    
    public:
        Game();
        Game(int, char**);
    
        Game(const Game&);
        Game& operator=(const Game);
        ~Game();
    
        void set_cave_size(int);
        int get_cave_size();
    
        void set_player_x_loc(int);
        void set_player_y_loc(int);
    
        int get_player_x_loc();
        int get_player_y_loc();

        void set_arrows(int);
        int get_arrows();
        
        void create_grid(int);
    
        void random_fill(int);
    
        void fill_room();
    
        void grid_debug(int, bool);
    
        void print_percepts();

        void move_player();
        bool check_move(char);
        bool check_move(string);

        void shoot_arrow();
        void wumpus_killed();

        void encounter();

        void game_over(bool);

        void bats_flap();

        void wumpus_move();

        void remove_item(int, int);

        void game_cycle(int, bool);
};


#endif /* Game_h */