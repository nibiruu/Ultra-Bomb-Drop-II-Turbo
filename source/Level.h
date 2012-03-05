#define LEVEL_COL 20
#define LEVEL_ROW 20 

typedef enum {
    GROUND,
    SOLID,
    BREAK
} Tile;

class Level {
  
    Tile board_data[LEVEL_ROW][LEVEL_COL];
    
    void generate(); //Generates a random level
    
    LocalPlayer* local;
    vector<Player*> players;
    
public:
    Level(); //Constructor to generate a random level
    
    void add_player(Player* player);
    void set_local(LocalPlayer* player);
    
    void update();
};