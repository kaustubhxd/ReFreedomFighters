"""specs_s5745.py - unclaimed-57, band batch 45: 0x5c30c0 (GUESS). Thiscall, two stack args (w, unused), ret 8. The word w equals this+0xf5, or
this+0xf7, or neither (so all three exits run). Hook: 0x5c3560 (thiscall, two arguments, callee pops 8; logged, returns 0). The object's slots
+0x64 (one argument) and +0x68 (two arguments) are logging stubs; the engine dword at +0x40 is random; the flag at +0xf9 is 0 or 1."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _disp(c):
    def h(em, r):
        em.calllog.append(('5c3560', 0, em.reg('ecx'), (em.arg32(0), em.arg32(1))))
        em.ret(eax=0, argbytes=8)
    c.emu.hook(0x5c3560, h)
    vt = c.emu.logging_vtable('band5c30c0_obj', 32, argwords={0x64: 1, 0x68: 2})
    obj = _rnd(c, 0x200)
    c.emu.w32(obj, vt)
    f5 = c.rng.getrandbits(16)
    f7 = c.rng.getrandbits(16)
    c.emu.wbytes(obj + 0xf5, bytes([f5 & 0xff, f5 >> 8]))
    c.emu.wbytes(obj + 0xf7, bytes([f7 & 0xff, f7 >> 8]))
    c.emu.wbytes(obj + 0xf9, bytes([c.rng.choice([0, 1])]))
    eng = _rnd(c, 0x100)
    c.emu.w32(eng + 0x40, c.rng.getrandbits(32))
    c.emu.w32(0x70039c, eng)
    pick = c.rng.random()
    w = f5 if pick < 0.4 else (f7 if pick < 0.8 else (f5 ^ 0x1) & 0xffff)
    return [obj, w | (c.rng.getrandbits(16) << 16), c.rng.getrandbits(32)]


S(0x5c30c0, 'unnamed_5c30c0 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_disp,
  note='unclaimed-57 band batch 45; 0x5c3560 hooked (logged, pops 8); vtable slots +0x64 and +0x68 stubbed')
