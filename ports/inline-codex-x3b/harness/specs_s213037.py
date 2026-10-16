"""specs_s213037.py - batch 213037: record table lookups with log calls and a slot 0xac forward, Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub

_TAB = None


def _table(e):
    global _TAB
    if _TAB is None:
        raw = e.rbytes(0x6e7a30, 18 * 0x14)
        _TAB = [struct.unpack_from('<5I', raw, 0x14 * k) for k in range(18)]
    return _TAB


def g4d2700(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    tab = _table(e)
    rec = r.choice(tab)
    key = rec[2]
    import os
    if os.environ.get('DBG'): print('KEY', key)
    mask = r.choice([rec[4], rec[4], 0, r.getrandbits(32), 1, rec[4] & 0xffff])

    def lg(emu, res_):
        a = [emu.arg32(0), emu.arg32(1)]
        if a[1] == 0x6963cc:
            a.append(emu.arg32(2))
        emu.calllog.append(('log', emu.reg('ecx'), tuple(a)))
        emu.ret(eax=r.getrandbits(32))
    L = obj(c, 0x20, {0x24: e.stub_fn('log', lg)}, nslots=0xc)
    e.w32(0x700390, L)
    this = obj(c, 0x20, {0xac: pystub(c, 5, ret=r.getrandbits(32), this=True, stackmark=(4,))}, nslots=0x30)
    s = bytes(r.randint(1, 255) for _ in range(r.randint(0, 8))) + b'\0'
    sp = rnd(c, len(s) + 4)
    e.wbytes(sp, s)
    t = rec[2]
    if t in (0xc, 0xe):
        xs = bytes(r.randint(1, 255) for _ in range(r.randint(0, 8))) + b'\0'
        X = rnd(c, len(xs) + 4)
        e.wbytes(X, xs)
    elif t in (0xf, 0x11, 5, 0xd):
        X = rnd(c, 8)
    else:
        X = r.getrandbits(32)
    Y = r.choice([0, 0, r.getrandbits(32), 1])
    return [this, sp, mask, key, X, Y]


S(0x4d2700, 'record_forward', 'thiscall', None, ret='eax', gen=g4d2700)
