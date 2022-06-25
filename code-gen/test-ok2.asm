
f1:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$4,%15
@f1_body:
		SUBS	8(%14),12(%14),%0
		SUBS	%0,16(%14),%0
		MOV 	%0,-4(%14)
		MOV 	-4(%14),%13
		JMP 	@f1_exit
@f1_exit:
		MOV 	%14,%15
		POP 	%14
		RET
main:
		PUSH	%14
		MOV 	%15,%14
@main_body:
			PUSH	$2
			PUSH	$4
			PUSH	$7
			CALL	f1
			ADDS	%15,$12,%15
		MOV 	%13,%0
		MOV 	%0,%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET