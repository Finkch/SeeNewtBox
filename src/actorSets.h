/*
 * actorSets.h
 *
 *  Created on: Dec. 9, 2022
 *      Author: skyler.alderson
 */

#ifndef ACTORSETS_H_
#define ACTORSETS_H_

//	This file contains sets of actors


//	Creates macros to define the Actors
#define sol(a) a = createActor("Sol", 1.989E30, 696340E3);
#define terra(a) a = createActor("Terra", 5.972E24, 6371E3); a.pos = createVector(149.6E9, 0, 0); a.vel = createVector(0, 29.78e3, 0);

Actor* twoBody(Actor* actors) {

	//	Sol
	Actor sol;
	sol = sol(sol);
	actors[0] = sol;

	//	Terra
	Actor terra;
	terra = terra(terra);
	terra.vel = createVector(0, 0, 0);
	actors[1] = terra;


	return actors;
}


#endif /* ACTORSETS_H_ */
