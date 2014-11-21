/*
 *
 * Confidential Information of Telekinesys Research Limited (t/a Havok). Not for disclosure or distribution without Havok's
 * prior written consent. This software contains code, techniques and know-how which is confidential and proprietary to Havok.
 * Product and Trade Secret source code contains trade secrets of Havok. Havok Software (C) Copyright 1999-2014 Telekinesys Research Limited t/a Havok. All Rights Reserved. Use of this software is subject to the terms of an end user license agreement.
 *
 */

#ifndef HK_PATCH_TEST_CLASSES_H
#define HK_PATCH_TEST_CLASSES_H

extern HK_EXPORT_COMMON const class hkClass hkTestBClass;
extern HK_EXPORT_COMMON const class hkClass hkTestAClass;
extern HK_EXPORT_COMMON const class hkClass hkTestCClass;
extern HK_EXPORT_COMMON const class hkClass hkTestPatchObjectClass;

struct HK_EXPORT_COMMON hkTestC
{
	// +version(3)
	HK_DECLARE_REFLECTION();
	HK_DECLARE_NONVIRTUAL_CLASS_ALLOCATOR(HK_MEMORY_CLASS_SERIALIZE, hkTestC);
	int m_userData;
	int m_userData2;
};

struct HK_EXPORT_COMMON hkTestA
{
	// +version(2)
	HK_DECLARE_REFLECTION();
	HK_DECLARE_NONVIRTUAL_CLASS_ALLOCATOR(HK_MEMORY_CLASS_SERIALIZE, hkTestA);
	float m_float;
};

struct HK_EXPORT_COMMON hkTestB
{
	// +version(1)
	HK_DECLARE_REFLECTION();
	HK_DECLARE_NONVIRTUAL_CLASS_ALLOCATOR(HK_MEMORY_CLASS_SERIALIZE, hkTestB);
	char* m_string;
	struct hkTestC* m_object;
};

struct HK_EXPORT_COMMON hkTestPatchObject
{
	// +version(2)
	HK_DECLARE_REFLECTION();
	HK_DECLARE_NONVIRTUAL_CLASS_ALLOCATOR(HK_MEMORY_CLASS_SERIALIZE, hkTestPatchObject);

	int m_intMember;
	hkTestA m_structMember;
};

#endif // HK_PATCH_TEST_CLASSES_H

/*
 * Havok SDK - NO SOURCE PC DOWNLOAD, BUILD(#20140907)
 * 
 * Confidential Information of Havok.  (C) Copyright 1999-2014
 * Telekinesys Research Limited t/a Havok. All Rights Reserved. The Havok
 * Logo, and the Havok buzzsaw logo are trademarks of Havok.  Title, ownership
 * rights, and intellectual property rights in the Havok software remain in
 * Havok and/or its suppliers.
 * 
 * Use of this software for evaluation purposes is subject to and indicates
 * acceptance of the End User licence Agreement for this product. A copy of
 * the license is included with this software and is also available at www.havok.com/tryhavok.
 * 
 */