
CGBBANK EQU $10

MAP_HEADER: MACRO
    
    dw (\1) - ($4000 * (BANK(\1) - $0B))
    db \2
    dw \3
    db \4
    db BANK(\5)
    dw \5
    db \6
    db \7
ENDM
SCRIPT_AT_POS: MACRO
    
                db ((\1) << 4) | (\2)
                dw \3
ENDM
SCRIPT_POINTER: MACRO
    dw ((\1 - $4000) + ((BANK(\1) - $0D) * $4000))
ENDM
data_bbbbbbbbbbbbbbbbbbbbwbb: MACRO
    db \1
    shift
    db \1
    shift
    db \1
    shift
    db \1
    shift
    db \1
    shift
    db \1
    shift
    db \1
    shift
    db \1
    shift
    db \1
    shift
    db \1
    shift
    db \1
    shift
    db \1
    shift
    db \1
    shift
    db \1
    shift
    db \1
    shift
    db \1
    shift
    db \1
    shift
    db \1
    shift
    db \1
    shift
    db \1
    shift
    dw \1
    shift
    db \1
    shift
    db \1
    shift
ENDM
ld_long_load: MACRO
    db $FA
    dw \1
ENDM
ld_long_store: MACRO
    db $EA
    dw \1
ENDM
sCALL: MACRO
    db $02
    db ((BANK(\1) - $0D) << 6) | (HIGH(\1) & $3F), LOW(\1)
ENDM
sCHECK_MONEY: MACRO
    db $d1
    dw \1
ENDM
sCLEAR_FAST_MOVEMENT: MACRO
    db $89
ENDM
sCLEAR_FLAG: MACRO
    db $db
    db \1
ENDM
sCLOSE_MAP: MACRO
    db $ae
ENDM
sDELAY: MACRO
    db $f0
    db \1
ENDM
sDEL_NPC_1: MACRO
    db $18
ENDM
sDEL_NPC_2: MACRO
    db $28
ENDM
sDEL_NPC_3: MACRO
    db $38
ENDM
sDEL_NPC_4: MACRO
    db $48
ENDM
sDEL_NPC_5: MACRO
    db $58
ENDM
sDEL_NPC_6: MACRO
    db $68
ENDM
sDEL_NPC_7: MACRO
    db $78
ENDM
sEND: MACRO
    db $00
ENDM
sFADE_TO_BLACK: MACRO
    db $bd
ENDM
sFADE_TO_NORMAL: MACRO
    db $bc
ENDM
sFADE_TO_WHITE: MACRO
    db $be
ENDM
sFLASH_SCREEN: MACRO
    db $bf
ENDM
sFOLLOWER_DELETE: MACRO
    db $98
ENDM
sFOLLOWER_DIRECTION_DOWN: MACRO
    db $95
ENDM
sFOLLOWER_DIRECTION_LEFT: MACRO
    db $97
ENDM
sFOLLOWER_DIRECTION_RIGHT: MACRO
    db $96
ENDM
sFOLLOWER_DIRECTION_UP: MACRO
    db $94
ENDM
sFOLLOWER_SET_POSITION: MACRO
    db $99
    db \1, \2
ENDM
sFOLLOWER_STEP_BACKWARD: MACRO
    db $91
ENDM
sFOLLOWER_STEP_FORWARD: MACRO
    db $90
ENDM
sFULL_HP: MACRO
    db $c0
ENDM
sFULL_HP_DUMMY_12: MACRO
    db $12
ENDM
sFULL_HP_DUMMY_13: MACRO
    db $13
ENDM
sFULL_HP_DUMMY_22: MACRO
    db $22
ENDM
sFULL_HP_DUMMY_23: MACRO
    db $23
ENDM
sFULL_HP_DUMMY_32: MACRO
    db $32
ENDM
sFULL_HP_DUMMY_33: MACRO
    db $33
ENDM
sFULL_HP_DUMMY_42: MACRO
    db $42
ENDM
sFULL_HP_DUMMY_43: MACRO
    db $43
ENDM
sFULL_HP_DUMMY_52: MACRO
    db $52
