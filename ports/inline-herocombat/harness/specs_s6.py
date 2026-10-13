"""specs_s6.py - inline session batch 6 (Haiku, night): 0x466c70, 0x4ccb40, 0x4cf530, 0x59d530, 0x5853a0."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _k(c):
    return c.rng.choice([2, 2, 0, 1, 3, -1, c.rng.getrandbits(32)])


# 0x466c70 stdcall: (u32* out, int k)
S(0x466c70, 'resultOfK (unknown) stdcall', 'stdcall', None, ret='eax',
  gen=lambda c: [_rnd(c, 16), _k(c) & 0xffffffff], note='batch6; result written to out, k == 2 selects the vtable form')


# 0x4ccb40 thiscall: (this, n, m)
def _ctor2(c):
    o = _rnd(c, 0x30)
    pick = lambda: c.rng.choice([-5, -1, 0, 1, 2, 3, 7, 100, c.rng.randint(-2**31, 2**31 - 1)])
    return [o, pick() & 0xffffffff, pick() & 0xffffffff]


S(0x4ccb40, 'initTable2 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_ctor2,
  note='batch6; vtable 0x6958cc, rows = m + 2')


# 0x4cf530 thiscall: (this, u32* p). Node chains of 0..3 nodes, each node's first dword is the next pointer.
def _pool(c):
    e, r = c.emu, c.rng
    self_ = _rnd(c, 0x30)
    e.w32(self_ + 0x10, r.randint(0, 40))
    e.w32(self_ + 0x18, r.randint(0, 6))
    k = r.randint(0, 3)
    nodes = [_rnd(c, 0x10) for _ in range(k)]
    for i, n in enumerate(nodes):
        e.w32(n, nodes[i + 1] if i + 1 < k else 0)
    p = e.alloc(8, 4)
    e.w32(p, nodes[0] if nodes else 0)
    e.w32(p + 4, r.randint(-3, 40) & 0xffffffff)
    return [self_, p]


S(0x4cf530, 'pooledStep (unknown) thiscall', 'thiscall', None, ret='eax', gen=_pool,
  note='batch6; negative count path walks the node chain')


# 0x59d530 fastcall: (src, end, dst). Blocks of 0x40 bytes; end - src is a multiple of 0x40; dst may be NULL.
def _blocks(c):
    e, r = c.emu, c.rng
    n = r.randint(0, 4) * 0x40
    src = e.alloc(max(n, 0x40), 16)
    e.wbytes(src, bytes(r.getrandbits(8) for _ in range(max(n, 0x40))))
    dst = 0 if r.random() < 0.1 else e.alloc(0x100, 16)
    if dst:
        e.wbytes(dst, bytes(r.getrandbits(8) for _ in range(0x100)))
    return [src, src + n, dst]


S(0x59d530, 'copyBlocks64 (unknown) fastcall', 'fastcall', None, ret=None, gen=_blocks,
  note='batch6; disjoint buffers only (overlap not generated)')


# 0x5853a0 fastcall: (src, end, dst, unused). Records of 0x48 bytes; end - src is a multiple of 0x48.
def _recs(c):
    e, r = c.emu, c.rng
    n = r.randint(0, 3) * 0x48
    src = e.alloc(max(n, 0x48), 16)
    e.wbytes(src, bytes(r.getrandbits(8) for _ in range(max(n, 0x48))))
    dst = 0 if r.random() < 0.1 else e.alloc(0x180, 16)
    if dst:
        e.wbytes(dst, bytes(r.getrandbits(8) for _ in range(0x180)))
    return [src, src + n, dst, r.getrandbits(32)]


S(0x5853a0, 'copyRecords48 (unknown) fastcall', 'fastcall', None, ret=None, gen=_recs,
  note='batch6; disjoint buffers only (overlap not generated)')
