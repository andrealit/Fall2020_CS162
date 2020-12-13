/*********************************************************************
 ** Program Filename: Game.cpp
 ** Author: Andrea Tongsak
 ** Date: 11/19/2020
 ** Description: The game class declaration
 ** Input: -
 ** Output: -
 *********************************************************************/
#include "Game.h"
#include "Room.h"

#include <iostream>
#include <vector>

/*
* Function: Game Default Constructor
* Description: The equal operator sets an oldGame to the current game
* Parameters: the old game object
* Pre-Conditions: -
* Post-Conditions: -
 */
Game::Game() {
    cave_size = 4;
    wumpus_dead = false;
    game_done = false;
    
    // cave size
}

/*
* Function: Game Constructor with Parameters
* Description: Creates a cave with a parameters
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: -
 */
Game::Game(int size, char **cInput) {
    cout << "Print out the cave." << endl;
    
    set_cave_size(size);

    cave = vector<vector<Room>> (cave_size, vector<Room>(cave_size));
    
    // cave size
    for (int i = 0; i < cave_size; i++) {
        cout << "Row created." << endl;
        for (int j = 0; j < cave_size; j++) {
            cout << "Column created." << endl;
        }
    }
}

/*
* Function: Game Copy Constructor
* Description: Copies over the game
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: -
 */
Game::Game(const Game& oldGame) {
    cave = oldGame.cave;
    cave_size = oldGame.cave_size;
    wumpus_dead = oldGame.wumpus_dead;
    game_done = oldGame.game_done;
    player_x_start = oldGame.player_x_start;
    player_y_start = oldGame.player_y_start;
    playX = oldGame.playX;
    playY = oldGame.playY;
    player_action = oldGame.player_action;
    move = oldGame.move;
    num_gold = oldGame.num_gold;
    arrows = oldGame.arrows;
}

/*
* Function: Game Equal Operator
* Description: The equal operator sets an oldGame to the current game
* Parameters: the old game object
* Pre-Conditions: -
* Post-Conditions: -
 */
Game &Game::operator=(const Game oldGame) {
    cave = oldGame.cave;
    cave_size = oldGame.cave_size;
    wumpus_dead = oldGame.wumpus_dead;
    game_done = oldGame.game_done;
    player_x_start = oldGame.player_x_start;
    player_y_start = oldGame.player_y_start;
    playX = oldGame.playX;
    playY = oldGame.playY;
    player_action = oldGame.player_action;
    move = oldGame.move;
    num_gold = oldGame.num_gold;
    arrows = oldGame.arrows;
    return *this;
}

/*
* Function: Game Destructor
* Description: The game destructor to reallocate memory
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: -
 */
Game::~Game() {
    // destroy the game
    
}

/*
* Function: set_cave_size
* Description: The equal operator sets an oldGame to the current game
* Parameters: the old game object
* Pre-Conditions: -
* Post-Conditions: -
 */
void Game::set_cave_size(int caveSize) {
    cave_size = caveSize;
}

/*
* Function: get_cave_size
* Description: Access the cave size
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: -
 */
int Game::get_cave_size() {
    return cave_size;
}

/*
* Function: set_player_x_loc
* Description: set the player x location
* Parameters: the x location
* Pre-Conditions: -
* Post-Conditions: -
 */
void Game::set_player_x_loc(int xLoc) {
    playX = xLoc;
}

/*
* Function: set_player_y_loc
* Description: set the player y location
* Parameters: the y location
* Pre-Conditions: -
* Post-Conditions: -
 */
void Game::set_player_y_loc(int yLoc) {
    playY = yLoc;
}

/*
* Function: get_player_x_loc
* Description: Access the player x location
* Parameters: the x location
* Pre-Conditions: -
* Post-Conditions: -
 */
int Game::get_player_x_loc() {
    return playX;
}

/*
* Function: get_player_y_loc
* Description: Access the player y location
* Parameters: the y location
* Pre-Conditions: -
* Post-Conditions: -
 */
int Game::get_player_y_loc() {
    return playY;
}

/*
* Function: set_arrows
* Description: Mutator for the arrow number
* Parameters: int
* Pre-Conditions: -
* Post-Conditions: the arrow num is set
 */
void Game::set_arrows(int arr) {
    arrows = arr;
}

/*
* Function: get_arrows
* Description: Accessor for the arrow number
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: the arrow num is returned
 */
int Game::get_arrows() {
    return arrows;
}

/*
* Function: create_grid
* Description: We create the grid
* Parameters: size
* Pre-Conditions: The grid is created
* Post-Conditions: The grid of the correct size is printed out, rooms filled.
 */
