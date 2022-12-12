/*
 * simulate.h
 *
 *  Created on: Dec. 9, 2022
 *      Author: skyler.alderson
 */

#ifndef SIMULATE_H_
#define SIMULATE_H_

#define G -6.67E-11

//	This header does the simulations


//	Calculates the gravity between a pair of actors
void simulatePair(Actor* actors, int i, int j) {

	//	The displacement from a to b
	Vector ab = createVector(actors[j].pos.x - actors[i].pos.x, actors[j].pos.y - actors[i].pos.y, actors[j].pos.z - actors[i].pos.z);


	//	The displacement from b to a
	//	Which is -1 * ab
	Vector ba = createVector(-1 * ab.x, -1 * ab.y, -1* ab.z);


	//	Calculates the magnitude of the vectors
	double distance = hypotenuse3D(ab);


	//	Calculates the force on each actor
	double force = G * actors[i].mass * actors[j].mass / pow(distance, 2);


	//	Creates the acceleration vectors
	Vector aAcc = scalarToVector(force / actors[i].mass, ab);
	Vector bAcc = scalarToVector(force / actors[j].mass, ba);

	actors[i].acc = aAcc;
	actors[j].acc = bAcc;

}

//	Considers every pair of actors
void simulate(Actor* actors, int len) {
	for (int i = 0; i < len - 1; i++)
		for (int j = i + 1; j < len; j ++)
			simulatePair(actors, i, j);
}

//	Sets up a round of simulations
void gravity(Actor* actors, int len, double timeStep) {

	//	Gets acceleration
	simulate(actors, len);


	//	Applies acceleration onto velocity
	for (int i = 0; i < len; i++)
		accOnVel(actors, i, timeStep);


	//	Applies velocity onto position
	for (int i = 0; i < len; i++)
		velOnPos(actors, i, timeStep);


	//	Resets the acceleration for each actor
	for (int i = 0; i < len; i++)
		resetAcc(actors, i);

}



#endif /* SIMULATE_H_ */
