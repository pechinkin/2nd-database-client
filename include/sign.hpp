#ifndef SIGN_H
#define SIGN_H
enum ZodiacSign {
    Aries,
    Taurus,
    Gemini,
    Cancer,
    Leo,
    Virgo,
    Libra,
    Scorpio,
    Sagittarius,
    Capricorn,
    Aquarius,
    Pisces
};
using string = std::string;

class Sign
{
private:
    int day;
    int month;
    int year;
    ZodiacSign sign;
    
    string name;
    string surname;
    
public:
    void SetDay(int _d), SetMonth(int _m), SetYear(int _y), SetName(string _name), SetSurname(string _surname);
    void SetZodiacSign();
    
    int GetDay() const, GetMonth() const, GetYear() const;
    ZodiacSign GetZodiacSign() const;
    string GetName() const, GetSurname() const;
    
    friend std::ostream& operator<<(std::ostream& output, const Sign* example_sign);
    
    Sign();
    Sign(int _d, int _m, int _y, string _name, string _surname);
    Sign(Sign* another);
};
#endif
