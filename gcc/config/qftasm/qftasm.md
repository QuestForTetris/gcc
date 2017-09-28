; Machine description for the QFT computer.
; -quartata

(define_attr "length" "" (const_int 1))
(define_delay (eq_attr "type" "branch,call") [(eq_attr "type" "!branch,call") (nil) (nil)])

(define_insn "nop"
  [(const_int 0)]
  "1"
  ". MNZ 0 0 0;")

; Moves and branches

(define_insn "movhi"
  [(set (match_operand:HI 0 "" "m") (match_operand:HI 1 "" "m"))]
  "1"
  ". MLZ -1 %0 %1;")

(define_insn "indirect_jump"
  [(set (pc) (match_operand:HI 0 "" "m"))]
  "1"
  ". MLZ -1 A%0 0;")

(define_insn "jump"
  [(set (pc) (match_operand 0 "" ""))]
  "1"
  ". MLZ -1 %l0 0;")

(define_insn "cbranchhi4"
  [(set (reg:CC 0)
        (compare:CC
         (match_operand:HI 1 "" "m,m,n")
         (match_operand:HI 2 "" "m,n,m")))
   (set (pc)
        (if_then_else (match_operator 0 ""
                       [(reg:CC 0) (const_int 0)])
                      (label_ref (match_operand 3 "" ""))
                      (pc)))]
  "1"
  {
    return qft_cbranch(operands, which_alternative);
  }
  [(set_attr "length" "2")])

; Arithmetic

; Add and subtract need to support operating on the stack pointer "register", fix me
(define_insn "addhi3"
  [(set (match_operand:HI 0 "" "m,m,m") 
        (plus:HI (match_operand:HI 1 "" "m,m,n") (match_operand:HI 2 "" "m,n,m")))]
  "1"
  {
    switch (which_alternative) {
    case 0: // memory, memory
      return ". ADD A%1 A%2 %0;";
    case 1: // memory, immediate
      return ". ADD A%1 %2 %0;";
    case 2: // immediate, memory
      return ". ADD %1 A%2 %0;";
    }
  })

(define_insn "subhi3"
  [(set (match_operand:HI 0 "" "m,m,m") 
        (minus:HI (match_operand:HI 1 "" "m,m,n") (match_operand:HI 2 "" "m,n,m")))]
  ""
  {
    switch (which_alternative) {
    case 0: // memory, memory
      return ". SUB A%1 A%2 %0;";
    case 1: // memory, immediate
      return ". SUB A%1 %2 %0;";
    case 2: // immediate, memory
      return ". SUB %1 A%2 %0;";
    }
  })

(define_insn "andhi3"
  [(set (match_operand:HI 0 "" "m,m,m") 
        (and:HI (match_operand:HI 1 "" "m,m,n") (match_operand:HI 2 "" "m,n,m")))]
  "1"
  {
    switch (which_alternative) {
    case 0: // memory, memory
      return ". AND A%1 A%2 %0;";
    case 1: // memory, immediate
      return ". AND A%1 %2 %0;";
    case 2: // immediate, memory
      return ". AND %1 A%2 %0;";
    }
  })

(define_insn "iorhi3"
  [(set (match_operand:HI 0 "" "m,m,m") 
        (ior:HI (match_operand:HI 1 "" "m,m,n") (match_operand:HI 2 "" "m,n,m")))]
  "1"
  {
    switch (which_alternative) {
    case 0: // memory, memory
      return ". OR A%1 A%2 %0;";
    case 1: // memory, immediate
      return ". OR A%1 %2 %0;";
    case 2: // immediate, memory
      return ". OR %1 A%2 %0;";
    }
  })

(define_insn "xorhi3"
  [(set (match_operand:HI 0 "" "m,m,m") 
        (xor:HI (match_operand:HI 1 "" "m,m,n") (match_operand:HI 2 "" "m,n,m")))]
  "1"
  {
    switch (which_alternative) {
    case 0: // memory, memory
      return ". XOR A%1 A%2 %0;";
    case 1: // memory, immediate
      return ". XOR A%1 %2 %0;";
    case 2: // immediate, memory
      return ". XOR %1 A%2 %0;";
    }
  })

(define_insn "neghi2"
  [(set (match_operand:HI 0 "" "m") 
        (not:HI (match_operand:HI 1 "" "m")))]
  "1"
  ". ANT %1 0 %0;")

(define_insn "mulhi3"
  [(set (match_operand:HI 0 "" "m,m,m") 
        (mult:HI (match_operand:HI 1 "" "m,m,n") (match_operand:HI 2 "" "m,n,m")))]
  "1"
  {
    return qftasm_multiply(operands, which_alternative);
  }
  [(set_attr "length" "10")]) ; variable length for memory * immediate, adjusted later in qftasm.h

(define_insn "abshi2"
  [(set (match_operand:HI 0 "" "m")
        (abs:HI (match_operand:HI 1 "" "m")))]
  "1"
  {
    return ". SRA A%1 15 1;\n"
           ". ADD A%1 A1 %0;\n"
           ". XOR A%0 A1 %0;\n"
  }
  [(set_attr "length" "3")])