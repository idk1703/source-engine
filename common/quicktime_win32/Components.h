/*
		File:       Components.h

		Contains:   Component Manager Interfaces.

		Version:    QuickTime 7.3

		Copyright:  (c) 2007 (c) 1990-2003 by Apple Computer, Inc., all rights reserved

		Bugs?:      For bug reports, consult the following page on
								the World Wide Web:

										http://developer.apple.com/bugreporter/

*/
#ifndef __COMPONENTS__
#define __COMPONENTS__

#ifndef __MACERRORS__
#include <MacErrors.h>
#endif

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __MIXEDMODE__
#include <MixedMode.h>
#endif

#ifndef __FILES__
#include <Files.h>
#endif




#if PRAGMA_ONCE
#pragma once
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if PRAGMA_IMPORT
#pragma import on
#endif

#if PRAGMA_STRUCT_ALIGN
		#pragma options align=mac68k
#elif PRAGMA_STRUCT_PACKPUSH
		#pragma pack(push, 2)
#elif PRAGMA_STRUCT_PACK
		#pragma pack(2)
#endif

enum {
	kAppleManufacturer            = FOUR_CHAR_CODE('appl'), /* Apple supplied components */
	kComponentResourceType        = FOUR_CHAR_CODE('thng'), /* a components resource type */
	kComponentAliasResourceType   = FOUR_CHAR_CODE('thga') /* component alias resource type */
};

enum {
	kAnyComponentType             = 0,
	kAnyComponentSubType          = 0,
	kAnyComponentManufacturer     = 0,
	kAnyComponentFlagsMask        = 0
};

enum {
	cmpIsMissing                  = 1L << 29,
	cmpWantsRegisterMessage       = 1L << 31
};

enum {
	kComponentOpenSelect          = -1,   /* ComponentInstance for this open */
	kComponentCloseSelect         = -2,   /* ComponentInstance for this close */
	kComponentCanDoSelect         = -3,   /* selector # being queried */
	kComponentVersionSelect       = -4,   /* no params */
	kComponentRegisterSelect      = -5,   /* no params */
	kComponentTargetSelect        = -6,   /* ComponentInstance for top of call chain */
	kComponentUnregisterSelect    = -7,   /* no params */
	kComponentGetMPWorkFunctionSelect = -8, /* some params */
	kComponentExecuteWiredActionSelect = -9, /* QTAtomContainer actionContainer, QTAtom actionAtom, QTCustomActionTargetPtr target, QTEventRecordPtr event */
	kComponentGetPublicResourceSelect = -10 /* OSType resourceType, short resourceId, Handle *resource */
};

/* Component Resource Extension flags */
enum {
	componentDoAutoVersion        = (1 << 0),
	componentWantsUnregister      = (1 << 1),
	componentAutoVersionIncludeFlags = (1 << 2),
	componentHasMultiplePlatforms = (1 << 3),
	componentLoadResident         = (1 << 4)
};



/* Set Default Component flags */
enum {
	defaultComponentIdentical     = 0,
	defaultComponentAnyFlags      = 1,
	defaultComponentAnyManufacturer = 2,
	defaultComponentAnySubType    = 4,
	defaultComponentAnyFlagsAnyManufacturer = (defaultComponentAnyFlags + defaultComponentAnyManufacturer),
	defaultComponentAnyFlagsAnyManufacturerAnySubType = (defaultComponentAnyFlags + defaultComponentAnyManufacturer + defaultComponentAnySubType)
};

/* RegisterComponentResource flags */
enum {
	registerComponentGlobal       = 1,
	registerComponentNoDuplicates = 2,
	registerComponentAfterExisting = 4,
	registerComponentAliasesOnly  = 8
};


struct ComponentDescription {
	OSType              componentType;          /* A unique 4-byte code indentifying the command set */
	OSType              componentSubType;       /* Particular flavor of this instance */
	OSType              componentManufacturer;  /* Vendor indentification */
	unsigned long       componentFlags;         /* 8 each for Component,Type,SubType,Manuf/revision */
	unsigned long       componentFlagsMask;     /* Mask for specifying which flags to consider in search, zero during registration */
};
typedef struct ComponentDescription     ComponentDescription;

