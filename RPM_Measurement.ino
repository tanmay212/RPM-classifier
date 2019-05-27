//speed measurement using IR and LM393 comparator IC
#include <TimerOne.h>
unsigned int counter=0;


//sensor pin = 2 because 2 is directly connected to the Interrupt 0.
void docount()  // counts from the speed sensor
{
  counter++;  // increase +1 the counter value
} 

void timerIsr()
{
  Timer1.detachInterrupt();  //stop the timer
  Serial.print("Motor Speed: "); 
  int rotation = (counter / 20);  // divide by number of holes in Disc
  Serial.print(rotation,DEC);  //printing rotation in decimals
  Serial.println(" Rotation per seconds"); 
  counter=0;  //  reset counter to zero
  Timer1.attachInterrupt( timerIsr );  //enable the timer
}

void setup() 
{
  Serial.begin(9600);
  
  
  Timer1.initialize(1000000); // set timer for 1sec
  attachInterrupt(0, docount, RISING);  // increase counter when speed sensor pin goes High
  Timer1.attachInterrupt( timerIsr ); // enable the timer
} 

void loop()
{
  }
