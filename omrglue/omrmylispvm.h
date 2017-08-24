#ifndef omrmylispvm_h
#define omrmylispvm_h

#include "omr.h"
#include "hashtable_api.h"
#include "objectdescription.h"

typedef struct OMR_VM_MyLISP {
	OMR_VM *_omrVM;
	OMR_VMThread *_omrVMThread;
	J9HashTable *rootTable;
	J9HashTable *objectTable;
	omrthread_t self;
	omrthread_rwmutex_t _vmAccessMutex;
	volatile uintptr_t _vmExclusiveAccessCount;
} OMR_VM_MyLISP;

typedef struct RootEntry {
	const char *name;
	omrobjectptr_t rootPtr;
} RootEntry;

typedef struct ObjectEntry {
	const char *name;
	omrobjectptr_t objPtr;
	int32_t numOfRef;
} ObjectEntry;

uintptr_t rootTableHashFn(void *entry, void *userData);
uintptr_t rootTableHashEqualFn(void *leftEntry, void *rightEntry, void *userData);

uintptr_t objectTableHashFn(void *entry, void *userData);
uintptr_t objectTableHashEqualFn(void *leftEntry, void *rightEntry, void *userData);
uintptr_t objectTableFreeFn(void *entry, void *userData);

#endif