struct ResourceSpec {
	OSType              resType;                /* 4-byte code    */
	short               resID;                  /*         */
};
typedef struct ResourceSpec             ResourceSpec;
struct ComponentResource {
	ComponentDescription  cd;                   /* Registration parameters */
	ResourceSpec        component;              /* resource where Component code is found */
	ResourceSpec        componentName;          /* name string resource */
	ResourceSpec        componentInfo;          /* info string resource */
	ResourceSpec        componentIcon;          /* icon resource */
};
typedef struct ComponentResource        ComponentResource;
typedef ComponentResource *             ComponentResourcePtr;
typedef ComponentResourcePtr *          ComponentResourceHandle;
struct ComponentPlatformInfo {
	long                componentFlags;         /* flags of Component */
	ResourceSpec        component;              /* resource where Component code is found */
	short               platformType;           /* gestaltSysArchitecture result */
};
typedef struct ComponentPlatformInfo    ComponentPlatformInfo;
struct ComponentResourceExtension {
	long                componentVersion;       /* version of Component */
	long                componentRegisterFlags; /* flags for registration */
	short               componentIconFamily;    /* resource id of Icon Family */
};
typedef struct ComponentResourceExtension ComponentResourceExtension;
struct ComponentPlatformInfoArray {
	long                count;
	ComponentPlatformInfo  platformArray[1];
};
typedef struct ComponentPlatformInfoArray ComponentPlatformInfoArray;
struct ExtComponentResource {
	ComponentDescription  cd;                   /* registration parameters */
	ResourceSpec        component;              /* resource where Component code is found */
	ResourceSpec        componentName;          /* name string resource */
	ResourceSpec        componentInfo;          /* info string resource */
	ResourceSpec        componentIcon;          /* icon resource */
	long                componentVersion;       /* version of Component */
	long                componentRegisterFlags; /* flags for registration */
	short               componentIconFamily;    /* resource id of Icon Family */
	long                count;                  /* elements in platformArray */
	ComponentPlatformInfo  platformArray[1];
};
typedef struct ExtComponentResource     ExtComponentResource;
typedef ExtComponentResource *          ExtComponentResourcePtr;
typedef ExtComponentResourcePtr *       ExtComponentResourceHandle;
struct ComponentAliasResource {
	ComponentResource   cr;                     /* Registration parameters */
	ComponentDescription  aliasCD;              /* component alias description */
};
typedef struct ComponentAliasResource   ComponentAliasResource;
/*  Structure received by Component:        */
struct ComponentParameters {
	UInt8               flags;                  /* call modifiers: sync/async, deferred, immed, etc */
	UInt8               paramSize;              /* size in bytes of actual parameters passed to this call */
	short               what;                   /* routine selector, negative for Component management calls */
	long                params[1];              /* actual parameters for the indicated routine */
};
typedef struct ComponentParameters      ComponentParameters;
struct ComponentRecord {
	long                data[1];
};
typedef struct ComponentRecord          ComponentRecord;
typedef ComponentRecord *               Component;
struct ComponentInstanceRecord {
	long                data[1];
};
typedef struct ComponentInstanceRecord  ComponentInstanceRecord;
typedef ComponentInstanceRecord *       ComponentInstance;
struct RegisteredComponentRecord {
	long                data[1];
};
typedef struct RegisteredComponentRecord RegisteredComponentRecord;
typedef RegisteredComponentRecord *     RegisteredComponentRecordPtr;
struct RegisteredComponentInstanceRecord {
	long                data[1];
};
typedef struct RegisteredComponentInstanceRecord RegisteredComponentInstanceRecord;
typedef RegisteredComponentInstanceRecord * RegisteredComponentInstanceRecordPtr;
typedef long                            ComponentResult;
enum {
	platform68k                   = 1,    /* platform type (response from gestaltComponentPlatform) */
	platformPowerPC               = 2,    /* (when gestaltComponentPlatform is not implemented, use */
	platformInterpreted           = 3,    /* gestaltSysArchitecture) */
	platformWin32                 = 4,
	platformPowerPCNativeEntryPoint = 5
};

enum {
	mpWorkFlagDoWork              = (1 << 0),
	mpWorkFlagDoCompletion        = (1 << 1),
	mpWorkFlagCopyWorkBlock       = (1 << 2),
	mpWorkFlagDontBlock           = (1 << 3),
	mpWorkFlagGetProcessorCount   = (1 << 4),
	mpWorkFlagGetIsRunning        = (1 << 6)
};

enum {
	cmpAliasNoFlags               = 0,
	cmpAliasOnlyThisFile          = 1
};

struct ComponentMPWorkFunctionHeaderRecord {
	UInt32              headerSize;
	UInt32              recordSize;
	UInt32              workFlags;
	UInt16              processorCount;
	UInt8               unused;
	UInt8               isRunning;
};
typedef struct ComponentMPWorkFunctionHeaderRecord ComponentMPWorkFunctionHeaderRecord;
typedef ComponentMPWorkFunctionHeaderRecord * ComponentMPWorkFunctionHeaderRecordPtr;
typedef CALLBACK_API( ComponentResult , ComponentMPWorkFunctionProcPtr )(void *globalRefCon, ComponentMPWorkFunctionHeaderRecordPtr header);
typedef CALLBACK_API( ComponentResult , ComponentRoutineProcPtr )(ComponentParameters *cp, Handle componentStorage);
typedef CALLBACK_API( OSErr , GetMissingComponentResourceProcPtr )(Component c, OSType resType, short resID, void *refCon, Handle *resource);
typedef STACK_UPP_TYPE(ComponentMPWorkFunctionProcPtr)          ComponentMPWorkFunctionUPP;
typedef STACK_UPP_TYPE(ComponentRoutineProcPtr)                 ComponentRoutineUPP;
typedef STACK_UPP_TYPE(GetMissingComponentResourceProcPtr)      GetMissingComponentResourceUPP;
/*
		The parameter list for each ComponentFunction is unique. It is
		therefore up to users to create the appropriate procInfo for their
		own ComponentFunctions where necessary.
*/
typedef UniversalProcPtr                ComponentFunctionUPP;
/*
 *  NewComponentFunctionUPP()
 *
 *  Discussion:
 *    For use in writing a Carbon compliant Component.  It is used to
 *    create a ComponentFunctionUPP needed to call
 *    CallComponentFunction in the Components dispatch routine.
 *
 *  Availability:
 *    Non-Carbon CFM:   available as macro/inline
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 */
EXTERN_API( ComponentFunctionUPP )
NewComponentFunctionUPP(
	ProcPtr        userRoutine,
	ProcInfoType   procInfo);
