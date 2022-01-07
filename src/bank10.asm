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
	ld c, 0
	
.load_attr_byte
	push hl
	inc c
	ld a, [de]
	cp $20
	jr nz, .attrs_end
	inc de
	inc de
	/*
	ld a, [de]
	sub $80
	add l
	ld l, a
	adc h
	sub l
	ld h, a
	ld a, [hl]
	*/
	inc de
	inc de
	push de
	ld de, wRoomTiles
	ld a, c
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
	
	/*
	ld a, 2
	ld [rSVBK], a
.load_attr_byte_to_wram
	ldi a, [hl]
	ld [de], a
	inc de
	dec c
	jr nz, .load_attr_byte_to_wram
	
	xor a
	ldh [rSVBK], a
	*/
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
	db $00, $00, $00, $00, $00, $02, $00, $00, $00, $02, $00, $00, $00, $02, $02, $02
	db $00, $00, $01, $01, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $02
	db $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
	db $02, $02, $02, $02, $02, $02, $01, $01, $00, $00, $00, $00, $00, $00, $00, $00
	db $02, $02, $02, $02, $02, $01, $00, $01, $00, $02, $00, $00, $00, $00, $00, $00
	db $02, $02, $02, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
	db $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $01, $00
	db $01, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $02, $01, $02, $00, $00