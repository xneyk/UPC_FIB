
	.data 
mat1:	.space 120	# 5*6*4
mat2:	.space 15	# 3*5
	.align 3
mat3:	.space 32	# 2*2*8
#	.align 2
mat4:	.word 2, 3, 1, 2, 4, 3	# {{2,3,1},{2,4,3}}

	.text 
	.globl main
main:
	