#if !OPAQUE_UPP_TYPES
	#ifdef __cplusplus
		inline DEFINE_API(ComponentFunctionUPP ) NewComponentFunctionUPP(ProcPtr userRoutine, ProcInfoType procInfo) { return (ComponentFunctionUPP)NewRoutineDescriptor((ProcPtr)(userRoutine), (ProcInfoType)procInfo, GetCurrentArchitecture()); }
	#else
		#define NewComponentFunctionUPP(userRoutine, procInfo) ((ComponentFunctionUPP)NewRoutineDescriptor((ProcPtr)(userRoutine), (ProcInfoType)procInfo, GetCurrentArchitecture()))
	#endif
#endif


/*
 *  DisposeComponentFunctionUPP()
 *
 *  Discussion:
 *    For use in writing a Carbon compliant Component.  It is used to
 *    dispose of a ComponentFunctionUPP created by
 *    NewComponentFunctionUPP.
 *
 *  Availability:
 *    Non-Carbon CFM:   available as macro/inline
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 */
EXTERN_API( void )
DisposeComponentFunctionUPP(ComponentFunctionUPP userUPP);
#if !OPAQUE_UPP_TYPES
	#ifdef __cplusplus
		inline DEFINE_API(void) DisposeComponentFunctionUPP(ComponentFunctionUPP userUPP) { DisposeRoutineDescriptor(userUPP); }
	#else
		#define DisposeComponentFunctionUPP(userUPP) (DisposeRoutineDescriptor(userUPP))
	#endif
#endif



#if TARGET_RT_MAC_CFM
/*
		CallComponentUPP is a global variable exported from InterfaceLib.
		It is the ProcPtr passed to CallUniversalProc to manually call a component function.
*/
/*
 *  CallComponentUPP
 *
 *  Availability:
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 *    CarbonLib:        not available
 *    Mac OS X:         not available
 */
extern UniversalProcPtr CallComponentUPP;
#endif

#define ComponentCallNow( callNumber, paramSize ) \
		FIVEWORDINLINE( 0x2F3C,paramSize,callNumber,0x7000,0xA82A )

/********************************************************
*                                                       *
*               APPLICATION LEVEL CALLS                 *
*                                                       *
********************************************************/
/********************************************************
* Component Database Add, Delete, and Query Routines
********************************************************/
/*
 *  RegisterComponent()
 *
 *  Availability:
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API( Component )
RegisterComponent(
	ComponentDescription *  cd,
	ComponentRoutineUPP     componentEntryPoint,
	short                   global,
	Handle                  componentName,
	Handle                  componentInfo,
	Handle                  componentIcon)                      TWOWORDINLINE(0x7001, 0xA82A);


/*
 *  RegisterComponentResource()
 *
 *  Availability:
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API( Component )
RegisterComponentResource(
	ComponentResourceHandle   cr,
	short                     global)                           TWOWORDINLINE(0x7012, 0xA82A);


/*
 *  UnregisterComponent()
 *
 *  Availability:
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API( OSErr )
UnregisterComponent(Component aComponent)                     TWOWORDINLINE(0x7002, 0xA82A);


/*
 *  FindNextComponent()
 *
 *  Availability:
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API( Component )
FindNextComponent(
	Component               aComponent,
	ComponentDescription *  looking)                            TWOWORDINLINE(0x7004, 0xA82A);


/*
 *  CountComponents()
 *
 *  Availability:
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API( long )
CountComponents(ComponentDescription * looking)               TWOWORDINLINE(0x7003, 0xA82A);


/*
 *  GetComponentInfo()
 *
 *  Availability:
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API( OSErr )
GetComponentInfo(
	Component               aComponent,
	ComponentDescription *  cd,
	Handle                  componentName,
	Handle                  componentInfo,
	Handle                  componentIcon)                      TWOWORDINLINE(0x7005, 0xA82A);


/*
 *  GetComponentListModSeed()
 *
 *  Availability:
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API( long )
GetComponentListModSeed(void)                                 TWOWORDINLINE(0x7006, 0xA82A);


/*
 *  GetComponentTypeModSeed()
 *
 *  Availability:
 *    Non-Carbon CFM:   in InterfaceLib via QuickTime 2.5 and later
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API( long )
GetComponentTypeModSeed(OSType componentType)                 TWOWORDINLINE(0x702C, 0xA82A);


/********************************************************
* Component Instance Allocation and dispatch routines
********************************************************/
/*
 *  OpenAComponent()
 *
 *  Availability:
 *    Non-Carbon CFM:   in InterfaceLib via QuickTime 2.5 and later
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API( OSErr )
OpenAComponent(
	Component            aComponent,
	ComponentInstance *  ci)                                    TWOWORDINLINE(0x702D, 0xA82A);


/*
 *  OpenComponent()
 *
 *  Availability:
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API( ComponentInstance )
OpenComponent(Component aComponent)                           TWOWORDINLINE(0x7007, 0xA82A);


/*
 *  CloseComponent()
 *
 *  Availability:
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API( OSErr )
CloseComponent(ComponentInstance aComponentInstance)          TWOWORDINLINE(0x7008, 0xA82A);


/*
 *  GetComponentInstanceError()
 *
 *  Availability:
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API( OSErr )
GetComponentInstanceError(ComponentInstance aComponentInstance) TWOWORDINLINE(0x700A, 0xA82A);


/********************************************************
* Component aliases
********************************************************/
/*
 *  ResolveComponentAlias()
 *
 *  Availability:
 *    Non-Carbon CFM:   in InterfaceLib via QuickTime 3.0 and later
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API( Component )
ResolveComponentAlias(Component aComponent)                   TWOWORDINLINE(0x7020, 0xA82A);


/********************************************************
* Component public resources and public string lists
********************************************************/
/* Note: GetComponentPublicResource returns a Handle, not a resource.  The caller must dispose it with DisposeHandle. */
/*
 *  GetComponentPublicResource()
 *
 *  Availability:
 *    Non-Carbon CFM:   in InterfaceLib via QuickTime 4.0 and later
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Mac OS X:         in version 10.0 and later
 */
