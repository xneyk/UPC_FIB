.text
	.align 4
	.globl OperaMat
	.type	OperaMat, @function
OperaMat:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	pushl	%ebx
	pushl	%esi
	pushl	%edi
# Aqui has de introducir el codigo
	# %esi === i
	# %edi === j
	# %eax === res

	movl	$0, %eax						# res = 0
	movl	$0, %esi						# i = 0
_for_i:
	cmpl	$3, %esi						# i <cmp> 3
	jge	_end_for_i

	movl	$0, %edi						# j = 0
_for_j:
	cmpl	%esi, %edi					# j <cmp> i
	jg		_end_for_j

	imull	N, %esi, %ecx				# %ecx <- i*N
	addl	%edi, %ecx					# %ecx <- i*N + j
	addl	8(%ebp, %ecx, 4), %eax	# res += Matriz[i][j]

	incl	%edi							# ++j
	jmp	_for_j
_end_for_j:

	addl	12(%ebp), %esi				# i += salto
	jmp	_for_i
_end_for_i:

	movl	%eax, -4(%ebp)				# res -> MEM.
	movl	%esi, -8(%ebp)				# i_reg -> i_MEM
	movl	%esi, -12(%ebp)			# j_reg -> j_MEM
	
# El final de la rutina ya esta programado
	movl	-4(%ebp), %eax
	popl	%edi
	popl	%esi
	popl	%ebx
	movl	%ebp,%esp
	popl	%ebp
	ret