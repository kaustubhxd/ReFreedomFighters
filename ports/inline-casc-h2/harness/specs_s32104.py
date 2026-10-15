"""specs_s32104.py - h2 (Sonnet) batch 32104: three tier H functions. Callees/slots are recorders; order pinned with calllog.
Slot 0x20 of 0x657c50 leaves its stack argument for 0x63eab0 (ret 4): stub pop=0, hook pop=4."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _log(tag):
    return lambda emu, k: emu.calllog.append((tag,))


def g5d5510(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    so = sysobj(c)
    for off in (0x6f, 0x73):
        e.wbytes(so + off, r.choice([0, 15, 16, 17, -1 & 0xffffffff, -16 & 0xffffffff, -17 & 0xffffffff, 1000, r.getrandbits(32), 0x7fffffff, 0x80000000]).to_bytes(4, 'little'))
    o = obj(c, 0x20, {0x258: pystub(c, 2, ret=r.getrandbits(32), this=True, deref={0: 2})}, nslots=0x258 // 4 + 1)
    me = rnd(c, 0x60)
    e.w32(me + 0x44, o)
    return [me]


def g657c50(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    q = rnd(c, 0x20)
    z = rnd(c, 0x20)
    so = sysobj(c)
    sl = obj(c, 0x20, {0x20: pystub(c, 1, ret=q, this=True, pop=0, side=_log('a'))}, nslots=0x20 // 4 + 1)
    e.wbytes(so + 0x190f, sl.to_bytes(4, 'little'))
    inner = rnd(c, 0x40)
    e.wbytes(inner + 0x20, r.getrandbits(32).to_bytes(4, 'little'))
    e.wbytes(so + 0x1aa3, inner.to_bytes(4, 'little'))
    hook_rec(c, 0x63eab0, 1, this=True, pop=4, ret=q, side=_log('b'))
    hook_rec(c, 0x658dc0, 1, this=True, pop=4, ret=(z if r.random() < 0.7 else 0), side=_log('c'))
    hook_rec(c, 0x658ff0, 1, this=True, pop=4, side=_log('d'))
    p = rnd(c, 0x80)
    e.w32(p + 0x6c, r.choice([0, 0, 1, r.getrandbits(32)]) if r.random() < 0.2 else r.randrange(1, 1000))
    e.wbytes(p + 0x5a, r.choice([0, 1, 0x1234, 0xffff]).to_bytes(2, 'little') if r.random() < 0.25 else r.randrange(1, 0xffff).to_bytes(2, 'little'))
    return [p, F(r.uniform(-9, 9))]


def g57c870(c):
    clear_hooks(c)
    hook_rec(c, 0x4cbe50, 1, this=True, pop=4)
    return [rnd(c, 0xc0), rnd(c, 0xc0)]


S(0x5d5510, 'GUESS slot 0x258 with two scaled floats', 'thiscall', None, ret='eax', gen=g5d5510, note='batch32104')
S(0x657c50, 'GUESS lookup and apply float via chain of calls', 'stdcall', None, ret=None, gen=g657c50, note='batch32104')
S(0x57c870, 'GUESS copy-assign fields 0x80..0xb3 (variant)', 'thiscall', None, ret='eax', gen=g57c870, note='batch32104')