EXTERN_API( OSErr )
GetComponentPublicResource(
	Component   aComponent,
	OSType      resourceType,
	short       resourceID,
	Handle *    theResource)                                    TWOWORDINLINE(0x7038, 0xA82A);


/*
 *  GetComponentPublicResourceList()
 *
 *  Availability:
 *    Non-Carbon CFM:   in InterfaceLib via QuickTime 4.0 and later
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Mac OS X:         in version 10.0 and later
 */
EXTERN_API( OSErr )
GetComponentPublicResourceList(
	OSType                           resourceType,
	short                            resourceID,
	long                             flags,
	ComponentDescription *           cd,
	GetMissingComponentResourceUPP   missingProc,
	void *                           refCon,
	void *                           atomContainerPtr)          TWOWORDINLINE(0x7039, 0xA82A);


/*
 *  GetComponentPublicIndString()
 *
 *  Availability:
 *    Non-Carbon CFM:   in InterfaceLib via QuickTime 4.0 and later
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Mac OS X:         in version 10.0 and later
 */
EXTERN_API( OSErr )
GetComponentPublicIndString(
	Component   aComponent,
	Str255      theString,
	short       strListID,
	short       index)                                          TWOWORDINLINE(0x703A, 0xA82A);


/********************************************************
*                                                       *
*                   CALLS MADE BY COMPONENTS            *
*                                                       *
********************************************************/
/********************************************************
* Component Management routines
********************************************************/
/*
 *  SetComponentInstanceError()
 *
 *  Availability:
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API( void )
SetComponentInstanceError(
	ComponentInstance   aComponentInstance,
	OSErr               theError)                               TWOWORDINLINE(0x700B, 0xA82A);


/*
 *  GetComponentRefcon()
 *
 *  Availability:
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API( long )
GetComponentRefcon(Component aComponent)                      TWOWORDINLINE(0x7010, 0xA82A);


/*
 *  SetComponentRefcon()
 *
 *  Availability:
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API( void )
SetComponentRefcon(
	Component   aComponent,
	long        theRefcon)                                      TWOWORDINLINE(0x7011, 0xA82A);


/*
 *  OpenComponentResFile()
 *
 *  Availability:
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API( short )
OpenComponentResFile(Component aComponent)                    TWOWORDINLINE(0x7015, 0xA82A);


/*
 *  OpenAComponentResFile()
 *
 *  Availability:
 *    Non-Carbon CFM:   in InterfaceLib via QuickTime 2.5 and later
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API( OSErr )
OpenAComponentResFile(
	Component   aComponent,
	short *     resRef)                                         TWOWORDINLINE(0x702F, 0xA82A);


/*
 *  CloseComponentResFile()
 *
 *  Availability:
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API( OSErr )
CloseComponentResFile(short refnum)                           TWOWORDINLINE(0x7018, 0xA82A);


/* Note: GetComponentResource returns a Handle, not a resource.  The caller must dispose it with DisposeHandle. */
/*
 *  GetComponentResource()
 *
 *  Availability:
 *    Non-Carbon CFM:   in InterfaceLib via QuickTime 3.0 and later
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API( OSErr )
GetComponentResource(
	Component   aComponent,
	OSType      resType,
	short       resID,
	Handle *    theResource)                                    TWOWORDINLINE(0x7035, 0xA82A);


/*
 *  GetComponentIndString()
 *
 *  Availability:
 *    Non-Carbon CFM:   in InterfaceLib via QuickTime 3.0 and later
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API( OSErr )
GetComponentIndString(
	Component   aComponent,
	Str255      theString,
	short       strListID,
	short       index)                                          TWOWORDINLINE(0x7036, 0xA82A);


/********************************************************
* Component Instance Management routines
********************************************************/
/*
 *  GetComponentInstanceStorage()
 *
 *  Availability:
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API( Handle )
GetComponentInstanceStorage(ComponentInstance aComponentInstance) TWOWORDINLINE(0x700C, 0xA82A);


/*
 *  SetComponentInstanceStorage()
 *
 *  Availability:
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API( void )
SetComponentInstanceStorage(
	ComponentInstance   aComponentInstance,
	Handle              theStorage)                             TWOWORDINLINE(0x700D, 0xA82A);


#if CALL_NOT_IN_CARBON
/*
 *  GetComponentInstanceA5()
 *
 *  Availability:
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 *    CarbonLib:        not available
 *    Mac OS X:         not available
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API( long )
GetComponentInstanceA5(ComponentInstance aComponentInstance)  TWOWORDINLINE(0x700E, 0xA82A);


/*
 *  SetComponentInstanceA5()
 *
 *  Availability:
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 *    CarbonLib:        not available
 *    Mac OS X:         not available
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API( void )
SetComponentInstanceA5(
	ComponentInstance   aComponentInstance,
	long                theA5)                                  TWOWORDINLINE(0x700F, 0xA82A);


#endif  /* CALL_NOT_IN_CARBON */

