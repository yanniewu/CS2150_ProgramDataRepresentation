; threexplusone.s
; Purpose : This file contains the implementation of the Collatx Conjecture and returns the number of steps taken
; Optimization: used "test" to check if a number is even/odd, used "shift" for x/2

	global threexplusone

	section .text

; Parameter 1 - the starting value (rdi)

threexplusone:
	xor rax, rax 	; counter

base:
	cmp rdi, 1 		; if (rdi==1), jump to end
	je end
	test rdi, 1 	; if rdi is odd, jump to odd
	jnz odd

even:
	shr rdi, 1 		; rdi/2
	call threexplusone
	inc rax 		; rax++
	jmp end


odd:
	;lea rdi, [rdi+rdi*2+1]     //Slower
	imul rdi, 3 	; rdi*3 + 1
	add rdi, 1 		
	call threexplusone
	inc rax 		; rax++
	jmp end
	

end:
	ret
