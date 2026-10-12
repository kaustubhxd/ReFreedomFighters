"""specs_s2428.py - decomp area 24, batch 2428: five short functions.
0x61c630 (GUESS owner): cdecl, plain ret: the dword at (first argument)+0x5c = second argument.
0x4f45f0 ZLINEOBJ::GetWidth() const: float of the signed dword at +0xb0 on st0 (thiscall).
0x48f970 ZTimeUpdateList::Find(unsigned int): walk from the dword at +0xa04 through the next pointers at +0x10; the
node whose first dword equals the key is returned, else 0 (thiscall, ret 4). Lists are 0..6 nodes, acyclic.
0x4cf570 LINKREFTAB::RunToRefPtr(RefRun*): 0 when the first dword of the run is 0, else that value plus
(2 - the dword at this+0x18)*4 (thiscall, ret 4). Only values are computed; nothing is dereferenced.
0x65f1b0 ZGeometryDecal::Init(): zeroes the dword at +0xcc and the dword at +0x2d0+0x3400; fills 127 words at +0x2d0
with stride 0x68 (values 1..127), then 0xffff at the next slot (thiscall, plain ret). The object is 0x7000 bytes."""
from pilot import S
from recruits_util import rnd, clear_hooks


def _store(c):
    clear_hooks(c)
    r = c.rng
    return [rnd(c, 0x80), r.getrandbits(32)]


def _width(c):
    clear_hooks(c)
    o = rnd(c, 0x100)
    return [o]


def _find(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    self_ = rnd(c, 0x40)
    n = r.randint(0, 6)
    keys = []
    nodes = []
    for _ in range(n):
        nd = rnd(c, 0x20)
        k = r.choice([r.randint(0, 5), r.getrandbits(32)])
        e.w32(nd, k)
        keys.append(k)
        nodes.append(nd)
    for i, nd in enumerate(nodes):
        e.w32(nd + 0x10, nodes[i + 1] if i + 1 < n else 0)
    e.w32(self_ + 0xa04, nodes[0] if nodes else 0)
    key = r.choice(keys) if keys and r.random() < 0.6 else r.randint(0, 5)
    return [self_, key]


def _runref(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    self_ = rnd(c, 0x40)
    e.w32(self_ + 0x18, r.randint(0, 4))
    run = rnd(c, 0x20)
    e.w32(run, r.choice([0, r.randint(1, 1 << 20), r.getrandbits(32)]))
    return [self_, run]


def _decal(c):
    clear_hooks(c)
    return [rnd(c, 0x7000)]


S(0x61c630, 'GUESS: cdecl store at +0x5c (0x61c630)', 'cdecl', None, ret=None, gen=_store, note='batch2428')
S(0x4f45f0, 'ZLINEOBJ::GetWidth', 'thiscall', None, ret='st0', gen=_width, note='batch2428')
S(0x48f970, 'ZTimeUpdateList::Find', 'thiscall', None, ret='eax', gen=_find, note='batch2428')
S(0x4cf570, 'LINKREFTAB::RunToRefPtr', 'thiscall', None, ret='eax', gen=_runref, note='batch2428')
S(0x65f1b0, 'ZGeometryDecal::Init', 'thiscall', None, ret=None, gen=_decal, note='batch2428')
