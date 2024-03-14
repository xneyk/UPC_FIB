	.data

	.text
	.globl main
main:	
	li $t4, 0x1234ABCD
	li $t1, 16
	addiu $t2, $t4, 0
bucle:
	srl $t4, $t4, 1		# srl 16
	addu $t2, $t2, $t2	# $t4 * 1610
	addiu $t1, $t1, -1
	bne $t1, $zero, bucle
	or $t4, $t4, $t2