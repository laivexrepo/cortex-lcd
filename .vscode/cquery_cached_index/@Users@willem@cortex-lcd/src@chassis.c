#include "main.h"    // includes API.h and other headers
#include "chassis.h" // redundant, but ensures that the corresponding header file (chassis.h) is included

void chassisSet(int left, int right) {
  motorSet(LM_F_DRIVE, left);
  motorSet(RM_F_DRIVE, -right);
  motorSet(LM_B_DRIVE, left);
  motorSet(RM_B_DRIVE, -right);
}
