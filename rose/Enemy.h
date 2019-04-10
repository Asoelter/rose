#include "actor.h"
#pragma once

class Enemy 
{
public:
	/**
	 * @brief Construct a new Enemy object
	 * 
	 */
	Enemy();

	/**
	 * @brief Destroy the Enemy object
	 * 
	 */
	virtual ~Enemy() = default;

protected:
	double m_health = 100;
	int m_damage = 0;
	int xp;
	bool alive;

	/**
	 * @brief Increases the enemies health by half
	 * of it's current amount of health
	 * 
	 */
	virtual void heal();

	/**
	 * @brief Decreases the enemies health by damage amount
	 * 
	 * @param damage The amount of damage to take
	 */
	virtual void takeDamage(int damage);

	// 	 			   .-"""-.
	//                /  . -  \
	//                \       /
	//          .-""-.,:.-_-.<
	//         /    _; o / )o|
	//         \  ; / `  `"  '\
	//          '.-| ;-.____, |             .,
	//              \ `._~_/ /             /"/
	// ,.           /`-.__.-'\`-._     ,",' ;
	// \"\         / /|   o   \._ `-._; /  ./-.
	//  ; ';,     / / |    ’___\ `-.,( /  //.-'
	// :\  \\;_.-" ;  |.-"``    `\    /-. /.-'
	//  :\  .\),.-'  /      }{    |   '..'
	//    \ .-\      |          , /
	//     '..'      ;'        , /
	//              ( __ `;--;'__`)
	//               `//'`    `||`
	//              _//        ||
	//      .-"-._,(__)      .(__).-""-.
	//     /          \     /           \
	//     \          /     \           /
	//      `'--=="--`       `--""==--'`jgs+/-miK

	/**
	 * @brief I honestly don't know what this is 
	 * 
	 * @param x The value to return
	 * @return int The parameter
	 */
	virtual int sendXP(int x);

};

