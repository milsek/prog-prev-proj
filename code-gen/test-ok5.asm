
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$8,%15
@main_body:
		MOV 	$0,-8(%14)
		MOV 	$5,-4(%14)
@loop_0:
		CMPS 	-4(%14),$11
		JGES	@end_loop_0
		ADDS	-4(%14),$5,%0
		MOV 	%0,-4(%14)
		SUBS	-4(%14),$2,%0
		MOV 	%0,-4(%14)
@loop_1:
		CMPS 	-8(%14),$10
		JGES	@end_loop_1
		ADDS	-8(%14),$1,%0
		MOV 	%0,-8(%14)
		JMP	@loop_1
@end_loop_1:
		JMP	@loop_0
@end_loop_0:
		MOV 	$10,%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET