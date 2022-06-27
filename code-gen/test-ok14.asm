
main:
		PUSH	%14
		MOV 	%15,%14
		MOV 	$3,-4(%14)
		MOV 	$-9,-8(%14)
		MOV 	-4(%14),%0
		MOV		$0, %1
@mul_0:
		CMPS 	%0, $0
		JLTS	@mul_neg_0
@mul_pos_0:
		CMPS	%0, $0
		JEQ		@end_mul_0
		ADDS	%1, -8(%14), %1
		SUBS	%0, $1, %0
		JMP		@mul_pos_0
@mul_neg_0:
		CMPS 	%0, $0
		JEQ		@end_mul_0
		SUBS	%1, -8(%14), %1
		ADDS	%0, $1, %0
		JMP		@mul_neg_0
@end_mul_0:
		MOV 	%1,-12(%14)
		SUBS	%15,$12,%15
@main_body:
		MOV 	$5,%0
		MOV		$0, %1
@mul_1:
		CMPS 	%0, $0
		JLTS	@mul_neg_1
@mul_pos_1:
		CMPS	%0, $0
		JEQ		@end_mul_1
		ADDS	%1, -12(%14), %1
		SUBS	%0, $1, %0
		JMP		@mul_pos_1
@mul_neg_1:
		CMPS 	%0, $0
		JEQ		@end_mul_1
		SUBS	%1, -12(%14), %1
		ADDS	%0, $1, %0
		JMP		@mul_neg_1
@end_mul_1:
		MOV 	%1,%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET