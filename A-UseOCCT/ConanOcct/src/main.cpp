#include <iostream>

#include <Standard_CString.hxx>

int main(void)
{
   Standard_CString strHelloWorld("Hello World!");
   Standard_CString strHelloOcct("Hello OpenCascade!");

   std::cout << strHelloWorld << std::endl;
   std::cout << strHelloOcct << std::endl;
   
   return 0;
}