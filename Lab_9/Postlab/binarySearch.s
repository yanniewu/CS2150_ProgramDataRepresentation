; binarySearch.s
; Purpose : This file searches an array for a given number using the binary search method

global binarySearch

section .text

; Parameter 1 - pointer to int array (rdi)
; Parameter 2 - integer representing beginning of array (rsi)
; Parameter 3 - integer representing end of array (rdx)
; Parameter 4 - target element to find (rcx)

binarySearch:

loop:
	cmp rsi, rdx  	; while(low <= high)
	jg notFound

	mov r11, rsi 	; mid = (low+high)/2
	add r11, rdx
	shr r11, 1

	cmp [rdi+4*r11], ecx 		; if(a[mid]<key)
	jl low

	cmp [rdi+4*r11], ecx 		; else if(a[mid]>key)
	jg high

	cmp [rdi+4*r11], ecx 		; else
	je done


low:
	mov rsi, r11	; low = mid+1;
	add rsi, 1
	jmp loop

high:
	mov rdx, r11	; high = mid-1;
	sub rdx, 1
	jmp loop

notFound:
	mov rax, -1
	ret

done: 
	mov rax, r11
	ret
