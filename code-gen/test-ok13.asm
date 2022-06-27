
fibonacci:
		PUSH	%14
		MOV 	%15,%14
		MOV 	$0,-4(%14)
		MOV 	$1,-8(%14)
		MOV 	$0,-12(%14)
		MOV 	$2,-16(%14)
		SUBS	%15,$16,%15
@fibonacci_body:
@loop_0:
		CMPS 	-16(%14),8(%14)
		JGTS	@end_loop_0
		ADDS	-4(%14),-8(%14),%0
		MOV 	%0,-12(%14)
		MOV 	-8(%14),-4(%14)
		MOV 	-12(%14),-8(%14)
		ADDS	-16(%14), $1,-16(%14)
		JMP	@loop_0
@end_loop_0:
		CMPS 	12(%14),$0
		JNE 	@false0
@true0:
		MOV 	-8(%14),%0
		JMP 	@exit0
@false0:
		MOV 	-4(%14),%0
@exit0:
		MOV 	%0,%13
		JMP 	@fibonacci_exit
@fibonacci_exit:
		MOV 	%14,%15
		POP 	%14
		RET
main:
		PUSH	%14
		MOV 	%15,%14
@main_body:
			PUSH	$25
			CALL	fibonacci
			ADDS	%15,$4,%15
		MOV 	%13,%0
		MOV 	%0,%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET