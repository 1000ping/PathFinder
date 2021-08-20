
#include <iostream>
using namespace std;

#define N 8

bool solveMazeUtil(
	int maze[N][N], int x,
	int y, int x2, int y2, int sol[N][N]);



bool isSafe(int maze[N][N], int x, int y)
{

	if (
		x >= 0 && x < N && y >= 0
		&& y < N && (maze[x][y] == 1||maze[x][y] == 2||maze[x][y] == 3))
	{
		return true;
	}
	return false;
}


bool solveMaze(int maze[N][N],int X1,int Y1,int X2,int Y2)
{
	int sol[N][N] = {};
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			sol[i][j] = 0;
		}
	}
	if (solveMazeUtil(
		maze, X1, Y1,X2,Y2, sol)
		== false) {
		cout<<"Solution doesn't exist"<<endl<<endl;
		return false;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << sol[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
	return true;
}


bool solveMazeUtil(
	int maze[N][N], int x,
	int y, int x2, int y2, int sol[N][N])
{
	cout << "Chess board" << endl << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << maze[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "Path matrix" << endl << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << sol[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
	
	if (
		x == x2 && y == y2 
		&& maze[x][y] == 3) {
		sol[x][y] = 1;
		cout << "Solution exist"<<endl<<endl;
		return true;
	}

	
	if (isSafe(maze, x, y) == true) {
		
		if (sol[x][y] == 1)
			return false;

		
		sol[x][y] = 1;
		

		
		if (solveMazeUtil(
			maze, x + 1, y, x2, y2, sol)
			== true)
			return true;

	
		if (solveMazeUtil(
			maze, x, y + 1, x2, y2, sol)
			== true)
			return true;

	
		if (solveMazeUtil(
			maze, x - 1, y, x2, y2, sol)
			== true)
			return true;

		
		if (solveMazeUtil(
			maze, x, y - 1, x2, y2, sol)
			== true)
			return true;
		
		if (solveMazeUtil(
			maze, x + 1, y+1, x2, y2, sol)
			== true)
			return true;


		if (solveMazeUtil(
			maze, x-1, y + 1, x2, y2, sol)
			== true)
			return true;


		if (solveMazeUtil(
			maze, x - 1, y-1, x2, y2, sol)
			== true)
			return true;


		if (solveMazeUtil(
			maze, x+1, y - 1, x2, y2, sol)
			== true)
			return true;

		
	
		sol[x][y] = 0;
		return false;
	}

	return false;
}

int main()
{
	//int maze[N][N] = {{1,1,1,1,1,1,1,1},{0,1,0,0,0,0,0,1} ,{0,0,1,0,0,0,0,1}, {0,0,0,1,0,0,0,1} ,{0,0,0,0,1,0,0,1} ,{0,0,0,0,0,1,0,1} ,{0,0,0,0,0,0,1,1} ,{0,0,0,0,0,0,0,1} };
	//int maze[N][N] = {{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}};

	int maze[N][N] = {};

	
	srand(time(NULL));
	cout << "empty chess board." << endl;
	cout << "where 1 represents its whited out and you can move there." << endl << endl;

	for (int i=0;i<N;i++)
	{
		for (int j = 0; j < N; j++)
		{
			maze[i][j] = 1;
			cout <<maze[i][j]<<"  ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "a piece is placed on the chessboard which is represented by 2." << endl;
	cout << "this piece is placed on the board at a random whited out space." << endl << endl;

	int x1 = rand() % N;
	int y1 = rand() % N;

	maze[x1][y1] = 2;

	cout << "destination of that piece is also selected at random from the whited out pieced and is represented by 3." << endl << endl;

	int x2 = rand() % N;
	int y2 = rand() % N;
	while (x1 == x2 && y1 == y2)
	{
		x2 = rand() % N;
		y2 = rand() % N;
	}
	maze[x2][y2] = 3;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{

			cout << maze[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if ((rand() % 101) <= 30 && maze[i][j] != 2 && maze[i][j] != 3)
			{
				maze[i][j] = 0;
			}

			cout << maze[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
	solveMaze(maze,x1,y1,x2,y2);
	getchar();
	//solveMaze(maze, 3, 1, 1, 2);
	return 0; 
}
