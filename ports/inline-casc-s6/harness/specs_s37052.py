"""specs_s37052.py - cascade s6 batch 37052 (0x6378c0, fastcall(c, stride, x, y, src, a14, out)). 0x636de0 hooked (ecx recorded, 5 stack args); shift global 0x6f5a90 random 0..40;
src is a random-filled pixel image, out random-filled so the bit merge is visible."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _g6378c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))
    hook_rec(c, 0x636de0, 5, this=True, pop=0x14, ret=lambda em, k: r.getrandbits(32))
    e.w32(0x6f5a90, r.choice([0, 1, 4, 8, 16, 24, 31, 33, 40]))
    stride = r.choice([4, 5, 8, 12])
    x = r.choice([0, 1, 4])
    y = r.choice([0, 1, 2])
    src = rnd(c, 4 * (y * stride + x + 4 * stride + 4) + 16)
    out = rnd(c, 0x20)
    return [r.getrandbits(32), stride, x, y, src, r.getrandbits(32), out]


S(0x6378c0, 'GUESS encode 4x4 block to 4-bit values', 'fastcall', None, ret='eax', gen=_g6378c0, note='batch37052')
