
a:
		WORD	1
b:
		WORD	1
main:
		PUSH	%14
		MOV 	%15,%14
@main_body:
		MOV 	$5,a
		MOV 	$3,b
@if0:
		CMPS 	a,b
		JLES	@false0
@true0:
		MOV 	a,%13
		JMP 	@main_exit
		JMP 	@exit0
@false0:
		MOV 	b,%13
		JMP 	@main_exit
@exit0:
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET