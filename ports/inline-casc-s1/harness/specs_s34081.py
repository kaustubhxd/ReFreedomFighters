"""specs_s34081.py - eight queue items. Free lists: word [this+2] head in {0xffff, 0, 1, 3}; filters: id from {0xf, 0x1b, 0x1c, other} with [a+0xc] zero or not; box test with values around the bounds."""
from pilot import S
from recruits_util import rnd, clear_hooks


def _g537e90(c):
    clear_hooks(c)
    r = c.rng
    return [rnd(c, 0x100), r.choice([0, 1, 2, 3, 4, 4, 5, 6]), r.getrandbits(32), r.getrandbits(32)]


def _free(stride_blocks):
    def g(c):
        clear_hooks(c)
        r = c.rng
        me = rnd(c, stride_blocks)
        c.emu.wbytes(me + 2, r.choice([0xffff, 0, 1, 3, 4]).to_bytes(2, 'little'))
        return [me]
    return g


def _filt(c):
    clear_hooks(c)
    r = c.rng
    a = rnd(c, 0x20)
    c.emu.w32(a + 0xc, r.choice([0, 0, 1, r.getrandbits(32)]))
    return [a, r.choice([0xf, 0x1b, 0x1c, 0x1c, 0, 0x1d, r.getrandbits(32), 0xffffffff])]


def _g532800(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x20)
    base = [r.choice([r.getrandbits(32), r.randrange(0, 1000), 0x7ffffff0, 0x80000010]) for _ in range(6)]
    for i, v in enumerate(base):
        c.emu.w32(me + 4 + 4 * i, v)
    p = rnd(c, 0x10)
    q = rnd(c, 0x10)
    wide = r.random() < 0.3
    for i in range(3):
        dp = r.choice([-1, -1, 0, 1, -7]) if not wide else r.getrandbits(32)
        dq = r.choice([1, 1, 0, -1, 7]) if not wide else r.getrandbits(32)
        c.emu.w32(p + 4 * i, (base[3 + i] + dp) & 0xffffffff)
        c.emu.w32(q + 4 * i, (base[i] + dq) & 0xffffffff)
    return [me, r.getrandbits(32), r.getrandbits(32), p, q]


S(0x537e90, 'GUESS store slot unless index 4', 'thiscall', None, ret='al', gen=_g537e90, note='batch34081')
S(0x63b050, 'GUESS pop 0x4c-byte entry', 'thiscall', None, ret='eax', gen=_free(0x300), note='batch34081')
S(0x6486e0, 'GUESS pop 32-byte entry', 'thiscall', None, ret='eax', gen=_free(0x200), note='batch34081')
S(0x62ce20, 'GUESS event filter A', 'cdecl', None, ret='eax', gen=_filt, note='batch34081')
S(0x62d160, 'GUESS event filter B', 'cdecl', None, ret='eax', gen=_filt, note='batch34081')
S(0x62d940, 'GUESS event filter C', 'cdecl', None, ret='eax', gen=_filt, note='batch34081')
S(0x62db60, 'GUESS event filter D', 'cdecl', None, ret='eax', gen=_filt, note='batch34081')
S(0x532800, 'GUESS box strictly inside test', 'thiscall', None, ret='al', gen=_g532800, note='batch34081')
