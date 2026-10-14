"""specs_s1610.py - soundtimers batch 1610: ZIKLNKOBJ::PlaySoundFootStep (AddSound3d logged by content)."""
from pilot import S
from sthelp import rnd, stub, Seq, world, obj
from specs_s1609 import _add3d, _fill


def _foot(c):
    seq = Seq(c)
    r = c.rng
    def5 = r.getrandbits(32)
    snd = r.getrandbits(32)
    g1, g2, fw = r.getrandbits(32), r.getrandbits(32), r.getrandbits(32) if r.random() < 0.9 else 0
    k = r.random()
    look = [(0, g1, snd)] if k < 0.4 else ([(0, g2, snd)] if k < 0.6 else ([(0, def5, snd)] if k < 0.85 else []))
    me, hc, hn = world(c, seq, slots={0x3b8: _fill(c, seq), 0x3b4: _fill(c, seq), 0x390: stub(c, seq, 1)},
                       dll_slots={0x58: stub(c, seq, 2, ret=0, retfn=look), 0x5c: stub(c, seq, 1, ret=def5)})
    _add3d(c, seq, hn)
    s = c.emu.r32(0x70039c)
    db = c.emu.r32(s + 0x9b)
    vt = c.emu.alloc(0x80, 4)
    c.emu.w32(vt + 0x60, c.emu.r32(c.emu.r32(db) + 0x60))
    c.emu.w32(vt + 0x4c, stub(c, seq, 1, ret=r.getrandbits(32)))
    c.emu.w32(db, vt)
    m = c.emu.r32(me + 8)
    for i in range(12):
        c.emu.wf32(m + 4 * i, r.uniform(-50, 50))
    c.emu.w8(me + 0x146, r.choice([0, 1]))
    c.emu.w8(me + 0x144, r.choice([0, 1]))
    c.emu.w32(me + 0x14b, g1 if r.random() < 0.6 else 0)
    c.emu.w32(me + 0x147, g2)
    c.emu.w32(me + 0x14f, fw)
    return [me, r.choice([0, 1, 0x100, r.getrandbits(32)])]


S(0x4670b0, 'ZIKLNKOBJ::PlaySoundFootStep', 'thiscall', None, ret='eax', gen=_foot, note='batch1610')
