"""specs_s291.py - unclaimed area 76 (docs/20-unclaimed-76.md), residue-15 logger-using leaf: 0x438eb0. Stubs: the engine
logger at 0x700390 (slot 0x20 thiscall with two arguments, returns an object; that object's slot 0x2c is a cdecl report,
logged). Exe helpers 0x439670 and 0x438e30 run as original code."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _status(c):
    e = c.emu

    def report(em, rr):                       # cdecl (obj, text): the caller pops
        args = tuple(em.arg32(k) for k in range(2))
        em.calllog.append(('rep438', 0x2c, args))
        em.ret(eax=0, argbytes=0)

    rep_vt = e.fake_vtable('rep438', 0x20, {0x2c: report})
    rep = _rnd(c, 0x40)
    e.w32(rep, rep_vt)

    def get(em, rr):                          # thiscall (two arguments): returns the report object
        args = tuple(em.arg32(k) for k in range(2))
        em.calllog.append(('log438', 0x20, args))
        em.ret(eax=rep, argbytes=8)

    lg_vt = e.fake_vtable('log438', 0x30, {0x20: get})
    lg = _rnd(c, 0x40)
    e.w32(lg, lg_vt)
    e.w32(0x700390, lg)

    o = _rnd(c, 0x40)
    e.w32(o + 0, c.rng.choice([0, 1, 2, 3]))
    e.w8(o + 0xc, c.rng.choice([0, 1, 1]))
    sub = _rnd(c, 0x20)
    e.w32(sub + 0, 3)          # 3 stops the recursion in 0x439670 (it recurses on [sub+8] otherwise)
    e.w8(sub + 0xc, c.rng.choice([0, 1, 1, 1]))
    # the object at o+0xd (used by 0x438e30): slot 0x4c writes its out pointer 0 (the loop ends); slot 0x5c writes 1 on its first call
    # (sometimes) and 0 later, and returns a value; 0x438c30 (hooked) returns a second object whose slot 0x28 returns a byte
    flip = {'n': 0}
    want_loop = c.rng.random() < 0.5

    def s4c(em, rr):
        em.w32(em.arg32(0), 0)
        em.calllog.append(('o4c', 0x4c, em.reg('ecx'), ()))
        em.ret(eax=0, argbytes=8)

    def s5c(em, rr):
        flip['n'] += 1
        em.w32(em.arg32(0), 1 if (want_loop and flip['n'] == 1) else 0)
        em.calllog.append(('o5c', 0x5c, em.reg('ecx'), ()))
        em.ret(eax=0x2a, argbytes=4)

    o_vt = e.fake_vtable('obj438', 0x80, {0x4c: s4c, 0x5c: s5c})
    o_obj = _rnd(c, 0x40)
    e.w32(o_obj, o_vt)
    e.w32(o + 0xd, o_obj)

    o2_vt = e.fake_vtable('obj438b', 0x40, {0x28: lambda em, rr: em.ret(eax=c.rng.getrandbits(8), argbytes=0)})
    o2 = _rnd(c, 0x40)
    e.w32(o2, o2_vt)

    def h438c30(em, rr):
        em.calllog.append(('h438c30', 0, em.reg('ecx'), ()))
        em.ret(eax=o2, argbytes=0)

    e.hook(0x438c30, h438c30)
    e.w32(o + 8, sub)
    e.w8(o + 0x2d, c.rng.getrandbits(8))
    a = o if c.rng.random() < 0.85 else 0
    return [_rnd(c, 0x10), a]


S(0x438eb0, 'statusOf (GUESS)', 'thiscall', None, ret='al', gen=_status, note='batch291; logger slot 0x20; ret 4')
