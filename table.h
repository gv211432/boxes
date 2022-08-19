#ifndef gauravsTable
#define gauravsTable

namespace boxes
{
#include <iostream>
#include <vector>
#include <functional>
#include "./convert.h"
    convert_vec::Convert CONVERT;
    using namespace std;

    size_t VECTOR_OUTER_LEN = 0; // to hold the outer length of the vector
    size_t VECTOR_INNER_LEN = 0; // to hold the inner length of the vector

    size_t CARRY_V_OUT = 0; // to add to the index printed by the print_char_functions
    size_t CARRY_V_IN = 0;  // to add to the index printed by the print_char_functions

    // char PIPE_TYPE[4] = "|"; // this is the default pipe character

    // ╻ ╻╻┏━┓╻╺━┓┏━┓┏┓╻╺┳╸┏━┓╻     ╻ ╻┏━╸┏━┓╺┳╸╻┏━╸┏━┓╻
    // ┣━┫┃┣┳┛┃┏━┛┃ ┃┃┗┫ ┃ ┣━┫┃     ┃┏┛┣╸ ┣┳┛ ┃ ┃┃  ┣━┫┃
    // ╹ ╹╹╹┗╸╹┗━╸┗━┛╹ ╹ ╹ ╹ ╹┗━╸   ┗┛ ┗━╸╹┗╸ ╹ ╹┗━╸╹ ╹┗━╸
    // this is to print the second string on the top of the box
    void print_char_horizontal(string &text1, string &text2)
    {
        // first printing out the characters
        std::cout << "\033[31;1m"; // color is red and bold
        for (size_t i = 0; i < text2.size(); i++)
        {
            if (i == 0) // printing initial space based on presence of text1 or not
                (text1.empty()) ? std::cout << "   " << text2[i] << "   "
                                : std::cout << "        " << text2[i] << "   ";
            else // this is normal gap between characters
                std::cout << "  " << text2[i] << "   ";
        }
        std::cout << std::endl; // printing nextline char for printing indices

        // then printing out the indices
        std::cout << "\033[34m";               // setting the color voilet and bold format
        size_t index_print_len = text2.size(); // load the length of the text2
        if (index_print_len > 0)               // if text2 is not empty, only then srart printing index and strings on top
            for (size_t i = 0; i < VECTOR_INNER_LEN + 1; i++)
            {
                if (i == 0)
                    index_print_len++,                                                  // incresing the length by one so that it prints one more index number for null character
                        (text1.empty()) ? std::cout << "   " << i + CARRY_V_IN << "   " // inital space based on text1 present or not
                                        : std::cout << "        " << i + CARRY_V_IN << "   ";
                else if (i + CARRY_V_IN <= 9) // if index is under one digit
                    std::cout << "  " << i + CARRY_V_IN << "   ";
                else // if index is 2 digit, adjust spaces
                    std::cout << " " << i + CARRY_V_IN << "   ";
            }
        std::cout << "\033[0m" << std::endl; // decolorize the text
    }

    // this is to print the first string vertically, left of the box
    void print_char_vertical(string &text1, bool &text1_exhausted, size_t &i)
    {
        i--;                       // decrese the i by 1
        std::cout << "\033[31;1m"; // text color red and bold
        if (!text1.empty())        // if string is not empty
        {
            if (text1_exhausted) // if text exhausted print empty spaces
                i + CARRY_V_OUT <= 9 ? std::cout << "   "
                                                 << "\033[34;1m" << i + CARRY_V_OUT << "\033[0m"
                                                 << " "
                                     : std::cout << "  "
                                                 << "\033[34;1m" << i + CARRY_V_OUT << "\033[0m"
                                                 << " ";
            else if (text1[i])                                                                   // if character available print them
                i + CARRY_V_OUT <= 9 ? std::cout << text1[i] << "  "                             // if index 1 digit
                                                 << "\033[34;1m" << i + CARRY_V_OUT << "\033[0m" // color the index as voilet
                                                 << " "
                                     : std::cout << text1[i] << " "                              // if index is 2 digit adjust spaces
                                                 << "\033[34;1m" << i + CARRY_V_OUT << "\033[0m" // color the index as voilet
                                                 << " ";
            else // whenever character becomes '\0' make text1_exhausted tru, to prevent segmentation error
            {
                text1_exhausted = true;                                                          // if strig is exhausted, make this true
                i + CARRY_V_OUT <= 9 ? std::cout << "   "                                        // if index 1 digit
                                                 << "\033[34;1m" << i + CARRY_V_OUT << "\033[0m" // color the index as voilet
                                                 << " "
                                     : std::cout << "  "                                         // if index is 2 digit adjust spaces
                                                 << "\033[34;1m" << i + CARRY_V_OUT << "\033[0m" // color the index as voilet
                                                 << " ";
            }
        }
        std::cout << "\033[0m"; // noramlize the text output
        i++;                    // increse i by 1 before exiting, default value
    }

    // ┏┓ ┏━┓┏━┓╻
    // ┣┻┓┃ ┃┃ ┃┃
    // ┗━┛┗━┛┗━┛┗━╸

    void print_type_2_bool(vector<bool> &v)
    {
        for (size_t j = 0; j < v.size(); j++)
        {
            size_t len = 1;                // this line id copied form above, we are just making the length 1 to print "T" or  "F"
            std::cout << "┃";              // befor starting to print the content, print the starting left side pipe
            size_t mid = (5 - len) / 2;    // let the middel position be mid, here we will print the value "T" or "F"
            for (size_t k = 0; k < 6; k++) // traversing the 6 spaces in a box
            {
                if (k == mid) // for printing 1 letter of T or F, we choose the middle
                {             // position of the availble space
                    if (v[j])
                        cout << "\033[32;1m" // printing it green
                             << "T"
                             << "\033[0m";
                    else
                        cout << "\033[31m" // printing it red
                             << "F"
                             << "\033[0m";

                    k += len;
                    continue;
                }
                cout << " "; // if its not middle position, print space for padding
            }
            if (j >= (v.size() - 1)) // if it was the last iteration, also print the next line
                cout << "┃\n";       // character
        }
    }

