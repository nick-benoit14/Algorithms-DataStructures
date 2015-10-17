#include <iostream>

class Knap
  {
  public:

    Knap(int* v, int l, int inCap)
      {
        val = v;
        length = l;
        depth = 0;
        cap = inCap;
      std::cout << "Max: "  << k(cap) << std::endl;
      }

      int k(int c)
        {
            for(int i = 0; i < depth; i++) std::cout << "    "; //print tree structure
            std::cout << "knap(" << c << ")" << std::endl;
            depth = cap - c;


            if(c < 0)return 0; //Dont go too deep!
            int space, max = 0, t;
            for(int i = 0; i < length; i++) //Try each value - look for maximum structure
              {
                  space = c - val[i];
                if(space  >= 0) //if there is space
                  {
                    t = k(space) + val[i];
                    if(t > max) max = t; //try to add item. If greater than max then it is new max
                  }
             }
            return max;
        }
  private:
      int * val;
      int length;
      int depth;
      int cap;

  };




int main()
  {

    int * v;
    v = new int[3];
    for(int i = 0; i < 3; i++)v[i] = i+2;
    int l = 3;

    Knap k(v, l, 10);

    int *r = new int[2];
    r[0] = 3;
    r[1] = 6;

    Knap q(r, 2, 100); //Such massive recomputation im not even sure this will ever finish

  }
