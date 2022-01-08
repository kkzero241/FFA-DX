INCLUDE "include/hardware.inc"
INCLUDE "include/macros.inc"
INCLUDE "include/charmaps.inc"


SECTION "bank10", ROMx[$4000],BANK[CGBBANK]

UpdateScreenPalette:
	di
	ld a, $C0
	ldh [rBCPS], a
	ldh [rOCPS], a
	ld hl, wBGPals
.update_pal_regs
	ld a, 2
	ldh [rSVBK], a
REPT 64
	ldi a,[hl]
	ldh [rBCPD], a
ENDR
REPT 64
	ldi a,[hl]
	ldh [rOCPD], a
ENDR
	xor a
	ldh [rSVBK], a
	reti
	

LoadBGPal:
	di
	push af
	ld hl, BGPalList
	ld de, wBGPals
	ld c, a
	add c
	add l
	ld l, a
	adc h
	sub l
	ld h, a
	ldi a, [hl]
	ld c, a
	ld a, [hl]
	ld h, a
	ld l, c
	ld c, 64
	
	ld a, 2
	ldh [rSVBK], a
.load_bgpal_byte_to_wram
	ldi a, [hl]
	ld [de], a
	inc de
	dec c
	jr nz, .load_bgpal_byte_to_wram
	
	xor a
	ldh [rSVBK], a
	pop af
	reti
	
LoadAttrs:
	di
	ld a, [wMapNumber]
	ld hl, AttrList
	ld de, wBackgroundRenderRequests
	push bc
	ld b, 0
	ld c, a
	add hl, bc
	add hl, bc
	ldi a, [hl]
	ld c, a
	ld a, [hl]
	ld h, a
	ld l, c
	ld a, 1
	ldh [rVBK], a
	ld c, $FF
	
.load_attr_byte
	push hl
	inc c
	ld a, [de]
	cp $20
	jr nz, .attrs_end
	inc de
	inc de
	inc de
	inc de
	push de
	ld de, wRoomTiles
	push hl
	ld hl, LevelmapLUT
	add hl, bc
	ld a, [hl]
	pop hl
	add e
	ld e, a
	ld a, [de]
	push bc
	ld c, a
	add hl, bc
	ld a, [hl]
	pop bc
	pop de
	push af
	ld a, [de]
	ld l, a
	inc de
	ld a, [de]
	ld h, a
	inc de
.stat_check
	ld a, [rSTAT]
	and a, 3
	jr nz, .stat_check
	ld a, 1
	ldh [rVBK], a
	pop af
	ldi [hl], a
	ld [hl], a
	pop hl
	jr .load_attr_byte
.attrs_end
	pop hl
	xor a
	ldh [rVBK], a
	pop bc
	reti
	
/* ;DEPRECATED FUNCTION
parseMetatileIndexNumB10:
	di
	ld hl, wRoomTileAttrs
	ld b, 0
	ld c, a
	add hl, bc
	push af
	ld c, a
	ld a, 2
	ldh [rSVBK], a
	ld a, 1
	ldh [rVBK], a
	ld a, [hl]
	ld hl, $9800
	push af
	ld a, [wBackgroundDrawPositionX]
	add l
	ld l, a
	ld a, [wBackgroundDrawPositionY]
	sla a
	sla a
	sla a
	push de
	ld d, 0
	ld e, a
	add hl, de
	add hl, de
	add hl, de
	add hl, de
	pop de
	pop af
	ld c, d
	ld d, 0
	swap c
	;de horiz, bc vert
	add hl, de
	add hl, de
	add hl, bc
	add hl, bc
	add hl, bc
	add hl, bc
	push af
.stat_check
	ld a, [rSTAT]
	and a, 3
	jr nz, .stat_check
	pop af
	ldi [hl], a
	ldd [hl], a
	ld b, 0
	ld c, $20
	add hl, bc
	ldi [hl], a
	ldd [hl], a
	xor a
	ldh [rSVBK], a
	ldh [rVBK], a
	pop af
	
	call parseMetatileIndexNumOG
	reti
*/

BGPalList:
	dw BGPalDefault
	dw BGPalOverworld
	dw BGPalDefault
	dw BGPalDefault
	dw BGPalDefault
	dw BGPalDefault
	dw BGPalDefault
	dw BGPalTitle
	dw BGPalDefault
	dw BGPalDefault
	dw BGPalDefault
	dw BGPalDefault
	dw BGPalDefault
	dw BGPalDefault
	dw BGPalDefault
	dw BGPalDefault
	
AttrList:
	dw AttrDefault
	dw AttrOverworld
	dw AttrDefault
	dw AttrDefault
	dw AttrDefault
	dw AttrDefault
	dw AttrDefault
	dw AttrDefault
	dw AttrDefault
	dw AttrDefault
	dw AttrDefault
	dw AttrDefault
	dw AttrDefault
	dw AttrDefault
	dw AttrDefault
	dw AttrDefault

