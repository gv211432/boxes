#ifndef gauravs_print_arr_vec
#define gauravs_print_arr_vec

namespace print_vec
{
#include <iostream>
#include <vector>
#include <stdbool.h>
    using namespace std;

    class Print
    {
    public:
        // ==================================================================
        // ==================================================================

        // Print the array of size "n"
        // print_arr(*array, array_size)
        void print_arr(int *arr, size_t len)
        {
            std::cout << "[ ";
            for (size_t i = 0; i < len; i++)
                cout << *(arr + i), ((i + 1) < len) ? cout << ", " : cout << " ";
            std::cout << "]" << std::endl;
        }

        // Print the bool array of size "n"
        // print_arr(*array, array_size)
        void print_arr(bool *arr, size_t len)
        {
            std::cout << "[ ";
            for (size_t i = 0; i < len; i++)
                cout << *(arr + i), ((i + 1) < len) ? cout << ", " : cout << " ";
            std::cout << "]" << std::endl;
        }

        // Print the char array of size "n"
        // print_arr(*array, array_size)
        void print_arr(char *arr, size_t len)
        {
            std::cout << "[ ";
            for (size_t i = 0; i < len; i++)
                cout << *(arr + i), ((i + 1) < len) ? cout << ", " : cout << " ";
            std::cout << "]" << std::endl;
        }

        // ==================================================================

        // Prints the vector "v" int
        void print_arr(vector<int> &v)
        {
            std::cout << "[ ";
            for (auto &n : v)
                std::cout << n, &n == &v.back() ? cout << " " : cout << ", ";
            std::cout << "]" << std::endl;
        }

        // Prints the vector "v" bool
        void print_arr(vector<bool> &v)
        {
            std::cout << "[ ";
            for (size_t i = 0; i < v.size(); i++)
            {
                std::cout << v[i];
                if (i == v.size() - 1)
                    cout << " ";
                else
                    cout << ", ";
            }
            std::cout << "]" << std::endl;
        }

        // Prints the vector "v" char
        void print_arr(vector<char> &v)
        {
            std::cout << "[ ";
            for (auto &n : v)
                std::cout << n, &n == &v.back() ? cout << " " : cout << ", ";
            std::cout << "]" << std::endl;
        }

        // Prints the vector "v" string
        void print_arr(vector<string> &v)
        {
            std::cout << "[ ";
            for (auto &n : v)
                std::cout << n, &n == &v.back() ? cout << " " : cout << ", ";
            std::cout << "]" << std::endl;
        }

        // ==================================================================
        // ==================================================================

        // Prints the array of array with length "len" and width as "width"
        // print_aoa(*array, array_len, array_width)
        void print_aoa(int *arr, size_t len, size_t width)
        {
            std::cout << "[ \n";
            for (size_t i = 0; i < len; i++)
            {
                std::cout << "[ ";
                for (size_t j = 0; j < width; j++)
                    cout << *(arr + i * len + j), ((j + 1) < width) ? cout << ", " : cout << " ";
                std::cout << "]" << std::endl;
            }
            std::cout << "]" << std::endl;
        }

        // Prints the array of array with length "len" and width as "width"
        // print_aoa(*array, array_len, array_width)
        void print_aoa(bool *arr, size_t len, size_t width)
        {
            std::cout << "[ \n";
            for (size_t i = 0; i < len; i++)
            {
                std::cout << "[ ";
                for (size_t j = 0; j < width; j++)
                    cout << *(arr + i * len + j), ((j + 1) < width) ? cout << ", " : cout << " ";
                std::cout << "]" << std::endl;
            }
            std::cout << "]" << std::endl;
        }

        // Prints the array of array with length "len" and width as "width"
        // print_aoa(*array, array_len, array_width)
        void print_aoa(char *arr, size_t len, size_t width)
        {
            std::cout << "[ \n";
            for (size_t i = 0; i < len; i++)
            {
                std::cout << "[ ";
                for (size_t j = 0; j < width; j++)
                    cout << *(arr + i * len + j), ((j + 1) < width) ? cout << ", " : cout << " ";
                std::cout << "]" << std::endl;
            }
            std::cout << "]" << std::endl;
        }

