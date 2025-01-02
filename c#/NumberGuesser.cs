using System.Diagnostics.Metrics;
using System.Numerics;
using System.Reflection.Metadata;
using static System.Runtime.InteropServices.JavaScript.JSType;

// Main
GetAppInfo();
GreetUser();

// Init the first correct number.
int correctNumber = randNumGenerator();

// Init guess var.
int guess = 0;

// Init play answer.
string playAnswer = "Y";

do{
    Console.Write("Guess a number between 1 and 10: ");
    string guessInput = Console.ReadLine();

    // Cast guessInput string to an int for num comparison
    if (!int.TryParse(guessInput, out guess))
    {
        PrintColorMessage(ConsoleColor.Red, "Please enter an actual number 1 - 10.");
        continue;
    }

    guess = Int32.Parse(guessInput);

    if (guess != correctNumber)
    {
        PrintColorMessage(ConsoleColor.Red, "Your guess of {0} was incorrect. Please try again!");
    }
    else
    {
        PrintColorMessage(ConsoleColor.Green, "Congrats! You guessed correctly!");
        Console.Write("Do you want to keep playing? (Y/N): ");
        playAnswer = Console.ReadLine().ToUpper();
        correctNumber = randNumGenerator();
    }

} while (correctNumber != guess && playAnswer == "Y");

int randNumGenerator()
{
    Random random = new Random();
    correctNumber = random.Next(1, 10);
    return correctNumber;
}

// Function Definitions
static void GetAppInfo()
{
    string appName = "Number Guesser";
    string appVersion = "1.0.0";
    string appAuthor = "Taylor Moore";

    // Change Text Color
    Console.ForegroundColor = ConsoleColor.Cyan;

    // Write App Info
    Console.WriteLine("{0}: Version {1} by {2}", appName, appVersion, appAuthor);

    // Reset Text Color
    Console.ResetColor();
}
static void GreetUser()
{
    Console.Write("What is your name? ");
    string nameInput = Console.ReadLine();
    Console.WriteLine("Hello {0}, let's play a game...", nameInput);
}
static void PrintColorMessage(ConsoleColor color, string message)
{
    Console.ForegroundColor = color;
    Console.WriteLine(message);
    Console.ResetColor();
}