void Game::create_grid(int size) {
    // default is 4 for cave size
    cout << "Cave of size " << size << " is created." << endl;

    set_cave_size(size);

    cave = vector<vector<Room>> (cave_size, vector<Room>(cave_size));
        
    // cave size
    for (int i = 0; i < cave_size; i++) {
        for (int j = 0; j < cave_size; j++) {
            cave[i][j].set_event(0);
        }
    }
}

/*
* Function: random_fill
* Description: We randomly fill the grid with one wumpus,
* Parameters: none
* Pre-Conditions: The grid is created
* Post-Conditions: The grid of the correct size is printed out, rooms filled.
 */
void Game::random_fill(int roomType) {
    
    // uses variables to set to a new location
    int locX, locY;
    
    // checks if valid location
    bool valid = false;
        
    while (valid == false) {
        locX = rand() % cave_size;
        locY = rand() % cave_size;
        
        if (roomType == 2) { // set the wumpus loc
            wumpX = locX;
            wumpY = locY;
        }
        
        if (roomType == 1) { // player starts where the rope is
            playX = locX;
            playY = locY;
            player_x_start = locX;
            player_y_start = locY;
            cave[locX][locY].set_player(true); // player set at place!
        }
    
        if (cave[locX][locY].get_event() == 0) { // find empty room
            cave[locX][locY].set_event(roomType);
            valid = true; // break
        }
    }
}

/*
* Function: fill_room
* Description: The room is filled with a random "type"
* Parameters: An int that correlates to the correct game
* Pre-Conditions: -
* Post-Conditions: The room is filled out completely
 */
void Game::fill_room() {
    
    // set the rope & player first
    random_fill(1);
    
    // Set the wumpus
    random_fill(2);
    
    // set the two bats
    random_fill(3);
    random_fill(3);
    
    // set the two pits
    random_fill(4);
    random_fill(4);
    
    // set 3 gold treasures
    num_gold = 3;
    for (int i = 0; i < 3; i++) {
        random_fill(5);
    }
    gold_collected = 0;
}

/*
* Function: grid_debug
* Description: print out the grid with the player location
* Parameters: An int for grid size, bool for debug
* Pre-Conditions: -
* Post-Conditions: The grid, with the player and debut, is printed
 */
void Game::grid_debug(int gridSize, bool debug) {
    set_arrows(3);

    set_cave_size(gridSize);
    
    for (int i = 0; i < cave_size; i++) { // rows
            for (int j = 0; j < cave_size; j++) { // columns
                cout << "+-------+";
            }
            cout << endl;
            for (int j = 0; j < cave_size; j++) {
                cout << "|       |";
            }
            
            cout << endl;
            for (int j = 0; j < cave_size; j++) {

                if (debug) {
                    if (cave[i][j].get_event() == 1 || (i == player_x_start && j == player_y_start)) { // print the player position
                        cout << "|   R   |";
                    } else if (i == playX && j == playY) {
                        cout << "|   *   |";
                    } else if (cave[i][j].get_event() == 2) {
                        cout << "|   W   |";
                    } else if (cave[i][j].get_event() == 3) {
                        cout << "|   B   |";
                    } else if (cave[i][j].get_event() == 4) {
                        cout << "|   P   |";
                    } else if (cave[i][j].get_event() == 5) {
                        cout << "|   G   |";
                    } else {
                        cout << "|       |";
                    }

                } else {
                    if (i == playX && j == playY) {
                        cout << "|   *   |";
                    } else {
                        cout << "|       |";
                    }
                }
            }
            cout << endl;
            for (int j = 0; j < cave_size; j++) {
                cout << "|       |";
            }
            cout << endl;
    }
    for (int j = 0; j < cave_size; j++) {
        cout << "+-------+";
    }
    cout << endl;
}

/*
* Function: print_percepts
* Description: print out the percepts around the player's position
* Parameters: An int that correlates to the correct game
* Pre-Conditions: -
* Post-Conditions: The room is filled out completely
 */
void Game::print_percepts() {

    cout << "Player location: " << endl;
    cout << playX << ", " << playY << endl;

    // use the player coordinates as the "anchor"

    // display the room's messages if it's not empty. (empty = 0)
    if ((playY + 1) < cave_size && cave[playX][playY+1].get_event() != 0) {
        //right
        cave[playX][playY+1].get_percept();
    }

    if ((playY - 1) >= 0 && cave[playX][playY-1].get_event() != 0) {
        //left
        cave[playX][playY-1].get_percept();
    }

    if ((playX - 1) >= 0 && cave[playX-1][playY].get_event() != 0) {
        //bottom
        cave[playX-1][playY].get_percept();
    }

    if ((playX + 1) < cave_size && cave[playX+1][playY].get_event() != 0) {
        //top
        cave[playX+1][playY].get_percept();
    }
}

/*
* Function: move_player
* Description: move the player around the grid
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: player can move with the key commands
 */