    void print_type_1_bool(vector<bool> &v) // all
    {
        for (size_t j = 0; j < v.size(); j++)
        {
            size_t len = 1;

            std::cout << "|";
            size_t mid = (5 - len) / 2;
            for (size_t k = 0; k < 6; k++)
            {
                if (k == mid)
                {
                    if (v[j])
                        cout << "\033[32;1m"
                             << "T"
                             << "\033[0m";
                    else
                        cout << "\033[31m"
                             << "F"
                             << "\033[0m";

                    k += len;
                    continue;
                }
                cout << " ";
            }
            if (j >= (v.size() - 1))
                cout << "|"
                     << "\n";
        }
    }

    // ╻┏┓╻╺┳╸
    // ┃┃┗┫ ┃
    // ╹╹ ╹ ╹

    void print_type_1_int(vector<int> &v, const vector<int> &trace = {})
    {
        // for (size_t j = 0; j < v.size(); j++)
        // {
        //     size_t len = 0;
        //     size_t num = v[j];

        //     do
        //         num /= 10, len++;
        //     while (num > 0);

        //     std::cout << "|";
        //     size_t mid = (5 - len) / 2;
        //     for (size_t k = 0; k < 6; k++)
        //     {
        //         if (k == mid)
        //         {
        //             cout << "\033[32m" << v[j] << "\033[0m";
        //             k += len;
        //             continue;
        //         }
        //         cout << " ";
        //     }
        //     if (j == v.size() - 1)
        //         cout << "|\n";
        // }

        // bool trace_exhausted = false; // use this for validation when trace vector is exhausted
        for (size_t j = 0; j < v.size(); j++)
        {
            size_t len = 0;
            v[j] < 0 ? len = 1 : len = 0; // to hold the length of the number
            size_t num = abs(v[j]);       // to hold the copy of the number

            do // calculating the length of the number
                num /= 10, len++;
            while (num > 0);

            auto load = to_string(v[j]);
            if (len > 5)
                load = " over", len = 5;

            std::cout << "|"; // printing first pipe of the row
            size_t mid = (5 - len) / 2;
            for (size_t k = 0; k < 6; k++)
            {
                if (k == mid)
                {
                    if (!trace.empty())
                        trace[j] ? cout << "\033[31;1m" << load << "\033[0m"
                                 : cout << "\033[32;1m" << load << "\033[0m";
                    else
                        cout << "\033[32;1m" << load << "\033[0m";
                    k += len;
                    continue;
                }
                cout << " ";
            }
            // std::cout << "j : " << j << " v.size : " << v.size() << std::endl;
            if (j == v.size() - 1) // for last column print closing pipe with new line
                std::cout << "|" << std::endl;
        }
    }

    void print_type_2_int(vector<int> &v, const vector<int> &trace = {})
    {
        // bool trace_exhausted = false; // use this for validation when trace vector is exhausted
        for (size_t j = 0; j < v.size(); j++)
        {
            size_t len = 0;
            v[j] < 0 ? len = 1 : len = 0; // to hold the length of the number
            size_t num = abs(v[j]);       // to hold the copy of the number

            do // calculating the length of the number
                num /= 10, len++;
            while (num > 0);

            auto load = to_string(v[j]);
            if (len > 5)
                load = " over", len = 5;

            std::cout << "┃"; // printing first pipe of the row
            size_t mid = (5 - len) / 2;
            for (size_t k = 0; k < 6; k++)
            {
                if (k == mid)
                {
                    if (!trace.empty())
                        trace[j] ? cout << "\033[31;1m" << load << "\033[0m"
                                 : cout << "\033[32;1m" << load << "\033[0m";
                    else
                        cout << "\033[32;1m" << load << "\033[0m";
                    k += len;
                    continue;
                }
                cout << " ";
            }
            // std::cout << "j : " << j << " v.size : " << v.size() << std::endl;
            if (j == v.size() - 1) // for last column print closing pipe with new line
                std::cout << "┃" << std::endl;
        }
    }

    // ┏━╸╻ ╻┏━┓┏━┓
    // ┃  ┣━┫┣━┫┣┳┛
    // ┗━╸╹ ╹╹ ╹╹┗╸

    void print_type_1_char(vector<char> &v, const vector<int> &trace = {})
    {
        // bool trace_exhausted = false; // use this for validation when trace vector is exhausted
        for (size_t j = 0; j < v.size(); j++)
        {
            size_t len = 1; // to hold the length of the number
            // size_t num = v[j]; // to hold the copy of the number

            // do // calculating the length of the number
            //     num /= 10, len++;
            // while (num > 0);

            std::cout << "|"; // printing first pipe of the row
            size_t mid = (5 - len) / 2;
            for (size_t k = 0; k < 6; k++)
            {
                if (k == mid)
                {
                    if (!trace.empty())
                        trace[j] ? cout << "\033[31;1m" << v[j] << "\033[0m"
                                 : cout << "\033[32;1m" << v[j] << "\033[0m";
                    else
                        cout << "\033[32;1m" << v[j] << "\033[0m";
                    k += len;
                    continue;
                }
                cout << " ";
            }
            // std::cout << "j : " << j << " v.size : " << v.size() << std::endl;
            if (j == v.size() - 1) // for last column print closing pipe with new line
                std::cout << "|" << std::endl;
        }
    }

