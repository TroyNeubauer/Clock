 #include "mymath.h"
 
 double map(double value, double sourceMin, double sourceMax, double destMin, double destMax){
	double n = normalize(sourceMin, sourceMax, value);
	return lerp(destMin, destMax, n);
}


double normalize(double min, double max, double value) {
	return (value - min) / (max - min);
}

double lerp(double a, double b, double f) {
	return a + f * (b - a);
}