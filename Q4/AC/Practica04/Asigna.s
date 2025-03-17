.text
	.align 4
	.globl Asignar
	.type Asignar,@function
Asignar:
	pushl	%ebp						# save ebp old value
	movl	%esp, %ebp				# initialize new stack base pointer

	movl	8(%ebp), %ecx			# &v[] --> ecx
	imull	$12, 24(%ebp), %edx	# 12*pos
	addl	%edx, %ecx				# &v[pos] --> ecx
	# all X values need to pass through to a register in order to move them to v[pos].
	movb	12(%ebp), %dl			# X.c --> dl
	movb	%dl, (%ecx)				# v[pos].c = X.c
	movl	16(%ebp), %edx			# X.k --> edx
	movl	%edx, 4(%ecx)			# v[pos].k = X.k
	movl	20(%ebp), %edx			# X.m --> = X.m
	movl	%edx, 8(%ecx)			# v[pos].m = X.m

	# no free local variables or registers needed (it does no have)
	popl	%ebp						# restore old ebp value
	ret