    void print_type_2_char(vector<char> &v, const vector<int> &trace = {})
    {
        // bool trace_exhausted = false; // use this for validation when trace vector is exhausted
        for (size_t j = 0; j < v.size(); j++)
        {
            size_t len = 1; // to hold the length of the number
            // size_t num = v[j]; // to hold the copy of the number

            // do // calculating the length of the number
            //     num /= 10, len++;
            // while (num > 0);

            std::cout << "┃"; // printing first pipe of the row
            size_t mid = (5 - len) / 2;
            for (size_t k = 0; k < 6; k++)
            {
                if (k == mid)
                {
                    if (!trace.empty())
                        trace[j] ? cout << "\033[31;1m" << v[j] << "\033[0m"
                                 : cout << "\033[32;1m" << v[j] << "\033[0m";
                    else
                        cout << "\033[32;1m" << v[j] << "\033[0m";
                    k += len;
                    continue;
                }
                cout << " ";
            }
            // std::cout << "j : " << j << " v.size : " << v.size() << std::endl;
            if (j == v.size() - 1) // for last column print closing pipe with new line
                std::cout << "┃" << std::endl;
        }
    }

    class Boxes
    {
        // ╻┏┓╻╺┳╸
        // ┃┃┗┫ ┃
        // ╹╹ ╹ ╹
        // ================================================================
        void table_type_2_int(vector<vector<int>> &v, function<void(vector<int> &, const vector<int> &)> print_func,
                              string text1 = "", string text2 = "", const vector<vector<int>> &trace = {})
        {
            size_t a = v.size() + 1, b = v[0].size() - 1; // a and b will keep the length of the dimensions of vov
            VECTOR_OUTER_LEN = a, VECTOR_INNER_LEN = b;
            bool text1_exhausted = false; // it will track if text1 is exhausted printing

            // first printing the text2 on the top of the box
            print_char_horizontal(text1, text2);

            if (b == 0) // when the breath of the vov is 1
            {
                for (size_t i = 0; i <= a; i++)
                {
                    if (i > 0 and i < a)
                    {
                        print_char_vertical(text1, text1_exhausted, i); // this prints out the first string at left
                        if (!trace.empty())                             // if trace vector is not empty
                            print_func(v[i - 1], trace[i - 1]);         // this prints the vertical pipes and contents in the boxes
                        else
                            print_func(v[i - 1], {}); // this prints the vertical pipes and contents in the boxes
                    }

                    if (i == a - 1)
                        continue;

                    for (size_t j = 0; j <= b; j++)
                    {
                        if (i == 0 && j == 0)
                            (text1.empty()) ? std::cout << "┏━━━━━┓" : std::cout << "     ┏━━━━━┓";
                        else if (i == 0 and j == b)
                            (text1.empty()) ? std::cout << "┏━━━━━┓" : std::cout << "     ┏━━━━━┓";
                        else if (i == a and j == 0)
                            (text1.empty()) ? std::cout << "┗━━━━━┛" : std::cout << "     ┗━━━━━┛";
                        else if (i == a and j == b)
                            (text1.empty()) ? std::cout << "┗━━━━━┛" : std::cout << "     ┗━━━━━┛";
                        else if (j == 0)
                            (text1.empty()) ? std::cout << "┣━━━━━┫" : std::cout << "     ┣━━━━━┫";
                        else if (j == b)
                            (text1.empty()) ? std::cout << "┣━━━━━┫" : std::cout << "     ┣━━━━━┫";
                        else
                            (text1.empty()) ? std::cout << "───────" : std::cout << "     ───────";
                    }
                    std::cout << " " << std::endl;
                }
                std::cout << " " << std::endl;
            }
            else if (a == 1)
            {
                // for this block do nothing
            }
            else
            {
                for (size_t i = 0; i <= a; i++)
                {
                    if (i > 0 and i < a)
                    {
                        print_char_vertical(text1, text1_exhausted, i); // this prints out the first string at left
                        if (!trace.empty())                             // if trace vectro is not empty
                            print_func(v[i - 1], trace[i - 1]);         // this prints the vertical pipes and contents in the boxes
                        else
                            print_func(v[i - 1], {}); // this prints the vertical pipes and contents in the boxes
                    }

                    if (i == a - 1)
                        continue;

                    for (size_t j = 0; j <= b; j++)
                    {
                        if (j == 0)
                        {
                            if (i == 0)
                                (text1.empty()) ? std::cout << "┏━━━━━┳" : std::cout << "     ┏━━━━━┳";
                            else if (i == a)
                                (text1.empty()) ? std::cout << "┗━━━━━" : std::cout << "     ┗━━━━━";
                            else
                                (text1.empty()) ? std::cout << "┣━━━━━╋" : std::cout << "     ┣━━━━━╋";
                        }
                        else if (i == 0 and j == b)
                            std::cout << "━━━━━┓";
                        else if (i == a and j == b)
                            std::cout << "┻━━━━━┛";
                        else if (j == b)
                            std::cout << "━━━━━┫";
                        else if (i == 0)
                            std::cout << "━━━━━┳";
                        else if (i == a)
                            std::cout << "┻━━━━━";
                        else
                            std::cout << "━━━━━╋";
                    }
                    std::cout << " " << std::endl;
                }
                std::cout << " " << std::endl;
            }
        }

