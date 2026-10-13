"""specs_s8816.py - hitreact batch 8816: PullTriangleCyl2 (0x547080). vaddscalar / vscalar3 / vnorm 0x44c840 / vaddscalar4 / vscalar run
as exe code; PlayBodySound 0x546980 is patched to a recording stub (fastcall pos, bool; vol, id, 0: records the position contents, the
volume bits and the id); the render manager's slot 0x58 returns an object whose geom (+8) has a per-case +0x3c."""
from pilot import S, F
from wkit import rnd, obj, fedge
from dkit import patch_jmp
from hkit import rec_stub, fvec
import struct


def _sound_stub(c):
    rec = c.emu.alloc(32, 4)
    code = b''
    for j in range(3):   # [ecx + 4j]
        code += b'\x8b\x41' + bytes([4 * j]) + b'\xa3' + struct.pack('<I', rec + 4 * j)
    code += b'\x88\x15' + struct.pack('<I', rec + 12)                        # mov [rec+12], dl
    code += b'\x8b\x44\x24\x04\xa3' + struct.pack('<I', rec + 16)            # vol
    code += b'\x8b\x44\x24\x08\xa3' + struct.pack('<I', rec + 20)            # id
    code += b'\xff\x05' + struct.pack('<I', rec + 24) + b'\xc2\x0c\x00'
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def _gen(c):
    r = c.rng
    emu = c.emu
    patch_jmp(c, 0x546980, _sound_stub(c))
    geom = rnd(c, 0x80)
    emu.w32(geom + 0x3c, r.choice((0, 0x40000, 0x40000000, 0x40040000, r.getrandbits(32), 0x1)))
    ob = rnd(c, 0x40)
    emu.w32(ob + 8, geom)
    rm = obj(c, 0x100, {0x58: rec_stub(c, 1, ret=ob)})
    eng = rnd(c, 0x100)
    emu.w32(eng + 0x9b, rm)
    emu.w32(0x70039c, eng)
    n = [r.uniform(-1, 1) for _ in range(3)]
    if r.random() < 0.5:
        L = sum(x * x for x in n) ** 0.5 or 1.0
        n = [x / L for x in n]
    t = r.choice((0.0, 1.0, 0.5, r.random(), r.random(), fedge(c)))
    depth = r.choice((r.uniform(0, 20), 0.0, fedge(c)))
    sau = fvec(c, n + [t, depth])
    big = r.random() < 0.5   # displacements large enough for the friction branch / the sound
    V = lambda: [r.uniform(-30, 30) if big else r.uniform(-2, 2) for _ in range(3)]
    PA, PB, QA, QB = fvec(c, V()), fvec(c, V()), fvec(c, V()), fvec(c, V())
    if r.random() < 0.15:   # s = n . v exactly 0: unit normal along x, displacements with x = 0
        emu.wf32(sau, 1.0); emu.wf32(sau + 4, 0.0); emu.wf32(sau + 8, 0.0)
        for q in (QA, QB):
            emu.wf32(q, 0.0)
            emu.wf32(q + 4, r.uniform(-0.6, 0.6)); emu.wf32(q + 8, r.uniform(-0.6, 0.6))
    w = lambda: r.choice((1.0, 0.5, 0.0, 1e-4, r.uniform(0, 2), fedge(c)))
    emu.mu.ctl_flush_tb()
    return [rnd(c, 16), PA, F(r.random()), F(r.random()), F(r.random()), PB, F(w()), F(w()), QA, QB, sau,
            r.choice((0, 1, 0x100)), r.getrandbits(32)]


S(0x547080, 'PullTriangleCyl2', 'fastcall', ret=None, gen=_gen)
