#pragma once

#undef  SetPlayerPos
HOOK_DEFN(SetPlayerPos, bool(int playerid, float x, float y, float z));
#define BAD_SetPlayerPos *SetPlayerPos

/*namespace samp_natives
{
	extern "C" __declspec(dllexport) bool
		NATIVE_SetPlayerPos(int playerid, float x, float y, float z);

	extern class Native_SetPlayerPos : public NativeHook<bool(int playerid, float x, float y, float z)>
	{
	public:
		Native_SetPlayerPos()
			:
			NativeHook<bool(int playerid, float x, float y, float z)>("SetPlayerPos", &sampgdk_SetPlayerPos, &Call)
		{}

		using NativeHookBase::IsEnabled;

	private:
		friend bool
			NATIVE_SetPlayerPos(int playerid, float x, float y, float z);

		static cell
			Call(AMX * amx, cell * params)
		{
			return ::samp_natives::SetPlayerPos.CallDoOuter(amx, params);
		}

		bool Do(int playerid, float x, float y, float z) const;
	} SetPlayerPos;

	extern "C" __declspec(dllexport) bool
		NATIVE_SetPlayerPos(
			typename ::samp_natives::TypeResolver<void(int playerid)>::type p3,
			typename ::samp_natives::TypeResolver<void(float x)>::type p2,
			typename ::samp_natives::TypeResolver<void(float y)>::type p1,
			typename ::samp_natives::TypeResolver<void(float z)>::type p0)
	{
		#pragma comment(linker, "/EXPORT:SetPlayerPos=hi")
		return ::samp_natives::SetPlayerPos.Do(p3, p2, p1, p0);
	}
};*/

