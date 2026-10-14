"""specs_s5798.py - unclaimed-57, batch 98: 0x5d9e20 (GUESS name unnamed_5d9e20). Thiscall, no stack args, plain ret. The engine (global 0x70039c)
sub-object at +0x9b has a fake slot +0x58 (one argument, logged) that returns four distinct objects e1..e4 on its four calls. Each object has fake
slots +0x27c (one argument, logged) and +0x250 (no arguments, logged). The writes to e1..e4 (+0x30 and +0x48) and to this (+0x88, +0x8c, +0x90,
+0x94) are checked by the heap comparison. The fields +0x48 to +0x54 are random dwords."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d9e20(c):
    e = c.emu
    objs = [_rnd(c, 0x80) for _ in range(4)]
    idx = [0]

    def h58(em, r):
        k = idx[0]
        idx[0] += 1
        em.calllog.append(('58', 0, None, (em.arg32(0),)))
        em.ret(eax=objs[k], argbytes=4)

    def h27c(em, r):
        em.calllog.append(('27c', 0, 'E' if em.reg('ecx') in objs else 'other', (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    def h250(em, r):
        em.calllog.append(('250', 0, 'E' if em.reg('ecx') in objs else 'other', ()))
        em.ret(eax=0, argbytes=0)

    vt_o = e.fake_vtable('d9e20_o', 160, {0x27c: h27c, 0x250: h250})
    for o in objs:
        e.w32(o, vt_o)
    vt_sub = e.fake_vtable('d9e20_sub', 160, {0x58: h58})
    sub = _rnd(c, 0x40)
    e.w32(sub, vt_sub)
    eng = _rnd(c, 0x100)
    e.w32(eng + 0x9b, sub)
    e.w32(0x70039c, eng)
    self_obj = _rnd(c, 0x100)
    return [self_obj]


S(0x5d9e20, 'unnamed_5d9e20 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_d9e20,
  note='unclaimed-57 batch 98; engine sub slot +0x58 fake (four objects); e1..e4 slots +0x27c and +0x250 logged')
