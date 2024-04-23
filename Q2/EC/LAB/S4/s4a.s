	.data
signe:		.word 0
exponent:	.word 0
mantissa:	.word 0
cfixa:		.word 0x87D18A00
cflotant:	.float 0.0

	.text
	.globl main
main:
	addiu	$sp, $sp, -4
	sw	$ra, 0($sp)

	la	$t0, cfixa
	lw	$a0, 0($t0)
	la	$a1, signe
	la	$a2, exponent
	la	$a3, mantissa
	jal	descompon

	la	$a0, signe
	lw	$a0,0($a0)
	la	$a1, exponent
	lw	$a1,0($a1)
	la	$a2, mantissa
	lw	$a2,0($a2)
	jal	compon

	la	$t0, cflotant
	swc1	$f0, 0($t0)

	lw	$ra, 0($sp)
	addiu	$sp, $sp, 4
	jr	$ra


descompon:
	srl	$t0, $a0, 31		# $t0<0> = signe
	sw	$t0, 0($a1)		# guardem el signe
	sll	$a0, $a0, 1		# elimina el signe
	
	# exp a $t0
_if:	bne	$a0, $zero, _else	# else si cfixe == 0
	move	$t0, $zero		# exp = 0
	# no cal matissa = 0 ja que cfixe ja es 0
	b	_end_if
_else:
	li 	$t0, 18			# exp = 18
_while:	blt	$a0, $zero, _end_while	# branch if cfixe < 0 --> mantissa a part alta : $a0<31> = 1
	sll	$a0, $a0, 1		# avançem cfixe una posició
	addiu	$t0, $t0, -1		# --exp;
	b	_while
_end_while:
	srl	$a0, $a0, 8		# fem l'espai de signe i mantissa (8 bit + sobre escriure bit ocult)
	li 	$t1, 0x7FFFFF		# 
	and	$a0, $a0, $t1		# mascara mantissa i eliminació bit ocult
	addiu	$t0, $t0, 127		# exp excés a 127
	
_end_if:
	sw $t0, 0($a2)			# guardem l'exponent resultant
	sw $a0, 0($a3)			# guardem la mantissa resultant

compon:	
	move	$t0, $zero
	sll	$t0, $a0, 8		# portem el signe al bit 8.
	or	$t0, $t0, $a1		# seee eeee e
	sll	$t0, $t0, 23		# portem tot cap a la part alta (de manera que queda s a bit 31)
	or	$t0, $t0, $a2		# afegim la mantissa
	mtc1 	$t0, $f0
	
	jr	$ra			# return
