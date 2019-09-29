# SnakeSFML


SnakeSFML features 

Will you be able to beat the hard mode ? (Beating hard mode, is actually attaining maximum snake length ;) ) 

### Requirements
In order to compile this code, you'll need SFML installed. A quick way to do it on linux (debian based): 

  ```sudo apt install libsfml-dev```
  
### Compile
Simply type : 
``` make ```

or if you're keen to compile it by hand : 
```g++ -c include/*.hpp src/*.cpp && g++ *.o -o snake -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio && ./snake ```

![Play](resources/play.gif)

Have fun :)! 

