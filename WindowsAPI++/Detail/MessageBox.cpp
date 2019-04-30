////////////////////////////////////////////////////////////
//
// MIT License
//
// Copyright(c) 2019 Kurt Slagle - kurt_slagle@yahoo.com
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
// The origin of this software must not be misrepresented; you must not claim
// that you wrote the original software.If you use this software in a product,
// an acknowledgment of the software used is required.
//
////////////////////////////////////////////////////////////

#include "MessageBox.h"

#include <Windows.h>
#include "atlstr.h"

#ifdef MessageBox
#define _MESSAGE_BOX MessageBox
#undef MessageBox
#endif

namespace WindowsAPI
{

  MessageBox::MessageBox(detail::hwnd HandleToOwnerWindow, detail::lpcwstr DisplayText, detail::lpcwstr CaptionText, detail::uint BoxType)
    : m_HandleToOwnerWindow(HandleToOwnerWindow)
    , m_Message(DisplayText)
    , m_Caption(CaptionText)
    , m_Type(BoxType)
  {
  }

  //MessageBox::MessageBox(const MessageBox &Other)
  //{
  //}

  //MessageBox::MessageBox(MessageBox &&Other)
  //{
  //}

  //MessageBox &MessageBox::operator=(const MessageBox &Other)
  //{
  //  // TODO: insert return statement here
  //}

  //MessageBox &MessageBox::operator=(MessageBox &&Other)
  //{
  //  // TODO: insert return statement here
  //}

  MessageBox::~MessageBox()
  {
  }

  MessageBox::Result MessageBox::operator()() const
  {
    const auto ret = MessageBoxW((HWND) m_HandleToOwnerWindow, (LPCWSTR) m_Message, (LPCWSTR) m_Caption, (UINT) m_Type);

    switch (ret)
    {
      case IDABORT:
        return Result::Abort;
      case IDCANCEL:
        return Result::Cancel;
      case IDCONTINUE:
        return Result::Continue;
      case IDIGNORE:
        return Result::Ignore;
      case IDNO:
        return Result::No;
      case IDOK:
        return Result::Ok;
      case IDRETRY:
        return Result::Retry;
      case IDTRYAGAIN:
        return Result::TryAgain;
      case IDYES:
        return Result::Yes;
    }
  }

}
