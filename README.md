# Connect Four Solver library for Android Studio 

The library is developed based on my connect 4 solver written in c++. Link to my c++ solver: https://github.com/bennywong3/connect4solver-cpp

The Java code calls function in this native library through the **Java Native Interface (JNI)**. I used **CMake** for this library.

Codes are modified to suit JNI, like no more main in cpp, no more ifstream as it is not supported, 7x6 book is moved to android asset file, etc.



## Content of this repo
Folder **c4solver**: This is the library. Import this folder as library in Android studio and you can use the solver!

Folder **librarytest**: the simple example app that uses the library to solve connect 4. You can see how to call the function in this example app.

This app takes in the connect 4 board position input and output the scores for the 7 columns. Highest score is the optimal move.

<img src=example.png height="500">

What is the Position’s notation? I quote from [Pascal Pons](http://blog.gamesolver.org/solving-connect-four/02-test-protocol/)
> We will simply use the sequence of the played columns to code any valid Connect 4 position. The first column (left) is 1, the second column is 2, etc.

For example, the Position “4453” is:

<img src=website_example.jpg height="300">

The above screenshot is from [his website](https://connect4.gamesolver.org/?pos=4453), you can validate that the library calculates correctly.
