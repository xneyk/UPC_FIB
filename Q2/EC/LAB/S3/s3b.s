	# Sessio 3

	.data 
# Declara aqui les variables mat1, mat4 i col

mat1:	.space 120		# 5*6*4
#	.align 2
mat4:	.word 2, 3, 1, 2, 4, 3	# {{2,3,1},{2,4,3}} 
col:	.word 2

	.text 
	.globl main
main:	
	addiu $sp, $sp, -4	# reservem B.A per $ra
	sw $ra, 0($sp)		# guardem $ra al B.A
	
	la $a0, mat4
	lw $a1, 8($a0)		# @mat4[0][2] = @mat4+(0*3+2)*4
	la $a2, col
	lw $a2, 0($a2)
	
	jal subr
	
	la $s0, mat1		# @mat1[4][3] = @mat1+(4*6+3)*4
	sw $v0, 108($t0)	# mat1[4][3] = subr(mat4, mat4[0][2], col)
	
	la $a0, mat4
	li $a1, 1
	li $a2, 1
	
	jal subr

	sw $v0, 0($s0)		# mat1[0][0] = subr(mat4, 1, 1)
	
	lw $ra, 0($sp)
	addiu $sp, $sp, 4	# alliberem B.A
	jr $ra
subr:
	la $t0, mat1 + 20	# @mat1[j][5] = @mat1+(j*6+5)*4 = @mat1+20 + j*6*4
	li $t1, 24		# 6*4
	mult $t1, $a2		# j*6*4
	mflo $t1
	addu $t0, $t0, $t1	# @mat1[j][5]
	
	li $t1, 3
	mult $a1, $t1		# i*3
	mflo $t1
	addu $t1, $t1, $a2	# i*3+j
	sll $t1, $t1, 2		# (i*3+j)*4
	addu $a0, $a0, $t1	# @x[i][j] = @x + (i*3+j)*4
	lw $a0, 0($a0)		# x[i][j]
	sw $a0, 0($t0)		# mat[j][5] = x[i][j]
	
	move $v0, $a1		# return i;
	jr $ra
