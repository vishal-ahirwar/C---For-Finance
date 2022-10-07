#include<iostream>
#include<string>

//Importing the std namespace into the global namespace with
using namespace std;

//An alternative is to put using statements with the namespace scopes at the top of the file, indicating that anytime these elements appear in the code, they are understood to be coming from the std namespace. 
using std::cout;
using std::cin;
using std::endl;

int main()
{
    std::cout<<"Hello, World!\n";
    std::cout<<"Oops! Sorry,\n";
    std::cout<<"Your Name  :";
    std::string name{};
    std::cin>>name;
    std::cout<<"Hello, "<<name<<"\n";
    return 0;
};
/*
cout and cin, along with the string class, depend upon including the C++ Standard Library declaration files iostream and string.
Members of the Standard Library need to be scoped by their namespace std.
An alternative is to put using statements with the namespace scopes at the top of the file, 
indicating that anytime these elements appear in the code, they are understood to be coming from the std namespace. Also, 
you may find it easier to type endl (end of line) rather than '\n’
*/


/*
The structure of a procedural program should be familiar, namely:

A `main()` function, which is called first in execution of a program, and

A set of user-defined functions that contain individual tasks that comprise the program.

In the simplest case, these can all be written in a single executable file containing `main()`.

We first declare each user-defined function in a function declaration statement, prior to the start of program execution in the `main()` function. A function declaration states its name, return type, and input argument types, followed by a semicolon.

The function implementations are written beneath `main()`, each containing a series of commands within open and closed braces. User-defined function calls can then be made within the `main` function, or from other user-defined functions.

Single line comments are indicated by two consecutive forward slashes. The high-level format is shown here
// Function declarations ("//" indicates a comment line)
return_type function_01(input arguments);
return_type function_02(input arguments);
return_type function_03(input arguments);
.
.
.
int main()
{
  // Call each function 
  function_01(input arguments);
  function_02(input arguments);
  function_03(input arguments);
.
.
.
}
return_type function_01(input arguments)
{
  // Do stuff
  // Return something (or void return)
}
return_type function_02(input arguments)
{
  // Do stuff
  // Return something (or void return)
}
return_type function_03(input arguments)
{
  // Do stuff
  // Return something (or void return)
}
.
.
.

unction declarations
C++ functions may or may not return a value; furthermore, they may or may not take input arguments. A function that has no return value is indicated by a `void` return type. For example, if we move our “Hello World” example into a separate function, it would simply output a message to the screen without returning a value when called from the `main` function, so it would be declared as a `void` function. In addition, it does not require any input parameters, so its declaration would take on the form


void hello_world(); 

Next, suppose we want to write a real-valued function that takes in a single variable and returns twice its value. In this case, our declaration will have a double precision floating type return, indicated by `double`, and an input of the same type. If we name this function `twice_a_real`, and the input variable `x`, our declaration would be written as

double twice_a_real(double x); 

As a final example, as in other programming languages, a function can take in more than one variable. Suppose we wish to add three integers in a function called `add_three_ints` and return the sum of variables `i`, `j`, and `k`. Integer types are indicated by `int`, so our function declaration would be

int add_three_ints(int i, int j, int k);    

Function implementations
Function implementations, also called function definitions, are where we implement the actual commands to display a message to the screen, calculate a mathematical result, or to perform other tasks. The body of the function is placed inside braces, as shown here for the `hello_world` function. We again need to indicate the `void` return type.


void hello_world()
{
  std::cout << "Hello World!\n";
}


we can write the implementations of our two simple mathematical functions. As in their declarations, the `double` and `int` return types, respectively, as well as the types of their input variables, must be included:

double twice_a_real(double x)
{
	double y = 2.0 * x;
	return y;
}
int add_three_ints(int i, int j, int k)
{
	return i + j + k;
}


Commands and declarations in C++ terminate with a semicolon:


Again, as C++ is a strongly-typed language, numerical variable types should be indicated before initialization.

double x1 = 10.6;
int k;	// Defaults to zero
double y1 = twice_a_real(x1);

C++11 introduced the `auto` keyword that can automatically deduce a variable or object type, as well as uniform initialization (with braces). Varied opinions on their use exist, but many programmers still prefer to explicitly state plain old data (POD) types such as `int` and `double` to avoid ambiguity. This will be the style followed in this book. `auto` and uniform initialization will be discussed later within contexts where they tend to be more useful.


One-line comments are indicated with two forward slashes, eg,

// This is a comment



There is no difference to the compiler between a single space or multiple spaces; for example, despite the variations in whitespace, the following code is legal:

  int j = 1101;
  int k=   603;
  int sum = j +    k;
  std::cout <<    "j + k = " <<   sum << "\n";



  A well-known mantra in programming, however, and particularly relevant to C++, is just because you can do something, doesn’t mean you should. The above code will be more readable and maintainable if written with clear and consistent spacing:

  int j = 1101;
  int k = 603;
  int sum = j + k;
  std::cout << "j + k = " << sum << "\n";


  Again, for more realistic and complex code, this mantra should be kept in mind. It will be a recurring theme throughout this book.

Code may also be continued onto multiple lines without the use of a continuation character, and vertical spaces are ignored. Returning to our previous example, writing

  int j = 1101;
  int k = 
          603;
  
  int sum = j + k;
  std::cout << "j + k = " 
            << sum 
            << "\n";
would yield the same result. As before, the preceding example, with uniform spacing and each command placed in a single line, would be preferable. However, it should be noted that, in quantitative programming where complex and nested calculations are involved, it often becomes highly advisable to split up formulae and algorithms on multiple lines for clarity and code maintainability. We will see examples of this in subsequent chapters.

Finally, C++ syntax is case sensitive. For example, two `double` variables `x` and `X` would be as different as two other variables `kirk` and `spock`. The same applies to function names. In examples above, we used the Standard Library function `std::cout`. Attempting to write `std::Cout` instead would trigger a compiler error.



Naming Conventions
Variable, function, and class names can be any contiguous combination of letters and numbers, subject to the following conditions:

Names must begin with a letter or an underscore; leading numerals are not allowed.

Other than the underscore character, special characters, such as `@`, `=`, `$` etc are not allowed.

Spaces are not allowed. Names must be contiguous.

Language keywords are not allowed in naming, such as `double`, `if`, `while`, etc. A complete listing can be found on https://en.cppreference.com/w/cpp/keyword.

The maximum name length is compiler-dependent, and in at least one case – the GNU gcc compiler – imposes no limitation; however, see the mantra discussed above.

Single letter variable and function names are fine for simple examples and plain mathematical functions. However, for quantitative models, it will usually be better to pass function arguments with more descriptive names. Function and class names as well should also provide some indication of what they do.



Several naming styles have been common over the years, namely

Lower Camel case; eg, `optionDelta`, `riskFreeRate`, `efficientFrontier`: Letter of first word in lower case, and following words capitalized

Upper Camel, aka Pascal case; eg, `OptionDelta`, `RiskFreeRate`, `EfficientFrontier`: Letter of each word is in upper case

Snake case; eg, `option_delta`, `risk_free_rate`, `efficient_frontier`: Each word begins with lower case, separated by an underscore character


ower Camel and Snake cases are the most typical of what is found in C++ function and variable names, and class names are usually in Upper Camel form. In recent years – likely propelled by Google’s C++ Style Guide [5] – variable and function names have gravitated more toward the snake case. As such, we will adopt this convention in this book, and use Upper Camel for class names.

In cases where single characters are used for integral counting variables, it is still common to use the FORTRAN convention of letters `i` through `n`, although this is not required. We will also adopt this practice.
*/
