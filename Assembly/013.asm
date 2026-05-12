.model small
.stack 100h
.data   

a db "Enter letter: $"
b db "Same $"  
c db "Different $"

.code
main proc
    mov ax, @data
    mov ds, ax
    
    mov ah, 9 
    lea dx, a 
    int 21h
    
    mov ah, 1 
    int 21h
    mov bl, al
    
    mov ah, 2
    mov dl, 10
    int 21h
    mov dl, 13
    int 21h
    
    mov ah, 9
    lea dx, a
    int 21h
    
    mov ah, 1 
    int 21h
    mov bh, al
    
    XOR bl, bh
    
    mov ah, 2
    mov dl, 10
    int 21h
    mov dl, 13
    int 21h
    
    cmp bl, 0
    je  same
    
    dif:
    mov ah, 9
    lea dx, c
    int 21h
    jmp exit
    
    same:
    mov ah, 9
    lea dx, b
    int 21h
        
    exit:
    mov ah, 4ch 
    int 21h
    main endp
end main
