// Introduction to Cling and C++ (This is a one-line comment)

// In compiled C++ code it is possible to specify a multi-line 
// (or "block") comment by enclosing it between "/*" and "*/". 
// Unfortunately, Cling cannot parse multi-line comments.

// SIMPLE TERMINAL OUTPUT
// ======================
// Compiled C++ has no built-in INPUT or OUTPUT. Even writing to the 
// terminal requires a HEADER FILE to be INCLUDED. For now we will
// simply give the syntax and defer an explanation until a later 
// lecture.
// Header files are included using the #include directive
#include <iostream> // the "iostream" header file enables terminal I/O

// Now we can write output to the terminal like this:
std::cout << "Number of iterations was: " << numIterations << std::endl;

// This line uses the STREAM OUTPUT OPERATOR "<<" and the NAMESPACE
// RESOLUTION OPERATOR "::". Don't worry about them for now!

// NOTE: Literals and variables with DIFFERENT BUILT-IN TYPES can be
// written by the same statement. 

// VARIABLE TYPES
// ==============
// C++ is a STRONGLY TYPED language. All variable declarations
// must include a type specification

// Numeric data types
// ==================
// The C++ language grammar specifies several numeric data types:
 
//  * Integer types:
// short, int, long (int), long long (int)
 
//  * Unsigned (positive only) integer types:
// unsigned short, unsigned int, unsigned long (int), 
// unsigned long long int
 
//  * Real (floating point) types:
// float, double, long double, long long double
 
// The different types in each category use different numbers of 
// bytes to store their associated values. To discover the number 
// of bytes that TYPE requires, use the sizeof(TYPE) OPERATOR. 

// The following STATEMENT DECLARES a long integer with IDENTIFIER
// sizeOfInt. The ';' character is used to mark the end of the 
// statement.

long int sizeOfInt;

// A basic C++ declaration statement comprises a TYPE SPECIFICATION 
// (in this case, "long int"), an IDENTIFIER 

// Now, let's assign a value to the sizeOfInt variable. This is
// done using the ASSIGNMENT OPERATOR "="
// NOTE: C++ is case-sensitive so e.g. sizeOfInt is NOT the same as
// sizeofint.
// NOTE: This time, try omitting the semicolon, which will cause Cling
// to print the result of the statement. In this case it will print
// the type and value of sizeOfInt.
// NOTE: Skipping the semicolon is NOT valid C++. We are making use
// of Cling's functionality here because I/O in C++ is a bit tricky for 
// the moment.

sizeOfInt = sizeof(int);

// sizeOfInt is a mutable variable, so we can legally assign another 
// value to it. This time we'll use a LITERAL integer token. 

sizeOfInt = 2;

// We could have combined the declaration and definition into a
// single statement.

long int sizeOfDouble = sizeof(double);

// Now try entering the following PARTIAL statement

sizeof(long double);

// If you skip the semicolon, Cling should print: (unsigned long) 8
 
// This is telling us that the result of the sizeof() function
// is really an "unsigned long int". C++ has automatically 
// converted it to a "long int" on our behalf. 
// NOTE: In this case that's okay, but it might cause problems
// in some cases (We'll discuss the hazzards of unsigned integers
// in a later lecture). 

// What happens if we try to assign a real number value to sizeOfInt?

sizeOfInt = 4.8;

// Cling outputs:
// input_line_11:2:14: warning: implicit conversion from 'double' to 
// 'long' changes
//       value from 4.8 to 4 [-Wliteral-conversion]
//  sizeOfInt = 4.8
//            ~ ^~~
//
// Cling has TRUNCATED (not rounded) the value 4.2 to retain only
// the integer part, so now sizeOfInt is equal to 4. This is 
// PROBABLY not what we want, so by default Cling issues a warning.

// PERMITTED IDENTIFIERS
// =====================
//
// Now that we've experimented with a few simple statements, we'll
// investigate set of identifiers that are permitted by C++.

// Next, enter:

int yetAnotherInt!;

// Cling outputs: 
//
// input_line_5:2:19: error: expected ';' at end of declaration
//  int yetAnotherInt!
//                   ^
//                   ;
//
// ** RULE 1: IDENTIFIERS in C++ may only include alphanumeric 
//    characters and underscores "_".
//
// In this case, Cling interprets the "!" as a logical negation
// OPERATOR, which is invalid C++ in this context. 

// Now try:

int 5plus5; 

