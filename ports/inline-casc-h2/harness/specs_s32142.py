"""specs_s32142.py - h2 (Sonnet) batch 32142: 0x5b9050, 0x6106e0. Callees/slots are recorders."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, reftab

NAN = 0x7fc00000


def _bits(f):
    try:
        return struct.unpack('<I', struct.pack('<f', f))[0]
    except OverflowError:
        return 0x7f800000


def _fv(bits):
    return struct.unpack('<f', struct.pack('<I', bits))[0]


def _log(tag):
    return lambda emu, k: emu.calllog.append((tag,))


def _assert_hook(c):
    r = c.rng

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    c.emu.w32(0x7003b0, c.emu.stub_fn('assert hook', ah))


def g5b9050(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, side=_log('gs'))
    n = r.choice([0, 1, 2, 3])
    ids = [r.choice([0, r.getrandbits(32), r.getrandbits(32)]) for _ in range(n)]
    sobjs = []
    for _ in range(n):
        blk = rnd(c, 0x60)
        for off in (0x40, 0x44, 0x48):
            e.w32(blk + off, _bits(r.uniform(-50, 50)) if r.random() < 0.9 else r.choice([NAN, 0, 0x7f800000]))
        so_ = obj(c, 0x20, {0x78: pystub(c, 1, this=True, side=_log('s78'))}, nslots=0x7c // 4)
        e.w32(so_ + 8, blk)
        sobjs.append(so_)
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda emu, k: sobjs[min(k, max(n - 1, 0))] if sobjs else 0)})

    def edx_log(emu, k):
        emu.calllog.append(('e', emu.reg('edx')))
    hook_rec(c, 0x451890, 1, this=True, pop=4, side=edx_log)
    me = rnd(c, 0xc0)
    e.w32(me + 0x4c, r.choice([reftab(c, list(ids)), reftab(c, list(ids)), reftab(c, list(ids)), 0]))
    return [me, rnd(c, 0x10)]


def g6106e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _assert_hook(c)
    hook_rec(c, 0x633654, 0, pop=0, ret=lambda emu, k: emu.reg('eax'))
    flag = r.choice([0, 0, 0, 0, 1, 0x100, 0x1ff, r.getrandbits(32)])
    nanf = _fv(NAN)

    def fv():
        return r.choice([r.uniform(-10, 10), r.uniform(0.1, 5), r.uniform(1, 1000), 0.0, 1.0, -1.0, 2.0, 100.0, nanf]) if r.random() < 0.97 else r.choice([0.0, nanf])
    vals = [fv() for _ in range(6)]
    if r.random() < 0.15:
        vals[1] = vals[0]       # r == l -> division by zero
    if r.random() < 0.15:
        vals[3] = vals[2]       # t == b
    if r.random() < 0.15:
        vals[5] = vals[4]       # f == n
    if (flag & 0xff) == 0:
        hook_rec(c, 0x6107e0, 1, this=True, pop=4, deref={0: 16}, ret=r.getrandbits(32))
    else:
        hook_rec(c, 0x6107e0, 1, this=True, pop=4, nullflag=(0,), ret=r.getrandbits(32))
    return [rnd(c, 0x20)] + [F(v) for v in vals] + [flag]


S(0x5b9050, 'GUESS apply transform to registered objects', 'thiscall', None, ret=None, gen=g5b9050, nan_heap=True, note='batch32142')
S(0x6106e0, 'GUESS build perspective frustum matrix', 'thiscall', None, ret='eax', gen=g6106e0, nan_heap=True, note='batch32142')