ENDM
sFULL_HP_DUMMY_53: MACRO
    db $53
ENDM
sFULL_HP_DUMMY_62: MACRO
    db $62
ENDM
sFULL_HP_DUMMY_63: MACRO
    db $63
ENDM
sFULL_HP_DUMMY_72: MACRO
    db $72
ENDM
sFULL_HP_DUMMY_73: MACRO
    db $73
ENDM
sFULL_HP_DUMMY_82: MACRO
    db $82
ENDM
sFULL_HP_DUMMY_83: MACRO
    db $83
ENDM
sFULL_HP_DUMMY_8C: MACRO
    db $8c
ENDM
sFULL_HP_DUMMY_8D: MACRO
    db $8d
ENDM
sFULL_HP_DUMMY_8E: MACRO
    db $8e
ENDM
sFULL_HP_DUMMY_92: MACRO
    db $92
ENDM
sFULL_HP_DUMMY_93: MACRO
    db $93
ENDM
sFULL_HP_DUMMY_F1: MACRO
    db $f1
ENDM
sFULL_HP_DUMMY_F2: MACRO
    db $f2
ENDM
sFULL_HP_DUMMY_F5: MACRO
    db $f5
ENDM
sFULL_HP_DUMMY_F7: MACRO
    db $f7
ENDM
sFULL_HP_DUMMY_FA: MACRO
    db $fa
ENDM
sFULL_MANA: MACRO
    db $c1
ENDM
sGIVE_EQUIPMENT: MACRO
    db $d8
    db \1
ENDM
sGIVE_FOLLOWER: MACRO
    db $9c
    db \1
ENDM
sGIVE_MAGIC: MACRO
    db $d6
    db \1
ENDM
sGIVE_XP: MACRO
    db $d2
    dw \1
ENDM
sIF_08_JR: MACRO
    db $08
    
    REPT _NARG - 1
        db \1
        SHIFT
    ENDR
        db $00
        db \1 - @ - 1
ENDM
sIF_09_JR: MACRO
    db $09
    
    REPT _NARG - 1
        db \1
        SHIFT
    ENDR
        db $00
        db \1 - @ - 1
ENDM
sIF_0A_JR: MACRO
    db $0a
    
    REPT _NARG - 1
        db \1
        SHIFT
    ENDR
        db $00
        db \1 - @ - 1
ENDM
sIF_0B_JR: MACRO
    db $0b
    
    REPT _NARG - 1
        db \1
        SHIFT
    ENDR
        db $00
        db \1 - @ - 1
ENDM
sIF_0C_JR: MACRO
    db $0c
    
    REPT _NARG - 1
        db \1
        SHIFT
    ENDR
        db $00
        db \1 - @ - 1
ENDM
sJR: MACRO
    db $01
    db \1 - @ - 1
ENDM
sLOAD_ROOM: MACRO
    db $f4
    db \1, \2, \3, \4
ENDM
sLOAD_ROOM_INSTANT: MACRO
    db $f3
    db \1, \2, \3, \4
ENDM
sLOOP: MACRO
    db $03
    db \1, \2
ENDM
sMSG: MACRO
    db $04
    SETCHARMAP SCRIPT
ENDM
sNOP_05: MACRO
    db $05
ENDM
sNOP_06: MACRO
    db $06
ENDM
sNOP_07: MACRO
    db $07
ENDM
sNOP_0D: MACRO
    db $0d
ENDM
sNOP_0E: MACRO
    db $0e
ENDM
sNOP_0F: MACRO
    db $0f
ENDM
sNOP_1C: MACRO
    db $1c
ENDM
sNOP_1D: MACRO
    db $1d
ENDM
sNOP_1E: MACRO
    db $1e
ENDM
sNOP_1F: MACRO
    db $1f
ENDM
sNOP_2C: MACRO
    db $2c
ENDM
sNOP_2D: MACRO
    db $2d
ENDM
sNOP_2E: MACRO
    db $2e
ENDM
sNOP_2F: MACRO
    db $2f
ENDM
sNOP_3C: MACRO
    db $3c
ENDM
sNOP_3D: MACRO
    db $3d
ENDM
sNOP_3E: MACRO
    db $3e
ENDM
sNOP_3F: MACRO
    db $3f
ENDM
sNOP_4C: MACRO
    db $4c
ENDM
sNOP_4D: MACRO
    db $4d
ENDM
sNOP_4E: MACRO
    db $4e
ENDM
sNOP_4F: MACRO
    db $4f
ENDM
sNOP_5C: MACRO
    db $5c
ENDM
sNOP_5D: MACRO
    db $5d
ENDM
sNOP_5E: MACRO
    db $5e
ENDM
sNOP_5F: MACRO
    db $5f
ENDM
sNOP_6C: MACRO
    db $6c
ENDM
sNOP_6D: MACRO
    db $6d
ENDM
sNOP_6E: MACRO
    db $6e
ENDM
sNOP_6F: MACRO
    db $6f
ENDM
sNOP_7C: MACRO
    db $7c
ENDM
sNOP_7D: MACRO
    db $7d
ENDM
sNOP_7E: MACRO
    db $7e
ENDM
sNOP_7F: MACRO
    db $7f
ENDM
sNOP_9E: MACRO
    db $9e
ENDM
sNOP_9F: MACRO
    db $9f
ENDM
sNOP_A7: MACRO
    db $a7
ENDM
sNOP_A8: MACRO
    db $a8
ENDM
sNOP_B1: MACRO
    db $b1
ENDM
sNOP_B2: MACRO
    db $b2
ENDM
sNOP_B3: MACRO
    db $b3
ENDM
sNOP_B4: MACRO
    db $b4
ENDM
sNOP_B5: MACRO
    db $b5
ENDM
sNOP_BB: MACRO
    db $bb
ENDM
sNOP_CD: MACRO
    db $cd
ENDM
sNOP_CE: MACRO
    db $ce
ENDM
sNOP_CF: MACRO
    db $cf
ENDM
sNOP_DF: MACRO
    db $df
ENDM
sNPC_1_STEP_BACKWARDS: MACRO
    db $11
ENDM
sNPC_1_STEP_FORWARD: MACRO
    db $10
ENDM
sNPC_2_STEP_BACKWARDS: MACRO
    db $21
ENDM
sNPC_2_STEP_FORWARD: MACRO
    db $20
ENDM
sNPC_3_STEP_BACKWARDS: MACRO
    db $31
ENDM
sNPC_3_STEP_FORWARD: MACRO
    db $30
ENDM
sNPC_4_STEP_BACKWARDS: MACRO
    db $41
ENDM
sNPC_4_STEP_FORWARD: MACRO
    db $40
ENDM
sNPC_5_STEP_BACKWARDS: MACRO
    db $51
ENDM
sNPC_5_STEP_FORWARD: MACRO
    db $50
ENDM
sNPC_6_STEP_BACKWARDS: MACRO
    db $61
ENDM
sNPC_6_STEP_FORWARD: MACRO
    db $60
ENDM
sNPC_7_STEP_BACKWARDS: MACRO
    db $71
ENDM
sNPC_7_STEP_FORWARD: MACRO
    db $70
ENDM
sOPEN_MAP: MACRO
    db $ac
ENDM
sOPEN_SHOP: MACRO
    db $f6
    db \1
ENDM
sPLAYER_GIVE_STATUS: MACRO
    db $c4
    db \1
ENDM
sPLAYER_JUMP: MACRO
    db $8b
    db \1
ENDM
sPLAYER_STEP_BACKWARD: MACRO
    db $81
ENDM
sPLAYER_STEP_FORWARD: MACRO
    db $80
ENDM
sRESET_GAME: MACRO
    db $c8
ENDM
sRUN_ROOM_SCRIPT: MACRO
    db $ec
ENDM
sSCROLL_ROOM_DOWN: MACRO
    db $e8
ENDM
sSCROLL_ROOM_LEFT: MACRO
    db $ea
ENDM
sSCROLL_ROOM_RIGHT: MACRO
    db $eb
ENDM
sSCROLL_ROOM_UP: MACRO
    db $e9
