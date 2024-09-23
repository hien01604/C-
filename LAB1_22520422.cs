using Microsoft.VisualBasic;
using System;
using System.ComponentModel;
using System.Drawing;
using System.Dynamic;
using System.Numerics;
using System.Runtime.InteropServices;
using System.Runtime.Intrinsics.X86;
using System.Security.Principal;
using static System.Runtime.InteropServices.JavaScript.JSType;
using System.Threading.Channels;

namespace Class1
{
    class Program
    {
        static void Main()
        {
            int choice;
            do
            {
                Console.Write("Choose 0-20: ");

                choice = int.Parse(Console.ReadLine());

                switch (choice)
                {
                    case 0:
                        Console.WriteLine("Exit");
                        break;
                    case 1:
                        Console.WriteLine("1. Convert 1 lowercase letter to uppercase");
                        Problem_1();
                        break;
                    case 2:
                        Console.WriteLine("2. Check whether all the three points fall on one straight line.");
                        Problem_2();
                        break;
                    case 3:
                        Console.WriteLine("3. Determine whether a point lies inside the\r\ncircle, on the circle or outside the circle.");
                        Problem_3();
                        break;
                    case 4:
                        Console.WriteLine("4. Determineswhether the character entered is a capital letter, " +
                            "a small case letter, a digit or a special symbol.");
                        Problem_4();
                        break;
                    case 5:
                        Console.WriteLine("5. Performs a conversion depending on the type of conversion. ");
                        Problem_5();
                        break;
                    case 6:
                        Console.WriteLine("6. Find the efficiency of the worker.");
                        Problem_6();
                        break;
                    case 7:
                        Console.WriteLine("7. Determine whether a year\r\nentered through the keyboard is a leap year or not.");
                        Problem_7();
                        break;
                    case 8:
                        Console.WriteLine("8. Checks whether the entered value is an arithmetic operator, logical\r\noperator, conditional operator, relational operator or something else.");
                        Problem_8();
                        break;
                    case 9:
                        Console.WriteLine("9. rints an identity matrix");
                        Problem_9();
                        break;
                    case 10:
                        Console.WriteLine("10. Prints the following series.\r\n1 2 4 8 16 21 64 128 ...nth iteration.");
                        Problem_10();
                        break;
                    case 11:
                        Console.WriteLine("11. Prints the following output (you\r\nneed to find a pattern to print letters in this order): A B D H P");
                        Problem_11();
                        break;
                    case 12:
                        Console.WriteLine("12. Prints the following output.\r\n1 2 2 3 3 3 4 4 4 4 5 5 5 5 5 6 6 6 6 6 6 . . . nth iteration.");
                        Problem_12();
                        break;
                    case 13:
                        Console.WriteLine("13. Print all the ASCII values and their equivalent\r\ncharacters ");
                        Problem_13();
                        break;
                    case 14:
                        Console.WriteLine("14. Print all the ASCII values and their equivalent\r\ncharacters ");
                        Problem_14();
                        break;
                    case 15:
                        Console.WriteLine("15. Draw Pascal's triangle.");
                        Problem_15();
                        break;
                    case 16:
                        Console.WriteLine("16. Calculate the surface area and volume of a sphere");
                        Problem_16();
                        break;
                    case 17:
                        Console.WriteLine("17. Calculate the value of the function y = x^2 + 4x -3.5");
                        Problem_17();
                        break;
                    case 18:
                        Console.WriteLine("18. Covert decimal to binary.");
                        Problem_18();
                        break;
                    case 19:
                        Console.WriteLine("19. Find the smallest number among three numbers");
                        Problem_19();
                        break;
                    case 20:
                        Console.WriteLine("20. A menu that allows the user to choose to calculate\r\nthe area and perimeter of one of three shapes: triangle, rectangle, or circle.");
                        Problem_20();
                        break;
                    default:
                        Console.WriteLine("Choose again.");
                        break;
                }

            } while (choice >= 1 && choice <= 20);
        }

        //Problem 1: Write a program that converts 1 lower case letter ("a" - "z") to its
        //corresponding upper-case letter("A" - "Z"). For example, if the user enters "c" then the
        //program will show "C" on the screen.
        static void Problem_1()
        {
            Console.Write("Enter a lowercase letter: ");
            char lowerCaseLetter = Console.ReadLine()[0];

            // Convert lowercase to uppercase using Char.ToUpper()
            char upperCaseLetter = (char)(lowerCaseLetter - 32);

            Console.WriteLine("Uppercase letter: " + upperCaseLetter);
        }

