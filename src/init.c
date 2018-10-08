/** @file init.c
 * @brief File for initialization code
 *
 * This file should contain the user initialize() function and any functions related to it.
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"
#include "lcd.h"

/*
 * Runs pre-initialization code. This function will be started in kernel mode one time while the
 * VEX Cortex is starting up. As the scheduler is still paused, most API functions will fail.
 *
 * The purpose of this function is solely to set the default pin modes (pinMode()) and port
 * states (digitalWrite()) of limit switches, push buttons, and solenoids. It can also safely
 * configure a UART port (usartOpen()) but cannot set up an LCD (lcdInit()).
 */
void initializeIO() {
}

/*
 * Runs user initialization code. This function will be started in its own task with the default
 * priority and stack size once when the robot is starting up. It is possible that the VEXnet
 * communication link may not be fully established at this time, so reading from the VEX
 * Joystick may fail.
 *
 * This function should initialize most sensors (gyro, encoders, ultrasonics), LCDs, global
 * variables, and IMEs.
 *
 * This function must exit relatively promptly, or the operatorControl() and autonomous() tasks
 * will not start. An autonomous mode selection menu like the pre_auton() in other environments
 * can be implemented in this task if desired.
 */

// These two sample scripts are run based on button selection
void exampleScript1() {
  lcdClear(uart1);
  lcdPrint(uart1, 1, "Running Script 1");
  lcdPrint(uart1, 2, "Batt: %1.3f V", (double)powerLevelMain() / 1000);
  delay(200);
  return;
}

void exampleScript2() {
   // Run select script
   lcdClear(uart1);
   lcdPrint(uart1, 1, "Running Script 2");
   lcdPrint(uart1, 2, "Batt: %1.3f V", (double)powerLevelMain() / 1000);
   delay(200);
   return;
}

void exampleScript3() {
   // Run select script
   lcdClear(uart1);
   lcdPrint(uart1, 1, "Running Script 3");
   lcdPrint(uart1, 2, "Batt: %1.3f V", (double)powerLevelMain() / 1000);
   delay(200);
   return;
}

// THese two arrays, hold the script names/description and the function name to be executed
const char* titles[] = {"Script 1", "Script 2", "Script 3"};
void (*scripts[])() = {exampleScript1, exampleScript2, exampleScript3};


void initialize() {
  // When using the LCD select library to set the right Autonomous Program
  lcdScriptInit(uart1); // Example LCD is in UART1
  lcdScriptSelect();

}
