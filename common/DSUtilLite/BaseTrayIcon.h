/*
 *      Copyright (C) 2010-2013 Hendrik Leppkes
 *      http://www.1f0.de
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#pragma once

#include <ShellAPI.h>

class CBaseTrayIcon
{
public:
  CBaseTrayIcon(IBaseFilter *pFilter, const WCHAR *wszName, int resIcon);
  void Destroy();

  static BOOL ProcessBlackList();

private:
  virtual ~CBaseTrayIcon(void);

  HRESULT StartMessageThread();
  HRESULT RegisterWindowClass();
  HRESULT CreateMessageWindow();
  HRESULT CreateTrayIconData();

  DWORD TrayMessageThread();
  static unsigned int WINAPI InitialThreadProc(LPVOID pv);

  static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

private:
  CAMEvent m_evSetupFinished;
  BOOL m_bDestroy;

  HANDLE m_hThread;
  HWND m_hWnd;
  BOOL m_bPropPageOpen;

  IBaseFilter *m_pFilter;
  const WCHAR *m_wszName;
  int m_resIcon;
  NOTIFYICONDATA m_NotifyIconData;
};
