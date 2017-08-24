OMRDIR=$(CURDIR)/omr
OMRGLUEDIR=$(CURDIR)/omrglue
OMRLIBDIR=$(OMRDIR)/lib
OMRLIBS=$(OMRLIBDIR)/libomrstatic.a

SPEC=linux_x86-64

include $(OMRDIR)/omrmakefiles/omr_defs.mk

.PHONY: all
all: parsing

parsing: $(OMRLIBS) parsing.o mpc/mpc.o
	g++ -Wall -g --std=gnu++14 -ledit -lm -lpthread -ldl $(OMRLIBS) omrglue/omrmylispvm.o mpc/mpc.o parsing.o -o parsing

parsing.o: parsing.c
	cc -c -Wall -g --std=gnu99 -Impc -I$(OMRDIR)/include_core -Iomrglue parsing.c

mpc/mpc.o:
	$(MAKE) -C mpc

.PHONY: clean
clean: omr-clean
	rm -f *.o
	rm -f mpc/mpc.o
	rm -f prompt
	rm -f parsing

.PHONY: omr-clean
omr-clean:
	$(MAKE) -C $(OMRDIR) clean
	$(MAKE) -C $(OMRDIR) -f run_configure.mk OMRGLUE="$(OMRGLUEDIR)" clean

.PHONY: omr-config
omr-config:
	$(MAKE) -C $(OMRDIR) -f run_configure.mk OMRGLUE="$(OMRGLUEDIR)" OMRGLUE_INCLUDES="$(SRC_DIR)" SPEC="$(SPEC)" CXX="$(CXX)" OPT_FLAGS="$(OPT_FLAGS)" EXTRA_FLAGS="$(EXTRA_FLAGS)" DBG_FLAGS="$(DBG_FLAGS)" FEATURE_FLAGS="$(FEATURE_FLAGS)" enable_warnings_as_errors=no enable_debug=no

$(OMRLIBS): omr-config
	$(MAKE) -C $(OMRDIR)
