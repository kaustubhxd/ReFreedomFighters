"""specs_s602.py - damage batch 602: ZFFActor::OnProjectileHit (PC 0x5a16a0). GetDamageMultForBone runs as exe code;
the bone collision, render manager, weapon, template, ammo and OnDamageInfo are heap stubs."""
import struct
from pilot import S
from wkit import rnd, stub, obj, fedge


def coll_stub(c, zone, front):
    """GetBoneCollision stand-in: records pos/dir pointers' first floats, writes exactly 2 bytes {zone, front}
    at the out pointer, returns the out pointer, ret 0xc."""
    rec = c.emu.alloc(16, 4)
    code = b''
    code += b'\x8b\x44\x24\x08' + b'\x8b\x00' + b'\xa3' + struct.pack('<I', rec)        # [rec] = *pos
    code += b'\x8b\x44\x24\x0c' + b'\x8b\x40\x08' + b'\xa3' + struct.pack('<I', rec + 4)  # [rec+4] = dir[2]
    code += b'\xff\x05' + struct.pack('<I', rec + 8)                                      # count
    code += b'\x8b\x44\x24\x04' + b'\x66\xc7\x00' + struct.pack('<H', zone | (front << 8))  # mov word [eax], imm
    code += b'\xc2\x0c\x00'
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def _vec(c, a):
    for i in range(3):
        c.emu.wf32(a + 4 * i, c.rng.uniform(-3000, 3000))


def _gen(c):
    r = c.rng
    emu = c.emu
    zone = r.choice(list(range(10)) * 2 + [2, 3, 2, 3, 12, 0xff])
    front = r.getrandbits(1)
    asserts = stub(c, 0, cdecl=True)
    emu.w32(0x7003b0, asserts)
    # OnDamageInfo stub copies every defined SDamageInfo field
    dmg = stub(c, 1, skip=(0,), copy=(0, [(o, 'd') for o in range(0, 0x2c, 4)]))
    actor = obj(c, 0xa00, {0x388: coll_stub(c, zone, front), 0x6c0: dmg})
    for off in range(0x3ea, 0x412, 4):
        emu.wf32(actor + off, r.choice((1.0, 1.0, 5.0, 0.5, 2.0, fedge(c))))
    emu.wbytes(actor + 0x7a0, struct.pack('<h', r.choice((0, 1, 100, 150, -3, r.randrange(-0x8000, 0x8000)))))
    # weapon, template, ammo
    calc = emu.alloc(4, 4)
    emu.wf32(calc, r.choice((20.0, 30.0, 34.5, 0.0, fedge(c), r.uniform(0, 200))))
    ammo = obj(c, 0x40, {0x32c: stub(c, 0, ret=r.choice((5, 5, 1, 2, 9)))})
    wtype = r.choice((4, 4, 0, 1, 2, 5, 6, 7, 3))
    tmpl = obj(c, 0x40, {0x35c: stub(c, 2, fld=calc), 0x330: stub(c, 0, ret=wtype),
                         0x340: stub(c, 1, ret=ammo if r.random() < 0.8 else 0)})
    w = obj(c, 0x100, {0x350: stub(c, 0, ret=tmpl)})
    eng = rnd(c, 0x1c00)
    emu.w32(eng + 0x1b5d, r.choice((1, 1, 0, 2)))
    rm = obj(c, 0x40, {0x58: stub(c, 1, ret=w if r.random() < 0.9 else 0)})
    emu.w32(eng + 0x9b, rm)
    emu.w32(0x70039c, eng)
    proj = rnd(c, 0x40)
    _vec(c, proj + 0xc)
    _vec(c, proj + 0x28)
    hit = rnd(c, 0x20)
    emu.w32(hit, proj)
    emu.wf32(hit + 0x14, r.choice((r.uniform(0, 12000), 0.0, 5000.0, fedge(c))))
    return [actor, hit]


S(0x5a16a0, 'ZFFActor::OnProjectileHit', 'thiscall', ret=None, gen=_gen)
