#include "Level.h"

Level::Level() {
    
    generate();
    
}

void Level::generate() {
    //blank for now
}

void Level::add_player(Player* player) {
    players.push_back(player);
}

void Level::set_local(LocalPlayer* player) {
    local = player;
}

void update() {
    //Go through all objects and call update
}