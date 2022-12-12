/*
 * actor.h
 *
 *  Created on: Oct. 14, 2022
 *      Author: skyler.alderson
 */

#ifndef ACTOR_H_
#define ACTOR_H_

//	This function defines Actors and Vectors


//	Defines a vector in 3D
struct Vectors {
	double x;
	double y;
	double z;
};

typedef struct Vectors Vector;


//	Defines an actor
//	An actor is a thing that, like, exists
struct Actors {
	char* name[10];

	double mass;
	double radius;

	Vector pos;
	Vector vel;
	Vector acc;
	Vector fakeAcc; //	Used because acc is reset before each print-out
};

typedef struct Actors Actor;




//		BEGIN initialise Actors and Vectors

//	Returns an vector with all values initialised to 0
Vector createVector(double x, double y, double z) {
	Vector vec;
	vec.x = x;
	vec.y = y;
	vec.z = z;

	return vec;
}

//	Returns an actor with all values initialised to 0
Actor createActor(char* actorName, double inMass, double inRadius) {
	Actor act;

	memcpy(act.name, actorName, sizeof(act.name));

	act.mass = inMass;
	act.radius = inRadius;

	act.pos = createVector(0, 0, 0);
	act.vel = createVector(0, 0, 0);
	act.acc = createVector(0, 0, 0);

	return act;
}

void adjustAcc(Actor a, Vector v) {
	a.acc.x = v.x;
	a.acc.y = v.y;
	a.acc.z = v.z;

	a.acc = v;
}

//		END initialisation



//		BEGIN actor functions

void accOnVel(Actor* actors, int i, double timeStep) {
	actors[i].vel.x += actors[i].acc.x * timeStep;
	actors[i].vel.y += actors[i].acc.y * timeStep;
	actors[i].vel.z += actors[i].acc.z * timeStep;
}

void velOnPos(Actor* actors, int i, double timeStep) {
	actors[i].pos.x += actors[i].vel.x * timeStep;
	actors[i].pos.y += actors[i].vel.y * timeStep;
	actors[i].pos.z += actors[i].vel.z * timeStep;
}

void resetAcc(Actor* actors, int i) {
	actors[i].fakeAcc = actors[i].acc;
	actors[i].acc = createVector(0, 0, 0);
}

//		END actor functions



//		BEGIN print functions
void printVector(Vector vector) {
	printf("%e, %e, %e\n", vector.x, vector.y, vector.z);
}


void printActor(Actor actor) {
	printf("%s:\n", actor.name);
	printf("\tMass:\t\t%e\n\tRadius:\t\t%e\n", actor.mass, actor.radius);

	printf("\tPosition:\t");
	printVector(actor.pos);

	printf("\tVelocity:\t");
	printVector(actor.vel);

	printf("\tAcceleration:\t");
	printVector(actor.fakeAcc);
}
//		END print functions


#endif /* ACTOR_H_ */