/*
 *  CountComponentInstances()
 *
 *  Availability:
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API( long )
CountComponentInstances(Component aComponent)                 TWOWORDINLINE(0x7013, 0xA82A);


/* useful helper routines for convenient method dispatching */
/*
 *  CallComponentFunction()
 *
 *  Availability:
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 */
EXTERN_API( long )
CallComponentFunction(
	ComponentParameters *  params,
	ComponentFunctionUPP   func)                                TWOWORDINLINE(0x70FF, 0xA82A);


/*
 *  CallComponentFunctionWithStorage()
 *
 *  Availability:
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API( long )
CallComponentFunctionWithStorage(
	Handle                 storage,
	ComponentParameters *  params,
	ComponentFunctionUPP   func)                                TWOWORDINLINE(0x70FF, 0xA82A);


#if TARGET_OS_MAC && !TARGET_CPU_68K
/*
 *  CallComponentFunctionWithStorageProcInfo()
 *
 *  Availability:
 *    Non-Carbon CFM:   in InterfaceLib via QuickTime 2.5 and later
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 */
EXTERN_API( long )
CallComponentFunctionWithStorageProcInfo(
	Handle                 storage,
	ComponentParameters *  params,
	ProcPtr                func,
	ProcInfoType           funcProcInfo);


#else
#define CallComponentFunctionWithStorageProcInfo(storage, params, func, funcProcInfo ) CallComponentFunctionWithStorage(storage, params, func)

#endif  /* TARGET_OS_MAC && !TARGET_CPU_68K */

/*
 *  DelegateComponentCall()
 *
 *  Availability:
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API( long )
DelegateComponentCall(
	ComponentParameters *  originalParams,
	ComponentInstance      ci)                                  TWOWORDINLINE(0x7024, 0xA82A);


/*
 *  SetDefaultComponent()
 *
 *  Availability:
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API( OSErr )
SetDefaultComponent(
	Component   aComponent,
	short       flags)                                          TWOWORDINLINE(0x701E, 0xA82A);


/*
 *  OpenDefaultComponent()
 *
 *  Availability:
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API( ComponentInstance )
OpenDefaultComponent(
	OSType   componentType,
	OSType   componentSubType)                                  TWOWORDINLINE(0x7021, 0xA82A);


/*
 *  OpenADefaultComponent()
 *
 *  Availability:
 *    Non-Carbon CFM:   in InterfaceLib via QuickTime 2.5 and later
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API( OSErr )
OpenADefaultComponent(
	OSType               componentType,
	OSType               componentSubType,
	ComponentInstance *  ci)                                    TWOWORDINLINE(0x702E, 0xA82A);


/*
 *  CaptureComponent()
 *
 *  Availability:
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API( Component )
CaptureComponent(
	Component   capturedComponent,
	Component   capturingComponent)                             TWOWORDINLINE(0x701C, 0xA82A);


/*
 *  UncaptureComponent()
 *
 *  Availability:
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API( OSErr )
UncaptureComponent(Component aComponent)                      TWOWORDINLINE(0x701D, 0xA82A);


/*
 *  RegisterComponentResourceFile()
 *
 *  Availability:
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API( long )
RegisterComponentResourceFile(
	short   resRefNum,
	short   global)                                             TWOWORDINLINE(0x7014, 0xA82A);


/*
 *  GetComponentIconSuite()
 *
 *  Availability:
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API( OSErr )
GetComponentIconSuite(
	Component   aComponent,
	Handle *    iconSuite)                                      TWOWORDINLINE(0x7029, 0xA82A);


/********************************************************
*                                                       *
*           Direct calls to the Components              *
*                                                       *
********************************************************/
/* Old style names*/

/*
 *  ComponentFunctionImplemented()
 *
 *  Availability:
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API( long )
ComponentFunctionImplemented(
	ComponentInstance   ci,
	short               ftnNumber)                              FIVEWORDINLINE(0x2F3C, 0x0002, 0xFFFD, 0x7000, 0xA82A);


/*
 *  GetComponentVersion()
 *
 *  Availability:
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API( long )
GetComponentVersion(ComponentInstance ci)                     FIVEWORDINLINE(0x2F3C, 0x0000, 0xFFFC, 0x7000, 0xA82A);


/*
 *  ComponentSetTarget()
 *
 *  Availability:
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API( long )
ComponentSetTarget(
	ComponentInstance   ci,
	ComponentInstance   target)                                 FIVEWORDINLINE(0x2F3C, 0x0004, 0xFFFA, 0x7000, 0xA82A);


/* New style names*/

