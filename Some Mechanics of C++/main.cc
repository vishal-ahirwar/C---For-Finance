/*
The `vector` Container
The `vector` container in the C++ Standard Library is the go-to choice for storing and managing an indexed array of like types. It is particularly useful for managing vectors of real numbers that are ubiquitous in quantitative work, with `double` types representing the numerical values.
Being a generic container, `std::vector` can hold elements of a common arbitrary type, ranging from plain old data (POD) types such as `double` and `int`, to objects of user-defined and library classes.
#include <vector>
using std::vector;
//. . .
vector <double> x;		// Vector of real numbers
vector <BondTrade> bond_trades;	// Vector of user-defined BondTrade objects
The type to be held is indicated inside the angle brackets.

Setting and Accessing Elements of a `vector`
An STL `vector` essentially encapsulates and manages a dynamic array, meaning that elements can be appended to it or removed from it after it is constructed. The `vector` also supports random access, meaning an element can be accessed, and moreover modified, by the index of the element. Like everything else in C++, a `vector` is zero-indexed, meaning that the index of its first position is index 0, and its last position is index n - 1, if it holds n elements.

Creating a `vector` and Using its Index
The following instruction will create a vector holding three real numbers.

vector <double> v(3);	// Will hold three elements
The `vector` can be populated element by element as shown here. Note that indexing starts with zero rather than one.

v[0] = 10.6;		// Set the first element (index 0) and assign to 10.6
v[1] = 58.63;		// Set the second element (index 1) and assign to 58.63
v[2] = 0.874;		// Set the first element (index 2) and assign to 0.874

he index is indicated by square brackets. We can also change the values by simply reassigning an element to a new value; viz,

v[1] = 13.68;
It is also possible to initialize vectors using uniform initialization introduced in C++11. Also known as braced initialization, use of the assignment operator is optional:

vector <double> w{9.8, 36.8, 91.3, 104.7}; // No assignment operator
vector <int> q = {4, 12, 15};	 // With assignment operator 


Member Functions
As `vector` is a class, it holds a number of public member functions, including three: `at`, `size`, and `push_back`.

The `at` Function
The `at` function essentially performs the same roles as the square bracket operator, namely access of an element for a given index, or to modify the element.

double val = v.at(2);	// val = 0.874
w.at(1) = val;			// 36.8 in w[1] is replaced with 0.874

The difference between using the square bracket operator and the `at` function is the latter performs bound checking. Two examples are

Attempting to access an element that exceeds the maximum index; eg,

double out_of_range = v.at(100);	// 2 is the max index for v
Attempting to use a negative index value

w.at(-3) = 19.28;
In each case, an exception will be thrown that can be used in error handling. Otherwise, you can just think of `at` and `[.]` as the same.


The `size` Function
The name of this member function makes it fairly obvious what it does: it returns the number of elements held by a `vector`:

auto num_elems_w = w.size();	// Returns 5
auto num_elems_q = q.size();	// Returns 3
You may notice this is the first time we have used the `auto` keyword. What this does is automatically deduce the type returned from the `size` function. We will see in future cases how useful `auto` can be, but here, it helps us get around the fact that the maximum size of a `std::vector` container will vary depending upon compiler settings and the platform you are using. The type will be some form of an unsigned (non-negative) integer, of which there are multiple sizes.

So as to not get into the weeds here, we don’t need to be concerned with the specific unsigned type here, so we can mostly just use `auto` for the return type of the `size` member function.




The `push_back` Function
This function will append elements to a `vector`; that is, new elements are “pushed onto the back” of the container.

For example, we can append a new element to the `vector v` above, say 47.44:

v.push_back(47.44);
Now, `v` contains four values: 10.6, 58.63, 0.84, 47.44, with `v[3]` (fourth element, using 0-indexing) equal to the new value.

We can also append values to an empty vector. At the outset, we defined

vector <double> x;		// x.size() = 0
Now, if we append a value,

x.push_back(3.08);	// x.size() = 1
`x` now contains the value 3.08 in its index 0 position and contains one element. This can be repeated arbitrarily many times:
x.push_back(5.12);	// x.size() = 2
x.push_back(7.32);	// x.size() = 3
//. . . etc


To close the discussion on `push_back`, there is one potential gotcha to be aware of,

Suppose we create a `vector` of integers with three elements:

`vector <int> ints(3);`

Now, each element will hold the default value of an `int` type: 0.

If we then apply the `push_back` function to append, say, 5:

`ints.push_back(5);`

this value will be appended as a new element following the third zero; ie, the vector now contains four elements.

0 0 0 5

To put a value into any of the first three positions, you will need to use the index explicitly; eg

ints[0] = 2;
ints.at(2) = 4;
Concluding Remarks on STL `vector`s
In the examples above, we only used plain old numerical types `double` and `int`. Vectors of real numbers are of course fundamental for computational work, but keep in mind an STL `vector` is generic, in that it can hold elements of any valid type, including objects rather than just numerical data types, as we shall see in more advanced contexts.

Also, as mentioned earlier, in real-world production level programming, inputs are taken from function arguments that come from market and product data, and user input, not hard-coded values as seen in the previous examples. One might find vectors set with fixed numerical values in test functions, but they should be avoided in production code.

The Standard Library contains additional STL containers, plus a large set of STL algorithms that are now a core component of modern C++ programming. These will be discussed in greater detail in Chapter 7, and becoming familiar with the basics of the `vector` container now will make this material more accessible when we get to it.

Finally, to reiterate, prefer using an STL `vector` over a dynamic C-style array using `new` and `delete`. There is no performance benefit to using the latter, and memory management is all encapsulated inside the `vector` class, freeing the developer from risks due to memory leaks.



Enum Constants and Classes
Enumerated constants, more commonly called enums for short, map text to integers. Prior to C++11, enums were a great means of making it clearer for us mere mortals to comprehend integer codes by representing them in (contiguous) words. It was also far more efficient for the machine to process integers rather than bulkier `std::string` objects that take up more memory. And finally, errors caused by typos in quoted characters and stray strings could be avoided.

The C++11 Standard improved on this further with enum classes. These remove ambiguities that can occur with overlapping integer values when using regular enum constants, while preserving the advantages.



Enum Constants
Enums allow us to pass around identifiers, classifications, indicators etc in text representation, while behind the scenes, the compiler recognizes them as integers.

As an example, we can create an enum called `OptionType` that will indicate the types of option deals that are allowed in a simple trading system, eg European, American, Bermudan, and Asian. The `enum` type is declared; then, inside the braces, the allowable types are defined, separated by commas. By default, each will be assigned an integer value starting at zero and incremented by one (remember that indexing in C++ is zero-based). The closing brace must be followed by a semicolon. In code, we would write:


enum OptionType
{
    European,     	// default integer value = 0
    American,     	// default integer value = 1
    Bermudan,     	// default integer value = 2
    Asian	      	// default integer value = 3
};  


We can then verify that in place of each option type, its corresponding integer value is given:

cout << " European = " << European << endl;
cout << " American = " << American << endl;
cout << " Bermudan = " << Bermudan << endl;
cout << " Asian = " << Asian << endl;
cout << endl;
Checking the output, we get:

European
American
Bermudan
Asian
So, we can see how the program treats the text representations as integers. Note that these text labels are not enclosed in quotation marks, as they ultimately represent integer types, not strings.

Potential Conflicts with Enums
As discussed at the outset, for any `enum` type, the default integer assignments start at zero and then are incremented by one for each type member. Therefore, it is possible that two enumerated constants from two different types could be numerically equal. For example, suppose we define two different `enum` types, called `Football` and `Baseball`, representing the defensive positions in each sport. By default, the baseball positions start with 0 for the pitcher and are incremented by one for each in the list. The same goes for the football positions, starting with defensive tackle. The integer constants are provided in the comments.


enum Baseball
{
	Pitcher,		// 0
	Catcher,		// 1
	First_Baseman,	// 2
	Second_Baseman,	// 3
	Third_Baseman,	// 4
	Shortstop,		// 5
	Left_Field,    // 6
	Center_Field,	// 7
	Right_Field	// 8
};
enum Football
{
	Defensive_Tackle,	// 0
	Edge_Rusher,		// 1
	Defensive_End,		// 2
	Linebacker,		// 3
	Cornerback,		// 4
	Strong_Safety,		// 5
	Weak_Safety		// 6
};
Then, we could compare `Defensive_End` and `First_Baseman`:

	if (Defensive_End == First_Baseman)
	{
		cout << " Defensive_End == First_Baseman is true" << endl;
	}
	else
	{
		cout << " Defensive_End != First_Baseman is true" << endl;
	}
Our result would be nonsense:

Defensive_End == First_Baseman is true
This is because both positions map to an integer value of 2.

A quick fix, and one that was often employed prior to C++11, would be to reindex each set of enums; eg,

enum Baseball
{
	Pitcher = 100,	
	Catcher,		// 101
	First_Baseman,	// 102
	. . .
};
enum Football
{
	Defensive_Tackle = 200,
	Edge_Rusher,		// 201
	Defensive_End,		// 202
	. . .
};
Now, if we compare `Defensive_End` and `First_Baseman`, they will no longer be equal, because 202 ≠ 102. Still, in large code bases there might be hundreds of enum definitions, so it would not be out of the question for an overlap to slip in and cause errors. Enum classes, introduced in C++11, eliminate this risk.



Enum Classes
A new and more robust way to avoid `enum` overlaps was introduced in C++11 that eliminates the integer representation altogether. The other benefits of enums, such as avoiding cryptic numerical codes and larger string objects, still remain, but the conflicts are avoided by using what is called an enum class. As an example, we can define bond and futures contract categories within enum classes, as shown here:


enum class Bond
{
	Government,
	Corporate,		      
	Municipal,
	Convertible
};
enum class Futures_Contract
{
	Gold,
	Silver,
	Oil,
	Natural_Gas,
	Wheat,
	Corn
	};
enum class Options_Contract
{
    European,     	
    American,     	
    Bermudan,     
    Asian	      
};


Notice that we no longer need to manually set integer values to avoid conflicts as we did with regular enums.

Attempting to compare members of two different enum classes -- such as a `Bond` and a `Futures_Contract` position, will now result in a compiler error. For example, the following will not even compile:

if(Bond::Corporate == Futures_Contract::Gold)
{
	// . . .
}
This works to our advantage, as it is much better to catch an error at compile time rather than runtime. Modern best practices now maintain that we should prefer using enum classes rather than enumerated constants [[refer to ISO Guidelines]].

Control Structures
Control structures consist of two categories:

Conditional branching, such as `if` statements

Iterative controls that repeat a set of commands in a loop

In C++, the code that pertains to a given condition or sequence is contained in a block defined by braces. Similar to a function, variables declared within a block will go out of scope when the block terminates. These structures can also be nested within one another.

It was assumed in the previous section on enums and enum classes that you are familiar with the basics of `if` conditions, but here you can read through a more comprehensive review of conditional and iterative constructs that will be utilized heavily from here on out. Both depend on logical operators determining a true or false condition, so before launching into our tour of control structures, a quick review of logical operators and Boolean types are in order.

The C++ boolean type, represented represented by `bool`, can store a value of either `true` or `false`. Behind the scenes, a `bool` type has a size of one byte and may store only `1` for `true`, or `0` for `false`. Note that `true` and `false` are not placed in quotations, as ;ole enums they are not character types. They represent fixed integer values.

*/

