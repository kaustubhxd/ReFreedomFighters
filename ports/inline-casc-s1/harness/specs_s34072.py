"""specs_s34072.py - 0x466c30 (a == 0x465708 half the time, zero b/c/d often), 0x54c300 (member +0x50 null or slot 0x18 tail), 0x5d4210 (unaligned field copy; src and this distinct random blocks),
0x537790 (base dword +0x5302 unaligned, kind dword of a in 0/1/2/other, offset +8), 0x433350 (hooked 0x431410 records this and both stack args; second arg byte vs dword)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _g466c30(c):
    r = c.rng
    clear_hooks(c)
    z = lambda: r.choice([0, 0, 0, 1, r.getrandbits(32)])
    a = r.choice([0x465708, 0x465708, 0, 0x465709, r.getrandbits(32)])
    return [a, z(), z(), z()]


def _g54c300(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x60)
    inner = 0 if r.random() < 0.3 else obj(c, 0x40, {0x18: pystub(c, 1, ret=r.getrandbits(32), this=True)}, nslots=0x1c // 4)
    c.emu.w32(me + 0x50, inner)
    return [me, r.getrandbits(32)]


def _g5d4210(c):
    clear_hooks(c)
    return [rnd(c, 0x80), rnd(c, 0x80)]


def _g537790(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x5310)
    c.emu.wbytes(me + 0x5302, r.choice([0, r.getrandbits(32), r.getrandbits(32)]).to_bytes(4, 'little'))
    if r.random() < 0.15:
        return [me, 0]
    a = rnd(c, 0x20)
    c.emu.w32(a, r.choice([0, 1, 2, 2, 3, r.getrandbits(32)]))
    c.emu.w32(a + 8, r.choice([0, r.getrandbits(32), r.getrandbits(32)]))
    return [me, a]


def _g433350(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x431410, 2, ret=r.getrandbits(32), this=True)
    return [rnd(c, 0x40), r.getrandbits(32), r.choice([0, 1, 0x100, 0x1234, r.getrandbits(32)])]


S(0x466c30, 'GUESS compare against the constant 0x465708 and zeros', 'stdcall', None, ret='eax', gen=_g466c30, note='batch34072')
S(0x54c300, 'GUESS forward to member +0x50 slot 0x18', 'thiscall', None, ret='eax', gen=_g54c300, note='batch34072')
S(0x5d4210, 'GUESS copy unaligned fields', 'thiscall', None, ret=None, gen=_g5d4210, note='batch34072')
S(0x537790, 'GUESS resolve entry address', 'thiscall', None, ret='eax', gen=_g537790, note='batch34072')
S(0x433350, 'GUESS normalise second arg to bool then tail', 'thiscall', None, ret='eax', gen=_g433350, note='batch34072')
