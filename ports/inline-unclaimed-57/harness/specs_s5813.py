"""specs_s5813.py - unclaimed-57, batch 113: 0x5d3d90 (GUESS name unnamed_5d3d90). Thiscall, no stack args, plain ret. The sub-object (engine +0x9b) has fake
slots +0x138 (returns an object x, the same each time) and +0x58 (one arg, logged; returns a per-case dword). x has a fake slot +0x88 (two args: the key,
logged; it writes the per-key value through the pointer). The five keys 0x681320, 0x68fcbc, 0x68fccc, 0x68fcdc and 0x67a1b8 each get their own value, so
each of this+0x68, +0x6c, +0x70, +0x74 and +0x85 is checked by the heap comparison and by the logged arguments."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d3d90(c):
    e = c.emu
    keys = [0x681320, 0x68fcbc, 0x68fccc, 0x68fcdc, 0x67a1b8]
    vals = {k: c.rng.getrandbits(32) for k in keys}
    rv = c.rng.getrandbits(32)

    def h138(em, r):
        em.calllog.append(('138', 0, None, ()))
        em.ret(eax=x_obj, argbytes=0)

    def h58(em, r):
        em.calllog.append(('58', 0, None, (em.arg32(0),)))
        em.ret(eax=rv, argbytes=4)

    def h88(em, r):
        k = em.arg32(0)
        em.calllog.append(('88', 0, None, (k,)))
        em.w32(em.arg32(1), vals.get(k, 0x12345678))
        em.ret(eax=0, argbytes=8)

    vt_sub = e.fake_vtable('d3d90_sub', 200, {0x138: h138, 0x58: h58})
    vt_x = e.fake_vtable('d3d90_x', 200, {0x88: h88})
    x_obj = _rnd(c, 0x40)
    e.w32(x_obj, vt_x)
    sub = _rnd(c, 0x100)
    e.w32(sub, vt_sub)
    eng = _rnd(c, 0x2000)
    e.w32(eng + 0x9b, sub)
    e.w32(0x70039c, eng)
    self_obj = _rnd(c, 0x200)
    return [self_obj]


S(0x5d3d90, 'unnamed_5d3d90 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_d3d90,
  note='unclaimed-57 batch 113; sub slots +0x138 and +0x58 fake; x slot +0x88 writes per-key values (five keys)')
