/** Config File Header for Electric Field Sim
 * \author Henry J Schmale
 * \date March 11, 2015
 * \file config.h
 *
 * Contains the complete text of an example ini file for this program
 * and it contains a function to write it out to file.
 */

#ifndef CONFIG_H_INC
#define CONFIG_H_INC

// Contains the complete text of an example configuration file
static const char* EXAMPLE_INI =
    "# Example Electron Field Sim Job File\n"
    "[GLOBAL]\n"
    "Xmin     =-10          ; min x-axis coord simmed\n"
    "Xmax     = 10          ; max x-axis coord\n"
    "Ymin     =-10          ; min y-axis coord\n"
    "Ymax     = 10          ; max y-axis coord\n"
    "NumSrcs  = 2           ; number of charge srcs\n"
    "NumBall  = 1           ; number of movable balls\n"
    "dXYRes   = .1          ; Coord Resolution\n"
    "dTRes    = .01         ; Time Resolution\n"
    "simulate = true        ; should simulte\n"
    "TSim     = 10          ; seconds to simulate\n\n"
    "# Sources are prefixed with `SRC_X` where x is the id\n"
    "# Object ids start at 0\n"
    "[SRC_0]\n"
    "xPos     = 2           ; x-axis posisition\n"
    "yPos     = -2          ; y-axis posisition\n"
    "charge   = 27E-6       ; charge on src in columbs\n\n"
    "[SRC_1]\n"
    "xPos     = 5\n"
    "yPos     = 9\n"
    "charge   = -10E-6\n\n"
    "# Balls are prefixed with `BALL_X` where X is the id\n"
    "[BALL_0]\n"
    "xPos     = -5          ; X-axis posisition\n"
    "yPos     = -5          ; y-axis pos\n"
    "mass     = .1          ; mass in kilograms\n";

/**\brief Parses the arguements passed to prog
 * \param argc arguement count
 * \param argv argument array
 */
int parseArgs(int argc, char **argv);

#endif // CONFIG_H_INC
