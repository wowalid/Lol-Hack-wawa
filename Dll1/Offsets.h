#pragma once
#include <Windows.h>
#include "Object.h"
#include "Player.h"
#include "D3DVECTOR.h"
class Offsets
{
public:

	DWORD base = (DWORD)GetModuleHandle(NULL);
	
	//Offsets
	DWORD oLocalPlayer = base + 0x2DB2160;
	DWORD ObjManager = base + 0x2dac858;
	DWORD oChatClientPtr = base + 0x31B7C98;
	DWORD oGameTime = base + 0x31A6D24;
	DWORD oRenderer = base + 0x31D4AA0;
	DWORD oZoomBase = base + 0x31A6C80;
	DWORD oUnderMouseObj = base + 0x25506FC;
	DWORD oNetClient = base + 0x31B221C;
	DWORD oMissionInfo = base + 0x31E3AEC;
	DWORD oGameState = base + 0x31A7524;
	DWORD oVersion = base + 0x31B5CB0;
	DWORD oMousePointer = base + 0x1502754;
	DWORD oTexturePack = base + 0x31B2E18;


	//Conventions
	typedef float(__fastcall* fnGetBoundingRadius)(Object* thisPtr, double* result);
	typedef int(__thiscall* fnGetHPBarV3D)(Object* pObj, D3DVECTOR* pVec);
	typedef bool(__cdecl* fnWorld2Screen)(D3DVECTOR* vIn, D3DVECTOR* vOut);
	typedef int(__cdecl* fnScreen2World)(float a1, float a2, D3DVECTOR* vIn, D3DVECTOR* vOut);
	typedef bool(__thiscall* fnWorld2Map)(void* thisPtr, D3DVECTOR* vIn, float *fXOut, float *fYOut);
	typedef int(__thiscall* fnMap2World)(void* thisPtr, unsigned int a2, int a3, int a4, int *a5);
	typedef void*(__cdecl* fnGetTacticalMap)();
	typedef char(__stdcall* fnUseObject)(Object* pObj);
	typedef bool(__cdecl* fnIsWall)(D3DVECTOR* position, unsigned __int16 uk);
	//typedef cTexturePTR(__thiscall* fnLoadTexture)(DWORD *rendererPtr, std::string* strTextureFileName, DWORD* dwSharedMemory, int a4, int a5, int a6);
	typedef char(__thiscall* fnPrintChat)(DWORD* ChatClientPtr, const char* cMessage, unsigned int iColor);
	typedef int(__thiscall* fnSendChat)(DWORD* ChatClientPtr, char* a2);
	typedef void(__thiscall* fnIssueOrder) (Object* thisPtr, DWORD dwOrder, D3DVECTOR* TargetPos, Object* TargetPtr, bool attackLoc, bool isPassive, DWORD isNetworked); // 2 = move 
	typedef char(__thiscall* fnDrawTurretRange) (Object* objPtr);
	typedef void(__thiscall* fnDrawHUD) (int a1);
	typedef int(__thiscall* fnOnAFK)(BYTE* thisPtr);
	typedef int(__thiscall* fnLevelUp)(void* thisPtr, float a2, signed int nLevel, int a4);
	typedef int(__thiscall* fnOnTeleport) (Object* thisPtr, std::string* a1, std::string* a2);
	typedef char(__thiscall* fnOnSurrenderVote)(void* thisPtr, int nNetworkID, int nSurrenderType, char a4, char a5);
	typedef int(__thiscall* fnAssignNetworkID)(Object* thisPtr, int nNetworkID);
	typedef int(__thiscall* fnDeleteObject)(void* thisPtr, Object* pObject);
	//typedef char(__thiscall* fnOnProcessSpellW)(void* spellbookPtr, LoLCore::CSpellCastInfo* pSpellInfo);
	//typedef void(__thiscall* fnUpdateChargeableSpell)(void* spellbookPtr, SpellInfo* pSpellInfo, signed int spell_slot, Vector3D* vPos, bool ReleaseCast);e
	typedef int(__cdecl* fnOnLoadChampion)(const char *player_name, const char *champion_name, unsigned int skin_id, int a4, int a5, int a6, int a7, int a8, int a9);
	//typedef void(__thiscall* fnCastSpell)(void* spellbook, SpellInfo* a2, signed int spell_slot, Vector3D* target_position, Vector3D* startPos, int target_network_id);
	typedef signed int(__thiscall* fnGetSpellState)(void *spellbook, signed int spellslot, DWORD *a3);
	typedef float(__cdecl* fnGetAttackCastDelay)(Object* pObj, int index);
	typedef float(__cdecl* fnGetAttackDelay)(Object* pObj, int index);
	typedef char(__stdcall* fnDoEmote)(unsigned __int8 nId);
	//typedef void(__cdecl* fnDrawCircle) (Vector3D* a1, float a2, D3DCOLOR* a3, int a4, float a5, int a6, float a7);
	//typedef void(__cdecl* fnDrawCircleIndicator) (D3DCOLOR* a1, Vector3D* a2, float a3, cTexturePTR a4, float a5, float a6, int a7);
	//typedef uint8_t(__stdcall* fnOnProcessPacket)(GameNetPacket* packetPtr);
	//typedef int(__cdecl* fnOnProcessSpell)(void* spellbookPtr, signed int spellslot, int a3, SpellData* pSpellData, char IsBasicAttack, char a6);
	//typedef char(__thiscall* fnEventHandler) (void* thisPtr, event_t * pEvent, IEventArgs& pArgs);
	typedef int(__thiscall* fnPlaySound)(void *thisPtr, int a2, int a3, std::string const & soundFile, int a5, int a6, float fVolume, int IEventFinishedCallback);
	typedef int(__thiscall* fnSetPath)(void* thisPtr, int a2);
	typedef int(__cdecl* fnApplySkin) (int a1, const char *a2, const char *a3, int a4, int a5, int a6, int a7, int a8, int a9);
	typedef int(__cdecl* fnFloatingText) (int a1, int a2, int a3, int a4, char a5);
	//D3D
	/*typedef HRESULT(WINAPI* fnD3DPresent)(LPDIRECT3DDEVICE9 pDevice, CONST RECT *pSourceRect, CONST RECT *pDestRect, HWND hDestWindowOverride, CONST RGNDATA *pDR);
	typedef HRESULT(WINAPI* fnD3DBeginScene)(LPDIRECT3DDEVICE9 pDevice);
	typedef HRESULT(WINAPI* fnD3DEndScene)(LPDIRECT3DDEVICE9 pDevice);
	typedef HRESULT(WINAPI* fnD3DReset)(LPDIRECT3DDEVICE9 pDevice, D3DPRESENT_PARAMETERS* Para1);*/

