"""vh.py - shared spec helpers for the vehicles thread (copied from inline-batch45 specs_s55.py:
_rnd random heap block, _stub recording heap stub, _obj object with a fake vtable), plus rnd32/rbool."""
import struct


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _stub(c, nargs, fills=(), ret=0, skip=(), fld=None, copy=None, adds=(), ofills=(), peeks=()):
    """copy = (argidx, [(off, 'd'|'b'), ...]) copies fields of the struct an arg points to into the record."""
    nrec = nargs + 1 + (len(copy[1]) if copy else 0) + len(peeks)
    rec = c.emu.alloc(4 * nrec, 4)
    code = b''
    for i in range(nargs):
        if i in skip:
            continue
        code += b'\x8b\x44\x24' + bytes([4 + 4 * i]) + b'\xa3' + struct.pack('<I', rec + 4 * i)
    if copy:
        code += b'\x8b\x44\x24' + bytes([4 + 4 * copy[0]])
        for k, (off, kind) in enumerate(copy[1]):
            code += (b'\x8b\x50' if kind == 'd' else b'\x0f\xb6\x50') + bytes([off])
            code += b'\x89\x15' + struct.pack('<I', rec + 4 * (nargs + 1 + k))
    for k, addr in enumerate(peeks):   # record a dword of memory at call time
        code += b'\xa1' + struct.pack('<I', addr) + b'\xa3' + struct.pack('<I', rec + 4 * (nrec - len(peeks) + k))
    for ai, off, src, nd in ofills:   # out = [arg]+off, filled from src
        code += b'\x8b\x44\x24' + bytes([4 + 4 * ai])
        for j in range(nd):
            code += b'\x8b\x15' + struct.pack('<I', src + 4 * j) + b'\x89\x50' + bytes([off + 4 * j])
    for ai, src, nd in adds:   # out[j] += src[j] (SSE single adds), like a local-to-world offset
        code += b'\x8b\x44\x24' + bytes([4 + 4 * ai])
        for j in range(nd):
            code += b'\xf3\x0f\x10\x40' + bytes([4 * j]) + b'\xf3\x0f\x58\x05' + struct.pack('<I', src + 4 * j)
            code += b'\xf3\x0f\x11\x40' + bytes([4 * j])
    for ai, src, nd in fills:
        code += b'\x8b\x44\x24' + bytes([4 + 4 * ai])
        for j in range(nd):
            code += b'\x8b\x15' + struct.pack('<I', src + 4 * j) + b'\x89\x50' + bytes([4 * j])
    code += b'\xff\x05' + struct.pack('<I', rec + 4 * nargs)
    if fld is not None:
        code += b'\xd9\x05' + struct.pack('<I', fld)
    code += b'\xb8' + struct.pack('<I', ret & 0xffffffff) + b'\xc2' + struct.pack('<H', 4 * nargs)
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def _obj(c, size, slots):
    o = _rnd(c, size)
    vt = c.emu.alloc(max(slots) + 4, 4)
    for off, code in slots.items():
        c.emu.w32(vt + off, code)
    c.emu.w32(o, vt)
    return o


def obj(c, size, slots=None):
    """Random object of `size` bytes; slots {vtable offset: code addr}; vtable of 0x800 bytes filled with a
    trap address so an unexpected vcall faults the same way in both runs."""
    o = _rnd(c, size)
    vt = c.emu.alloc(0x800, 4, fill=0)
    for off in range(0, 0x800, 4):
        c.emu.w32(vt + off, 0x0dead000 + off)
    for off, code in (slots or {}).items():
        c.emu.w32(vt + off, code)
    c.emu.w32(o, vt)
    return o


def r32(c):
    return c.rng.getrandbits(32)


def rf(c, lo=-1000.0, hi=1000.0):
    """random float bits, with some specials"""
    k = c.rng.random()
    if k < 0.05:
        return c.rng.choice([0, 0x80000000, 0x3f800000, 0xbf800000])
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(lo, hi)))[0]


def cstub(c, nargs, ret=0):
    """cdecl stub (caller pops): records nargs stack args and a call count, returns ret in eax."""
    rec = c.emu.alloc(4 * (nargs + 1), 4)
    code = b''
    for i in range(nargs):
        code += b'\x8b\x44\x24' + bytes([4 + 4 * i]) + b'\xa3' + struct.pack('<I', rec + 4 * i)
    code += b'\xff\x05' + struct.pack('<I', rec + 4 * nargs)
    code += b'\xb8' + struct.pack('<I', ret & 0xffffffff) + b'\xc3'
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def idstub(c, table, nargs=1):
    """thiscall stub for id -> object lookups (world slot 0x58): returns table[arg0 & 3], records the last arg0 and
    a call count; pops nargs."""
    rec = c.emu.alloc(8, 4)
    tbl = c.emu.alloc(16, 4)
    for i in range(4):
        c.emu.w32(tbl + 4 * i, table[i % len(table)])
    code = (b'\x8b\x44\x24\x04' + b'\xa3' + struct.pack('<I', rec) + b'\xff\x05' + struct.pack('<I', rec + 4) +
            b'\x83\xe0\x03' + b'\x8b\x04\x85' + struct.pack('<I', tbl) + b'\xc2' + struct.pack('<H', 4 * nargs))
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def fconst(c, v):
    a = c.emu.alloc(4, 4)
    c.emu.wf32(a, v)
    return a


def hookrec(c, addr, nargs, ret=0, this=True, peeks=(), skip=(), cdecl=False):
    """Stand in for the exe function at addr for this case (both runs): records ECX (if this), the stack args, the
    dwords at `peeks` (pairs (argidx, offset): read [arg + offset]) and a call count into a heap block, sets EAX and
    pops nargs. Use for deep callees with direct calls (particle emitters, sound) that cannot be given a vtable stub."""
    from unicorn.x86_const import UC_X86_REG_ECX
    n = (1 if this else 0) + nargs + len(peeks) + 1
    rec = c.emu.alloc(4 * n, 4)

    def h(emu, res):
        esp = emu.reg('esp')
        k = 0
        if this:
            emu.w32(rec, emu.mu.reg_read(UC_X86_REG_ECX))
            k = 1
        for i in range(nargs):
            if i not in skip:   # skip stack-address args (they differ between the two runs)
                emu.w32(rec + 4 * (k + i), emu.r32(esp + 4 + 4 * i))
        for j, (ai, off) in enumerate(peeks):
            emu.w32(rec + 4 * (k + nargs + j), emu.r32(emu.r32(esp + 4 + 4 * ai) + off))
        emu.w32(rec + 4 * (n - 1), emu.r32(rec + 4 * (n - 1)) + 1)
        emu.ret(eax=ret, argbytes=0 if cdecl else 4 * nargs)
    c.emu.hook(addr, h)
    return rec
