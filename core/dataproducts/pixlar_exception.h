#ifndef __PIXLAR_EXCEPTION_H__
#define __PIXLAR_EXCEPTION_H__

#include <iostream>
#include <exception>


namespace pixevd{


  class pixlar_exception : public std::exception {
    
  public:
    
    pixlar_exception(std::string msg="") : std::exception()
    {
      _msg = "\033[93m";
      _msg += msg;
      _msg += "\033[00m";
    }

    virtual ~pixlar_exception() throw() {}
    virtual const char* what() const throw()
    { return _msg.c_str(); }

  private:
    
    std::string _msg;
  };
}

#endif