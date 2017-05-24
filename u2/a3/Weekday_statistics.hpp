#ifndef WEEKDAY_STATISTICS_H
#define WEEKDAY_STATISTICS_H

class Weekday_statistics {
private:
int monday, tuesday, wednesday, thursday, friday, saturday, sunday;
public:
    Weekday_statistics();
    void set_monday_value(int), set_tuesday_value(int), set_wednesday_value(int), set_thursday_value(int), set_friday_value(int), set_saturday_value(int), set_sunday_value(int);
    int get_monday_value(), get_tuesday_value(), get_wednesday_value(), get_thursday_value(), get_friday_value(), get_saturday_value(), get_sunday_value();
};
#endif
