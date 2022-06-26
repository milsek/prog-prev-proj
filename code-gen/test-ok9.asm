
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$8,%15
@main_body:
		MOV 	$0,-4(%14)
		MOV 	$0,-8(%14)
@while_0:
		CMPS 	-4(%14),$10
		JGES	@end_while_0
		ADDS	-4(%14),$1,%0
		MOV 	%0,-4(%14)
@if0:
		CMPS 	-4(%14),$5
		JGES	@false0
@true0:
		JMP	@while_0
		JMP 	@exit0
@false0:
@exit0:
		ADDS	-8(%14),-4(%14),%0
		MOV 	%0,-8(%14)
		JMP	@while_0
@end_while_0:
		MOV 	-8(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET