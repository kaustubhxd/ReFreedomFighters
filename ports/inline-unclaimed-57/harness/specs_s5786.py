"""specs_s5786.py - unclaimed-57, batch 86: 0x5c4f80 (GUESS name unnamed_5c4f80). Thiscall, one stack argument obj (ret 4), returns al = 1.
The object this has an array base at +0x4c (entries of 0x19 bytes, filled with random data) and a count at +0x50 (0 to 3, so the loop runs
0 to 3 times). obj has fake slots +0x54, +0x64, +0x44 and +0x60 (one dword value each, logged) and +0x68 (one pointer: logged as an offset
from the array base, since the base is the same allocation in both executions)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _c4f80(c):
    e = c.emu
    base = _rnd(c, 0x19 * 4 + 0x20)
    n = c.rng.randrange(0, 4)

    def slot_val(off):
        def h(em, r):
            em.calllog.append(('o', off, 'O' if em.reg('ecx') == obj else 'other', (em.arg32(0),)))
            em.ret(eax=0, argbytes=4)
        return h

    def h68(em, r):
        p = em.arg32(0)
        rel = p - base if base <= p < base + 0x19 * 4 + 0x20 else 'other'
        em.calllog.append(('o', 0x68, 'O' if em.reg('ecx') == obj else 'other', (rel,)))
        em.ret(eax=0, argbytes=4)

    slots = {0x54: slot_val(0x54), 0x64: slot_val(0x64), 0x44: slot_val(0x44), 0x60: slot_val(0x60), 0x68: h68}
    vt_o = e.fake_vtable('c4f80_o', 160, slots)
    obj = _rnd(c, 0x40)
    e.w32(obj, vt_o)
    self_obj = _rnd(c, 0x80)
    e.w32(self_obj + 0x4c, base)
    e.w32(self_obj + 0x50, n)
    return [self_obj, obj]


S(0x5c4f80, 'unnamed_5c4f80 (GUESS) thiscall', 'thiscall', None, ret='al', gen=_c4f80,
  note='unclaimed-57 batch 86; obj fake slots +0x54, +0x64, +0x44, +0x60 (values logged), +0x68 (pointer logged as an offset)')
