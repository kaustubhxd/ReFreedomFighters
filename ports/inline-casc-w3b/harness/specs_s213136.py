"""specs_s213136.py - batch 213136: 3D gradient noise over the permutation / gradient tables, Sonnet-w3b."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g451560(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    f32 = lambda v: struct.unpack('<f', struct.pack('<f', v))[0]
    rdf = lambda a: struct.unpack('<f', bytes(e.rbytes(a, 4)))[0]
    perm = e.alloc(4 * 512 + 16, 4)
    e.wbytes(perm, b''.join(struct.pack('<I', r.randrange(256)) for _ in range(512)))
    grad = e.alloc(4 * 3 * 512 + 16, 4)
    e.wbytes(grad, b''.join(struct.pack('<f', f32(r.choice([0.0, 1.0, -1.0, 0.5, r.uniform(-1, 1), r.uniform(-1, 1)]))) for _ in range(3 * 512)))
    e.w32(0x6ff978, perm)
    e.w32(0x6ff97c, grad)
    flag = 0 if r.random() < 0.05 else 1
    e.wbytes(0x6ff980, bytes([flag]))
    c1 = rdf(0x681380)

    def side(emu, k):
        emu.wbytes(0x6ff980, bytes([1]))
    hook_rec(c, 0x4513e0, 0, pop=0, this=True, side=side)

    def comp():
        t = r.random()
        if t < 0.15:
            return f32(r.choice([0.0, 1.0, -1.0, 0.5, 2.0, 255.0, 256.0, -c1, -c1 - 0.5, 100.25]))
        if t < 0.9:
            return f32(r.uniform(-300, 300))
        return f32(r.choice([-3000.0, 1e6, -1e6, 3e9]))
    p = e.alloc(16, 4)
    e.wbytes(p, struct.pack('<3f', comp(), comp(), comp()))
    return [p]


S(0x451560, 'gradient_noise3', 'thiscall', None, ret='st0', gen=g451560)
