"""specs_s213155.py - batch 213155: integer grid line walk (transliterated frame; octree probes 0x52e320 / 0x531070 hooked), Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def g52dbb0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rb = lambda: r.getrandbits(32)
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)
    bias = [r.choice([0.2, 0.5, 0.8, 0.95])]

    def probe(tag):
        def side(emu, k):
            s2 = emu.reg('ecx')
            mv = emu.arg32(0)
            emu.calllog.append((tag, bytes(emu.rbytes(s2, 0x2d)), bytes(emu.rbytes(mv, 6))))
            # the real probe moves the cell: perturb a few fields of the struct the way it does
            if r.random() < 0.7:
                emu.wbytes(s2 + 0x18, struct.pack('<3H', r.randint(0, 12), r.randint(0, 12), r.randint(0, 12)))
            emu.wbytes(s2 + 0x28, struct.pack('<I', rb()))
            emu.wbytes(s2 + 0x2c, bytes([r.getrandbits(8)]))
        return side
    ret = lambda emu, k: (rb() & ~0xffff) | (r.randint(1, 0xffff) if r.random() < bias[0] else 0)
    hook_rec(c, 0x52e320, 1, pop=4, this='mark', stackmark=(0,), side=probe('p3'), ret=ret)
    hook_rec(c, 0x531070, 1, pop=4, this='mark', stackmark=(0,), side=probe('pn'), ret=ret)
    this = rnd(c, 0x400)
    e.wbytes(this + 0x38, struct.pack('<I', r.choice([3, 4, 5, 6, 8])))
    a = e.alloc(16, 4)
    b = e.alloc(16, 4)
    lim = r.choice([3, 6, 10, 40])

    def rec(base):
        w = [r.randint(0, lim), r.randint(0, lim), r.randint(0, lim)]
        e.wbytes(base, struct.pack('<H', r.choice([0, 1, 2, 5, 0xffff])) + b'\0\0' + struct.pack('<HHH', *w))
    rec(a)
    rec(b)
    if r.random() < 0.3:      # end close to start
        e.wbytes(b + 4, bytes(e.rbytes(a + 4, 6)))
        w = struct.unpack('<3H', bytes(e.rbytes(b + 4, 6)))
        e.wbytes(b + 4, struct.pack('<3H', w[0], w[1], (w[2] + r.choice([-3, -2, 0, 1, 5, 6])) & 0xffff))
    scen = r.random()
    if scen < 0.15:
        # long walk: probes always open, destination ~1000 steps away, tiny z drift
        bias[0] = 1.0
        ax, ay = r.randint(0, 30), r.randint(0, 30)
        az = r.randint(5, 30)
        tot = r.choice([997, 998, 999, 1000, 1001])
        dxv = r.randint(0, tot) * r.choice([-1, 1])
        dyv = (tot - abs(dxv)) * r.choice([-1, 1])
        ax += 1000 if dxv < 0 else 0
        ay += 1000 if dyv < 0 else 0
        e.wbytes(a, struct.pack('<H', 1) + b'\0\0' + struct.pack('<3H', ax, ay, az))
        e.wbytes(b, struct.pack('<H', 1) + b'\0\0' + struct.pack('<3H', (ax + dxv) & 0xffff, (ay + dyv) & 0xffff, az + r.randint(-5, 2)))
    elif scen < 0.55:
        # destination right next to the start
        bias[0] = r.choice([0.8, 0.95, 1.0])
        ax, ay, az = r.randint(2, 20), r.randint(2, 20), r.randint(8, 20)
        mx, my = r.choice([(1, 0), (-1, 0), (0, 1), (0, -1), (0, 0), (1, 1), (2, 0), (0, -2)])
        e.wbytes(a, struct.pack('<H', 1) + b'\0\0' + struct.pack('<3H', ax, ay, az))
        e.wbytes(b, struct.pack('<H', 1) + b'\0\0' + struct.pack('<3H', ax + mx, ay + my, az + r.randint(-7, 7)))
    return [this, a, b, 0]


S(0x52dbb0, 'grid_line_walk', 'thiscall', None, ret='al', gen=g52dbb0, stack_arg_bytes=12)
