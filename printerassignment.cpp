// Printer Interface
class Iprinter
{
public:
    virtual void print()=0;
};

class printer: Iprinter
{
public:
    void print(){}
};

// Scanner interface
class Iscanner
{
public:
    virtual void scan()=0;
};

class scanner: Iscanner
{
public:
    void scan(){}
};

class printScanner
{
public:
    printScanner(){}
    void printManager(Iprinter *printer)
    {
        printer->print();
    }
    void scanManager(Iscanner *scanner)
    {
        scanner->scan();
    }
};