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
void simulatePair(Actor a, Actor b) {

	//	The displacement from a to b
	Vector ab = createVector(b.pos.x - a.pos.x, b.pos.y - a.pos.y, b.pos.z - a.pos.z);


	//	The displacement from b to a
	//	Which is -1 * ab
	Vector ba = createVector(-1 * ab.x, -1 * ab.y, -1* ab.z);


	//	Calculates the magnitude of the vectors
	double distance = hypotenuse3D(ab);


	//	Calculates the force on each actor
	double force = G * a.mass * b.mass / pow(distance, 2);


	//	Creates the acceleration vectors
	Vector aAcc = scalarToVector(force / a.mass, ab);
	Vector bAcc = scalarToVector(force / b.mass, ba);

	a.acc.x = aAcc.x;
	a.acc.y = aAcc.y;
	a.acc.z = aAcc.z;


	b.acc = bAcc;

	printf("simAcc:\t%e, %e, %e\n", aAcc.x, aAcc.y, aAcc.z);
	printf("aAcc:\t%e, %e, %e\n", a.acc.x, a.acc.y, a.acc.z);
}

//	Considers every pair of actors
void simulate(Actor* actors, int len) {
	for (int i = 0; i < len - 1; i++)
		for (int j = i + 1; j < len; j ++)
			simulatePair(actors[i], actors[j]);
}

//	Sets up a round of simulations
void gravity(Actor* actors, int len, double timeStep) {

	//	Gets acceleration
	simulate(actors, len);


	for (int i = 0; i < len; i++) {
		Actor a = actors[i];
		printf("\nRAcc, %s:\t%e, %e, %e\n\n", a.name, a.acc.x, a.acc.y, a.acc.z);
	}


	//	Applies acceleration onto velocity
	for (int i = 0; i < len; i++)
		accOnVel(actors[i], timeStep);


	//	Applies velocity onto position
	for (int i = 0; i < len; i++)
		velOnPos(actors[i], timeStep);


	//	Resets the acceleration for each actor
	for (int i = 0; i < len; i++)
		resetAcc(actors[i]);

}



#endif /* SIMULATE_H_ */
