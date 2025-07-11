/*
 * exist.c
 *
 *  Created on: Oct. 14, 2022
 *      Author: skyler.alderson
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include "actor.h"
#include "calculate.h"
#include "simulate.h"
#include "actorSets.h"

//	There is a problem somewhere in simulate,
//	right at the end of simulate pairs,
//	where the acceleration vector simply
//	isn't being copied back. I think it is an
//	issue with references and scope. Yet, those
//	fixes don't seem to work. Feh.
//
//	Yeah, it's almost certainly pointers.


void printout(Actor* actors, int len) {
	for (int j = 0; j < len; j++)
			printActor(actors[j]);
}


int main() {

	//	Grabs the actors
	Actor* actors = malloc(2 * sizeof(Actor));
	actors = twoBody(actors);

	int len = 2;

	//printActor(actors[0]);
	//printActor(actors[1]);


	//	The time simulated every step
	//	In seconds
	double timeStep = 1e4;

	//	Simulates and prints out
	for (int i = 0; i < 10e4; i++) {


		//	Does a step
		gravity(actors, len, timeStep);

		//	Gives a print-out of an actor
		printout(actors, len);

		//	The factor of 1000 puts it into milliseconds
		usleep(160 * 1000);

	}

	free(actors);

	return 0;

}