// Cling outputs: 
//
// input_line_4:2:6: error: expected unqualified-id
//  int 5plus5
//      ^
//
// The error states that Cling expects to find an IDENTIFIER after 
// the "int" token. 
//
// ** RULE 2: IDENTIFIERS in C++ may NOT BEGIN with numeric charaters.
// 
// Instead, Cling interprets the "5" character as a 
// separate LITERAL token, which is invalid C++ in this context. 

// Imagine we wanted to declare an unsigned integer to store the number 
// of dollars in a cash register. We might be tempted to call that 
// variable "float".

unsigned int float;

// Cling outputs: 
//
// input_line_10:2:15: error: cannot combine with previous 'int' declaration
//     specifier
//  unsigned int float;
//             ^
// input_line_10:2:2: warning: declaration does not declare anything
//     [-Wmissing-declarations]
//  unsigned int float;
//  ^~~~~~~~~~~~~~~~~~
//
// What went wrong? 
//
// ** RULE 3: Names of built-in types are RESERVED WORDS in C++ and cannot be
//    interpreted as IDENTIFIERS. 
//
// Instead, Cling interprets the the "float" token as a type specification,
// which makes no sense in this context.

// Finally, what happens if we try to re-declare an identifier?

double sizeOfInt;

// Cling outputs:
//
// input_line_13:2:9: error: redefinition of 'sizeOfInt' with a different type:
//       'double' vs 'long'
//  double sizeOfInt;
//         ^
// input_line_12:2:6: note: previous definition is here
//  long int sizeOfInt;
//           ^
//
// ** RULE 4: All identifiers declared within the same SCOPE
//    must be UNIQUE (More on scopes in C++ in lecture 3)
//
// Even if we had tried to redeclare sizeOfInt to have the SAME
// TYPE

long int sizeOfInt; 

// Cling outputs:
//
// input_line_6:2:11: error: redefinition of 'sizeOfInt'
//  long int sizeOfInt;
//           ^
// input_line_4:2:11: note: previous definition is here
//  long int sizeOfInt;
//           ^

// MUTABILITY
// ==========
//
// In C++, the "const" keyword is used to specify that a variable
// is immutable and (once initialized) cannot be modified. 
//
// NOTE: Immutable variables MUST be initialized when they are 
// declared.
// 
// The following statement declares an immutable integer.

const int theAnswer = 42;

// Now try modifying the value of "theAnswer"

theAnswer = 12;

// Cling will not allow us to do so, and outputs:
//
// input_line_9:2:12: error: read-only variable is not assignable
//  theAnswer = 12;
//  ~~~~~~~~~ ^

// OPERATORS
// =========
//
// C++ several different categories of operator INCLUDING: 
// ASSIGNMENT (e.g. "=", "+=", "-=") 
// ARITHMETIC (e.g. "+", "-", "*")
// RELATIONAL (e.g. "==", "!=", "<")
// LOGICAL ("&&", "||", "!")
// INCREMENT ("++", "--")
//
// The programatic entities that operators act on are called
// ARGUMENTS. ARGUMENTS can be VARIABLES, LITERALS or STATEMENTS
// that return values.
//
// Operators that act on a single argument are called UNARY
// operators.
//
// Operators that act on two arguments are called BINARY operators.
//
// C++ also defines a TERNARY operator, which acts on three 
// arguments. 
//
// For more details about operators, see the READING ASSIGNMENT for
// Lecture 2.
//

// ARITHMETIC OPERATORS
// ====================
//
// Now let's try a few arithmetic operations. The following statements
// declare and initialize an integer VARIABLE before ADDING a LITERAL
// value and ASSIGNING the result to another integer.

int three = 3;
int seven = three + 4;

// The assignment operator "=" and the addition operator "+" are both
// BINARY OPERATORS.

// It is possible to assign the result to the VARIABLE argument.

int five = 2; // Incorrect!
five = five + 3; // That's better.

// LITERALS are immutable so cannot be ASSIGNED the result of an 
// operation. Try:

5 = five + 0;

// Cling prints:
// input_line_12:2:4: error: expression is not assignable
//  5 = five + 0;
//  ~ ^

// Here's a more complicated example that introduces the multiplication
// "*", and subtraction operators. What does it compute?

float startPos = 150;
float startSpeed = 0;
float acceleration = -9.8;
float time = 5;

float mysteryValue = startPos + startSpeed * time + 0.5 * acceleration * time * time; 

