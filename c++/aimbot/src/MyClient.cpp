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

#include "StdAfx.h"
#include "MyClient.h"
#include <time.h>
#ifdef WIN32
#define snprintf _snprintf
#endif

CMyClient::CMyClient() : m_plays(0), m_wins(0)
{
    // seed the PRNG so that we're not (too) predictable
    srand(time(NULL));
}

HRESULT CMyClient::HandleIm(const CAccBstr& in, CAccBstr& out)
{   
    enum ERps { kBad = -1, kRock, kPaper, kScissors };
    const char* kRpsStrings[] = { "Rock", "Paper", "Scissors" };    
    const char* kRpsResults[] = { "We tied.", "I win!", "You win!" };
	int you2;
    // Figure out what we both picked.
    ERps me = (ERps)(rand() % 3), you = kBad;    
    if (in[0] == 'r' || in[0] == 'R')
        you = kRock;
    else if (in[0] == 'p' || in[0] == 'P')
        you = kPaper;
    else if (in[0] == 's' || in[0] == 'S')
        you = kScissors;
	else if (in[0] == 'l')
		you2 = 1;

    // See who won, and send the appropriate response.
    char buf[4096] = "";
    if (you != kBad)
    {
        m_plays++;
        int n = ((int)me - (int)you + 3) % 3;
        if (n == 1)
            m_wins++;
        snprintf(buf, xp_countof(buf), 
            "You picked %s. I picked %s. %s\r\nI have won %d out of %d games (%.02f%%).",
            kRpsStrings[you], kRpsStrings[me], kRpsResults[n],
            m_wins, m_plays, (double)m_wins/(double)m_plays*100);
    }
	else if ( you2 == 1)
	{
		snprintf(buf, xp_countof(buf), "hey sexy");
	}
    else
    {
        snprintf(buf, xp_countof(buf), "Hi! Would you like to play \"Rock, Paper, Scissors\"?\r\n"
            "Type \"rock\", \"paper\", or \"scissors\" to start playing bitch");
    }
    
    out = buf;
    return S_OK;
}
