#include "InvestmentCalc.h"

#include <iostream>
#include <iomanip>

// Constructor assigns input values to member variables
InvestmentCalculator::InvestmentCalculator(double t_initialInvestment, double t_monthlyDeposit, double t_annualInterestRate, int t_numberOfYears)
{
    m_initialInvestment = t_initialInvestment;
    m_monthlyDeposit = t_monthlyDeposit;
    m_annualInterestRate = t_annualInterestRate;
    m_numberOfYears = t_numberOfYears;
}

// Prints a formatted table header
void InvestmentCalculator::printHeader(const std::string& t_title) const
{
    std::cout << "  " << t_title << std::endl;
    std::cout << "=======================================" << std::endl;

    std::cout << std::left
        << std::setw(8) << "Year"
        << std::setw(18) << "Year End Balance"
        << std::setw(20) << "Year End Earned Interest"
        << std::endl;

    std::cout << "---------------------------------------" << std::endl;
}

// calculate and print report without monthly deposits
double InvestmentCalculator::BalanceWithoutMonthlyDeposit() const
{
    printHeader("Balance and Interest Without Additional Monthly Deposits");

    double balance = m_initialInvestment;
    double annualRate = m_annualInterestRate / 100.0;

    std::cout << std::fixed << std::setprecision(2);

    for (int year = 1; year <= m_numberOfYears; ++year)
    {
        double yearlyInterest = balance * annualRate;
        balance += yearlyInterest;

        std::cout << std::left
            << std::setw(8) << year
            << "$" << std::setw(17) << balance
            << "$" << std::setw(19) << yearlyInterest
            << std::endl;
    }

    return balance;
}

// calculate and print report with monthly deposits
double InvestmentCalculator::BalanceWithMonthlyDeposit() const
{
    printHeader("Balance and Interest With Additional Monthly Deposits");

    double balance = m_initialInvestment;
    double annualRate = m_annualInterestRate / 100.0;
    double monthlyRate = annualRate / 12.0;

    std::cout << std::fixed << std::setprecision(2);

    for (int year = 1; year <= m_numberOfYears; ++year)
    {
        double yearlyInterest = 0.0;

        for (int month = 1; month <= 12; ++month)
        {
            balance += m_monthlyDeposit;

            double monthlyInterest = balance * monthlyRate;
            balance += monthlyInterest;
            yearlyInterest += monthlyInterest;
        }

        std::cout << std::left << std::setw(8) << year << "$" << std::setw(17) << balance << "$" << std::setw(19) << yearlyInterest << std::endl;
    }

    return balance;
}

