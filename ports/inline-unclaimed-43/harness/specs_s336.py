"""specs_s336.py - area 71 batch 336: 0x4db520, thiscall, no arguments, returns a dword. The word at this+0x5e is 0 in 20% of
cases (the return is 0), else the engine-side slot 0x4c value (drawn in gen) plus (n-1)*0x70. The engine is the global at
0x70039c with member +0x9b, whose +8 object has slot 0x4c."""
from pilot import S
import engine_stubs as E


def _gen(c):
    r = c.rng
    val = r.getrandbits(32)
    n = 0 if r.random() < 0.2 else r.randrange(1, 6)
    slots = {}
    for i in range(0x4c // 4 + 1):
        off = 4 * i

        def h(e, rr, off=off):
            e.calllog.append(('ZENGINEOBJ', off, e.reg('ecx'), ()))
            e.ret(eax=val if off == 0x4c else 0, argbytes=0)
        slots[off] = h
    obj = E.zero_obj(c, 0x40)
    c.emu.w32(obj, c.emu.fake_vtable('ZENGINEOBJ', 0x4c // 4 + 1, slots))
    mem = E.zero_obj(c, 0x40)
    c.emu.w32(mem + 8, obj)
    eng = E.zero_obj(c, 0x400)
    c.emu.w32(eng + 0x9b, mem)
    E.set_global(c, 0x70039c, eng)
    this = E.zero_obj(c, 0x80)
    c.emu.wbytes(this + 0x5e, n.to_bytes(2, 'little'))
    c.emu.mu.ctl_flush_tb()
    return [this]


S(0x4db520, 'indexed offset from engine slot 0x4c (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='area 71 batch 336 (leaf, residue 10)')
