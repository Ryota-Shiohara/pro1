# Parameters
BIT_W = 8                           # bit width of CPU
BIT_MASK = 2**BIT_W - 1             # Bit mask for BIT_W
BIT_FMAT = "0" + str(BIT_W) + "b"   # Output format string


# ALU selection signal definition
ALU_S_ADD = 0b000 #0
ALU_S_SUB = 0b001 #1
ALU_S_AND = 0b010 #2
ALU_S_OR  = 0b011 #3
ALU_S_XOR = 0b100 #4
ALU_S_SLL = 0b101 #5 (Shift Left Logical)
ALU_S_SRL = 0b110 #6 (Shift Right Logical)
ALU_S_SRA = 0b111 #7 (Shift Right Arithmetic)

def printbit(v):
    print("0b" + format((v & BIT_MASK), BIT_FMAT) + " (" + str(v) + ")")

# ALU
def alu(A, B, S):
    A0 = A
    B0 = B
    if A & 2**(BIT_W - 1) > 0:
        A = (A & 2**(BIT_W-1) - 1) - 2**(BIT_W-1)
    
    if B & 2**(BIT_W - 1) > 0:
        B = (B & 2**(BIT_W-1) - 1) - 2**(BIT_W-1)

    # write your own code here

    if S == ALU_S_ADD:
        Y = A + B
    elif S == ALU_S_SUB:
        Y = A - B
    elif S == ALU_S_AND:
        Y = A & B
    elif S == ALU_S_OR:
        Y = A | B
    elif S == ALU_S_XOR:
        Y = A ^ B
    elif S == ALU_S_SLL:
        Y = A * 2 ** B
    elif S == ALU_S_SRL:
        Y = A0 // 2 ** B
    elif S == ALU_S_SRA:
        Y = A // 2 ** B




    Y = Y & BIT_MASK
   
    if Y & 2**(BIT_W - 1) > 0:
        return (Y & 2**(BIT_W-1) - 1) - 2**(BIT_W-1)
    else:
        return Y

if __name__ == "__main__":
    A = 0b0000_0110; B = 0b0011_0010; S = ALU_S_ADD; printbit(alu(A, B, S))
    A = 0b0000_0110; B = 0b0011_0010; S = ALU_S_SUB; printbit(alu(A, B, S))
    A = 0b0000_0110; B = 0b0011_0010; S = ALU_S_AND; printbit(alu(A, B, S))
    A = 0b0000_0110; B = 0b0011_0010; S = ALU_S_OR;  printbit(alu(A, B, S))
    A = 0b0000_0110; B = 0b0011_0010; S = ALU_S_XOR; printbit(alu(A, B, S))
    A = 0b0000_0110; B = 0b0000_0010; S = ALU_S_SLL; printbit(alu(A, B, S))
    A = 0b1000_0110; B = 0b0000_0010; S = ALU_S_SRL; printbit(alu(A, B, S))
    A = 0b1000_0110; B = 0b0000_0010; S = ALU_S_SRA; printbit(alu(A, B, S))

