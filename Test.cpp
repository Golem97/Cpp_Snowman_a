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

//To run Test.cpp using clang++-9  -std=c++2a Test.cpp


//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
//#include "snowman.cpp"

#include "doctest.h"
#include "snowman.hpp"
#include <stdexcept>

using namespace ariel;
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

//I changed the syntax of eras to feet with c++11
string nospaces(string input)
{
    input.erase(remove(input.begin(),input.end(), ' '), input.end());
    input.erase(remove(input.begin(),input.end(), '\t'), input.end());
    input.erase(remove(input.begin(),input.end(), '\n'), input.end());
    input.erase(remove(input.begin(),input.end(), '\r'), input.end());
    return input;
}


//____________________________MY TESTS_________________________//

TEST_CASE("Good Snowman code") 
    {
        CHECK(nospaces(snowman(11111111)) == nospaces("_===_\n(.,.)\n<( : )>\n( : )"));
        CHECK(nospaces(snowman(33333333)) == nospaces("_\n/_\\\n(O_O)\n/(> <)\\\n(___)"));
        CHECK(nospaces(snowman(43214321)) == nospaces("___\n(_*_)\n(o_.)\n(] [)\\\n( : )"));
        CHECK(nospaces(snowman(12341234)) == nospaces("_===_\n(O.-)/\n<(> <)\n(   )"));
        CHECK(nospaces(snowman(41322111)) == nospaces("___\n(_*_)\n\\(O,o) \n( : )>\n( : )"));

    }

TEST_CASE("Bad Snowman code")
    {
        //Wrong Input (Good size Severals wrong digits)
        CHECK_THROWS(snowman(00000000));
        CHECK_THROWS(snowman(55555555));
        CHECK_THROWS(snowman(66666666));
        CHECK_THROWS(snowman(77777777));
        CHECK_THROWS(snowman(88888888));
        CHECK_THROWS(snowman(99999999));
      

        ///Shortest Input (Frome 1 to 7)
         CHECK_THROWS(snowman(1));
         CHECK_THROWS(snowman(11));
         CHECK_THROWS(snowman(111)); 
         CHECK_THROWS(snowman(1111)); 
         CHECK_THROWS(snowman(11111)); 
         CHECK_THROWS(snowman(111111)); 
         CHECK_THROWS(snowman(1111111));

        
        //Negatives input
        CHECK_THROWS(snowman(-11111111));
        CHECK_THROWS(snowman(-22222222));
        CHECK_THROWS(snowman(-33333333));
        CHECK_THROWS(snowman(-44444444));
        CHECK_THROWS(snowman(-14118754));
        
        //Check wrong input for each digit
        CHECK_THROWS(snowman(01111111));
        CHECK_THROWS(snowman(15111111));
        CHECK_THROWS(snowman(11611111));
        CHECK_THROWS(snowman(11171111));
        CHECK_THROWS(snowman(11118111));
        CHECK_THROWS(snowman(11111911));
        CHECK_THROWS(snowman(11111101));
        CHECK_THROWS(snowman(11111115));
    }

//TEST HATS
TEST_CASE("Hats") 
{   //Straw Hat
    CHECK(nospaces(snowman(11111111)) == nospaces("_===_\n(.,.)\n<( : )>\n( : )"));
    //Mexican Hat
    CHECK(nospaces(snowman(21111111)) == nospaces("___\n.....\n(.,.)\n<( : )>\n( : )"));
    //Fez
    CHECK(nospaces(snowman(31111111)) == nospaces("_\n/_\\\n(.,.)\n<( : )>\n( : )"));
    //Russian Hat
    CHECK(nospaces(snowman(41111111)) == nospaces("___\n(_*_)\n(.,.)\n<( : )>\n( : )"));
}

