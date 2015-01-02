#pragma once
#include "StdAfx.h"
#include "VoiceCommands.h"
#include "VoiceSynthesisTest.h"

class MyVoiceRecognition: public PXCSpeechRecognition::Handler
{
public:
	~MyVoiceRecognition(void);
	MyVoiceRecognition();//PXCSession *session=0
	virtual void PXCAPI OnRecognition(const PXCSpeechRecognition::RecognitionData *data);
	virtual void PXCAPI OnAlert(const PXCSpeechRecognition::AlertData *data);
public:
	PXCSession  *g_session;
	map<int, PXCAudioSource::DeviceInfo> g_devices;
	map<int, pxcUID> g_modules;
	/* Grammar & Vocabulary File Names */
	//pxcCHAR g_file[1024];
	//pxcCHAR v_file[1024];

	PXCSpeechRecognition *g_vrec;
	PXCAudioSource* g_source;
	PXCSpeechRecognition::ProfileInfo pinfo;
public:
	VoiceCommands voiceCmds;
	bool SetVoiceCommands(std::vector<std::wstring> &cmds);

public:
	time_t tLastTime, tCurrTime;
	//tm* local;
	tm *gmtLastTime, *gmtCurrTime;
	char buf[128];//= {0};
	//t = time(NULL);
	//local = localtime(&t);
	//gmt = gmtime(&t);

public:
	std::string commandLastTime;
	MyVoiceSynthesis speaker;
};

