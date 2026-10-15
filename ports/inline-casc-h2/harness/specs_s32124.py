"""specs_s32124.py - h2 (Sonnet) batch 32124: 0x43ed70 and 0x63eca0. Slots/callees are recorders; the chunk list is built in the spec."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _log(tag):
    return lambda emu, k: emu.calllog.append((tag,))


def g43ed70(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    # the real /GS check keeps EAX (the function returns the object): the hook must not clear it
    hook_rec(c, 0x633654, 0, pop=0, ret=lambda emu, k: emu.reg('eax'), side=_log('gs'))
    hook_rec(c, 0x4dc630, 2, this=True, pop=8, side=_log('c'))
    hook_rec(c, 0x4690b0, 0, this=True, pop=0, side=_log('e'))
    rr = obj(c, 0x20, {0x220: pystub(c, 3, this=True, deref={0: 3}, side=_log('a')), 0x224: pystub(c, 1, this=True, side=_log('b'))}, nslots=0x224 // 4 + 1)
    e.w32(rr + 8, rnd(c, 0x20))
    me = obj(c, 0x300, {0x294: pystub(c, 4, ret=rr, this=True, side=_log('n'))}, nslots=0x294 // 4 + 1)
    v = rnd(c, 0x10)
    for i in range(3):
        e.wbytes(v + 4 * i, struct.pack('<f', r.uniform(-9, 9)))
    return [me, v, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


def g63eca0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    # build up to 3 chunks: [count][?][next][?][ptr0 ptr1 ...] with items at +0x10
    nchunks = r.choice([1, 1, 2, 3])
    chunks = []
    for k in range(nchunks):
        cnt = r.randrange(1, 5)
        ch = rnd(c, 0x10 + 4 * cnt + 8)
        e.w32(ch, cnt)
        for j in range(cnt):
            o = rnd(c, 0x50)
            e.w32(ch + 0x10 + 4 * j, o)
        chunks.append((ch, cnt))
    for k in range(nchunks):
        e.w32(chunks[k][0] + 8, chunks[k + 1][0] if k + 1 < nchunks else 0)
    first, cnt0 = chunks[0]
    idx = r.randrange(0, cnt0)
    it = rnd(c, 0x20)
    e.w32(it, (first + 0x10 + 4 * idx) if r.random() > 0.1 else 0)
    e.w32(it + 4, idx)
    e.w32(it + 8, first)
    vt = e.alloc(0x40, 4)
    e.w32(vt + 0xc, pystub(c, 1, ret=it, this=True, nullflag=(0,), side=_log('it')))
    me = rnd(c, 0x1e0)
    e.wbytes(me + 0x1c8, vt.to_bytes(4, 'little'))
    return [me, rnd(c, 0x80)]


S(0x43ed70, 'GUESS create object, set position through slots', 'thiscall', None, ret='eax', gen=g43ed70, nan_heap=True, note='batch32124')
S(0x63eca0, 'GUESS collect values from a chunked pointer list', 'thiscall', None, ret='eax', gen=g63eca0, note='batch32124')
