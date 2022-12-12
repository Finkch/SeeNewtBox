/*
 * calculate.h
 *
 *  Created on: Dec. 9, 2022
 *      Author: skyler.alderson
 */

#ifndef CALCULATE_H_
#define CALCULATE_H_

//	This header holds handy-dandy math functions
double hypotenuse3D(Vector a) {
	return pow(pow(a.x, 2) + pow(a.y, 2) + pow(a.z, 2), 0.5);
}

double hypotenuse2D(double a, double b) {
	return pow(pow(a, 2) + pow(b, 2), 0.5);
}

Vector scalarToVector(double scalar, Vector vector) {

	//	The vector to be returned
	Vector a = createVector(0, 0, 0);

	//	Uses spherical coordinate conversions and angles to
	//	split the scalar into its constituent vector components
	a.x = fabs(scalar * cos(atan(vector.z / hypotenuse2D(vector.x, vector.y))) * cos(atan(vector.y / vector.x)));
	a.y = fabs(scalar * cos(atan(vector.z / hypotenuse2D(vector.x, vector.y))) * sin(atan(vector.y / vector.x)));
	a.z = fabs(scalar * sin(atan(vector.z / hypotenuse2D(vector.x, vector.y))));


	//	In the conversion, negatives were lost so this here
	//	is to reintroduce them
	if (vector.x <= 0)
		a.x *= -1;

	if (vector.y <= 0)
		a.y *= -1;

	if (vector.z <= 0)
		a.z *= -1;

	return a;
}



#endif /* CALCULATE_H_ */
