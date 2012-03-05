class Player {
  
    int cur_x;
    int cur_y;
    
    //Game specific stuff
    int score;
    int max_bombs;
    int blast_pow;
    
public:
    Player();
    
    virtual ~Player() {
    }
    
    int getX();
    int getY();
    
    virtual void update();
    
};