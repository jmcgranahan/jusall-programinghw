///----------------------------------------------------------------------------
///
///   Copyright (c) 2007-2008, AOL LLC 

///   All rights reserved.

///   Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

///   Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer. 
///   Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution. 
///   Neither the name of the AOL LLC nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission. 
///   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
///   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
///   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
///   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
///   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
///   EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
///   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
///   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
///   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
///   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
///   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
///
///----------------------------------------------------------------------------

#include "StdAfx.h" // standard AIMCC includes
#include "Client.h" // AIM bot base class

CClient::CClient() 
{    
}

HRESULT CClient::Start(const COptionsMap& args)
{
    CAccBstr userName(args.Username());    
    CAccBstr password(args.Password());    
    if (userName.Length() == 0 || password.Length() == 0)
        return E_INVALIDARG;      

    // create and init session
    CAccPtr<IAccClientInfo> spiClientInfo;
    ACC_TRY_HR(AccCreateSession(IID_IAccSession, (void**)&m_spiSession));
    ACC_TRY_HR(Advise(m_spiSession));
    ACC_TRY_HR(m_spiSession->get_ClientInfo(&spiClientInfo));
    ACC_TRY_HR(spiClientInfo->put_Property(AccClientInfoProp_Description,
        CAccVariant("accbot (key=ju1O5ulaJDJANv8B)")));    
    ACC_TRY_HR(m_spiSession->put_Identity(userName));        

    // disable idle
    AIMCC::put_SecondsOfInactivityBeforeIdleState(m_spiSession, INT_MAX);        
    // disable plugins
    AIMCC::put_Plugins(m_spiSession, NULL);
    return m_spiSession->SignOn(password);
}

void CClient::OnStateChange(IAccSession*, AccSessionState state, AccResult hr)
{
    // Tell the operator what is happening
    switch (state)
    {
    case AccSessionState_Disconnected:
        printf("accbot disconnected, reconnecting...\n");
        break;
    case AccSessionState_Connecting:
        printf("accbot connecting...\n");
        break;
    case AccSessionState_SecurId:
    case AccSessionState_SecurIdNextKey:
        printf("accbot does not support securid.\n");
        m_spiSession->SetSecurIdKey(NULL);
        break;
    case AccSessionState_Online:                    
        printf("accbot online and ready.\n");
        break;
    case AccSessionState_Offline:        
        Unadvise(m_spiSession);
        AccPostQuit(hr);
        printf("accbot offline, qutting.\n");
        break;
    }
}

void CClient::OnSecondarySessionStateChange(IAccSession*,
                                            IAccSecondarySession* piSecSession, 
                                            AccSecondarySessionState state,
                                            AccResult)
{    
    // Only accept "normal" IM sessions, reject all others
    if (state == AccSecondarySessionState_ReceivedProposal)
    {
        AccSecondarySessionServiceId id;
        piSecSession->get_ServiceId(&id);
        if (id == AccSecondarySessionServiceId_Im)
        {
            AccImSessionType type;
            CAccPtr<IAccImSession> spiImSession(piSecSession);
            AIMCC::get_SessionType(spiImSession, &type);
            if (type == AccImSessionType_Im)
                piSecSession->Accept();
            else
                piSecSession->Reject();
        }
        else 
            piSecSession->Reject();
    }
}

void CClient::OnImReceived(IAccSession*, IAccImSession* piImSession, 
                           IAccParticipant*, IAccIm* piIm)
{
    // Send the IM to the handler
    CAccBstr plainIn, plainOut;
    CAccPtr<IAccIm> spiResponse;
    if (SUCCEEDED(piIm->GetConvertedText(OLESTR("text/plain"), &plainIn)) &&
        SUCCEEDED(m_spiSession->CreateIm(NULL, OLESTR("text/plain"), &spiResponse)) &&
        SUCCEEDED(HandleIm(plainIn, plainOut)) &&
        SUCCEEDED(spiResponse->put_Text(plainOut)))
        piImSession->SendIm(spiResponse);        
}

// ****************************************************************************
//  COptionsMap implementation

HRESULT COptionsMap::Init(xp_int argc, const char* argv[])
{
    // parse options into name-value pairs
    // right now options must be space-separated; this could be enhanced
    enum State { kOpts, kUserName, kPassword, kDone } state = kOpts;
    for (xp_int i = 1; i < argc; i++)
    {
        const char* cur = argv[i];
        switch (state)
        {
        case kOpts:
            if (cur[0] == '-')
            {
                if (strcmp(cur, "--") == 0) // end of opts
                    state = kUserName;
                /*
                else if (i + 1 < argc)
                {
                    SetAt(cur, TBstr(argv[++i]));
                }
                */
                break;
            }
        // else fall through
        case kUserName:
            m_userName = cur;
            state = kPassword;
            break;
        case kPassword:
            m_password = cur;
            state = kDone;
            break;        
        }
    }

    return S_OK;
}
