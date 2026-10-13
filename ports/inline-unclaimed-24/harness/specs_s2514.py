"""specs_s2514.py - decomp area 24, batch 2514.
0x60b6f0 (GUESS renderer per-frame state setup + per-element pass): thiscall, no args, plain ret. Object layout: +0x94 embedded object
(slot 0x18 returns a table (reftab fake: slots 0x4c begin / 0x64 next over random heap elements), slot 0x14 returns the start index);
slots 0xd8, 0xdc (ints), 0x134 (4 args, pops 16); +0x1377 device object (stdcall slots 0x94 SetTransform (matrix content recorded),
0xc8 SetRenderState); [0x724a00] device (slots 0xc8, 0xf4, 0xfc). The exe's 0x60ff30 / 0x60feb0 run as code over random state caches.
Globals 0x724848/0x724a48, 0x724928, 0x72492c, 0x724934, 0x72493c, 0x724a08 are random or equal to the compared constant."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, pystub, reftab, stub_memset


def _gen(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    sysobj(c)
    stub_memset(c)
    dev = obj(c, 0x20, {0xc8: pystub(c, 3), 0xf4: pystub(c, 3), 0xfc: pystub(c, 4)})
    e.w32(0x724a00, dev)
    dev2 = obj(c, 0x20, {0x94: pystub(c, 3, deref={2: 16}), 0xc8: pystub(c, 3)})
    elems = []
    for _ in range(r.choice([0, 1, 2, 4, 6])):
        el = rnd(c, 0x400)
        k = r.random()
        mask = 0 if k < 0.15 else ((1 << r.randint(0, 7)) | (r.getrandbits(24) << 8 if r.random() < 0.5 else 0))
        e.wbytes(el + 0x1d9, struct.pack('<I', mask & 0xffffffff))
        elems.append(el)
    tbl = reftab(c, elems)
    emb_vt = e.alloc(0x40, 4)
    start = r.choice([0, 1, 49, r.randint(0, 49), r.randint(0, 60)])
    e.w32(emb_vt + 0x18, pystub(c, 0, this=True, ret=(tbl if r.random() < 0.93 else 0)))
    e.w32(emb_vt + 0x14, pystub(c, 0, this=True, ret=start))
    me = rnd(c, 0x1400)
    vt = e.alloc(0x200, 4)
    e.w32(vt + 0xd8, pystub(c, 0, this=True, ret=r.choice([0, 640, 800, r.getrandbits(32)])))
    e.w32(vt + 0xdc, pystub(c, 0, this=True, ret=r.choice([0, 480, 600, r.getrandbits(32)])))
    e.w32(vt + 0x134, pystub(c, 4, this=True))
    e.w32(me, vt)
    e.w32(me + 0x94, emb_vt)
    e.wbytes(me + 0x1377, struct.pack('<I', dev2))
    tex = r.getrandbits(32)
    e.w32(0x724a48, tex)
    e.w32(0x724848, tex if r.random() < 0.5 else r.getrandbits(32))
    for a, v in ((0x724928, 5), (0x72492c, 6), (0x724934, 1), (0x72493c, 0)):
        e.w32(a, v if r.random() < 0.5 else r.getrandbits(3))
    e.w32(0x724a08, r.choice([0, 1, 2, 3]))
    for base in (0x724868, 0x724888, 0x7248a8, 0x7248c8, 0x7248e8, 0x724908):
        for i in range(2):
            e.w32(base + 4 * i, r.choice([0, 1, 2, 3]))
    return [me]


S(0x60b6f0, 'GUESS renderer per-frame state setup', 'thiscall', None, ret=None, gen=_gen, note='batch2514')
