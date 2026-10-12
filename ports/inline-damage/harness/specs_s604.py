"""specs_s604.py - damage batch 604: ZFFHERO::AdjustHitPoints (PC 0x58b9c0). Patched to stubs: the OSD damage flash
0x5a5be0 and ZGameOSD::SetHealth 0x5e0dd0. Options/scene/message lookups are vtable stubs."""
import struct
from pilot import S
from wkit import rnd, stub, obj, fedge
from dkit import patch_jmp, byte_out_stub


def _gen(c):
    r = c.rng
    emu = c.emu
    patch_jmp(c, 0x5a5be0, stub(c, 1))
    patch_jmp(c, 0x5e0dd0, stub(c, 1))
    emu.wf32(0x6ffa60, r.choice((0.0, 0.0, 0.0, -0.0, 1.0, float('nan'))))
    hero = obj(c, 0x1000, {0x12c: stub(c, 3, skip=(2,), copy=(2, [(0, 'd'), (4, 'd')]))})
    mx = r.choice((100.0, 300.0, 200.0, 0.0, r.uniform(1, 2000), fedge(c)))
    emu.wf32(hero + 0x7fb, mx)
    emu.wf32(hero + 0x7ff, r.choice((mx, mx * 0.5, mx * 0.25, 0.0, -1.0, r.uniform(-50, 2100), fedge(c))))
    emu.w8(hero + 0x9f4, r.getrandbits(1))
    emu.w8(hero + 0x653, r.choice((0, 1)))
    osd = rnd(c, 0x2000)
    emu.w32(osd + 0x1d0f, rnd(c, 0x20))
    emu.w32(hero + 0x852, osd if r.random() < 0.85 or True else 0)
    if r.random() < 0.15:
        emu.w8(hero + 0x653, 0)
        emu.w32(hero + 0x852, 0)
    ctrl = r.getrandbits(32)
    cv = emu.alloc(4, 4)
    emu.w32(cv, ctrl)
    opts = obj(c, 0x20, {0x90: byte_out_stub(c, 2, 1, r.choice((0, 1)))})
    scene = obj(c, 0x20, {0x88: stub(c, 2, skip=(1,), ofills=[(1, 0, cv, 1)])})
    rm = obj(c, 0x200, {0x134: stub(c, 0, ret=opts), 0x138: stub(c, 0, ret=scene),
                        0x4c: stub(c, 1, ret=r.getrandbits(32)),
                        0x114: stub(c, 4, ret=r.getrandbits(32))})
    eng = rnd(c, 0x200)
    emu.w32(eng + 0x9b, rm)
    emu.w32(0x70039c, eng)
    d = r.choice((-30.0, -60.0, -0.0, 0.0, 5.0, -1e-30, -1000.0, 25.0, float('nan'), r.uniform(-200, 50), fedge(c)))
    return [hero, struct.unpack('<I', struct.pack('<f', d))[0], r.choice((0, 0, r.getrandbits(32))),
            r.choice((0, 0, 1, 0x100, r.getrandbits(32)))]


S(0x58b9c0, 'ZFFHERO::AdjustHitPoints', 'thiscall', ret='st0', gen=_gen)
