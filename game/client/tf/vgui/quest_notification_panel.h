//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose:
//
// $NoKeywords: $
//=============================================================================//

#ifndef QUEST_NOTIFICATION_PANEL_H
#define QUEST_NOTIFICATION_PANEL_H
#ifdef _WIN32
#pragma once
#endif

#include <vgui/VGUI.h>
#include "hudelement.h"
#include "vgui_controls/EditablePanel.h"
#include <../common/GameUI/cvarslider.h>
#include "vgui_controls/CheckButton.h"
#include "vgui_controls/ScrollableEditablePanel.h"
#include "econ_item_inventory.h"

using namespace vgui;
#define NEVER_REPEAT -1.f

class CQuestNotificationPanel;

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
class CQuestNotification
{
public:
	CQuestNotification( CEconItem *pItem );

	enum ENotificationType_t
	{
		NOTIFICATION_TYPE_NEW_QUEST = 0,
		NOTIFICATION_TYPE_COMPLETED,
		NOTIFICATION_TYPE_FULLY_COMPLETED,

		NUM_NOTIFICATION_TYPES
	};

	virtual ~CQuestNotification() {}

	virtual float Present( CQuestNotificationPanel* pNotificationPanel );
	virtual void Update( CQuestNotificationPanel* pNotificationPanel ) = 0;
	virtual bool IsDone() const = 0;
	virtual bool ShouldPresent() const = 0;
	virtual ENotificationType_t GetType() const = 0;
	virtual float GetReplayTime() const = 0;

	CEconItemHandle& GetItemHandle() { return m_hItem; }

protected:
	CEconItemHandle m_hItem;
	RealTimeCountdownTimer	m_timerDialog;
	RealTimeCountdownTimer	m_timerShow;
};

//-----------------------------------------------------------------------------
// Notifications where we'll speak
//-----------------------------------------------------------------------------
class CQuestNotification_Speaking : public CQuestNotification
{
public:

	CQuestNotification_Speaking( CEconItem *pItem );
	virtual ~CQuestNotification_Speaking() {}

	virtual float Present( CQuestNotificationPanel* pNotificationPanel ) OVERRIDE;
	virtual void Update( CQuestNotificationPanel* pNotificationPanel ) OVERRIDE;
	virtual bool IsDone() const OVERRIDE;

protected:
	virtual const char *GetSoundEntry( const CQuestThemeDefinition* pTheme, int nClassIndex ) = 0;

	const char *m_pszSoundToSpeak;
};

//-----------------------------------------------------------------------------
// New quest notification
//-----------------------------------------------------------------------------
class CQuestNotification_NewQuest : public CQuestNotification_Speaking
{
	DECLARE_CLASS_SIMPLE( CQuestNotification_NewQuest, CQuestNotification_Speaking );
public:
	CQuestNotification_NewQuest( CEconItem *pItem )
		: CQuestNotification_Speaking( pItem )
	{}

	virtual ~CQuestNotification_NewQuest() {}

	virtual bool ShouldPresent() const OVERRIDE;
	ENotificationType_t GetType() const { return NOTIFICATION_TYPE_NEW_QUEST; }
	virtual float GetReplayTime() const { return 300.f; }
	static float k_flReplayTime;

protected:
	virtual const char *GetSoundEntry( const CQuestThemeDefinition* pTheme, int nClassIndex ) OVERRIDE;

	static CUtlVector< itemid_t > m_vecNotifiedItemIDs;
};

//-----------------------------------------------------------------------------
// Quest complete notification
//-----------------------------------------------------------------------------
class CQuestNotification_CompletedQuest : public CQuestNotification_Speaking
{
	DECLARE_CLASS_SIMPLE( CQuestNotification_CompletedQuest, CQuestNotification_Speaking );
public:
	CQuestNotification_CompletedQuest( CEconItem *pItem );

	virtual ~CQuestNotification_CompletedQuest() {}

	virtual bool ShouldPresent() const;
	ENotificationType_t GetType() const { return NOTIFICATION_TYPE_COMPLETED; }
	virtual float GetReplayTime() const { return NEVER_REPEAT; }

protected:
	virtual const char *GetSoundEntry( const CQuestThemeDefinition* pTheme, int nClassIndex ) OVERRIDE;

	RealTimeCountdownTimer m_PresentTimer;
};

class CQuestNotification_FullyCompletedQuest : public CQuestNotification_CompletedQuest
{
	DECLARE_CLASS_SIMPLE( CQuestNotification_FullyCompletedQuest, CQuestNotification_CompletedQuest );
public:
	CQuestNotification_FullyCompletedQuest( CEconItem *pItem ) : CQuestNotification_CompletedQuest( pItem )
	{
	}

	virtual ~CQuestNotification_FullyCompletedQuest() {}

	ENotificationType_t GetType() const { return NOTIFICATION_TYPE_FULLY_COMPLETED; }
protected:
	virtual const char *GetSoundEntry( const CQuestThemeDefinition* pTheme, int nClassIndex ) OVERRIDE;
};

//-----------------------------------------------------------------------------
// The quest notification panel where a character tells the user about quest state
//-----------------------------------------------------------------------------
class CQuestNotificationPanel : public CHudElement, public EditablePanel
{
	DECLARE_CLASS_SIMPLE( CQuestNotificationPanel, EditablePanel );
public:
	CQuestNotificationPanel( const char *pszElementName );
	virtual ~CQuestNotificationPanel();

	virtual void ApplySchemeSettings( IScheme *pScheme ) OVERRIDE;
	virtual void PerformLayout() OVERRIDE;
	virtual void FireGameEvent( IGameEvent * event ) OVERRIDE;
	virtual void Reset() OVERRIDE;
	virtual bool ShouldDraw() OVERRIDE;
	virtual void OnThink() OVERRIDE;
private:

	bool ShouldPresent();

	void Update();
	void CheckForNotificationOpportunities();

	bool AddNotificationForItem( const CEconItemView *pItem, CQuestNotification* pNotification );
	void SetCharacterImage( const char *pszImageName );

	CUtlVector< CQuestNotification* > m_vecNotifications;

	float m_flTimeSinceLastShown;
	bool m_bIsPresenting;
	RealTimeCountdownTimer	m_timerHoldUp;
	RealTimeCountdownTimer	m_timerNotificationCooldown;
	RealTimeCountdownTimer	m_animTimer;
	EditablePanel  *m_pMainContainer;
	bool			m_bInitialized;

	CUtlMap< itemid_t, CCopyableUtlVector< float > > m_mapNotifiedItemIDs;
};

#endif // QUEST_NOTIFICATION_PANEL_H