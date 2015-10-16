    this.k = function(arr, capacity)  ///rewrite dynamic solution mutha fucka!

      {
              var max = new this.item(),  space;
              if(capacity < 0)
                {
                  var nullItem = new this.Item();
                  return nullItem;
                }
              for(var i = 0; i < arr.length; i++)
                 {

                  space = capacity - arr[i];
                  if(space >= 0)
                    {
                      var t1 = new this.item();
                      var t2 = this.k(arr, space);
                      t1.max = arr[i] + t2.max; //add max
                      t1.items.push(arr[i]);
                     for(var j = 0; j < t2.items.length; j++){ t1.items.push(t2.items[j]);}

                      if (t1.max >= max.max){max = t1;}
                    }
                  }
              return max;
      }

    this.item = function()
      {
        this.max = 0;
        this.items = [];
        this.getItems = function(){return this.items;}

      }
  }


var arr = [1,2,3,4];
var c = new Knap();
console.log(c.k(arr, 12));
