
OMRDIR=$(CURDIR)/omr
OMRGLUEDIR=$(CURDIR)/omrglue
OMRLIB=$(OMRDIR)/lib/libomrstatic.a

SPEC=linux_x86-64

include $(OMRDIR)/omrmakefiles/omr_defs.mk

.PHONY: all
all: prompt parsing

prompt: prompt.c
	cc -std=c99 -Wall -g prompt.c -ledit -o prompt

parsing: omr parsing.c mpc.c
	cc -std=c99 -Wall -g parsing.c mpc.c -ledit -lm -o parsing

.PHONY: clean
clean: omr-clean
	rm -f prompt
	rm -f parsing

.PHONY: omr-clean
omr-clean:
	$(MAKE) -C $(OMRDIR) clean
	$(MAKE) -C $(OMRDIR) -f run_configure.mk OMRGLUE="$(OMRGLUEDIR)" clean

.PHONY: omr-config
omr-config:
	$(MAKE) -C $(OMRDIR) -f run_configure.mk OMRGLUE="$(OMRGLUEDIR)" OMRGLUE_INCLUDES="$(SRC_DIR)" SPEC="$(SPEC)" CXX="$(CXX)" OPT_FLAGS="$(OPT_FLAGS)" EXTRA_FLAGS="$(EXTRA_FLAGS)" DBG_FLAGS="$(DBG_FLAGS)" FEATURE_FLAGS="$(FEATURE_FLAGS)" enable_warnings_as_errors=no enable_debug=no

.PHONY: omr
omr: omr-config
	$(MAKE) -C $(OMRDIR)
