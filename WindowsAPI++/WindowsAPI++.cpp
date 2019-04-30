#include <iostream>

#include "Detail/MessageBox.h"

int main(int argc, char **argv)
{
  const char *message = "Test Message";
  const char *title = "Title?";

  WindowsAPI::MessageBox MBox(0, L"Test Message", L"Title?", WindowsAPI::MessageBox::Type::Ok);

  auto ret = MBox();

  switch (ret)
  {
    case WindowsAPI::MessageBox::Result::Ok:
    {
      std::cout << "Hit OK\n";
      break;
    }

    case WindowsAPI::MessageBox::Result::Abort:
    {
      std::cout << "Hit Abort\n";
      break;
    }

    case WindowsAPI::MessageBox::Result::Cancel:
    {
      std::cout << "Hit Cancel\n";
      break;
    }

    case WindowsAPI::MessageBox::Result::Continue:
    {
      std::cout << "Hit Continue\n";
      break;
    }

    case WindowsAPI::MessageBox::Result::Ignore:
    {
      std::cout << "Hit Ignore\n";
      break;
    }
  }

  return 0;
}
