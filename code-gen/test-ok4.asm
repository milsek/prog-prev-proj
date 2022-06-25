
main:
		PUSH	%14
		MOV 	%15,%14
@main_body:
@if0:
		CMPS 	$5,$3
		JLES	@false0
@true0:
		MOV 	$5,%13
		JMP 	@main_exit
		JMP 	@exit0
@false0:
		MOV 	$3,%13
		JMP 	@main_exit
@exit0:
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET