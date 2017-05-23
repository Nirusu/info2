#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
// This include causes an error because Weekday_statistics is already included in count_13th.hpp
// #include "Weekday_statistics.hpp"
#include "count_13th.hpp"

TEST_CASE("Creating a class")
 {
 Weekday_statistics w;
 }

TEST_CASE("Getters")
 {
 Weekday_statistics w;
 int dummy;
  dummy = w.get_monday_value();
  dummy = w.get_tuesday_value();
  dummy = w.get_wednesday_value();
  dummy = w.get_thursday_value();
  dummy = w.get_friday_value();
  dummy = w.get_saturday_value();
  dummy = w.get_sunday_value();
 }

TEST_CASE("Setters")
 {
 Weekday_statistics w;
 int dummy = 1;
  w.set_monday_value(dummy);
  w.set_tuesday_value(dummy);
  w.set_wednesday_value(dummy);
  w.set_thursday_value(dummy);
  w.set_friday_value(dummy);
  w.set_saturday_value(dummy);
  w.set_sunday_value(dummy);
 }

TEST_CASE("The function itself")
 {
 int start_year = 1900;
 int year_offset = 2;
 Weekday_statistics w = count_13th(start_year, year_offset);
 }
