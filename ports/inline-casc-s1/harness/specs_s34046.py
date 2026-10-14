"""specs_s34046.py - cascade tier E, batch 34046.
0x486c30: the key is one of the seven fields, a duplicate of an earlier field (the first match wins) or unrelated (the assert hook, which returns a random value, is set).
0x4d2680: hooked 0x634d22 performs the copy in Python and logs (n, source bytes); 0x4d2820 logs the whole stack message (header dwords and payload bytes, read through its pointer argument) and
the /GS check 0x633654 is a recorder; b and d are 0..0x40, a / e random buffers.
0x4d87c0: the import atol is a Python stub (parses the leading integer of the string, logs its argument bytes, pops nothing); p is null in a third; [this+0x104] points at a byte; slot 4 of this
(two stack arguments, caller-popped) returns a block; the logger object at 0x700390 (slot 0x20 then caller-popped slot 0x2c) is set."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _assert_hook(c):
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))


def _g486c30(c):
    clear_hooks(c)
    r = c.rng
    _assert_hook(c)
    me = rnd(c, 0x40)
    offs = [0x10, 0x14, 0x18, 0x1c, 0x24, 0x20, 0x28]
    vals = [r.getrandbits(32) for _ in offs]
    if r.random() < 0.4:
        i, j = sorted(r.sample(range(7), 2))
        vals[j] = vals[i]
    for o, v in zip(offs, vals):
        c.emu.w32(me + o, v)
    k = r.choice(vals) if r.random() < 0.85 else r.getrandbits(32)
    return [me, k]


def _g4d2680(c):
    clear_hooks(c)
    r = c.rng

    def mc(em, res_):
        dst, src, n = em.arg32(0), em.arg32(1), em.arg32(2)
        data = bytes(em.rbytes(src, n))
        em.calllog.append(('memcpy', n, data))
        em.wbytes(dst, data)
        em.ret(eax=dst, argbytes=0)
    c.emu.stub_import  # (the memcpy is an exe function, hooked below)
    c.emu.hook(0x634d22, mc)

    def msg(em, k):
        p = em.arg32(0)
        b = em.r32(p)
        d = em.r32(p + 8)
        em.calllog.append(('msg', em.r32(p), em.r32(p + 4), em.r32(p + 8), bytes(em.rbytes(p + 0xc, b + d))))
    hook_rec(c, 0x4d2820, 1, this=True, side=msg, stackmark=(0,))
    hook_rec(c, 0x633654, 0, pop=0)
    b, d = r.randint(0, 0x40), r.randint(0, 0x40)
    return [rnd(c, 0x20), rnd(c, 0x80), b, r.getrandbits(32), d, rnd(c, 0x80)]


def _g4d87c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def atol(em, res_):
        s = em.arg32(0)
        txt = bytes(em.rbytes(s, 8))
        em.calllog.append(('atol', txt))
        digits = b''
        for ch in txt:
            if 0x30 <= ch <= 0x39:
                digits += bytes([ch])
            else:
                break
        em.ret(eax=int(digits) if digits else 0, argbytes=0)
    e.stub_import('atol', atol)
    lg2 = obj(c, 0x20, {0x2c: pystub(c, 3, this=True, pop=0)}, nslots=0x40 // 4)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=lg2, this=True)}, nslots=0x20)
    e.w32(0x700390, lg)
    res = rnd(c, 0x20)
    me = obj(c, 0x110, {4: pystub(c, 2, ret=res, this=True, pop=0)}, nslots=8)
    flag = rnd(c, 0x10)
    e.w32(me + 0x104, flag)
    if r.random() < 1 / 3:
        p = 0
    else:
        p = rnd(c, 0x10)
        e.wbytes(p, r.choice([b'0\0', b'1\0', b'12ab\0', b'x\0', b'00\0', bytes([r.randrange(1, 256) for _ in range(6)]) + b'\0']))
    return [me, p]


S(0x486c30, 'GUESS map key to one of seven fields', 'thiscall', None, ret='eax', gen=_g486c30, note='batch34046')
S(0x4d2680, 'GUESS pack two byte blocks into a stack message and send it', 'thiscall', None, ret=None, gen=_g4d2680, note='batch34046')
S(0x4d87c0, 'GUESS set flag byte from parsed number or log it', 'thiscall', None, ret=None, gen=_g4d87c0, note='batch34046')
