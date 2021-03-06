#include <iostream>
#include <string>
#include <glog/logging.h>
#include "HelloPython.h"

void ExcutePyRun()
{
    HelloPython pyobj("../script", "HelloPython");
    PyErr ret = pyobj.Create();
    if (ret != PY_SUCCESS)
    {
        LOG(WARNING) << "create: " << ret << std::endl;
    }
        
    pyobj.Hello(ret);
    if (ret != PY_SUCCESS)
    {
        LOG(WARNING) << "Hello Fail: " << ret << std::endl;
    }

    int number = pyobj.Fib(6, ret);
    if (ret != PY_SUCCESS)
    {
        LOG(WARNING) << "Fib Fail: " << ret << std::endl;
    }
    else
    {
        LOG(INFO) << "Fib number: " << number << std::endl;
    }
    
    pyobj.Delete();
}

int main(int argc, char** argv)
{
    ExcutePyRun();
    return 0;
}