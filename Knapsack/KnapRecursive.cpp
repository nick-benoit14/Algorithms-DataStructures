// check out optimal substructure
//think abour recombining values
#include <iostream>

class Knap
  {
  public:

    Knap(int* v, int l, int cap)
      {
        val = v;
        length = l;
        depth = 0;
      std::cout << "Max: "  << k(cap) << std::endl;
      }

      int k(int cap)
        {
            for(int i = 0; i < depth; i++) std::cout << " ";
            std::cout << "knap(" << cap << ")" << std::endl;
            depth++;

            int space, max = 0;
            for(int i = 0; i < length; i++)
              {
                //add next item in list
                  //if item in list fits
                      //if item > max
                          //max = item
                space = cap - val[i];

                if(space > 0) //if there is space
                  {
                    std::cout << "space : " << space << std::endl;

                    if(max + val[i] > max)
                      {
                      max = max + val[i];
                      std::cout << "max: " << max << std::endl;
                      }
                  return max +  k(space);
                  }
             }
            return max;
        }
  private:
      int * val;
      int length;
      int depth;

  };




int main()
  {

    //int v[] = {1,2,3,4,5,6,7,8};
    int * v;
    v = new int[3];
    for(int i = 0; i < 3; i++)v[i] = i+1;

    int l = 3;

    Knap k(v, l, 4);

  }

  //arrVal[]
  //cap
  //space
