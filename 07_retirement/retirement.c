#include <stdlib.h>
#include <stdio.h>

struct _retire_info {
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;


double balanceCalc(double balance, retire_info general) {
  return balance * general.rate_of_return + balance + general.contribution;
}

void retirement(int startAge, double initial, retire_info working, retire_info retired) {
  //for working
  int age = startAge;
  double balance = initial;

  for(int i = 0; i < working.months; i++) {
    int year = age / 12;
    int month = age % 12;
    printf("Age %3d month %2d you have $%.2f\n", year, month, balance);
    age ++;
    balance = balanceCalc(balance, working);
  }
  //for retired
  for( int i = 0; i < retired.months; i++) {
    int year = age / 12;
    int month = age % 12;
    printf("Age %3d month %2d you have $%.2f\n", year, month, balance);
    age ++;
    balance = balanceCalc(balance, retired);
  }
}

int main(void) {
  retire_info working;
  retire_info retired;
  

  working.months = 489;
  working.contribution = 1000.0;
  working.rate_of_return = 0.045/12;

  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 0.01 /12;

  int start_age = 327;
  double initial_savings = 21345.00;

  retirement(start_age, initial_savings, working, retired);

  return EXIT_SUCCESS;
}