        // =======================================================================
        void table_type_1_int(vector<vector<int>> &v, function<void(vector<int> &, const vector<int> &)> print_func,
                              string text1 = "", string text2 = "", const vector<vector<int>> &trace = {})
        {
            size_t a = v.size() + 1, b = v[0].size() - 1; // a and b will keep the length of the dimensions of vov
            VECTOR_OUTER_LEN = a, VECTOR_INNER_LEN = b;
            bool text1_exhausted = false; // it will trake if text1 is exhausted printing

            // first printing the text2 on the top of the box
            print_char_horizontal(text1, text2);

            // if only length is 1 and breadth is 1 or more than 1
            if (b == 0)
            {
                for (size_t i = 0; i <= a; i++)
                {
                    if (i > 0 and i < a)
                    {
                        print_char_vertical(text1, text1_exhausted, i); // this prints out the first string at left
                        if (!trace.empty())                             // if trace vectro is not empty
                            print_func(v[i - 1], trace[i - 1]);         // this prints the vertical pipes and contents in the boxes
                        else
                            print_func(v[i - 1], {}); // this prints the vertical pipes and contents in the boxes
                    }

                    if (i == a - 1)
                        continue;

                    for (size_t j = 0; j <= b; j++)
                    {
                        if (i == 0 && j == 0)
                            (text1.empty()) ? std::cout << "┌─────┐" : std::cout << "     ┌─────┐";
                        else if (i == 0 and j == b)
                            (text1.empty()) ? std::cout << "┌─────┐" : std::cout << "     ┌─────┐";
                        else if (i == a and j == 0)
                            (text1.empty()) ? std::cout << "└─────┘" : std::cout << "     └─────┘";
                        else if (i == a and j == b)
                            (text1.empty()) ? std::cout << "└─────┘" : std::cout << "     └─────┘";
                        else if (j == 0)
                            (text1.empty()) ? std::cout << "+─────+" : std::cout << "     +─────+";
                        else if (j == b)
                            (text1.empty()) ? std::cout << "+─────+" : std::cout << "     +─────+";
                        else
                            (text1.empty()) ? std::cout << "───────" : std::cout << "     ───────";
                    }
                    std::cout << " " << std::endl;
                }
                std::cout << " " << std::endl;
            }
            else if (a == 1)
            {
                // for this block do nothing so that it skip one horizontal line
            }
            else
            {
                for (size_t i = 0; i <= a; i++)
                {
                    if (i > 0 and i < a)
                    {
                        print_char_vertical(text1, text1_exhausted, i); // this prints out the first string at left
                        if (!trace.empty())                             // if trace vectro is not empty
                            print_func(v[i - 1], trace[i - 1]);         // this prints the vertical pipes and contents in the boxes
                        else
                            print_func(v[i - 1], {}); // this prints the vertical pipes and contents in the boxes
                    }

                    if (i == a - 1)
                        continue;

                    for (size_t j = 0; j <= b; j++)
                    {
                        if (j == 0)
                        {
                            if (i == 0)
                                (text1.empty()) ? std::cout << "┌─────" : std::cout << "     ┌─────";
                            else if (i == a)
                                (text1.empty()) ? std::cout << "└─────┘" : std::cout << "     └─────┘";
                            else
                                (text1.empty()) ? std::cout << "+─────" : std::cout << "     +─────";
                        }

                        else if (i == 0 and j == b)
                            std::cout << "┌─────┐";
                        else if (i == a and j == b)
                            std::cout << "─────┘";
                        else if (j == b)
                            std::cout << "┌─────+";
                        else if (i == 0)
                            std::cout << "┌─────";
                        else if (i == a)
                            std::cout << "─────┘";
                        else
                            std::cout << "┌─────";
                    }
                    std::cout << " " << std::endl;
                }
                std::cout << " " << std::endl;
            }
        }

        // ┏┓ ┏━┓┏━┓╻
        // ┣┻┓┃ ┃┃ ┃┃
        // ┗━┛┗━┛┗━┛┗━╸
        // ================================================================

        void table_type_2_bool(vector<vector<bool>> &v, function<void(vector<bool> &)> print_func,
                               string text1 = "", string text2 = "")
        {
            size_t a = v.size() + 1, b = v[0].size() - 1; // a and b will keep the length of the dimensions of vov
            VECTOR_OUTER_LEN = a, VECTOR_INNER_LEN = b;
            bool text1_exhausted = false; // it will trake if text1 is exhausted printing
            // printing the second string on the top of the box
            print_char_horizontal(text1, text2);

            if (b == 0)
            {
                // for (size_t i = 0; i <= a; i++)
                // {
                //     print_char_vertical(text1, text1_exhausted, i);
                //     print_func(v[i - 1]);
                // }
                // std::cout << " " << std::endl;

                for (size_t i = 0; i <= a; i++)
                {
                    if (i > 0 and i < a)
                    {
                        print_char_vertical(text1, text1_exhausted, i); // this prints out the first string at left
                        print_func(v[i - 1]);                           // this prints the vertical pipes and contents in the boxes
                    }

                    if (i == a - 1)
                        continue;

                    for (size_t j = 0; j <= b; j++)
                    {
                        if (i == 0 && j == 0)
                            (text1.empty()) ? std::cout << "┏━━━━━┓" : std::cout << "     ┏━━━━━┓";
                        else if (i == 0 and j == b)
                            (text1.empty()) ? std::cout << "┏━━━━━┓" : std::cout << "     ┏━━━━━┓";
                        else if (i == a and j == 0)
                            (text1.empty()) ? std::cout << "┗━━━━━┛" : std::cout << "     ┗━━━━━┛";
                        else if (i == a and j == b)
                            (text1.empty()) ? std::cout << "┗━━━━━┛" : std::cout << "     ┗━━━━━┛";
                        else if (j == 0)
                            (text1.empty()) ? std::cout << "┣━━━━━┫" : std::cout << "     ┣━━━━━┫";
                        else if (j == b)
                            (text1.empty()) ? std::cout << "┣━━━━━┫" : std::cout << "     ┣━━━━━┫";
                        else
                            (text1.empty()) ? std::cout << "───────" : std::cout << "     ───────";
                    }
                    std::cout << " " << std::endl;
                }
                std::cout << " " << std::endl;
            }
            else if (a == 1)
            {
            }
            else
            {
                for (size_t i = 0; i <= a; i++)
                {
                    if (i > 0 and i < a)
                    {
                        print_char_vertical(text1, text1_exhausted, i);
                        print_func(v[i - 1]);
                    }
                    if (i == a - 1)
                        continue;

                    for (size_t j = 0; j <= b; j++)
                    {
                        if (j == 0)
                        {
                            if (i == 0)
                                (text1.empty()) ? std::cout << "┏━━━━━┳" : std::cout << "     ┏━━━━━┳";
                            else if (i == a)
                                (text1.empty()) ? std::cout << "┗━━━━━" : std::cout << "     ┗━━━━━";
                            else
                                (text1.empty()) ? std::cout << "┣━━━━━╋" : std::cout << "     ┣━━━━━╋";
                        }
                        else if (i == 0 and j == b)
                            std::cout << "━━━━━┓";
                        else if (i == a and j == b)
                            std::cout << "┻━━━━━┛";
                        else if (j == b)
                            std::cout << "━━━━━┫";
                        else if (i == 0)
                            std::cout << "━━━━━┳";
                        else if (i == a)
                            std::cout << "┻━━━━━";
                        else
                            std::cout << "━━━━━╋";
                    }
                    std::cout << " " << std::endl;
                }
                std::cout << " " << std::endl;
            }
        }

