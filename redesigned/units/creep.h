#ifndef CREEP_H
#define CREEP_H

#include "../resource.h"
#include "../types.h"
//#include "unit.h"
#include "mobile_unit.h"

class Creep : public MobileUnit
{
public: 
   void spawn(const int& num);  //also creep type? when we have a type
   std::string serializeCreep(const Creep& creep);

	virtual UnitTypes getType() const { return TYPE_CREEP; }
	virtual size_t getSize() const { return sizeof(Creep); }

	//Creep(): pPath( 0 ), pSaved( 0 ), moveSpeed( 0 ){}

	Creep( const Creep& );
	void	Update( void );
	void	setSpeed( int newSpeed) { moveSpeed = newSpeed; }
	void	setPath( Point *pt )	{ pPath = pt; }
	void	nextPoint( void )	{ pPath++; }
	void	savePoint( Point &pt )	{ pSaved = &pt; }
	void	Move( Point );
	int	getDirection( int, int );
	void	Attack( void );
	//void	setTarget( Attackable &newTarget ) { pTarget = &newTarget; }
	float	Rotate( Point ); 
	void	setDamage( int newDamage ) { attackDamage = newDamage;  }
	void	setRange( int newRange ) { attackRange = newRange; }
	bool	inRange( Point, Point, int );
	virtual void	CheckTarget( void );
	virtual void	FindTarget( void );
	//bool			hasWeakness( int, int );

	Point	*	pPath;
	Point	*	pSaved;
	int      	moveSpeed;   //the speed which a unit can move. ex. (it can move 1 square per 30 frames)

private:
};

#endif
