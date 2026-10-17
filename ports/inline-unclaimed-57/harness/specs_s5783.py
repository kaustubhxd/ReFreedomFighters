"""specs_s5783.py - unclaimed-57, batch 83: 0x5c6370 (GUESS name unnamed_5c6370). Thiscall, two stack arguments (flag, obj; ret 8), no return
value; this is not used. In about one case in ten obj is null (early return). The object obj has fake slots +0x4c (one argument: writes 0
through it) and +0x5c (one argument: writes the loop flag through it and returns a handle); the flag sequence is 0 to 3 nonzero values
then zero. The engine (global 0x70039c) sub-object at +0x9b has a fake slot +0x58 (one argument: the handle, logged) returning an object
r (null in about one case in four). r has fake slots +0x28 and +0x2c (no arguments, logged with their tag). Only the low byte of flag
matters, so both values are chosen at random."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _c6370(c):
    e = c.emu
    seq = [1] * c.rng.randrange(0, 4) + [0]
    handles = [c.rng.getrandbits(32) for _ in range(4)]
    idx = [0]
    r_obj = _rnd(c, 0x40)
    null_r = c.rng.random() < 0.25

    def h4c(em, r):
        em.calllog.append(('4c', 0, None, ()))
        em.w32(em.arg32(0), 0)
        em.ret(eax=0, argbytes=4)

    def h5c(em, r):
        i = idx[0]
        idx[0] += 1
        flag = seq[i] if i < len(seq) else 0
        em.calllog.append(('5c', 0, None, (flag,)))
        em.w32(em.arg32(0), flag)
        em.ret(eax=handles[i % 4], argbytes=4)

    def h58(em, r):
        em.calllog.append(('58', 0, None, (em.arg32(0),)))
        em.ret(eax=0 if null_r else r_obj, argbytes=4)

    def h28(em, r):
        em.calllog.append(('28', 0, 'R' if em.reg('ecx') == r_obj else 'other', ()))
        em.ret(eax=0, argbytes=0)

    def h2c(em, r):
        em.calllog.append(('2c', 0, 'R' if em.reg('ecx') == r_obj else 'other', ()))
        em.ret(eax=0, argbytes=0)

    vt_obj = e.fake_vtable('c6370_obj', 160, {0x4c: h4c, 0x5c: h5c})
    vt_sub = e.fake_vtable('c6370_sub', 160, {0x58: h58})
    vt_r = e.fake_vtable('c6370_r', 160, {0x28: h28, 0x2c: h2c})
    e.w32(r_obj, vt_r)
    obj = _rnd(c, 0x40)
    e.w32(obj, vt_obj)
    sub = _rnd(c, 0x40)
    e.w32(sub, vt_sub)
    eng = _rnd(c, 0x100)
    e.w32(eng + 0x9b, sub)
    e.w32(0x70039c, eng)
    self_obj = _rnd(c, 0x40)
    flag = c.rng.getrandbits(32)
    return [self_obj, flag, 0 if c.rng.random() < 0.1 else obj]


S(0x5c6370, 'unnamed_5c6370 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_c6370,
  note='unclaimed-57 batch 83; obj slots +0x4c and +0x5c fake (flag sequence); engine sub slot +0x58 fake; r slots +0x28 and +0x2c logged')
