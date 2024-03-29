#include <stdio.h>
#include <iostream>

typedef struct node {
	int num;
	int state[3][3];
	struct node* next1;
	struct node* next2;
	struct node* next3;
	struct node* next4;
	struct node* father;
}node;

using namespace std;

bool compare(node* a, node* b);
bool canUp(node* n);
bool canDown(node* n);
bool canRight(node* n);
bool canLeft(node* n);
node* moveUp(node* n);
node* moveRight(node* n);
node* moveDown(node* n);
node* moveLeft(node* n);

node* start(node* goal);
int createNodes(node* father,  int n);
void show(node* n);


int main() {
	
	
	//Pruebas
	

	return 0;
}


node* start(node* goal) {
	node* head = NULL;
	head = (node*)malloc(sizeof(node));
	//BUENO int starter[9] = { 1,2,0,4,5,3,7,8,9 };
	//PRUEBA 
	int starter[9] = {1,2,0,4,5,3,6,7,8};
	int goalS[9] = { 1,2,3,4,5,6,7,8,0 };

	int flag = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			head->state[i][j] = starter[flag];
			goal->state[i][j] = goalS[flag];
			flag++;
		}
	}
	head->num = 0;
	return head;
}
int createNodes(node* father, int n) {
	int naux = n;
	//Up
	if (canUp(father)) {
		node* son1 = NULL;
		son1 = (node*)malloc(sizeof(node));
		son1 = moveUp(father);
		naux++;
		son1->num = naux;
		father->next1 = son1;
		father->next1->father = father;
	}else { father->next1 = NULL; }
	//Right
	if (canRight(father)) {
		node* son2 = NULL;
		son2 = (node*)malloc(sizeof(node));
		son2 = moveRight((node*)father);
		naux++;
		son2->num = naux;
		father->next2 = son2;
		father->next2->father = father;
	}
	else { father->next2 = NULL; }
	//Down
	if (canDown(father)) {
		node* son3 = NULL;
		son3 = (node*)malloc(sizeof(node));
		son3 = moveDown(father);
		naux++;
		son3->num = naux;
		father->next3 = son3;
		father->next3->father = father;
	}
	else { father->next3 = NULL; }
	//Left
	if (canLeft(father)) {
		node* son4 = NULL;
		son4 = (node*)malloc(sizeof(node));
		son4 = moveLeft(father);
		naux++;
		son4->num = naux;
		father->next4 = son4;
		father->next4->father = father;
	}
	else { father->next4 = NULL; }
	return naux;
}
bool canUp(node* n) {
	int y;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (n->state[i][j] == 0) {
				y = i;
			}
		}
	}
	if (y == 2) { return false; }
	else { return true; }
}
bool canDown(node* n) {
	int y;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (n->state[i][j] == 0) {
				y = i;
			}
		}
	}
	if (y == 0) { return false; }
	else { return true; }
}
bool canLeft(node* n) {
	int x;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (n->state[i][j] == 0) {
				x = j;
			}
		}
	}
	if (x == 2) { return false; }
	else { return true; }
}
bool canRight(node* n) {
	int x;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (n->state[i][j] == 0) {
				x = j;
			}
		}
	}
	if (x == 0) { return false; }
	else { return true; }
}
node* moveDown(node* n) {
	node* temp = NULL;
	temp = (node*)malloc(sizeof(node));
	int aux, x, y;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			temp->state[i][j] = n->state[i][j];
			if (n->state[i][j] == 0) {
				x = j;
				y = i;
			}
		}
	}
	aux = n->state[y - 1][x];
	temp->state[y - 1][x] = 0;
	temp->state[y][x] = aux;
	return temp;
}
node* moveUp(node* n) {
	node* temp = NULL;
	temp = (node*)malloc(sizeof(node));
	int aux, x, y;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			temp->state[i][j] = n->state[i][j];
			if (n->state[i][j] == 0) {
				x = j;
				y = i;
			}
		}
	}
	aux = n->state[y + 1][x];
	temp->state[y + 1][x] = 0;
	temp->state[y][x] = aux;
	return temp;
}
node* moveLeft(node* n) {
	node* temp = NULL;
	temp = (node*)malloc(sizeof(node));
	int aux, x, y;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			temp->state[i][j] = n->state[i][j];
			if (n->state[i][j] == 0) {
				x = j;
				y = i;
			}
		}
	}
	aux = n->state[y][x+1];
	temp->state[y][x+1] = 0;
	temp->state[y][x] = aux;
	return temp;
}
node* moveRight(node* n) {
	node* temp = NULL;
	temp = (node*)malloc(sizeof(node));
	int aux, x, y;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			temp->state[i][j] = n->state[i][j];
			if (n->state[i][j] == 0) {
				x = j;
				y = i;
			}
		}
	}
	aux = n->state[y][x - 1];
	temp->state[y][x - 1] = 0;
	temp->state[y][x] = aux;
	return temp;
}
bool compare(node* a, node* b) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (a->state[i][j] != b->state[i][j]) { return false; }
		}
		cout << endl;
	}
	return true;
}
void show(node* n) {
	cout << "Nodo numero: " << n->num << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << n->state[i][j] << " ";
		}
		cout << endl;
	}
}
