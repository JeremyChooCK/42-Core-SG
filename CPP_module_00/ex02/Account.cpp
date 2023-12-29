#include "Account.hpp"
#include <iostream>
#include <chrono>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts++), _amount(initial_deposit),
      _nbDeposits(0), _nbWithdrawals(0) {
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created\n";
}

Account::~Account() {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed\n";
}

void Account::makeDeposit(int deposit) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit;
    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;
    std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << "\n";
}

bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    if (_amount >= withdrawal) {
        _amount -= withdrawal;
        _nbWithdrawals++;
        _totalAmount -= withdrawal;
        _totalNbWithdrawals++;
        std::cout << "index:" << _accountIndex << ";p_amount:" << (_amount + withdrawal) << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << "\n";
        return true;
    } else {
        std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused\n";
        return false;
    }
}

int Account::checkAmount() const {
    return _amount;
}

void Account::displayStatus() const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << "\n";
}

int Account::getNbAccounts() {
    return _nbAccounts;
}

int Account::getTotalAmount() {
    return _totalAmount;
}

int Account::getNbDeposits() {
    return _totalNbDeposits;
}

int Account::getNbWithdrawals() {
    return _totalNbWithdrawals;
}

void Account::displayAccountsInfos() {
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << "\n";
}

void Account::_displayTimestamp() {
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);

    std::tm buf;
    localtime_r(&in_time_t, &buf);

    std::cout << "[" << (buf.tm_year + 1900)
              << std::setw(2) << std::setfill('0') << (buf.tm_mon + 1)
              << std::setw(2) << std::setfill('0') << buf.tm_mday << "_"
              << std::setw(2) << std::setfill('0') << buf.tm_hour
              << std::setw(2) << std::setfill('0') << buf.tm_min
              << std::setw(2) << std::setfill('0') << buf.tm_sec << "] ";
}
