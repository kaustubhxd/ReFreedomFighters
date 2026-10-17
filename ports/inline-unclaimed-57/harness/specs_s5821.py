"""specs_s5821.py - unclaimed-57, batch 121: 0x5c5910 (CTimerEvent::TimeUpdate(), thiscall, no args, plain ret). The counter at this+0x4c runs past the limit at
this+0x50 in about one case in three (then the body runs). The engine (global 0x70039c) has a fake vtable: slot +0x1bc (two args, returns two per-case values for
0x20 and 0x21, precomputed so both runs see them). The logger (global 0x700390) is an object whose slot +0x20 (two args) returns object o. o has slot +0x2c (a
cdecl call with three arguments: logged). The engine sub-object (+0x9b) has slot +0x114 (five args, logged; returns a per-case dword). this+0x44 is an object
with slot +0x130 (two args, logged). The divisor this+0x48 is 1 to 7 (nonzero)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d5910(c):
    e = c.emu
    rv = [c.rng.randrange(-100000, 100000) for _ in range(2)]
    ri = [0]
    o_obj = _rnd(c, 0x40)
    rw = c.rng.getrandbits(32)

    def h1bc(em, r):
        k = ri[0]
        ri[0] += 1
        em.calllog.append(('1bc', 0, None, (em.arg32(0), em.arg32(1))))
        em.ret(eax=rv[k % 2] & 0xffffffff, argbytes=8)

    def h20(em, r):
        em.calllog.append(('p20', 0, None, (em.arg32(0), em.arg32(1))))
        em.ret(eax=o_obj, argbytes=8)

    def h2c(em, r):
        em.calllog.append(('o2c', 0, None, (em.arg32(0), em.arg32(1), em.arg32(2))))
        em.ret(eax=0)   # cdecl: the caller pops the three arguments

    def h114(em, r):
        em.calllog.append(('114', 0, None, tuple(em.arg32(k) for k in range(5))))
        em.ret(eax=rw, argbytes=20)

    def h130(em, r):
        em.calllog.append(('130', 0, 'S' if em.reg('ecx') == obj else 'other', (em.arg32(0), em.arg32(1))))
        em.ret(eax=0, argbytes=8)

    vt_eng = e.fake_vtable('d5910_eng', 200, {0x1bc: h1bc})
    vt_p = e.fake_vtable('d5910_p', 200, {0x20: h20})
    vt_o = e.fake_vtable('d5910_o', 200, {0x2c: h2c})
    vt_sub = e.fake_vtable('d5910_sub', 200, {0x114: h114})
    vt_obj = e.fake_vtable('d5910_obj', 200, {0x130: h130})
    e.w32(o_obj, vt_o)
    eng = _rnd(c, 0x2000)
    e.w32(eng, vt_eng)
    sub = _rnd(c, 0x40)
    e.w32(sub, vt_sub)
    e.w32(eng + 0x9b, sub)
    e.w32(0x70039c, eng)
    p = _rnd(c, 0x40)
    e.w32(p, vt_p)
    e.w32(0x700390, p)
    obj = _rnd(c, 0x40)
    e.w32(obj, vt_obj)
    self_obj = _rnd(c, 0x100)
    e.w32(self_obj + 0x44, obj)
    e.w32(self_obj + 0x48, c.rng.randrange(1, 8))
    e.w32(self_obj + 0x4c, c.rng.randrange(0, 4))
    e.w32(self_obj + 0x50, c.rng.randrange(0, 3))
    return [self_obj]


S(0x5c5910, 'CTimerEvent::TimeUpdate (GUESS) thiscall', 'thiscall', None, ret=None, gen=_d5910,
  note='unclaimed-57 batch 121; engine slot +0x1bc, logger slot +0x20, o slot +0x2c (cdecl), sub slot +0x114, obj slot +0x130 fake')