//TEST NOSES
TEST_CASE("Noses") 
{
    //Normal
    CHECK(nospaces(snowman(11111111)) == nospaces("_===_\n(.,.)\n<( : )>\n( : )"));
    //Dot
    CHECK(nospaces(snowman(12111111)) == nospaces("_===_\n(...)\n<( : )>\n( : )"));
    //Line
    CHECK(nospaces(snowman(13111111)) == nospaces("_===_\n(._.)\n<( : )>\n( : )"));
    //Nones
    CHECK(nospaces(snowman(14111111)) == nospaces("_===_\n(. .)\n<( : )>\n( : )"));
}

//TEST LEFT EYE
TEST_CASE("Left Eye") 
{
   //Normal
    CHECK(nospaces(snowman(11111411)) == nospaces("_===_\n(.,.)\n<( : )\n( : )"));
    //Dot
    CHECK(nospaces(snowman(11112411)) == nospaces("_===_\n\\(.,.)\n( : )\n( : )"));
    //Line
    CHECK(nospaces(snowman(11113411)) == nospaces("_===_\n(.,.)\n/( : )\n( : )"));
     //Noness
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
}

//TEST RIGHT EYE
TEST_CASE("Right Eye")
{
    //Dot
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    //Bigger Dot
    CHECK(nospaces(snowman(11124411)) == nospaces("_===_\n(.,o)\n( : )\n( : )"));
    //Biggest Dot 
    CHECK(nospaces(snowman(11134411)) == nospaces("_===_\n(.,O)\n( : )\n( : )"));
     //Closed
    CHECK(nospaces(snowman(11144411)) == nospaces("_===_\n(.,-)\n( : )\n( : )"));

}

//TEST LEFT ARM
TEST_CASE("Left Arm")
{
    //Normal Arm
    CHECK(nospaces(snowman(11111411)) == nospaces("_===_\n(.,.)\n<( : )\n( : )"));
    //Upwards Arm
    CHECK(nospaces(snowman(11112411)) == nospaces("_===_\n\\(.,.)\n( : )\n( : )"));
    //Downwards Arm
    CHECK(nospaces(snowman(11113411)) == nospaces("_===_\n(.,.)\n/( : )\n( : )"));
    //None
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));

}

//RIGHT ARM TEST
TEST_CASE("Right Arm") 
{
    //Normal Arm
    CHECK(nospaces(snowman(11114111)) == nospaces("_===_\n(.,.)\n( : )>\n( : )"));
    //Upwards Arm
    CHECK(nospaces(snowman(11114211)) == nospaces("_===_\n(.,.)/\n( : )\n( : )"));
    //Downwards Arm
    CHECK(nospaces(snowman(11114311)) == nospaces("_===_\n(.,.)\n( : )\\\n( : )"));
    //None
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
}

//TORSO TEST
TEST_CASE("Torso") 
{
    //Buttons
    CHECK(nospaces(snowman(11144411)) == nospaces("_===_\n(.,-)\n( : )\n( : )"));
    //Vest
    CHECK(nospaces(snowman(11144421)) == nospaces("_===_\n(.,-)\n(] [)\n( : )"));
    //Inward Arms
    CHECK(nospaces(snowman(11144431)) == nospaces("_===_\n(.,-)\n(> <)\n( : )"));
    //None 
    CHECK(nospaces(snowman(11144441)) == nospaces("_===_\n(.,-)\n(   )\n( : )"));
}

//BASE TEST
TEST_CASE("Base") 
{
    //Buttons 
    CHECK(nospaces(snowman(11144411)) == nospaces("_===_\n(.,-)\n( : )\n( : )"));
    //Feet
    CHECK(nospaces(snowman(11144412)) == nospaces("_===_\n(.,-)\n( : )\n(\" \")"));
    //Flat
    CHECK(nospaces(snowman(11144413)) == nospaces("_===_\n(.,-)\n( : )\n(___)"));
    //None 
    CHECK(nospaces(snowman(11144414)) == nospaces("_===_\n(.,-)\n( : )\n(   )"));
}