        //Problem 2: Write a program that takes three points(x1, y1), (x2, y2) and(x3, y3)
        //from the user and the program will check whether all the three points fall on one straight line.
        static void Problem_2()
        {
            // Input the coordinates of three points
            Console.WriteLine("Enter (x1, y1): ");
            double x1 = Convert.ToDouble(Console.ReadLine());
            double y1 = Convert.ToDouble(Console.ReadLine());

            Console.WriteLine("Enter (x2, y2): ");
            double x2 = Convert.ToDouble(Console.ReadLine());
            double y2 = Convert.ToDouble(Console.ReadLine());

            Console.WriteLine("Enter (x3, y3): ");
            double x3 = Convert.ToDouble(Console.ReadLine());
            double y3 = Convert.ToDouble(Console.ReadLine());

            // Calculate the area of the triangle
            double area = Math.Abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0;

            // Check if the area is zero
            if (area == 0)
                Console.WriteLine("The points are collinear.");
            else
                Console.WriteLine("The points are not collinear.");
        }

        //Problem 3: Write a program that takes coordinates (x, y) of the center of a circle
        //and its radius from the user, the program will determine whether a point lies inside the
        //circle, on the circle or outside the circle
        static void Problem_3()
        {
            // Input center and radius of the circle
            Console.WriteLine("Enter the x coordinate of the center:");
            double xCenter = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine("Enter the y coordinate of the center:");
            double yCenter = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine("Enter the radius of the circle:");
            double radius = Convert.ToDouble(Console.ReadLine());

            // Input a  point 
            Console.WriteLine("Enter the x coordinate of the point:");
            double xPoint = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine("Enter the y coordinate of the point:");
            double yPoint = Convert.ToDouble(Console.ReadLine());

            // Calculate the distance between center and point
            double distance = Math.Sqrt(Math.Pow(xPoint - xCenter, 2) + Math.Pow(yPoint - yCenter, 2));

            // Determine where the point lies
            if (distance < radius)
                Console.WriteLine("The point lies inside the circle.");
            else if (distance == radius)
                Console.WriteLine("The point lies on the circle.");
            else
                Console.WriteLine("The point lies outside the circle.");
        }

        //Problem 4: Write a program that takes a character from the user and determines
        //whether the character entered is a capital letter, a small case letter, a digit or a special
        //symbol.The following table shows the range of ASCII values for various characters. 
        static void Problem_4()
        {
            Console.WriteLine("Enter a character: ");
            char inputChar = Console.ReadKey().KeyChar; // Reads a single character input
            Console.WriteLine();

            // Convert character to ASCII value
            int value = (int)inputChar;

            // Check if it's an uppercase letter
            if (value >= 65 && value <= 90)
            {
                Console.WriteLine("The character is an uppercase letter.");
            }
            // Check if it's a lowercase letter
            else if (value >= 97 && value <= 122)
            {
                Console.WriteLine("The character is a lowercase letter.");
            }
            // Check if it's a digit
            else if (value >= 48 && value <= 57)
            {
                Console.WriteLine("The character is a digit.");
            }
            // If not any of the above, it's a special symbol
            else
            {
                Console.WriteLine("The character is a special symbol.");
            }
        }

        //Problem 5: Write a program using a switch statement that takes one value from the
        //user and asks about the type of conversion and then performs a conversion depending on
        //the type of conversion.If user enters:
        //                                       I -> convert from inches to centimeters.
        //                                       G -> convert from gallons to liters.
        //                                       M -> convert from mile to kilometer.
        //                                       P -> convert from pound to kilogram.
        //If the user enters any other character, then show a proper message.
        static void Problem_5()
        {
            Console.WriteLine("Enter a conversion type (I, G, M, P): ");
            char option = Console.ReadKey().KeyChar;
            Console.WriteLine();

            switch (option)
            {
                case 'I': // Inches to centimeters
                    Console.WriteLine("Enter value in inches:");
                    double inches = Convert.ToDouble(Console.ReadLine());
                    Console.WriteLine($"{inches} inches is {inches * 2.54} centimeters.");
                    break;

                case 'G': // Gallons to liters
                    Console.WriteLine("Enter value in gallons:");
                    double gallons = Convert.ToDouble(Console.ReadLine());
                    Console.WriteLine($"{gallons} gallons is {gallons * 3.78541} liters.");
                    break;

                case 'M': // Miles to kilometers
                    Console.WriteLine("Enter value in miles:");
                    double miles = Convert.ToDouble(Console.ReadLine());
                    Console.WriteLine($"{miles} miles is {miles * 1.60934} kilometers.");
                    break;

                case 'P': // Pounds to kilograms
                    Console.WriteLine("Enter value in pounds:");
                    double pounds = Convert.ToDouble(Console.ReadLine());
                    Console.WriteLine($"{pounds} pounds is {pounds * 0.453592} kilograms.");
                    break;

                default:
                    Console.WriteLine("Invalid input. Please enter I, G, M, or P for valid conversions.");
                    break;
            }
        }

