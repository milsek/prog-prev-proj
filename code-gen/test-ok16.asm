
main:
		PUSH	%14
		MOV 	%15,%14
		MOV 	$0,-4(%14)
		MOV 	$0,-8(%14)
		SUBS	%15,$8,%15
@main_body:
@loop_0:
		CMPS 	-4(%14),$6
		JGES	@end_loop_0
		MOV 	$0,-12(%14)
@loop_1:
		CMPS 	-12(%14),$6
		JGES	@end_loop_1
		ADDS	-4(%14),-8(%14),%0
		ADDS	%0,-12(%14),%0
		MOV 	%0,-8(%14)
		ADDS	-12(%14), $1, -12(%14)
		JMP 	@loop_1
@end_loop_1:
		ADDS	-4(%14), $1,-4(%14)
		JMP		@loop_0
@end_loop_0:
		MOV 	-8(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET