
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$12,%15
@main_body:
		MOV 	$0,-4(%14)
		MOV 	$0,-8(%14)
		MOV 	$0,-12(%14)
@loop_0:
		CMPS 	-4(%14),$10
		JGES	@end_loop_0
@loop_1:
		CMPS 	-8(%14),$10
		JGES	@end_loop_1
@if0:
		CMPS 	-4(%14),$5
		JLTS	@false0
@true0:
		JMP	@end_loop_1
		JMP 	@exit0
@false0:
@exit0:
		ADDS	-12(%14),-8(%14),%0
		MOV 	%0,-12(%14)
		ADDS	-8(%14),$1,%0
		MOV 	%0,-8(%14)
		JMP	@loop_1
@end_loop_1:
		ADDS	-4(%14),$1,%0
		MOV 	%0,-4(%14)
		JMP	@loop_0
@end_loop_0:
		MOV 	-12(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET