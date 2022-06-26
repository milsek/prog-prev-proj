
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$8,%15
@main_body:
		MOV 	$0,-8(%14)
		MOV 	$5,-4(%14)
@while_0:
		CMPS 	-4(%14),$11
		JGES	@end_while_0
		ADDS	-4(%14),$5,%0
		MOV 	%0,-4(%14)
		SUBS	-4(%14),$2,%0
		MOV 	%0,-4(%14)
@while_1:
		CMPS 	-8(%14),$10
		JGES	@end_while_1
		ADDS	-8(%14),$1,%0
		MOV 	%0,-8(%14)
		JMP	@while_1
@end_while_1:
		JMP	@while_0
@end_while_0:
		MOV 	$10,%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET