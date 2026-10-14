"""specs_s34096.py - seven items.
0x533da0: free-list table with this+4 head index 0..3 and links; a = 0 / 0x80000000 / small. 0x5be720: assert hook word 0x7003b0 is a recorder stub; n -2..5, cursor around n, tag bytes 0xff in a third.
0x63dbc0: 0..3 entry blocks with the unaligned key; a = 0 or one of the keys. 0x545cb0: five pointer outputs. 0x5aef80: 0..3 entries. 0x52db40: both bound words around each other."""
from pilot import S
from recruits_util import rnd, clear_hooks


def _g533da0(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x60)
    c.emu.w32(me + 4, r.choice([0, 1, 2, 3]))
    for i in range(6):
        c.emu.w32(me + 8 * i + 0xc, r.choice([0, 1, 2, 3, 0x80000000, 0x80000002, 0xfffffffe]))
    return [me, r.choice([0, 0x80000000, 1, 2, 3, 4, 5]), r.getrandbits(32)]


def _g5be720(c):
    clear_hooks(c)
    r = c.rng

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    c.emu.w32(0x7003b0, c.emu.stub_fn('assert hook', ah))
    me = rnd(c, 0x940)
    n = r.choice([0xfffffffe, 0, 1, 2, 3, 5])
    c.emu.w32(me + 0x910, n)
    c.emu.wbytes(me + 0x922, r.choice([0, 1, 2, 4, 0xffffffff, 7, 0xfffffffe]).to_bytes(4, 'little'))
    for i in range(8):
        c.emu.wbytes(me + 0x71c + 5 * i, bytes([r.choice([0xff, 0xff, 0, 1, 0xfe])]))
    return [me]


def _g63dbc0(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x110)
    n = r.choice([0, 1, 2, 3])
    c.emu.w32(me + 0xec, n)
    keys = []
    for i in range(n):
        e = rnd(c, 0x10040)
        k = r.getrandbits(32)
        keys.append(k)
        c.emu.wbytes(e + 0x10029, k.to_bytes(4, 'little'))
        c.emu.w32(me + 0xf0 + 4 * i, e)
    a = r.choice([0, 0] + keys + [r.getrandbits(32)])
    return [me, a]


def _filt(c):
    clear_hooks(c)
    r = c.rng
    a = rnd(c, 0x20)
    c.emu.w32(a + 0xc, r.choice([0, 0, 1, r.getrandbits(32)]))
    return [a, r.choice([0x15, 0x24, 0x24, 0xf, 0x1c, 0x1c, 0, 0x1d, r.getrandbits(32), 0xffffffff])]


def _g545cb0(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x20)
    base = rnd(c, 0x34 * 4 + 0x40)
    c.emu.wbytes(me + 0xf, base.to_bytes(4, 'little'))
    return [me, r.choice([0, 1, 2, 3]), rnd(c, 0x10), rnd(c, 0x10), rnd(c, 0x10), rnd(c, 0x10)]


def _g5aef80(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x30)
    n = r.choice([0, 1, 2, 3])
    c.emu.w32(me, n)
    a = r.getrandbits(32)
    for i in range(n):
        e = rnd(c, 0x20)
        c.emu.w32(e + 0x10, a if r.random() < 0.4 else r.getrandbits(32))
        c.emu.w32(me + 4 + 4 * i, e)
    return [me, a]


def _g52db40(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x40)
    P = rnd(c, 0x50)
    m = r.choice([0, 1, 2, 3, 5, 10, 32, 33, 0x7fffffff, 0x80000000, r.getrandbits(32)])
    c.emu.w32(P + 0x38, m)
    c.emu.w32(me, P)
    s = (m + r.choice([0, 1, 2, 3, -1, -2, 5, 100])) & 0xffffffff
    c.emu.wbytes(me + 0x12, s.to_bytes(4, 'little'))
    return [me]


S(0x533da0, 'GUESS free-list alloc', 'thiscall', None, ret='eax', gen=_g533da0, note='batch34096')
S(0x5be720, 'GUESS round-robin free slot', 'thiscall', None, ret='eax', gen=_g5be720, note='batch34096')
S(0x63dbc0, 'GUESS find entry by key', 'thiscall', None, ret='eax', gen=_g63dbc0, note='batch34096')
S(0x62d560, 'GUESS event filter P', 'cdecl', None, ret='eax', gen=_filt, note='batch34096')
S(0x545cb0, 'GUESS read record fields', 'thiscall', None, ret='eax', gen=_g545cb0, note='batch34096')
S(0x5aef80, 'GUESS find field by key', 'thiscall', None, ret='eax', gen=_g5aef80, note='batch34096')
S(0x52db40, 'GUESS derive masks and state byte', 'thiscall', None, ret=None, gen=_g52db40, note='batch34096')
