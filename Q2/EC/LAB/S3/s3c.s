	# Sessio 3

	.data 
mat:	.word 0,0,2,0,0,0
	.word 0,0,4,0,0,0
	.word 0,0,6,0,0,0
	.word 0,0,8,0,0,0
	
result:	.word 0

	.text 
	.globl main
main:
	addiu $sp, $sp, -4
	sw $ra, 0($sp)
	
	la $a0, mat
	jal suma_col
	la $t0, result
	sw $v0, 0($t0)
	
	lw $ra, 0($sp)
	addiu $sp, $sp, 4
	jr $ra
	
suma_col:
	move $v0, $zero		# int suma = 0;
	addiu $t6, $a0, 8	# int *p = &m[0][2] = &m+(0*NC + 2)*4
	move $t7, $zero		# int i = 0
	
_for:	sltiu $t0, $t7, 4
	beq $t0, $zero, _end_for

	lw $t1, 0($t6)		# *p
	addu $v0, $v0, $t1	# suma += *p
	addiu $t6, $t6, 24	# 6 elems * 4 bytes
	addiu $t7, $t7, 1	# i++
	
	b _for
_end_for:
	jr $ra