void Game::move_player() {
    char moveCommands;
    char wantMove;
    bool okCommand = false;
    bool move1 = false;
    bool move2 = false;

    cout << "Do you want to move? 🚶 (y/n)" << endl;
    cin >> wantMove;

    if (wantMove == 'y') {
        cout << "To move: " << endl;
        cout << "(w) north" << endl;
        cout << "(a) west" << endl;
        cout << "(s) south" << endl;
        cout << "(d) east" << endl;

        cout << "Move?" << endl;
        cin >> moveCommands;

        switch (moveCommands) {
            case 'w':
                okCommand = true;
                cout << "Up." << endl;
                if (check_move('w')) {
                    cave[playX][playY].set_event(0);
                    playX--;
                }
                break;
            case 'a': 
                okCommand = true;
                cout << "Left." << endl;
                if (check_move('a')) {
                    cave[playX][playY].set_event(0);
                    playY--;
                }
                break;
            case 'd':
                okCommand = true;
                cout << "Right." << endl;
                if (check_move('d')) {
                    cave[playX][playY].set_event(0);
                    playY++;
                }
                break;
            case 's': 
                okCommand = true;
                cout << "South." << endl;
                if (check_move('s')) {
                    cave[playX][playY].set_event(0);
                    playX++;
                }
                break;
            default:
                cout << "try again." << endl;
                break;
        }
    } else if (wantMove == 'n'){
        cout << "Didn't move." << endl;
    } else {
        cout << "Incorrect input." << endl;
        return;
    }

    cout << "Player location: " << endl;
    cout << playX << ", " << playY << endl;

}

/*
* Function: check_move
* Description: check that the move is good
* Parameters: char (type of move)
* Pre-Conditions: -
* Post-Conditions: The move is checked
 */
bool Game::check_move(char input) {

    if (input == 'w') {
        if (playX-1 >= 0) {
            return true;
        } else {
            return false;
        }
    }

    if (input == 'a') {
        if (playY-1 >= 0) {
            return true;
        } else {
            return false;
        }
    }

    if (input == 'd') {
        if (playY+1 < cave_size) {
            return true;
        } else {
            return false;
        }
    }

    if (input == 's') {
        if (playX+1 < cave_size) {
            return true;
        } else {
            return false;
        }
    }
}


/*
* Function: check_move
* Description: check that the move is good
* Parameters: string (type of move)
* Pre-Conditions: -
* Post-Conditions: The move is checked
 */
bool Game::check_move(string input) {

    if (input == " w") {
        if (playX-1 >= 0) {
            return true;
        } else {
            return false;
        }
    }

    if (input == " a") {
        if (playY-1 >= 0) {
            return true;
        } else {
            return false;
        }
    }

    if (input == " d") {
        if (playY+1 < cave_size) {
            return true;
        } else {
            return false;
        }
    }

    if (input == " s") {
        if (playX+1 < cave_size) {
            return true;
        } else {
            return false;
        }
    }
}


/*
* Function: shoot_arrow
* Description: an arrow is shot in the direction
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: The arrow is shot, decrease number of arrows, and print if the wumpus is dead
 */
void Game::shoot_arrow() {

    string shootCommand;
    char wantShoot;

    cout << "Do you want to shoot arrows? 🏹 (y/n)" << endl;
    cin >> wantShoot;

    if (wantShoot == 'y') {

        if (wumpus_dead == true) {
            cout << "Wumpus dead! 💀 No need for violence." << endl;
            return;
        }

        cout << get_arrows() << " arrows left." << endl;

        if (arrows == 0 && wumpus_dead == false) {
            cout << "No more arrows." << endl;
            return;
        }

        cout << "To shoot: " << endl;
        cout << "( w) north" << endl;
        cout << "( a) west" << endl;
        cout << "( s) south" << endl;
        cout << "( d) east" << endl;
        
        cin.ignore();
        getline(cin, shootCommand);

        if (shootCommand == " w") {
            if (check_move(" w")) {
                arrows--;
                if (cave[playX-1][playY].get_event() == 2) {
                    wumpus_killed();
                    return;
                } else {
                    wumpus_move();
                }
            }        
        }

        if (shootCommand == " a") {
            if (check_move(" a")) {
                arrows--;
                if (cave[playX][playY-1].get_event() == 2) {
                    wumpus_killed();
                    return;
                } else {
                    wumpus_move();
                }
            }
        }

        if (shootCommand == " s") {
            if (check_move(" s")) {
                arrows--;
                if (cave[playX+1][playY].get_event() == 2) {
                    wumpus_killed();
                    return;
                } else {
                    wumpus_move();
                }
            }
        }

        if (shootCommand == " d") {
            if (check_move(" d")) {
                arrows--;
                if (cave[playX][playY+1].get_event() == 2) {
                    wumpus_killed();
                    return;
                } else {
                    wumpus_move();
                }
            }
        }


    } else if (wantShoot == 'n'){
        cout << "Didn't shoot." << endl;
    } else {
        cout << "Incorrect input." << endl;
        return;
    }
}

