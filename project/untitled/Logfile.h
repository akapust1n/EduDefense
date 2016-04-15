
#ifndef Logfile_h__
#define Logfile_h__

#include <fstream>
#include <string>

class Logfile
{
public:

    static Logfile& GetInstance()
    {
        static Logfile Instance("Logfile.log");
        return Instance;
    }
    ~Logfile();

    Logfile& operator<<(short rhs)
    {
        m_File << rhs;
        return *this;
    }
    Logfile& operator<<(unsigned short rhs)
    {
        m_File << rhs;
        return *this;
    }
    Logfile& operator<<(int rhs)
    {
        m_File << rhs;
        return *this;
    }
    Logfile& operator<<(unsigned int rhs)
    {
        m_File << rhs;
        return *this;
    }
    Logfile& operator<<(long rhs)
    {
        m_File << rhs;
        return *this;
    }
    Logfile& operator<<(unsigned long rhs)
    {
        m_File << rhs;
        return *this;
    }
    Logfile& operator<<(float rhs)
    {
        m_File << rhs;
        return *this;
    }
    Logfile& operator<<(double rhs)
    {
        m_File << rhs;
        return *this;
    }
    Logfile& operator<<(const char* rhs)
    {
        m_File << rhs;
        return *this;
    }
    Logfile& operator<<(const char rhs)
    {
        m_File << rhs;
        return *this;
    }
    Logfile& operator<<(const std::string& rhs)
    {
        m_File << rhs;
        return *this;
    }
    Logfile& operator<<(Logfile& (Modifier)(Logfile&))
    {
        return Modifier(*this);
    }
private:
    Logfile(const std::string LogFileName);
    std::ofstream m_File;
};


// Modifier
Logfile& Error(Logfile& Log);
Logfile& Warning(Logfile& Log);
Logfile& Info(Logfile& Log);
Logfile& NewLine(Logfile& Log);
#endif // Logfile_h__

