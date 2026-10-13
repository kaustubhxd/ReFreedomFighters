"""specs_s13008.py - fresh-13 batch 8: 0x63b710 ZOffsetAllocPointerSort<1024>::AllocHi(size). Thiscall, 1 arg, returns
eax. The object is 0x3410 random bytes; top (+0x3408) in -2..12 (sometimes a random negative); each bucket 0..top holds
0..4 nodes taken from distinct random pool slots (this+0x400 + 12*k) or is empty; node addr/size are random, sizes are
small; the request size is either one of the node sizes (exact use-up path) or random small; addr ties occur."""
from pilot import S
from fr13 import rnd, clear_hooks, flush


def _gen(c):
    r = c.rng
    clear_hooks(c)
    me = rnd(c, 0x3410)
    top = r.choice([-1, -2, 0, 1, 3, 7, 12, r.randint(0, 12), -r.randint(1, 1 << 30)])
    c.emu.w32(me + 0x3408, top & 0xffffffff)
    slots = r.sample(range(1024), 60)
    sizes = []
    addrs = [r.getrandbits(32) for _ in range(6)]
    for b in range(max(0, top + 1) if top >= 0 else 0):
        n = r.choice([0, 0, 1, 2, 3, 4])
        head = 0
        for _ in range(n):
            k = slots.pop()
            node = me + 0x400 + 12 * k
            sz = r.randint(1, 64) if r.random() < 0.8 else r.getrandbits(32)
            sizes.append(sz)
            c.emu.w32(node, r.choice(addrs) if r.random() < 0.2 else r.getrandbits(32))
            c.emu.w32(node + 4, sz)
            c.emu.w32(node + 8, head)
            head = node
        c.emu.w32(me + 4 * b, head)
    size = r.choice(sizes) if sizes and r.random() < 0.4 else r.randint(0, 80)
    flush(c)
    return [me, size]


S(0x63b710, 'ZOffsetAllocPointerSort<1024>::AllocHi', 'thiscall', None, ret='eax', gen=_gen,
  note='fresh13 batch13008; bucket lists in the node pool')
