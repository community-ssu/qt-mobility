/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the Qt Mobility Components.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial Usage
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Solutions Commercial License Agreement provided
** with the Software or, alternatively, in accordance with the terms
** contained in a written agreement between you and Nokia.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
** Please note Third Party Software included with Qt Solutions may impose
** additional restrictions and it is the user's responsibility to ensure
** that they have met the licensing requirements of the GPL, LGPL, or Qt
** Solutions Commercial license and the relevant license of the Third
** Party Software they are using.
**
** If you are unsure which license is appropriate for your use, please
** contact the sales department at qt-sales@nokia.com.
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef DIRECTSHOWIOREADER_H
#define DIRECTSHOWIOREADER_H

#include <QtCore/qmutex.h>
#include <QtCore/qobject.h>
#include <QtCore/qwaitcondition.h>

#include <dshow.h>

QT_BEGIN_NAMESPACE
class QIODevice;
QT_END_NAMESPACE

class DirectShowEventLoop;
class DirectShowIOSource;
class DirectShowSampleRequest;

class DirectShowIOReader : public QObject, public IAsyncReader
{
    Q_OBJECT
public:
    DirectShowIOReader(QIODevice *device, DirectShowIOSource *source, DirectShowEventLoop *loop);
    ~DirectShowIOReader();

    // IUnknown
    HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppvObject);
    ULONG STDMETHODCALLTYPE AddRef();
    ULONG STDMETHODCALLTYPE Release();

    // IAsyncReader
    HRESULT STDMETHODCALLTYPE RequestAllocator(
            IMemAllocator *pPreferred, ALLOCATOR_PROPERTIES *pProps, IMemAllocator **ppActual);

    HRESULT STDMETHODCALLTYPE Request(IMediaSample *pSample, DWORD_PTR dwUser);

    HRESULT STDMETHODCALLTYPE WaitForNext(
            DWORD dwTimeout, IMediaSample **ppSample, DWORD_PTR *pdwUser);

    HRESULT STDMETHODCALLTYPE SyncReadAligned(IMediaSample *pSample);

    HRESULT STDMETHODCALLTYPE SyncRead(LONGLONG llPosition, LONG lLength, BYTE *pBuffer);

    HRESULT STDMETHODCALLTYPE Length(LONGLONG *pTotal, LONGLONG *pAvailable);

    HRESULT STDMETHODCALLTYPE BeginFlush();
    HRESULT STDMETHODCALLTYPE EndFlush();

protected:
    void customEvent(QEvent *event);

private Q_SLOTS:
    void readyRead();

private:
    HRESULT blockingRead(LONGLONG position, LONG length, BYTE *buffer, qint64 *bytesRead);
    bool nonBlockingRead(
            LONGLONG position, LONG length, BYTE *buffer, qint64 *bytesRead, HRESULT *result);
    void flushRequests();

    DirectShowIOSource *m_source;
    QIODevice *m_device;
    DirectShowEventLoop *m_loop;
    DirectShowSampleRequest *m_pendingHead;
    DirectShowSampleRequest *m_pendingTail;
    DirectShowSampleRequest *m_readyHead;
    DirectShowSampleRequest *m_readyTail;
    LONGLONG m_synchronousPosition;
    LONG m_synchronousLength;
    qint64 m_synchronousBytesRead;
    BYTE *m_synchronousBuffer;
    HRESULT m_synchronousResult;
    LONGLONG m_totalLength;
    LONGLONG m_availableLength;
    bool m_flushing;
    QMutex m_mutex;
    QWaitCondition m_wait;
};

#endif
