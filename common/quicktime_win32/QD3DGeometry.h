/*
		File:       QD3DGeometry.h

		Contains:   Q3Geometry methods

		Version:    Technology: Quickdraw 3D 1.6
								Release:    QuickTime 7.3

		Copyright:  (c) 2007 (c) 1995-1999 by Apple Computer, Inc., all rights reserved.

		Bugs?:      For bug reports, consult the following page on
								the World Wide Web:

										http://developer.apple.com/bugreporter/

*/
#ifndef __QD3DGEOMETRY__
#define __QD3DGEOMETRY__

#ifndef __QD3D__
#include <QD3D.h>
#endif

#ifndef __QD3DSET__
#include <QD3DSet.h>
#endif

#if PRAGMA_ONCE
#pragma once
#endif

#ifdef __cplusplus
extern "C"
{
#endif

#if PRAGMA_IMPORT
#pragma import on
#endif

#if PRAGMA_STRUCT_ALIGN
#pragma options align = power
#elif PRAGMA_STRUCT_PACKPUSH
#pragma pack(push, 2)
#elif PRAGMA_STRUCT_PACK
#pragma pack(2)
#endif

#if PRAGMA_ENUM_ALWAYSINT
#if defined(__fourbyteints__) && !__fourbyteints__
#define __QD3DGEOMETRY__RESTORE_TWOBYTEINTS
#pragma fourbyteints on
#endif
#pragma enumsalwaysint on
#elif PRAGMA_ENUM_OPTIONS
#pragma option enum =int
#elif PRAGMA_ENUM_PACK
#if __option(pack_enums)
#define __QD3DGEOMETRY__RESTORE_PACKED_ENUMS
#pragma options(!pack_enums)
#endif
#endif

/******************************************************************************
 **                                                                          **
 **                             Geometry Routines                            **
 **                                                                          **
 *****************************************************************************/
#if CALL_NOT_IN_CARBON
	/*
	 *  Q3Geometry_GetType()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3ObjectType)
	Q3Geometry_GetType(TQ3GeometryObject geometry);

	/*
	 *  Q3Geometry_GetAttributeSet()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Geometry_GetAttributeSet(TQ3GeometryObject geometry, TQ3AttributeSet *attributeSet);

	/*
	 *  Q3Geometry_SetAttributeSet()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Geometry_SetAttributeSet(TQ3GeometryObject geometry, TQ3AttributeSet attributeSet);

	/*
	 *  Q3Geometry_Submit()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Geometry_Submit(TQ3GeometryObject geometry, TQ3ViewObject view);

/******************************************************************************
 **                                                                          **
 **                         Box Data Structure Definitions                   **
 **                                                                          **
 *****************************************************************************/
#endif /* CALL_NOT_IN_CARBON */

	struct TQ3BoxData
	{
		TQ3Point3D origin;
		TQ3Vector3D orientation;
		TQ3Vector3D majorAxis;
		TQ3Vector3D minorAxis;
		TQ3AttributeSet *faceAttributeSet; /* Ordering : Left, right,    */
										   /*           front, back,   */
										   /*           top, bottom    */
		TQ3AttributeSet boxAttributeSet;
	};
	typedef struct TQ3BoxData TQ3BoxData;
/******************************************************************************
 **                                                                          **
 **                             Box Routines                                 **
 **                                                                          **
 *****************************************************************************/
#if CALL_NOT_IN_CARBON
	/*
	 *  Q3Box_New()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3GeometryObject)
	Q3Box_New(const TQ3BoxData *boxData);

	/*
	 *  Q3Box_Submit()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Box_Submit(const TQ3BoxData *boxData, TQ3ViewObject view);

	/*
	 *  Q3Box_SetData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Box_SetData(TQ3GeometryObject box, const TQ3BoxData *boxData);

	/*
	 *  Q3Box_GetData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Box_GetData(TQ3GeometryObject box, TQ3BoxData *boxData);

	/*
	 *  Q3Box_EmptyData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Box_EmptyData(TQ3BoxData *boxData);

	/*
	 *  Q3Box_SetOrigin()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Box_SetOrigin(TQ3GeometryObject box, const TQ3Point3D *origin);

	/*
	 *  Q3Box_SetOrientation()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Box_SetOrientation(TQ3GeometryObject box, const TQ3Vector3D *orientation);

	/*
	 *  Q3Box_SetMajorAxis()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Box_SetMajorAxis(TQ3GeometryObject box, const TQ3Vector3D *majorAxis);

	/*
	 *  Q3Box_SetMinorAxis()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Box_SetMinorAxis(TQ3GeometryObject box, const TQ3Vector3D *minorAxis);

	/*
	 *  Q3Box_GetOrigin()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Box_GetOrigin(TQ3GeometryObject box, TQ3Point3D *origin);

	/*
	 *  Q3Box_GetOrientation()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Box_GetOrientation(TQ3GeometryObject box, TQ3Vector3D *orientation);

	/*
	 *  Q3Box_GetMajorAxis()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Box_GetMajorAxis(TQ3GeometryObject box, TQ3Vector3D *majorAxis);

	/*
	 *  Q3Box_GetMinorAxis()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Box_GetMinorAxis(TQ3GeometryObject box, TQ3Vector3D *minorAxis);

	/*
	 *  Q3Box_GetFaceAttributeSet()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Box_GetFaceAttributeSet(TQ3GeometryObject box, unsigned long faceIndex, TQ3AttributeSet *faceAttributeSet);

	/*
	 *  Q3Box_SetFaceAttributeSet()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Box_SetFaceAttributeSet(TQ3GeometryObject box, unsigned long faceIndex, TQ3AttributeSet faceAttributeSet);

/******************************************************************************
 **                                                                          **
 **                     Cone Data Structure Definitions                      **
 **                                                                          **
 *****************************************************************************/
#endif /* CALL_NOT_IN_CARBON */

	struct TQ3ConeData
	{
		TQ3Point3D origin;
		TQ3Vector3D orientation;
		TQ3Vector3D majorRadius;
		TQ3Vector3D minorRadius;
		float uMin;
		float uMax;
		float vMin;
		float vMax;
		TQ3EndCap caps;
		TQ3AttributeSet interiorAttributeSet;
		TQ3AttributeSet faceAttributeSet;
		TQ3AttributeSet bottomAttributeSet;
		TQ3AttributeSet coneAttributeSet;
	};
	typedef struct TQ3ConeData TQ3ConeData;
/******************************************************************************
 **                                                                          **
 **                             Cone Routines                                **
 **                                                                          **
 *****************************************************************************/
#if CALL_NOT_IN_CARBON
	/*
	 *  Q3Cone_New()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3GeometryObject)
	Q3Cone_New(const TQ3ConeData *coneData);

	/*
	 *  Q3Cone_Submit()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Cone_Submit(const TQ3ConeData *coneData, TQ3ViewObject view);

	/*
	 *  Q3Cone_SetData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Cone_SetData(TQ3GeometryObject cone, const TQ3ConeData *coneData);

	/*
	 *  Q3Cone_GetData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Cone_GetData(TQ3GeometryObject cone, TQ3ConeData *coneData);

	/*
	 *  Q3Cone_SetOrigin()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Cone_SetOrigin(TQ3GeometryObject cone, const TQ3Point3D *origin);

	/*
	 *  Q3Cone_SetOrientation()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Cone_SetOrientation(TQ3GeometryObject cone, const TQ3Vector3D *orientation);

	/*
	 *  Q3Cone_SetMajorRadius()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Cone_SetMajorRadius(TQ3GeometryObject cone, const TQ3Vector3D *majorRadius);

	/*
	 *  Q3Cone_SetMinorRadius()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Cone_SetMinorRadius(TQ3GeometryObject cone, const TQ3Vector3D *minorRadius);

	/*
	 *  Q3Cone_GetOrigin()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Cone_GetOrigin(TQ3GeometryObject cone, TQ3Point3D *origin);

	/*
	 *  Q3Cone_GetOrientation()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Cone_GetOrientation(TQ3GeometryObject cone, TQ3Vector3D *orientation);

	/*
	 *  Q3Cone_GetMajorRadius()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Cone_GetMajorRadius(TQ3GeometryObject cone, TQ3Vector3D *majorRadius);

	/*
	 *  Q3Cone_GetMinorRadius()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Cone_GetMinorRadius(TQ3GeometryObject cone, TQ3Vector3D *minorRadius);

	/*
	 *  Q3Cone_SetCaps()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Cone_SetCaps(TQ3GeometryObject cone, TQ3EndCap caps);

	/*
	 *  Q3Cone_GetCaps()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Cone_GetCaps(TQ3GeometryObject cone, TQ3EndCap *caps);

	/*
	 *  Q3Cone_SetBottomAttributeSet()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Cone_SetBottomAttributeSet(TQ3GeometryObject cone, TQ3AttributeSet bottomAttributeSet);

	/*
	 *  Q3Cone_GetBottomAttributeSet()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Cone_GetBottomAttributeSet(TQ3GeometryObject cone, TQ3AttributeSet *bottomAttributeSet);

	/*
	 *  Q3Cone_SetFaceAttributeSet()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Cone_SetFaceAttributeSet(TQ3GeometryObject cone, TQ3AttributeSet faceAttributeSet);

	/*
	 *  Q3Cone_GetFaceAttributeSet()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Cone_GetFaceAttributeSet(TQ3GeometryObject cone, TQ3AttributeSet *faceAttributeSet);

	/*
	 *  Q3Cone_EmptyData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Cone_EmptyData(TQ3ConeData *coneData);

/******************************************************************************
 **                                                                          **
 **                     Cylinder Data Structure Definitions                  **
 **                                                                          **
 *****************************************************************************/
#endif /* CALL_NOT_IN_CARBON */

	struct TQ3CylinderData
	{
		TQ3Point3D origin;
		TQ3Vector3D orientation;
		TQ3Vector3D majorRadius;
		TQ3Vector3D minorRadius;
		float uMin;
		float uMax;
		float vMin;
		float vMax;
		TQ3EndCap caps;
		TQ3AttributeSet interiorAttributeSet;
		TQ3AttributeSet topAttributeSet;
		TQ3AttributeSet faceAttributeSet;
		TQ3AttributeSet bottomAttributeSet;
		TQ3AttributeSet cylinderAttributeSet;
	};
	typedef struct TQ3CylinderData TQ3CylinderData;
/******************************************************************************
 **                                                                          **
 **                         Cylinder Routines                                **
 **                                                                          **
 *****************************************************************************/
#if CALL_NOT_IN_CARBON
	/*
	 *  Q3Cylinder_New()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3GeometryObject)
	Q3Cylinder_New(const TQ3CylinderData *cylinderData);

	/*
	 *  Q3Cylinder_Submit()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Cylinder_Submit(const TQ3CylinderData *cylinderData, TQ3ViewObject view);

	/*
	 *  Q3Cylinder_SetData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Cylinder_SetData(TQ3GeometryObject cylinder, const TQ3CylinderData *cylinderData);

	/*
	 *  Q3Cylinder_GetData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Cylinder_GetData(TQ3GeometryObject cylinder, TQ3CylinderData *cylinderData);

	/*
	 *  Q3Cylinder_SetOrigin()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Cylinder_SetOrigin(TQ3GeometryObject cylinder, const TQ3Point3D *origin);

	/*
	 *  Q3Cylinder_SetOrientation()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Cylinder_SetOrientation(TQ3GeometryObject cylinder, const TQ3Vector3D *orientation);

	/*
	 *  Q3Cylinder_SetMajorRadius()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Cylinder_SetMajorRadius(TQ3GeometryObject cylinder, const TQ3Vector3D *majorRadius);

	/*
	 *  Q3Cylinder_SetMinorRadius()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Cylinder_SetMinorRadius(TQ3GeometryObject cylinder, const TQ3Vector3D *minorRadius);

	/*
	 *  Q3Cylinder_GetOrigin()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Cylinder_GetOrigin(TQ3GeometryObject cylinder, TQ3Point3D *origin);

	/*
	 *  Q3Cylinder_GetOrientation()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Cylinder_GetOrientation(TQ3GeometryObject cylinder, TQ3Vector3D *orientation);

	/*
	 *  Q3Cylinder_GetMajorRadius()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Cylinder_GetMajorRadius(TQ3GeometryObject cylinder, TQ3Vector3D *majorRadius);

	/*
	 *  Q3Cylinder_GetMinorRadius()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Cylinder_GetMinorRadius(TQ3GeometryObject cylinder, TQ3Vector3D *minorRadius);

	/*
	 *  Q3Cylinder_SetCaps()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Cylinder_SetCaps(TQ3GeometryObject cylinder, TQ3EndCap caps);

	/*
	 *  Q3Cylinder_GetCaps()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Cylinder_GetCaps(TQ3GeometryObject cylinder, TQ3EndCap *caps);

	/*
	 *  Q3Cylinder_SetTopAttributeSet()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Cylinder_SetTopAttributeSet(TQ3GeometryObject cylinder, TQ3AttributeSet topAttributeSet);

	/*
	 *  Q3Cylinder_GetTopAttributeSet()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Cylinder_GetTopAttributeSet(TQ3GeometryObject cylinder, TQ3AttributeSet *topAttributeSet);

	/*
	 *  Q3Cylinder_SetBottomAttributeSet()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Cylinder_SetBottomAttributeSet(TQ3GeometryObject cylinder, TQ3AttributeSet bottomAttributeSet);

	/*
	 *  Q3Cylinder_GetBottomAttributeSet()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Cylinder_GetBottomAttributeSet(TQ3GeometryObject cylinder, TQ3AttributeSet *bottomAttributeSet);

	/*
	 *  Q3Cylinder_SetFaceAttributeSet()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Cylinder_SetFaceAttributeSet(TQ3GeometryObject cylinder, TQ3AttributeSet faceAttributeSet);

	/*
	 *  Q3Cylinder_GetFaceAttributeSet()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Cylinder_GetFaceAttributeSet(TQ3GeometryObject cylinder, TQ3AttributeSet *faceAttributeSet);

	/*
	 *  Q3Cylinder_EmptyData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Cylinder_EmptyData(TQ3CylinderData *cylinderData);

/******************************************************************************
 **                                                                          **
 **                     Disk Data Structure Definitions                      **
 **                                                                          **
 *****************************************************************************/
#endif /* CALL_NOT_IN_CARBON */

	struct TQ3DiskData
	{
		TQ3Point3D origin;
		TQ3Vector3D majorRadius;
		TQ3Vector3D minorRadius;
		float uMin;
		float uMax;
		float vMin;
		float vMax;
		TQ3AttributeSet diskAttributeSet;
	};
	typedef struct TQ3DiskData TQ3DiskData;
/******************************************************************************
 **                                                                          **
 **                             Disk Routines                                **
 **                                                                          **
 *****************************************************************************/
#if CALL_NOT_IN_CARBON
	/*
	 *  Q3Disk_New()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3GeometryObject)
	Q3Disk_New(const TQ3DiskData *diskData);

	/*
	 *  Q3Disk_Submit()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Disk_Submit(const TQ3DiskData *diskData, TQ3ViewObject view);

	/*
	 *  Q3Disk_SetData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Disk_SetData(TQ3GeometryObject disk, const TQ3DiskData *diskData);

	/*
	 *  Q3Disk_GetData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Disk_GetData(TQ3GeometryObject disk, TQ3DiskData *diskData);

	/*
	 *  Q3Disk_SetOrigin()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Disk_SetOrigin(TQ3GeometryObject disk, const TQ3Point3D *origin);

	/*
	 *  Q3Disk_SetMajorRadius()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Disk_SetMajorRadius(TQ3GeometryObject disk, const TQ3Vector3D *majorRadius);

	/*
	 *  Q3Disk_SetMinorRadius()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Disk_SetMinorRadius(TQ3GeometryObject disk, const TQ3Vector3D *minorRadius);

	/*
	 *  Q3Disk_GetOrigin()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Disk_GetOrigin(TQ3GeometryObject disk, TQ3Point3D *origin);

	/*
	 *  Q3Disk_GetMajorRadius()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Disk_GetMajorRadius(TQ3GeometryObject disk, TQ3Vector3D *majorRadius);

	/*
	 *  Q3Disk_GetMinorRadius()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Disk_GetMinorRadius(TQ3GeometryObject disk, TQ3Vector3D *minorRadius);

	/*
	 *  Q3Disk_EmptyData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Disk_EmptyData(TQ3DiskData *diskData);

/******************************************************************************
 **                                                                          **
 **                  Ellipse Data Structure Definitions                      **
 **                                                                          **
 *****************************************************************************/
#endif /* CALL_NOT_IN_CARBON */

	struct TQ3EllipseData
	{
		TQ3Point3D origin;
		TQ3Vector3D majorRadius;
		TQ3Vector3D minorRadius;
		float uMin;
		float uMax;
		TQ3AttributeSet ellipseAttributeSet;
	};
	typedef struct TQ3EllipseData TQ3EllipseData;
/******************************************************************************
 **                                                                          **
 **                             Ellipse Routines                             **
 **                                                                          **
 *****************************************************************************/
#if CALL_NOT_IN_CARBON
	/*
	 *  Q3Ellipse_New()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3GeometryObject)
	Q3Ellipse_New(const TQ3EllipseData *ellipseData);

	/*
	 *  Q3Ellipse_Submit()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Ellipse_Submit(const TQ3EllipseData *ellipseData, TQ3ViewObject view);

	/*
	 *  Q3Ellipse_SetData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Ellipse_SetData(TQ3GeometryObject ellipse, const TQ3EllipseData *ellipseData);

	/*
	 *  Q3Ellipse_GetData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Ellipse_GetData(TQ3GeometryObject ellipse, TQ3EllipseData *ellipseData);

	/*
	 *  Q3Ellipse_SetOrigin()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Ellipse_SetOrigin(TQ3GeometryObject ellipse, const TQ3Point3D *origin);

	/*
	 *  Q3Ellipse_SetMajorRadius()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Ellipse_SetMajorRadius(TQ3GeometryObject ellipse, const TQ3Vector3D *majorRadius);

	/*
	 *  Q3Ellipse_SetMinorRadius()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Ellipse_SetMinorRadius(TQ3GeometryObject ellipse, const TQ3Vector3D *minorRadius);

	/*
	 *  Q3Ellipse_GetOrigin()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Ellipse_GetOrigin(TQ3GeometryObject ellipse, TQ3Point3D *origin);

	/*
	 *  Q3Ellipse_GetMajorRadius()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Ellipse_GetMajorRadius(TQ3GeometryObject ellipse, TQ3Vector3D *majorRadius);

	/*
	 *  Q3Ellipse_GetMinorRadius()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Ellipse_GetMinorRadius(TQ3GeometryObject ellipse, TQ3Vector3D *minorRadius);

	/*
	 *  Q3Ellipse_EmptyData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Ellipse_EmptyData(TQ3EllipseData *ellipseData);

/******************************************************************************
 **                                                                          **
 **                         Ellipsoid Data structures                        **
 **                                                                          **
 *****************************************************************************/
#endif /* CALL_NOT_IN_CARBON */

	struct TQ3EllipsoidData
	{
		TQ3Point3D origin;
		TQ3Vector3D orientation;
		TQ3Vector3D majorRadius;
		TQ3Vector3D minorRadius;
		float uMin;
		float uMax;
		float vMin;
		float vMax;
		TQ3EndCap caps;
		TQ3AttributeSet interiorAttributeSet;
		TQ3AttributeSet ellipsoidAttributeSet;
	};
	typedef struct TQ3EllipsoidData TQ3EllipsoidData;
/******************************************************************************
 **                                                                          **
 **                         Ellipsoid Routines                               **
 **                                                                          **
 *****************************************************************************/
#if CALL_NOT_IN_CARBON
	/*
	 *  Q3Ellipsoid_New()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3GeometryObject)
	Q3Ellipsoid_New(const TQ3EllipsoidData *ellipsoidData);

	/*
	 *  Q3Ellipsoid_Submit()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Ellipsoid_Submit(const TQ3EllipsoidData *ellipsoidData, TQ3ViewObject view);

	/*
	 *  Q3Ellipsoid_SetData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Ellipsoid_SetData(TQ3GeometryObject ellipsoid, const TQ3EllipsoidData *ellipsoidData);

	/*
	 *  Q3Ellipsoid_GetData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Ellipsoid_GetData(TQ3GeometryObject ellipsoid, TQ3EllipsoidData *ellipsoidData);

	/*
	 *  Q3Ellipsoid_SetOrigin()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Ellipsoid_SetOrigin(TQ3GeometryObject ellipsoid, const TQ3Point3D *origin);

	/*
	 *  Q3Ellipsoid_SetOrientation()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Ellipsoid_SetOrientation(TQ3GeometryObject ellipsoid, const TQ3Vector3D *orientation);

	/*
	 *  Q3Ellipsoid_SetMajorRadius()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Ellipsoid_SetMajorRadius(TQ3GeometryObject ellipsoid, const TQ3Vector3D *majorRadius);

	/*
	 *  Q3Ellipsoid_SetMinorRadius()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Ellipsoid_SetMinorRadius(TQ3GeometryObject ellipsoid, const TQ3Vector3D *minorRadius);

	/*
	 *  Q3Ellipsoid_GetOrigin()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Ellipsoid_GetOrigin(TQ3GeometryObject ellipsoid, TQ3Point3D *origin);

	/*
	 *  Q3Ellipsoid_GetOrientation()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Ellipsoid_GetOrientation(TQ3GeometryObject ellipsoid, TQ3Vector3D *orientation);

	/*
	 *  Q3Ellipsoid_GetMajorRadius()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Ellipsoid_GetMajorRadius(TQ3GeometryObject ellipsoid, TQ3Vector3D *majorRadius);

	/*
	 *  Q3Ellipsoid_GetMinorRadius()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Ellipsoid_GetMinorRadius(TQ3GeometryObject ellipsoid, TQ3Vector3D *minorRadius);

	/*
	 *  Q3Ellipsoid_EmptyData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Ellipsoid_EmptyData(TQ3EllipsoidData *ellipsoidData);

/******************************************************************************
 **                                                                          **
 **                 General Polygon Data Structure Definitions               **
 **                                                                          **
 *****************************************************************************/
#endif /* CALL_NOT_IN_CARBON */

	enum TQ3GeneralPolygonShapeHint
	{
		kQ3GeneralPolygonShapeHintComplex = 0,
		kQ3GeneralPolygonShapeHintConcave = 1,
		kQ3GeneralPolygonShapeHintConvex = 2
	};
	typedef enum TQ3GeneralPolygonShapeHint TQ3GeneralPolygonShapeHint;

	struct TQ3GeneralPolygonContourData
	{
		unsigned long numVertices;
		TQ3Vertex3D *vertices;
	};
	typedef struct TQ3GeneralPolygonContourData TQ3GeneralPolygonContourData;
	struct TQ3GeneralPolygonData
	{
		unsigned long numContours;
		TQ3GeneralPolygonContourData *contours;
		TQ3GeneralPolygonShapeHint shapeHint;
		TQ3AttributeSet generalPolygonAttributeSet;
	};
	typedef struct TQ3GeneralPolygonData TQ3GeneralPolygonData;
/******************************************************************************
 **                                                                          **
 **                         General polygon Routines                         **
 **                                                                          **
 *****************************************************************************/
#if CALL_NOT_IN_CARBON
	/*
	 *  Q3GeneralPolygon_New()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3GeometryObject)
	Q3GeneralPolygon_New(const TQ3GeneralPolygonData *generalPolygonData);

	/*
	 *  Q3GeneralPolygon_Submit()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3GeneralPolygon_Submit(const TQ3GeneralPolygonData *generalPolygonData, TQ3ViewObject view);

	/*
	 *  Q3GeneralPolygon_SetData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3GeneralPolygon_SetData(TQ3GeometryObject generalPolygon, const TQ3GeneralPolygonData *generalPolygonData);

	/*
	 *  Q3GeneralPolygon_GetData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3GeneralPolygon_GetData(TQ3GeometryObject polygon, TQ3GeneralPolygonData *generalPolygonData);

	/*
	 *  Q3GeneralPolygon_EmptyData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3GeneralPolygon_EmptyData(TQ3GeneralPolygonData *generalPolygonData);

	/*
	 *  Q3GeneralPolygon_GetVertexPosition()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3GeneralPolygon_GetVertexPosition(TQ3GeometryObject generalPolygon, unsigned long contourIndex,
									   unsigned long pointIndex, TQ3Point3D *position);

	/*
	 *  Q3GeneralPolygon_SetVertexPosition()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3GeneralPolygon_SetVertexPosition(TQ3GeometryObject generalPolygon, unsigned long contourIndex,
									   unsigned long pointIndex, const TQ3Point3D *position);

	/*
	 *  Q3GeneralPolygon_GetVertexAttributeSet()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3GeneralPolygon_GetVertexAttributeSet(TQ3GeometryObject generalPolygon, unsigned long contourIndex,
										   unsigned long pointIndex, TQ3AttributeSet *attributeSet);

	/*
	 *  Q3GeneralPolygon_SetVertexAttributeSet()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3GeneralPolygon_SetVertexAttributeSet(TQ3GeometryObject generalPolygon, unsigned long contourIndex,
										   unsigned long pointIndex, TQ3AttributeSet attributeSet);

	/*
	 *  Q3GeneralPolygon_SetShapeHint()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3GeneralPolygon_SetShapeHint(TQ3GeometryObject generalPolygon, TQ3GeneralPolygonShapeHint shapeHint);

	/*
	 *  Q3GeneralPolygon_GetShapeHint()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3GeneralPolygon_GetShapeHint(TQ3GeometryObject generalPolygon, TQ3GeneralPolygonShapeHint *shapeHint);

/******************************************************************************
 **                                                                          **
 **                     Line Data Structure Definitions                      **
 **                                                                          **
 *****************************************************************************/
#endif /* CALL_NOT_IN_CARBON */

	struct TQ3LineData
	{
		TQ3Vertex3D vertices[2];
		TQ3AttributeSet lineAttributeSet;
	};
	typedef struct TQ3LineData TQ3LineData;
/******************************************************************************
 **                                                                          **
 **                         Line Routines                                    **
 **                                                                          **
 *****************************************************************************/
#if CALL_NOT_IN_CARBON
	/*
	 *  Q3Line_New()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3GeometryObject)
	Q3Line_New(const TQ3LineData *lineData);

	/*
	 *  Q3Line_Submit()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Line_Submit(const TQ3LineData *lineData, TQ3ViewObject view);

	/*
	 *  Q3Line_GetData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Line_GetData(TQ3GeometryObject line, TQ3LineData *lineData);

	/*
	 *  Q3Line_SetData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Line_SetData(TQ3GeometryObject line, const TQ3LineData *lineData);

	/*
	 *  Q3Line_GetVertexPosition()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Line_GetVertexPosition(TQ3GeometryObject line, unsigned long index, TQ3Point3D *position);

	/*
	 *  Q3Line_SetVertexPosition()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Line_SetVertexPosition(TQ3GeometryObject line, unsigned long index, const TQ3Point3D *position);

	/*
	 *  Q3Line_GetVertexAttributeSet()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Line_GetVertexAttributeSet(TQ3GeometryObject line, unsigned long index, TQ3AttributeSet *attributeSet);

	/*
	 *  Q3Line_SetVertexAttributeSet()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Line_SetVertexAttributeSet(TQ3GeometryObject line, unsigned long index, TQ3AttributeSet attributeSet);

	/*
	 *  Q3Line_EmptyData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Line_EmptyData(TQ3LineData *lineData);

/******************************************************************************
 **                                                                          **
 **                     Marker Data Structure Definitions                    **
 **                                                                          **
 *****************************************************************************/
#endif /* CALL_NOT_IN_CARBON */

	struct TQ3MarkerData
	{
		TQ3Point3D location;
		long xOffset;
		long yOffset;
		TQ3Bitmap bitmap;
		TQ3AttributeSet markerAttributeSet;
	};
	typedef struct TQ3MarkerData TQ3MarkerData;
/******************************************************************************
 **                                                                          **
 **                             Marker Routines                              **
 **                                                                          **
 *****************************************************************************/
#if CALL_NOT_IN_CARBON
	/*
	 *  Q3Marker_New()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3GeometryObject)
	Q3Marker_New(const TQ3MarkerData *markerData);

	/*
	 *  Q3Marker_Submit()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Marker_Submit(const TQ3MarkerData *markerData, TQ3ViewObject view);

	/*
	 *  Q3Marker_SetData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Marker_SetData(TQ3GeometryObject geometry, const TQ3MarkerData *markerData);

	/*
	 *  Q3Marker_GetData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Marker_GetData(TQ3GeometryObject geometry, TQ3MarkerData *markerData);

	/*
	 *  Q3Marker_EmptyData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Marker_EmptyData(TQ3MarkerData *markerData);

	/*
	 *  Q3Marker_GetPosition()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Marker_GetPosition(TQ3GeometryObject marker, TQ3Point3D *location);

	/*
	 *  Q3Marker_SetPosition()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Marker_SetPosition(TQ3GeometryObject marker, const TQ3Point3D *location);

	/*
	 *  Q3Marker_GetXOffset()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Marker_GetXOffset(TQ3GeometryObject marker, long *xOffset);

	/*
	 *  Q3Marker_SetXOffset()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Marker_SetXOffset(TQ3GeometryObject marker, long xOffset);

	/*
	 *  Q3Marker_GetYOffset()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Marker_GetYOffset(TQ3GeometryObject marker, long *yOffset);

	/*
	 *  Q3Marker_SetYOffset()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Marker_SetYOffset(TQ3GeometryObject marker, long yOffset);

	/*
	 *  Q3Marker_GetBitmap()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Marker_GetBitmap(TQ3GeometryObject marker, TQ3Bitmap *bitmap);

	/*
	 *  Q3Marker_SetBitmap()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Marker_SetBitmap(TQ3GeometryObject marker, const TQ3Bitmap *bitmap);

/******************************************************************************
 **                                                                          **
 **                     Mesh Data Structure Definitions                      **
 **                                                                          **
 *****************************************************************************/
#endif /* CALL_NOT_IN_CARBON */

	typedef struct OpaqueTQ3MeshComponent *TQ3MeshComponent;
	typedef struct OpaqueTQ3MeshVertex *TQ3MeshVertex;
	typedef struct OpaqueTQ3MeshFace *TQ3MeshFace;
	typedef struct OpaqueTQ3MeshEdge *TQ3MeshEdge;
	typedef struct OpaqueTQ3MeshContour *TQ3MeshContour;
/******************************************************************************
 **                                                                          **
 **                         Mesh Routines                                    **
 **                                                                          **
 *****************************************************************************/
/*
 *  Constructors
 */
#if CALL_NOT_IN_CARBON
	/*
	 *  Q3Mesh_New()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3GeometryObject)
	Q3Mesh_New(void);

	/*
	 *  Q3Mesh_VertexNew()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3MeshVertex)
	Q3Mesh_VertexNew(TQ3GeometryObject mesh, const TQ3Vertex3D *vertex);

	/*
	 *  Q3Mesh_FaceNew()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3MeshFace)
	Q3Mesh_FaceNew(TQ3GeometryObject mesh, unsigned long numVertices, const TQ3MeshVertex *vertices,
				   TQ3AttributeSet attributeSet);

	/*
	 *  Destructors
	 */
	/*
	 *  Q3Mesh_VertexDelete()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Mesh_VertexDelete(TQ3GeometryObject mesh, TQ3MeshVertex vertex);

	/*
	 *  Q3Mesh_FaceDelete()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Mesh_FaceDelete(TQ3GeometryObject mesh, TQ3MeshFace face);

	/*
	 * Methods
	 */
	/*
	 *  Q3Mesh_DelayUpdates()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Mesh_DelayUpdates(TQ3GeometryObject mesh);

	/*
	 *  Q3Mesh_ResumeUpdates()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Mesh_ResumeUpdates(TQ3GeometryObject mesh);

	/*
	 *  Q3Mesh_FaceToContour()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3MeshContour)
	Q3Mesh_FaceToContour(TQ3GeometryObject mesh, TQ3MeshFace containerFace, TQ3MeshFace face);

	/*
	 *  Q3Mesh_ContourToFace()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3MeshFace)
	Q3Mesh_ContourToFace(TQ3GeometryObject mesh, TQ3MeshContour contour);

	/*
	 * Mesh
	 */
	/*
	 *  Q3Mesh_GetNumComponents()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Mesh_GetNumComponents(TQ3GeometryObject mesh, unsigned long *numComponents);

	/*
	 *  Q3Mesh_GetNumEdges()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Mesh_GetNumEdges(TQ3GeometryObject mesh, unsigned long *numEdges);

	/*
	 *  Q3Mesh_GetNumVertices()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Mesh_GetNumVertices(TQ3GeometryObject mesh, unsigned long *numVertices);

	/*
	 *  Q3Mesh_GetNumFaces()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Mesh_GetNumFaces(TQ3GeometryObject mesh, unsigned long *numFaces);

	/*
	 *  Q3Mesh_GetNumCorners()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Mesh_GetNumCorners(TQ3GeometryObject mesh, unsigned long *numCorners);

	/*
	 *  Q3Mesh_GetOrientable()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Mesh_GetOrientable(TQ3GeometryObject mesh, TQ3Boolean *orientable);

	/*
	 * Component
	 */
	/*
	 *  Q3Mesh_GetComponentNumVertices()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Mesh_GetComponentNumVertices(TQ3GeometryObject mesh, TQ3MeshComponent component, unsigned long *numVertices);

	/*
	 *  Q3Mesh_GetComponentNumEdges()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Mesh_GetComponentNumEdges(TQ3GeometryObject mesh, TQ3MeshComponent component, unsigned long *numEdges);

	/*
	 *  Q3Mesh_GetComponentBoundingBox()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Mesh_GetComponentBoundingBox(TQ3GeometryObject mesh, TQ3MeshComponent component, TQ3BoundingBox *boundingBox);

	/*
	 *  Q3Mesh_GetComponentOrientable()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Mesh_GetComponentOrientable(TQ3GeometryObject mesh, TQ3MeshComponent component, TQ3Boolean *orientable);

	/*
	 * Vertex
	 */
	/*
	 *  Q3Mesh_GetVertexCoordinates()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Mesh_GetVertexCoordinates(TQ3GeometryObject mesh, TQ3MeshVertex vertex, TQ3Point3D *coordinates);

	/*
	 *  Q3Mesh_GetVertexIndex()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Mesh_GetVertexIndex(TQ3GeometryObject mesh, TQ3MeshVertex vertex, unsigned long *index);

	/*
	 *  Q3Mesh_GetVertexOnBoundary()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Mesh_GetVertexOnBoundary(TQ3GeometryObject mesh, TQ3MeshVertex vertex, TQ3Boolean *onBoundary);

	/*
	 *  Q3Mesh_GetVertexComponent()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Mesh_GetVertexComponent(TQ3GeometryObject mesh, TQ3MeshVertex vertex, TQ3MeshComponent *component);

	/*
	 *  Q3Mesh_GetVertexAttributeSet()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Mesh_GetVertexAttributeSet(TQ3GeometryObject mesh, TQ3MeshVertex vertex, TQ3AttributeSet *attributeSet);

	/*
	 *  Q3Mesh_SetVertexCoordinates()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Mesh_SetVertexCoordinates(TQ3GeometryObject mesh, TQ3MeshVertex vertex, const TQ3Point3D *coordinates);

	/*
	 *  Q3Mesh_SetVertexAttributeSet()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Mesh_SetVertexAttributeSet(TQ3GeometryObject mesh, TQ3MeshVertex vertex, TQ3AttributeSet attributeSet);

	/*
	 * Face
	 */
	/*
	 *  Q3Mesh_GetFaceNumVertices()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Mesh_GetFaceNumVertices(TQ3GeometryObject mesh, TQ3MeshFace face, unsigned long *numVertices);

	/*
	 *  Q3Mesh_GetFacePlaneEquation()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Mesh_GetFacePlaneEquation(TQ3GeometryObject mesh, TQ3MeshFace face, TQ3PlaneEquation *planeEquation);

	/*
	 *  Q3Mesh_GetFaceNumContours()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Mesh_GetFaceNumContours(TQ3GeometryObject mesh, TQ3MeshFace face, unsigned long *numContours);

	/*
	 *  Q3Mesh_GetFaceIndex()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Mesh_GetFaceIndex(TQ3GeometryObject mesh, TQ3MeshFace face, unsigned long *index);

	/*
	 *  Q3Mesh_GetFaceComponent()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Mesh_GetFaceComponent(TQ3GeometryObject mesh, TQ3MeshFace face, TQ3MeshComponent *component);

	/*
	 *  Q3Mesh_GetFaceAttributeSet()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Mesh_GetFaceAttributeSet(TQ3GeometryObject mesh, TQ3MeshFace face, TQ3AttributeSet *attributeSet);

	/*
	 *  Q3Mesh_SetFaceAttributeSet()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Mesh_SetFaceAttributeSet(TQ3GeometryObject mesh, TQ3MeshFace face, TQ3AttributeSet attributeSet);

	/*
	 * Edge
	 */
	/*
	 *  Q3Mesh_GetEdgeVertices()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Mesh_GetEdgeVertices(TQ3GeometryObject mesh, TQ3MeshEdge edge, TQ3MeshVertex *vertex1, TQ3MeshVertex *vertex2);

	/*
	 *  Q3Mesh_GetEdgeFaces()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Mesh_GetEdgeFaces(TQ3GeometryObject mesh, TQ3MeshEdge edge, TQ3MeshFace *face1, TQ3MeshFace *face2);

	/*
	 *  Q3Mesh_GetEdgeOnBoundary()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Mesh_GetEdgeOnBoundary(TQ3GeometryObject mesh, TQ3MeshEdge edge, TQ3Boolean *onBoundary);

	/*
	 *  Q3Mesh_GetEdgeComponent()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Mesh_GetEdgeComponent(TQ3GeometryObject mesh, TQ3MeshEdge edge, TQ3MeshComponent *component);

	/*
	 *  Q3Mesh_GetEdgeAttributeSet()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Mesh_GetEdgeAttributeSet(TQ3GeometryObject mesh, TQ3MeshEdge edge, TQ3AttributeSet *attributeSet);

	/*
	 *  Q3Mesh_SetEdgeAttributeSet()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Mesh_SetEdgeAttributeSet(TQ3GeometryObject mesh, TQ3MeshEdge edge, TQ3AttributeSet attributeSet);

	/*
	 * Contour
	 */
	/*
	 *  Q3Mesh_GetContourFace()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Mesh_GetContourFace(TQ3GeometryObject mesh, TQ3MeshContour contour, TQ3MeshFace *face);

	/*
	 *  Q3Mesh_GetContourNumVertices()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Mesh_GetContourNumVertices(TQ3GeometryObject mesh, TQ3MeshContour contour, unsigned long *numVertices);

	/*
	 * Corner
	 */
	/*
	 *  Q3Mesh_GetCornerAttributeSet()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Mesh_GetCornerAttributeSet(TQ3GeometryObject mesh, TQ3MeshVertex vertex, TQ3MeshFace face,
								 TQ3AttributeSet *attributeSet);

	/*
	 *  Q3Mesh_SetCornerAttributeSet()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Mesh_SetCornerAttributeSet(TQ3GeometryObject mesh, TQ3MeshVertex vertex, TQ3MeshFace face,
								 TQ3AttributeSet attributeSet);

/*
 * Public Mesh Iterators
 */
#endif /* CALL_NOT_IN_CARBON */

	struct TQ3MeshIterator
	{
		void *var1;
		void *var2;
		void *var3;
		struct
		{
			void *field1;
			char field2[4];
		} var4;
	};
	typedef struct TQ3MeshIterator TQ3MeshIterator;
#if CALL_NOT_IN_CARBON
	/*
	 *  Q3Mesh_FirstMeshComponent()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3MeshComponent)
	Q3Mesh_FirstMeshComponent(TQ3GeometryObject mesh, TQ3MeshIterator *iterator);

	/*
	 *  Q3Mesh_NextMeshComponent()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3MeshComponent)
	Q3Mesh_NextMeshComponent(TQ3MeshIterator *iterator);

	/*
	 *  Q3Mesh_FirstComponentVertex()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3MeshVertex)
	Q3Mesh_FirstComponentVertex(TQ3MeshComponent component, TQ3MeshIterator *iterator);

	/*
	 *  Q3Mesh_NextComponentVertex()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3MeshVertex)
	Q3Mesh_NextComponentVertex(TQ3MeshIterator *iterator);

	/*
	 *  Q3Mesh_FirstComponentEdge()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3MeshEdge)
	Q3Mesh_FirstComponentEdge(TQ3MeshComponent component, TQ3MeshIterator *iterator);

	/*
	 *  Q3Mesh_NextComponentEdge()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3MeshEdge)
	Q3Mesh_NextComponentEdge(TQ3MeshIterator *iterator);

	/*
	 *  Q3Mesh_FirstMeshVertex()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3MeshVertex)
	Q3Mesh_FirstMeshVertex(TQ3GeometryObject mesh, TQ3MeshIterator *iterator);

	/*
	 *  Q3Mesh_NextMeshVertex()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3MeshVertex)
	Q3Mesh_NextMeshVertex(TQ3MeshIterator *iterator);

	/*
	 *  Q3Mesh_FirstMeshFace()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3MeshFace)
	Q3Mesh_FirstMeshFace(TQ3GeometryObject mesh, TQ3MeshIterator *iterator);

	/*
	 *  Q3Mesh_NextMeshFace()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3MeshFace)
	Q3Mesh_NextMeshFace(TQ3MeshIterator *iterator);

	/*
	 *  Q3Mesh_FirstMeshEdge()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3MeshEdge)
	Q3Mesh_FirstMeshEdge(TQ3GeometryObject mesh, TQ3MeshIterator *iterator);

	/*
	 *  Q3Mesh_NextMeshEdge()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3MeshEdge)
	Q3Mesh_NextMeshEdge(TQ3MeshIterator *iterator);

	/*
	 *  Q3Mesh_FirstVertexEdge()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3MeshEdge)
	Q3Mesh_FirstVertexEdge(TQ3MeshVertex vertex, TQ3MeshIterator *iterator);

	/*
	 *  Q3Mesh_NextVertexEdge()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3MeshEdge)
	Q3Mesh_NextVertexEdge(TQ3MeshIterator *iterator);

	/*
	 *  Q3Mesh_FirstVertexVertex()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3MeshVertex)
	Q3Mesh_FirstVertexVertex(TQ3MeshVertex vertex, TQ3MeshIterator *iterator);

	/*
	 *  Q3Mesh_NextVertexVertex()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3MeshVertex)
	Q3Mesh_NextVertexVertex(TQ3MeshIterator *iterator);

	/*
	 *  Q3Mesh_FirstVertexFace()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3MeshFace)
	Q3Mesh_FirstVertexFace(TQ3MeshVertex vertex, TQ3MeshIterator *iterator);

	/*
	 *  Q3Mesh_NextVertexFace()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3MeshFace)
	Q3Mesh_NextVertexFace(TQ3MeshIterator *iterator);

	/*
	 *  Q3Mesh_FirstFaceEdge()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3MeshEdge)
	Q3Mesh_FirstFaceEdge(TQ3MeshFace face, TQ3MeshIterator *iterator);

	/*
	 *  Q3Mesh_NextFaceEdge()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3MeshEdge)
	Q3Mesh_NextFaceEdge(TQ3MeshIterator *iterator);

	/*
	 *  Q3Mesh_FirstFaceVertex()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3MeshVertex)
	Q3Mesh_FirstFaceVertex(TQ3MeshFace face, TQ3MeshIterator *iterator);

	/*
	 *  Q3Mesh_NextFaceVertex()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3MeshVertex)
	Q3Mesh_NextFaceVertex(TQ3MeshIterator *iterator);

	/*
	 *  Q3Mesh_FirstFaceFace()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3MeshFace)
	Q3Mesh_FirstFaceFace(TQ3MeshFace face, TQ3MeshIterator *iterator);

	/*
	 *  Q3Mesh_NextFaceFace()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3MeshFace)
	Q3Mesh_NextFaceFace(TQ3MeshIterator *iterator);

	/*
	 *  Q3Mesh_FirstFaceContour()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3MeshContour)
	Q3Mesh_FirstFaceContour(TQ3MeshFace face, TQ3MeshIterator *iterator);

	/*
	 *  Q3Mesh_NextFaceContour()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3MeshContour)
	Q3Mesh_NextFaceContour(TQ3MeshIterator *iterator);

	/*
	 *  Q3Mesh_FirstContourEdge()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3MeshEdge)
	Q3Mesh_FirstContourEdge(TQ3MeshContour contour, TQ3MeshIterator *iterator);

	/*
	 *  Q3Mesh_NextContourEdge()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3MeshEdge)
	Q3Mesh_NextContourEdge(TQ3MeshIterator *iterator);

	/*
	 *  Q3Mesh_FirstContourVertex()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3MeshVertex)
	Q3Mesh_FirstContourVertex(TQ3MeshContour contour, TQ3MeshIterator *iterator);

	/*
	 *  Q3Mesh_NextContourVertex()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3MeshVertex)
	Q3Mesh_NextContourVertex(TQ3MeshIterator *iterator);

	/*
	 *  Q3Mesh_FirstContourFace()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3MeshFace)
	Q3Mesh_FirstContourFace(TQ3MeshContour contour, TQ3MeshIterator *iterator);

	/*
	 *  Q3Mesh_NextContourFace()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3MeshFace)
	Q3Mesh_NextContourFace(TQ3MeshIterator *iterator);

#define Q3ForEachMeshComponent(m, c, i) \
	for((c) = Q3Mesh_FirstMeshComponent((m), (i)); (c); (c) = Q3Mesh_NextMeshComponent((i)))

#define Q3ForEachComponentVertex(c, v, i) \
	for((v) = Q3Mesh_FirstComponentVertex((c), (i)); (v); (v) = Q3Mesh_NextComponentVertex((i)))

#define Q3ForEachComponentEdge(c, e, i) \
	for((e) = Q3Mesh_FirstComponentEdge((c), (i)); (e); (e) = Q3Mesh_NextComponentEdge((i)))

#define Q3ForEachMeshVertex(m, v, i) for((v) = Q3Mesh_FirstMeshVertex((m), (i)); (v); (v) = Q3Mesh_NextMeshVertex((i)))

#define Q3ForEachMeshFace(m, f, i) for((f) = Q3Mesh_FirstMeshFace((m), (i)); (f); (f) = Q3Mesh_NextMeshFace((i)))

#define Q3ForEachMeshEdge(m, e, i) for((e) = Q3Mesh_FirstMeshEdge((m), (i)); (e); (e) = Q3Mesh_NextMeshEdge((i)))

#define Q3ForEachVertexEdge(v, e, i) for((e) = Q3Mesh_FirstVertexEdge((v), (i)); (e); (e) = Q3Mesh_NextVertexEdge((i)))

#define Q3ForEachVertexVertex(v, n, i) \
	for((n) = Q3Mesh_FirstVertexVertex((v), (i)); (n); (n) = Q3Mesh_NextVertexVertex((i)))

#define Q3ForEachVertexFace(v, f, i) for((f) = Q3Mesh_FirstVertexFace((v), (i)); (f); (f) = Q3Mesh_NextVertexFace((i)))

#define Q3ForEachFaceEdge(f, e, i) for((e) = Q3Mesh_FirstFaceEdge((f), (i)); (e); (e) = Q3Mesh_NextFaceEdge((i)))

#define Q3ForEachFaceVertex(f, v, i) for((v) = Q3Mesh_FirstFaceVertex((f), (i)); (v); (v) = Q3Mesh_NextFaceVertex((i)))

#define Q3ForEachFaceFace(f, n, i) for((n) = Q3Mesh_FirstFaceFace((f), (i)); (n); (n) = Q3Mesh_NextFaceFace((i)))

#define Q3ForEachFaceContour(f, h, i) \
	for((h) = Q3Mesh_FirstFaceContour((f), (i)); (h); (h) = Q3Mesh_NextFaceContour((i)))

#define Q3ForEachContourEdge(h, e, i) \
	for((e) = Q3Mesh_FirstContourEdge((h), (i)); (e); (e) = Q3Mesh_NextContourEdge((i)))

#define Q3ForEachContourVertex(h, v, i) \
	for((v) = Q3Mesh_FirstContourVertex((h), (i)); (v); (v) = Q3Mesh_NextContourVertex((i)))

#define Q3ForEachContourFace(h, f, i) \
	for((f) = Q3Mesh_FirstContourFace((h), (i)); (f); (f) = Q3Mesh_NextContourFace((i)))

/******************************************************************************
 **                                                                          **
 **                         Maximum order for NURB Curves                    **
 **                                                                          **
 *****************************************************************************/
#define kQ3NURBCurveMaxOrder 16

/******************************************************************************
 **                                                                          **
 **                     NURB Data Structure Definitions                      **
 **                                                                          **
 *****************************************************************************/
#endif /* CALL_NOT_IN_CARBON */

	struct TQ3NURBCurveData
	{
		unsigned long order;
		unsigned long numPoints;
		TQ3RationalPoint4D *controlPoints;
		float *knots;
		TQ3AttributeSet curveAttributeSet;
	};
	typedef struct TQ3NURBCurveData TQ3NURBCurveData;
/******************************************************************************
 **                                                                          **
 **                             NURB Curve Routines                          **
 **                                                                          **
 *****************************************************************************/
#if CALL_NOT_IN_CARBON
	/*
	 *  Q3NURBCurve_New()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3GeometryObject)
	Q3NURBCurve_New(const TQ3NURBCurveData *curveData);

	/*
	 *  Q3NURBCurve_Submit()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3NURBCurve_Submit(const TQ3NURBCurveData *curveData, TQ3ViewObject view);

	/*
	 *  Q3NURBCurve_SetData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3NURBCurve_SetData(TQ3GeometryObject curve, const TQ3NURBCurveData *nurbCurveData);

	/*
	 *  Q3NURBCurve_GetData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3NURBCurve_GetData(TQ3GeometryObject curve, TQ3NURBCurveData *nurbCurveData);

	/*
	 *  Q3NURBCurve_EmptyData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3NURBCurve_EmptyData(TQ3NURBCurveData *nurbCurveData);

	/*
	 *  Q3NURBCurve_SetControlPoint()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3NURBCurve_SetControlPoint(TQ3GeometryObject curve, unsigned long pointIndex, const TQ3RationalPoint4D *point4D);

	/*
	 *  Q3NURBCurve_GetControlPoint()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3NURBCurve_GetControlPoint(TQ3GeometryObject curve, unsigned long pointIndex, TQ3RationalPoint4D *point4D);

	/*
	 *  Q3NURBCurve_SetKnot()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3NURBCurve_SetKnot(TQ3GeometryObject curve, unsigned long knotIndex, float knotValue);

	/*
	 *  Q3NURBCurve_GetKnot()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3NURBCurve_GetKnot(TQ3GeometryObject curve, unsigned long knotIndex, float *knotValue);

/******************************************************************************
 **                                                                          **
 **                         Maximum NURB Patch Order                         **
 **                                                                          **
 *****************************************************************************/
#define kQ3NURBPatchMaxOrder 11
/******************************************************************************
 **                                                                          **
 **                     NURB Patch Data Structure Definitions                **
 **                                                                          **
 *****************************************************************************/
#endif /* CALL_NOT_IN_CARBON */

	struct TQ3NURBPatchTrimCurveData
	{
		unsigned long order;
		unsigned long numPoints;
		TQ3RationalPoint3D *controlPoints;
		float *knots;
	};
	typedef struct TQ3NURBPatchTrimCurveData TQ3NURBPatchTrimCurveData;
	struct TQ3NURBPatchTrimLoopData
	{
		unsigned long numTrimCurves;
		TQ3NURBPatchTrimCurveData *trimCurves;
	};
	typedef struct TQ3NURBPatchTrimLoopData TQ3NURBPatchTrimLoopData;
	struct TQ3NURBPatchData
	{
		unsigned long uOrder;
		unsigned long vOrder;
		unsigned long numRows;
		unsigned long numColumns;
		TQ3RationalPoint4D *controlPoints;
		float *uKnots;
		float *vKnots;
		unsigned long numTrimLoops;
		TQ3NURBPatchTrimLoopData *trimLoops;
		TQ3AttributeSet patchAttributeSet;
	};
	typedef struct TQ3NURBPatchData TQ3NURBPatchData;
/******************************************************************************
 **                                                                          **
 **                             NURB Patch Routines                          **
 **                                                                          **
 *****************************************************************************/
#if CALL_NOT_IN_CARBON
	/*
	 *  Q3NURBPatch_New()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3GeometryObject)
	Q3NURBPatch_New(const TQ3NURBPatchData *nurbPatchData);

	/*
	 *  Q3NURBPatch_Submit()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3NURBPatch_Submit(const TQ3NURBPatchData *nurbPatchData, TQ3ViewObject view);

	/*
	 *  Q3NURBPatch_SetData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3NURBPatch_SetData(TQ3GeometryObject nurbPatch, const TQ3NURBPatchData *nurbPatchData);

	/*
	 *  Q3NURBPatch_GetData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3NURBPatch_GetData(TQ3GeometryObject nurbPatch, TQ3NURBPatchData *nurbPatchData);

	/*
	 *  Q3NURBPatch_SetControlPoint()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3NURBPatch_SetControlPoint(TQ3GeometryObject nurbPatch, unsigned long rowIndex, unsigned long columnIndex,
								const TQ3RationalPoint4D *point4D);

	/*
	 *  Q3NURBPatch_GetControlPoint()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3NURBPatch_GetControlPoint(TQ3GeometryObject nurbPatch, unsigned long rowIndex, unsigned long columnIndex,
								TQ3RationalPoint4D *point4D);

	/*
	 *  Q3NURBPatch_SetUKnot()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3NURBPatch_SetUKnot(TQ3GeometryObject nurbPatch, unsigned long knotIndex, float knotValue);

	/*
	 *  Q3NURBPatch_SetVKnot()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3NURBPatch_SetVKnot(TQ3GeometryObject nurbPatch, unsigned long knotIndex, float knotValue);

	/*
	 *  Q3NURBPatch_GetUKnot()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3NURBPatch_GetUKnot(TQ3GeometryObject nurbPatch, unsigned long knotIndex, float *knotValue);

	/*
	 *  Q3NURBPatch_GetVKnot()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3NURBPatch_GetVKnot(TQ3GeometryObject nurbPatch, unsigned long knotIndex, float *knotValue);

	/*
	 *  Q3NURBPatch_EmptyData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3NURBPatch_EmptyData(TQ3NURBPatchData *nurbPatchData);

/******************************************************************************
 **                                                                          **
 **                     Pixmap Marker Data Structure Definitions             **
 **                                                                          **
 *****************************************************************************/
#endif /* CALL_NOT_IN_CARBON */

	struct TQ3PixmapMarkerData
	{
		TQ3Point3D position;
		long xOffset;
		long yOffset;
		TQ3StoragePixmap pixmap;
		TQ3AttributeSet pixmapMarkerAttributeSet;
	};
	typedef struct TQ3PixmapMarkerData TQ3PixmapMarkerData;
/******************************************************************************
 **                                                                          **
 **                             Pixmap Marker Routines                       **
 **                                                                          **
 *****************************************************************************/
#if CALL_NOT_IN_CARBON
	/*
	 *  Q3PixmapMarker_New()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3GeometryObject)
	Q3PixmapMarker_New(const TQ3PixmapMarkerData *pixmapMarkerData);

	/*
	 *  Q3PixmapMarker_Submit()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3PixmapMarker_Submit(const TQ3PixmapMarkerData *pixmapMarkerData, TQ3ViewObject view);

	/*
	 *  Q3PixmapMarker_SetData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3PixmapMarker_SetData(TQ3GeometryObject geometry, const TQ3PixmapMarkerData *pixmapMarkerData);

	/*
	 *  Q3PixmapMarker_GetData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3PixmapMarker_GetData(TQ3GeometryObject geometry, TQ3PixmapMarkerData *pixmapMarkerData);

	/*
	 *  Q3PixmapMarker_EmptyData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3PixmapMarker_EmptyData(TQ3PixmapMarkerData *pixmapMarkerData);

	/*
	 *  Q3PixmapMarker_GetPosition()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3PixmapMarker_GetPosition(TQ3GeometryObject pixmapMarker, TQ3Point3D *position);

	/*
	 *  Q3PixmapMarker_SetPosition()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3PixmapMarker_SetPosition(TQ3GeometryObject pixmapMarker, const TQ3Point3D *position);

	/*
	 *  Q3PixmapMarker_GetXOffset()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3PixmapMarker_GetXOffset(TQ3GeometryObject pixmapMarker, long *xOffset);

	/*
	 *  Q3PixmapMarker_SetXOffset()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3PixmapMarker_SetXOffset(TQ3GeometryObject pixmapMarker, long xOffset);

	/*
	 *  Q3PixmapMarker_GetYOffset()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3PixmapMarker_GetYOffset(TQ3GeometryObject pixmapMarker, long *yOffset);

	/*
	 *  Q3PixmapMarker_SetYOffset()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3PixmapMarker_SetYOffset(TQ3GeometryObject pixmapMarker, long yOffset);

	/*
	 *  Q3PixmapMarker_GetPixmap()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3PixmapMarker_GetPixmap(TQ3GeometryObject pixmapMarker, TQ3StoragePixmap *pixmap);

	/*
	 *  Q3PixmapMarker_SetPixmap()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3PixmapMarker_SetPixmap(TQ3GeometryObject pixmapMarker, const TQ3StoragePixmap *pixmap);

/******************************************************************************
 **                                                                          **
 **                     Point Data Structure Definitions                     **
 **                                                                          **
 *****************************************************************************/
#endif /* CALL_NOT_IN_CARBON */

	struct TQ3PointData
	{
		TQ3Point3D point;
		TQ3AttributeSet pointAttributeSet;
	};
	typedef struct TQ3PointData TQ3PointData;
/******************************************************************************
 **                                                                          **
 **                             Point Routines                               **
 **                                                                          **
 *****************************************************************************/
#if CALL_NOT_IN_CARBON
	/*
	 *  Q3Point_New()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3GeometryObject)
	Q3Point_New(const TQ3PointData *pointData);

	/*
	 *  Q3Point_Submit()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Point_Submit(const TQ3PointData *pointData, TQ3ViewObject view);

	/*
	 *  Q3Point_GetData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Point_GetData(TQ3GeometryObject point, TQ3PointData *pointData);

	/*
	 *  Q3Point_SetData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Point_SetData(TQ3GeometryObject point, const TQ3PointData *pointData);

	/*
	 *  Q3Point_EmptyData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Point_EmptyData(TQ3PointData *pointData);

	/*
	 *  Q3Point_SetPosition()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Point_SetPosition(TQ3GeometryObject point, const TQ3Point3D *position);

	/*
	 *  Q3Point_GetPosition()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Point_GetPosition(TQ3GeometryObject point, TQ3Point3D *position);

/******************************************************************************
 **                                                                          **
 **                     Polygon Data Structure Definitions                   **
 **                                                                          **
 *****************************************************************************/
#endif /* CALL_NOT_IN_CARBON */

	struct TQ3PolygonData
	{
		unsigned long numVertices;
		TQ3Vertex3D *vertices;
		TQ3AttributeSet polygonAttributeSet;
	};
	typedef struct TQ3PolygonData TQ3PolygonData;
/******************************************************************************
 **                                                                          **
 **                         Polygon Routines                                 **
 **                                                                          **
 *****************************************************************************/
#if CALL_NOT_IN_CARBON
	/*
	 *  Q3Polygon_New()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3GeometryObject)
	Q3Polygon_New(const TQ3PolygonData *polygonData);

	/*
	 *  Q3Polygon_Submit()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Polygon_Submit(const TQ3PolygonData *polygonData, TQ3ViewObject view);

	/*
	 *  Q3Polygon_SetData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Polygon_SetData(TQ3GeometryObject polygon, const TQ3PolygonData *polygonData);

	/*
	 *  Q3Polygon_GetData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Polygon_GetData(TQ3GeometryObject polygon, TQ3PolygonData *polygonData);

	/*
	 *  Q3Polygon_EmptyData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Polygon_EmptyData(TQ3PolygonData *polygonData);

	/*
	 *  Q3Polygon_GetVertexPosition()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Polygon_GetVertexPosition(TQ3GeometryObject polygon, unsigned long index, TQ3Point3D *point);

	/*
	 *  Q3Polygon_SetVertexPosition()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Polygon_SetVertexPosition(TQ3GeometryObject polygon, unsigned long index, const TQ3Point3D *point);

	/*
	 *  Q3Polygon_GetVertexAttributeSet()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Polygon_GetVertexAttributeSet(TQ3GeometryObject polygon, unsigned long index, TQ3AttributeSet *attributeSet);

	/*
	 *  Q3Polygon_SetVertexAttributeSet()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Polygon_SetVertexAttributeSet(TQ3GeometryObject polygon, unsigned long index, TQ3AttributeSet attributeSet);

/******************************************************************************
 **                                                                          **
 **                     Polyhedron Data Structure Definitions                **
 **                                                                          **
 *****************************************************************************/
#endif /* CALL_NOT_IN_CARBON */

	enum TQ3PolyhedronEdgeMasks
	{
		kQ3PolyhedronEdgeNone = 0,
		kQ3PolyhedronEdge01 = 1 << 0,
		kQ3PolyhedronEdge12 = 1 << 1,
		kQ3PolyhedronEdge20 = 1 << 2,
		kQ3PolyhedronEdgeAll = kQ3PolyhedronEdge01 | kQ3PolyhedronEdge12 | kQ3PolyhedronEdge20
	};
	typedef enum TQ3PolyhedronEdgeMasks TQ3PolyhedronEdgeMasks;

	typedef unsigned long TQ3PolyhedronEdge;
	struct TQ3PolyhedronEdgeData
	{
		unsigned long vertexIndices[2];
		unsigned long triangleIndices[2];
		TQ3AttributeSet edgeAttributeSet;
	};
	typedef struct TQ3PolyhedronEdgeData TQ3PolyhedronEdgeData;
	struct TQ3PolyhedronTriangleData
	{
		unsigned long vertexIndices[3];
		TQ3PolyhedronEdge edgeFlag;
		TQ3AttributeSet triangleAttributeSet;
	};
	typedef struct TQ3PolyhedronTriangleData TQ3PolyhedronTriangleData;
	struct TQ3PolyhedronData
	{
		unsigned long numVertices;
		TQ3Vertex3D *vertices;
		unsigned long numEdges;
		TQ3PolyhedronEdgeData *edges;
		unsigned long numTriangles;
		TQ3PolyhedronTriangleData *triangles;
		TQ3AttributeSet polyhedronAttributeSet;
	};
	typedef struct TQ3PolyhedronData TQ3PolyhedronData;
/******************************************************************************
 **                                                                          **
 **                             Polyhedron Routines                          **
 **                                                                          **
 *****************************************************************************/
#if CALL_NOT_IN_CARBON
	/*
	 *  Q3Polyhedron_New()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3GeometryObject)
	Q3Polyhedron_New(const TQ3PolyhedronData *polyhedronData);

	/*
	 *  Q3Polyhedron_Submit()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Polyhedron_Submit(const TQ3PolyhedronData *polyhedronData, TQ3ViewObject view);

	/*
	 *  Q3Polyhedron_SetData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Polyhedron_SetData(TQ3GeometryObject polyhedron, const TQ3PolyhedronData *polyhedronData);

	/*
	 *  Q3Polyhedron_GetData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Polyhedron_GetData(TQ3GeometryObject polyhedron, TQ3PolyhedronData *polyhedronData);

	/*
	 *  Q3Polyhedron_EmptyData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Polyhedron_EmptyData(TQ3PolyhedronData *polyhedronData);

	/*
	 *  Q3Polyhedron_SetVertexPosition()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Polyhedron_SetVertexPosition(TQ3GeometryObject polyhedron, unsigned long index, const TQ3Point3D *point);

	/*
	 *  Q3Polyhedron_GetVertexPosition()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Polyhedron_GetVertexPosition(TQ3GeometryObject polyhedron, unsigned long index, TQ3Point3D *point);

	/*
	 *  Q3Polyhedron_SetVertexAttributeSet()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Polyhedron_SetVertexAttributeSet(TQ3GeometryObject polyhedron, unsigned long index, TQ3AttributeSet attributeSet);

	/*
	 *  Q3Polyhedron_GetVertexAttributeSet()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Polyhedron_GetVertexAttributeSet(TQ3GeometryObject polyhedron, unsigned long index,
									   TQ3AttributeSet *attributeSet);

	/*
	 *  Q3Polyhedron_GetTriangleData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Polyhedron_GetTriangleData(TQ3GeometryObject polyhedron, unsigned long triangleIndex,
								 TQ3PolyhedronTriangleData *triangleData);

	/*
	 *  Q3Polyhedron_SetTriangleData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Polyhedron_SetTriangleData(TQ3GeometryObject polyhedron, unsigned long triangleIndex,
								 const TQ3PolyhedronTriangleData *triangleData);

	/*
	 *  Q3Polyhedron_GetEdgeData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Polyhedron_GetEdgeData(TQ3GeometryObject polyhedron, unsigned long edgeIndex, TQ3PolyhedronEdgeData *edgeData);

	/*
	 *  Q3Polyhedron_SetEdgeData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Polyhedron_SetEdgeData(TQ3GeometryObject polyhedron, unsigned long edgeIndex,
							 const TQ3PolyhedronEdgeData *edgeData);

/******************************************************************************
 **                                                                          **
 **                     PolyLine Data Structure Definitions                  **
 **                                                                          **
 *****************************************************************************/
#endif /* CALL_NOT_IN_CARBON */

	struct TQ3PolyLineData
	{
		unsigned long numVertices;
		TQ3Vertex3D *vertices;
		TQ3AttributeSet *segmentAttributeSet;
		TQ3AttributeSet polyLineAttributeSet;
	};
	typedef struct TQ3PolyLineData TQ3PolyLineData;
/******************************************************************************
 **                                                                          **
 **                         PolyLine Routines                                **
 **                                                                          **
 *****************************************************************************/
#if CALL_NOT_IN_CARBON
	/*
	 *  Q3PolyLine_New()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3GeometryObject)
	Q3PolyLine_New(const TQ3PolyLineData *polylineData);

	/*
	 *  Q3PolyLine_Submit()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3PolyLine_Submit(const TQ3PolyLineData *polyLineData, TQ3ViewObject view);

	/*
	 *  Q3PolyLine_SetData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3PolyLine_SetData(TQ3GeometryObject polyLine, const TQ3PolyLineData *polyLineData);

	/*
	 *  Q3PolyLine_GetData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3PolyLine_GetData(TQ3GeometryObject polyLine, TQ3PolyLineData *polyLineData);

	/*
	 *  Q3PolyLine_EmptyData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3PolyLine_EmptyData(TQ3PolyLineData *polyLineData);

	/*
	 *  Q3PolyLine_GetVertexPosition()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3PolyLine_GetVertexPosition(TQ3GeometryObject polyLine, unsigned long index, TQ3Point3D *position);

	/*
	 *  Q3PolyLine_SetVertexPosition()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3PolyLine_SetVertexPosition(TQ3GeometryObject polyLine, unsigned long index, const TQ3Point3D *position);

	/*
	 *  Q3PolyLine_GetVertexAttributeSet()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3PolyLine_GetVertexAttributeSet(TQ3GeometryObject polyLine, unsigned long index, TQ3AttributeSet *attributeSet);

	/*
	 *  Q3PolyLine_SetVertexAttributeSet()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3PolyLine_SetVertexAttributeSet(TQ3GeometryObject polyLine, unsigned long index, TQ3AttributeSet attributeSet);

	/*
	 *  Q3PolyLine_GetSegmentAttributeSet()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3PolyLine_GetSegmentAttributeSet(TQ3GeometryObject polyLine, unsigned long index, TQ3AttributeSet *attributeSet);

	/*
	 *  Q3PolyLine_SetSegmentAttributeSet()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3PolyLine_SetSegmentAttributeSet(TQ3GeometryObject polyLine, unsigned long index, TQ3AttributeSet attributeSet);

/******************************************************************************
 **                                                                          **
 **                     Torus Data Structure Definitions                     **
 **                                                                          **
 *****************************************************************************/
#endif /* CALL_NOT_IN_CARBON */

	struct TQ3TorusData
	{
		TQ3Point3D origin;
		TQ3Vector3D orientation;
		TQ3Vector3D majorRadius;
		TQ3Vector3D minorRadius;
		float ratio;
		float uMin;
		float uMax;
		float vMin;
		float vMax;
		TQ3EndCap caps;
		TQ3AttributeSet interiorAttributeSet;
		TQ3AttributeSet torusAttributeSet;
	};
	typedef struct TQ3TorusData TQ3TorusData;
/******************************************************************************
 **                                                                          **
 **                             Torus Routines                               **
 **                                                                          **
 *****************************************************************************/
#if CALL_NOT_IN_CARBON
	/*
	 *  Q3Torus_New()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3GeometryObject)
	Q3Torus_New(const TQ3TorusData *torusData);

	/*
	 *  Q3Torus_Submit()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Torus_Submit(const TQ3TorusData *torusData, TQ3ViewObject view);

	/*
	 *  Q3Torus_SetData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Torus_SetData(TQ3GeometryObject torus, const TQ3TorusData *torusData);

	/*
	 *  Q3Torus_GetData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Torus_GetData(TQ3GeometryObject torus, TQ3TorusData *torusData);

	/*
	 *  Q3Torus_SetOrigin()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Torus_SetOrigin(TQ3GeometryObject torus, const TQ3Point3D *origin);

	/*
	 *  Q3Torus_SetOrientation()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Torus_SetOrientation(TQ3GeometryObject torus, const TQ3Vector3D *orientation);

	/*
	 *  Q3Torus_SetMajorRadius()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Torus_SetMajorRadius(TQ3GeometryObject torus, const TQ3Vector3D *majorRadius);

	/*
	 *  Q3Torus_SetMinorRadius()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Torus_SetMinorRadius(TQ3GeometryObject torus, const TQ3Vector3D *minorRadius);

	/*
	 *  Q3Torus_SetRatio()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Torus_SetRatio(TQ3GeometryObject torus, float ratio);

	/*
	 *  Q3Torus_GetOrigin()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Torus_GetOrigin(TQ3GeometryObject torus, TQ3Point3D *origin);

	/*
	 *  Q3Torus_GetOrientation()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Torus_GetOrientation(TQ3GeometryObject torus, TQ3Vector3D *orientation);

	/*
	 *  Q3Torus_GetMajorRadius()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Torus_GetMajorRadius(TQ3GeometryObject torus, TQ3Vector3D *majorRadius);

	/*
	 *  Q3Torus_GetMinorRadius()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Torus_GetMinorRadius(TQ3GeometryObject torus, TQ3Vector3D *minorRadius);

	/*
	 *  Q3Torus_GetRatio()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Torus_GetRatio(TQ3GeometryObject torus, float *ratio);

	/*
	 *  Q3Torus_EmptyData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Torus_EmptyData(TQ3TorusData *torusData);

/******************************************************************************
 **                                                                          **
 **                     Triangle Data Structure Definitions                  **
 **                                                                          **
 *****************************************************************************/
#endif /* CALL_NOT_IN_CARBON */

	struct TQ3TriangleData
	{
		TQ3Vertex3D vertices[3];
		TQ3AttributeSet triangleAttributeSet;
	};
	typedef struct TQ3TriangleData TQ3TriangleData;
/******************************************************************************
 **                                                                          **
 **                         Triangle Routines                                **
 **                                                                          **
 *****************************************************************************/
#if CALL_NOT_IN_CARBON
	/*
	 *  Q3Triangle_New()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3GeometryObject)
	Q3Triangle_New(const TQ3TriangleData *triangleData);

	/*
	 *  Q3Triangle_Submit()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Triangle_Submit(const TQ3TriangleData *triangleData, TQ3ViewObject view);

	/*
	 *  Q3Triangle_SetData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Triangle_SetData(TQ3GeometryObject triangle, const TQ3TriangleData *triangleData);

	/*
	 *  Q3Triangle_GetData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Triangle_GetData(TQ3GeometryObject triangle, TQ3TriangleData *triangleData);

	/*
	 *  Q3Triangle_EmptyData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Triangle_EmptyData(TQ3TriangleData *triangleData);

	/*
	 *  Q3Triangle_GetVertexPosition()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Triangle_GetVertexPosition(TQ3GeometryObject triangle, unsigned long index, TQ3Point3D *point);

	/*
	 *  Q3Triangle_SetVertexPosition()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Triangle_SetVertexPosition(TQ3GeometryObject triangle, unsigned long index, const TQ3Point3D *point);

	/*
	 *  Q3Triangle_GetVertexAttributeSet()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Triangle_GetVertexAttributeSet(TQ3GeometryObject triangle, unsigned long index, TQ3AttributeSet *attributeSet);

	/*
	 *  Q3Triangle_SetVertexAttributeSet()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3Triangle_SetVertexAttributeSet(TQ3GeometryObject triangle, unsigned long index, TQ3AttributeSet attributeSet);

/******************************************************************************
 **                                                                          **
 **                     TriGrid Data Structure Definitions                   **
 **                                                                          **
 *****************************************************************************/
#endif /* CALL_NOT_IN_CARBON */

	struct TQ3TriGridData
	{
		unsigned long numRows;
		unsigned long numColumns;
		TQ3Vertex3D *vertices;
		TQ3AttributeSet *facetAttributeSet;
		TQ3AttributeSet triGridAttributeSet;
	};
	typedef struct TQ3TriGridData TQ3TriGridData;
/******************************************************************************
 **                                                                          **
 **                             TriGrid Routines                             **
 **                                                                          **
 *****************************************************************************/
#if CALL_NOT_IN_CARBON
	/*
	 *  Q3TriGrid_New()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3GeometryObject)
	Q3TriGrid_New(const TQ3TriGridData *triGridData);

	/*
	 *  Q3TriGrid_Submit()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3TriGrid_Submit(const TQ3TriGridData *triGridData, TQ3ViewObject view);

	/*
	 *  Q3TriGrid_SetData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3TriGrid_SetData(TQ3GeometryObject triGrid, const TQ3TriGridData *triGridData);

	/*
	 *  Q3TriGrid_GetData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3TriGrid_GetData(TQ3GeometryObject triGrid, TQ3TriGridData *triGridData);

	/*
	 *  Q3TriGrid_EmptyData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3TriGrid_EmptyData(TQ3TriGridData *triGridData);

	/*
	 *  Q3TriGrid_GetVertexPosition()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3TriGrid_GetVertexPosition(TQ3GeometryObject triGrid, unsigned long rowIndex, unsigned long columnIndex,
								TQ3Point3D *position);

	/*
	 *  Q3TriGrid_SetVertexPosition()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3TriGrid_SetVertexPosition(TQ3GeometryObject triGrid, unsigned long rowIndex, unsigned long columnIndex,
								const TQ3Point3D *position);

	/*
	 *  Q3TriGrid_GetVertexAttributeSet()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3TriGrid_GetVertexAttributeSet(TQ3GeometryObject triGrid, unsigned long rowIndex, unsigned long columnIndex,
									TQ3AttributeSet *attributeSet);

	/*
	 *  Q3TriGrid_SetVertexAttributeSet()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3TriGrid_SetVertexAttributeSet(TQ3GeometryObject triGrid, unsigned long rowIndex, unsigned long columnIndex,
									TQ3AttributeSet attributeSet);

	/*
	 *  Q3TriGrid_GetFacetAttributeSet()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3TriGrid_GetFacetAttributeSet(TQ3GeometryObject triGrid, unsigned long faceIndex,
								   TQ3AttributeSet *facetAttributeSet);

	/*
	 *  Q3TriGrid_SetFacetAttributeSet()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3TriGrid_SetFacetAttributeSet(TQ3GeometryObject triGrid, unsigned long faceIndex,
								   TQ3AttributeSet facetAttributeSet);

/******************************************************************************
 **                                                                          **
 **                     TriMesh Data Structure Definitions                   **
 **                                                                          **
 *****************************************************************************/
#endif /* CALL_NOT_IN_CARBON */

	struct TQ3TriMeshTriangleData
	{
		unsigned long pointIndices[3];
	};
	typedef struct TQ3TriMeshTriangleData TQ3TriMeshTriangleData;
	struct TQ3TriMeshEdgeData
	{
		unsigned long pointIndices[2];
		unsigned long triangleIndices[2];
	};
	typedef struct TQ3TriMeshEdgeData TQ3TriMeshEdgeData;
	struct TQ3TriMeshAttributeData
	{
		TQ3AttributeType attributeType; /* The type of attribute       */
		void *data;						/* Pointer to the contiguous     */
										/* attribute data.           */
		char *attributeUseArray;		/* This is only used with custom */
										/* attributes                */
	};
	typedef struct TQ3TriMeshAttributeData TQ3TriMeshAttributeData;
	struct TQ3TriMeshData
	{
		TQ3AttributeSet triMeshAttributeSet;

		unsigned long numTriangles;
		TQ3TriMeshTriangleData *triangles;

		unsigned long numTriangleAttributeTypes;
		TQ3TriMeshAttributeData *triangleAttributeTypes;

		unsigned long numEdges;
		TQ3TriMeshEdgeData *edges;

		unsigned long numEdgeAttributeTypes;
		TQ3TriMeshAttributeData *edgeAttributeTypes;

		unsigned long numPoints;
		TQ3Point3D *points;

		unsigned long numVertexAttributeTypes;
		TQ3TriMeshAttributeData *vertexAttributeTypes;

		TQ3BoundingBox bBox;
	};
	typedef struct TQ3TriMeshData TQ3TriMeshData;
/******************************************************************************
 **                                                                          **
 **                         TriMesh Routines                                 **
 **                                                                          **
 *****************************************************************************/
#if CALL_NOT_IN_CARBON
	/*
	 *  Q3TriMesh_New()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3GeometryObject)
	Q3TriMesh_New(const TQ3TriMeshData *triMeshData);

	/*
	 *  Q3TriMesh_Submit()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3TriMesh_Submit(const TQ3TriMeshData *triMeshData, TQ3ViewObject view);

	/*
	 *  Q3TriMesh_SetData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3TriMesh_SetData(TQ3GeometryObject triMesh, const TQ3TriMeshData *triMeshData);

	/*
	 *  Q3TriMesh_GetData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3TriMesh_GetData(TQ3GeometryObject triMesh, TQ3TriMeshData *triMeshData);

	/*
	 *  Q3TriMesh_EmptyData()
	 *
	 *  Availability:
	 *    Non-Carbon CFM:   not available
	 *    CarbonLib:        not available
	 *    Mac OS X:         not available
	 */
	EXTERN_API_C(TQ3Status)
	Q3TriMesh_EmptyData(TQ3TriMeshData *triMeshData);

#endif /* CALL_NOT_IN_CARBON */

#if PRAGMA_ENUM_ALWAYSINT
#pragma enumsalwaysint reset
#ifdef __QD3DGEOMETRY__RESTORE_TWOBYTEINTS
#pragma fourbyteints off
#endif
#elif PRAGMA_ENUM_OPTIONS
#pragma option enum =reset
#elif defined(__QD3DGEOMETRY__RESTORE_PACKED_ENUMS)
#pragma options(pack_enums)
#endif

#if PRAGMA_STRUCT_ALIGN
#pragma options align = reset
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

#endif /* __QD3DGEOMETRY__ */