/*
 *  CallComponentOpen()
 *
 *  Availability:
 *    Non-Carbon CFM:   in InterfaceLib via QuickTime 2.5 and later
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API( ComponentResult )
CallComponentOpen(
	ComponentInstance   ci,
	ComponentInstance   self)                                   FIVEWORDINLINE(0x2F3C, 0x0004, 0xFFFF, 0x7000, 0xA82A);


/*
 *  CallComponentClose()
 *
 *  Availability:
 *    Non-Carbon CFM:   in InterfaceLib via QuickTime 2.5 and later
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API( ComponentResult )
CallComponentClose(
	ComponentInstance   ci,
	ComponentInstance   self)                                   FIVEWORDINLINE(0x2F3C, 0x0004, 0xFFFE, 0x7000, 0xA82A);


/*
 *  CallComponentCanDo()
 *
 *  Availability:
 *    Non-Carbon CFM:   in InterfaceLib via QuickTime 2.5 and later
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API( ComponentResult )
CallComponentCanDo(
	ComponentInstance   ci,
	short               ftnNumber)                              FIVEWORDINLINE(0x2F3C, 0x0002, 0xFFFD, 0x7000, 0xA82A);


/*
 *  CallComponentVersion()
 *
 *  Availability:
 *    Non-Carbon CFM:   in InterfaceLib via QuickTime 2.5 and later
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API( ComponentResult )
CallComponentVersion(ComponentInstance ci)                    FIVEWORDINLINE(0x2F3C, 0x0000, 0xFFFC, 0x7000, 0xA82A);


/*
 *  CallComponentRegister()
 *
 *  Availability:
 *    Non-Carbon CFM:   in InterfaceLib via QuickTime 2.5 and later
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API( ComponentResult )
CallComponentRegister(ComponentInstance ci)                   FIVEWORDINLINE(0x2F3C, 0x0000, 0xFFFB, 0x7000, 0xA82A);


/*
 *  CallComponentTarget()
 *
 *  Availability:
 *    Non-Carbon CFM:   in InterfaceLib via QuickTime 2.5 and later
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API( ComponentResult )
CallComponentTarget(
	ComponentInstance   ci,
	ComponentInstance   target)                                 FIVEWORDINLINE(0x2F3C, 0x0004, 0xFFFA, 0x7000, 0xA82A);


/*
 *  CallComponentUnregister()
 *
 *  Availability:
 *    Non-Carbon CFM:   in InterfaceLib via QuickTime 2.5 and later
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API( ComponentResult )
CallComponentUnregister(ComponentInstance ci)                 FIVEWORDINLINE(0x2F3C, 0x0000, 0xFFF9, 0x7000, 0xA82A);


/*
 *  CallComponentGetMPWorkFunction()
 *
 *  Availability:
 *    Non-Carbon CFM:   in InterfaceLib via QuickTime 2.5 and later
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API( ComponentResult )
CallComponentGetMPWorkFunction(
	ComponentInstance             ci,
	ComponentMPWorkFunctionUPP *  workFunction,
	void **                       refCon)                       FIVEWORDINLINE(0x2F3C, 0x0008, 0xFFF8, 0x7000, 0xA82A);


/*
 *  CallComponentGetPublicResource()
 *
 *  Availability:
 *    Non-Carbon CFM:   in InterfaceLib via QuickTime 4.0 and later
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Mac OS X:         in version 10.0 and later
 */
EXTERN_API( ComponentResult )
CallComponentGetPublicResource(
	ComponentInstance   ci,
	OSType              resourceType,
	short               resourceID,
	Handle *            resource)                               FIVEWORDINLINE(0x2F3C, 0x000A, 0xFFF6, 0x7000, 0xA82A);



#if !TARGET_OS_MAC
/*
				CallComponent is used by ComponentGlue routines to manually call a component function.
		*/
#if CALL_NOT_IN_CARBON
/*
 *  CallComponent()
 *
 *  Availability:
 *    Non-Carbon CFM:   not available
 *    CarbonLib:        not available
 *    Mac OS X:         not available
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
EXTERN_API( ComponentResult )
CallComponent(
	ComponentInstance      ci,
	ComponentParameters *  cp);


#endif  /* CALL_NOT_IN_CARBON */

#endif  /* !TARGET_OS_MAC */

/*
		CallComponentDispatch is a CarbonLib routine that replaces CallComponent inline glue
		to call a component function.
 */
/*
 *  CallComponentDispatch()
 *
 *  Availability:
 *    Non-Carbon CFM:   not available
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 */
EXTERN_API( ComponentResult )
CallComponentDispatch(ComponentParameters * cp);



