CC      := gcc
CCFLAGS += -I$(realpath common) -g
LDFLAGS += -L$(realpath common) -lm

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

