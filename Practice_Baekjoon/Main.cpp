#include<iostream>
#include "problem.h"

int main(void) {
	Problem* pb = new Problem_12865();

	pb->Solution();

	delete pb;
	return 0;
}