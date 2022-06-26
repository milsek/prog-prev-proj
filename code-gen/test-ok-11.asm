
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$8,%15
@main_body:
		MOV 	$51,-4(%14)
		MOV 	$0,-8(%14)
@while_0:
		CMPS 	-4(%14),-8(%14)
		JLES	@end_while_0
			SUBS	-4(%14), $1,-4(%14)
			ADDS	-8(%14), $1,-8(%14)
		JMP	@while_0
@end_while_0:
		MOV 	-4(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET