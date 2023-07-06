BOOTLOADER = stm32-dfu

FORCE_NKRO = yes
COMBO_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes

AUDIO_ENABLE = no

ifeq ($(strip $(AUDIO_ENABLE)), yes)
    SRC += muse.c
endif
