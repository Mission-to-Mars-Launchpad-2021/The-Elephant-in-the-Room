#include <ArduinoUnit.h>


bool is_a_leap_year(int year)
{
  return (year % 4==0) and (year % 100!=0) || (year % 400==0);
}

test(a_typical_common_year_return_false)
{
  assertFalse(is_a_leap_year(2001));
}


test(a_typical_leap_year_return_true)
{
  assertTrue(is_a_leap_year(2020));
}

test(a_typical_leap_year_return_false)
{
  assertTrue(is_a_leap_year(2000));
}

test(a_typical_common_year_return_true)
{
  assertFalse(is_a_leap_year(1900));
}


void setup() {
Serial.begin(115200);

}

void loop() {
  Test::run();  

}
