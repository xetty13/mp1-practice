struct Vector
{
private:
    int n;
    double* x;
public:
    Vector(); // конструктор по умолчанию
    Vector(int _n); // конструктор с параметром
    Vector(const Vector& a); // конструктор копирования
    ~Vector(); // деструктор
    Vector operator+(const Vector& a) const; // покомпонентное сложение
    Vector operator-(const Vector& a) const; // покомпонентное вычитание
    Vector operator+(double a) const; // прибавление константы
    Vector operator-(double a) const; // вычитание константы
    Vector operator*(double a) const; // умножение на константу
    double operator*(const Vector& a) const; // скалярное произведение
    Vector& operator+=(const Vector& a); // покомпонентное сложение
    Vector& operator-=(const Vector& a); // покомпонентное вычитание
    Vector& operator+=(double a); // прибавление константы
    Vector& operator-=(double a); // вычитание константы
    Vector& operator*=(double a); // умножение на константу
    const Vector& operator=(const Vector& a); // присваивание
    double& operator[](int i);// запись
    const double& operator[](int i) const; // чтение
    double Length() const; // функция получения дины вектора
    void* operator new[](size_t n); //выделение памяти
    void operator delete[](void* p); // освобождение памяти
    void Add(); // добавление вектора
    void Print() const;// печать вектора
};