        void table_type_1_bool(vector<vector<bool>> &v, function<void(vector<bool> &)> print_func,
                               string text1 = "", string text2 = "")
        {
            size_t a = v.size() + 1, b = v[0].size() - 1; // a and b will keep the length of the dimensions of vov
            VECTOR_OUTER_LEN = a, VECTOR_INNER_LEN = b;
            bool text1_exhausted = false; // it will trake if text1 is exhausted printing
            // printing the second string on the top of the box
            print_char_horizontal(text1, text2);

            if (b == 0)
            {
                for (size_t i = 0; i <= a; i++)
                {
                    if (i > 0 and i < a)
                    {
                        print_char_vertical(text1, text1_exhausted, i); // this prints out the first string at left
                        print_func(v[i - 1]);                           // this prints the vertical pipes and contents in the boxes
                    }

                    if (i == a - 1)
                        continue;

                    for (size_t j = 0; j <= b; j++)
                    {
                        if (i == 0 && j == 0)
                            (text1.empty()) ? std::cout << "┌─────┐" : std::cout << "     ┌─────┐";
                        else if (i == 0 and j == b)
                            (text1.empty()) ? std::cout << "┌─────┐" : std::cout << "     ┌─────┐";
                        else if (i == a and j == 0)
                            (text1.empty()) ? std::cout << "└─────┘" : std::cout << "     └─────┘";
                        else if (i == a and j == b)
                            (text1.empty()) ? std::cout << "└─────┘" : std::cout << "     └─────┘";
                        else if (j == 0)
                            (text1.empty()) ? std::cout << "+─────+" : std::cout << "     +─────+";
                        else if (j == b)
                            (text1.empty()) ? std::cout << "+─────+" : std::cout << "     +─────+";
                        else
                            (text1.empty()) ? std::cout << "───────" : std::cout << "     ───────";
                    }
                    std::cout << " " << std::endl;
                }
                std::cout << " " << std::endl;
            }
            else if (a == 1)
            {
            }
            else
            {
                for (size_t i = 0; i <= a; i++)
                {
                    if (i > 0 and i < a)
                    {
                        print_char_vertical(text1, text1_exhausted, i);
                        print_func(v[i - 1]);
                    }
                    if (i == a - 1)
                        continue;

                    for (size_t j = 0; j <= b; j++)
                    {
                        if (j == 0)
                        {
                            if (i == 0)
                                (text1.empty()) ? std::cout << "┌─────" : std::cout << "     ┌─────";
                            else if (i == a)
                                (text1.empty()) ? std::cout << "└─────┘" : std::cout << "     └─────┘";
                            else
                                (text1.empty()) ? std::cout << "+─────" : std::cout << "     +─────";
                        }

                        else if (i == 0 and j == b)
                            std::cout << "┌─────┐";
                        else if (i == a and j == b)
                            std::cout << "─────┘";
                        else if (j == b)
                            std::cout << "┌─────+";
                        else if (i == 0)
                            std::cout << "┌─────";
                        else if (i == a)
                            std::cout << "─────┘";
                        else
                            std::cout << "┌─────";
                    }
                    std::cout << " " << std::endl;
                }
                std::cout << " " << std::endl;
            }
        }
        // ┏━╸╻ ╻┏━┓┏━┓
        // ┃  ┣━┫┣━┫┣┳┛
        // ┗━╸╹ ╹╹ ╹╹┗╸
        // ================================================================

