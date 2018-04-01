#pragma once
#include <iostream>
#include "String.h"
#include "Memory.h"
class cString
{
public:
	char *getString()
	{
		if (this->m_iLen > 15)
			return (this->m_szString);

		return (this->m_caString);
	}

private:
	union
	{
		struct
		{
			/* 0x00000000 */ char m_caString[0x10];
		};

		struct
		{
			/* 0x00000000 */ char *m_szString;
			/* 0x00000004 */ char m_notUse[0x0C];
		};
	};

	/* 0x00000010 */ int m_iLen;
	/* 0x00000014 */ int m_iMax;
};

class ObjectType {
public :
	int Type;
};

class Object
{
public:

	unsigned char Padding[0x4];
	ObjectType* Type;
	int Index;
	unsigned char Padding34[0x8];
	int Team; // 100 = allies , 200 = ennemies , 300 = neutre
	int Champion;
	unsigned char Padding35[0x4];
	cString Name;
	unsigned char Padding0[0xC8];
	float X; //0x100
	float Y; 
	float Z; 
	unsigned char Padding2[0x56C];
	float mHP;
	unsigned char Padding3[0x42C];
	float AttackRange; //0xAA8
	unsigned char Padding4[0x474];
	float mAttackSpeedMod; // 0xF20
	bool isMinion() {
		if (Team == 200 && Type->Type == 5) {
			return true;
		}
		return false;
	}
	