#include<iostream>
#include<vector>

//ERRORS----------
// enum Gender
// {
//     Male,
//     Female
// };
// enum Angels
// {
//     Male,
//     Female
// };
//Enum Class
enum class Gender
{
    Male,Female
};
enum class Angels
{
    Male,Female
};

int main()
{
    Angels WhiteAngel{Angels::Male};
    Gender Boy{Gender::Male};

    if(0)
    {
        std::cout<<"Gender...\n";
    }else
    {
        std::cout<<"Gender...Nope...\n";
    };

/*
Control Structures
Control structures consist of two categories:

Conditional branching, such as `if` statements

Iterative controls that repeat a set of commands in a loop

In C++, the code that pertains to a given condition or sequence is contained in a block defined by braces. Similar to a function, variables declared within a block will go out of scope when the block terminates. These structures can also be nested within one another.

It was assumed in the previous section on enums and enum classes that you are familiar with the basics of `if` conditions, but here you can read through a more comprehensive review of conditional and iterative constructs that will be utilized heavily from here on out. Both depend on logical operators determining a true or false condition, so before launching into our tour of control structures, a quick review of logical operators and Boolean types are in order.

The C++ boolean type, represented represented by `bool`, can store a value of either `true` or `false`. Behind the scenes, a `bool` type has a size of one byte and may store only `1` for `true`, or `0` for `false`. Note that `true` and `false` are not placed in quotations, as ;ole enums they are not character types. They represent fixed integer values.

The C++ operators for equality and inequalities will return a `bool` type based on whether the result is true or false. They are as follows:

`<, >` Strict inequality

`<=, >=` Inclusive inequality

`==` Equality

`!=` Not equals

And and Or operations are represented by `&&` and `||` respectively.

Examples will follow in the next section on conditional branching.

Conditional Branching
C++ supports both the usual `if` based logic found in most other languages, and `switch`/`case` statements that offer a cleaner alternative to multiple `else if` conditions in special cases.

`if` and Related Conditions
The usual conditional branching statements

`if (condition) then (action)`

`if (condition) then (action), else (default action)`

`if (condition 1) then (action 1),`

`else if (condition 2) then (action 2)`

`...`

`else if (condition n) then (action n)`

`else (default action)`

are represented by the following C++ syntax. Each condition, whether it be `if`, `else if`, or `else`, the code that gets executed for a `true` condition is contained within a separate body, indicated by open and closed braces.

// Simple if
if (condition)
{
  // action
}
// if/else
if (condition)
{
  // action
}
else
{
  // default action
}
// if/else if.../else
if (condition 1)
{
  // action 1
}
else if (condition 2)
{
  // action 2
}
// ...
else if (condition n)
{
  // action n
}
else
{
  // default action
}
TIP
In conditional statements containing `else if`, it is a best practice to include a default `else` block at the end. Without it, code may build without any complaints from the compiler and run just fine, but its execution could very easily result in unexpected behavior that can cause major headaches in larger and more realistic code bases.

Utilizing the inequality operators introduced above, we can then write some simple examples with all three variations on the `if` statement theme:

	int x = 1;
	int y = 2;
	int z = 3;
	
	// Simple if
	if (x > 0)
	{
		cout << x << " > 0" << endl;
	}
	// if/else
	if (x >= y)
	{
		cout << x << " >= " << y << endl;
	}
	else
	{
		cout << x << " is less than " << y << endl;
	}
	// if/else if.../else
	if (x == z)
	{
		cout << x << " == " << z << endl;
	}
	else if (x < z)
	{
		cout << x << " > " << z << endl;
	}
	else if (x > z)
	{
		cout << x << " < " << z << endl;
	}
	else
	{
		cout << "Default condition" << endl;
	}
WARNING
Due to the nature of floating point numerical representation and arithmetic, one should never test for exact equality between two `double` types, nor should floating point types be compared identically to zero. These cases will be covered later in a separate context.

The operators for logical AND and OR can also be used within conditional arguments. For example:

	#include <cmath>
	using std::abs;
	using std::exp;
	
	// Simple if
	if (x > 0 || y < 1)
	{
		cout << x << " > 0 OR " << y << " < 1 " << endl;
	}
	// if/else if.../else
	if (x > 0 && y < 1)
	{
		cout << x << " > 0 AND " << y << " < 1 " << endl;
	}
	else if (x <= 0 || y >= 1)
	{
		cout << x << " <= 0 OR " << y << " >= 1 " << endl;
	}
	else if (z <= 0 || (abs(x) > z && exp(y) < z))
	{
		cout << z << " <= 0 OR " << endl;
		cout << abs(x) << " > " << z << " AND " 
			      << exp(y) << " < " << z << endl;
	}
	else
	{
		cout << "Default condition" << endl;
	}
Note that in the last `else if` condition, we put the AND condition inside round brackets, as OR takes precedence over AND. [cppreference.com]

Finally, we can assign logical conditions to `bool` variables, and used within `if` conditions, as shown here:

	bool cond1 = (x > 0 && y < 1);
	bool cond2 = (z <= 0 || (abs(x) > z && abs(y) < z));
	if (cond1)
	{
		cout << x << " > 0 AND " << y << " < 1 " << endl;
	}
	else if (!cond1)
	{
		cout << x << " <= 0 OR " << y << " >= 1 " << endl;
	}
	else if (cond2)
	{
		cout << z << " <= 0 OR " << endl;
		cout << abs(x) << " > " << z << " AND "
			<< abs(y) << " < " << z << endl;
	}
	else
	{
		cout << "Default condition" << endl;
	}
Note that a boolean variable can be negated simply by preceding it with the `!` operator, as shown in the first `else if` condition above.

WARNING
A common trap is to mistakenly use `=` to test equality instead of `==`. The former is the assignment operator and will cause unexpected behavior in this case. Be sure to use `==` when testing for equality.

Ternary `if` Statement
There is also a convenient one-line shortcut for short and sweet `if-else` combinations. The syntax is as follows:

type `var = ` logical condition `? var_val_true`(if `true`) : `var_val_false`(if `false`);

In English, this means if _logical condition_ is `true`, assign the value `var` to `var_val_true`; otherwise, assign it to `var_val_false`.

A code example should make this clearer:

using std::sin;
using std::cos;
int j = 10;
int k = 20;
double theta = 3.14;
double result = j < k ? sin(theta) : cos(theta);
So, in this example, `result` would be assigned the value of sin(3.14), or approximately zero.

The `switch`/`case` Statement
Also known as just a `switch` statement, this control sequence allows us to eliminate some of the clutter that comes with multiple `else if` clauses, but for the particular case of branching on the state of a single integer type, or alternatively, either an enum that maps to an integer, or an enum class member.

For each possible `case`, the command that follows the matching state is executed. As with the `else` condition above, a `default` action should be provided at the end to catch cases that do not fall into any of the given categories, or handle the error if no other possibilities are admissible.

As a first example, consider a case where we pretend an integer condition represents a type of option, and in place of each `cout`, the action would be to call a corresponding pricing model. This will render our code more readable and maintainable than using multiple `else if` statements.

void switch_statement(int x)
{
	switch (x)
	{
	case 0:
		cout << "European Option: Use Black-Scholes" << endl;
		break;
	case 1:    
		cout << "American Option: Use a lattice model" << endl;
		break;
	case 2:
		cout << "Bermudan Option: Use Longstaff-Schwartz Monte Carlo" << endl;
		break;
	case 3:
		cout << "Asian Option: Calculate average of the spot time series" << endl;
		break;
	default:
		cout << "Option type unknown" << endl;
		break;
	}
}
After each case, the `break` statement instructs the program to exit the `switch` statement once the corresponding code for a particular state is executed. So if `x` is `1`, a lattice model would be called to price an American option, and then control would pass out of the body of the `switch` statement rather than checking if `x` is `2`.

There are also cases where one might want to drop down to the next step if the same action is desired for multiple states. For example, in (American) football, if a drive stalls, the offense punts the ball on fourth down and no points are scored. If the team scores, however, it might have kicked a field goal for three points, or scored a touchdown with three possible outcomes:

Miss the extra point(s) -- Result is six points

Kick the extra point -- Result is seven points

Score a two-point conversion -- Result is eight points

No matter how a team scores, it kicks the ball off to their opponent, so for cases 3, 6, 7, and 8, we just drop down through each case until we hit the kickoff. This quasi-Bayesian logic could then be implemented with the following code:

void switch_football(int x)
{
	switch (x)
	{
	case 0:		// Drive stalls
		cout << "Punt" << endl;
		break;
	case 3:		// Kick field goal
	case 6:		// Score touchdown; miss extra point(s)
	case 7:		// Kick extra point
	case 8:		// Score two-point conversion
		cout << "Kick off" << endl;
		break;
	default:
		cout << "Are you at a tennis match?" << endl;
		break;
	}
}
An obvious pre-C++11 alternative for the `switch` on option pricing `case`s would be to substitute in the corresponding enums for the integer codes, thus making the logic even easier to understand for human consumption (`cout` messages remain the same):

void switch_statement_enum(OptionType ot)
{
	switch (ot)
	{
	case European:		// = 0
		cout << "European Option: Use Black-Scholes" << endl;
		break;
	case American:		// = 1    
		. . .
	case Bermudan:		// = 2
		. . .
	case Asian:		// = 3
		. . .
	default:
		cout << "Option type unknown" << endl;
		break;
	}
}
However, modern ISO Guidelines now favor using enum classes, for the reasons demonstrated above with integer conflicts. So, we just substitute the `Options_Contract` enum class into the preceding example to get:

void switch_enum_class_member(Options_Contract oc)
{
	switch (oc)
	{
	case Options_Contract::European:
		cout << "European Option: Use Black-Scholes" << endl;
		break;
	case Options_Contract::American:    
		. . .
	case Options_Contract::Bermudan:
		. . .
	case Options_Contract::Asian:
		. . .
	default:
		cout << "Option type unknown" << endl;
		break;
	}
}
Iterative Statements
In C++, there are two built-in language features that enable looping logic and iteration:

`while` and `do...while` loops

`for` loops (including range-based `for` loops)

These iterative commands will execute a repeated block of code over a set of values or objects based on a fixed count, while a logical condition is true, or over a range of elements held by a `vector`.

`while` and `do...while` Loops
The essential workflow behind a `while` loop is to repeat a block of code while a logical expression is `true` (or alternatively, whilst `false`). The following simple example demonstrates a simple `while` loop, where the incremented value of an integer is output to the screen while its value remains strictly less than some fixed maximum value:

int i = 0;
int max = 10;
while (i < max)
{
	cout << i << ", ";
	++i;
}
Our logical condition is for `i` to be strictly less than the value `max`. As long as this condition holds, the value of `i` will be incremented

A `do...while` loop is similar, except that by placing the `while` condition at the end, it guarantees that at least one iteration of the loop will be executed. For example:

int i = 0;
int max = 10;
do 
{
	cout << i << ", ";
	++i;
} while (i < max);
Note that even if `max` had been set to zero or less, there would still be one trip through the `do...while` loop, as the maximum condition is not checked until the end. This is the distinction that separates it from the simpler `while` loop.

In time, we will see looping examples that involve more interesting mathematics and financial applications.

The `for` Loop
This construct is another form of iteration over a countable range. The form that is employed in C++ can be summarized in the following pseudocode example:

for(initial expression executed only once;
exit condition executed at the beginning of every loop;
loop expression executed at the end of every loop)
{
DoSomeStuff;
}
The syntax here is important, namely the semicolons separating the three expressions in the `for` argument. Breaking this down into parts a, b, and c, we would have

for(a; b; c) 
Each of these parts is typically dependent on some form of a counter, such as an `int i` counter as seen in the `while` statement; however, we now move this index into the argument of the `for` statement, which allows us to remove the increment from the body of the loop. The (a) part determines the starting value of the counter, (b) indicates where to stop, and (c) enforces how the counter is increased or decreased.

For example, we could rewrite the `while` example above using a `for` loop as follows:

int max = 10;
for(int i = 0; i < max; ++i)
{
	cout << i << ", ";		// we no longer need ++i in the body
}   
The results will be exactly the same as the those in the `while` loop examples.

There technically is a difference between the pre- and post- increment operator that can affect other uses, but either `++i` with `i++` in the `for` will work identically. It is generally preferred to use `++i`

It is also legal to have a `for` loop where a decrement (`--`) is used to decrease the index value down to some minimum value.

`break` and `continue`
In iterative loops, it is sometimes necessary to break out of a loop before a maximum or minimum index value is attained, or before the specified logical condition would otherwise terminate the iteration. A prime example in computational finance is barrier option pricing using Monte Carlo simulation. The simulation paths will typically have the same number of time steps; however, in the case of an up-and-out barrier option, for example, we would need to break out of the loop if the underlying asset price rose above the barrier level.

This is accomplished by applying the same `break` command as used in `switch` statements. A simple example is shown here, which also demonstrates nesting an `if` condition inside a `for` block:

int max = 10;
for (int i = 0; i < 100; ++i)
{
	cout << i << ", ";
	if (i > max)
	{
	    cout << "Passed i = " << max << "; I'm tired, so let's go home." 
	        << endl;
	    break;
	}
}
Once `i` is incremented to 11, the `if` statement is true, so the `break` command is called, causing the program control to exit the `for` loop.

There is also the `continue` keyword that can be used to continue the process of the loop, but since this is the default behavior of a loop anyway, its usefulness is limited.

Nested Loops
In addition to nesting `if` conditions inside loops, it is also possible to nest iterative blocks inside other blocks, whether they be `for` or `while` loop. In quantitative programming, it is easy to find oneself writing double and sometimes even triple nested loops when implementing common numerical routines and financial models. This type of coding, however, can become complex and error prone in a hurry, so one needs to take special precautions, as well as consider alternatives we will take up later.

Range-Based `for` Loops
Prior to C++11, iterating through a `vector` would involve using the index as the counter, up to the number its elements.

vector<double> v;
// Populate the vector v and then use below:
for(unsigned i = 0; i < v.size(); ++i)
{
	// Do something with v[i] or v.at(i). . .
}
Range-based `for` loops, introduced in C++11, make this more functional and elegant. Instead of explicitly using the `vector` index, a range-based for loop simply says “for every element `elem` in `v`, do something with it”:

for(auto elem : v)
{
	// Use elem, rather than v[i] or v.at(i)
}
As a trivial example, calculate the sum of the elements:

double sum = 0.0;
for(auto elem : v)
{
	sum += elem;
}
And we are done. No worries about making a mistake with the index, there is less to type, and the code more obviously expresses what it is doing. The ISO Guidelines in fact tell us to prefer using range-based `for` loops with `vector` objects, as well as other STL containers that will be discussed in Chapter 7.

Aliases
Aliasing can take on several forms, the first being one of convenience, namely type aliasing, where commonly used parameterized type names can be assigned to a shorter and more descriptive alias names.

In addition, reference aliases help to avoid copies of objects being created when they are passed into functions, often resulting in significant speedup at runtime.

Pointers can also be considered as aliases, particularly useful for representing an active object in class design (the `this` pointer in Chapter 4). Pointers (and now smart pointers) can also be used for allocating memory that persists, but this is a separate and deeper discussion that will be deferred until Chapter 6.

Both references and pointers can help facilitate the object-oriented programming concepts of inheritance and composition that will be presented in subsequent chapters.

`std::vector<double>` objects are ubiquitous in quantitative code for fairly obvious reasons. Because it is used so much, it is common to assign a type alias to it, such as `RealVector`. This better expresses what it is mathematically, plus we don’t need to bother with as much typing.

Using modern C++, we can define the alias `RealVector` by simply defining it as follows:
*/
using RealVector=std::vector<double>;
RealVector v={3.12,23.53,6.4,343.4};
v.push_back(5.4);
v.push_back(67.4);

//Redefination is not Allowed
// using RealVector=std::vector<std::string>;
// RealVector Names{};

/*
As long as the alias is defined before it is used in the code, then it’s fair game.

Prior to C++11, this application of the `using` command did not exist, so type aliasing was accomplished by using the `typedef` command; eg,

typedef vector<double> RealVector;
This is also valid C++ and is still found in many modern code bases, but the `using` form is preferable per the modern ISO Guidelines. The detailed reason for this is outside the scope of this book, but the upshot is `using` can be used to define aliases of generic templated types (eg, not just `double` parameters as above), while `typedef` cannot.

References
A reference, put simply, provides an alias for a variable, rather than a type. Once a reference is defined, then accessing or modifying it is exactly the same as using the original variable. A reference is created by placing an ampersand between the type name and the reference name before assigning it to the original variable. For example:

int original = 15;
int& ref = original;	// int& means "reference to an int"
At this point, both `original` and `ref` would return 15 if accessed in a function or assigned to another variable. However, reassigning `original` to 12 would also mean `ref` now returns 12. Similarly, reassigning `ref` would change the value held by `original`:

original = 12;			// ref now = 12	
ref = 4;				// original also now = 4
It is important to note that a reference must be assigned at the same time it is declared. For example,

int& ozone;
would be nonsense as there is nothing to which it refers, and the code would fail to compile. Also, once a reference is defined, it cannot be reassigned to another variable for the remainder of its lifetime.

Using a reference for a plain old numerical type is trivial, but they become important when passing large objects into a function, so as to avoid object copy that can decimate a program’s runtime performance.

Suppose we have a `std::vector` containing 2000 option contract objects? By passing it as a reference into a function, the original object itself can be accessed without copying it.

There is one caveat, however. Remember that if a reference is modified, so is the original variable to which it refers. For this reason, one can just make the reference argument `const`. Then, any attempt to modify the reference will be prevented by the compiler.

For example, here are two functions that take in a `std::vector<int>` object as a reference argument. The first one returns the sum of the elements, so there is no modification of the elements attempted. The second one, however, attempts to reset each element to twice its value and then sum the elements. This will result in a compiler error – much better than a runtime error – and prevent the operations from ever being executed:

// This is OK
using IntVector = std::vector<int>;
int sum_ints(const IntVector& v)
{
	int sum = 0;
	for (auto elem : v)
	{
		sum += elem;
	}
	
	return sum;
}
int sum_of_twice_the_ints(const IntVector& v)
{
	// Will not compile!  const prevents modification
	// of the elements in the vector v.
	
	int sum = 0;
	for (auto elem : v)
	{
		elem = 2 * elem;
		sum += elem;
	}
	
	return sum;
}
NOTE
It is also possible to pass a function argument as non-`const` reference, with the intent to modify it in place. In this case, one would typically make the return type `void`, instead of returning a modified variable. This is rarely justified anymore in modern C++ due to return value optimization (RVO). With RVO, objects by default are returned “in place” rather than as copies from functions. This is now a requirement for compilers per the ISO standards, beginning with C++11.

Pointers
A pointer in C++ shares some similarities with a reference, in that it can also be an alias to another variable, but rather than being permanently tied to a variable throughout its lifetime, a pointer points to a memory address containing the variable’s contents, and it can be redirected to another memory address containing another variable.

This unfortunately can be confusing, as a memory address of a variable is also indicated by the `&` operator, in addition to another operator `*` that is used to declare a pointer. A simple example illustrates this. First, declare and assign an integer variable:

int x = 42;
Next, declare a pointer to an integer, using the `*` operator:

int* xp;
This says to create a variable that will be a pointer to an `int` type, but don’t point to anything specific yet; this comes in the next step:

xp = &x;    

The `&` operator in this case means the address of `x`. `xp` now points at the memory address that contains the contents of `x`, namely 42. Note that this usage of `&` has a different meaning than declaring a reference.

We can now access the contents of this memory address by dereferencing `xp` by applying the `*` operator. If we put

std::cout << *xp << std::endl;
the output would be 42, just as if we had applied `std::cout` to the variable `x`. Note the `*` operator is used in a different context here, accessing the contents of memory rather than declaring a pointer.

We can also means we can change the value of `x`. For example, putting

*xp = 25;
then both `*xp` and `x` will return the value 25, rather than 42.

It is also possible to reassign the pointer `xp` to a different memory address; this is not possible to do with a reference. Suppose we have a different integer variable `y` and we reassign `xp` to point to the address of `y`:

int y = 106;
xp = &y;
Now, `*xp` will return 106 rather than 25, but `x` is still equal to 25.


Similar to references, pointers can be used with objects. If we have a class `SomeClass` with a member function, say `some_fcn`, then we can define a pointer to a `SomeClass` object:

SomeClass sc;
auto SomeClass* ptr_sc = &sc;
As it’s obvious that `ptr_sc` will point to a `SomeClass` object, we can use the `auto` keyword without obscuring its context.

Suppose also that `SomeClass` has a member function `some_fcn`. This function can be invoked by dereferencing `ptr_sc` and then calling it in the usual way:

(*ptr_sc).some_fcn();
More common, however, is to use the indirection operator, indicated by an arrow:

ptr_sc->some_fcn();
This is all we will need to know about pointers for now. More specifically, these examples take place in stack memory, and they are automatically deleted when the function or control block in which they are defined terminates. More advanced usage will be presented later.


Function and Operator Overloading
A key feature of C++, as well as other modern programming languages, is implementing different versions of the same function name, distinguished by different sets of input arguments. This is known as function overloading. A related feature that is very convenient to us as quantitative programmers is operator overloading, where we can define an operation for specific types, such as vector multiplication. Operator overloading is not supported in as many languages as function overloading; for example, it exists in C++ and C#, but it is not an option in Java.

Function Overloading
To illustrate function overloading, let’s look at an example of two versions of a `sum` function, one of which returns a `double` type, while the other returns a `vector<double>`. The first version is trivial, just summing two real numbers.

#include <vector> 
// . . .
double sum(double x, double y)
{
	return x + y;
}
The second version, however, will take in two `std::vector<double>` objects and return a vector containing the sum of its elements.

std::vector<double> sum(const std::vector<double>& x, const std::vector<double>& y)
{
	// NOTE TO SELF: Can we do this with range-based for loops(?!)
	std::vector<double> vec_sum;
	if(x.size() == y.size())
	{
		for (int i = 0; i < x.size(); ++i)
		{
			vec_sum.push_back(x.at(i) + y.at(i));
		}	
	}
	return vec_sum;		// Empty if size of x and y do not match
}
As we can see, the two functions perform two distinct tasks, and have different return types, based on the types of arguments.

Overloaded functions can also be distinguished based on the number of arguments of the same type, as well as return the same type. For example (trivially), we could define a `sum` function that takes in three real numbers:

double sum(double x, double y, double z)
{
	return x + y + z;
}
Now, if we put in our `main()` function the following,

sum(5.31, 92.26);
sum(4.19, 41.9, 419.0);
the respective overloaded functions will be called.



Operator Overloading
C++ provides the standard mathematical operators for integer and floating type numerical values. The Standard Library also provides the `+` operator for `std::string` types, which will concatenate them. However, there are no operators provided for `std::vector`, for example. So, if we want to compute an element-by-element sum of two vectors, or calculate a dot product, we’re on our own.

We could just use the `sum` overload for two vectors as shown above for vector addition, and write a new function called `dot_product` for vector multiplication. However, C++ provides us with a more naturally mathematical approach, namely operator overloading.

For a vector sum, the addition operator replaces the `sum` overload as shown below. The body of the function remains the same:

std::vector<double> operator + (const std::vector<double>& x, const std::vector<double>& y)
{
	std::vector<double> add_vec;
	if (x.size() == y.size())
	{
		for (unsigned i = 0; i < x.size(); ++i)
		{
			add_vec.push_back(x.at(i) + y.at(i));
		}
	}
	return add_vec;		// Empty vector if x & y sizes not identical
}
Similarly, for the dot product, which returns a scalar (`double`), overload the `*` operator:

double operator * (const std::vector<double>& x, const std::vector<double>& y)
{
	double dot_prod = 0.0;
	if (x.size() == y.size())
	{
		for (int i = 0; i < x.size(); ++i)
		{
			dot_prod += (x[i] * y[i]);
		}
	}
	return dot_prod;	// Return 0.0 if size of x and y do not match		
}
Then, for two vectors `x` and `y`, say

std::vector<double> x = {1.1, 2.2, 3.3};
std::vector<double> y = {0.1, 0.2, 0.3};
the overloaded operators would perform vector addition and multiplication:

auto v_sum = x + y;		// ans: {1.2, 2.4, 3.6}
auto v_dot = x * y;		// ans: 1.54
For `double` types, the compiler knows to apply the language-provided operators

double s = 1.1 + 0.1;	// s = 1.2
double p = 2.2 * 0.2;	// p = 0.44


As for other examples, if we were to write a `Matrix` class, we would also want to overload operators `+`, `-`, and `*`. For a `Date` class, we could define `-` to return the number of days between two dates. Operator overloading is thus very convenient for mathematical and financial programming. 



References
[1] CppReference: `https://en.cppreference.com/w/cpp/language/operator_precedence]`


*/


};
