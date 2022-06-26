
a:
		WORD	1
main:
		PUSH	%14
		MOV 	%15,%14
		MOV 	$3,-4(%14)
		SUBS	%15,$4,%15
@main_body:
		MOV 	$5,a
@if0:
		CMPS 	a,-4(%14)
		JLES	@false0
@true0:
		MOV 	a,%13
		JMP 	@main_exit
		JMP 	@exit0
@false0:
		MOV 	-4(%14),%13
		JMP 	@main_exit
@exit0:
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET