"""specs_s38001.py - cascade s8 batch 38001: 0x5318a0 (chain shortening over 0x15-byte nodes). 41 nodes: +0xe next link (always a higher index, or 0), +0x14 flag byte
(bit 0 set about 20%); lock table at this+32*i+0x9e maps i to an index >= i, so the outer loop always ends. 0x52dbb0 hooked (random accept)."""
import struct
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec

NN = 40


def _g5318a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))
    nodes = e.alloc((NN + 1) * 0x15, 4)
    e.wbytes(nodes, bytes(r.getrandbits(8) for _ in range((NN + 1) * 0x15)))
    pz = r.choice([0.0, 0.03, 0.1, 0.25])
    pf = r.choice([0.0, 0.0, 0.05, 0.2])
    for i in range(NN + 1):
        nxt = 0 if (i == NN or r.random() < pz) else r.randrange(i + 1, min(NN, i + 3) + 1) if r.random() < 0.7 else r.randrange(i + 1, NN + 1)
        e.wbytes(nodes + i * 0x15 + 0xe, struct.pack('<H', nxt))
        fl = r.getrandbits(8)
        fl = (fl | 1) if r.random() < pf else (fl & ~1)
        e.wbytes(nodes + i * 0x15 + 0x14, bytes([fl]))
    me = rnd(c, 0xa0 + 32 * (NN + 1) + 8)
    e.w32(me + 0x98, nodes)
    for i in range(NN + 1):
        e.wbytes(me + i * 32 + 0x9e, struct.pack('<H', r.randrange(i, NN + 1)))
    pa = r.choice([0.5, 0.85, 0.97, 1.0])
    hook_rec(c, 0x52dbb0, 3, this=True, pop=12, ret=lambda em, k: 1 if r.random() < pa else 0)
    start = r.choice([0, r.randrange(1, NN + 1), r.randrange(1, NN + 1), r.randrange(1, 6)])
    return [me, start | (r.getrandbits(16) << 16 if r.random() < 0.3 else 0)]


S(0x5318a0, 'GUESS chain shortening', 'thiscall', None, ret=None, gen=_g5318a0, note='batch38001')
