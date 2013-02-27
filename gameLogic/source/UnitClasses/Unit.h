

//base unit classes, all concrete unit types will inherit from this in some way
class Unit{
public:
    Unit(const int& unitID, const int& teamID, const int& hp, const int& xPos, const int& yPos):
     unitID_(unitID), teamID_(teamID), healthPoints_(hp), xPos_(xPos), yPos_(yPos) {
        //validation

        //check that unit id is unique
        //check that teamID is correct(1 of the 2 teams)
        //check that hp is > 0
        //x/y?

    }

    /*********************
     * getters and setters
     *********************/
    int getID(){
        return unitID_;
    }

    int getTeam(){
        return teamID_;
    }

    int getHP(){
        return healthPoints_;
    }

    int getX(){
        return xPos_;
    }

    int getY(){
        return yPos_;
    }

    //some setters may not be needed, some may require validation
    void setID(const int& id){
        unitID_ = id;
    }

    void setTeam(const int& team){
        teamID_ = team;
    }

    void setHP(const int& hp){
        healthPoints_ = hp;
    }

    void setX(const int& x){
        xPos_ = x;
    }

    void setY(const int& y){
        yPos_ = y;
    }

    //other useful functions
    void setPos(x, y){
        xPos_ = x;
        yPos_ = y;
    }

    bool isDead(){
        if(healthPoints_ == 0){
            return true;
        }
        return false;
    }

    void addHP(const int& add){
        healthPoints_ += add;
    }

    //virtual because attacks might be mitigated by armour?
    virtual void subHP(const int& sub){
        healthPoints_ -= sub;
    }

    //pure virtual function for displaying info about the class
    //makes the class abstract
    virtual void display() const = 0;
private:
    int unitID_;//unique ID for the unit
    int teamID_;//ID of the team that the unit is associated with
    int healthPoints_;//health points of the unit
    int xPos_;//x position of the unit
    int yPos_;//y position of the unit
}