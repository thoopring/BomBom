//---------------------------------------------------------------------------

#pragma hdrstop

#include "CPstock.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
// Global Variable
//---------------------------------------------------------------------------
int global;
//CLSlog Log("THR_TEST1","D:\\work\\Builder\\Berlin\\01.Study PJT\\bin\\log");
//CLSlog Log("THR_TEST1","..\\bin\\log");
extern CLSlog Log;
CPstock *Pstock;
//---------------------------------------------------------------------------
// Constuctor
//---------------------------------------------------------------------------
CPstock::CPstock(void)
{
	Log.Write("CPstock start");
}
//---------------------------------------------------------------------------
CPstock::CPstock(const char *ipAddr, int port)
{
	Log.Write("CPstock start");
	m_tcpClinet = new CLSstockIF("STOCKTCP",port, ipAddr, TCP_CLIENT);
	InitEnv();  //작업환경 초기화
//	m_thr = new THRclient(m_tcpClinet);
//	Log.Write("Main Loop Start");
//
//	m_thr->start();
	MainLoop();
}
//---------------------------------------------------------------------------
// ~CPstock
//---------------------------------------------------------------------------
CPstock::~CPstock(void)
{
	//
}
//---------------------------------------------------------------------------
// InitNetwork
//---------------------------------------------------------------------------
bool __fastcall CPstock::InitNetwork()
{
	//open client socket
	if(!m_tcpClinet->Open())
		return (false);

	return (true);
}
//---------------------------------------------------------------------------
// InitEnv
//---------------------------------------------------------------------------
bool __fastcall CPstock::InitEnv()
{
    //Network 초기화
	if(!InitNetwork())
	{
		return (false);
	}
}
//---------------------------------------------------------------------------
// ClearEnv
//---------------------------------------------------------------------------
void __fastcall CPstock::ClearEnv()
{

}
//---------------------------------------------------------------------------
// ManageThread
//---------------------------------------------------------------------------
void __fastcall CPstock::ManageThread()
{

}
//---------------------------------------------------------------------------
// GetTcpStatus
//---------------------------------------------------------------------------
bool __fastcall CPstock::GetTcpStatus()
{
	return (m_tcpClinet->Connected);
}
//---------------------------------------------------------------------------
// GetCommStatus
//---------------------------------------------------------------------------
bool __fastcall CPstock::GetCommStatus()
{
	return (m_tcpClinet->Connected);
}
//---------------------------------------------------------------------------
// MainLoop
//---------------------------------------------------------------------------
int __fastcall CPstock::MainLoop()
{
	m_thr = new THRclient(m_tcpClinet);
	Log.Write("Main Loop Start");

	m_thr->start();
}
//---------------------------------------------------------------------------
// SendEcho
//---------------------------------------------------------------------------
bool __fastcall CPstock::SendEcho(char *str)
{
    return (m_tcpClinet->SendEcho(str));
}
