
#include <string.h>
#include "omrmylispvm.h"

// See https://github.com/eclipse/omr/blob/master/example/glue/omrExampleVM.cpp

uintptr_t
rootTableHashFn(void *entry, void *userData)
{
	const char *name = ((RootEntry *)entry)->name;
	uintptr_t length = strlen(name);
	uintptr_t hash = 0;
	uintptr_t i;

	for (i = 0; i < length; i++) {
		hash = (hash << 5) - hash + name[i];
	}

	return hash;
}

uintptr_t
rootTableHashEqualFn(void *leftEntry, void *rightEntry, void *userData)
{
	RootEntry *loe = (RootEntry *)leftEntry;
	RootEntry *roe = (RootEntry *)rightEntry;
	return (0 == strcmp(loe->name, roe->name));
}

uintptr_t
objectTableHashFn(void *entry, void *userData)
{
	const char *name = ((ObjectEntry *)entry)->name;
	uintptr_t length = strlen(name);
	uintptr_t hash = 0;
	uintptr_t i;

	for (i = 0; i < length; i++) {
		hash = (hash << 5) - hash + name[i];
	}

	return hash;
}

uintptr_t
objectTableHashEqualFn(void *leftEntry, void *rightEntry, void *userData)
{
	ObjectEntry *loe = (ObjectEntry *)leftEntry;
	ObjectEntry *roe = (ObjectEntry *)rightEntry;
	return (0 == strcmp(loe->name, roe->name));
}

uintptr_t
objectTableFreeFn(void *entry, void *userData)
{
	OMR_VM_MyLISP *exampleVM = (OMR_VM_MyLISP *)userData;
	OMRPORT_ACCESS_FROM_OMRVM(exampleVM->_omrVM);
	ObjectEntry *objEntry = (ObjectEntry *)entry;

	omrmem_free_memory((void *)objEntry->name);
	objEntry->name = NULL;

	return 0;
}
