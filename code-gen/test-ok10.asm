
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$4,%15
@main_body:
		MOV 	$0,-4(%14)
@while_0:
		CMPS 	-4(%14),$10
		JGES	@end_while_0
			ADDS	-4(%14), $1,-4(%14)
		JMP	@while_0
@end_while_0:
		MOV 	-4(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET