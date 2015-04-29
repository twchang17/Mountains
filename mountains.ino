
#include <MeggyJrSimple.h>    
int X=1;
int Y=7;
int change = random(4) - 2;
boolean gameOver = false;
int mountains [] = {0,0,0,0,0,0,0,5};

void setup()                    
{
  MeggyJrSimpleSetup();      
}

void loop()                     
{
 while (gameOver == false)
{
  DrawPx(X,Y,4);
  if(collide() == true)
  {
    gameOver=true;
  }
  playerMovement();
  drawMountains();
  updateMountains();
  DisplaySlate();
  delay(100);
  ClearSlate(); 
}
  displayX();
}  

void drawMountains()
{
  for(int i = 0; i < 8; i++)  // interate through the array (0-7) (i)
    for(int j = 0; j < mountains[i]; j++)// iterate the number of times specified by the value and the index (j) 
      DrawPx(i,j,2); // DrawPx (i,j,2)
  
}

void updateMountains() {
  for(int i = 0; i < 8; i++) { // iterate through array (0-7)
   mountains[i]=mountains[i+1];// index 0 takes the value of index 1
   } // index takes the value of index 2 
   mountains[7]=random(6); // index 7 takes some random number
}

boolean collide() {
  if(Y<mountains[X])
  return true;
 else return false;
}

void displayX()
{
  DrawPx(3,4,5);
  DisplaySlate();
  CheckButtonsPress();
  if(Button_A) {
    gameOver=false;
  (X=1 , Y=7);  
  }  
}  

void playerMovement()
{
  CheckButtonsPress(); //up
  if (Button_Up)
  {
    Y++;
  }
  
  if (Button_Down) //down
  {
    Y--;
  }  
  
  if(Button_Left) //left
  {
    X--; 
  }
  
  if(Button_Right) //right
  {
    X++;
  }     
  
  if(X>7)
  {  
    X--;
  }
  
  if(X<0)
  {
    X++;
  }
  
  if(Y>7)
  {
    Y--;
  }
  
  if(Y<0)
  {
    Y++;
  }
}
