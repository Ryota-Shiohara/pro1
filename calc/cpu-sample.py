import utils

# Parameters
BIT_W = 32                           # bit width of CPU
BIT_MASK = 2**BIT_W - 1             # Bit mask for BIT_W
BIT_FMAT = "0" + str(BIT_W) + "b"   # Output format string

L1MISS_PENALTY = 100

# Cache parameters
CACHE_SIZE = 16          # Number of cache entries
CACHE_INDEX_BITS = 4     # log2(CACHE_SIZE)
CACHE_OFFSET_BITS = 4    # Byte offset bits 
CACHE_TAG_BITS = BIT_W - CACHE_INDEX_BITS - CACHE_OFFSET_BITS

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

# Cache structure: each entry has [valid_bit, tag, data]
cache = [[0, 0, utils.Wire(0, BIT_W)] for _ in range(CACHE_SIZE)]

# Cache statistics
cache_hits = 0
cache_misses = 0

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

# Cache access function
def cache_access(maddr, mwe, Wdata):
    global cache_hits, cache_misses
    
    # Extract tag, index, offset from address
    addr_bits = maddr.unsigned
    index = (addr_bits >> CACHE_OFFSET_BITS) & ((1 << CACHE_INDEX_BITS) - 1)
    tag = addr_bits >> (CACHE_OFFSET_BITS + CACHE_INDEX_BITS)
    
    # Check cache hit
    valid = cache[index][0]
    cache_tag = cache[index][1]
    cache_data = cache[index][2]
    
    if mwe:  # Write operation
        # Write-through: write to both cache and memory
        utils.dmem_writeword(dmem, maddr, Wdata)
        cache[index][0] = 1  # Set valid
        cache[index][1] = tag
        cache[index][2] = Wdata
        return 0, True  # Always hit on write (write-through)
    else:  # Read operation
        if valid == 1 and cache_tag == tag:
            # Cache hit!
            cache_hits += 1
            print(f"  [Cache HIT] index={index}, tag={hex(tag)}")
            return cache_data, True
        else:
            # Cache miss
            cache_misses += 1
            print(f"  [Cache MISS] index={index}, tag={hex(tag)}")
            # Load from memory
            data = utils.dmem_readword(dmem, maddr)
            # Update cache
            cache[index][0] = 1
            cache[index][1] = tag
            cache[index][2] = data
            return data, False

# Data-memory access function (now uses cache)
def dmem_access(maddr, mwe, Wdata):
    data, is_hit = cache_access(maddr, mwe, Wdata)
    return data, is_hit

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
        ResultSrc = 0b00
        MemWrite = 0
        ALUSrc  = 0
        ImmSrc = 0b00
        RegWrite = 1
        ALUOp = 0b10
        JumpPCSrc = 0b0

    elif (opcode.bstring == "0000011"): # lw instrunction
        # write your own code here #
        Branch = 0
        ResultSrc = 0b01
        MemWrite = 0
        ALUSrc  = 1
        ImmSrc = 0b00
        RegWrite = 1
        ALUOp = 0b00
        JumpPCSrc = 0b0
        
    elif (opcode.bstring == "0010011"): # I-type
        Branch = 0
        ResultSrc = 0b00
        MemWrite = 0
        ALUSrc  = 1
        ImmSrc = 0b00
        RegWrite = 1
        ALUOp = 0b10
        JumpPCSrc = 0b0

        
    elif (opcode.bstring == "0100011"): # S-type
        Branch = 0
        ResultSrc = 0b00
        MemWrite = 1
        ALUSrc  = 1
        ImmSrc = 0b01
        RegWrite = 0
        ALUOp = 0b00
        JumpPCSrc = 0b0

    elif (opcode.bstring == "1100011"): # B-type
        Branch = 1
        ResultSrc = 0b00
        MemWrite = 0
        ALUSrc  = 0
        ImmSrc = 0b10
        RegWrite = 0
        ALUOp = 0b01
        JumpPCSrc = 0b0

    elif (opcode.bstring == "1101111"):
        Branch = 1
        ResultSrc = 0b10
        MemWrite = 0
        ALUSrc = 0
        ImmSrc = 0b11
        RegWrite = 1
        ALUOp = 0b00
        JumpPCSrc = 0b0

    return Branch, ResultSrc, MemWrite, ALUSrc, ImmSrc, RegWrite, ALUOp, JumpPCSrc

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

