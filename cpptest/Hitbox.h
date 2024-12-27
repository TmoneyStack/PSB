#ifndef HITBOX_H    //header guard
#define HITBOX_H    //header guard

static const int PLAYER_SPEED = 3;

// Hitbox Class Object
// Defines a rectangular Hitbox for players and non-moving objects in program.
class Hitbox{
    int m_pos[2];     // middle / origin (x,y)
    int m_dist[2];    // dist from midpoint -- half of length and width
    int m_speed;
    unsigned int m_color;   //Hex color format: 0xAABBGGRR

public:
    //Constructor
    Hitbox();

    //Constructor - Overwrite
    Hitbox(int x, int y, int length, int width, unsigned int color);

    //Destructor
    ~Hitbox();

    //Constructor - Copy
    //todo Hitbox(const Hitbox& source);               //? may remove const for ease of access

    //Assignemnt Opperator
    //todo Hitbox& operator=(const Hitbox& other);     //? may remove const for ease of access

    //accessers & mutators
    int getX();
    void setX(int x);
    int getY();
    void setY(int y);
    int getWidth();
    void setWidth(int width);
    int getLength();
    void setLength(int length);
    int getSpeed();
    void setSpeed(int speed);
    unsigned int getColor();
    void setColor(unsigned int color);

    // returns the outer bounds of the hitbox. Axis is either FALSE = X or TRUE = Y
    // set as bool because we are only working with 2 axis
    // info - for a 3D envornenment, this would require a rework
    int hbMin(bool axis);
    int hbMax(bool axis);    

    // checks for intersections in reference to another hitbox. Returns true if intersecting.
    // info - for a 3D envornenment, this would require a rework
    bool isIntersect(Hitbox* other);

    
};

#endif //HITBOX_H