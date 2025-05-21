; linearSearch.s
;
; Purpose: implementation of linearSearch (finding the index of a value in an array)
;
; Parameter 1 is a pointer to the int array (rdi)
; Parameter 2 is the size of the array (rsi)
; Parameter 3 is the value to look for (rdx)

	global linearSearch

	section .text

linearSearch:
	xor r11, r11	; set r11 = 0 (counter)

loop:
	cmp r11, rsi 	; if (r11 > size), jump to notFound
	je notFound

	cmp [rdi+4*r11], edx	; if a[i] == target, jump to done
	je found

	inc r11     	 		; r11++
	jmp loop


found:
	mov rax, r11
	ret

notFound:
	mov rax, -1		 ; returns -1 if array does not contain target
	ret