ENDM
sSET_FAST_MOVEMENT: MACRO
    db $88
ENDM
sSET_FLAG: MACRO
    db $da
    db \1
ENDM
sSET_MUSIC: MACRO
    db $f8
    db \1
ENDM
sSET_NPC_1_DIRECTION_DOWN: MACRO
    db $15
ENDM
sSET_NPC_1_DIRECTION_LEFT: MACRO
    db $17
ENDM
sSET_NPC_1_DIRECTION_RIGHT: MACRO
    db $16
ENDM
sSET_NPC_1_DIRECTION_UP: MACRO
    db $14
ENDM
sSET_NPC_1_POSITION: MACRO
    db $19
    db \1, \2
ENDM
sSET_NPC_2_DIRECTION_DOWN: MACRO
    db $25
ENDM
sSET_NPC_2_DIRECTION_LEFT: MACRO
    db $27
ENDM
sSET_NPC_2_DIRECTION_RIGHT: MACRO
    db $26
ENDM
sSET_NPC_2_DIRECTION_UP: MACRO
    db $24
ENDM
sSET_NPC_2_POSITION: MACRO
    db $29
    db \1, \2
ENDM
sSET_NPC_3_DIRECTION_DOWN: MACRO
    db $35
ENDM
sSET_NPC_3_DIRECTION_LEFT: MACRO
    db $37
ENDM
sSET_NPC_3_DIRECTION_RIGHT: MACRO
    db $36
ENDM
sSET_NPC_3_DIRECTION_UP: MACRO
    db $34
ENDM
sSET_NPC_3_POSITION: MACRO
    db $39
    db \1, \2
ENDM
sSET_NPC_4_DIRECTION_DOWN: MACRO
    db $45
ENDM
sSET_NPC_4_DIRECTION_LEFT: MACRO
    db $47
ENDM
sSET_NPC_4_DIRECTION_RIGHT: MACRO
    db $46
ENDM
sSET_NPC_4_DIRECTION_UP: MACRO
    db $44
ENDM
sSET_NPC_4_POSITION: MACRO
    db $49
    db \1, \2
ENDM
sSET_NPC_5_DIRECTION_DOWN: MACRO
    db $55
ENDM
sSET_NPC_5_DIRECTION_LEFT: MACRO
    db $57
ENDM
sSET_NPC_5_DIRECTION_RIGHT: MACRO
    db $56
ENDM
sSET_NPC_5_DIRECTION_UP: MACRO
    db $54
ENDM
sSET_NPC_5_POSITION: MACRO
    db $59
    db \1, \2
ENDM
sSET_NPC_6_DIRECTION_DOWN: MACRO
    db $65
ENDM
sSET_NPC_6_DIRECTION_LEFT: MACRO
    db $67
ENDM
sSET_NPC_6_DIRECTION_RIGHT: MACRO
    db $66
ENDM
sSET_NPC_6_DIRECTION_UP: MACRO
    db $64
ENDM
sSET_NPC_6_POSITION: MACRO
    db $69
    db \1, \2
ENDM
sSET_NPC_7_DIRECTION_DOWN: MACRO
    db $75
ENDM
sSET_NPC_7_DIRECTION_LEFT: MACRO
    db $77
ENDM
sSET_NPC_7_DIRECTION_RIGHT: MACRO
    db $76
ENDM
sSET_NPC_7_DIRECTION_UP: MACRO
    db $74
ENDM
sSET_NPC_7_POSITION: MACRO
    db $79
    db \1, \2
ENDM
sSET_NPC_TYPES: MACRO
    db $fc
    db \1
ENDM
sSET_PLAYER_DIRECTION_DOWN: MACRO
    db $85
ENDM
sSET_PLAYER_DIRECTION_LEFT: MACRO
    db $87
ENDM
sSET_PLAYER_DIRECTION_RIGHT: MACRO
    db $86
ENDM
sSET_PLAYER_DIRECTION_UP: MACRO
    db $84
ENDM
sSET_PLAYER_HURT_SPRITE: MACRO
    db $a5