        // ==================================================================

        // Prints the vector of vector
        void print_aoa(vector<vector<int>> &v)
        {
            for (auto &x : v)
            {
                std::cout << "{ ";
                for (auto &n : x)
                    std::cout << n, &n == &x.back() ? cout << " " : cout << ", ";
                std::cout << "}" << std::endl;
            }
        }

        // Prints the vector of vector
        void print_aoa(vector<vector<char>> &v)
        {
            for (auto &x : v)
            {
                std::cout << "{ ";
                for (auto &n : x)
                    std::cout << n, &n == &x.back() ? cout << " " : cout << ", ";
                std::cout << "}" << std::endl;
            }
        }

        // Prints the vector of vector
        void print_aoa(vector<vector<bool>> &vec)
        {
            for (auto &v : vec)
            {
                std::cout << "{ ";
                for (size_t i = 0; i < v.size(); i++)
                {
                    std::cout << v[i];
                    if (i == v.size() - 1)
                        cout << " ";
                    else
                        cout << ", ";
                }
                std::cout << "}" << std::endl;
            }
        }

        void print_aoa(vector<vector<string>> &v)
        {
            for (auto x : v)
            {
                std::cout << "{ ";
                for (auto &n : x)
                    std::cout << n, &n == &x.back() ? cout << " " : cout << ", ";
                std::cout << "}" << std::endl;
            }
        }

        // ==================================================================
        // ==================================================================

        // Prints the vector "v"
        void print_vov(vector<int> &v)
        {
            std::cout << "{ ";
            for (auto &n : v)
                std::cout << n, &n == &v.back() ? cout << " " : cout << ", ";
            std::cout << "}" << std::endl;
        }

        // Prints the vector "v"
        void print_vov(vector<bool> &v)
        {
            std::cout << "{ ";
            // here we cannot take reference of bool element
            for (size_t i = 0; i < v.size(); i++)
            {
                std::cout << v[i];
                if (i == v.size() - 1)
                    cout << " ";
                else
                    cout << ", ";
            }
            std::cout << "}" << std::endl;
        }

        // Prints the vector "v"
        void print_vov(vector<char> &v)
        {
            std::cout << "{ ";
            for (auto &n : v)
                std::cout << n, &n == &v.back() ? cout << " " : cout << ", ";
            std::cout << "}" << std::endl;
        }

        void print_vov(vector<string> &v)
        {
            std::cout << "{ ";
            for (auto &n : v)
                std::cout << n, &n == &v.back() ? cout << " " : cout << ", ";
            std::cout << "}" << std::endl;
        }

        // ==================================================================

        // template <typyname T>
        void print_vov(vector<vector<int>> &v)
        {
            for (auto &x : v)
            {
                std::cout << "{ ";
                for (auto &n : x)
                    std::cout << n, &n == &x.back() ? cout << " " : cout << ", ";
                std::cout << "}" << std::endl;
            }
        }

        void print_vov(vector<vector<bool>> &vec)
        {
            for (auto &v : vec)
            {
                std::cout << "{ ";
                for (size_t i = 0; i < v.size(); i++)
                {
                    std::cout << v[i];
                    if (i == v.size() - 1)
                        cout << " ";
                    else
                        cout << ", ";
                }
                std::cout << "}" << std::endl;
            }
        }

        void print_vov(vector<vector<char>> &v)
        {
            for (auto &x : v)
            {
                std::cout << "{ ";
                for (auto &n : x)
                    std::cout << n, &n == &x.back() ? cout << " " : cout << ", ";
                std::cout << "}" << std::endl;
            }
        }

        void print_vov(vector<vector<string>> &v)
        {
            for (auto &x : v)
            {
                std::cout << "{ ";
                for (auto &n : x)
                    std::cout << n, &n == &x.back() ? cout << " " : cout << ", ";
                std::cout << "}" << std::endl;
            }
        }
    };
} // namespace print_vov

#endif