/*
* Function: wumpus_dead
* Description: the wumpus has died helper function
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: The wumpus dies, the game is over.
 */
void Game::wumpus_killed() {
    cout << "The arrow has striked down the wumpus!" << endl;
    remove_item(wumpX, wumpY);
    wumpus_dead = true;
}

/*
* Function: encounter
* Description: what happens when the player encounters a square
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: the correct event happens
 */
void Game::encounter() {

    cout << "Event: " << cave[playX][playY].get_event() << endl;

    if (cave[playX][playY].get_event() != 0 && cave[playX][playY].get_event() != 1) { // if not an empty room, or their starting place
        cave[playX][playY].get_room_event()->encounter();
    }

    // if player returns to the same room as their rope
    if (playX == player_x_start && playY == player_y_start) {
        cout << "Rope room!" << endl;
        game_over(true);
    }

    // if gold is found
    if (cave[playX][playY].get_event() == 5) {
        gold_collected++;
        remove_item(playX, playY);
    }

    // if bat is found
    if (cave[playX][playY].get_event() == 3) {
        // move function
        bats_flap();
        remove_item(playX, playY);
    }

    // if pit is found
    if (cave[playX][playY].get_event() == 4) {
        game_over(false);
    }

    // if wumpus is found
    if (cave[playX][playY].get_event() == 2) {
        game_over(false);
    }

}

/*
* Function: check_game
* Description: ends the game
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: the game ends
 */
void Game::game_over(bool safe) {
    // if player returns safely, check for gold
    if (safe) {
        if (gold_collected == 3) {
            game_done = true;
            if (wumpus_dead) {
                cout << "You killed the wumpus, rip 👾" << endl;
            }
            cout << "Congrats, winner! 🎉 Climbing out of the cave. 🎊" << endl;
            return;
        } else {
            cout << "Hmm, pick up your gold first. 👑" << endl;
            return;
        }
    } else {
        game_done = true;
        cout << "D E F E A T." << endl;
        return;
    }

}

/*
* Function: bats_flap
* Description: bats pick up and move the player
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: The player is moved to a random empty room.
 */
void Game::bats_flap() {
    srand(time(NULL));
    int randX, randY;

    cave[playX][playY].set_player(false);
    cave[playX][playY].set_event(0);
    bool moved = false;

    while (moved == false) {
        randX = rand() % cave_size;
        randY = rand() % cave_size;
        set_player_x_loc(randX);
        set_player_y_loc(randY);

        playX = randX;
        playY = randY;
        cave[playX][playY].set_player(true);
        moved = true;

        // condition with unsafe rooms
        if (cave[playX][playY].get_event() == 4 || cave[playX][playY].get_event() == 2) {
            cave[playX][playY].get_room_event()->encounter();
            game_over(false);
            return;
        }

        // condition with a gold room
        if (cave[playX][playY].get_event() == 5) {
            cave[playX][playY].get_room_event()->encounter();
            gold_collected++;
            remove_item(playX, playY);
            return;
        }
        
    }
}

/*
* Function: wumpus_move
* Description: the wumpus moves to a random spot, 75% chance
* Parameters: -
* Pre-Conditions: -
* Post-Conditions: The wumpus is moved to a random empty room.
 */
void Game::wumpus_move() {
    srand(time(NULL));

    cout << "Fwip! Arrow missed!" << endl;
    cout << get_arrows() << " remain." << endl;

    int pick = rand() % 4;

    if (pick != 1) { // the 75% chance of being any other number
        cout << "Whoops, you woke the wumpus. They're crawling away..." << endl;
        cave[wumpX][wumpY].set_event(0);

        random_fill(2);
        cave[wumpX][wumpY].set_event(2);
    }
}

/*
* Function: remove_item
* Description: remove item
* Parameters: int, int
* Pre-Conditions: -
* Post-Conditions: The item is removed at the specific coordinate
 */
void Game::remove_item(int x, int y) {
    cave[x][y].set_event(0); // empty room
    //cave[x][y].set_room_event(NULL);
}

/*
* Function: game_cycle
* Description: game cycles through for wumpus until game is over
* Parameters: size of board. whether in debug mode or not
* Pre-Conditions: -
* Post-Conditions: all game functions used here
 */
void Game::game_cycle(int size, bool debug) {
    // creation and filling
    create_grid(size);
    fill_room();

    // while the game is not over, repeat this cycle
    while (game_done == false) {
        // print
        grid_debug(size, debug);
        print_percepts();

        // shoot
        shoot_arrow();

        // move option
        move_player();

        // encounter
        encounter();
    }

}