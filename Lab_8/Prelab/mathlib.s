; mathlib.s
;
; Purpose: Implememntation of product and power
;
; Parameter 1 (in rdi) is x
; Parameter 2 (in rsi) is y

 	global product
 	global power

 	section .text

product:

startProd:
 	mov rax, 0 		; sets rax to 0
 	mov r10, rsi	; uses y as counter in r10

loopProd:
	add rax, rdi	; rax += x
	dec r10	 		; r10--
	jnz loopProd    ; repeats loop until r10=0

doneProd:
	ret


power:

startPow:
	mov rax, 0 		; sets rax to 0
	cmp rsi, 0 		; if (y == 0), return base case
	je basePow			

	dec rsi			; y--
	call power 	; recursion
	mov rsi, rax
	call product	; multiply using product
	ret
    
basePow:
	mov rax, 1
	ret
	
	