ENDM
sSET_PLAYER_LAYDOWN_SPRITE: MACRO
    db $a6
ENDM
sSET_PLAYER_NORMAL_SPRITE: MACRO
    db $a4
ENDM
sSET_PLAYER_POSITION: MACRO
    db $8a
    db \1, \2
ENDM
sSET_ROOM_TILE: MACRO
    db $b0
    db \1, \2, \3
ENDM
sSFX: MACRO
    db $f9
    db \1
ENDM
sSHAKE_SCREEN: MACRO
    db $fb
ENDM
sSPAWN_BOSS: MACRO
    db $fe
    db \1
ENDM
sSPAWN_NPC: MACRO
    db $fd
    db \1
ENDM
sTAKE_XP: MACRO
    db $d3
    dw \1
ENDM
sUNK_1A: MACRO
    db $1a
ENDM
sUNK_1B: MACRO
    db $1b
ENDM
sUNK_2A: MACRO
    db $2a
ENDM
sUNK_2B: MACRO
    db $2b
ENDM
sUNK_3A: MACRO
    db $3a
ENDM
sUNK_3B: MACRO
    db $3b
ENDM
sUNK_4A: MACRO
    db $4a
ENDM
sUNK_4B: MACRO
    db $4b
ENDM
sUNK_5A: MACRO
    db $5a
ENDM
sUNK_5B: MACRO
    db $5b
ENDM
sUNK_6A: MACRO
    db $6a
ENDM
sUNK_6B: MACRO
    db $6b
ENDM
sUNK_7A: MACRO
    db $7a
ENDM
sUNK_7B: MACRO
    db $7b
ENDM
sUNK_9A: MACRO
    db $9a
ENDM
sUNK_9B: MACRO
    db $9b
ENDM
sUNK_A0: MACRO
    db $a0
ENDM
sUNK_A1: MACRO
    db $a1
ENDM
sUNK_A2: MACRO
    db $a2
ENDM
sUNK_A3: MACRO
    db $a3
ENDM
sUNK_A9: MACRO
    db $a9
ENDM
sUNK_AB: MACRO
    db $ab
ENDM
sUNK_AF: MACRO
    db $af
ENDM
sUNK_B6: MACRO
    db $b6
ENDM
sUNK_BA: MACRO
    db $ba
    db \1, \2, \3
ENDM
sUNK_C2: MACRO
    db $c2
    db \1
ENDM
sUNK_C5: MACRO
    db $c5
    db \1
ENDM
sUNK_C6: MACRO
    db $c6
ENDM
sUNK_C7: MACRO
    db $c7
ENDM
sUNK_C9: MACRO
    db $c9
    db \1, \2
ENDM
sUNK_CA: MACRO
    db $ca
    db \1, \2
ENDM
sUNK_CC: MACRO
    db $cc
ENDM
sUNK_D4: MACRO
    db $d4
    db \1
ENDM
sUNK_D5: MACRO
    db $d5
    db \1
ENDM
sUNK_D7: MACRO
    db $d7
    db \1
ENDM
sUNK_D9: MACRO
    db $d9
    db \1
ENDM
sUNK_DC: MACRO
    db $dc
ENDM
sUNK_DD: MACRO
    db $dd
ENDM
sUNK_DE: MACRO
    db $de
ENDM
sUNK_E0: MACRO
    db $e0
ENDM
sUNK_E1: MACRO
    db $e1
ENDM
sUNK_E2: MACRO
    db $e2
ENDM
sUNK_E3: MACRO
    db $e3
ENDM
sUNK_E4: MACRO
    db $e4
ENDM
sUNK_E5: MACRO
    db $e5
ENDM
sUNK_E6: MACRO
    db $e6
ENDM
sUNK_E7: MACRO
    db $e7
ENDM
sUNK_EE: MACRO
    db $ee
ENDM
sUNK_EF: MACRO
    db $ef
    db \1, \2
ENDM
sWAIT_MAP_CLOSE: MACRO
    db $ad
ENDM
short_halt: MACRO
    db $76
ENDM
short_stop: MACRO
    db $10
ENDM