def S_Ext(ImmSrc, funct7, rs2, rd, inst):
    imm_Itype = funct7.concat(rs2)
    imm_Stype = funct7.concat(rd)
    imm_Btype = utils.Wire(funct7.get_bits(6, 6), 1).concat(utils.Wire(rd.get_bits(0, 0), 1)).concat(utils.Wire(funct7.get_bits(5, 0), 6)).concat(utils.Wire(rd.get_bits(4, 1), 4)).concat(utils.Wire(0, 1))
    imm_JByte = utils.Wire(inst.get_bits(31, 31), 1).concat(utils.Wire(inst.get_bits(19, 12), 8)).concat(utils.Wire(inst.get_bits(20, 20), 1)).concat(utils.Wire(inst.get_bits(30, 21), 10)).concat(utils.Wire(0, 1))
    
    if (ImmSrc == 0b00):
        imm = imm_Itype
    elif (ImmSrc == 0b01):
        imm = imm_Stype
    elif (ImmSrc == 0b10):
        imm = imm_Btype
    elif (ImmSrc == 0b11):
        imm = imm_JByte
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
            
            # Print cache statistics
            total_accesses = cache_hits + cache_misses
            if total_accesses > 0:
                hit_rate = (cache_hits / total_accesses) * 100
                print(f"\n=== Cache Statistics ===")
                print(f"Cache Hits: {cache_hits}")
                print(f"Cache Misses: {cache_misses}")
                print(f"Total Accesses: {total_accesses}")
                print(f"Hit Rate: {hit_rate:.2f}%")
            
            quit()

        # main decoder routine
        Branch, ResultSrc, MemWrite, ALUSrc, ImmSrc, RegWrite, ALUOp, JumpPCSrc = main_decoder(opcode)

        # ALU decoder routine
        ALUControl = alu_decoder(ALUOp, opcode, funct7, funct3)

        # read register file
        d1, d2 = reg_read(rs1, rs2)
        
        # generate immediate value (suppoted ImmSrc = 00 or 01 or 10)
        imm = S_Ext(ImmSrc, funct7, rs2, rd, inst)

        # AlU input source selection
        A = d1
        if (ALUSrc == 0):
            B = d2 # write your own code here #
        else:
            B = imm # write your own code here #
            
        # AlU execution
        res_alu, zero = alu(A, B, ALUControl)

        # Data memory access
        cache_hit = False
        if (opcode.bstring == "0000011" or opcode.bstring == "0100011"):
            res_dmem, cache_hit = dmem_access(res_alu, MemWrite, d2)

        # Result source selection
        if (ResultSrc == 0b00):
            wd3 = res_alu # write your own code here #
        elif (ResultSrc == 0b01):
            wd3 = res_dmem # write your own code here #
        elif (ResultSrc == 0b10):
            wd3 = PC + utils.Wire(4, BIT_W)

        # write register file
        reg_write(rd, RegWrite, wd3)

        # Next PC calculation
        if ((Branch == 1 and zero == 1 and funct3.bstring == "000") or (Branch == 1 and zero == 0 and funct3.bstring == "001") or (opcode.bstring == "1101111")):
            if  (JumpPCSrc == 0b0):
                PC = PC + imm
            elif (JumpPCSrc == 0b1):
                PC = d1 + imm
        else:
            PC = PC + 4

        if (opcode.bstring == "0000011" or opcode.bstring == "0100011"):
            if cache_hit:
                cycle = cycle + 1  
            else:
                cycle = cycle + 1 + L1MISS_PENALTY  
        else:
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
