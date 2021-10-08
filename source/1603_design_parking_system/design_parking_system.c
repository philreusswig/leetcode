#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DEBUG  0

// car type
#define BIG    1
#define MEDIUM 2
#define SMALL  3

// Bool
#define TRUE   1
#define FALSE  0

typedef struct {
   int big;
   int medium;
   int small;
} ParkingSystem;

/////////////////////////////////////////////////////////////////////////////////////////////////
// @desc create parking system with number of spaces per car type
// @param big - number of big car parking spaces
// @param medium - number of medium car parking spaces
// @param small - number of small car parking spaces
// @return ParkingSystem* - pointer to parking system structure
////////////////////////////////////////////////////////////////////////////////////////////////
ParkingSystem* parkingSystemCreate(int big, int medium, int small) {
   ParkingSystem* obj;

   obj = (ParkingSystem *) malloc(sizeof(ParkingSystem));

   obj->big = big;
   obj->medium = medium;
   obj->small = small;

   return obj;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
// @desc get number of available parking spaces for specified car type
// @param obj - parking spaces struct
// @param carType - car type (big, medium, small)
//          1: big
//          2: medium
//          3: small
// @return numParkingSpaces - number of available parking spaces for specified car type
////////////////////////////////////////////////////////////////////////////////////////////////
int getNumParkingSpaces(ParkingSystem* obj, int carType) {
   int numParkingSpaces;

   switch (carType) {
      case BIG:
         numParkingSpaces = obj->big;
         break;
      case MEDIUM:
         numParkingSpaces = obj->medium;
         break;
      case SMALL:
         numParkingSpaces = obj->small;
         break;
      default:
         numParkingSpaces = 0;
         break;
   }

   return numParkingSpaces;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
// @desc reduce the number of available car spaces by one for given car type
// @param obj - parking spaces struct
// @param carType - car type (big, medium, small)
//          1: big
//          2: medium
//          3: small
// @return none
////////////////////////////////////////////////////////////////////////////////////////////////
void modifyNumParkingSpaces(ParkingSystem* obj, int carType) {
   int* pNumParkingSpaces = NULL;

   switch (carType) {
      case BIG:
         pNumParkingSpaces = &obj->big;
         break;
      case MEDIUM:
         pNumParkingSpaces = &obj->medium;
         break;
      case SMALL:
         pNumParkingSpaces = &obj->small;
         break;
      default:

         break;
   }

   if (pNumParkingSpaces != NULL) {
      *pNumParkingSpaces -= 1;
      return;
   }
   else {
      return;
   }
}

/////////////////////////////////////////////////////////////////////////////////////////////////
// @desc add a car to a parking space
// @param obj - parking spaces struct
// @param carType - car type (big, medium, small)
//          1: big
//          2: medium
//          3: small
// @return bool 
//          true: if successfully added a car to an available parking space
//          false: no available parking spaces
////////////////////////////////////////////////////////////////////////////////////////////////
bool parkingSystemAddCar(ParkingSystem* obj, int carType) {
   bool isParkingSpaceAvailable = FALSE;
   int numParkingSpaces;

   numParkingSpaces = getNumParkingSpaces(obj, carType);

   if (numParkingSpaces > 0) {
      modifyNumParkingSpaces(obj, carType);
      return isParkingSpaceAvailable = TRUE;
   }
   else {
      return isParkingSpaceAvailable = FALSE;
   }
}

/////////////////////////////////////////////////////////////////////////////////////////////////
// @desc free/destroy parking system
// @param obj - parking spaces struct
// @return none
////////////////////////////////////////////////////////////////////////////////////////////////
void parkingSystemFree(ParkingSystem* obj) {
   free(obj);
}

/**
 * Your ParkingSystem struct will be instantiated and called as such:
 * ParkingSystem* obj = parkingSystemCreate(big, medium, small);
 * bool param_1 = parkingSystemAddCar(obj, carType);
 
 * parkingSystemFree(obj);
*/
int main() {
   ParkingSystem* obj = parkingSystemCreate(1, 1, 0);
   bool param_1 = parkingSystemAddCar(obj, SMALL);
   parkingSystemFree(obj);

   return 0;
}