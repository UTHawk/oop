#include "stdafx.h"

#pragma warning(disable :4996)
#include "Ellipse.h"
#include "Trapeze.h"
#include "IsoscelesTrapeze.h"
#include "Shared_ptr.cpp"
#include "Vector.cpp"
#include <ctime>
#include <stdio.h> 
#include <string>
#define NumberOfShapes 10
#define ValueRange 50

void generateShapes(vector<shared_ptr<Shape>>& Shapes) {
	srand(time(nullptr));
	for (shared_ptr<Shape> &shape : Shapes){
		int object = rand() % 3;
		switch (object) {
			case 0: {
				shape.reset(new Ellipse({ (double) (rand() % 3 + 1),  (double) (rand() %3 + 1) }, rand() % ValueRange, rand() % ValueRange));
				break;
			}
			case 1: {
				shape.reset(new Trapeze({ (double)(rand() % 3 + 1),  (double)(rand() % 3 + 1) }, (double)rand() / ValueRange, (double)rand() / ValueRange, (double)rand() / ValueRange, (double)rand() / ValueRange));
				break;
			}
			case 2: {
				shape.reset(new IsoscelesTrapeze({ (double)(rand() % 3 + 1),  (double)(rand() % 3 + 1) }, (double)rand() / ValueRange, (double)rand() / ValueRange, (double)rand() / ValueRange));
				break;
			}
		}
	}
}

bool properties(Shape& shape) {
	if (shape.getCenter().x == shape.getCenter().y)
		return true;
	return false;
}

int main() {
	vector<shared_ptr<Shape>> shapes(NumberOfShapes);
	generateShapes(shapes);
	cout << "**********************************************" << endl;
	vector<shared_ptr<Shape>> boxShapes;
	cout << "After searching for two equal elements:" << endl;
	for (shared_ptr<Shape> &shape : shapes) {
		if (properties(*shape))
			cout << *shape << endl;
	}
	cout << "***********************************************" << endl;
	cout << "After modifying the found items : " << endl;
	for (shared_ptr<Shape> &shape : shapes) {
		if (properties(*shape)) {
			(*shape).reLocate(0, 0);
			cout << *shape << endl;
		}
	}	
	system("pause");
	return 0;
}