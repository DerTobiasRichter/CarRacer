#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

int main() {

    /*  while(){ //links rechts anschlagprüfung
          //lese eingabe
          //prüfe richtung
          //prüfe ist noch genug platz
          //ist genug platz, dann rücke, und neue zeile
          //ist nicht genug platz, dann beende
      }*/

    int y_min = 0;
    int y_max = 21;
    int y_left_boundary = 0;
    int y_right_boundary = 20;
    int y_car_position = 9;
    char key = ' ';// getchar();

    //Print start line of the car racer game and boundaries
    for(int y = 0 ;y <= y_max; y++) {
        if (y == y_left_boundary) {
            std::cout << "|";
        } else if (y == y_right_boundary) {
            std::cout << "|";
        } else if (y == y_car_position) {
            std::cout << "#";
        } else {
            std::cout << " ";
        }
    }
   //Tasteneingabe/Steuerung
   while(key!='q') {

       std::cin >> key;
        // Car Movement
       if (key == 'a' || key == 'd') {
           if (key == 'd') {
               //move car right
               y_car_position = y_car_position + 1;
           } else if (key == 'a') {
               //move car left
               y_car_position = y_car_position -1;
           }
       }

       // Move Left Wall
       srand(time(NULL) - 39038945143); // Zufallsfunktion

       int rand_left = rand() % 3 -1; // [-1|0|+1] -->% Modulo Operator 2 d.h. teilen durch 2 --> Integer 0-1; -1 d.h. Integer 0 ?

       if (rand_left == 0) {
           y_left_boundary = y_left_boundary;
       }
       else if (rand_left == 1) {
           if (y_left_boundary + 5 <= y_right_boundary) {
               y_left_boundary = y_left_boundary + 1;
           }
       }
       else if (rand_left == -1) {
           if (y_min <= y_left_boundary - 1) {
               y_left_boundary = y_left_boundary - 1;
           }
       }

       // Move Right Wall
       srand(time(NULL) + 90374843);
       int rand_right = rand() % 3 - 1; // [-1|0|+1] -->% 2 d.h. teilen durch 2 --> Integer 0-1; -1 d.h. Integer 0 ?

       if (rand_right == 0) {
           y_right_boundary = y_right_boundary;
       }
       else if (rand_right == 1) {
           if (y_left_boundary + 5 <= y_right_boundary) {
               y_right_boundary = y_right_boundary - 1;
           }
       } else if (rand_right == -1) {
           if (y_right_boundary + 1 <= y_max) {
               y_right_boundary = y_right_boundary + 1;
           }
       }

       //Draw Game [Walls and Car]
       for (int y = 0; y <= y_max; y++) {

           if (y == y_left_boundary) {
               std::cout << "|";
           } else if (y == y_right_boundary) {
               std::cout << "|";
           } else if (y == y_car_position) {
               std::cout << "#";
           } else {
               std::cout << " ";
           }
       }

       // Check Collision
       if(y_left_boundary >= y_car_position || y_car_position >= y_right_boundary){
           std::cout << "Autsch!" << std::endl;
           break;
       }
   }

   return 0;
}