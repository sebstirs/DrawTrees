#include <iostream>
#include <string>

using namespace std;
//swaps
void swap(string *x, string *y) {
	string temp = *x;
	*x = *y;
	*y = temp;
}
void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}
//drawtrees func
string drawTree(string names[], int parents[], int size) {
	//find root note set to index 0
	for (int i = 0; i < size; i++) {
		int x = size;
		if (parents[i] == -1 && i != 0) {
			int temp = parents[i];
			string tempS = names[i];
			for (int j = 0; j <= size; j++)
			{
				parents[j+1] = parents[j ]; //move all element to the left except first one
				names[j + 1] = names[j];
			}
			parents[0] = temp;
			names[0] = tempS;
			break;
		}
	}
	//find max
	int max = parents[1];
	for (int i = 1; i < max; i++) {
		if (parents[i] > max)
			max = parents[i];
	}
	//find parent node
	/*
	int count = 1;
	for (int i = 1; i < size; i++) {

		if (parents[i] == max) {
			int temp = parents[i];
			string tempS = names[i];
			int j = size;
			while (j - 1 > 1) {
				swap(parents[j - 1], parents[j]);
				swap(names[j - 1], names[j]);
				j--;
			}
			parents[0] = temp;
			names[0] = tempS;
			break;
		}
	}
	*/
	//print tree
	for (int i = 0; i < size; i++) {
		cout << names[i] << endl;
	}
	return "success";
}

int main() {
	int exampleA[8] = { -1,0,1,1,0,0,5,5 };
	string arrA[8] = {"Root","SubB","LEAF1","LEAF2","LEAF3","SubA","LEAF4","LEAF5"};
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

	return 0;
}