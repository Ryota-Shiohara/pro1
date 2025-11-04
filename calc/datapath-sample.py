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

# Memory read or write type signal definition
MEM_R = 0b0 #0 load data from memory
MEM_W = 0b1 #1 store data to memory

# Data Path operation type signal definition
DP_ALU = 0b0 #0 ALU operation in the datapath 
DP_MEM = 0b1 #1 Memory operation in the datapath

# Output binary value with 2's complement
def printbit(v):
    print("0b" + format((v & BIT_MASK), BIT_FMAT) + " (" + str(v) + ")")

# Data-memory and Register-file definition
dmem = [0b0000_1001, 0b0000_0100, 0b0000_0101, 0b0000_0010, 0b0000_0000, 0b0000_0000, 0b0000_0000, 0b0000_0000]
reg  = [0b0000_0000] * 4


# ALU
def alu(A, B, S):
    A0 = A
    B0 = B
    if A & 2**(BIT_W - 1) > 0:
        A = (A & 2**(BIT_W-1) - 1) - 2**(BIT_W-1)
    
    if B & 2**(BIT_W - 1) > 0:
        B = (B & 2**(BIT_W-1) - 1) - 2**(BIT_W-1)

    # copy your own ALU implementatino here

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

# Data-memory access function
def dmem_access(maddr, mwe, Wdata):
    if (mwe):
        dmem[maddr] = Wdata
        return 0
    else:
        return dmem[maddr]

# Register file access functions
def reg_read(A1, A2):
    D1 = reg[A1]
    D2 = reg[A2]
    return D1, D2

def reg_write(A3, WE, WD3):
    if (WE and A3 != 0):
        reg[A3] = WD3

# Datapath
def datapath(dp_type, op, a1, a2, a3, maddr):
    # Write your own code here 
    if dp_type == DP_ALU:
        D1, D2 = reg_read(a1, a2)
        reg_write(a3, MEM_W, alu(D1, D2, op))
    else:
        if op == MEM_R:
            reg_write(a3, MEM_W, dmem_access(maddr, MEM_R, NA))
        else:
            D1, D2 = reg_read(a1, NA)
            dmem_access(maddr, MEM_W, D1)
        
        



# Main routine for test
if __name__ == "__main__":
    NA = 0
    datapath(DP_MEM,     MEM_R, NA, NA,  1,  0) # reg[1] <- dmem[0]
    datapath(DP_MEM,     MEM_R, NA, NA,  2,  1) # reg[2] <- dmem[1]
    datapath(DP_ALU, ALU_S_ADD,  1,  2,  3, NA) # reg[3] <- reg[1] + reg[2]
    datapath(DP_MEM,     MEM_R, NA, NA,  1,  2) # reg[1] <- dmem[2]
    datapath(DP_MEM,     MEM_R, NA, NA,  2,  3) # reg[2] <- dmem[3]
    datapath(DP_ALU, ALU_S_ADD,  1,  2,  2, NA) # reg[2] <- reg[1] + reg[2]
    datapath(DP_ALU, ALU_S_SUB,  3,  2,  1, NA) # reg[1] <- reg[3] - reg[2]
    datapath(DP_MEM,     MEM_W,  1, NA, NA,  4) # dmem[4] <- reg[1]

    print(dmem)
    print(reg)
