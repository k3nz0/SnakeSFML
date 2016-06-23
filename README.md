# SnakeSFML

This is my very first SFML game. Feel free to criticize my dirty code and help me improve it :p.

### Requirements
In order to compile this code, you'll need SFML installed. A quick way to do it on linux (debian based): 

  ```sudo apt-get install libsfml-dev```
  
### Compile
```g++ -c include/*.hpp src/*.cpp && g++ *.o -o snake -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio && ./snake ```

or type :
``` make ```

Have fun :)! 

