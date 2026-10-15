"""specs_s90000.py - hard trial (opus). 0x44b740: SEH-framed cdecl; engine object (0x70039c) +0x1a9f (unaligned) sound
object or NULL, slot 0x118 thiscall(1 arg) recorded with the SEH chain the callee sees (seh_record: next, handler,
state of 2 records) under 0-2 fake outer records (seh_chain); fs:[0] after return compared by pilot (out['seh'])."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, seh_record, seh_chain


def _g44b740(c):
    clear_hooks(c)
    r = c.rng
    seh_chain(c, r.choice([0, 1, 2]))
    eng = rnd(c, 0x1b00)
    c.emu.w32(0x70039c, eng)
    k = r.random()
    if k < 0.2:
        c.emu.wbytes(eng + 0x1a9f, b'\0\0\0\0')
    else:
        snd = obj(c, 0x40, {0x118: pystub(c, 1, this=True, side=seh_record(c, 2))}, nslots=0x48)
        c.emu.wbytes(eng + 0x1a9f, snd.to_bytes(4, 'little'))
    return [r.choice([0, 1, 0xffffffff, r.getrandbits(32), r.getrandbits(16)])]


S(0x44b740, 'GUESS ZSoundObject release sound', 'cdecl', None, ret=None, gen=_g44b740, note='batch90000')
