class  Triangle {
    double a, b, c;

public:

    Triangle();

    Triangle(double, double, double);

    double Area();

    friend bool operator>(Triangle, Triangle);
};

