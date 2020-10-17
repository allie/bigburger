float easing_linear_f(double x, float min, float max) {
	return max - ((max - min) - (max - min) * x);
}

double easing_linear_d(double x, double min, double max) {
	return max - ((max - min) - (max - min) * x);
}

int easing_linear_i(double x, int min, int max) {
	return max - ((max - min) - (max - min) * x);
}