// NOTE: Multiple operations can be combined into a single statement.
// NOTE: The multiplication operations are performed BEFORE the additions
// The multiplication operator is said to have HIGHER PRECEDENCE.
// For more information about operator precedence, see the READING ASSIGNMENT
// for Lecture 2.

// THE BOOLEAN TYPE
// ================
//
// Before introducing LOGICAL operators we need to introduce the BOOLEAN
// type. In C++, boolean values are represented by a special type "bool".
// Boolean variables may have one of two values: "true" or "false".
// NOTE: In C++, non-zero integer values are automatically converted
//       to "true" if assigned to a boolean variable. Zero-valued integers
//       are converted to false.
//
// The following statements declare two boolean variables.

bool vrai;
bool faux;

// The value of a boolean variable can be assigned using a boolean
// LITERAL e.g.

vrai = true;
faux = false;

// or using an integer value

vrai = -5; // the value of vrai is now "true"
faux = 0; // the value of faux is now "false"

// RELATIONAL/COMPARATIVE OPERATIONS
// =================================
//
// Relational and comparative operators are BINARY operators that
// compare two values and return "true" or "false" depending upon
// the result of the comparison.
//

// The EQUALITY operator ("==") returns "true" if both arguments compare 
// equal and "false" otherwise.

int first = 5;
int second = 6;

bool equalAtFirst = (first == second); // false
// NOTE: parentheses can be used to wrap subexpressions.

first = first + 1;

bool equalNow = (first == second); // true

// Other relational operators test whether the left hand argument is
// GREATER THAN (">"), LESS THAN ("<"), GREATER THAN OR EQUAL TO (">=")
// or LESS THAN OR EQUAL TO ("<=").

float large = 2e16; // This is how to write 2x10^16 as a literal float.
float small = 2.16;

bool commonSense = (large > small); // true
bool tardisSense = (small > large); // false (sadly)

bool fallacy = (large > large); // false
fallacy = (large < large);
fallacy = (small > small);
fallacy = (small < small);

fallacy = (small >= large);
fallacy = (large <= small);

bool truism = (large >= large); // true
truism = (small <= small);

// C++ defines the LOGICAL AND operator "&&", the LOGICAL OR
// operator "||" and the LOGICAL NOT operator "!"
//
// LOGICAL EXPRESSIONS involve logical operators and return 
// boolean values.

bool rosesAreRed = true;
bool violetsAreBlue = false;
bool violetsAreViolet = true;

// Both arguments of the "&&" (AND) operator must be true for 
// the result to be true
bool poetry = rosesAreRed && violetsAreBlue; // false
bool reality = rosesAreRed && violetsAreViolet; // true

// At least one argument of the "||" (OR) operator must be true for 
// the result to be true.
bool fight = false; // I don't like guns!
bool flight = true; // I do like runs!

bool reflex = fight || flight; // true

// Prepending a boolean value with the "!" (NOT) operator inverts
// the truth-value
bool matter = true;
bool antimatter = !matter;

bool proton = true;
bool electron = true;
bool antiProton = !proton; // false
bool antiElectron = !electron; // false

bool particle = electron || proton; // true
// LOGICAL operators can also be applied to parenthesized 
// sub-expressions
bool antiParticle = !(electron || proton); // true

bool hydrogen = electron && proton;
bool antiHydrogen = !electron && !proton; // QUESTION: Why is this...
bool notHydrogen = !(electron && proton); // ... different from this?

// FLOW CONTROL STATEMENTS
// =======================
// We have now seen many of the basic components that are used to build
// expressions in C++. We can compute numerical values and perform 
// boolean operations.

// Flow control statements utilise the results of boolean expressions
// to "decide" when a computation should be performed. The most fundamental
// type of flow control statements in in C++ are IF-THEN-ELSE statements.

// IF-THEN-ELSE STATEMENTS
// =======================
// The following example demonstrates the basic syntax of such statements.

bool lotionOnSkin; // defaults to false
bool hoseAgain;

// if clause: If the parenthesised expression is true, then the code
// between the subsequent pair of braces will be executed.
if(lotionOnSkin){ 
  hoseAgain = false;
 }
// else clause: This is executed if the parenthesized expression attached
// to the if clause is false.
 else{
   hoseAgain = true;
 }

// If there are more than two possible states, MULTIPLE else if() clauses
// can be added before the else statement 

bool agentStarling = true; // Hello, Clarice...

if(lotionOnSkin){
  hoseAgain = false;
 }
