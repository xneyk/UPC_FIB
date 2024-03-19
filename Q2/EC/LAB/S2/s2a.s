	.data

	.text
	.globl main
main:
	li $s1, 23 # Y
	li $s0, 8  # X

# COPIA EL TEU CODI AQUI
	
	li $t0, 0x01
	sllv $t0, $t0, $s0	# 1<<X
	addiu $t0, $t0, -1	# (1<<X)-1
	xor $s1, $s1, $t0	# Y^(1<<X)-1
	
	jr $ra