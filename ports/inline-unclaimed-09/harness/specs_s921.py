"""specs_s921.py - unclaimed-09 batch 13 (docs/20-unclaimed-09.md, claim 13): ZMoveToPlayer::Init2().

The global at 0x70039c is 0x2000 random bytes; its +0x9b object is A. Every virtual call is a logged Python handler
(unverified callees):
- A: vt+0x138 returns r1; vt+0x58 takes the out value and returns x (or null in about one case in five).
- r1: vt+0x88 writes a random dword (the out value) through its pointer argument.
- x: vt+0x20 returns E (three calls, the same object).
- E: vt+0x1e0 returns a random bool (al); vt+0x94 logs the two locals read through its pointers; vt+0x28c logs its
  three arguments.
- this+0x44 = D: vt+0x80 writes two random dwords through its pointers; D+8 is a random value.
- this: vt+0x58 logs the end of the function.
Stack pointers are never logged; the values read through them are."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    e = c.emu
    rng = c.rng
    out_val = rng.getrandbits(32)
    al = rng.getrandbits(1)
    x_null = rng.random() < 0.2
    l34_v = rng.getrandbits(32)
    l10_v = rng.getrandbits(32)
    d8 = rng.getrandbits(32)

    def h_r1_88(e2, r):
        e2.calllog.append(('R1_88', e2.arg32(0)))
        e2.w32(e2.arg32(1), out_val)
        e2.ret(eax=0, argbytes=8)

    def h_a_138(e2, r):
        e2.calllog.append(('A138',))
        e2.ret(eax=r1, argbytes=0)

    def h_a_58(e2, r):
        e2.calllog.append(('A58', e2.arg32(0)))
        e2.ret(eax=0 if x_null else xobj, argbytes=4)

    def h_x_20(e2, r):
        e2.calllog.append(('X20',))
        e2.ret(eax=eobj, argbytes=0)

    def h_e_1e0(e2, r):
        e2.calllog.append(('E1e0', e2.arg32(0)))
        e2.ret(eax=al, argbytes=4)

    def h_e_94(e2, r):
        p34, p10 = e2.arg32(0), e2.arg32(1)
        e2.calllog.append(('E94', int.from_bytes(e2.rbytes(p34, 4), 'little'), int.from_bytes(e2.rbytes(p10, 4), 'little')))
        e2.ret(eax=0, argbytes=8)

    def h_e_28c(e2, r):
        e2.calllog.append(('E28c', e2.arg32(0), e2.arg32(1), e2.arg32(2)))
        e2.ret(eax=0, argbytes=12)

    def h_d_80(e2, r):
        p34, p10 = e2.arg32(0), e2.arg32(1)
        e2.w32(p34, l34_v)
        e2.w32(p10, l10_v)
        e2.calllog.append(('D80',))
        e2.ret(eax=0, argbytes=8)

    def h_this_58(e2, r):
        e2.calllog.append(('This58',))
        e2.ret(eax=0, argbytes=0)

    r1 = e.fake_object('mtp_r1', 0x40, slots={0x88: h_r1_88})
    eobj = e.fake_object('mtp_e', 0x40, slots={0x1e0: h_e_1e0, 0x94: h_e_94, 0x28c: h_e_28c})
    xobj = e.fake_object('mtp_x', 0x40, slots={0x20: h_x_20})
    a = e.fake_object('mtp_a', 0x40, slots={0x138: h_a_138, 0x58: h_a_58})
    d = e.fake_object('mtp_d', 0x40, slots={0x80: h_d_80})
    e.w32(d + 8, d8)
    g = _rnd(c, 0x2000)
    e.w32(g + 0x9b, a)
    e.w32(0x70039c, g)
    this = e.fake_object('mtp_this', 0x100, slots={0x58: h_this_58})
    e.wbytes(this + 4, bytes(rng.getrandbits(8) for _ in range(0x100 - 4)))
    e.w32(this + 0x44, d)
    return [this]


S(0x4bbac0, 'ZMoveToPlayer::Init2 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-09 b13; every vtable call stubbed (unverified callees)')
