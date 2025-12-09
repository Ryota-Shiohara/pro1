BIT_W = 32                           # bit width of CPU

class Wire:
    """Class representing a signal with fixed bit width"""
    
    def __init__(self, value, bit_width=BIT_W):
        self.bit_width = bit_width
        self.mask = (1 << bit_width) - 1
        self.sign_bit = 1 << (bit_width - 1)
        # Mask value to specified bit width
        self._value = value & self.mask
    
    @property
    def unsigned(self):
        """Get as unsigned integer"""
        return self._value
    
    @property
    def signed(self):
        """Get as signed integer"""
        if self._value & self.sign_bit:
            return self._value - (1 << self.bit_width)
        return self._value

    @property
    def bstring(self):
        """Get as binary string"""
        bin = format(self._value, f'0{self.bit_width}b')
        return bin

    def get_bits(self, high, low):
        """Get specified bit range"""
        mask = (1 << (high - low + 1)) - 1
        return (self._value >> low) & mask
    
    def __add__(self, other):
        """Addition"""
        if isinstance(other, Wire):
            result = self.signed + other.signed
        else:
            result = self.signed + other
        return Wire(result, self.bit_width)
    
    def __sub__(self, other):
        """Subtraction"""
        if isinstance(other, Wire):
            result = self.signed - other.signed
        else:
            result = self.signed - other
        return Wire(result, self.bit_width)
    
    def __and__(self, other):
        """Bitwise AND"""
        if isinstance(other, Wire):
            result = self.unsigned & other.unsigned
        else:
            result = self.unsigned & other
        return Wire(result, self.bit_width)
    
    def __or__(self, other):
        """Bitwise OR"""
        if isinstance(other, Wire):
            result = self.unsigned | other.unsigned
        else:
            result = self.unsigned | other
        return Wire(result, self.bit_width)
    
    def __xor__(self, other):
        """Bitwise XOR"""
        if isinstance(other, Wire):
            result = self.unsigned ^ other.unsigned
        else:
            result = self.unsigned ^ other
        return Wire(result, self.bit_width)
    
    def __lshift__(self, shift):
        """Logical left shift"""
        if isinstance(shift, Wire):
            shift = shift.unsigned
        result = (self.unsigned << shift) & self.mask
        return Wire(result, self.bit_width)
    
    def logical_rshift(self, shift):
        """Logical right shift"""
        if isinstance(shift, Wire):
            shift = shift.unsigned
        result = self.unsigned >> shift
        return Wire(result, self.bit_width)
    
    def arithmetic_rshift(self, shift):
        """Arithmetic right shift"""
        if isinstance(shift, Wire):
            shift = shift.unsigned
        # Right shift as signed value
        result = self.signed >> shift
        return Wire(result, self.bit_width)

    def __rshift__(self, shift):
        """Arithmetic right shift"""
        if isinstance(shift, Wire):
            shift = shift.unsigned
        # Right shift as signed value
        result = self.signed >> shift
        return Wire(result, self.bit_width)

    def concat(self, other):
        """Arithmetic right shift"""
        if isinstance(other, Wire):
            return Wire(int(self.bstring + other.bstring, 2), self.bit_width + other.bit_width)
        else:
            print("Unsupported operation for concat")
            return 0
    

def init_imem(imem, filename):
    try:
        with open(filename, "r") as file:
            tmp = []
            for line in file:
                if "//" in line:
                    line = line.split("//")[0]
                for char in line:
                    if char.isdigit():
                        tmp.append(char)
                imem.append(int("".join(tmp[24:32]), 2))
                imem.append(int("".join(tmp[16:24]), 2))
                imem.append(int("".join(tmp[8:16]), 2))
                imem.append(int("".join(tmp[0:8]), 2))
                tmp = []
    except FileNotFoundError:
        print(f"Cannot find the file: {filename}")
    except Exception as e:
        print(f"Error: {e}")

def init_dmem(dmem, filename):
    try:
        with open(filename, "r") as file:
            for line in file:
                dmem.append(int(line[6:8], 16))
                dmem.append(int(line[4:6], 16))
                dmem.append(int(line[2:4], 16))
                dmem.append(int(line[0:2], 16))
    except FileNotFoundError:
        print(f"Cannot find the file: {filename}")
    except Exception as e:
        print(f"Error: {e}")

def imem_readword(imem, addr0):
    addr = addr0.unsigned
    return Wire((imem[addr+3] << 24) + (imem[addr+2] << 16) + (imem[addr+1] << 8) + imem[addr], BIT_W)

def dmem_readword(dmem, addr0):
    addr = addr0.unsigned
    return Wire((dmem[addr+3] << 24) + (dmem[addr+2] << 16) + (dmem[addr+1] << 8) + dmem[addr], BIT_W)

def dmem_writeword(dmem, addr0, data0):
    addr = addr0.unsigned
    data = data0.unsigned
    dmem[addr+3] = (data >> 24) & 0xff
    dmem[addr+2] = (data >> 16) & 0xff
    dmem[addr+1] = (data >> 8)  & 0xff
    dmem[addr]   = data & 0xff

def print_mem(mem):
    for i in range(0, len(mem), 4):
        print (format(i, f'0{4}x') + ": 0x" + format(mem[i+3], f'0{2}x') + format(mem[i+2], f'0{2}x') + format(mem[i+1], f'0{2}x') + format(mem[i], f'0{2}x'))

def print_reg(reg):
    for i in range(0, 31):
        print(str(reg[i].signed) + ", ", end="")
    print (reg[31].signed)
