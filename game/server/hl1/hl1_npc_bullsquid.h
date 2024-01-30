//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose:
//
// $NoKeywords: $
//
//=============================================================================//
#ifndef NPC_BULLSQUID_H
#define NPC_BULLSQUID_H

#include "hl1_ai_basenpc.h"

class CNPC_Bullsquid : public CHL1BaseNPC
{
	DECLARE_CLASS(CNPC_Bullsquid, CHL1BaseNPC);

public:
	void Spawn(void);
	void Precache(void);
	Class_T Classify(void);

	void IdleSound(void);
	void PainSound(const CTakeDamageInfo &info);
	void AlertSound(void);
	void DeathSound(const CTakeDamageInfo &info);
	void AttackSound(void);

	float MaxYawSpeed(void);

	void HandleAnimEvent(animevent_t *pEvent);

	int RangeAttack1Conditions(float flDot, float flDist);
	int MeleeAttack1Conditions(float flDot, float flDist);
	int MeleeAttack2Conditions(float flDot, float flDist);

	bool FValidateHintType(CAI_Hint *pHint);
	void RemoveIgnoredConditions(void);
	Disposition_t IRelationType(CBaseEntity *pTarget);
	int OnTakeDamage_Alive(const CTakeDamageInfo &inputInfo);

	int GetSoundInterests(void);
	void RunAI(void);
	virtual void OnListened(void);

	int SelectSchedule(void);
	int TranslateSchedule(int scheduleType);

	bool FInViewCone(Vector pOrigin);
	bool FVisible(Vector vecOrigin);

	void StartTask(const Task_t *pTask);
	void RunTask(const Task_t *pTask);

	NPC_STATE SelectIdealState(void);

	DEFINE_CUSTOM_AI;
	DECLARE_DATADESC()

private:
	bool m_fCanThreatDisplay; // this is so the squid only does the "I see a headcrab!" dance one time.
	float m_flLastHurtTime; // we keep track of this, because if something hurts a squid, it will forget about its love
							// of headcrabs for a while.
	float m_flNextSpitTime; // last time the bullsquid used the spit attack.
	float m_flHungryTime;	// set this is a future time to stop the monster from eating for a while.
};
#endif // NPC_BULLSQUID_H