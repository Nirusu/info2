// using formula from Georg Glaeser: https://de.wikipedia.org/wiki/Wochentagsberechnung#Formel
#include "count_13th.hpp"
Weekday_statistics count_13th(int start_year, int  year_offset) {
    Weekday_statistics w;
    // const day variable initialized to 13. Since we use an generic algorithm to calculate the day, we could change this value if we want to get values for another day, but otherwise this variable is kinda obsolete.
    const int day = 13;
    // calc_day is the result of the formula
    int calcDay = 0;
    // In perspective of the algorithm, January and February are still calculated in the old year, so if we reach March, we have to set the value to the real year.
    int formulaMonth = 0;
    // start in 1900. January and February "belong to the last year" according to the formula, so for these two months we start with 1899 (the previous year in general).
    int firstTwoDigitsYear = 18;
    int lastTwoDigitsYear = 99;
    // for loop to process a year
    for (;year_offset > 0; year_offset--) {
        // for loops to process a month. Use the normal month convention because it's easier to work with. We adjust it later to match the formula.
        for (int month = 1; month <= 12; month++) {
            // In terms of the formula, the year begins in March. Since January and February were calculated in the last year, we fix the year when we reach March. Modulo 100 because we only need two digits.
            if (month == 3) {
                if (lastTwoDigitsYear == 99)
                    firstTwoDigitsYear = ++firstTwoDigitsYear % 100;
                lastTwoDigitsYear = ++lastTwoDigitsYear % 100;
            }
            // January and February are 11 and 12 in the algorithm, so we add 10 to them. No mod 12 because we don't want to have a 0 if we work with 12 (February).
            if (month == 1 || month == 2) {
                formulaMonth = month + 10;
            }
                // Since Match is the new year in terms of the formula, adjust the number of the month to match the formula.
            else {
                formulaMonth = month - 2;
            }
            // the Gaussian bracket functions from the formula, separated into single variables for easier debugging.
            // cast to int to get rid of the decimal digits, we don't need them
            int prodFormulaMonth = (int)(2.6*formulaMonth-0.2);
            int divLastTwoDigitsYear = lastTwoDigitsYear/4;
            int divFirstTwoDigitsYear = firstTwoDigitsYear/4;
            int prodFirstTwoDigitsYear = 2*firstTwoDigitsYear;
            // let's put all that together
            calcDay = (day + prodFormulaMonth + lastTwoDigitsYear + divLastTwoDigitsYear + divFirstTwoDigitsYear - prodFirstTwoDigitsYear) % 7;
            // fix potential minus modulo because C++ can't do it on its own
            while (calcDay < 0)
                calcDay += 7;
            // assign the integer result to the weekday and increase the matching counter
            switch(calcDay) {
                case 0: w.set_sunday_value(w.get_sunday_value() + 1); break;
                case 1: w.set_monday_value(w.get_monday_value() + 1); break;
                case 2: w.set_tuesday_value(w.get_tuesday_value() + 1); break;
                case 3: w.set_wednesday_value(w.get_wednesday_value() + 1); break;
                case 4: w.set_thursday_value(w.get_thursday_value() + 1); break;
                case 5: w.set_friday_value(w.get_friday_value() + 1); break;
                case 6: w.set_saturday_value(w.get_saturday_value() + 1); break;
                default: break;
            }
        }
    }
    return w;
}