#ifndef FILENOTFOUNDEXCEPTION_H
#define FILENOTFOUNDEXCEPTION_H
#include <QException>

class FileNotFoundException: public QException
{
public:
    FileNotFoundException();
};

#endif // FILENOTFOUNDEXCEPTION_H
