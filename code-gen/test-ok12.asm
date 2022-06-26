
main:
		PUSH	%14
		MOV 	%15,%14
		MOV 	$5,-4(%14)
		MOV 	$7,-8(%14)
		ADDS	-4(%14),-8(%14),%0
		CMPS 	%0,$9
		JGES	@false0
@true0:
		MOV 	$9,%0
		JMP 	@exit0
@false0:
		MOV 	$25,%0
@exit0:
		MOV 	%0,-12(%14)
		SUBS	%15,$12,%15
@main_body:
		MOV 	-12(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET