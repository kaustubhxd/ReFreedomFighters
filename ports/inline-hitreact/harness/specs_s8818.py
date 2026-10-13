"""specs_s8818.py - hitreact batch 8818: ConstrainedParticleSystem::CheckCollision3 (0x543a90). PSVECSubtract / d = a + b / vaddscalar /
vaddscalar4 / vscalar and area 81's 0x546fa0 run as exe code. CollideLineBetweenParticles3 0x5440b0 (batch 8817) is patched to a stub
that puts particle 5's pos back to the case's starting position with x + 1 (so pass 2 sees crossings and the order is checked). The face list is an iterator object whose slot 0x4c resets
it and slot 0x64 returns the next of 0-3 face records. Faces are mostly well-formed triangles (signed axis frames, the inverse edge basis
in the rows) with particle 5 crossing them, so most cases take the contact branches; the rest are random."""
import struct
from pilot import S
from wkit import rnd, obj
from dkit import patch_jmp


def _code(c, b):
    a = c.emu.alloc(len(b) + 16, 16)
    c.emu.wbytes(a, b)
    return a


def _iter(c, vals):
    n = len(vals)
    tab = c.emu.alloc(4 * (n + 1), 4)
    for i, v in enumerate(vals + [0]):
        c.emu.w32(tab + 4 * i, v)
    cnt = c.emu.alloc(4, 4)
    start = _code(c, b'\xc7\x05' + struct.pack('<I', cnt) + b'\x00\x00\x00\x00\xc2\x04\x00')
    code = b'\xa1' + struct.pack('<I', cnt) + b'\x3d' + struct.pack('<I', n) + b'\x76\x05\xb8' + struct.pack('<I', n)
    code += b'\x8b\x04\x85' + struct.pack('<I', tab) + b'\xff\x05' + struct.pack('<I', cnt) + b'\xc2\x04\x00'
    return start, _code(c, code)


def _lines_stub(c, buf):
    """thiscall, no arguments: particle 5's pos = the 3 floats at buf (the case's starting position, x + 1)."""
    code = b'\x8b\x41\x0f'                                                                  # mov eax,[ecx+0xf]
    for j in range(3):
        code += b'\x8b\x15' + struct.pack('<I', buf + 4 * j) + b'\x89\x90' + struct.pack('<I', 0x110 + 4 * j)
    return _code(c, code + b'\xc3')


def _frame(r):
    ax = [0, 1, 2]
    r.shuffle(ax)
    out = []
    for a in ax:
        v = [0.0, 0.0, 0.0]
        v[a] = r.choice((-1.0, 1.0))
        out.append(v)
    return out


def _gen(c):
    r = c.rng
    emu = c.emu
    base = emu.alloc(0x34 * 16 + 0x40, 4)
    emu.wbytes(base, bytes(r.getrandbits(8) for _ in range(0x34 * 16 + 0x40)))
    for i in range(16):
        for k in range(3):
            for o in (0, 0xc, 0x18):
                emu.wf32(base + i * 0x34 + o + 4 * k, r.uniform(-100, 100))
            emu.wf32(base + i * 0x34 + 0x24 + 4 * k, r.uniform(-8, 8))
    r5 = base + 0x104
    nf = r.choice((0, 1, 1, 2, 2, 3))
    faces = []
    aimed = False
    for i in range(nf):
        f = rnd(c, 0x80)
        if r.random() < 0.8:
            a1, a2, a3 = _frame(r)
            L1, L2 = r.uniform(20, 200), r.uniform(20, 200)
            V = [r.uniform(-100, 100) for _ in range(3)]
            for k in range(3):
                emu.wf32(f + 0x10 + 0xc * k, a1[k] / L1)
                emu.wf32(f + 0x14 + 0xc * k, a2[k] / L2)
                emu.wf32(f + 0x18 + 0xc * k, a3[k])
                emu.wf32(f + 0x34 + 4 * k, V[k])
            N = a3 if r.random() < 0.7 else [r.uniform(-1, 1) for _ in range(3)]
            for k in range(3):
                emu.wf32(f + 4 + 4 * k, N[k])
            if not aimed or r.random() < 0.3:
                aimed = True
                al, be = r.uniform(-0.1, 0.7), r.uniform(-0.1, 0.7)
                h1, h2 = r.uniform(-3, 30), r.uniform(-3, 30)
                last = [V[k] + a1[k] * L1 * al + a2[k] * L2 * be + a3[k] * h1 for k in range(3)]
                pos = [last[k] - a3[k] * (h1 + h2) + r.uniform(-2, 2) for k in range(3)]
                if r.random() < 0.1:
                    pos = list(last)
                elif r.random() < 0.15:   # crossing from behind (dn > 0), small steps
                    h1 = -r.uniform(0, 0.6)
                    last = [V[k] + a1[k] * L1 * al + a2[k] * L2 * be + a3[k] * h1 for k in range(3)]
                    pos = [last[k] + a3[k] * r.uniform(0, 1.2) for k in range(3)]
                vs = r.choice((5.0, 5.0, 1.5))
                for k in range(3):
                    emu.wf32(r5 + 4 * k, last[k])
                    emu.wf32(r5 + 0xc + 4 * k, pos[k])
                    emu.wf32(r5 + 0x24 + 4 * k, r.uniform(-vs, vs) + (-a3[k] * r.uniform(0, 8)))
        faces.append(f)
    st, nx = _iter(c, faces)
    buf = emu.alloc(12, 4)
    for k in range(3):
        emu.w32(buf + 4 * k, emu.r32(r5 + 0xc + 4 * k))
    emu.wf32(buf, emu.rf32(buf) + 1.0)
    patch_jmp(c, 0x5440b0, _lines_stub(c, buf))
    fl = obj(c, 0x80, {0x4c: st, 0x64: nx})
    holder = rnd(c, 0x40)
    emu.w32(holder + 0x14, fl if r.random() < 0.92 else 0)
    self = rnd(c, 0x80)
    emu.w32(self + 0xf, base)
    emu.w32(self + 0x28, 16)
    emu.w32(self + 0x5d, holder)
    emu.w8(self + 0x50, r.choice((0, 1)))
    emu.mu.ctl_flush_tb()
    return [self]


S(0x543a90, 'CheckCollision3', 'thiscall', ret='al', gen=_gen)
