"""specs_s600.py - area 49 batch 600: ZParticleController::CreateParticle (0x4561c0).
The controller (self) holds the per-id tables and the particle pool pointer (+0x81d). The sys object supplies the
render manager (+0x9b, slot 0x58 returns the template) and the random float (slot 0x1c0, ST0)."""
from pilot import S
from pe_emu import F
from wkit import rnd, stub, obj, vec, fedge
from unicorn.x86_const import UC_X86_REG_EAX  # noqa: F401


def _cp(c):
    r = c.rng
    # template (emitter) object
    tmpl = rnd(c, 0x200)
    c.emu.w8(tmpl + 0x48, 0 if r.random() < 0.5 else r.randint(1, 255))
    for off in (0x24, 0x28, 0x2c, 0x30, 0x34, 0x38, 0x3c, 0x40, 0x44):
        c.emu.wf32(tmpl + off, r.uniform(0.0, 4.0) if r.random() < 0.9 else fedge(c))
    # render manager and sys object
    rm = obj(c, 0x100, {0x58: stub(c, 1, ret=tmpl)})
    sysv = obj(c, 0xa0, {0x1c0: stub(c, 2, fldv=r.choice((0.0, 0.5, 0.999, r.random())))})
    c.emu.w32(sysv + 0x9b, rm)
    c.emu.w32(sysv + 0x40, r.randint(0, 1 << 20))
    c.emu.w32(0x70039c, sysv)
    # controller: per-id tables and the pool pointer
    self_ = rnd(c, 0x900)
    pid = r.randint(0, 9)
    for i in range(10):
        c.emu.w32(self_ + i * 8 + 0x15, 0 if i != pid else 0)   # template handle (unused: rm returns tmpl)
        c.emu.w32(self_ + i * 8 + 0x19, 0 if r.random() < 0.6 else r.randint(1, 30))
    pool = c.emu.alloc(0x26000, 16)
    c.emu.wbytes(pool, bytes(r.getrandbits(8) for _ in range(0x20000)))
    cnt = r.randint(0, 6)
    c.emu.w32(pool + 0x25400, cnt)
    for i in range(64):
        c.emu.w32(pool + 0x25300 + 4 * i, r.randint(0, 40))
    c.emu.w32(self_ + 0x81d, pool)
    for i in range(0, 40):
        p = pool + i * 0x94c
        c.emu.w32(p + 4, r.choice((0x40, 0x40, 0, 1, 2)))
    time = r.randint(-(1 << 20), 1 << 20)
    return [self_, pid, vec(c, 3, -50, 50), vec(c, 3, -50, 50), time & 0xffffffff]


S(0x4561c0, 'ZParticleController::CreateParticle', 'thiscall', None, ret=None, gen=_cp)