BGPalDefault:
	dw $7FFF, $5294, $2D6B, $0000
	dw $7FFF, $5294, $2D6B, $0000
	dw $7FFF, $5294, $2D6B, $0000
	dw $7FFF, $5294, $2D6B, $0000
	dw $7FFF, $5294, $2D6B, $0000
	dw $7FFF, $5294, $2D6B, $0000
	dw $7FFF, $5294, $2D6B, $0000
	dw $7FFF, $5294, $2D6B, $0000
	
BGPalOverworld:
	dw $7FFF, $5294, $2D6B, $0000 ;Castle
	dw $2FEB, $1AE6, $09E2, $0000 ;Grass
	dw $43BE, $26D7, $1591, $0000 ;Soil
	dw $7FFF, $5294, $2D6B, $0000
	dw $7FFF, $5294, $2D6B, $0000
	dw $7FFF, $5294, $2D6B, $0000
	dw $7FFF, $5294, $2D6B, $0000
	dw $7FFF, $5294, $2D6B, $0000
	
BGPalTitle:
	dw $0260, $039F, $031F, $025F
	dw $7FFF, $5294, $2D6B, $0000
	dw $7FFF, $5294, $2D6B, $0000
	dw $7FFF, $5294, $2D6B, $0000
	dw $7FFF, $5294, $2D6B, $0000
	dw $7FFF, $5294, $2D6B, $0000
	dw $7FFF, $5294, $2D6B, $0000
	dw $7FFF, $5294, $2D6B, $0000
	
AttrDefault:
	db $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
	db $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
	db $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
	db $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
	db $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
	db $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
	db $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
	db $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
	
AttrOverworld:
	db $01, $01, $00, $00, $00, $00, $00, $00, $02, $00, $00, $00, $00, $00, $00, $02
	db $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $02
	db $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
	db $02, $02, $02, $02, $02, $02, $01, $01, $00, $00, $00, $00, $00, $00, $00, $00
	db $02, $02, $02, $02, $02, $01, $00, $01, $00, $02, $00, $00, $00, $00, $00, $00
	db $02, $02, $02, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
	db $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $01, $00
	db $01, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $02, $01, $02, $00, $00
	
LevelmapLUT:
	db 00, 00, 01, 01, 02, 02, 03, 03, 04, 04
	db 05, 05, 06, 06, 07, 07, 08, 08, 09, 09
	db 10, 10, 11, 11, 12, 12, 13, 13, 14, 14
	db 15, 15, 16, 16, 17, 17, 18, 18, 19, 19
	db 20, 20, 21, 21, 22, 22, 23, 23, 24, 24
	db 25, 25, 26, 26, 27, 27, 28, 28, 29, 29
	db 30, 30, 31, 31, 32, 32, 33, 33, 34, 34
	db 35, 35, 36, 36, 37, 37, 38, 38, 38, 39
	db 40, 40, 41, 41, 42, 42, 43, 43, 44, 44
	db 45, 45, 46, 46, 47, 47, 48, 48, 49, 49
	db 50, 50, 51, 51, 52, 52, 53, 53, 54, 54
	db 55, 55, 56, 56, 57, 57, 58, 58, 59, 59
	db 60, 60, 61, 61, 62, 62, 63, 63, 64, 64
	db 65, 65, 66, 66, 67, 67, 68, 68, 69, 69
	db 70, 70, 71, 71, 72, 72, 73, 73, 74, 74
	db 75, 75, 76, 76, 77, 77, 78, 78, 79, 79
/*
	db 00, 01, 02, 03, 04, 05, 06, 07, 08, 09
	db 00, 01, 02, 03, 04, 05, 06, 07, 08, 09
	db 10, 11, 12, 13, 14, 15, 16, 17, 18, 19
	db 10, 11, 12, 13, 14, 15, 16, 17, 18, 19
	db 20, 21, 22, 23, 24, 25, 26, 27, 28, 29
	db 20, 21, 22, 23, 24, 25, 26, 27, 28, 29
	db 30, 31, 32, 33, 34, 35, 36, 37, 38, 39
	db 30, 31, 32, 33, 34, 35, 36, 37, 38, 39
	db 40, 41, 42, 43, 44, 45, 46, 47, 48, 49
	db 40, 41, 42, 43, 44, 45, 46, 47, 48, 49
	db 50, 51, 52, 53, 54, 55, 56, 57, 58, 59
	db 50, 51, 52, 53, 54, 55, 56, 57, 58, 59
	db 60, 61, 62, 63, 64, 65, 66, 67, 68, 69
	db 60, 61, 62, 63, 64, 65, 66, 67, 68, 69
	db 70, 71, 72, 73, 74, 75, 76, 77, 78, 79
	db 70, 71, 72, 73, 74, 75, 76, 77, 78, 79
*/