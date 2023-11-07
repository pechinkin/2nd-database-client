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

class Sign
{
private:
    int day;
    int month;
    int year;
    ZodiacSign sign;
    
public:
    void SetDay(int _d), SetMonth(int _m), SetYear(int _y);
    void SetZodiacSign();
    int GetDay() const, GetMonth() const, GetYear() const;
    ZodiacSign GetZodiacSign() const;
    
    friend std::ostream& operator<<(std::ostream& output, const Sign* example_sign);
    
    Sign();
    Sign(int _d, int _m, int _y);
    Sign(Sign* another);
};