// The else if clause will only be considered if lotionOnSkin is false
 else if(agentStarling){ // to the rescue
   hoseAgain = false;
 }
// The else clause will only be considered if agentStarling is also false.
 else{
   hoseAgain = true;
 }

// LOOP STATEMENTS
// ===============
// If a set of statements or expressions must be executed repeatedly
// then this can be achieved using LOOP STATEMENTS.
// C++ defines three basic types of loop: FOR LOOPS, WHILE LOOPS and
// DO-WHILE loops

// FOR LOOPS:
// ==========
// A for loop will execute a block of code a FIXED number of times.
// The basic syntax of a for loop is illustrated by the following 
// example

double sum = 0.0; // initialize sum

for(int index = 0; // initialization of loop counter
    index < 10; // loop CONTINUATION condition
    ++index // post-iteration action (pre-increment operator)
){
  // this statement will be executed 10 times
  sum += index*5.0;
 }

// now sum == 225

// WHILE LOOPS
// ===========
// A while loop will execute a block of code (called the LOOP BODY)
// UNTIL a specified boolean expression evaluates to false.
// It evaluates that boolean expression BEFORE the loop body is executed.

// The basic syntax of a while loop is illustrated by the following
// example.

int numIterations = 0; // count the number of iterations
sum = 0.0; // reset sum

while(sum < 225.0){ // parenthesized continuation expression 
  sum += (numIterations++)*5.0; // post-increment operator
 }

// now numIterations == 10
// QUESTION: What if the pre-increment operator had been used?

// DO-WHILE LOOPS
// ==============
// A do-while loop is similar to a while loop except that the 
// continuation expression is evaluated AFTER the code in 
// the loop body has executed. This means that the loop body is
// GUARANTEED to be executed AT LEAST ONCE.

// The basic syntax of a do-while loop is illustrated by the following
// example.

numIterations = 0; // reset the count of iterations
sum = 0.0; // reset the sum (again!)

do{
  sum += numIterations*5.0;
  numIterations++;
 }while(numIterations <= 10); // NOTE: A semicolon is required to terminate
                              // a do while loop.
// now numIterations == 11 (even though the continuation expression
// specifies numIterations <= 0)

// SCOPE
// =====
// In C++ a SCOPE is a section of your code within which any variable
// identifiers have a particular interpretation.
// Examples of scopes in C++ include loop bodies and initializers, 
// generic code blocks (regions between pairs of "{" and "}" tokens) and
// FUNCTION BODIES (see Lecture 3), and the GLOBAL scope.

// The following code includes examples of various scope variants

// Identifiers declared outside any code blocks are said to be 
// defined a GLOBAL SCOPE. They have the same meaning at all points
// in the code UNLESS an identifier with the SAME NAME AND TYPE is 
// declared within a more specific scope.
float globalFloat = 2.0;

// Opening a code block using a "{" character defines the start of
// a new scope
{
  // Identifiers declared at global scope retain their interpretation
  // until they are redefined.
  std::cout << "Before redeclaration: " << globalFloat << std::endl;

  // The following apparent re-definition of globalFloat is legal C++
  // but the globalFloat identifier now refers to a different variable.
  float globalFloat = 3.0;
  
  std::cout << "After redeclaration: " << globalFloat << std::endl;

  // the closing brace closes the current scope
}
// What is the value of globalFloat now?
std::cout << "After scope exit: " << globalFloat << std::endl;

// EXCERCISE: Instead of redeclaring globalFloat, just assign a new value.
// Now what is the value after scope exit?

// The body of a for loop is also a code block with its own scope.
// In this case variables that are declared in the loop initializer
// ONLY have meaning in the initializer AND the loop body.

for(int index = 0; // index is declared in the loop initializer...
    index < 10; // ... it can be referenced therein...
    ++index){
  // index also has meaning in the scope of the loop body...
  std::cout << index << " " << (index*5.0) << std::endl;
 }

// ... but the following statement is an error - index has no meaning
// at global scope.
std::cout << index << std::endl;

// If you need to know the value that index reached while the loop was
// executing you must declare index in the ENCLOSING SCOPE, which is the 
// global scope IN THIS CASE.

int index;

for(index = 0; // index should not be re-declared, we want to 
               // reference the global identifier...
    index < 10;
    ++index){
  // index now refers to the variable declared at global scope
  std::cout << index << " " << (index*5.0) << std::endl;
 }

// What is the value of index now?
std::cout << index << std::endl;


