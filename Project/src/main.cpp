//*----------------- JUST BREATH ------------- *//

//*---------- Team Details ---------------*//

/*
+-----------------+---------+
| Name            | NetID   |
+-----------------+---------+
| Angie Fathalla  | af4292  |
+-----------------+---------+
| Mingkun Tian    | mt4835  |
+-----------------+---------+
| Dipit Vasdev    | dv2224  |
+-----------------+---------+
| Shashank Shekhar | ss16116 |
+-----------------+---------+
*/

#include <mbed.h>
#include "drivers/Dht11.h"


Dht11 sensor(PC_2)  ; 
DigitalOut led(LED4) ; 

 int main() {
    led = 0 ; 
    int counter = 0 ; 
    uint16_t prev = 0 ;
    uint16_t current = 0 ; 
    while(1){
        sensor.read();
        current = sensor.getHumidity() ; 
        printf("Current: %d \n",current);

        if(prev >= current){
            counter ++ ; 
        }else{
            counter = 0  ; 
        }
        printf("Counter : %d  || ",counter) ; 
        if(counter == 20)
        {
            printf("STOPPED") ; 
            led = 1 ; 
        }
        prev = current ; 
        thread_sleep_for(500)  ; 
    }
    
 }