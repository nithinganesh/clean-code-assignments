// C++ style implemnetation
#include <iostream>
using namespace std;

// Printer Interface
class Iprinter
{
public:
    virtual void print()=0;
};

class printer: public Iprinter
{
public:
    virtual void print()
    {
        std::cout<<"Printing..." << std::endl;
        std::cout<<"Complete" << std::endl;
    }
};

// Scanner interface
class Iscanner
{
public:
    virtual void scan()=0;
};

class scanner: public Iscanner
{
public:
    virtual void scan()
    {
        std::cout<<"Scanning..." << std::endl;
        std::cout<<"Complete" << std::endl;
    }
};

class printScanner
{
    Iprinter *print_obj_;
    Iscanner *scan_obj_;
public:
    printScanner(Iprinter *print_obj, Iscanner *scan_obj): print_obj_(print_obj),scan_obj_(scan_obj){}

    void printManager()
    {
        print_obj_->print();
    }
    void scanManager()
    {
        scan_obj_->scan();
    }
};

int main(){
    printScanner obj(new printer(),new scanner());
    obj.printManager();
    obj.scanManager();
    return 0;
}

// C style implementation
typedef void (*print_fp)();
typedef bool (*scan_fp)();
void printer()
{
    printf("Printing...\n");
    printf("Complete\n");
}

bool scanner()
{
    printf("Scanning...\n");
    printf("Complete\n");
    return true;
}

void printManager(print_fp fp)
{
    fp();
}

void scanManager(scan_fp fp)
{
    fp();
}

int main()
{
    printManager(printer);
    scanManager(scanner);
    return 0;
}