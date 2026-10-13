"""specs_s2708.py - unclaimed-27 claim 8 (docs/20-unclaimed-27.md): ZRunMatPosAnim::SetFrameStart (0x4e7ce0, thiscall, ret 4).
Stubs, NOT verified:
 - The global at 0x700390 is an object G whose vtable slot +0x20 (two arguments, ret 8) records them and returns A.
 - A's vtable slot +0x2c (cdecl: its two arguments on the stack, the caller cleans) records them and counts calls.
   The exe calls it with ecx = A's vtable pointer (as the original does); the port makes the same call with inline asm.
The object A (when this+9 is nonzero) is a fresh 0x800-byte object whose +4 dword has the top two bits chosen from 00, 40,
80, C0 (plus random low bits), and whose +8 is an offset in [0, 0x300]; the lo and hi dwords sit at A+off+4 and A+off+8."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _stub(c, code):
    s = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(s, code)
    return s


def _sfs(c):
    # A and its vtable
    a = _rnd(c, 0x800)
    top = c.rng.choice([0x00000000, 0x40000000, 0x80000000, 0xc0000000])
    c.emu.w32(a + 4, top | c.rng.getrandbits(30))
    off = c.rng.randint(0x10, 0x300) & ~3   # >= 0x10 so the lo/hi dwords cannot overwrite the flags or the offset at +4 and +8
    c.emu.w32(a + 8, off)
    lo = c.rng.randint(-1000, 1000)
    hi = lo + c.rng.randint(0, 1000)
    c.emu.w32(a + off + 4, lo & 0xffffffff)
    c.emu.w32(a + off + 8, hi & 0xffffffff)
    cnt = c.emu.alloc(0x10, 4)
    rec = c.emu.alloc(0x10, 4)
    avt = c.emu.alloc(0x400, 4)
    # cdecl slot +0x2c: count, record its two arguments (caller cleans), ret
    c.emu.w32(avt + 0x2c, _stub(c, b'\xff\x05' + cnt.to_bytes(4, 'little')
                                + b'\x8b\x44\x24\x04\xa3' + rec.to_bytes(4, 'little')
                                + b'\x8b\x44\x24\x08\xa3' + (rec + 4).to_bytes(4, 'little')
                                + b'\x89\x0d' + (rec + 8).to_bytes(4, 'little') + b'\xc3'))   # mov [rec+8], ecx
    c.emu.w32(a, avt)
    # G: slot +0x20 (thiscall, two arguments, ret 8) records them and returns A (or 0 when this+9 is zero)
    grec = c.emu.alloc(0x10, 4)
    gvt = c.emu.alloc(0x400, 4)
    ret_a = a   # never null: the exe reads the vtable of the returned object, so a null would fault in both sides
    c.emu.w32(gvt + 0x20, _stub(c, b'\x8b\x44\x24\x04\xa3' + grec.to_bytes(4, 'little')
                                + b'\x8b\x44\x24\x08\xa3' + (grec + 4).to_bytes(4, 'little')
                                + b'\xb8' + ret_a.to_bytes(4, 'little') + b'\xc2\x08\x00'))
    g = _rnd(c, 0x400)
    c.emu.w32(g, gvt)
    c.emu.w32(0x700390, g)
    # the object
    o = _rnd(c, 0x800)
    c.emu.w32(o + 9, a if c.rng.random() < 0.7 else 0)
    # the argument: sometimes at a boundary
    choice = c.rng.random()
    if choice < 0.2:
        arg = lo
    elif choice < 0.4:
        arg = hi
    elif choice < 0.6:
        arg = lo - 1
    elif choice < 0.8:
        arg = hi + 1
    else:
        arg = c.rng.randint(-2**31, 2**31 - 1)
    c.emu.mu.ctl_flush_tb()
    return [o, arg & 0xffffffff]


S(0x4e7ce0, 'ZRunMatPosAnim::SetFrameStart (unknown) thiscall', 'thiscall', None, ret=None, gen=_sfs,
  note='unclaimed-27 claim 8; G slot +0x20 and A slot +0x2c are stubs; the +0x2c call is cdecl with ecx = vtable')
