//Add check for visited 

#include <iostream>
#include <fstream>


using namespace std;

class Board{

public:
  Board(int i, int j){
    visited = new bool[i * j];
    rows = i;
    cols = j;
  }

  ~Board(){}

  void drawBoard(){
    for(int i = 0; i < rows; i++){
      for(int j = 0; j < cols; j++){
        if(visited[rows*i + j]) cout << "1";
        else cout << "-";
      }
      cout << endl;
    }
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
  }
  bool tour(int i, int j, int count){
    //if out of bounds - return false
    if(i < 0 || i > cols){
      *myfile << "DEAD" << endl;
      cout << "DEAD" << endl;
      return false;
    }

    if(j < 0 || j > rows){
      *myfile << "DEAD" << endl;
      cout << "DEAD" << endl;
      return false;
    }
    if(i == initialI && j == initialJ && count > 0)return true;
    if(count > 10000) {
      cout << "TOO MUCH RECURSION" << endl;
      return false;
    }

    *myfile << " I: " << i << "  |  J: " << j << endl;
    cout << " I: " << i << "  |  J: " << j << endl;

    //tour Left
    tour(i - 2, j + 1, count++);
    tour(i - 2, j - 1, count++);

    //tour Right
    tour(i + 2, j + 1, count++);
    tour(i + 2, j - 1, count++);

    //tour Top
    tour(i + 1, j + 2, count++);
    tour (i -1, j + 2, count++);

    //Tour Down
    tour(i + 1, j - 2, count++);
    tour(i - 1, j - 2, count++);

  }

private:
  int* i;
  int* j;
  int initialI;
  int initialJ;
  int rows, cols;
  ofstream* myfile;
};

int main(){

Board b(4,6);
b.drawBoard();
Knight k(1,1,3,3);
k.tour(1,1,0);



  return 0;
}
