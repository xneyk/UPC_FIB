.text
	.align 4
	.globl OperaVec
	.type	OperaVec, @function
OperaVec:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	pushl	%ebx
	pushl	%esi
	pushl	%edi
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -4(%ebp)
# Aqui has de introducir el codigo
# %esi === i
# %eax === res
	movl	$1, %esi 					# i = 1
	movl	-4(%ebp), %eax 			# eax <-- res
_for:
	cmpl	12(%ebp), %esi				# i <cmp> elementos
	jge	_end_for
_if:
	movl	8(%ebp), %ecx				# &Vector
	movl	(%ecx, %esi, 4), %edx	# edx <-- Vector[i]
	cmpl	-4(%ecx, %esi, 4), %edx	# Vector[i] <cmp> Vector[i-1]
	jne	_end_if
	movl	%esi, %eax					# res = i
_end_if:
	incl	%esi							# ++i
	jmp	_for
_end_for:
#	movl	%esi, -8(%ebp)				# i de registre a memoria (tot i no ser necesari ja que es destrueix)
	movl	%eax, -4(%ebp)				# res = res_registre (redundant pero per seguir els criteris de l'estructura)

# El final de la rutina ya esta programado
	movl	-4(%ebp), %eax
	popl	%edi
	popl	%esi
	popl	%ebx
	movl	%ebp,%esp
	popl	%ebp
	ret
