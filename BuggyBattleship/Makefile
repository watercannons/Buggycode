CC      := gcc
CCFLAGS += -I$(realpath common) -DGHS_FEE_COLLECT -Xprologue_epilogue_hooks_noinline -G
LDFLAGS += -L$(realpath common) -lm -lmulti -lghseagle

ifdef REPLAY
	CCFLAGS := -DREPLAY -DTARGET_LINUX $(CCFLAGS)
	LDFLAGS := -lreplay $(LDFLAGS)
endif

export

TOPTARGETS := all clean
SUBDIRS	   := host ai dumb-ai player ip-player

.PHONY: all clean $(SUBDIRS)

$(TOPTARGETS): $(SUBDIRS)
	if [ "$@" = "clean" ]; then rm -rf replays; fi

$(SUBDIRS):
	 $(MAKE) -C $@ $(MAKECMDGOALS)