	//Fonctions
	//fnW2S fnW2S = (fnW2S)(base + 0xBC6570);
	//fnS2W fnS2W = (fnS2W)(base + 0xBC6650);
	//fnM2W fnM2W = (fnM2W)(base + 0xA11800);
	//fnTM fnTM = (fnTM)(base + 0x5C0AF0);
	//fnLoadTexture fnLoadTexture = (fnLoadTexture)(base + 0xBBF6F0);
	//fnUpdateBuff fnUpdateBuff = (fnUpdateBuff)(base + 0x8EA620);
	//fnEventHandler fnEventHandler = (fnEventHandler)(base + 0x639030);
	//fnDispatchEvent fnDispatchEvent = (fnDispatchEvent)(base + 0x6ADCB0);
	//fnOnProcessPacket fnOnProcessPacket = (fnOnProcessPacket)(base + 0x764AC0);
	//fnOnLoadHero fnOnLoadHero = (fnOnLoadHero)(base + 0x770640);
	fnOnLoadChampion tOnLoadChampion = (fnOnLoadChampion)(base + 0x5B63E0);
	fnOnTeleport tOnTeleport = (fnOnTeleport)(base + 0x5DE7B0);
	fnSendChat tSendChat = (fnSendChat)(base + 0xA03FA0);
	//fnOpenChat fnOpenChat = (fnOpenChat)(base + 0x95DE00);
	//fnDisplayChat fnDisplayChat = (fnDisplayChat)(base + 0x94AC50);
	//fnSetChatScale fnSetChatScale = (fnSetChatScale)(base + 0x95B4D0);
	//fnOnDisconnect fnOnDisconnect = (fnOnDisconnect)(base + 0x9C6030);
	//fnOnAfk fnOnAfk = (fnOnAfk)(base + 0x9C6380);
	//fnSmartPing fnSmartPing = (fnSmartPing)(base + 0xA3DFC0);
	//fnGameUpdate fnGameUpdate = (fnGameUpdate)(base + 0x7053F0);
	//fnClientMain fnClientMain = (fnClientMain)(base + 0x680EF0);
	fnPlaySound tPlaySound = (fnPlaySound)(base + 0x66A6B0);
	fnIssueOrder tIssueOrder = (fnIssueOrder)(base + 0x1C1AE0);
	//fnHealthBarPos fnHealthBarPos = (fnHealthBarPos)(base + 0x5BA900);
	fnGetAttackDelay tGetAttackDelay = (fnGetAttackDelay)(base + 0x534040);
	fnGetAttackCastDelay tGetAttackCastDelay = (fnGetAttackCastDelay)(base + 0x5340A0);
	//fnGetBasicAttack fnGetBasicAttack = (fnGetBasicAttack)(base + 0x5B97C0);
	fnGetBoundingRadius tGetBoundingRadius = (fnGetBoundingRadius)(base + 0x5EE1C0);
	//fnAddRemoveBuff fnAddRemoveBuff = (fnAddRemoveBuff)(base + 0x910570);
	fnLevelUp tLevelUp = (fnLevelUp)(base + 0x61E920);
	//fnCreateObject fnCreateObject = (fnCreateObject)(base + 0x6DB620);
	fnAssignNetworkID tAssignNetworkID = (fnAssignNetworkID)(base + 0x6D63A0);
	//fnIdentifyObject fnIdentifyObject = (fnIdentifyObject)(base + 0x611A20);
	fnApplySkin tApplySkin = (fnApplySkin)(base + 0x5FE2D0);
	fnDeleteObject tDeleteObject = (fnDeleteObject)(base + 0x6CAC80);
	fnSetPath tSetPath = (fnSetPath)(base + 0x60C760);
	//fnCreatePath fnCreatePath = (fnCreatePath)(base + 0x8D80E0);
	//fnIsWallOfGrass fnIsWallOfGrass = (fnIsWallOfGrass)(base + 0x8E5530);
	//fnDoMasteryBadge fnDoMasteryBadge = (fnDoMasteryBadge)(base + 0x9486C0);
	fnOnSurrenderVote tOnSurrenderVote = (fnOnSurrenderVote)(base + 0xA06090);
	//fnLevelUpSpell fnLevelUpSpell = (fnLevelUpSpell)(base + 0x9231E0);
	//fnCastSpell fnCastSpell = (fnCastSpell)(base + 0x920180);
	//fnUpdChargeableSpell fnUpdChargeableSpell = (fnUpdChargeableSpell)(base + 0x9229E0);
	fnGetSpellState tGetSpellState = (fnGetSpellState)(base + 0x916220);
	//fnApplySpellCD fnApplySpellCD = (fnApplySpellCD)(base + 0x918780);
	//fnOnProcessSpellW fnOnProcessSpellW = (fnOnProcessSpellW)(base + 0x9312F0);
	//fnStopCast fnStopCast = (fnStopCast)(base + 0x9313F0);
	fnDrawTurretRange tDrawTurretRange = (fnDrawTurretRange)(base + 0x5FB3D0);
	//fnDrawCircle fnDrawCircle = (fnDrawCircle)(base + 0x92C070);
	fnFloatingText tFloatingText = (fnFloatingText)(base + 0x569590);
	fnDrawHUD tDrawHUD = (fnDrawHUD)(base + 0x99A360);

};

