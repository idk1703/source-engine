//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: TF's custom CPlayerResource
//
// $NoKeywords: $
//=============================================================================//

#ifndef TF_PLAYER_RESOURCE_H
#define TF_PLAYER_RESOURCE_H
#ifdef _WIN32
#pragma once
#endif

#include "tf_player_shared.h"

class CTFPlayerResource : public CPlayerResource, public CGameEventListener
{
	DECLARE_CLASS( CTFPlayerResource, CPlayerResource );

public:
	DECLARE_SERVERCLASS();

	CTFPlayerResource();

	virtual void FireGameEvent( IGameEvent *event );

	virtual void UpdatePlayerData( void );
	virtual void Spawn( void );
	virtual void Init( int iIndex ) OVERRIDE;

	int	GetTotalScore( int iIndex );

	void SetPartyLeaderIndex( int iTeam, int iIndex );
	int GetPartyLeaderIndex( int iTeam );
	void SetEventTeamStatus( int iValue ) { m_iEventTeamStatus = iValue; }
	uint32 GetEventTeamStatus( void ) { return m_iEventTeamStatus; }

	void SetPlayerClassWhenKilled( int iIndex, int iClass );

protected:
	virtual void UpdateConnectedPlayer( int iIndex, CBasePlayer *pPlayer ) OVERRIDE;
	virtual void UpdateDisconnectedPlayer( int iIndex ) OVERRIDE;

	CNetworkArray( int,	m_iTotalScore, MAX_PLAYERS+1 );
	CNetworkArray( int, m_iPlayerClass, MAX_PLAYERS+1 );
	CNetworkArray( int, m_iMaxHealth, MAX_PLAYERS+1 );
	CNetworkArray( int, m_iMaxBuffedHealth, MAX_PLAYERS+1 );
	CNetworkArray( bool, m_bArenaSpectator, MAX_PLAYERS+1 );
	CNetworkArray( int,	m_iActiveDominations, MAX_PLAYERS+1 );

	// These variables are only networked in tournament mode
	CNetworkArray( float,m_flNextRespawnTime, MAX_PLAYERS+1 );
	CNetworkArray( int,	m_iChargeLevel, MAX_PLAYERS+1 );

	CNetworkArray( int,	m_iDamage, MAX_PLAYERS+1 );
	CNetworkArray( int,	m_iDamageAssist, MAX_PLAYERS+1 );
	CNetworkArray( int, m_iDamageBoss, MAX_PLAYERS+1 );
	CNetworkArray( int, m_iHealing, MAX_PLAYERS+1 );
	CNetworkArray( int, m_iHealingAssist, MAX_PLAYERS+1 );
	CNetworkArray( int, m_iDamageBlocked, MAX_PLAYERS+1 );
	CNetworkArray( int, m_iCurrencyCollected, MAX_PLAYERS+1 );
	CNetworkArray( int, m_iBonusPoints, MAX_PLAYERS+1 );
	CNetworkArray( int, m_iPlayerLevel, MAX_PLAYERS+1 );
	// Pseudo multidimensional array [MAX_PLAYERS + 1][CTFPlayerShared::kTFStreak_COUNT]
	CNetworkArray( int, m_iStreaks, ( ( MAX_PLAYERS + 1 ) * CTFPlayerShared::kTFStreak_COUNT ) );
	CNetworkArray( int, m_iUpgradeRefundCredits, MAX_PLAYERS + 1 );
	CNetworkArray( int, m_iBuybackCredits, MAX_PLAYERS + 1 );

	CNetworkVar( int, m_iPartyLeaderRedTeamIndex );
	CNetworkVar( int, m_iPartyLeaderBlueTeamIndex );
	CNetworkVar( int, m_iEventTeamStatus );

	CNetworkArray( int, m_iPlayerClassWhenKilled, MAX_PLAYERS+1 );
	CNetworkArray( MM_PlayerConnectionState_t, m_iConnectionState, MAX_PLAYERS + 1 );

	float	m_flNextDamageAndHealingSend;

	CUtlVector< uint32 > m_vecRedPlayers;
	CUtlVector< uint32 > m_vecBluePlayers;
	CUtlVector< int > m_vecFreeSlots;
};

#endif // TF_PLAYER_RESOURCE_H