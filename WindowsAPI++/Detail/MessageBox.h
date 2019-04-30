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

#pragma once

#include "Types.h"
#include "WindowsAPIBase.h"

#include <memory>

namespace WindowsAPI
{

  /*
    Message Boxes
  */

  class MessageBox : public APIBase
  {
  public:

    enum Type : detail::uint
    {
      AbortRetryIgnore = 0x00000002L,
      CancelTryIgnore  = 0x00000006L,
      Help             = 0x00004000L,
      Ok               = 0x00000000L,
      OkCancel         = 0x00000001L,
      RetryCancel      = 0x00000005L,
      YesNo            = 0x00000004L,
      YesNoCancel      = 0x00000003L
    };

    enum Icon : detail::uint
    {
      Exclamation = 0x00000030L,
      Warning     = 0x00000030L,
      Information = 0x00000040L,
      Asterisk    = 0x00000040L,
      Question    = 0x00000020L,
      Stop        = 0x00000010L,
      Error       = 0x00000010L,
      Hand        = 0x00000010L
    };

    enum DefaultButton : detail::uint
    {
      Button1 = 0x00000000L,
      Button2 = 0x00000100L,
      Button3 = 0x00000200L,
      Button4 = 0x00000300L
    };

    enum Modality : detail::uint
    {
      AppModal    = 0x00000000L,
      SystemModal = 0x00001000L,
      TaskModal   = 0x00002000L
    };

    enum Options : detail::uint
    {
      DefaultDesktopOnly  = 0x00020000L,
      Right               = 0x00080000L,
      RightToLeftReading  = 0x00100000L,
      SetForeground       = 0x00010000L,
      TopMost             = 0x00040000L,
      ServiceNotification = 0x00200000L
    };

    enum class Result : int
    {
      Abort    = 3,
      Cancel   = 2,
      Continue = 11,
      Ignore   = 5,
      No       = 7,
      Ok       = 1,
      Retry    = 4,
      TryAgain = 10,
      Yes      = 6
    };

    MessageBox(detail::hwnd HandleToOwnerWindow = detail::null, detail::lpcwstr DisplayText = nullptr, detail::lpcwstr CaptionText = nullptr, detail::uint BoxType = Type::Ok);
    //MessageBox(const MessageBox &Other);
    //MessageBox(MessageBox &&Other);
    //MessageBox &operator =(const MessageBox &Other);
    //MessageBox &operator =(MessageBox &&Other);
    ~MessageBox() override final;

    Result operator()() const;

  private:

    detail::hwnd m_HandleToOwnerWindow;
    detail::lpcwstr m_Message;
    detail::lpcwstr m_Caption;
    detail::uint m_Type;

  };

}
