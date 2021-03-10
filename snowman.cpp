/*
===============================================================
>Submission 1.1 CPP_CS_Ariel University 2021 Year_2 Semester_2 
>Author <Nathanael Benichou>
>snowman-a  
>Snowman Structur :

 HHHHH
 HHHHH
X(LNR)Y
X(TTT)Y
 (BBB)

ARGS STRUCTUR : HNLRXYTB
================================================================
*/
#include <iostream>
#include "snowman.hpp"
#include <array>
#include <string>
#include <exception>
using namespace std;

namespace ariel
{

    string snowman(int input)
    {

        //Check if input is good 
        if (input < MINIMUM || input > MAXIMUM)
        {
            __throw_invalid_argument("Error! Not a valid input");
        }
        else
        {

            int *arr = new int[SIZE];
            //Checks for each digit if its correct
            for (int i = 0; i < SIZE; i++)
            {
                if (input % BASE > 4 || input % BASE < 1)
                {
                    __throw_invalid_argument("Error! Not a valid input");
                }
                arr[LAST_INDEX - i] = input % BASE;
                input /= BASE;
            }

            //Creat array For each parts of : HNLRXYTB

            //Empty, Straw hat, Mexican Hat,  Fez, Russian Hat
            const array<string, 5> hats = {"", "_===_\n", " ___ \n .....\n", "  _  \n  /_\\ \n", " ___ \n (_*_)\n"};

            //Empty, Normal, Dot, Line, None
            const array<string, 5> noses = {"", ",", ".", "_", " "};

            //Empty, Dot ,Bigger Dot, Biggest Dot, Closed
            const array<string, 5> right_Eye = {"", ".", "o", "O", "-"};

            //Empty, Dot ,Bigger Dot, Biggest Dot, Closed
            const array<string, 5> left_Eye = {"", ".", "o", "O", "-"};
            
            //Empty,  Normal Arm,  Upwards Arm, Downwards Arm, None
            const array<string, 5> high_Left = {"", " ", "\\", " ", " "};

            //Empty,  Normal Arm,  Upwards Arm, Downwards Arm, None
            const array<string, 5> low_Left = {"", "<", " ", "/", " "};
           
            //Empty,  Normal Arm,  Upwards Arm, Downwards Arm, None
            const array<string, 5> low_Right = {"", ">", " ", "\\", " "};

            //Empty,Buttons, vest, Inwards Arms, None
            const array<string, 5> torso = {"", " : ", "] [", "> <", "   "};

            //Empty,  Normal Arm,  Upwards Arm, Downwards Arm, None 
            const array<string, 5> high_Right = {"", " ", "/", " ", " "};

            //Empty, Buttons, feet, Flat, None
            const array<string, 5> base = {"", " : ", "\" \"", "___", "   "};

            //Constuction of the return ans with peek each value in corresponding index of is array.

            string snw = " " + hats[arr[0]] +
                         highs_Left[arr[4]] + "(" + left_Eye[arr[2]] + noses[arr[1]] + right_Eye[arr[3]] + ")" + high_Right[arr[5]] + "\n" +
                         low_Left[arr[4]] + "(" + torso[arr[6]] + ")" + low_Right[arr[5]] + "\n (" +
                         base[arr[7]] + ")";
            return snw;
        }
    }
}

