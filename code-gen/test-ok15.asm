
factorial:
		PUSH	%14
		MOV 	%15,%14
		MOV 	$1,-4(%14)
		SUBS	%15,$4,%15
@factorial_body:
		MOV 	$1,-8(%14)
@loop_0:
		CMPS 	-8(%14),8(%14)
		JGTS	@end_loop_0
		MOV 	-8(%14),%0
		MOV		$0, %1
@mul_0:
		CMPS 	%0, $0
		JLTS	@mul_neg_0
@mul_pos_0:
		CMPS	%0, $0
		JEQ		@end_mul_0
		ADDS	%1, -4(%14), %1
		SUBS	%0, $1, %0
		JMP		@mul_pos_0
@mul_neg_0:
		CMPS 	%0, $0
		JEQ		@end_mul_0
		SUBS	%1, -4(%14), %1
		ADDS	%0, $1, %0
		JMP		@mul_neg_0
@end_mul_0:
		MOV 	%1,-4(%14)
		ADDS	-8(%14), $1, -8(%14)
		JMP 	@loop_0
@end_loop_0:
		MOV 	-4(%14),%13
		JMP 	@factorial_exit
@factorial_exit:
		MOV 	%14,%15
		POP 	%14
		RET
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$4,%15
@main_body:
		MOV 	$0,-8(%14)
@loop_1:
		CMPS 	-8(%14),$20
		JGES	@end_loop_1
@if0:
		CMPS 	-8(%14),$10
		JLTS	@false0
@true0:
		MOV 	-8(%14),-4(%14)
		JMP	@end_loop_1
		JMP 	@exit0
@false0:
@exit0:
		ADDS	-8(%14), $1, -8(%14)
		JMP 	@loop_1
@end_loop_1:
			PUSH	-4(%14)
			CALL	factorial
			ADDS	%15,$4,%15
		MOV 	%13,%0
		MOV 	%0,%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET