#include <iostream>
#include <limits>
#include "InvestmentCalc.h"

// get a positive double value from user 
double getPositiveDouble(const std::string& prompt)
{
    double value;

    while (true)
    {
        std::cout << prompt;
        std::cin >> value;

        if (!std::cin || value <= 0.0)
        {
            std::cout << "Enter a positive number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
    }
}

// get a non negative double value from user 
double getNonNegativeDouble(const std::string& prompt)
{
    double value;

    while (true)
    {
        std::cout << prompt;
        std::cin >> value;

        if (!std::cin || value < 0.0)
        {
            std::cout << "Enter zero or a positive number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
    }
}

// Gets a positive integer value from the user
int getPositiveInt(const std::string& prompt)
{
    int value;

    while (true)
    {
        std::cout << prompt;
        std::cin >> value;

        if (!std::cin || value <= 0)
        {
            std::cout << "Please enter a positive whole number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
    }
}

int main()
{
    bool keepRunning = true;

    while (keepRunning)
    {
        std::cout << "**********************************" << std::endl;
        std::cout << "*********** Data Input ***********" << std::endl;
        std::cout << "**********************************" << std::endl;

        double initialInvestment = getPositiveDouble("Initial Investment Amount: ");
        double monthlyDeposit = getNonNegativeDouble("Monthly Deposit: ");
        double annualInterest = getPositiveDouble("Annual Interest (percent): ");
        int numberOfYears = getPositiveInt("Number of years: ");

        InvestmentCalculator calculator(
            initialInvestment,
            monthlyDeposit,
            annualInterest,
            numberOfYears
        );

        std::cout << "\nPress Enter to continue . . .";
        std::cin.get();

        std::cout << "\n\n";
        calculator.BalanceWithoutMonthlyDeposit();
        std::cout << "\n\n";
        calculator.BalanceWithMonthlyDeposit();
        std::cout << "\n";

        char choice;
        std::cout << "\nRun another projection? (Y/N): ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice != 'Y' && choice != 'y')
        {
            keepRunning = false;
        }
    }

    return 0;
}


