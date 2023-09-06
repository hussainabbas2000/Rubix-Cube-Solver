#include<iostream>
#include<string>
#include<vector>
#include<list>
using namespace std;


void RotateFaceClockwise(char arr[3][3]) {
	for (int i = 0; i < 3 / 2; i++) {
		for (int j = i; j < 3 - i - 1; j++) {

			// Swap elements of each cycle
			// in clockwise direction
			int temp = arr[i][j];
			arr[i][j] = arr[3 - 1 - j][i];
			arr[3- 1 - j][i] = arr[3 - 1 - i][3 - 1 - j];
			arr[3 - 1 - i][3 - 1 - j] = arr[j][3 - 1 - i];
			arr[j][3 - 1 - i] = temp;
		}
	}
}
void RotateFaceAntiClockwise(char arr[3][3]) {
	for (int x = 0; x < 3 / 2; x++) {
		// Consider elements in group
		// of 4 in current square
		for (int y = x; y < 3 - x - 1; y++) {
			// Store current cell in
			// temp variable
			int temp = arr[x][y];

			// Move values from right to top
			arr[x][y] = arr[y][3 - 1 - x];

			// Move values from bottom to right
			arr[y][3 - 1 - x]
				= arr[3 - 1 - x][3 - 1 - y];

			// Move values from left to bottom
			arr[3 - 1 - x][3 - 1 - y]
				= arr[3 - 1 - y][x];

			// Assign temp to left
			arr[3 - 1 - y][x] = temp;
		}
	}
}
class RubixCube {
	
public:
	char face1[3][3];
	char face2[3][3];
	char face3[3][3];
	char face4[3][3];
	char face5[3][3];
	char face6[3][3];
	RubixCube* prev;
	RubixCube* move1;
	RubixCube* move2;
	RubixCube* move3;
	RubixCube* move4;
	RubixCube* move5;
	RubixCube* move6;
	RubixCube* move7;
	RubixCube* move8;
	RubixCube* move9;
	RubixCube* move10;
	RubixCube* move11;
	RubixCube* move12;
	RubixCube() {
		prev = nullptr;
		move1 = nullptr;
		move2 = nullptr;
		move3 = nullptr;
		move4 = nullptr;
		move5 = nullptr;
		move6 = nullptr;
		move7 = nullptr;
		move8 = nullptr;
		move9 = nullptr;
		move10 = nullptr;
		move11 = nullptr;
		move12= nullptr;

		face1[0][0] = 'G';
		face1[0][1] = 'G';
		face1[0][2] = 'G';
		face1[1][0] = 'G';
		face1[1][1] = 'G';
		face1[1][2] = 'G';
		face1[2][0] = 'G';
		face1[2][1] = 'G';
		face1[2][2] = 'G';

		face2[0][0] = 'Y';
		face2[0][1] = 'Y';
		face2[0][2] = 'Y';
		face2[1][0] = 'Y';
		face2[1][1] = 'Y';
		face2[1][2] = 'Y';
		face2[2][0] = 'Y';
		face2[2][1] = 'Y';
		face2[2][2] = 'Y';

		face3[0][0] = 'B';
		face3[0][1] = 'B';
		face3[0][2] = 'B';
		face3[1][0] = 'B';
		face3[1][1] = 'B';
		face3[1][2] = 'B';
		face3[2][0] = 'B';
		face3[2][1] = 'B';
		face3[2][2] = 'B';

		face4[0][0] = 'W';
		face4[0][1] = 'W';
		face4[0][2] = 'W';
		face4[1][0] = 'W';
		face4[1][1] = 'W';
		face4[1][2] = 'W';
		face4[2][0] = 'W';
		face4[2][1] = 'W';
		face4[2][2] = 'W';


		face5[0][0] = 'R';
		face5[0][1] = 'R';
		face5[0][2] = 'R';
		face5[1][0] = 'R';
		face5[1][1] = 'R';
		face5[1][2] = 'R';
		face5[2][0] = 'R';
		face5[2][1] = 'R';
		face5[2][2] = 'R';

		face6[0][0] = 'P';
		face6[0][1] = 'P';
		face6[0][2] = 'P';
		face6[1][0] = 'P';
		face6[1][1] = 'P';
		face6[1][2] = 'P';
		face6[2][0] = 'P';
		face6[2][1] = 'P';
		face6[2][2] = 'P';
	}
	void print() {
		for (int i = 0; i < 3;i++) {
			for (int j = 0; j < 3;j++) {
				cout << "|" << face1[i][j];
			}
			cout << endl;
		}
		cout << endl;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << "|" << face2[i][j];
			}
			cout << endl;
		}
		cout << endl;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << "|" << face3[i][j];
			}
			cout << endl;
		}
		cout << endl;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << "|" << face4[i][j];
			}
			cout << endl;
		}
		cout << endl;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << "|" << face5[i][j];
			}
			cout << endl;
		}
		cout << endl;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << "|" << face6[i][j];
			}
			cout << endl;
		}
		cout << endl;

	}
	void moveUp(int face,int col) {
		if (face == 1) {
			if (col==0) {
				RotateFaceAntiClockwise(this->face4);
			}
			if (col==2) {
				RotateFaceClockwise(this->face2);
			}
			string temp = "";
			temp = temp + face5[0][col] + face5[1][col] + face5[2][col];
			face5[0][col]=face1[0][col];
			face5[1][col]=face1[1][col];
			face5[2][col]=face1[2][col];
			string temp2 = "";
			temp2 = temp2 + face3[0][col] + face3[1][col] + face3[2][col];
			face3[0][col] = temp[0];
			face3[1][col] = temp[1];
			face3[2][col] = temp[2];
			temp = temp2;
			temp2 = "";
			temp2 = temp2 + face6[0][col] + face6[1][col] + face6[2][col];
			face6[0][col] = temp[0];
			face6[1][col] = temp[1];
			face6[2][col] = temp[2];
			temp = temp2;
			temp2 = "";
			face1[0][col] = temp[0];
			face1[1][col] = temp[1];
			face1[2][col] = temp[2];
		} 
		else if (face==2) {
			string temp = "";
			temp = temp + face5[0][col] + face5[1][col] + face5[2][col];
			face5[0][col] = face2[0][col];
			face5[1][col] = face2[1][col];
			face5[2][col] = face2[2][col];
			string temp2 = "";
			temp2 = temp2 + face4[0][col] + face4[1][col] + face4[2][col];
			face4[0][col] = temp[0];
			face4[1][col] = temp[1];
			face4[2][col] = temp[2];
			temp = temp2;
			temp2 = "";
			temp2 = temp2 + face6[0][col] + face6[1][col] + face6[2][col];
			face6[0][col] = temp[0];
			face6[1][col] = temp[1];
			face6[2][col] = temp[2];
			temp = temp2;
			temp2 = "";
			face2[0][col] = temp[0];
			face2[1][col] = temp[1];
			face2[2][col] = temp[2];
		}
		else if (face==3) {
			string temp = "";
			temp = temp + face5[0][col] + face5[1][col] + face5[2][col];
			face5[0][col] = face3[0][col];
			face5[1][col] = face3[1][col];
			face5[2][col] = face3[2][col];
			string temp2 = "";
			temp2 = temp2 + face1[0][col] + face1[1][col] + face1[2][col];
			face1[0][col] = temp[0];
			face1[1][col] = temp[1];
			face1[2][col] = temp[2];
			temp = temp2;
			temp2 = "";
			temp2 = temp2 + face6[0][col] + face6[1][col] + face6[2][col];
			face6[0][col] = temp[0];
			face6[1][col] = temp[1];
			face6[2][col] = temp[2];
			temp = temp2;
			temp2 = "";
			face3[0][col] = temp[0];
			face3[1][col] = temp[1];
			face3[2][col] = temp[2];
		}
		else if (face==4) {
			string temp = "";
			temp = temp + face5[0][col] + face5[1][col] + face5[2][col];
			face5[0][col] = face4[0][col];
			face5[1][col] = face4[1][col];
			face5[2][col] = face4[2][col];
			string temp2 = "";
			temp2 = temp2 + face2[0][col] + face2[1][col] + face2[2][col];
			face2[0][col] = temp[0];
			face2[1][col] = temp[1];
			face2[2][col] = temp[2];
			temp = temp2;
			temp2 = "";
			temp2 = temp2 + face6[0][col] + face6[1][col] + face6[2][col];
			face6[0][col] = temp[0];
			face6[1][col] = temp[1];
			face6[2][col] = temp[2];
			temp = temp2;
			temp2 = "";
			face4[0][col] = temp[0];
			face4[1][col] = temp[1];
			face4[2][col] = temp[2];
		}
		else if (face==5) {
			string temp = "";
			temp = temp + face5[0][col] + face5[1][col] + face5[2][col];
			face1[0][col] = face5[0][col];
			face1[1][col] = face5[1][col];
			face1[2][col] = face5[2][col];
			string temp2 = "";
			temp2 = temp2 + face6[0][col] + face6[1][col] + face6[2][col];
			face6[0][col] = temp[0];
			face6[1][col] = temp[1];
			face6[2][col] = temp[2];
			temp = temp2;
			temp2 = "";
			temp2 = temp2 + face3[0][col] + face3[1][col] + face3[2][col];
			face3[0][col] = temp[0];
			face3[1][col] = temp[1];
			face3[2][col] = temp[2];
			temp = temp2;
			temp2 = "";
			face5[0][col] = temp[0];
			face5[1][col] = temp[1];
			face5[2][col] = temp[2];
		}
		else {
			string temp = "";
			temp = temp + face3[0][col] + face3[1][col] + face3[2][col];
			face3[0][col]=face6[0][col];
			face3[1][col]=face6[1][col];
			face3[2][col]=face6[2][col];
			string temp2 = "";
			temp2 = temp2 + face5[0][col] + face5[1][col] + face5[2][col];
			face5[0][col] = temp[0];
			face5[1][col] = temp[1];
			face5[2][col] = temp[2];
			temp = temp2;
			temp2 = "";
			temp2 = temp2 + face1[0][col] + face1[1][col] + face1[2][col];
			face1[0][col] = temp[0];
			face1[1][col] = temp[1];
			face1[2][col] = temp[2];
			temp = temp2;
			temp2 = "";
			face6[0][col] = temp[0];
			face6[1][col] = temp[1];
			face6[2][col] = temp[2];

		}
	}
	void moveDown(int face, int col) {		
		moveUp(face,col);
		moveUp(face, col);
		moveUp(face, col);		
	}
	void moveRight(int face,int row) {
		if (face==1) {
			if (row==0) {
				RotateFaceAntiClockwise(this->face5);
			}
			if (row==2) {
				RotateFaceClockwise(this->face6);
			}
			string temp = "";
			temp = temp + face2[row][0] + face2[row][1] + face2[row][1];
			face2[row][0] = face1[row][0];
			face2[row][1] = face1[row][1];
			face2[row][2] = face1[row][2];
			string temp2 = "";
			temp2 = temp2 + face3[row][0] + face3[row][1] + face3[row][2];
			face3[row][0] = temp[0];
			face3[row][1] = temp[1];
			face3[row][2] = temp[2];
			temp = temp2;
			temp2 = "";
			temp2 = temp2 + face4[row][0] + face4[row][1] + face4[row][2];
			face4[row][0] = temp[0];
			face4[row][1] = temp[1];
			face4[row][2] = temp[2];
			temp = temp2;
			temp2 = "";
			face1[row][0] = temp[0];
			face1[row][1] = temp[1];
			face1[row][2] = temp[2];
		}
		else if (face==2) {
			string temp = "";
			temp = temp + face2[row][0] + face2[row][1] + face2[row][1];
			face2[row][0] = face1[row][0];
			face2[row][1] = face1[row][1];
			face2[row][2] = face1[row][2];
			string temp2 = "";
			temp2 = temp2 + face3[row][0] + face3[row][1] + face3[row][2];
			face3[row][0] = temp[0];
			face3[row][1] = temp[1];
			face3[row][2] = temp[2];
			temp = temp2;
			temp2 = "";
			temp2 = temp2 + face4[row][0] + face4[row][1] + face4[row][2];
			face4[row][0] = temp[0];
			face4[row][1] = temp[1];
			face4[row][2] = temp[2];
			temp = temp2;
			temp2 = "";
			face1[row][0] = temp[0];
			face1[row][1] = temp[1];
			face1[row][2] = temp[2];
		}
		else if (face == 3) {
			string temp = "";
			temp = temp + face2[row][0] + face2[row][1] + face2[row][1];
			face2[row][0] = face1[row][0];
			face2[row][1] = face1[row][1];
			face2[row][2] = face1[row][2];
			string temp2 = "";
			temp2 = temp2 + face3[row][0] + face3[row][1] + face3[row][2];
			face3[row][0] = temp[0];
			face3[row][1] = temp[1];
			face3[row][2] = temp[2];
			temp = temp2;
			temp2 = "";
			temp2 = temp2 + face4[row][0] + face4[row][1] + face4[row][2];
			face4[row][0] = temp[0];
			face4[row][1] = temp[1];
			face4[row][2] = temp[2];
			temp = temp2;
			temp2 = "";
			face1[row][0] = temp[0];
			face1[row][1] = temp[1];
			face1[row][2] = temp[2];
		}
		else if (face == 4) {
			string temp = "";
			temp = temp + face2[row][0] + face2[row][1] + face2[row][1];
			face2[row][0] = face1[row][0];
			face2[row][1] = face1[row][1];
			face2[row][2] = face1[row][2];
			string temp2 = "";
			temp2 = temp2 + face3[row][0] + face3[row][1] + face3[row][2];
			face3[row][0] = temp[0];
			face3[row][1] = temp[1];
			face3[row][2] = temp[2];
			temp = temp2;
			temp2 = "";
			temp2 = temp2 + face4[row][0] + face4[row][1] + face4[row][2];
			face4[row][0] = temp[0];
			face4[row][1] = temp[1];
			face4[row][2] = temp[2];
			temp = temp2;
			temp2 = "";
			face1[row][0] = temp[0];
			face1[row][1] = temp[1];
			face1[row][2] = temp[2];
		}
		else if (face == 5) {
			string temp = "";
			temp = temp + face4[row][0] + face4[row][1] + face4[row][1];
			face4[row][0] = face5[row][0];
			face4[row][1] = face5[row][1];
			face4[row][2] = face5[row][2];
			string temp2 = "";
			temp2 = temp2 + face6[row][0] + face6[row][1] + face6[row][2];
			face6[row][0] = temp[0];
			face6[row][1] = temp[1];
			face6[row][2] = temp[2];
			temp = temp2;
			temp2 = "";
			temp2 = temp2 + face2[row][0] + face2[row][1] + face2[row][2];
			face2[row][0] = temp[0];
			face2[row][1] = temp[1];
			face2[row][2] = temp[2];
			temp = temp2;
			temp2 = "";
			face5[row][0] = temp[0];
			face5[row][1] = temp[1];
			face5[row][2] = temp[2];
		}
		else {
		string temp = "";
		temp = temp + face4[row][0] + face4[row][1] + face4[row][1];
		face4[row][0] = face5[row][0];
		face4[row][1] = face5[row][1];
		face4[row][2] = face5[row][2];
		string temp2 = "";
		temp2 = temp2 + face6[row][0] + face6[row][1] + face6[row][2];
		face6[row][0] = temp[0];
		face6[row][1] = temp[1];
		face6[row][2] = temp[2];
		temp = temp2;
		temp2 = "";
		temp2 = temp2 + face2[row][0] + face2[row][1] + face2[row][2];
		face2[row][0] = temp[0];
		face2[row][1] = temp[1];
		face2[row][2] = temp[2];
		temp = temp2;
		temp2 = "";
		face5[row][0] = temp[0];
		face5[row][1] = temp[1];
		face5[row][2] = temp[2];
		}
	}
	void moveLeft(int face,int row) {
		moveRight(face,row);
		moveRight(face, row);
		moveRight(face, row);
	}
	void operator =(RubixCube& r) {
		this->prev = r.prev;
		this->move1 = r.move1;
		this->move2 = r.move2;
		this->move4 = r.move4;
		this->move3 = r.move3;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				this->face1[i][j] = r.face1[i][j];				
			}
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				this->face2[i][j] = r.face2[i][j];			
			}
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				this->face3[i][j] = r.face3[i][j];
			}
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				this->face4[i][j] = r.face4[i][j];
					
				
			}
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				this->face5[i][j] = r.face5[i][j];
					
			}
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				this->face6[i][j] = r.face6[i][j];				
			}
		}
	}
	void solve() {
		// Mark all the vertices as not visited
		vector<RubixCube> visited;
		// Create a queue for BFS
		list<RubixCube> queue;
		RubixCube s;
		// Mark the current node as visited and enqueue it
		visited.push_back(*this);
		queue.push_back(*this);
		list<RubixCube>::iterator i;
		int count = 0;
		while (1)
		{
			// Dequeue a vertex from queue and print it
			s = queue.front();
			count++;
			cout << count << endl;
			s.print();
			queue.pop_front();
			RubixCube c1;
			RubixCube c2;
			RubixCube c3;
			RubixCube c4;
			RubixCube c5;
			RubixCube c6;
			RubixCube c7;
			RubixCube c8;
			RubixCube c9;
			RubixCube c10;
			RubixCube c11;
			RubixCube c12;
			// Get all adjacent vertices of the dequeued
			// vertex s. If a adjacent has not been visited,
			// then mark it visited and enqueue it
			s.moveDown(1,0);
			c1 = s;
			s.move1 = &c1;
			c1.prev = &s;
			bool p = true;
			for (int i = 0; i < visited.size();i++) {
				if (visited[i]==s) {
					p = false;
				}
			}
			if (p==true) {
				visited.push_back(s);
				queue.push_back(s);
			}
			p = true;
			if (s.isFinal()) {
				cout << "1" << endl;
				RubixCube* ptr = &s;
				while (ptr != nullptr) {
					ptr->print();
					ptr = ptr->prev;
				}				
				break;
			}
			s.moveUp(1,0);
			s.moveDown(1,1);
			c2 = s;
			s.move2 = &c2;
			c2.prev = &s;
			for (int i = 0; i < visited.size(); i++) {
				if (visited[i] == s) {
					p = false;
				}
			}
			if (p == true) {
				visited.push_back(s);
				queue.push_back(s);
			}
			p = true;
			if (s.isFinal()) {
				cout << "2" << endl;
				RubixCube* ptr = &s;
				while (ptr != nullptr) {
					ptr->print();
					ptr = ptr->prev;
				}
				break;
			}
			s.moveUp(1,1);
			s.moveDown(1,2);
			c3 = s;
			s.move3 = &c3;
			c3.prev = &s;
			for (int i = 0; i < visited.size(); i++) {
				if (visited[i] == s) {
					p = false;
				}
			}
			if (p == true) {
				visited.push_back(s);
				queue.push_back(s);
			}
			p = true;
			if (s.isFinal()) {
				cout << "3" << endl;
				RubixCube* ptr = &s;
				while (ptr != nullptr) {
					ptr->print();
					ptr = ptr->prev;
				}
				break;
			}
			s.moveUp(1,2);
			s.moveUp(1, 0);
			c4 = s;
			s.move4 = &c4;
			c4.prev = &s;
			p = true;
			for (int i = 0; i < visited.size(); i++) {
				if (visited[i] == s) {
					p = false;
				}
			}
			if (p == true) {
				visited.push_back(s);
				queue.push_back(s);
			}
			p = true;
			if (s.isFinal()) {
				cout << "4" << endl;
				RubixCube* ptr = &s;
				while (ptr != nullptr) {
					ptr->print();
					ptr = ptr->prev;
				}		
				break;
			}
			s.moveDown(1, 0);
			s.moveUp(1, 1);
			c5 = s;
			s.move5 = &c5;
			c5.prev = &s;
			for (int i = 0; i < visited.size(); i++) {
				if (visited[i] == s) {
					p = false;
				}
			}
			if (p == true) {
				visited.push_back(s);
				queue.push_back(s);
			}
			p = true;
			if (s.isFinal()) {
				cout << "5" << endl;
				RubixCube* ptr = &s;
				while (ptr != nullptr) {
					ptr->print();
					ptr = ptr->prev;
				}
				break;
			}
			s.moveDown(1, 1);
			s.moveUp(1, 2);
			c6 = s;
			s.move6 = &c6;
			c6.prev = &s;
			for (int i = 0; i < visited.size(); i++) {
				if (visited[i] == s) {
					p = false;
				}
			}
			if (p == true) {
				visited.push_back(s);
				queue.push_back(s);
			}
			p = true;
			if (s.isFinal()) {
				cout << "6" << endl;
				RubixCube* ptr = &s;
				while (ptr != nullptr) {
					ptr->print();
					ptr = ptr->prev;
				}
				break;
			}
			s.moveDown(1, 2);
			s.moveRight(1, 0);
			c7 = s;
			s.move7 = &c7;
			c7.prev = &s;
			p = true;
			for (int i = 0; i < visited.size(); i++) {
				if (visited[i] == s) {
					p = false;
				}
			}
			if (p == true) {
				visited.push_back(s);
				queue.push_back(s);
			}
			p = true;
			if (s.isFinal()) {
				cout << "7" << endl;
				RubixCube* ptr = &s;
				while (ptr != nullptr) {
					ptr->print();
					ptr = ptr->prev;
				}
				break;
			}
			s.moveLeft(1, 0);
			s.moveRight(1, 1);
			c8 = s;
			s.move8 = &c8;
			c8.prev = &s;
			for (int i = 0; i < visited.size(); i++) {
				if (visited[i] == s) {
					p = false;
				}
			}
			if (p == true) {
				visited.push_back(s);
				queue.push_back(s);
			}
			p = true;
			if (s.isFinal()) {
				cout << "8" << endl;
				RubixCube* ptr = &s;
				while (ptr != nullptr) {
					ptr->print();
					ptr = ptr->prev;
				}
				break;
			}
			s.moveLeft(1, 1);
			s.moveRight(1, 2);
			c9 = s;
			s.move9 = &c9;
			c9.prev = &s;
			for (int i = 0; i < visited.size(); i++) {
				if (visited[i] == s) {
					p = false;
				}
			}
			if (p == true) {
				visited.push_back(s);
				queue.push_back(s);
			}
			p = true;
			if (s.isFinal()) {
				cout << "9" << endl;
				RubixCube* ptr = &s;
				while (ptr != nullptr) {
					ptr->print();
					ptr = ptr->prev;
				}
				break;
			}
			s.moveLeft(1, 2);
			s.moveLeft(1, 0);
			c10 = s;
			s.move10 = &c10;
			c10.prev = &s;
			p = true;
			for (int i = 0; i < visited.size(); i++) {
				if (visited[i] == s) {
					p = false;
				}
			}
			if (p == true) {
				visited.push_back(s);
				queue.push_back(s);
			}
			p = true;
			if (s.isFinal()) {
				cout << "10" << endl;
				RubixCube* ptr = &s;
				while (ptr != nullptr) {
					ptr->print();
					ptr = ptr->prev;
				}
				break;
			}
			s.moveRight(1, 0);
			s.moveLeft(1, 1);
			c11 = s;
			s.move11= &c11;
			c11.prev = &s;
			for (int i = 0; i < visited.size(); i++) {
				if (visited[i] == s) {
					p = false;
				}
			}
			if (p == true) {
				visited.push_back(s);
				queue.push_back(s);
			}
			p = true;
			if (s.isFinal()) {
				cout << "11" << endl;
				RubixCube* ptr = &s;
				while (ptr != nullptr) {
					ptr->print();
					ptr = ptr->prev;
				}
				break;
			}
			s.moveRight(1, 1);
			s.moveLeft(1, 2);
			c12 = s;
			s.move12 = &c12;
			c12.prev = &s;
			for (int i = 0; i < visited.size(); i++) {
				if (visited[i] == s) {
					p = false;
				}
			}
			if (p == true) {
				visited.push_back(s);
				queue.push_back(s);
			}
			p = true;
			if (s.isFinal()) {
				cout << "12" << endl;
				RubixCube* ptr = &s;
				while (ptr != nullptr) {
					ptr->print();
					ptr = ptr->prev;
				}
				break;
			}
			s.moveRight(1, 2);

		}
		
		
	}
	bool operator ==(RubixCube& r) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (this->face1[i][j] != r.face1[i][j]) {
					return false;
				}
			}
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (this->face2[i][j] != r.face2[i][j]) {
					return false;
				}
			}
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (this->face3[i][j] != r.face3[i][j]) {
					return false;
				}
			}
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (this->face4[i][j] != r.face4[i][j]) {
					return false;
				}
			}
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (this->face5[i][j] != r.face5[i][j]) {
					return false;
				}
			}
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (this->face6[i][j] != r.face6[i][j]) {
					return false;
				}
			}
		}
		return true;
	}
	bool operator !=(RubixCube &r) {
		return !(*this == r);
	}
	bool isFinal() {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (face1[i][j]!='G') {
					return false;
				}
			}
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (face2[i][j] != 'Y') {
					return false;
				}
			}
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (face3[i][j] != 'B') {
					return false;
				}
			}
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (face4[i][j] != 'W') {
					return false;
				}
			}
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (face5[i][j] != 'R') {
					return false;
				}
			}
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (face6[i][j] != 'P') {
					return false;
				}
			}
		}
		return true;
	}
};
int main() {
	RubixCube c;
	c.moveRight(1,0);
	c.moveLeft(1, 2);
	c.solve();
	
}