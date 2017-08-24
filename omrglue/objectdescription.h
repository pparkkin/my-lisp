#if !defined(OBJECTDESCRIPTION_H_)
#define OBJECTDESCRIPTION_H_

#include "omrcomp.h"
#include "omr.h"

/**
 * Object token definitions to be used by OMR components.
 */
typedef uintptr_t* languageobjectptr_t;
typedef uintptr_t* omrobjectptr_t;
typedef uintptr_t* omrarrayptr_t;

#if defined (OMR_GC_COMPRESSED_POINTERS)
typedef uint32_t fomrobject_t;
typedef uint32_t fomrarray_t;
#else
typedef uintptr_t fomrobject_t;
typedef uintptr_t fomrarray_t;
#endif

#endif /* OBJECTDESCRIPTION_H_ */