        //Problem 6: In a company, worker efficiency is determined based on the time
        //required for a worker to complete a specific job.If the time taken by the worker is between
        //2 - 3 hours, then the worker is said to be highly efficient.If the time required by the worker
        //is 3 - 4 hours, then the worker is ordered to increase their speed.If the time taken is 4 - 5
        //hours, then the worker is given training to improve his speed and if the time taken by the
        //worker is more than 5 hours then the worker must leave the company. If the time taken by
        //the worker is input through the keyboard, then find the efficiency of the worker. 
        static void Problem_6()
        {
            Console.WriteLine("Input time taken by the worker: ");
            double time = Convert.ToDouble(Console.ReadLine());

            if (time >= 2 && time <= 3) //2 - 3 hours, then the worker is said to be highly efficient
            {
                Console.WriteLine("The worker is highly efficient.");
            }
            else if (time > 3 && time <= 4) //3 - 4 hours, then the worker is ordered to increase their speed
            {
                Console.WriteLine("The worker is ordered to increase their speed ");
            }
            else if (time > 4 && time <= 5) //4 - 5 hours, then the worker is given training to improve his speed
            {
                Console.WriteLine("The worker is given training to improve his speed");
            }
            else if (time > 5) //more than 5 hours then the worker must leave the company
            {
                Console.WriteLine("the worker must leave the company.");
            }
            else
            {
                Console.WriteLine("Please enter the time more than 2.");
            }
        }

        //Problem 7: Write a program using conditional operators to determine whether a year
        //entered through the keyboard is a leap year or not.
        static void Problem_7()
        {
            //Input a year
            Console.Write("Enter a year: ");
            int year = int.Parse(Console.ReadLine());

            // Using conditional operators to determine if it's a leap year
            bool isLeapYear = (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);

            // Output result
            if (isLeapYear)
            {
                Console.WriteLine("The year is a leap year.");
            }
            else
            {
                Console.WriteLine("The year is not a leap year.");
            }
        }

        //Problem 8: Write a program using a switch statement that takes one character value
        //from the user and checks whether the entered value is an arithmetic operator, logical
        //operator, conditional operator, relational operator or something else.
        static void Problem_8()
        {
            Console.Write("Enter a character: ");
            char input = Console.ReadLine()[0];  // Read a single character input

            switch (input)
            {
                // Arithmetic Operators
                case '+':
                case '-':
                case '*':
                case '/':
                case '%':
                    Console.WriteLine("The character is an arithmetic operator.");
                    break;

                // Logical Operators
                case '&':
                case '|':
                case '!':
                    Console.WriteLine("The character is a logical operator.");
                    break;

                // Conditional Operator
                case '?':
                    Console.WriteLine("The character is a conditional operator.");
                    break;

                // Relational Operators
                case '<':
                case '>':
                case '=':
                    Console.WriteLine("The character is a relational operator.");
                    break;

                // Default case for anything else
                default:
                    Console.WriteLine("The character is something else.");
                    break;
            }
        }
        //Problem 9: Write a program that prints an identity matrix using a for loop, in other
        //words takes a value n from the user and shows the identity table of size n * n
        static void Problem_9()
        {
            // Enter the matrix size
            Console.WriteLine("Enter the matrix size n: ");

            int n = int.Parse(Console.ReadLine());

            // Iterate over each row of the matrix
            for (int i = 0; i < n; i++)
            {
                // Iterate over each column of the matrix
                for (int j = 0; j < n; j++)
                {
                    // Check if row index equals column index
                    if (i == j)
                    {
                        // Print 1 for diagonal elements
                        Console.WriteLine("1");
                    }
                    else
                    {
                        // Print 0 for non-diagonal elements
                        Console.WriteLine("0");
                    }
                }
            }
        }


