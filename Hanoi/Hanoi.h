

class Hanoi{

public:
  Hanoi(int n);
  int  h(int n, int source, int dest, int aux);



private:
int  move(int numDisk, int source, int dest);
int numDisk;

};
