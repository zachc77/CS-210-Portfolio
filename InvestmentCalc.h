

#ifndef AIRGEAD_INVESTMENT_CALCULATOR_H_

#define AIRGEAD_INVESTMENT_CALCULATOR_H_

#include <string>

// handle calculations and report outputs 
class InvestmentCalculator {

public:

    // construct for initial data
    InvestmentCalculator(double t_initialInvestment,
        double t_monthlyDeposit,
        double t_annualInterestRate,
        int t_numberOfYears);

    // calculate and display without monthly deposits
    double BalanceWithoutMonthlyDeposit() const;

    // calculate and display with monthly deposits
    double BalanceWithMonthlyDeposit() const;

private:
    // member variables 
    double m_initialInvestment;
    double m_monthlyDeposit;
    double m_annualInterestRate;
    int    m_numberOfYears;

    // Prints the table header
    void printHeader(const std::string& t_title) const;
};

#endif // AIRGEAD_INVESTMENT_CALCULATOR_H_
