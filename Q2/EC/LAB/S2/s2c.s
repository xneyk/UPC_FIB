	.data
w:        .asciiz "8754830094826456674949263746929"
resultat: .byte 0

	.text
	.globl main
main:
	addiu	$sp, $sp, -4
	sw	$ra, 0($sp)
	la	$a0, w
	li	$a1, 31
	jal	moda
	la	$s0, resultat
	sb	$v0, 0($s0)
	move	$a0, $v0
	li	$v0, 11
	syscall
	lw	$ra, 0($sp)
	addiu	$sp, $sp, 4
	jr 	$ra

nofares:
	li	$t0, 0x12345678
	move	$t1, $t0
	move	$t2, $t0
	move	$t3, $t0
	move	$t4, $t0
	move 	$t5, $t0
	move	$t6, $t0
	move 	$t7, $t0
	move 	$t8, $t0
	move 	$t9, $t0
	move	$a0, $t0
	move	$a1, $t0
	move	$a2, $t0
	move	$a3, $t0
	jr	$ra


moda:
	addiu $sp, $sp, -56		# Reserva B.A
	sw $s0, 0($sp)		
	sw $s1, 4($sp)
	sw $s2, 8($sp)
	sw $ra, 12($sp)
	
	move $s1, $a0			# &vec[0]
	move $s2, $a1			# num
	
	addiu $t0, $sp, 16		# &histo[0]
	li $s0, 0			# k = 0
_for_1:
	slti $t1, $s0, 10		# k < 10
	beq $t1, $zero, _end_for_1	# salta si fals
	sw $zero, 0($t0)		# histo[k] = 0
	addiu $t0, $t0, 4		# &histo[k+1]
	addiu $s0, $s0, 1		# k++
	b _for_1
_end_for_1:

	li $v0, '0'			# max = '0'
	li $s0, 0			# k = 0
_for_2:
	slt $t1, $s0, $s2		# k < num
	beq $t1, $zero, _end_for_2	# salta si fals
	li $t2, '0'
	
	addiu $a0, $sp, 16		# &histo[0]
	lb $a1, 0($s1)			# vec[k]
	subu $a1, $a1, $t2		# vec[k] - '0'
	subu $a2, $v0, $t2		# max - '0'
	
	jal update
	
	addiu $v0, $v0, '0'		# max = '0' + update()
	addiu $s1, $s1, 1		# &vec[k+1]
	addiu $s0, $s0, 1		# k++
	b _for_2
_end_for_2:
	
	lw $s0, 0($sp)			# Recuperacio valors antics de reg. segurs
	lw $s1, 4($sp)
	lw $s2, 8($sp)
	lw $ra, 12($sp)
	addiu $sp, $sp, 56		# Alliberem B.A
	
	jr $ra				# return max
	
update:
	addiu $sp, $sp, -16		# Reserva B.A
	sw $s0, 0($sp)
	sw $s1, 4($sp)
	sw $s2, 8($sp)
	sw $ra, 12($sp)
	
	move $s0, $a0			# &h[0]
	move $s1, $a1			# i
	move $s2, $a2			# imax
	
	jal nofares
	
	sll $s1, $s1, 2			# i*4
	sll $s2, $s2, 2			# imax*4
	addu $t0, $s0, $s1		# &h[i]
	addu $t2, $s0, $s2		# &h[imax]
	lw $t1, 0($t0)			# h[i]
	lw $t2, 0($t2)			# h[imax]
	
	addiu $t1, $t1, 1		#
	sw $t1, 0($t0)			# h[i]++
	
_if:
	ble $t1, $t2, _else
	srl $v0, $s1, 2			# i/4
	b _end_if
_else:
	srl $v0, $s2, 2			# imax/4
_end_if:

	lw $s0, 0($sp)
	lw $s1, 4($sp)
	lw $s2, 8($sp)
	lw $ra, 12($sp)
	addiu $sp, $sp, 16		# Allibera B.A	
	
	jr $ra				# return