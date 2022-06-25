
f1:
		PUSH	%14
		MOV 	%15,%14
@f1_body:
		MOV 	8(%14),%13
		JMP 	@f1_exit
@f1_exit:
		MOV 	%14,%15
		POP 	%14
		RET
main:
		PUSH	%14
		MOV 	%15,%14
@main_body:
			PUSH	$10
			CALL	f1
			ADDS	%15,$4,%15
		MOV 	%13,%0
		MOV 	%0,%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET