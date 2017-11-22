class Date{
public:
    short day, month, year;
    
    Date(int d=0, int m=0, int y=0): day(d), month(m), year(y){}
    
    inline const bool is_leap() const {
        return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
    }
    
    inline int monthDays(){
        switch(month){
            case 2: return 28 + is_leap();
            case 4:
            case 6:
            case 9:
            case 11: return 30;
            default: break;
        }
        return 31;
    }
    
    inline void increase(){
        day++;
        if(day > monthDays()){
            day = 1;
            month++;
            if(month > 12){
                month = 1;
                year++;
            }
        }
    }
    
    inline bool const operator < (const Date a)const{
        if(year == a.year){
            if(month == a.month) return day < a.day;
            return month < a.month;
        }
        return year < a.year;
    }
    
    int operator -(Date b){
        Date a = *this;
        int t = 1;
        if(a < b){
            t = -1;
            swap(a, b);
        }
        int res = 0;
        while(b < a){
            res++;
            b.increase();
        }
        return res * t;
    }
    
    inline const void out() const {
        printf("%02d:%02d:%04d\n", day, month, year);
    }
};

