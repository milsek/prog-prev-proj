
increment:
		PUSH	%14
		MOV 	%15,%14
@increment_body:
		ADDS	8(%14),$1,%0
		MOV 	%0,%13
		JMP 	@increment_exit
@increment_exit:
		MOV 	%14,%15
		POP 	%14
		RET
add:
		PUSH	%14
		MOV 	%15,%14
@add_body:
		ADDS	12(%14),8(%14),%0
		MOV 	%0,%13
		JMP 	@add_exit
@add_exit:
		MOV 	%14,%15
		POP 	%14
		RET
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$8,%15
@main_body:
			PUSH	$1
			CALL	increment
			ADDS	%15,$4,%15
		MOV 	%13,%0
		MOV 	%0,-4(%14)
			PUSH	$1
			PUSH	$2
			CALL	add
			ADDS	%15,$8,%15
		MOV 	%13,%0
		MOV 	%0,-8(%14)
		ADDS	-4(%14),-8(%14),%0
		MOV 	%0,%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET