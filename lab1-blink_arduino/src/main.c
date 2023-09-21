/***********************************************************************
 * 
 * Blink a LED in Arduino-style and use function from the delay library.
 * ATmega328P (Arduino Uno), 16 MHz, PlatformIO
 *
 * Copyright (c) 2022 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/


/* Defines -----------------------------------------------------------*/
#define LED_GREEN PB5   // PB5 is AVR pin where green on-board LED 
#define LED_RED PB0
                        // is connected
#define SHORT_DELAY 500 // Delay in milliseconds
#ifndef F_CPU
# define F_CPU 16000000 // CPU frequency in Hz required for delay funcs
#endif

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>     // AVR device-specific IO definitions  KNIHOVNY
#include <util/delay.h> // Functions for busy-wait delay loops


// -----
// This part is needed to use Arduino functions but also physical pin
// names. We are using Arduino-style just to simplify the first lab.
#include "Arduino.h"
#define PB5 13          // In Arduino world, PB5 is called "13" NOZKA MIKROKONTROLERU 13
#define PB0 8
// -----


/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Toggle one LED and use delay library.
 * Returns:  none
 **********************************************************************/
int main(void) //TELO FUNKCE JE VE SLOZENYCH ZAVORKACH -- PRVNI FUNKCE KTERA SE SPUSTI A JE TAM VZDY SE JMENUJE *MAIN*
{
    uint8_t led_value = 0;  // Local variable to keep LED status -- LED VALUE JE PROMENNA

    // Set pin where on-board LED is connected as output
    pinMode(LED_GREEN, OUTPUT); // NASTAVENI PINU = PINmODE (NAZEV PINU CO JSEM SI VYMYSLEL, VSTUP/VYSTUP)
    pinMode(LED_RED, OUTPUT);

    // Infinite loop
    while (1)//OPAKUJ DOKUD JE SPLNEN VYROK V ZAVORCE(1)
    {
        // Pause several milliseconds
        _delay_ms(SHORT_DELAY); //250 MS SE NIC NEDEJE

        // Change LED value
        if (led_value == 0) {
            led_value = 1;
            // Set pin to HIGH
            digitalWrite(LED_GREEN, HIGH);
            digitalWrite(LED_RED, HIGH); // JE- LI VYROK PRAVDIVY STANE TO V ZAVORKACH, POKUD NE, STANE SE ELSE A STRIDA SE TO DOKOLA 
        }
        else {
            led_value = 0;
            // Clear pin to LOW
            digitalWrite(LED_GREEN, LOW);
             digitalWrite(LED_RED, LOW);
        }
    }

    // Will never reach this
    return 0;
}