/* UPP call backs */
/*
 *  NewComponentMPWorkFunctionUPP()
 *
 *  Availability:
 *    Non-Carbon CFM:   available as macro/inline
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 */
EXTERN_API_C( ComponentMPWorkFunctionUPP )
NewComponentMPWorkFunctionUPP(ComponentMPWorkFunctionProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
	enum { uppComponentMPWorkFunctionProcInfo = 0x000003F0 };  /* pascal 4_bytes Func(4_bytes, 4_bytes) */
	#ifdef __cplusplus
		inline DEFINE_API_C(ComponentMPWorkFunctionUPP) NewComponentMPWorkFunctionUPP(ComponentMPWorkFunctionProcPtr userRoutine) { return (ComponentMPWorkFunctionUPP)NewRoutineDescriptor((ProcPtr)(userRoutine), uppComponentMPWorkFunctionProcInfo, GetCurrentArchitecture()); }
	#else
		#define NewComponentMPWorkFunctionUPP(userRoutine) (ComponentMPWorkFunctionUPP)NewRoutineDescriptor((ProcPtr)(userRoutine), uppComponentMPWorkFunctionProcInfo, GetCurrentArchitecture())
	#endif
#endif

/*
 *  NewComponentRoutineUPP()
 *
 *  Availability:
 *    Non-Carbon CFM:   available as macro/inline
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 */
EXTERN_API_C( ComponentRoutineUPP )
NewComponentRoutineUPP(ComponentRoutineProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
	enum { uppComponentRoutineProcInfo = 0x000003F0 };  /* pascal 4_bytes Func(4_bytes, 4_bytes) */
	#ifdef __cplusplus
		inline DEFINE_API_C(ComponentRoutineUPP) NewComponentRoutineUPP(ComponentRoutineProcPtr userRoutine) { return (ComponentRoutineUPP)NewRoutineDescriptor((ProcPtr)(userRoutine), uppComponentRoutineProcInfo, GetCurrentArchitecture()); }
	#else
		#define NewComponentRoutineUPP(userRoutine) (ComponentRoutineUPP)NewRoutineDescriptor((ProcPtr)(userRoutine), uppComponentRoutineProcInfo, GetCurrentArchitecture())
	#endif
#endif

/*
 *  NewGetMissingComponentResourceUPP()
 *
 *  Availability:
 *    Non-Carbon CFM:   available as macro/inline
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 */
EXTERN_API_C( GetMissingComponentResourceUPP )
NewGetMissingComponentResourceUPP(GetMissingComponentResourceProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
	enum { uppGetMissingComponentResourceProcInfo = 0x0000FBE0 };  /* pascal 2_bytes Func(4_bytes, 4_bytes, 2_bytes, 4_bytes, 4_bytes) */
	#ifdef __cplusplus
		inline DEFINE_API_C(GetMissingComponentResourceUPP) NewGetMissingComponentResourceUPP(GetMissingComponentResourceProcPtr userRoutine) { return (GetMissingComponentResourceUPP)NewRoutineDescriptor((ProcPtr)(userRoutine), uppGetMissingComponentResourceProcInfo, GetCurrentArchitecture()); }
	#else
		#define NewGetMissingComponentResourceUPP(userRoutine) (GetMissingComponentResourceUPP)NewRoutineDescriptor((ProcPtr)(userRoutine), uppGetMissingComponentResourceProcInfo, GetCurrentArchitecture())
	#endif
#endif

/*
 *  DisposeComponentMPWorkFunctionUPP()
 *
 *  Availability:
 *    Non-Carbon CFM:   available as macro/inline
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 */
EXTERN_API_C( void )
DisposeComponentMPWorkFunctionUPP(ComponentMPWorkFunctionUPP userUPP);
#if !OPAQUE_UPP_TYPES
	#ifdef __cplusplus
			inline DEFINE_API_C(void) DisposeComponentMPWorkFunctionUPP(ComponentMPWorkFunctionUPP userUPP) { DisposeRoutineDescriptor((UniversalProcPtr)userUPP); }
	#else
			#define DisposeComponentMPWorkFunctionUPP(userUPP) DisposeRoutineDescriptor(userUPP)
	#endif
#endif

/*
 *  DisposeComponentRoutineUPP()
 *
 *  Availability:
 *    Non-Carbon CFM:   available as macro/inline
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 */
EXTERN_API_C( void )
DisposeComponentRoutineUPP(ComponentRoutineUPP userUPP);
#if !OPAQUE_UPP_TYPES
	#ifdef __cplusplus
			inline DEFINE_API_C(void) DisposeComponentRoutineUPP(ComponentRoutineUPP userUPP) { DisposeRoutineDescriptor((UniversalProcPtr)userUPP); }
	#else
			#define DisposeComponentRoutineUPP(userUPP) DisposeRoutineDescriptor(userUPP)
	#endif
#endif

/*
 *  DisposeGetMissingComponentResourceUPP()
 *
 *  Availability:
 *    Non-Carbon CFM:   available as macro/inline
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 */
EXTERN_API_C( void )
DisposeGetMissingComponentResourceUPP(GetMissingComponentResourceUPP userUPP);
#if !OPAQUE_UPP_TYPES
	#ifdef __cplusplus
			inline DEFINE_API_C(void) DisposeGetMissingComponentResourceUPP(GetMissingComponentResourceUPP userUPP) { DisposeRoutineDescriptor((UniversalProcPtr)userUPP); }
	#else
			#define DisposeGetMissingComponentResourceUPP(userUPP) DisposeRoutineDescriptor(userUPP)
	#endif
#endif

/*
 *  InvokeComponentMPWorkFunctionUPP()
 *
 *  Availability:
 *    Non-Carbon CFM:   available as macro/inline
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 */
EXTERN_API_C( ComponentResult )
InvokeComponentMPWorkFunctionUPP(
	void *                                  globalRefCon,
	ComponentMPWorkFunctionHeaderRecordPtr  header,
	ComponentMPWorkFunctionUPP              userUPP);
#if !OPAQUE_UPP_TYPES
	#ifdef __cplusplus
			inline DEFINE_API_C(ComponentResult) InvokeComponentMPWorkFunctionUPP(void * globalRefCon, ComponentMPWorkFunctionHeaderRecordPtr header, ComponentMPWorkFunctionUPP userUPP) { return (ComponentResult)CALL_TWO_PARAMETER_UPP(userUPP, uppComponentMPWorkFunctionProcInfo, globalRefCon, header); }
	#else
		#define InvokeComponentMPWorkFunctionUPP(globalRefCon, header, userUPP) (ComponentResult)CALL_TWO_PARAMETER_UPP((userUPP), uppComponentMPWorkFunctionProcInfo, (globalRefCon), (header))
	#endif
#endif

/*
 *  InvokeComponentRoutineUPP()
 *
 *  Availability:
 *    Non-Carbon CFM:   available as macro/inline
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 */
EXTERN_API_C( ComponentResult )
InvokeComponentRoutineUPP(
	ComponentParameters *  cp,
	Handle                 componentStorage,
	ComponentRoutineUPP    userUPP);
#if !OPAQUE_UPP_TYPES
	#ifdef __cplusplus
			inline DEFINE_API_C(ComponentResult) InvokeComponentRoutineUPP(ComponentParameters * cp, Handle componentStorage, ComponentRoutineUPP userUPP) { return (ComponentResult)CALL_TWO_PARAMETER_UPP(userUPP, uppComponentRoutineProcInfo, cp, componentStorage); }
	#else
		#define InvokeComponentRoutineUPP(cp, componentStorage, userUPP) (ComponentResult)CALL_TWO_PARAMETER_UPP((userUPP), uppComponentRoutineProcInfo, (cp), (componentStorage))
	#endif
#endif

/*
 *  InvokeGetMissingComponentResourceUPP()
 *
 *  Availability:
 *    Non-Carbon CFM:   available as macro/inline
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Mac OS X:         in version 10.0 and later
 */
EXTERN_API_C( OSErr )
InvokeGetMissingComponentResourceUPP(
	Component                       c,
	OSType                          resType,
	short                           resID,
	void *                          refCon,
	Handle *                        resource,
	GetMissingComponentResourceUPP  userUPP);
#if !OPAQUE_UPP_TYPES
	#ifdef __cplusplus
			inline DEFINE_API_C(OSErr) InvokeGetMissingComponentResourceUPP(Component c, OSType resType, short resID, void * refCon, Handle * resource, GetMissingComponentResourceUPP userUPP) { return (OSErr)CALL_FIVE_PARAMETER_UPP(userUPP, uppGetMissingComponentResourceProcInfo, c, resType, resID, refCon, resource); }
	#else
		#define InvokeGetMissingComponentResourceUPP(c, resType, resID, refCon, resource, userUPP) (OSErr)CALL_FIVE_PARAMETER_UPP((userUPP), uppGetMissingComponentResourceProcInfo, (c), (resType), (resID), (refCon), (resource))
	#endif
#endif

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
		/* support for pre-Carbon UPP routines: New...Proc and Call...Proc */
		#define NewComponentMPWorkFunctionProc(userRoutine)         NewComponentMPWorkFunctionUPP(userRoutine)
		#define NewComponentRoutineProc(userRoutine)                NewComponentRoutineUPP(userRoutine)
		#define NewGetMissingComponentResourceProc(userRoutine)     NewGetMissingComponentResourceUPP(userRoutine)
		#define CallComponentMPWorkFunctionProc(userRoutine, globalRefCon, header) InvokeComponentMPWorkFunctionUPP(globalRefCon, header, userRoutine)
		#define CallComponentRoutineProc(userRoutine, cp, componentStorage) InvokeComponentRoutineUPP(cp, componentStorage, userRoutine)
		#define CallGetMissingComponentResourceProc(userRoutine, c, resType, resID, refCon, resource) InvokeGetMissingComponentResourceUPP(c, resType, resID, refCon, resource, userRoutine)
#endif /* CALL_NOT_IN_CARBON */

/* ProcInfos */

/* MixedMode ProcInfo constants for component calls */
enum {
		uppComponentFunctionImplementedProcInfo    = 0x000002F0,
		uppGetComponentVersionProcInfo             = 0x000000F0,
		uppComponentSetTargetProcInfo              = 0x000003F0,
		uppCallComponentOpenProcInfo               = 0x000003F0,
		uppCallComponentCloseProcInfo              = 0x000003F0,
		uppCallComponentCanDoProcInfo              = 0x000002F0,
		uppCallComponentVersionProcInfo            = 0x000000F0,
		uppCallComponentRegisterProcInfo           = 0x000000F0,
		uppCallComponentTargetProcInfo             = 0x000003F0,
		uppCallComponentUnregisterProcInfo         = 0x000000F0,
		uppCallComponentGetMPWorkFunctionProcInfo  = 0x00000FF0,
		uppCallComponentGetPublicResourceProcInfo  = 0x00003BF0
};







#if PRAGMA_STRUCT_ALIGN
		#pragma options align=reset
#elif PRAGMA_STRUCT_PACKPUSH
		#pragma pack(pop)
#elif PRAGMA_STRUCT_PACK
		#pragma pack()
#endif

#ifdef PRAGMA_IMPORT_OFF
#pragma import off
#elif PRAGMA_IMPORT
#pragma import reset
#endif

#ifdef __cplusplus
}
#endif

#endif /* __COMPONENTS__ */