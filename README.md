![GitHub](https://img.shields.io/github/license/GV211432/boxes) ![GitHub issues](https://img.shields.io/github/issues-raw/GV211432/boxes) ![GitHub Repo stars](https://img.shields.io/github/stars/GV211432/boxes?style=social)

<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/othneildrew/Best-README-Template">
    <img src="docs/logo/box-circle.png" alt="Logo" width="120" height="120" >
  </a>
  
  <h3 align="center"><b>boxes</b></h3>

  <p align="center">
    Print array, array of array, vector, vector of vector <br> and strings more beautifully 👰
    <br />
    <a href="#"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/othneildrew/Best-README-Template">View Demo</a>
    ·
    <a href="https://github.com/gv211432/boxes/issues">Report Bug</a>
    ·
    <a href="https://github.com/gv211432/boxes/issues">Request Feature</a>
  </p>
</div>

<!-- ABOUT THE PROJECT -->

## ☑️ About The Project

**Print more beautifully.**<br>
The objective of this project is to help algorithm learners to visualize the algorithms. And also help with menial tasks like printing something again and again.

_Useful 😑 for debugging purposes❗_

![Intro Image](./docs/img/intro1.png)

## ⚙️ Installation 

<details>
 <summary><i>Click to see</i></summary>
Just download this file from above

![How to download](./docs/img/download1.png)

and unzip it ....

![How to unzip](./docs/img/download2.png)

and include it in your project.

`include in your project`

<details>
  <summary><i>Click to open the code</i></summary>
  <p>

```c++
#include <bits/stdc++.h>
#include "../boxes-main/utilities.h"
using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    leetcode::Box.Box_2(v);
    return 0;
}
```

Output

```js
┏━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┓
┃  1  ┃  2  ┃  3  ┃  4  ┃  5  ┃
┗━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┛
```

  </p>
</details>

![How to include](./docs/img/install1.png)

Output

![Output](./docs/img/install1_output.png)

</details>



<p align="right">(<a href="#top">back to top</a>)</p>

## 🧩 Modules


<details>
 <summary><i>Click to see</i></summary>

This section only shows the overview and scope of the project.

![modules](./docs/img/modules1.gif)

There are 4 modules in the library and more is coming soon..

![modules](./docs/img/modules2.png)


</details><br>

## 📑 How to use 

<details>
 <summary><i>Click to see</i></summary><br>

- ### **`Box`**

Boxes used for printing `vector` or `vector of vector` or `_array_` or `_array of array_` of type `[int, char, bool]`

<!-- Boxes -->
<details>
 <summary><i><b>Boxes for vector</b></i></summary>

Box_1
- Simple use
```c++
vector<int> v = {1, 2, 3, 4, 5};
leetcode::Box.Box_1(v);
```
Output
```c
┌─────┌─────┌─────┌─────┌─────┐ 
|  1  |  2  |  3  |  4  |  5  |
└─────┘─────┘─────┘─────┘─────┘
```
Box_2
<!-- one -->
- Plain use
```c++
vector<int> v = {1, 2, 3, 4, 5};
leetcode::Box.Box_2(v);
```
Output
```c
┏━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┓ 
┃  1  ┃  2  ┃  3  ┃  4  ┃  5  ┃
┗━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┛ 
```
<!-- two -->
- With horizontal index
```c++
vector<int> v = {1, 2, 3, 4, 5};
leetcode::Box.Box_2(v,""," ");
```
Output
```c
   1     2     3     4     5   
┏━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┓ 
┃  1  ┃  2  ┃  3  ┃  4  ┃  5  ┃
┗━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┛ 
```
<!-- three -->
- With horizontal index and string on top
```c++
vector<int> v = {1, 2, 3, 4, 5};
leetcode::Box.Box_2(v, "", "abcde");
```
Output
```c
   a     b     c     d     e   
   1     2     3     4     5   
┏━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┓ 
┃  1  ┃  2  ┃  3  ┃  4  ┃  5  ┃
┗━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┛ 
```
<!-- four -->
- Print vector of vector
```c++
vector<vector<int>> vv = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {12, 13, 14, 15, 16}};
leetcode::Box.Box_2(vv);
```
Output
```c
┏━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┓ 
┃  1  ┃  2  ┃  3  ┃  4  ┃  5  ┃
┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫ 
┃  6  ┃  7  ┃  8  ┃  9  ┃ 10  ┃
┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫ 
┃ 12  ┃ 13  ┃ 14  ┃ 15  ┃ 16  ┃
┗━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┛ 
```
<!-- five -->
- With vertical index
```c++
vector<vector<int>> vv = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {12, 13, 14, 15, 16}};
leetcode::Box.Box_2(vv, " ");
```
Output
```c
     ┏━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┓ 
   0 ┃  1  ┃  2  ┃  3  ┃  4  ┃  5  ┃
     ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫ 
   1 ┃  6  ┃  7  ┃  8  ┃  9  ┃ 10  ┃
     ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫ 
   2 ┃ 12  ┃ 13  ┃ 14  ┃ 15  ┃ 16  ┃
     ┗━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┛ 
```
<!-- six -->
- With vertical and horizontal index
```c++
vector<vector<int>> vv = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {12, 13, 14, 15, 16}};
leetcode::Box.Box_2(vv, " ", " ");
```
Output
```c
        0     1     2     3     4   
     ┏━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┓ 
   0 ┃  1  ┃  2  ┃  3  ┃  4  ┃  5  ┃
     ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫ 
   1 ┃  6  ┃  7  ┃  8  ┃  9  ┃ 10  ┃
     ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫ 
   2 ┃ 12  ┃ 13  ┃ 14  ┃ 15  ┃ 16  ┃
     ┗━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┛ 
```
<!-- seven -->
- With index and strings
```c++
vector<vector<int>> vv = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {12, 13, 14, 15, 16}};
leetcode::Box.Box_2(vv, "xyz", "abcde");
```
Output
```c
        a     b     c     d     e   
        0     1     2     3     4   
     ┏━━━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━┓ 
x  0 ┃  1  ┃  2  ┃  3  ┃  4  ┃  5  ┃
     ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫ 
y  1 ┃  6  ┃  7  ┃  8  ┃  9  ┃ 10  ┃
     ┣━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━┫ 
z  2 ┃ 12  ┃ 13  ┃ 14  ┃ 15  ┃ 16  ┃
     ┗━━━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━┛ 
```


</details><br>

<!-- Array -->
<details>
 <summary><i><b>Boxes for array</b></i></summary>

</details><br>

<!-- third -->
<details>
 <summary><i>Click to see</i></summary>

</details><br>

</details><br>

## 📖 License 

  [MIT](https://github.com/gv211432/boxes/blob/main/LICENSE)
