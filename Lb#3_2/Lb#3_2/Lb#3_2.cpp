#include <iostream>
class MyVector
{
    short* a;
    int size;
    int value;
    static int Count;
    int errorCode;
public:
    MyVector() : size(1), errorCode(0) { 
        a = new short[size];
        a[0] = 0;
        if (a == nullptr) 
            errorCode = 1; 
        Count++;
    }
    MyVector(int Size) : size(Size), errorCode(0), value(0) { 
        a = new short[Size];
        if (a == nullptr)
            errorCode = 1;
        else {
            for (int i = 0; i < Size; i++)
            {
                a[i] = value;
            }
        }
        Count++;
    }
    MyVector(int size, int value1) :size(size), value(value1), errorCode(0) { 
        a = new short[size];
        if (a == nullptr)
            errorCode = 1;
        else {
            for (int i = 0; i < size; i++)
            {
                a[i] = value1;
            }
        }
        Count++;
    }
    MyVector(MyVector& X) {
        size = X.size;
        a = new short[size];
        if (a == nullptr)
            errorCode = 1;
        else {
            for (int i = 0; i < size; i++)
            {
                a[i] = X.a[i];
            }
        }
        Count++;
    };

    ~MyVector() {
        delete[] a;
        Count--;
    }

    void ChangeElement(int i, short c) {
        if (i >= 0 && i < size) { 
            a[i] = c;
            errorCode = 0; 
        }
        else {
            errorCode = 2; 
        }
    }
    void OutputElement(int i) {
        std::cout << a[i] << std::endl;
    }
    void Add(short c) {
        for (int i = 0; i < size; i++)
        {
            a[i] += c;
        }
    }
    void Subtraction(short c) {
        for (int i = 0; i < size; i++)
        {
            a[i] -= c;
        }
    }
    void Multiple(unsigned char value) {
        for (int i = 0; i < size; i++)
        {
            a[i] *= value;
        }
    }
    void Comparison(int value, int j) {
        int choose;
        std::cout << "1 - >\n2 - =\n3 - !=\n";
        std::cin >> choose;
        switch (choose)
        {
        case 1:
            if (a[j] > value)
            {
                std::cout << true;
            }
            else {
                std::cout << false;
            }
            break;
        case 2:
            if (a[j] == value)
            {
                std::cout << true;
            }
            else {
                std::cout << false;
            }
            break;
        case 3:
            if (a[j] != value)
            {
                std::cout << true;
            }
            else {
                std::cout << false;
            }
            break;
        default:
            break;
        }
    }
    void printInfo() {
        std::cout << std::endl;
        for (int i = 0; i < size; i++) {
            std::cout << a[i] << " ";
        }
        std::cout << std::endl;
    }
    int getErrorCode() {
        return errorCode;
    }
    short& operator[](int index) {
        return a[index];
    }
    static int getObjectCount() {
        return Count;
    }
};

int MyVector::Count = 0;


int main()
{
    MyVector A;
    A.printInfo();
    MyVector B(9);
    B.printInfo();
    MyVector C(10, 7);
    C.printInfo();
    MyVector D = B;
    D.printInfo();
    B.ChangeElement(3, 15);
    B.printInfo();
    B.OutputElement(3);
    C.Add(5);
    C.printInfo();
    C.Subtraction(3);
    C.printInfo();
    D.Multiple(2);
    D.printInfo();
    A.Comparison(10, 2);
    std::cout << D.getErrorCode();
    std::cout << MyVector::getObjectCount();
    return 0;
}