        //Problem 10: Write a program using a for loop that prints the following series.
        //1 2 4 8 16 21 64 128...nth iteration.
        static void Problem_10()
        {
            Console.WriteLine("Enter the numbers of iteration: ");
            int n = int.Parse(Console.ReadLine());
            int value = 1; // Initialize the first number
            for (int i = 0; i < n; i++) // Loop through numbers of interation 
            {
                value *= 2; // The number is double in each iteration 
                Console.WriteLine(value + " "); // Print the number 
            }
        }

        //Problem 11: Write a program using a for loop that prints the following output(you
        //need to find a pattern to print letters in this order): A B D H P
        static void Problem_11()
        {
            // Define the pattern positions (powers of 2)
            int[] positions = { 1, 2, 4, 8, 16 };

            // Iterate using a for loop
            for (int i = 0; i < positions.Length; i++)
            {
                int position = positions[i];
                // Calculate the letter by converting position to a character
                char letter = (char)('A' + position - 1);
                // Print the letter followed by a space
                Console.Write(letter + " ");
            }
        }

        // Problem 12: Write a program using a loop that prints the following output.
        //1 2 2 3 3 3 4 4 4 4 5 5 5 5 5 6 6 6 6 6 6. . .nth iteration.
        static void Problem_12()
        {
            int n = int.Parse(Console.ReadLine());

            // iterates from 1 to n 
            for (int i = 1; i <= n; i++)
            {
                // Inner loop: prints the current number i, i times
                for (int j = 0; j < i; j++)
                {
                    Console.Write(i + " "); // Print the number followed by a space
                }
                Console.WriteLine();// Move to the next line after printing i times
            }
        }

        //Problem 13: Write a program to print all the ASCII values and their equivalent
        //characters using a while loop.The ASCII values vary from 0 to 255.
        static void Problem_13()
        {
            // Initialize a variable i to 0
            int i = 0;

            // While loop to iterate from 0 to 255 (inclusive)
            while (i <= 255)
            {
                // Print the current value of i and its corresponding ASCII character
                Console.WriteLine($"{i}: {(char)i}");

                i++;// Increment the value of i by 1

            }
        }


        //Problem 14: Write a program to print all the ASCII values and their equivalent
        //characters using a do -while loop.The ASCII values vary from 10 to 255.
        static void Problem_14()
        {
            int i = 10;

            // Loop through ASCII values from 0 to 255
            do
            {
                Console.WriteLine($"ASCII value: {i} = Character: {(char)i}");
                i++;
                // Combine casting and string interpolation
            } while (i < 255);
        }

        //Problem 15: Write a program to draw Pascal's triangle.
        static void Problem_15()
        {
            Console.Write("Enter the number of rows for Pascal's Triangle: ");
            int rows = Convert.ToInt32(Console.ReadLine());

            for (int i = 0; i < rows; i++)
            {
                // Print spaces for alignment
                for (int k = 0; k < rows - i; k++)
                {
                    Console.Write(" ");
                }

                int number = 1;
                // Print each row
                for (int j = 0; j <= i; j++)
                {
                    Console.Write(number + " ");
                    number = number * (i - j) / (j + 1);  // Calculate next number
                }
                Console.WriteLine();
            }
        }

        //Problem 16: Write a program to calculate the surface area and volume of a sphere
        //given its radius, which is entered from the keyboard. Use the default value of pi(pi can be
        //changed when calling the program).
        // Problem 16: Calculate the volume and surface area of a sphere

        static void Problem_16()
        {
            // Define the constant value for Pi
            const double PI = 3.1415;

            // enter the radius of the sphere
            Console.Write("Enter the radius of the sphere: ");

            double radius = Convert.ToDouble(Console.ReadLine());

            // Calculate the volume of the sphere using the formula:
            // Volume = (4/3) * Pi * r^3
            double volume = (4.0 / 3.0) * PI * Math.Pow(radius, 3);

            // Calculate the surface area of the sphere using the formula:
            // Surface Area = 4 * Pi * r^2
            double surfaceArea = 4 * PI * Math.Pow(radius, 2);

            // Output the calculated volume of the sphere
            Console.WriteLine($"Volume of the sphere: {volume}");

            // Output the calculated surface area of the sphere
            Console.WriteLine($"Surface Area of the sphere: {surfaceArea}");
        }


