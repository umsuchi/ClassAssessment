.model small
.stack 100h
.data
msg db 3
mssg db ?

.code
main proc
    mov ax, @data
    mov ds, ax
    
    mov ah, 2
    add msg, 48    
    mov ah, 2
    mov dl, msg
    int 21h
    
    mov ah, 1
    int 21h
    mov mssg, al  
    
    mov ah, 2
    mov dl, 10
    int 21h
    mov dl, 13
    int 21h
    
    mov ah, 2
    mov dl, mssg
    int 21h
    
    exit:
    mov ah, 4ch
    int 21h
    main endp
end main