import utils

# Parameters
BIT_W = 32                           # bit width of CPU
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

imem = []
dmem = []
reg  = [utils.Wire(0, BIT_W)] * 32

# ALU
def alu(A, B, S):
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
        Y = A << B
    elif S == ALU_S_SRL:
        Y = A.logical_rshift(B.unsigned)
    elif S == ALU_S_SRA:
        Y = A >> B
    else:
        print("Undefined selection signal")
        Y = utils.Wire(0, BIT_W)

    if (Y.signed == 0):
        zero = 1
    else:
        zero = 0

    return Y, zero

def imem_access(iaddr):
    if (iaddr.unsigned % 4 != 0):
        print("Error: inst memory address not aligned")
    return utils.imem_readword(imem, iaddr)

# Data-memory access function
def dmem_access(maddr, mwe, Wdata):
    if (mwe):
        utils.dmem_writeword(dmem, maddr, Wdata)
        return 0
    else:
        return utils.dmem_readword(dmem, maddr)

# Register file access function
def reg_read(A1, A2):
    D1 = reg[A1.unsigned]
    D2 = reg[A2.unsigned]
    return D1, D2

def reg_write(A3, WE, WD3):
    if (WE and A3.unsigned != 0):
        reg[A3.unsigned] = WD3

# Decoders (Main decoder and ALU decoder)
def main_decoder(opcode):
    if (opcode.bstring == "0110011"): # R-Type 
        Branch = 0
        ResultSrc = 0
        MemWrite = 0
        ALUSrc  = 0
        ImmSrc = 0b00
        RegWrite = 1
        ALUOp = 0b10

    elif (opcode.bstring == "0000011"): # lw instrunction
        # write your own code here #
        Branch = 0
        ResultSrc = 1
        MemWrite = 0
        ALUSrc  = 1
        ImmSrc = 0b00
        RegWrite = 1
        ALUOp = 0b00
        
    elif (opcode.bstring == "0010011"): # I-type
        Branch = 0
        ResultSrc = 0
        MemWrite = 0
        ALUSrc  = 1
        ImmSrc = 0b00
        RegWrite = 1
        ALUOp = 0b10

        
    elif (opcode.bstring == "0100011"): # S-type
        Branch = 0
        ResultSrc = 0 #d
        MemWrite = 1
        ALUSrc  = 1
        ImmSrc = 0b01
        RegWrite = 0
        ALUOp = 0b00

    elif (opcode.bstring == "1100011"): # B-type
        Branch = 1
        ResultSrc = 0 #d
        MemWrite = 0
        ALUSrc  = 0
        ImmSrc = 0b10
        RegWrite = 0
        ALUOp = 0b01


    return Branch, ResultSrc, MemWrite, ALUSrc, ImmSrc, RegWrite, ALUOp

def alu_decoder(ALUOp, opcode, funct7, funct3):
    if (ALUOp == 0b00):         # load or store 
        ALUControl = ALU_S_ADD
    elif (ALUOp == 0b01):       # branches
        ALUControl = ALU_S_SUB
    elif (ALUOp == 0b10):       # R-type
        if (funct3.bstring == "000"):
            if (opcode.get_bits(5,5) == 1 and funct7.get_bits(5,5) == 1):
                ALUControl = ALU_S_SUB
            else:
                ALUControl = ALU_S_ADD
        elif (funct3.bstring == "110"):
            ALUControl = ALU_S_OR
        elif (funct3.bstring == "111"):
            ALUControl = ALU_S_AND
        elif (funct3.bstring == "100"):
            ALUControl = ALU_S_XOR
        elif (funct3.bstring == "001"):
            ALUControl = ALU_S_SLL
        elif (funct3.bstring == "101"):
            ALUControl = ALU_S_SRL

        # write your own code here #


    return ALUControl

def S_Ext(ImmSrc, funct7, rs2, rd):
    imm_Itype = funct7.concat(rs2)
    imm_Stype = funct7.concat(rd)
    imm_Btype = utils.Wire(funct7.get_bits(6, 6), 1).concat(utils.Wire(rd.get_bits(0, 0), 1)).concat(utils.Wire(funct7.get_bits(5, 0), 6)).concat(utils.Wire(rd.get_bits(4, 1), 4)).concat(utils.Wire(0, 1))
    
    if (ImmSrc == 0b00):
        imm = imm_Itype
    elif (ImmSrc == 0b01):
        imm = imm_Stype
    elif (ImmSrc == 0b10):
        imm = imm_Btype
    else:
        print("Unsupported ImmSrc")

    return imm

# Main CPU datapath
def datapath():
    cycle = 0
    PC = utils.Wire(0, BIT_W)

    while (True):
        print("cyble:", cycle, "PC:", hex(PC.unsigned))

        # instruction fetch
        inst = imem_access(PC)

        # decode instruction to obtain each bit field (results are string of binary)
        funct7 = utils.Wire(inst.get_bits(31, 25), 7)
        funct3 = utils.Wire(inst.get_bits(14, 12), 3)
        rs2    = utils.Wire(inst.get_bits(24, 20), 5)
        rs1    = utils.Wire(inst.get_bits(19, 15), 5)
        rd     = utils.Wire(inst.get_bits(11, 7), 5)
        opcode = utils.Wire(inst.get_bits(6, 0), 7)

        # check if finish instruction reached
        if (opcode.bstring == "1110011"): #ecall instruction executed
            print("End call executed - Finish CPU Run")
            print("Dumping data memory")
            utils.print_mem(dmem)
            print("Cycle count: ", cycle)
            quit()

        # main decoder routine
        Branch, ResultSrc, MemWrite, ALUSrc, ImmSrc, RegWrite, ALUOp = main_decoder(opcode)

        # ALU decoder routine
        ALUControl = alu_decoder(ALUOp, opcode, funct7, funct3)

        # read register file
        d1, d2 = reg_read(rs1, rs2)
        
        # generate immediate value (suppoted ImmSrc = 00 or 01 or 10)
        imm = S_Ext(ImmSrc, funct7, rs2, rd)

        # AlU input source selection
        A = d1
        if (ALUSrc == 0):
            B = d2 # write your own code here #
        else:
            B = imm # write your own code here #
            
        # AlU execution
        res_alu, zero = alu(A, B, ALUControl)

        # Data memory access
        if (opcode.bstring == "0000011" or opcode.bstring == "0100011"):
            res_dmem = dmem_access(res_alu, MemWrite, d2)

        # Result source selection
        if (ResultSrc == 0):
            wd3 = res_alu # write your own code here #
        else:
            wd3 = res_dmem # write your own code here #

        # write register file
        reg_write(rd, RegWrite, wd3)

        # Next PC calculation
        if ((Branch == 1 and zero == 1 and funct3.bstring == "000") or (Branch == 1 and zero == 0 and funct3.bstring == "001")):
            PC = PC + imm
        else:
            PC = PC + 4

        cycle = cycle + 1

        # for debuging
        utils.print_reg(reg)
        utils.print_mem(dmem)
        print()

if __name__ == "__main__":
    print("Initializeg instruction memory")
    utils.init_imem(imem, "imem.dat")
    utils.print_mem(imem)

    print("\nInitializeg data  memory")
    utils.init_dmem(dmem, "dmem.dat")
    utils.print_mem(dmem)

    print("\nStart CPU Run\n")
    datapath()
