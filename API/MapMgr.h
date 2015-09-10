#pragma once

#include <Windows.h>
#include "GWAPIMgr.h"


namespace GWAPI{
	class MapMgr{
		GWAPIMgr* parent;
		friend class GWAPIMgr;
		struct PAB_ZoneMap {
			const DWORD header = 0xAB;
			DWORD mapid;
			int region;
			int district;
			int language;
			DWORD unk;
		};

		MapMgr(GWAPIMgr* obj);
	public:

		
		// Get current map ID.
		DWORD GetMapID();

		// Get current region you are in.
		inline int GetRegion() { return *(int*)(MemoryMgr::MapInfoPtr + 0x10); }

		// Get current language you are in.
		inline int GetLanguage() { return *(int*)(MemoryMgr::MapInfoPtr + 0xC); }

		// Get time, in ms, since the instance you are residing in has been created.
		DWORD GetInstanceTime();

		// Get the instance type (Outpost, Explorable or Loading)
		GwConstants::InstanceType GetInstanceType();

		// Travel to specified outpost.
		void Travel(DWORD MapID, DWORD District = 0, int Region = 0, DWORD Language = 0);


	};
}