        //Problem 17: Write a program to calculate the value of the function y = x ^ 2 + 4x -
        //3.5 for x belonging to the interval(a, b), where a and b are integers entered from the
        //keyboard (b is always greater than a).
        static void Problem_17()
        {
            // enter the value for 'a'
            Console.Write("Enter the value for a: ");
            int a = Convert.ToInt32(Console.ReadLine());

            // enter the value for 'b'
            Console.Write("Enter the value for b: ");
            int b = Convert.ToInt32(Console.ReadLine());

            // Loop through the values of x from a to b 
            for (int x = a; x <= b; x++)
            {
                // Calculate the value of y using the formula y = x^2 + 4x - 3.5
                double y = Math.Pow(x, 2) + 4 * x - 3.5;

                // Output the result for each x
                Console.WriteLine($"For x = {x}, y = {y}");
            }
        }


        //Problem 18: Write a program to input a number in the decimal system and convert
        //it to its corresponding binary representation.
        static void Problem_18()
        {
            // enter a decimal number
            Console.Write("Enter a decimal number: ");
            int decimalNumber = Convert.ToInt32(Console.ReadLine());

            // Convert the decimal number to its binary representation
            string binaryRepresentation = Convert.ToString(decimalNumber, 2);

            // Output the binary representation
            Console.WriteLine($"Binary representation: {binaryRepresentation}");
        }


        //Problem 19: Write a program to find the smallest number among three numbers a,
        //b, and c(a, b, c can have very large values) entered from the keyboard. Do not use if-else
        //or switch-case statements.
        static void Problem_19()
        {
            //  enter three numbers
            Console.Write("Enter the first number: ");
            long a = Convert.ToInt64(Console.ReadLine());

            Console.Write("Enter the second number: ");
            long b = Convert.ToInt64(Console.ReadLine());

            Console.Write("Enter the third number: ");
            long c = Convert.ToInt64(Console.ReadLine());

            //Find the smallest number among the three
            long smallest = Math.Min(a, Math.Min(b, c));

            // Output the smallest number
            Console.WriteLine($"The smallest number is: {smallest}");
        }


        //Problem 20: Write a program with a menu that allows the user to choose to calculate
        //the area and perimeter of one of three shapes: triangle, rectangle, or circle. The constant PI
        //is 3.1415.
        static void Problem_20()
        {
            // Define the constant for PI
            const double PI = 3.1415;

            // Menu for shape selection
            Console.WriteLine("Choose a shape to calculate:");
            Console.WriteLine("1. Triangle");
            Console.WriteLine("2. Rectangle");
            Console.WriteLine("3. Circle");

            int choice = Convert.ToInt32(Console.ReadLine());

            // Switch statement to handle different shapes
            switch (choice)
            {
                case 1: // Triangle
                    Console.Write("Enter the base of the triangle: ");
                    double baseT = Convert.ToDouble(Console.ReadLine());
                    Console.Write("Enter the height of the triangle: ");
                    double heightT = Convert.ToDouble(Console.ReadLine());
                    double areaT = 0.5 * baseT * heightT; // Area of the triangle
                    Console.WriteLine($"Area of the triangle: {areaT}");
                    break;

                case 2: // Rectangle
                    Console.Write("Enter the length of the rectangle: ");
                    double length = Convert.ToDouble(Console.ReadLine());
                    Console.Write("Enter the width of the rectangle: ");
                    double width = Convert.ToDouble(Console.ReadLine());
                    double areaR = length * width; // Area of the rectangle
                    double perimeterR = 2 * (length + width); // Perimeter of the rectangle
                    Console.WriteLine($"Area of the rectangle: {areaR}");
                    Console.WriteLine($"Perimeter of the rectangle: {perimeterR}");
                    break;

                case 3: // Circle
                    Console.Write("Enter the radius of the circle: ");
                    double radius = Convert.ToDouble(Console.ReadLine());
                    double areaC = PI * Math.Pow(radius, 2); // Area of the circle
                    double perimeterC = 2 * PI * radius; // Circumference of the circle
                    Console.WriteLine($"Area of the circle: {areaC}");
                    Console.WriteLine($"Perimeter of the circle: {perimeterC}");
                    break;

                default:
                    Console.WriteLine("Invalid choice."); // Handle invalid choices
                    break;
            }
        }

    }
}



