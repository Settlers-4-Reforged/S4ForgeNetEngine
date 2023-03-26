#pragma once

using namespace System;
using namespace System::Runtime::InteropServices;

#pragma unmanaged
#pragma comment(lib,"Dbghelp.lib")
#include <dbghelp.h>
#include <iostream>

#define TRACE_MAX_STACK_FRAMES 1024
#define TRACE_MAX_FUNCTION_NAME_LENGTH 1024

typedef struct _STACKTRACE
{
    //
    // Number of frames in Frames array.
    //
    UINT FrameCount;

    //
    // PC-Addresses of frames. Index 0 contains the topmost frame.
    //
    ULONGLONG Frames[1000];
} STACKTRACE, * PSTACKTRACE;

//
// Disable global optimization and ignore /GS waning caused by 
// inline assembly.
//
#pragma optimize( "g", off )
#pragma warning( push )
#pragma warning( disable : 4748 )
static HRESULT CaptureStackTrace(PSTACKTRACE StackTrace) {
    DWORD MaxFrames = TRACE_MAX_STACK_FRAMES;
    DWORD MachineType;
    CONTEXT Context;
    STACKFRAME64 StackFrame;
    

    //
    // Use current context.
    //
    ZeroMemory(&Context, sizeof(CONTEXT));

    Context.ContextFlags = CONTEXT_CONTROL;
    
    __asm
    {
    Label:
        mov[Context.Ebp], ebp;
        mov[Context.Esp], esp;
        mov eax, [Label];
        mov[Context.Eip], eax;
    }


    //
    // Set up stack frame.
    //
    ZeroMemory(&StackFrame, sizeof(STACKFRAME64));
    MachineType = IMAGE_FILE_MACHINE_I386;
    StackFrame.AddrPC.Offset = Context.Eip;
    StackFrame.AddrPC.Mode = AddrModeFlat;
    StackFrame.AddrFrame.Offset = Context.Ebp;
    StackFrame.AddrFrame.Mode = AddrModeFlat;
    StackFrame.AddrStack.Offset = Context.Esp;
    StackFrame.AddrStack.Mode = AddrModeFlat;

    StackTrace->FrameCount = 0;
    SymInitialize(GetCurrentProcess(), NULL, TRUE);

    while (StackTrace->FrameCount < MaxFrames)
    {
        if (!StackWalk64(
            MachineType,
            GetCurrentProcess(),
            GetCurrentThread(),
            &StackFrame,
            &Context,
            NULL,
            SymFunctionTableAccess64,
            SymGetModuleBase64,
            NULL))
        {
            //
            // Maybe it failed, maybe we have finished walking the stack.
            //
            break;
        }

        if (StackFrame.AddrPC.Offset != 0)
        {
            //
            // Valid frame.
            //
            StackTrace->Frames[StackTrace->FrameCount++] =
                StackFrame.AddrPC.Offset;
        }
        else
        {
            //
            // Base reached.
            //
            break;
        }
    }

    return S_OK;
}
#pragma warning( pop )
#pragma optimize( "g", on )

#pragma managed


static String^ GetStackTrace() {
#ifndef PUBLIC
    String^ output = "";

    STACKTRACE stacktrace{};
    CaptureStackTrace(&stacktrace);
    auto process = GetCurrentProcess();

    char buf[sizeof(SYMBOL_INFO) + (TRACE_MAX_FUNCTION_NAME_LENGTH - 1) * sizeof(TCHAR)];
    SYMBOL_INFO* symbol = (SYMBOL_INFO*)buf;
    symbol->MaxNameLen = TRACE_MAX_FUNCTION_NAME_LENGTH;
    symbol->SizeOfStruct = sizeof(SYMBOL_INFO);

    for (unsigned int i = 6; i < stacktrace.FrameCount; i++) {
        DWORD64 address = stacktrace.Frames[i];
        SymFromAddr(process, address, nullptr, symbol);
        if (symbol->NameLen == 0) {
            output += String::Format("  ?@0x{0}\n", address.ToString("X"));
        }
        else {
            output += String::Format("  {0}@0x{1} | Ret:0x{2}\n", Marshal::PtrToStringAnsi(IntPtr(symbol->Name)), symbol->Address.ToString("X"), address.ToString("X"));
        }
    }

    return output;
#endif
}

#define LOG_CALL() LogCall(__FUNCTION__ )

static void LogCall(String^ name) {
	NetModAPI::Logger::LogInfo("Called " + name + "!");

    String^ output = "Stack Trace for " + name + ":\n";

    output += GetStackTrace();
    NetModAPI::Logger::LogInfo(output);
}

