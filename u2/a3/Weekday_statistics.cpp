#include "Weekday_statistics.hpp"

Weekday_statistics::Weekday_statistics(): monday(0), tuesday(0), wednesday(0), thursday(0), friday(0), saturday(0), sunday(0) { }

void Weekday_statistics::set_monday_value(int value) {
    monday = value;
}

void Weekday_statistics::set_tuesday_value(int value) {
    tuesday = value;
}

void Weekday_statistics::set_wednesday_value(int value) {
    wednesday = value;
}

void Weekday_statistics::set_thursday_value(int value) {
    thursday = value;
}

void Weekday_statistics::set_friday_value(int value) {
    friday = value;
}

void Weekday_statistics::set_saturday_value(int value) {
    saturday = value;
}

void Weekday_statistics::set_sunday_value(int value) {
    sunday = value;
}

int Weekday_statistics::get_monday_value() {
    return monday;
}

int Weekday_statistics::get_tuesday_value() {
    return tuesday;
}

int Weekday_statistics::get_wednesday_value() {
    return wednesday;
}

int Weekday_statistics::get_thursday_value() {
    return thursday;
}

int Weekday_statistics::get_friday_value() {
    return friday;
}

int Weekday_statistics::get_saturday_value() {
    return saturday;
}

int Weekday_statistics::get_sunday_value() {
    return sunday;
}