        void table_type_2_char(vector<vector<char>> &v, function<void(vector<char> &, const vector<int> &)> print_func,
                               string text1 = "", string text2 = "", const vector<vector<int>> &trace = {})
        {
            size_t a = v.size() + 1, b = v[0].size() - 1; // a and b will keep the length of the dimensions of vov
            VECTOR_OUTER_LEN = a, VECTOR_INNER_LEN = b;
            bool text1_exhausted = false; // it will trake if text1 is exhausted printing

            // first printing the text2 on the top of the box
            print_char_horizontal(text1, text2);

            if (b == 0) // when the breadthe of the vov is 1
            {
                for (size_t i = 0; i <= a; i++)
                {
                    if (i > 0 and i < a)
                    {
                        print_char_vertical(text1, text1_exhausted, i); // this prints out the first string at left
                        if (!trace.empty())                             // if trace vectro is not empty
                            print_func(v[i - 1], trace[i - 1]);         // this prints the vertical pipes and contents in the boxes
                        else
                            print_func(v[i - 1], {}); // this prints the vertical pipes and contents in the boxes
                    }

                    if (i == a - 1)
                        continue;

                    for (size_t j = 0; j <= b; j++)
                    {
                        if (i == 0 && j == 0)
                            (text1.empty()) ? std::cout << "┏━━━━━┓" : std::cout << "     ┏━━━━━┓";
                        else if (i == 0 and j == b)
                            (text1.empty()) ? std::cout << "┏━━━━━┓" : std::cout << "     ┏━━━━━┓";
                        else if (i == a and j == 0)
                            (text1.empty()) ? std::cout << "┗━━━━━┛" : std::cout << "     ┗━━━━━┛";
                        else if (i == a and j == b)
                            (text1.empty()) ? std::cout << "┗━━━━━┛" : std::cout << "     ┗━━━━━┛";
                        else if (j == 0)
                            (text1.empty()) ? std::cout << "┣━━━━━┫" : std::cout << "     ┣━━━━━┫";
                        else if (j == b)
                            (text1.empty()) ? std::cout << "┣━━━━━┫" : std::cout << "     ┣━━━━━┫";
                        else
                            (text1.empty()) ? std::cout << "───────" : std::cout << "     ───────";
                    }
                    std::cout << " " << std::endl;
                }
                std::cout << " " << std::endl;
            }
            else if (a == 1)
            {
                // for this block do nothing
            }
            else
            {
                for (size_t i = 0; i <= a; i++)
                {
                    if (i > 0 and i < a)
                    {
                        print_char_vertical(text1, text1_exhausted, i); // this prints out the first string at left
                        if (!trace.empty())                             // if trace vectro is not empty
                            print_func(v[i - 1], trace[i - 1]);         // this prints the vertical pipes and contents in the boxes
                        else
                            print_func(v[i - 1], {}); // this prints the vertical pipes and contents in the boxes
                    }

                    if (i == a - 1)
                        continue;

                    for (size_t j = 0; j <= b; j++)
                    {
                        if (j == 0)
                        {
                            if (i == 0)
                                (text1.empty()) ? std::cout << "┏━━━━━┳" : std::cout << "     ┏━━━━━┳";
                            else if (i == a)
                                (text1.empty()) ? std::cout << "┗━━━━━" : std::cout << "     ┗━━━━━";
                            else
                                (text1.empty()) ? std::cout << "┣━━━━━╋" : std::cout << "     ┣━━━━━╋";
                        }
                        else if (i == 0 and j == b)
                            std::cout << "━━━━━┓";
                        else if (i == a and j == b)
                            std::cout << "┻━━━━━┛";
                        else if (j == b)
                            std::cout << "━━━━━┫";
                        else if (i == 0)
                            std::cout << "━━━━━┳";
                        else if (i == a)
                            std::cout << "┻━━━━━";
                        else
                            std::cout << "━━━━━╋";
                    }
                    std::cout << " " << std::endl;
                }
                std::cout << " " << std::endl;
            }
        }

        void table_type_1_char(vector<vector<char>> &v, function<void(vector<char> &, const vector<int> &)> print_func,
                               string text1 = "", string text2 = "", const vector<vector<int>> &trace = {})
        {
            size_t a = v.size() + 1, b = v[0].size() - 1; // a and b will keep the length of the dimensions of vov
            VECTOR_OUTER_LEN = a, VECTOR_INNER_LEN = b;
            bool text1_exhausted = false; // it will trake if text1 is exhausted printing

            // first printing the text2 on the top of the box
            print_char_horizontal(text1, text2);

            if (b == 0) // when the breadthe of the vov is 1
            {
                for (size_t i = 0; i <= a; i++)
                {
                    if (i > 0 and i < a)
                    {
                        print_char_vertical(text1, text1_exhausted, i); // this prints out the first string at left
                        if (!trace.empty())                             // if trace vectro is not empty
                            print_func(v[i - 1], trace[i - 1]);         // this prints the vertical pipes and contents in the boxes
                        else
                            print_func(v[i - 1], {}); // this prints the vertical pipes and contents in the boxes
                    }

                    if (i == a - 1)
                        continue;

                    for (size_t j = 0; j <= b; j++)
                    {
                        if (i == 0 && j == 0)
                            (text1.empty()) ? std::cout << "┌─────┐" : std::cout << "     ┌─────┐";
                        else if (i == 0 and j == b)
                            (text1.empty()) ? std::cout << "┌─────┐" : std::cout << "     ┌─────┐";
                        else if (i == a and j == 0)
                            (text1.empty()) ? std::cout << "└─────┘" : std::cout << "     └─────┘";
                        else if (i == a and j == b)
                            (text1.empty()) ? std::cout << "└─────┘" : std::cout << "     └─────┘";
                        else if (j == 0)
                            (text1.empty()) ? std::cout << "+─────+" : std::cout << "     +─────+";
                        else if (j == b)
                            (text1.empty()) ? std::cout << "+─────+" : std::cout << "     +─────+";
                        else
                            (text1.empty()) ? std::cout << "───────" : std::cout << "     ───────";
                    }
                    std::cout << " " << std::endl;
                }
                std::cout << " " << std::endl;
            }
            else if (a == 1)
            {
                // for this block do nothing
            }
            else
            {
                for (size_t i = 0; i <= a; i++)
                {
                    if (i > 0 and i < a)
                    {
                        print_char_vertical(text1, text1_exhausted, i); // this prints out the first string at left
                        if (!trace.empty())                             // if trace vectro is not empty
                            print_func(v[i - 1], trace[i - 1]);         // this prints the vertical pipes and contents in the boxes
                        else
                            print_func(v[i - 1], {}); // this prints the vertical pipes and contents in the boxes
                    }

                    if (i == a - 1)
                        continue;

                    for (size_t j = 0; j <= b; j++)
                    {
                        if (j == 0)
                        {
                            if (i == 0)
                                (text1.empty()) ? std::cout << "┌─────" : std::cout << "     ┌─────";
                            else if (i == a)
                                (text1.empty()) ? std::cout << "└─────┘" : std::cout << "     └─────┘";
                            else
                                (text1.empty()) ? std::cout << "+─────" : std::cout << "     +─────";
                        }

                        else if (i == 0 and j == b)
                            std::cout << "┌─────┐";
                        else if (i == a and j == b)
                            std::cout << "─────┘";
                        else if (j == b)
                            std::cout << "┌─────+";
                        else if (i == 0)
                            std::cout << "┌─────";
                        else if (i == a)
                            std::cout << "─────┘";
                        else
                            std::cout << "┌─────";
                    }
                    std::cout << " " << std::endl;
                }
                std::cout << " " << std::endl;
            }
        }

