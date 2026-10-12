"""specs_s6450.py - unclaimed-68 batch 45 (claim 45): ZSoundAmbient::GetListenerRoom (0x4a4220). Four entries at +0x1c8: logging objects (slot
+0x20 returns a block r whose +8 is a zeroed block), or null. The helper 0x4db3b0 is exe code. The engine object at [0x70039c]+0x9b has a
random dword at +0xadc. The index is 0..3 (the table is four entries in this spec)."""
from pilot import S
from engine_stubs import zero_obj, logged_obj, set_global


def _room(c):
    o = zero_obj(c, 0x400)
    for i in range(4):
        if c.rng.random() < 0.75:
            q = zero_obj(c, 0x100)
            r = zero_obj(c, 0x40)
            c.emu.w32(r + 8, q)
            ent = logged_obj(c, 'ZAmbRoomEnt%d' % i, 0x80, impl={0x20: (lambda rr: (lambda e, a: (rr, None)))(r)}, argwords={})
            c.emu.w32(o + 0x1c8 + 4 * i, ent)
    eng = zero_obj(c, 0x400)
    en = zero_obj(c, 0x1000)
    c.emu.w32(en + 0xadc, c.rng.getrandbits(32))
    c.emu.w32(eng + 0x9b, en)
    set_global(c, 0x70039c, eng)
    return [o, c.rng.randrange(0, 4)]


S(0x4a4220, 'ZSoundAmbient::GetListenerRoom (unknown) thiscall', 'thiscall', None, ret='eax', gen=_room,
  note='unclaimed-68 batch 45; table at +0x1c8; helper 0x4db3b0 (exe); engine fallback +0xadc')
