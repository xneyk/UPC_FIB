.text
	.align 4
	.globl Insertar
	.type Insertar,@function
Insertar:
	# i --> %esi, j --> %edi, lug --> %ebx
	pushl	%ebp					# save ebp old value
	movl	%esp, %ebp			# update new stack base pointer
	# <-- no local variables needed -->
	pushl	%ebx
	pushl	%edi
	pushl	%esi					# store old secure register values

	movl	$0, %esi				# i = 0
	movl	$-1, %ebx			# lug = -1

	movl	8(%ebp), %ecx		# &v[0] --> ecx
_do_while:
_if1:
	movl	4(%ecx), %edx		# v[i].k --> edx
	cmpl	%edx, 16(%ebp)		# X.k <cmp> v[i].k
	jge	_else1
	movl	%esi, %ebx			# lug = i
	jmp	_end_do_while		# break
_else1:
	incl	%esi					# ++i
# end of if
	addl	$12, %ecx			# &v[i+1]
	cmpl	$0x80000000, %edx	# v[i].k <cmp> 0x80000000
	jne	_do_while
_end_do_while:
_if2:
	cmpl	$0x80000000, %edx	# v[i].k <cmp> 0x80000000
	jge	_else2
	movl	%esi, %ebx			# lug = i
	jmp	_end_if2
_else2:
_while:
	incl	%esi					# ++i
	addl	$12, %ecx			# &v[i+1]
	cmpl	$0x80000000, 4(%ecx)	# v[i].k <cmp> 0x80000000
	jne	_while
_end_if2:
	movl	%esi, %edi			# j = i
	# initialy v[j] will be v[i] because j = i
_for:
	cmpl	%ebx, %edi			# j <cmp> lug
	jl		_end_for
	movb	(%ecx), %dl			# v[j].c --> dl
	movb	%dl, 12(%ecx)		# v[j+1].c <-- dl
	movl	4(%ecx), %edx			# v[j].k --> edx
	movl	%edx, 16(%ecx)		# v[j+1].k <-- edx
	movl	8(%ecx), %edx			# v[j].m --> edx
	movl	%edx, 20(%ecx)		# v[j+1].m <-- edx

	decl	%edi					# ++j
	subl	$12, %ecx			# &v[j-1]
	jmp	_for
_end_for:
	# params for Asignar(v, X, lug)
	pushl	%ebx					# lug
	movl	20(%ebp), %edx		# X_lo
	pushl	%edx
	movl	16(%ebp), %edx
	pushl	%edx
	movl	12(%ebp), %edx
	pushl	%edx					# X_hi
	movl	8(%ebp), %edx
	pushl	%edx					# &v
	call	Asignar
	addl	$20, %esp			# free parameters
	movl	%esi, %eax			# i --> eax
	addl	$1, %eax				# i + 1 for ret
	popl	%esi					# restore esi old value
	popl	%edi					# restore edi old value
	popl	%ebx					# restore ebx old value
	popl	%ebp					# restore ebp old value
	ret
