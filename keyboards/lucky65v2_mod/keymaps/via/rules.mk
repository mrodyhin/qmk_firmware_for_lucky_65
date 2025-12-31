VIA_ENABLE = yes
ENCODER_MAP_ENABLE = yes

MATRIX_LKEY_DISABLE = yes

ifeq ($(strip $(CONSOLE_ENABLE)), yes)
    KEYBOARD_SHARED_EP := yes
endif
