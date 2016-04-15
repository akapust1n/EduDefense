#include "Logfile.h"
//#include "Exception.h"
using namespace  std;

Logfile::Logfile( const std::string LogFileName )
{
   // m_File.open(open(LogFileName));
  /*  if (!m_File)
    {
        THROW_EXCEPTION("Die Logfiledatei konnte nicht erstellt oder ge�ffnet werden!")
    }*/
}

Logfile::~Logfile()
{
    m_File.close();
}

// Modifier
Logfile& Error(Logfile& Log)
{
    return Log << "FEHLER: ";
}

Logfile& Warning( Logfile& Log )
{
    return Log << "WARNUNG: ";
}

Logfile& Info( Logfile& Log )
{
    return Log << "INFO: ";
}

Logfile& NewLine( Logfile& Log )
{
    return Log << "\n";
}

