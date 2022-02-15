#include <iostream>

using namespace std;

void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

void swap(string *a, string *y) {
	string temp = *a;
	*a = *y;
	*y = temp;
}
void drawTree(string names[], int parents[], int size) {
	string namesPrint[16];
	int parentsPrint[16];
	int parentCounter = 0;
	//find max node
	int count = 0, max = parents[0];
	while (count < size - 1) {
		if (parents[count] > max)
			max = parents[count];
		count++;
	}
	//find root index;
	int intRoot;
	string stringRoot;
	for (int i = 0; i < size; i++){
		if (parents[i] == -1) {
			stringRoot = names[i];
			intRoot = parents[i];
			parentCounter++;
		}
	}
	//move rest of array
	for (int i = 1; i < size; i++) {
			namesPrint[parentCounter] = names[i-1];
			parentsPrint[parentCounter] = parents[i-1];
			parentCounter++;
	}
	//sort nodes
	/*
	for (int i = 0; i < size-1; i++) {
		for (int j = 0; j < size-i-1; j++) {
			if (parentsPrint[j] < parentsPrint[j + 1]) {
				swap(&parentsPrint[j], &parentsPrint[j + 1]);
				swap(&namesPrint[j], &namesPrint[j + 1]);
			}
		}
	}
	*/
	namesPrint[0] = stringRoot;
	parentsPrint[0] = intRoot;

	int j = size-1;
	parentCounter = 1;
	
	//draw tree
	for (int i = 0; i < size; i++) {
		if (parentsPrint[i] == -1) {
			cout << "+-" << namesPrint[i] << endl;
		}
		else if (parentsPrint[i] == max) {
			cout << "  +-" << namesPrint[i] << endl;
		}
		else if (parentsPrint[i] < max) {
			count = 0;
			cout << "  |";
			while(count < parentsPrint[i] - 1){ 
				cout << "  "; 
				count++;
			}
			cout << "+-" << namesPrint[i] << endl;
		}
	}

	for (int i = 0; i < size; i++) {
		//cout << namesPrint[i] << endl;
	}
}

int main() {
	int exampleA[8] = { -1,0,1,1,0,0,5,5 };
	string arrA[8] = { "Root","SubB","LEAF1","LEAF2","LEAF3","SubA","LEAF4","LEAF5" };
	int exampleB[8] = { 1,2,3,4,5,6,-1 };
	string arrB[8] = { "A","B","C","D","E","F","G" };
	int exampleC[8] = { 1,2,3,4,6,6,-1 };
	string arrC[8] = { "A","B","C","D","E","F","G" };
	int exampleD[8] = { 6,2,3,4,5,6,-1 };
	string arrD[8] = { "A","B","C","D","E","F","G" };
	int exampleE[15] = { -1,0,1,1,2,2,3,3,0,8,8,9,9,10,10 };
	string arrE[15] = { "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O" };

	cout << "ExampleA: " << "\n";
	drawTree(arrA, exampleA, 8);
	cout << "ExampleB: " << endl;
	drawTree(arrB, exampleB, 8);
	cout << "ExampleC: " << endl;
	drawTree(arrC, exampleC, 8);
	cout << "ExampleD: " << endl;
	drawTree(arrD, exampleD, 8);
	cout << "ExampleE: " << endl;
	drawTree(arrE, exampleE, 15);
}