    public:
        // ┏━┓╻ ╻┏┓ ╻  ╻┏━╸
        // ┣━┛┃ ┃┣┻┓┃  ┃┃
        // ╹  ┗━┛┗━┛┗━╸╹┗━╸
        // ╺━╸╺━╸╺━╸╺━╸╺━╸╺━╸╺━╸╺━╸╺━╸╺━╸╺━╸╺━╸╺━╸╺━╸╺━╸╺━╸╺━╸╺━╸╺━╸╺━╸╺━╸╺━╸╺━╸╺━╸╺━╸╺━╸
        // ╺━╸╺━╸╺━╸╺━╸╺━╸╺━╸╺━╸╺━╸╺━╸╺━╸╺━╸╺━╸╺━╸╺━╸╺━╸╺━╸╺━╸╺━╸╺━╸╺━╸╺━╸╺━╸╺━╸╺━╸╺━╸╺━╸

        // ┏┓ ┏━┓╻ ╻   ╺┓
        // ┣┻┓┃ ┃┏╋┛    ┃
        // ┗━┛┗━┛╹ ╹╺━╸╺┻╸
        // Integer
        // ====================================================================
        // ====================================================================
        // main function
        void Box_1(vector<vector<int>> &v, string text1, string text2,
                   vector<vector<int>> &trace)
        {
            table_type_1_int(v, &print_type_1_int, text1, text2, trace);
        }

        // derivatives

        void Box_1(vector<vector<int>> &v, string text1, string text2,
                   vector<int> &trace)
        {
            vector<vector<int>> tmp = {};
            tmp.push_back(trace);
            table_type_1_int(v, &print_type_1_int, text1, text2, tmp);
        }
        void Box_1(vector<int> &v, string text1, string text2,
                   vector<int> &trace)
        {
            vector<vector<int>> vv = {};
            vv.push_back(v);
            vector<vector<int>> tmp = {};
            tmp.push_back(trace);
            table_type_1_int(vv, &print_type_1_int, text1, text2, tmp);
        }

        void Box_1(vector<vector<int>> &v, string text1 = "", string text2 = "")
        {
            vector<vector<int>> trace = {};
            Box_1(v, text1, text2, trace);
        }

        void Box_1(vector<int> &v, string text1 = "", string text2 = "")
        {
            vector<vector<int>> vov = {};
            vov.push_back(v);
            Box_1(vov, text1, text2);
        }

        // converting array to vector and giving main funtion call
        void Box_1(int *arr, size_t len, string text1 = "", string text2 = "",
                   int *trace = nullptr, size_t len2 = 0)
        {
            // vector<int> v(len, 0);
            // for (size_t i = 0; i < len; i++)
            //     v[i] = *(arr + i);

            vector<int> v = CONVERT.arr_to_vec(arr, len);
            vector<int> temp(len2, 0);
            for (size_t i = 0; i < len2; i++)
                for (size_t j = 0; j < len2; j++)
                    temp.push_back(*(trace + i + j));

            Box_1(v, text1, text2, temp);
        }

        // Boolean :
        // ╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹
        // ╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹
        // main function

        void Box_1(vector<vector<bool>> &v, string text1 = "", string text2 = "")
        {
            table_type_1_bool(v, &print_type_1_bool, text1, text2);
        }

        void Box_1(vector<bool> &v, string text1 = "", string text2 = "")
        {
            vector<vector<bool>> vov;
            vov.push_back(v);
            // table_type_1_bool(vov, &print_type_1_bool, text1, text2);
            Box_1(vov, text1, text2);
        }

        void Box_1(bool *arr_of_arr, size_t len = 1, size_t width = 1, string text1 = "", string text2 = "")
        {
            vector<vector<bool>> vov = CONVERT.aoa_to_vov(arr_of_arr, len, width);
            Box_1(vov, text1, text2);
        }

        // Character :
        // ╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹
        // ╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹
        // this is the main function handling the vov with char
        void Box_1(vector<vector<char>> &v, string text1 = "", string text2 = "",
                   const vector<vector<int>> &trace = {})
        {
            table_type_1_char(v, &print_type_1_char, text1, text2, trace);
        }

        // derivative of Box_1 for vector of chracters
        void Box_1(vector<char> &v, string text1 = "", string text2 = "")
        {
            // CARRY_V_IN = 1, CARRY_V_OUT = 1;
            vector<vector<char>> vov;
            vov.push_back(v);
            Box_1(vov, text1, text2, {});
        }

        void Box_1(char *arr_of_arr, size_t len, size_t width, string text1 = "", string text2 = "",
                   int *trace = nullptr, size_t len2 = 0, size_t width2 = 0)
        {

            vector<vector<char>> v = CONVERT.aoa_to_vov(arr_of_arr, len, width); // vov
            vector<vector<int>> t = CONVERT.aoa_to_vov(trace, len2, width2);     // trace

            // main function call
            table_type_1_char(v, &print_type_1_char, text1, text2, t);
        }

        // ┏┓ ┏━┓╻ ╻   ┏━┓
        // ┣┻┓┃ ┃┏╋┛   ┏━┛
        // ┗━┛┗━┛╹ ╹╺━╸┗━╸
        // ====================================================================
        // ====================================================================

        // Integer :
        // ╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹
        // ╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹
        // this is main function call for Box_2 for vector of vector integer type
        // main funtion signature
        void Box_2(vector<vector<int>> &v, string text1, string text2,
                   const vector<vector<int>> &trace)
        {
            table_type_2_int(v, &print_type_2_int, text1, text2, trace);
        }

