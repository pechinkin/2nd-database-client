#include <iostream>
#include <sign.hpp>

void Sign::SetYear (int _y)
{
    year = _y;
}
void Sign::SetMonth (int _m)
{
    month = _m;
}
void Sign::SetDay (int _d)
{
    day = _d;
}
void Sign::SetName (string _name)
{
    name = _name;
}
void Sign::SetSurname (string _surname)
{
    surname = _surname;
}


int Sign::GetDay() const
{
    return day;
}
int Sign::GetMonth() const
{
    return month;
}
int Sign::GetYear() const
{
    return year;
}
ZodiacSign Sign::GetZodiacSign() const
{
    return sign;
}
string Sign::GetName() const
{
    return name;
}
string Sign::GetSurname() const
{
    return surname;
}
string Sign::GetNameOfZodiacSign() const
{
    switch (sign) {
        case 0:
            return "Aries";
            break;
        case 1:
            return "Taurus";
            break;
        case 2:
            return "Gemini";
            break;
        case 3:
            return "Cancer";
            break;
        case 4:
            return "Leo";
            break;
        case 5:
            return "Virgo";
            break;
        case 6:
            return "Libra";
            break;
        case 7:
            return "Scorpio";
            break;
        case 8:
            return "Sagittarius";
            break;
        case 9:
            return "Capricorn";
            break;
        case 10:
            return "Aquarius";
            break;
        case 11:
            return "Pisces";
            break;
        default:
            break;
    }
}

std::ostream& operator<<(std::ostream& output, const Sign* example_sign) {
    output << example_sign->GetDay() << '.' << example_sign->GetMonth() << '.' << example_sign->GetYear()
    << '[' << example_sign->GetNameOfZodiacSign() << ']' << example_sign->GetName()  << ' ' << example_sign->GetSurname() << std::endl;
    return output;
}

Sign::Sign()
{
    SetDay(1);
    SetMonth(1);
    SetYear(1970);
    SetZodiacSign();
    SetName("no_name");
    SetSurname("no_surname");
}

Sign::Sign(Sign* another)
{
    SetDay(another->GetDay());
    SetMonth(another->GetMonth());
    SetYear(another->GetYear());
    SetZodiacSign();
    SetName(another->GetName());
    SetSurname(another->GetSurname());
}

Sign::Sign(int _d, int _m, int _y, string _name, string _surname): Sign()
{
    try {
        if (_y >= 1920 && _y <=2023)
            SetYear(_y);
        else
            throw std::logic_error("Invalid year");
        
        if (_m >= 1 && _m <= 12)
            SetMonth(_m);
        else
            throw std::logic_error("Invalid month");
        
        if (_d >=1 &&
            (
             ( (_m == 1 || _m == 3||_m == 5 || _m == 7 || _m == 8 || _m == 10 || _m == 12) && (_d <= 31) )
             ||
             ( (_m == 2 || _m == 4 || _m == 6 || _m == 9 || _m == 11) && (_d <= 30) )
             ||
             ( ( (_y % 4 == 0) && (_d <= 29) ) || ( (_y % 4 != 0 ) && (_d <= 28) ) )
             )
            )
            SetDay(_d);
        else
            throw std::logic_error("Invalid day");
        SetZodiacSign();
        SetName(_name);
        SetSurname(_surname);
    }
    catch (const std::logic_error& ex) {std::cout << "Logic_error: " << ex.what() << std::endl;}
}

void Sign::SetZodiacSign(){
    if ((month == 3 && day >= 21) || (month == 4 && day <= 19)) {
        sign = Aries;
    } else if ((month == 4 && day >= 20) || (month == 5 && day <= 20)) {
        sign = Taurus;
    } else if ((month == 5 && day >= 21) || (month == 6 && day <= 20)) {
        sign = Gemini;
    } else if ((month == 6 && day >= 21) || (month == 7 && day <= 22)) {
        sign = Cancer;
    } else if ((month == 7 && day >= 23) || (month == 8 && day <= 22)) {
        sign = Leo;
    } else if ((month == 8 && day >= 23) || (month == 9 && day <= 22)) {
        sign = Virgo;
    } else if ((month == 9 && day >= 23) || (month == 10 && day <= 22)) {
        sign = Libra;
    } else if ((month == 10 && day >= 23) || (month == 11 && day <= 21)) {
        sign = Scorpio;
    } else if ((month == 11 && day >= 22) || (month == 12 && day <= 21)) {
        sign = Sagittarius;
    } else if ((month == 12 && day >= 22) || (month == 1 && day <= 19)) {
        sign = Capricorn;
    } else if ((month == 1 && day >= 20) || (month == 2 && day <= 18)) {
        sign = Aquarius;
    } else {
        sign = Pisces;
    }
}
