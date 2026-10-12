"""specs_s609.py - damage batch 609: ZFFActor::OnDamageInfo (PC 0x5a1030). Real: GetDamageMultForBone, createmat
(0x4de040). Patched to stubs: HitRagdoll 0x466c10, GetHitAimHeaderFromCollision 0x59fd30 (verified separately in 608),
ZFFActor::IsDead 0x5a0ad0, KillAllSounds 0x466ce0, ZGameOSD::PlaySound 0x59a5e0. Debug floats No_Damage (0x7142ec)
and No_DamageFriendly (0x7142f0) are varied."""
import struct
from pilot import S
from wkit import rnd, stub, obj, fedge, b
from dkit import coll_stub, seq_rec_stub, patch_jmp

MATCOPY = [(o, 'd') for o in range(0, 0x24, 4)]


def _gen(c):
    r = c.rng
    emu = c.emu
    typ = r.choice((0, 0, 0, 1, 1, 2, 3, 3, 4, 5, 6))
    zone = r.choice((1, 1, 2, 3, 2, 0, 4, 5, 6, 7, 8, 9, 12))
    patch_jmp(c, 0x466c10, stub(c, 3))
    patch_jmp(c, 0x59fd30, stub(c, 1, skip=(0,), copy=(0, [(0, 'b'), (1, 'b')]), ret=r.getrandbits(32)))
    patch_jmp(c, 0x5a0ad0, stub(c, 0, ret=b(c, 0.7)))
    patch_jmp(c, 0x466ce0, stub(c, 0))
    patch_jmp(c, 0x59a5e0, stub(c, 1))
    emu.w32(0x7003b0, stub(c, 0, cdecl=True))
    emu.wf32(0x7142ec, r.choice((0.0,) * 12 + (1.0, float('nan'))))
    emu.wf32(0x7142f0, r.choice((0.0,) * 6 + (1.0,)))
    emu.w16(0x7142dc, r.getrandbits(16)) if hasattr(emu, 'w16') else emu.wbytes(0x7142dc, struct.pack('<H', r.getrandbits(16)))
    o2 = obj(c, 0x10, {0x30: stub(c, 2, cdecl=True)})
    emu.w32(0x700390, obj(c, 0x10, {0x20: stub(c, 2, ret=o2)}))
    mpos = emu.alloc(0x40, 4)
    for i in range(12):
        emu.wf32(mpos + 4 * i, r.uniform(-500, 500))
    hdr = rnd(c, 0x80)
    emu.w32(hdr + 0x60, r.randrange(0, 60))
    emu.w32(hdr + 0x64, r.randrange(0, 120))
    actor = obj(c, 0xa00, {
        0x588: stub(c, 0, ret=r.choice((0, 0, 1))),
        0x354: stub(c, 2, ret=b(c, 0.4)),
        0x3f4: stub(c, 1),
        0x2b4: stub(c, 1, ret=r.randrange(0, 40)),
        0x390: stub(c, 3, skip=(1, 2), ofills=[(1, 0, mpos, 9), (2, 0, mpos + 0x24, 3)]),
        0x98: stub(c, 2, skip=(0, 1), copy=(1, [(0, 'd'), (4, 'd'), (8, 'd')])),
        0x660: stub(c, 0, ret=r.getrandbits(32)),
        0x388: coll_stub(c, zone, r.getrandbits(1)),
        0x21c: stub(c, 1, ret=hdr if r.random() < 0.7 else 0),
        0x57c: stub(c, 2, skip=(0, 1), ofills=[(0, 0, mpos, 9), (1, 0, mpos + 0x24, 3)]),
        0x370: stub(c, 2, skip=(0, 1), copy=(0, MATCOPY)),
        0x37c: stub(c, 7, skip=(3, 4), ret=b(c, 0.5)),
        0x598: stub(c, 1, ret=r.getrandbits(32)),
        0x128: stub(c, 3, skip=(1,), copy=(1, [(o, 'd') for o in range(0, 0x2c, 4)])),
        0x674: stub(c, 0, ret=r.choice((0, 1, 2, 0xffffffff))),
        0x6f0: stub(c, 1),
    })
    team = rnd(c, 8)
    if r.random() < 0.5:
        emu.w32(team + 4, 0)
    emu.w32(actor + 0x54, team)
    emu.wbytes(actor + 0x7a0, struct.pack('<h', r.choice((0, 0, 50, -1))))
    emu.w32(actor + 0x7a6, r.getrandbits(32) & ~(4 if r.random() < 0.7 else 0))
    emu.w32(actor + 0x936, rnd(c, 0x20))
    emu.w32(actor + 0x91c, r.choice((0, 0, 0, 1)))
    emu.w8(actor + 0x13a, r.getrandbits(1))
    for off in range(0x3ea, 0x412, 4):
        emu.wf32(actor + off, r.choice((1.0, 1.0, 5.0, fedge(c))))
    p = rnd(c, 0x900)
    osd = rnd(c, 0x100)
    emu.w8(osd + 0xe1, r.choice((0, 1)))
    emu.w32(p + 0x852, osd if r.random() < 0.8 else 0)
    emu.w32(actor + 0x92e, p if r.random() < 0.8 else 0)
    fxci = rnd(c, 0x40)
    emu.w32(fxci + 0x23, r.getrandbits(32) | (0x100000 if r.random() < 0.8 else 0))
    fx = obj(c, 0x200, {0x1bc: stub(c, 7, skip=(1, 2), copy=(2, [(0, 'd'), (4, 'd'), (8, 'd')])), 0x1e0: stub(c, 1, ret=b(c, 0.5))})
    emu.w32(fx + 0xc, fxci)
    room = obj(c, 0x40, {0x94: stub(c, 2, skip=(0, 1)), 0x1e0: stub(c, 1, ret=b(c, 0.5))})
    att = obj(c, 0x100, {0x1e0: stub(c, 1, ret=b(c, 0.5))})
    tmpl = rnd(c, 0x20)
    eng = obj(c, 0x1c00, {0x1c0: stub(c, 2, fldv=r.random())})
    emu.w32(eng + 0x1b5d, r.choice((1, 0, 0)))
    # render-manager handle lookups in call order: owner check, [effect, room], [head-zone attacker]
    rets = [att if r.random() < 0.85 else 0, fx if r.random() < 0.9 else 0, room if r.random() < 0.8 else 0,
            att if r.random() < 0.9 else 0]
    rm = obj(c, 0x200, {0x58: seq_rec_stub(c, 1, rets), 0x160: stub(c, 1, ret=tmpl if r.random() < 0.9 else 0)})
    emu.w32(eng + 0x9b, rm)
    emu.w32(0x70039c, eng)
    info = rnd(c, 0x30)
    emu.w32(info + 4, r.choice((0, 1)))
    emu.w32(info + 8, typ)
    for off in range(0x10, 0x28, 4):
        emu.wf32(info + off, r.uniform(-1, 1) if off >= 0x1c else r.uniform(-3000, 3000))
    emu.wf32(info + 0x28, r.choice((0.0, 35.0, 60.0, 100.0, 1e10, -3.0, r.uniform(0, 500), fedge(c))))
    return [actor, info]


S(0x5a1030, 'ZFFActor::OnDamageInfo', 'thiscall', ret=None, gen=_gen)
