"""specs_s603.py - damage batch 603: ZFFHERO::OnProjectileHit (PC 0x5936b0).
Real exe code: GetDamageMultForBone, the point distance 0x4e0870. Patched to heap stubs at their entries (both builds):
ForwardEventToFollowers 0x591820, AdjustHitPoints 0x58b9c0, GetInventoryInfo 0x5af0f0, ZIKLNKOBJ::PlaySound 0x466f60,
ZGameOSD::PlaySound 0x59a5e0. Everything reached through a vtable is a heap stub."""
import struct
from pilot import S
from wkit import rnd, stub, obj, fedge, b
from dkit import coll_stub, seq_rec_stub, patch_jmp


def _f(c, a, v):
    c.emu.wf32(a, v)


def _gen(c):
    r = c.rng
    emu = c.emu
    zone = r.choice([1, 1, 1, 2, 3, 2, 3, 0, 4, 5, 6, 7, 8, 9])
    # exe callees patched to stubs
    patch_jmp(c, 0x591820, stub(c, 2, skip=(1,), copy=(1, [(0, 'd'), (4, 'd')])))
    hpv = emu.alloc(4, 4)
    _f(c, hpv, r.choice((50.0, 1.0, 0.0, -5.0, float('nan'), r.uniform(-100, 300))))
    patch_jmp(c, 0x58b9c0, stub(c, 3, fld=hpv))
    info = rnd(c, 0x20)
    emu.w32(info + 0x10, r.choice((8, 8, 1, 2)))
    patch_jmp(c, 0x5af0f0, stub(c, 1, ret=info if r.random() < 0.8 else 0))
    patch_jmp(c, 0x466f60, stub(c, 1))
    patch_jmp(c, 0x59a5e0, stub(c, 1))
    emu.w32(0x7003b0, stub(c, 0, cdecl=True))
    emu.wf32(0x6ffa60, r.choice((0.0, 0.0, -0.0, 1.0, float('nan'))))
    # logger
    o2 = obj(c, 0x10, {0x2c: stub(c, 2, cdecl=True)})
    emu.w32(0x700390, obj(c, 0x10, {0x20: stub(c, 2, ret=o2)}))
    # teams
    t_h = rnd(c, 8)
    t_s = rnd(c, 8)
    if r.random() < 0.2:
        emu.w32(t_s + 4, struct.unpack('<I', c.emu.rbytes(t_h + 4, 4))[0])
    # shooter
    sp = emu.alloc(16, 4)
    for i in range(3):
        _f(c, sp + 4 * i, r.uniform(-3000, 3000))
    shooter = obj(c, 0x1000, {0x1e0: stub(c, 1, ret=b(c, 0.3)),
                              0x84: stub(c, 1, skip=(0,), ofills=[(0, 0, sp, 3)])})
    emu.w32(shooter + 0x54, t_s)
    ci = rnd(c, 0x40)
    emu.w32(ci + 0x23, r.choice((0x2003e8, 0x2007f9)))
    emu.w32(shooter + 0xc, ci)
    # hero
    hp_pos = emu.alloc(16, 4)
    for i in range(3):
        _f(c, hp_pos + 4 * i, r.uniform(-3000, 3000))
    anim = rnd(c, 0x10)
    hero = obj(c, 0x1000, {
        0x388: coll_stub(c, zone, r.getrandbits(1)),
        0x594: stub(c, 1),
        0x1e0: stub(c, 1, ret=b(c, 0.3)),
        0x84: stub(c, 1, skip=(0,), ofills=[(0, 0, hp_pos, 3)]),
        0x5d4: stub(c, 3, skip=(0,), copy=(0, [(0, 'b'), (1, 'b')]), ret=anim),
        0x4d8: stub(c, 1),
        0x224: stub(c, 4),
        0x5bc: stub(c, 3),
    })
    emu.w32(hero + 0x54, t_h)
    emu.w32(hero + 0x417, r.getrandbits(32) & ~(0x40000 if r.random() < 0.9 else 0))
    emu.w32(hero + 0x7f7, r.choice((0, 0, 10, 50, r.randrange(-5, 100))) & 0xffffffff)
    _f(c, hero + 0x7ff, r.choice((100.0, 30.0, 0.5, r.uniform(-10, 300))))
    for off in range(0x3ea, 0x412, 4):
        _f(c, hero + off, r.choice((1.0, 1.0, 5.0, fedge(c))))
    emu.w32(hero + 0x1e6, r.choice((0, 1234)))
    osd = rnd(c, 0x100)
    emu.w8(osd + 0xe1, r.choice((0, 0, 1)))
    emu.w32(hero + 0x852, osd if r.random() < 0.8 else 0)
    emu.w8(hero + 0x9e7, r.getrandbits(1))
    # weapon / template
    calc = emu.alloc(4, 4)
    _f(c, calc, r.choice((20.0, 34.7, 0.0, -3.5, 1e10, fedge(c), r.uniform(0, 120))))
    tmpl = obj(c, 0x40, {0x35c: stub(c, 2, fld=calc)})
    w = obj(c, 0x100, {0x350: stub(c, 0, ret=tmpl if r.random() < 0.95 else 0), 0x2e8: stub(c, 0, ret=r.getrandbits(32))})
    # engine and render manager
    rv = r.random()
    eng = obj(c, 0x1c00, {0x1c0: stub(c, 2, fldv=rv)})
    emu.w32(eng + 0x40, r.choice((r.randrange(0, 1 << 20), r.randrange(0, 1 << 14), 0, 0x7fffff00)))
    emu.w32(eng + 0x1b5d, r.choice((1, 0, 0)))
    emu.w32(hero + 0x694, (struct.unpack('<I', emu.rbytes(eng + 0x40, 4))[0] - r.choice((0, 0x100, 0x200, 0x201, 5000))) & 0xffffffff)
    now = struct.unpack('<i', emu.rbytes(eng + 0x40, 4))[0]
    _f(c, hero + 0x94a, r.choice((0.0, r.uniform(0, 1000), fedge(c), (now - 0x133) / 1024.0, (now - 0x134) / 1024.0)))
    k = r.random()
    shooter_r = 0 if k < 0.05 else (hero if k < 0.1 else shooter)
    rm = obj(c, 0x80, {0x58: seq_rec_stub(c, 1, [shooter_r, w if r.random() < 0.95 else 0]),
                       0x4c: stub(c, 1, ret=r.getrandbits(32))})
    emu.w32(eng + 0x9b, rm)
    emu.w32(0x70039c, eng)
    proj = rnd(c, 0x40)
    for off in (0xc, 0x10, 0x14, 0x28, 0x2c, 0x30):
        _f(c, proj + off, r.uniform(-3000, 3000))
    hit = rnd(c, 0x20)
    emu.w32(hit, proj)
    return [hero, hit]


S(0x5936b0, 'ZFFHERO::OnProjectileHit', 'thiscall', ret=None, gen=_gen)
