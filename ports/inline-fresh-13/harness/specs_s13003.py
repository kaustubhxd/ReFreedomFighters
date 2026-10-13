"""specs_s13003.py - fresh-13 batch 3: ZDrawArray::CalculateUsedArray for strides 0x34 (0x649950) and 0x10 (0x649f90).
Thiscall, two stack args (out array, unused; ret 8). Inputs: 0..6 blocks (8% of cases 200..255 blocks with n <= 4; 5% no
block at all), null-ended or circular; n = vtbl[+0x28]() from 0..40 (logged stub); each block's free list is a random
chain of distinct indices < n (some empty). 256 or more blocks are not generated: the exe then wraps the block counter and
reads stack bytes it never cleared (the hook path at 0x7003b0 is not exercised)."""
from pilot import S
from fr13 import Log, logstub, vobj, rnd, clear_hooks, flush, crt_memset


def _gen(c, stride):
    r = c.rng
    clear_hooks(c)
    log = Log(c, cap=8)
    crt_memset(c)
    k = r.random()
    if k < 0.05:
        nb, n = 0, r.randint(0, 40)
    elif k < 0.13:
        nb, n = r.randint(200, 255), r.randint(0, 4)
    else:
        nb, n = r.randint(1, 6), r.choice([0, 1, 2, 3, r.randint(0, 40), r.randint(0, 40)])
    me = vobj(c, 0x40, {0x28: logstub(c, log, 0, 1, ret=n)})
    blocks = [rnd(c, 0x10 + stride * max(n, 1)) for _ in range(nb)]
    for i, b in enumerate(blocks):
        nxt = blocks[i + 1] if i + 1 < nb else (blocks[0] if r.random() < 0.5 else 0)
        c.emu.w32(b + 8, nxt)
        free = r.sample(range(n), r.randint(0, n)) if n else []
        chain = free + [0xffff]
        c.emu.w16(b + 2, chain[0]) if hasattr(c.emu, 'w16') else c.emu.wbytes(b + 2, chain[0].to_bytes(2, 'little'))
        for a, nx in zip(chain, chain[1:]):
            c.emu.wbytes(b + 0x10 + a * stride, nx.to_bytes(2, 'little'))
    c.emu.w32(me + 8, blocks[0] if blocks else 0)
    out = rnd(c, 4 * max(1, nb * n) + 16)
    flush(c)
    return [me, out, r.getrandbits(32)]


S(0x649950, 'ZDrawArray<ZGateViewEntry>::CalculateUsedArray', 'thiscall', None, ret=None, gen=lambda c: _gen(c, 0x34),
  note='fresh13 batch13003; stride 0x34; vtbl+0x28 logged')
S(0x649f90, 'ZDrawArray<ZTextureDrawEntry>::CalculateUsedArray', 'thiscall', None, ret=None, gen=lambda c: _gen(c, 0x10),
  note='fresh13 batch13003; stride 0x10; vtbl+0x28 logged')