	/*
	unsigned char Padding0[0x20]; // 0x00

	//int Champion; // 0x18
	//unsigned char Padding1000[0x02];
	String Name; //0x20
	unsigned char Padding1[0x2B0]; // 0x1C
	float mPAR; // 0x2CC
	unsigned char Padding2[0x0C]; // 0x2D0
	float mMaxPAR; // 0x2DC
	unsigned char Padding3[0x0C]; // 0x2E0
	bool mPAREnabled; // 0x2EC
	unsigned char Padding4[0x1F]; // 0x2ED
	int mPARState; // 0x30C
	unsigned char Padding5[0x1C]; // 0x310
	float mSAR; // 0x32C
	unsigned char Padding6[0x0C]; // 0x330
	float mMaxSAR; // 0x33C
	unsigned char Padding7[0x0C]; // 0x340
	bool mSAREnabled; // 0x34C
	unsigned char Padding8[0x0F]; // 0x34D
	char mEmpoweredBitField; // 0x35C
	unsigned char Padding9[0x0F]; // 0x35D
	int mSARState; // 0x36C
	unsigned char Padding10[0x200]; // 0x370
	float mLifetime; // 0x570
	unsigned char Padding11[0x0C]; // 0x574
	float mMaxLifetime; // 0x580
	unsigned char Padding12[0x0C]; // 0x584
	float mLifetimeTicks; // 0x590
	unsigned char Padding13[0x28]; // 0x594
	float mPhysicalDamagePercentageModifier; // 0x5BC
	unsigned char Padding14[0x0C]; // 0x5C0
	float mMagicalDamagePercentageModifier; // 0x5CC
	unsigned char Padding15[0x1C]; // 0x5D0
	bool mIsUntargetableToEnemies; // 0x5EC
	unsigned char Padding16[0x0F]; // 0x5ED
	bool mIsUntargetableToAllies; // 0x5FC
	unsigned char Padding17[0x0F]; // 0x5FD
	bool mIsTargetable; // 0x60C
	unsigned char Padding18[0x0F]; // 0x60D
	float mIsTargetableToTeamFlags; // 0x61C
	unsigned char Padding19[0x58]; // 0x620
	float mHP; // 0x678
	unsigned char Padding20[0x0C]; // 0x67C
	float mMaxHP; // 0x688
	unsigned char Padding21[0x0C]; // 0x68C
	float mHPMaxPenalty; // 0x698
	unsigned char Padding22[0x1C]; // 0x69C
	float mAllShield; // 0x6B8
	unsigned char Padding23[0x0C]; // 0x6BC
	float mPhysicalShield; // 0x6C8
	unsigned char Padding24[0x0C]; // 0x6CC
	float mMagicalShield; // 0x6D8
	unsigned char Padding25[0x0C]; // 0x6DC
	float mChampSpecificHealth; // 0x6E8
	unsigned char Padding26[0x0C]; // 0x6EC
	int mStopShieldFade; // 0x6F8
	unsigned char Padding27[0x764]; // 0x6FC
	float mPercentCooldownCapMod; // 0xE60
	unsigned char Padding28[0x0C]; // 0xE64
	float mPassiveCooldownEndTime; // 0xE70
	unsigned char Padding29[0x0C]; // 0xE74
	float mPassiveCooldownTotalTime; // 0xE80
	unsigned char Padding30[0x2C]; // 0xE84
	float mFlatPhysicalDamageMod; // 0xEB0
	unsigned char Padding31[0x0C]; // 0xEB4
	float mPercentPhysicalDamageMod; // 0xEC0
	unsigned char Padding32[0x0C]; // 0xEC4
	float mFlatMagicDamageMod; // 0xED0
	unsigned char Padding33[0x0C]; // 0xED4
	float mPercentMagicDamageMod; // 0xEE0
	unsigned char Padding34[0x0C]; // 0xEE4
	float mFlatMagicReduction; // 0xEF0
	unsigned char Padding35[0x0C]; // 0xEF4
	float mPercentMagicReduction; // 0xF00
	unsigned char Padding36[0x0C]; // 0xF04
	float mFlatCastRangeMod; // 0xF10
	unsigned char Padding37[0x0C]; // 0xF14
	float mAttackSpeedMod; // 0xF20
	unsigned char Padding38[0x0C]; // 0xF24
	float mBaseAttackDamage; // 0xF30
	unsigned char Padding39[0x0C]; // 0xF34
	float mBaseAttackDamageSansPercentScale; // 0xF40
	unsigned char Padding40[0x0C]; // 0xF44
	float mFlatBaseAttackDamageMod; // 0xF50
	unsigned char Padding41[0x0C]; // 0xF54
	float mPercentBaseAttackDamageMod; // 0xF60
	unsigned char Padding42[0x0C]; // 0xF64
	float mBaseAbilityDamage; // 0xF70
	unsigned char Padding43[0x0C]; // 0xF74
	float mScaleSkinCoef; // 0xF80
	unsigned char Padding44[0x0C]; // 0xF84
	float mDodge; // 0xF90
	unsigned char Padding45[0x0C]; // 0xF94
	float mCrit; // 0xFA0
	unsigned char Padding46[0x0C]; // 0xFA4
	float mArmor; // 0xFB0
	unsigned char Padding47[0x0C]; // 0xFB4
	float mBonusArmor; // 0xFC0
	unsigned char Padding48[0x0C]; // 0xFC4
	float mSpellBlock; // 0xFD0
	unsigned char Padding49[0x0C]; // 0xFD4
	float mBonusSpellBlock; // 0xFE0
	unsigned char Padding50[0x0C]; // 0xFE4
	float mHPRegenRate; // 0xFF0
	unsigned char Padding51[0x0C]; // 0xFF4
	float mBaseHPRegenRate; // 0x1000
	unsigned char Padding52[0x0C]; // 0x1004
	float mMoveSpeed; // 0x1010
	unsigned char Padding53[0x0C]; // 0x1014
	float mMoveSpeedBaseIncrease; // 0x1020
	unsigned char Padding54[0x0C]; // 0x1024
	float mAttackRange; // 0x1030
	unsigned char Padding55[0x0C]; // 0x1034
	float mFlatBubbleRadiusMod; // 0x1040
	unsigned char Padding56[0x0C]; // 0x1044
	float mPercentBubbleRadiusMod; // 0x1050
	unsigned char Padding57[0x0C]; // 0x1054
	float mFlatArmorPenetration; // 0x1060
	unsigned char Padding58[0x0C]; // 0x1064
	float mPhysicalLethality; // 0x1070
	unsigned char Padding59[0x0C]; // 0x1074
	float mPercentArmorPenetration; // 0x1080
	unsigned char Padding60[0x0C]; // 0x1084
	float mPercentBonusArmorPenetration; // 0x1090
	unsigned char Padding61[0x0C]; // 0x1094
	float mPercentCritBonusArmorPenetration; // 0x10A0
	unsigned char Padding62[0x0C]; // 0x10A4
	float mPercentCritTotalArmorPenetration; // 0x10B0
	unsigned char Padding63[0x0C]; // 0x10B4
	float mFlatMagicPenetration; // 0x10C0
	unsigned char Padding64[0x0C]; // 0x10C4
	float mMagicLethality; // 0x10D0
	unsigned char Padding65[0x0C]; // 0x10D4
	float mPercentMagicPenetration; // 0x10E0
	unsigned char Padding66[0x0C]; // 0x10E4
	float mPercentBonusMagicPenetration; // 0x10F0
	unsigned char Padding67[0x0C]; // 0x10F4
	float mPercentLifeStealMod; // 0x1100
	unsigned char Padding68[0x0C]; // 0x1104
	float mPercentSpellVampMod; // 0x1110
	unsigned char Padding69[0x1C]; // 0x1114
	float mPercentCCReduction; // 0x1130
	unsigned char Padding70[0x0C]; // 0x1134
	float mPercentEXPBonus; // 0x1140
	unsigned char Padding71[0x0C]; // 0x1144
	float mPARRegenRate; // 0x1150
	unsigned char Padding72[0x0C]; // 0x1154
	float mPrimaryARBaseRegenRateRep; // 0x1160
	unsigned char Padding73[0x0C]; // 0x1164
	float mSecondaryARRegenRateRep; // 0x1170
	unsigned char Padding74[0x0C]; // 0x1174
	float mSecondaryARBaseRegenRateRep; // 0x1180
	unsigned char Padding75[0xB4]; // 0x1184
	float mGold; // 0x1238
	unsigned char Padding76[0x0C]; // 0x123C
	float mGoldTotal; // 0x1248
	unsigned char Padding77[0x0C]; // 0x124C
	float mMinimumGold; // 0x1258
	unsigned char Padding78[0x2458]; // 0x125C
	int mEvolvePoints; // 0x36B4
	unsigned char Padding79[0x0C]; // 0x36B8
	int mEvolveFlag; // 0x36C4
	unsigned char Padding80[0x0C]; // 0x36C8
	float mExp; // 0x36D4
	unsigned char Padding81[0x0C]; // 0x36D8
	int mLevelRef; // 0x36E4
	unsigned char Padding82[0x0C]; // 0x36E8
	bool mSkillUpLevelDeltaReplicate; // 0x36F4
	unsigned char Padding83[0x903]; // 0x36F5
	int mNumNeutralMinionsKilled; // 0x3FF8
	unsigned char Padding84[0x20]; // 0x3FFC
	int mInputLocks; // 0x401C
	unsigned char Padding85[0x0C]; // 0x4020
	int mHealthBarCharacterIDForIcon; // 0x402C
	unsigned char Padding86[0x530]; // 0x4030
	float mPhysicalDamageTaken; // 0x4560
	unsigned char Padding87[0x0C]; // 0x4564
	float mMagicDamageTaken; // 0x4570
	unsigned char Padding88[0x0C]; // 0x4574
	float mTrueDamageTaken; // 0x4580
	*/
};