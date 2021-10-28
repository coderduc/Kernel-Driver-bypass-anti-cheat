#pragma warning(disable: 4311 4459 4047)
#include "events.h"
#include "message.h"
#include "define.h"
PLOAD_IMAGE_NOTIFY_ROUTINE ImageLoadCallback(PUNICODE_STRING FullImageName, HANDLE ProcessId, PIMAGE_INFO ImageInfo) {
	if (wcsstr(FullImageName->Buffer, L"\\VALORANT-Win64-Shipping.exe")) {
		DebugMessage("Game Process Found !!!");
		GameBaseAddress = ImageInfo->ImageBase;
		ProcessID = (ULONG)ProcessId;
		DebugMessage("Game Base: %p \n",GameBaseAddress);
		DebugMessage("Process ID: %d \n", ProcessId);
	}
	return STATUS_SUCCESS;
}
