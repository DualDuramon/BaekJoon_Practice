#include<iostream>
#include "problem.h"

int main(void) {
	Problem* pb = new Problem_1080();

	pb->Solution();

	delete pb;
	return 0;
}