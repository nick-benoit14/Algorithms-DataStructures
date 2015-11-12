//TODO  unvisit dead end paths
//      return false if no true paths

#include <iostream>
#include <fstream>


using namespace std;

class Board{

public:
  Board(int i, int j){
    visited = new bool[i * j];
    for(int k = 0; k < i * j; k++) visited[k] = 0;
    rows = i;
    cols = j;
  }

  ~Board(){}

  void drawBoard(int inI, int inJ){
    for(int i = 0; i < rows; i++){
      for(int j = 0; j < cols; j++){
        int k = (i * cols + j);
        if(i == inI && j == inJ)cout << "o";
        else if(visited[k])cout << "1";
        else cout << "-";
      }
      cout << endl;
    }
  }

  bool isVisited(int i, int j){
    if (!visited[(cols*i) + j]){
      visited[(cols*i) + j] = true;
      return false;
    }
    else return true;
  }

private:
  bool*  visited;
  int rows;
  int cols;
};

class Knight{
public:
  Knight(int i, int j, int r, int c){
    initialI = i;
    initialJ = j;
    rows = r;
    cols = c;
    myfile = new ofstream("moves.txt");
    board = 0;
    numMoves = 0;
    attempts = 0;
  }

  Knight(int i, int j, int r, int c, Board* b){
    initialI = i;
    initialJ = j;
    rows = r;
    cols = c;
    myfile = new ofstream("moves.txt");
    board = b;
    visited = new bool[i * j];
    numMoves = 0;
    attempts = 0;



  }

  bool tour(int i, int j){

    attempts++; //keep track of number of moves

    if(board){
      board->isVisited(i,j); //board visited
      cout << endl << endl << endl;
      board->drawBoard(i,j);
      cout << "I: " << i << "  :  " << "J: " << j << endl;
    }

    //char step;
    //cout << "Press any key to step: "; //step by step
    //cin >> step;


    if(i == initialI && j == initialJ && attempts > 1)return true; //Done

    if(visited[cols * i + j]) return false; //dont revist squares
    visited[cols * i + j] = 1;

    //if out of bounds - return false
    if(i < 0 || i > cols){
      //*myfile << "DEAD" << endl;
      //cout << "DEAD" << endl;
      return false;
    }

    if(j < 0 || j > rows){
      //*myfile << "DEAD" << endl;
      //cout << "DEAD" << endl;
      return false;
    }

    *myfile << " I: " << i << "  |  J: " << j << endl;
     numMoves++;
    //cout << " I: " << i << "  |  J: " << j << endl;

    //tour Left
   if(!tour(i - 2, j + 1)){
     visited[cols * (i-2) + (j+1)] = 0; //unvisit
     return false;
   }
   else return true;

   tour(i - 2, j - 1);

    //tour Right
   tour(i + 2, j + 1);
   tour(i + 2, j - 1);

    //tour Top
   tour(i + 1, j + 2);
   tour (i -1, j + 2);

    //Tour Down
  tour(i + 1, j - 2);
  tour(i - 1, j - 2);

  }

  void statusReport(){
  *myfile << "Number of Attempted moves: " << attempts << endl;
  *myfile << "Number of Correct moves: " << numMoves << endl;


  }

private:
  int* i;
  int* j;
  int initialI;
  int initialJ;
  int rows, cols;
  bool* visited;
  ofstream* myfile;
  Board* board;
  int numMoves;
  int attempts;
};

int main(){

Board* b = new Board(6,4);
Knight k(0,0,6,4, b);
k.tour(0,0);
k.statusReport();

  return 0;
}
