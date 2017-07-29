#pragma once

namespace plugin_natives
{
#ifdef PLUGIN_NATIVES_HAS_FUNC
	std::list<NativeFuncBase *> *
		NativeFuncBase::all_ = 0;
#endif

#ifdef PLUGIN_NATIVES_HAS_HOOK
	static bool
		gPluginNativesInit = true;

	std::list<NativeHookBase *> *
		NativeHookBase::all_ = 0;
#endif

	int AmxLoad(AMX * amx)
	{
		logprintf("AmxLoad called: %p", NativeFuncBase::all_);
		int
			ret = 0;
#ifdef PLUGIN_NATIVES_HAS_FUNC
		if (NativeFuncBase::all_)
		{
			AMX_NATIVE_INFO
				curNative[2] = { {0, 0}, {0, 0} };
			for (NativeFuncBase * curFunc : *NativeFuncBase::all_)
			{
				curNative[0].name = curFunc->name_;
				curNative[0].func = curFunc->native_;
				logprintf("%s = %p, %p", curNative[0].name, (void *)curNative[0].func, &plugin_natives::Native_SetPlayerPosAndAngle::Call);
				ret = amx_Register(amx, curNative, -1);
				logprintf("registered");
			}
		}
#endif
//#ifdef PLUGIN_NATIVES_HAS_HOOK
//		if (gPluginNativesInit)
//		{
//			gPluginNativesInit = false;
//			if (NativeHookBase::all_)
//			{
//				AMX_NATIVE
//					curNative;
//				for (NativeHookBase * curFunc : *NativeHookBase::all_)
//				{
//					Log(LogLevel::DEBUG, "Hooking function %s", curFunc->name_);
//					logprintf("Hooking function %s", curFunc->name_);
//					curNative = sampgdk_FindNative(curFunc->name_);
//					if (curNative)
//					{
//						Log(LogLevel::DEBUG, "Address %p", curNative);
//						logprintf("Address %p", curNative);
//						_sleep(1000);
//						curFunc->hook_.Install((void *)curNative, (void *)curFunc->replacement_);
//					}
//				}
//			}
//		}
//#endif
		return ret;
	}
};

