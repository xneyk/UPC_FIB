	.data
result: .word 0
num:	.byte '7'

	.text
	.globl main
main:
	la $t0, result
	la $t1, num	# &num
	lb $t1, 0($t1)	# num
	#$t2 registre temporal per a carregar tots els immediats necesaris per a les comparacions
	
	#CONDICIONS DE L'IF
	li $t2, 'a'
	blt $t1, $t2, _or
	li $t2, 'z'
	ble $t1, $t2, _if
_or:
	li $t2, 'A'
	blt $t1, $t2, _else_if
	li $t2, 'Z'
	blt $t2, $t1, _else_if
_if:
	sw $t1, 0($t0)	# result = num
	b _end_if
_else_if:
	#CONDICIONS DE L'ELSE_IF
	li $t3, '0'		# Guardem a $t3 per si despres hem de fer la resta aprofitar el valor
	blt $t1, $t3, _else
	li $t2, '9'
	blt $t2, $t1, _else
	
	subu $t1, $t1, $t3	# num - '0'
	sw $t1, 0($t0)
	b _end_if
_else:
	li $t2, -1
	sw $t2, 0($t0)
_end_if:
	
	jr $ra