        // ╺┳┓┏━╸┏━┓╻╻ ╻┏━┓╺┳╸╻╻ ╻┏━╸   ┏━╸╻ ╻┏┓╻┏━╸╺┳╸╻┏━┓┏┓╻   ┏━┓╻┏━╸┏┓╻┏━┓╺┳╸╻ ╻┏━┓┏━╸
        //  ┃┃┣╸ ┣┳┛┃┃┏┛┣━┫ ┃ ┃┃┏┛┣╸    ┣╸ ┃ ┃┃┗┫┃   ┃ ┃┃ ┃┃┗┫   ┗━┓┃┃╺┓┃┗┫┣━┫ ┃ ┃ ┃┣┳┛┣╸
        // ╺┻┛┗━╸╹┗╸╹┗┛ ╹ ╹ ╹ ╹┗┛ ┗━╸   ╹  ┗━┛╹ ╹┗━╸ ╹ ╹┗━┛╹ ╹   ┗━┛╹┗━┛╹ ╹╹ ╹ ╹ ┗━┛╹┗╸┗━╸
        // derivative for fuction calls without color tracer
        void Box_2(vector<vector<int>> &v, string text1 = "", string text2 = "")
        {
            Box_2(v, text1, text2, {});
        }

        // derivative of Box_2 for vector of integers without color tracer
        // void Box_2(vector<int> &v, string text1 = "", string text2 = "")
        // {
        //     CARRY_V_IN = 1, CARRY_V_OUT = 1;
        //     vector<vector<int>> vov;
        //     vov.push_back(v);
        //     Box_2(vov, text1, text2, {});
        // }

        // derivative of Box_2 for vector of integers with color tracer
        void Box_2(vector<int> &v, string text1 = "", string text2 = "", const vector<int> &trace = {})
        {
            CARRY_V_IN = 1, CARRY_V_OUT = 1;
            vector<vector<int>> vov;
            vov.push_back(v);
            vector<vector<int>> trace_ov;
            trace_ov.push_back(trace);

            Box_2(vov, text1, text2, trace_ov);
        }

        // converting array to vector and giving main funtion call
        void Box_2(int *arr, size_t len, string text1 = "", string text2 = "",
                   int *trace = nullptr, size_t len2 = 0)
        {
            // vector<int> v(len, 0);
            // for (size_t i = 0; i < len; i++)
            //     v[i] = *(arr + i);

            vector<int> v = CONVERT.arr_to_vec(arr, len);
            vector<int> temp(len2, 0);
            for (size_t i = 0; i < len2; i++)
                for (size_t j = 0; j < len2; j++)
                    temp.push_back(*(trace + i + j));

            Box_2(v, text1, text2, temp);
        }

        // this is derived for adapting array of array
        void Box_2(int *arr_of_arr, size_t len, size_t width, string text1 = "", string text2 = "",
                   int *trace = nullptr, size_t len2 = 0, size_t width2 = 0)
        {
            // generating new vector of vector using array of array
            // vector<vector<int>> v(len, vector<int>(width, 0));
            // for (size_t i = 0; i < len; i++)
            //     for (size_t j = 0; j < width; j++)
            //         v[i][j] = *(arr_of_arr + i * len + j); //legacy

            // generating vov for color tracer using given array of array
            // vector<vector<int>> t;
            // if (trace != nullptr)
            // {
            //     for (size_t i = 0; i < len2; i++)
            //     {
            //         vector<int> temp(width2, 0);
            //         for (size_t j = 0; j < width2; j++)
            //             temp[j] = *(trace + i + j);
            //         t.push_back(temp);
            //     }
            // } // legacy

            vector<vector<int>> v = CONVERT.aoa_to_vov(arr_of_arr, len, width);
            vector<vector<int>> t = CONVERT.aoa_to_vov(trace, len2, width2);

            // main function call
            table_type_2_int(v, &print_type_2_int, text1, text2, t);
        }

        // Boolean :
        // ╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹
        // ╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹
        // this is main function for Box_2 for vector of vector boolean type
        void Box_2(vector<vector<bool>> &v, string text1 = "", string text2 = "")
        {
            table_type_2_bool(v, &print_type_2_bool, text1, text2);
        }

        void Box_2(vector<bool> &v, string text1 = "", string text2 = "")
        {
            vector<vector<bool>> vov;
            vov.push_back(v);
            // table_type_2_bool(vov, &print_type_2_bool, text1, text2);
            Box_2(vov, text1, text2);
        }

        void Box_2(bool *arr_of_arr, size_t len = 1, size_t width = 1, string text1 = "", string text2 = "")
        {
            vector<vector<bool>> vov = CONVERT.aoa_to_vov(arr_of_arr, len, width);
            Box_2(vov, text1, text2);
        }

        // Character :
        // ╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹
        // ╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹╹
        // this is the main function handling the vov with char
        void Box_2(vector<vector<char>> &v, string text1 = "", string text2 = "",
                   const vector<vector<int>> &trace = {})
        {
            table_type_2_char(v, &print_type_2_char, text1, text2, trace);
        }

        // derivative of Box_2 for vector of chracters
        void Box_2(vector<char> &v, string text1 = "", string text2 = "")
        {
            // CARRY_V_IN = 1, CARRY_V_OUT = 1;
            vector<vector<char>> vov;
            vov.push_back(v);
            Box_2(vov, text1, text2, {});
        }

        void Box_2(char *arr_of_arr, size_t len, size_t width, string text1 = "", string text2 = "",
                   int *trace = nullptr, size_t len2 = 0, size_t width2 = 0)
        {

            vector<vector<char>> v = CONVERT.aoa_to_vov(arr_of_arr, len, width); // vov
            vector<vector<int>> t = CONVERT.aoa_to_vov(trace, len2, width2);     // trace

            // main function call
            table_type_2_char(v, &print_type_2_char, text1, text2, t);
        }
    };
}

#endif

// ┏━╸┏━┓╻ ╻┏━┓┏━┓╻ ╻
// ┃╺┓┣━┫┃ ┃┣┳┛┣━┫┃┏┛
// ┗━┛╹ ╹┗━┛╹┗╸╹ ╹┗┛