#include <stdio.h>
int main() {    

    int initial_velocity, acceleration, time,  speed, distance;
    
    printf("Enter Initial Velocity , Acceleration and Time (calc speed and distance):\n ");
    scanf("%d %d %d", &initial_velocity, &acceleration, &time);

    // calculating speed
    speed = initial_velocity + (acceleration * time);
    // calculating Distance
    distance = (initial_velocity*time) + (.5* acceleration * (time*time)); 


    printf("Speed: \n");
    printf("%d = %d + (%d * %d)\n ",speed, initial_velocity, acceleration, time);
    printf("Distance:\n" );
    printf(" %d = (%d * %d) + (.05 * %d * (%d)^2) ",distance, initial_velocity,time, acceleration, time);
    return 0;
}






// ternary operator  -> Boolean expression ? if true : if false
//  v = u + at
// s = ut + .5 a t^2
//  