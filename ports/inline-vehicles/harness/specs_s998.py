"""specs_s998.py - area 53 (residue 11 remainder), batch 998: ZCollisionBase::GetDynamicGeomsInBoxInRooms (0x4ecd30), stdcall, ten
arguments. Every helper is a GUESS stand-in by address (machine code): 0x4e3180 and 0x4e2c60 count; 0x43e920 and 0x43e8e0 (fastcall) write
three dwords into their ECX vector from a random source; 0x4e4420 (thiscall, three stack args) counts into the struct's counter at +0x64; 0x4ec6d0
sets that counter to a random 0..3; 0x4daf90 writes three dwords into its stack vector; 0x4de7a0 writes three dwords into ECX; 0x4db600 counts;
0x4df330 answers a random flag (its stack pointers are not recorded). The element objects and the list are heap blocks."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _stub, obj, r32, rf


def code_block(c, parts):
    a = c.emu.alloc(sum(len(p) for p in parts) + 16, 16)
    c.emu.wbytes(a, b''.join(parts))
    return a


def _alloca_probe(emu, r):
    from unicorn.x86_const import UC_X86_REG_ESP, UC_X86_REG_EIP, UC_X86_REG_EAX
    mu = emu.mu
    esp = mu.reg_read(UC_X86_REG_ESP)
    eax = mu.reg_read(UC_X86_REG_EAX)
    ret = emu.r32(esp)
    mu.reg_write(UC_X86_REG_ESP, (esp + 4 - eax) & 0xffffffff)
    mu.reg_write(UC_X86_REG_EIP, ret)


def g(c):
    # --- helper stand-ins (addresses are the exe's; ss.patch writes them into the image per case)
    ss.patch(c, 0x4e3180, ss.rec(c, 0))
    ss.patch(c, 0x4e2c60, ss.rec(c, 0))
    srcA = c.emu.alloc(12, 4)
    srcB = c.emu.alloc(12, 4)
    for j in range(3):
        c.emu.w32(srcA + 4 * j, rf(c, -4, 4))
        c.emu.w32(srcB + 4 * j, rf(c, -4, 4))
    # 0x43e920 / 0x43e8e0 (fastcall: ecx = vector, edx = object, one stack arg): write three dwords into [ecx]; ret 4
    fc = [b'\x8b\x15' + struct.pack('<I', srcA + 4 * j) + b'\x89\x41' + bytes([4 * j]) for j in range(3)]
    ss.patch(c, 0x43e920, code_block(c, fc + [b'\xc2\x04\x00']))
    fc2 = [b'\x8b\x15' + struct.pack('<I', srcB + 4 * j) + b'\x89\x41' + bytes([4 * j]) for j in range(3)]
    ss.patch(c, 0x43e8e0, code_block(c, fc2 + [b'\xc2\x04\x00']))
    # 0x4e4420 (thiscall: self = r0, three stack args): inc [struct+0x64]; ret 12
    ss.patch(c, 0x4e4420, code_block(c, [b'\x8b\x44\x24\x04', b'\xff\x40\x64', b'\xc2\x0c\x00']))
    # 0x4ec6d0 (thiscall, ecx = struct): [ecx+0x64] = K; ret
    kval = c.rng.randint(0, 3)
    ss.patch(c, 0x4ec6d0, code_block(c, [b'\xc7\x41\x64' + struct.pack('<I', kval), b'\xc3']))
    # 0x4daf90 (thiscall, ecx = element, one stack arg = vector): write three dwords into [arg]; ret 4
    dv = [b'\x8b\x15' + struct.pack('<I', srcA + 4 * j) + b'\x89\x50' + bytes([4 * j]) for j in range(3)]
    ss.patch(c, 0x4daf90, code_block(c, [b'\x8b\x44\x24\x04'] + dv + [b'\xc2\x04\x00']))
    # 0x4de7a0 (thiscall, ecx = vector): write three dwords into [ecx]; ret (this is the exe's vector init; stood in here)
    dz = [b'\x8b\x15' + struct.pack('<I', srcB + 4 * j) + b'\x89\x51' + bytes([4 * j]) for j in range(3)]
    ss.patch(c, 0x4de7a0, code_block(c, dz + [b'\xc3']))
    ss.patch(c, 0x4db600, ss.rec(c, 2, log=False))
    # 0x4df330 (thiscall, ecx = a6, four stack args): returns al (random flag)
    df = _stub(c, 4, skip=(1, 2), ret=c.rng.randint(0, 1))
    ss.patch(c, 0x4df330, df)
    # the stack probe 0x6336b0 (_alloca_probe) uses a bnd branch that the emulator rejects (eip 0); its only effect here is ESP -= EAX,
    # so it is stood in by: pop the return address, sub esp,eax, push it back, ret.
    # the render manager: vslot 0x314 answers r0 (nonzero)
    r0 = 0
    R = obj(c, 0x40, {0x314: _stub(c, 0, ret=r0)})
    rm = obj(c, 0x1000)
    c.emu.w32(rm + 0xadc, R)
    sysobj = c.emu.alloc(0x200, 4)
    c.emu.w32(sysobj + 0x9b, rm)
    c.emu.w32(0x70039c, sysobj)
    # the list (four elements), the array of element pointers (three), the vector a8, the objects a6, a7
    X = [obj(c, 0x80) for _ in range(4)]
    lst = c.emu.alloc(16, 4)
    for j in range(4):
        c.emu.w32(lst + 4 * j, X[j])
    a4 = c.emu.alloc(12, 4)
    for j in range(3):
        c.emu.w32(a4 + 4 * j, X[(j + 1) % 4])
    a8 = c.emu.alloc(12, 4)
    for j in range(3):
        c.emu.w32(a8 + 4 * j, rf(c, -4, 4))
    a6 = obj(c, 0x40)
    a7 = obj(c, 0x40)
    a5 = c.rng.randint(0, 3)
    return [lst, r32(c), r32(c), a4, a5, a6, a7, a8, r32(c), c.rng.randint(0, 255)]


S(0x4ecd30, 'ZCollisionBase::GetDynamicGeomsInBoxInRooms', 'stdcall', gen=g, ret='eax')
